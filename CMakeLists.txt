cmake_minimum_required(VERSION 3.10.0)
project(cpp-api VERSION 0.1.0 LANGUAGES C CXX)

find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

add_executable(cpp-api
	main.cpp	
	server/server.cpp
	router/router.cpp
	database/database.cpp
	utils/utils.cpp
)

target_include_directories(
	cpp-api PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)


target_link_libraries(
	cpp-api PRIVATE
	mongo::mongocxx_static
	mongo::bsoncxx_static
)
