#ifndef SERVER_HPP_INCLUDED
#define SERVER_HPP_INCLUDED

#include "crow_all.h"
#include "database.hpp"
#include "router.hpp"
#include <cstdint>

class Server {
	private:
	crow::SimpleApp& _app;
	Router& _router;
	Database& _database;
	const uint16_t _PORT;
	void listen();
	void setup();

	public:
	Server(crow::SimpleApp& app, Router& router, Database& database, const uint16_t PORT);
	void Init();
};

#endif