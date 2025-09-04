FROM ubuntu:22.04 AS builder

RUN apt-get update && apt-get install -y --no-install-recommends \
    cmake \
    build-essential \
    libssl-dev \
    git \
    wget \
    ca-certificates \
    pkg-config \
    libboost-system-dev libboost-thread-dev libboost-date-time-dev libboost-regex-dev libboost-filesystem-dev libasio-dev \
    curl

RUN curl -OL https://github.com/mongodb/mongo-cxx-driver/releases/download/r4.1.1/mongo-cxx-driver-r4.1.1.tar.gz && \
    tar -xzf mongo-cxx-driver-r4.1.1.tar.gz && \
    cd mongo-cxx-driver-r4.1.1/build && \
    cmake .. \
    -DBUILD_SHARED_LIBS=OFF \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_CXX_STANDARD=17 && \
    make install

WORKDIR /app
COPY CMakeLists.txt main.cpp credentials.json ./
COPY include ./include
COPY server ./server
COPY router ./router
COPY utils ./utils
COPY database ./database
RUN cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
RUN cmake --build build

FROM ubuntu:22.04

RUN apt-get update && apt-get install -y --no-install-recommends ca-certificates

COPY --from=builder /app/build/cpp-api /usr/local/bin/cpp-api

EXPOSE 18080

CMD [ "/usr/local/bin/cpp-api" ]