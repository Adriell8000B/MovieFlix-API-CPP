#ifndef MOVIE_CONTROLLER_HPP_INCLUDED
#define MOVIE_CONTROLLER_HPP_INCLUDED

#include "crow_all.h"
#include "movie_repository.hpp"

class MovieController {
	private:
	MovieRepository& _MovieRepository;

	public:
	MovieController(MovieRepository& MovieRepository);
	crow::json::wvalue GetMovies();
	crow::json::wvalue GetMovie(std::string& movie_name);
};

#endif