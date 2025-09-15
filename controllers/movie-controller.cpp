#include "crow_all.h"
#include "movie_controller.hpp"
#include "movie_repository.hpp"
#include <bsoncxx/document/view-fwd.hpp>
#include <exception>
#include <string>
#include <utility>
#include <vector>

MovieController::MovieController(
	MovieRepository& MovieRepository
):_MovieRepository(MovieRepository) {}

crow::json::wvalue MovieController::GetMovies() {
	std::vector<std::string> movies_vector = this->_MovieRepository.RetrieveMovies();
	crow::json::wvalue movies_json_array = crow::json::wvalue::list();

	try {
		for(const auto& movie : movies_vector) {
		crow::json::wvalue movie_json_object = crow::json::load(movie);

			if(movie_json_object.t() != crow::json::type::Null) {
				movies_json_array[movies_json_array.size()] = std::move(movie_json_object);
			}
		}
	} catch (std::exception& e) {
		std::cout << "GetMovies(): " << e.what() << "\n";
	}

	return movies_json_array;
}