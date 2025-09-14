#ifndef SERVER_HPP_INCLUDED
#define SERVER_HPP_INCLUDED

#include "crow_all.h"
#include "database.hpp"
#include "middlewares.hpp"
#include "router.hpp"
#include <cstdint>

class Server {
	private:
	crow::App<crow::CORSHandler>& _app;
	Router& _router;
	Database& _database;
	Middlewares& _middlewares;
	const uint16_t _PORT;
	void listen();
	void setup();

	public:
	Server(
		crow::App<crow::CORSHandler>& app,
		Router& router,
		Database& database,
		Middlewares& middlewares,
		const uint16_t PORT
	);
	void Init();
};

#endif