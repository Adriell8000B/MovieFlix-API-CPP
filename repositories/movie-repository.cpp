#include "movie_model.hpp"
#include "movie_repository.hpp"
#include <exception>
#include <mongocxx/client.hpp>
#include <mongocxx/collection-fwd.hpp>
#include <mongocxx/database.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/uri.hpp>
#include <string>
#include <vector>

MovieRepository::MovieRepository(
	const Movies& movie,
	const std::string& uri,
	const std::string& database_name,
	const std::string& collection_name
):
_uri(mongocxx::uri{uri}),
_client(mongocxx::client{_uri}),
_movie(movie),
_database_name(database_name),
_collection_name(collection_name)
{}

std::vector<std::string> MovieRepository::RetrieveMovies() {
	std::vector<std::string> movies_vector;
	auto cursor = this->_client
	.database(this->_database_name)
	.collection(this->_collection_name).find({});

	try {
		for(auto&& doc : cursor) {
			movies_vector.push_back(bsoncxx::to_json(doc));
		}
	} catch (std::exception& e) {
		std::cout << "Couldn't get movies: " << e.what() << "\n";
	}

	return movies_vector;
}