#ifndef ROUTER_HPP_INCLUDED
#define ROUTER_HPP_INCLUDED

#include "crow_all.h"

class Router {
	private:
		crow::SimpleApp& _app;
	
	public :
		Router(crow::SimpleApp& app);
		void SetupRoutes();
};

#endif