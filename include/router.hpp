#ifndef ROUTER_HPP_INCLUDED
#define ROUTER_HPP_INCLUDED

#include "crow_all.h"
#include "movie_controller.hpp"

class Router {
	private:
		crow::App<crow::CORSHandler>& _app;
		MovieController& _Movie_Controller;
	
	public :
		Router(
			crow::App<crow::CORSHandler>& app,
			MovieController& Movie_Controller
		);
		void SetupRoutes();
};

#endif