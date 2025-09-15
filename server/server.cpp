#include "server.hpp"
#include "crow_all.h"
#include "database.hpp"
#include "middlewares.hpp"
#include "router.hpp"
#include <cstdint>
#include <exception>
#include <iostream>

Server::Server(
	crow::App<crow::CORSHandler>& app,
	Router& router,
	Database& database,
	Middlewares& middlewares,
	const uint16_t PORT
):
_app(app),
_router(router),
_database(database),
_middlewares(middlewares),
_PORT(PORT) {}

void Server::listen() {
	try {
		this->_app.port(this->_PORT).multithreaded().run();
	} catch (std::exception& error) {
		std::cerr << "Server::listen() -> an error ocurred: " << error.what() << "\n";
	}
}

void Server::setup() {
	this->_middlewares.SetupMiddlewares();
	this->_router.SetupRoutes();
	this->_database.SetupDatabase();
}

void Server::Init() {
	this->setup();
	this->listen();
}