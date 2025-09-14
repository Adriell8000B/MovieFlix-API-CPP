#include "crow_all.h"
#include "json.hpp"
#include "movie_controller.hpp"
#include "movie_repository.hpp"
#include <vector>

MovieController::MovieController(
	MovieRepository& MovieRepository
):_MovieRepository(MovieRepository) {}

crow::json::wvalue MovieController::GetMovies() {
	std::vector<std::string> movies = this->_MovieRepository.RetrieveMovies();
	nlohmann::json json_response;
	nlohmann::json json_movies = nlohmann::json::array();

	for (const auto& movie: movies) {
		json_movies.push_back(movie);
	}

	json_response["movies"] = json_movies;
	std::string json_string = json_response.dump();

	return crow::json::wvalue(json_string);
}