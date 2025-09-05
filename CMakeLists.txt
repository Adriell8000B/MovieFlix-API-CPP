cmake_minimum_required(VERSION 3.10.0)
project(MovieFlix-API-CPP VERSION 0.2.0 LANGUAGES C CXX)

find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

add_executable(MovieFlix-API-CPP
	main.cpp	
	server/server.cpp
	router/router.cpp
	database/database.cpp
	utils/utils.cpp
	middlewares/middlewares.cpp
)

target_include_directories(
	MovieFlix-API-CPP PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)


target_link_libraries(
	MovieFlix-API-CPP PRIVATE
	mongo::mongocxx_static
	mongo::bsoncxx_static
)
