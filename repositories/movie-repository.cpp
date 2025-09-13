#include "movie_model.hpp"
#include "movie_repository.hpp"
#include <exception>
#include <mongocxx/collection-fwd.hpp>
#include <mongocxx/database-fwd.hpp>
#include <mongocxx/database.hpp>
#include <bsoncxx/json.hpp>
#include <string>
#include <vector>

MovieRepository::MovieRepository(
	const Movies& movie,
	const mongocxx::database& database,
	mongocxx::collection& collection
):_movie(movie),
	_database(database),
	_collection(collection)
{}

std::vector<std::string> MovieRepository::GetMovies() {
	std::vector<std::string> movies_vector;
	auto cursor = this->_collection.find({});

	try {
		for(auto&& doc : cursor) {
			movies_vector.push_back(bsoncxx::to_json(doc));
		}
	} catch (std::exception& e) {
		std::cout << "Couldn't get movies: " << e.what() << "\n";
	}

	return movies_vector;
}