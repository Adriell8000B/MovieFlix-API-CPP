#ifndef ROUTER_HPP_INCLUDED
#define ROUTER_HPP_INCLUDED

#include "crow_all.h"

class Router {
	private:
		crow::App<crow::CORSHandler>& _app;
	
	public :
		Router(crow::App<crow::CORSHandler>& app);
		void SetupRoutes();
};

#endif