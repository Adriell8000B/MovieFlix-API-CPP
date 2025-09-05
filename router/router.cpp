#include "router.hpp"
#include "crow_all.h"

Router::Router(crow::App<crow::CORSHandler>& app): _app(app) {}

void Router::SetupRoutes() {
	CROW_ROUTE(this->_app, "/foo")([]() {
		return "<h1>Hi mom!</h1>";
	});
}