#include "router.hpp"
#include "crow_all.h"
#include "movie_controller.hpp"

Router::Router(
	crow::App<crow::CORSHandler>& app,
	MovieController& Movie_Controller
):
_app(app),
_Movie_Controller(Movie_Controller) {}

void Router::SetupRoutes() {
	CROW_ROUTE(this->_app, "/")([]() {
		return crow::json::wvalue("Hi mom!");
	});

	CROW_ROUTE(this->_app, "/movies")([&]() {
		return this->_Movie_Controller.GetMovies();
	});

	CROW_ROUTE(this->_app, "movies/<string>")([&](std::string movie_name) {
		return this->_Movie_Controller.GetMovie(movie_name);
	});
}