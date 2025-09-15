FROM ubuntu:22.04 AS builder

# Install dependencies and clean up apt
RUN apt-get update && apt-get install -y --no-install-recommends \
    cmake \
    build-essential \
    libssl-dev \
    git \
    wget \
    ca-certificates \
    pkg-config \
    libboost-system-dev libboost-thread-dev libboost-date-time-dev libboost-regex-dev libboost-filesystem-dev libasio-dev \
    curl && \
    rm -rf /var/lib/apt/lists/*

# Download and build mongo-cxx-driver
RUN curl --fail -OL https://github.com/mongodb/mongo-cxx-driver/releases/download/r4.1.1/mongo-cxx-driver-r4.1.1.tar.gz && \
    tar -xzf mongo-cxx-driver-r4.1.1.tar.gz && \
    cd mongo-cxx-driver-r4.1.1/build && \
    cmake .. \
    -DBUILD_SHARED_LIBS=OFF \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_CXX_STANDARD=17 && \
    make install

# Copy source code
WORKDIR /app
COPY controllers ./controllers
COPY database ./database
COPY include ./include
COPY middlewares ./middlewares
COPY models ./models
COPY repositories ./repositories
COPY router ./router
COPY server ./server
COPY utils ./utils
COPY CMakeLists.txt main.cpp ./

# Build source code
RUN cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
RUN cmake --build build

# --- Runtime ---
FROM ubuntu:22.04

# Install necessary runtime dependencies and clean up apt cache
RUN apt-get update && apt-get install -y --no-install-recommends ca-certificates && \
    rm -rf /var/lib/apt/*

# Create non-root user and use it
RUN useradd --create-home --shell /bin/bash appuser
USER appuser

# Copy built binary from builder
COPY --from=builder /app/build/MovieFlix-API-CPP /usr/local/bin/MovieFlix-API-CPP

# Expose port and run
EXPOSE 18080
CMD [ "/usr/local/bin/MovieFlix-API-CPP" ]
