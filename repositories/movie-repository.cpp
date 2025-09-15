#include "movie_model.hpp"
#include "movie_repository.hpp"
#include <bsoncxx/document/view-fwd.hpp>
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
	auto cursor = this->_client
	.database(this->_database_name)
	.collection(this->_collection_name).find({});

	std::vector<std::string> movies;

	for (auto&& doc : cursor) {
		movies.push_back(bsoncxx::to_json(doc));
	}

	return movies;
}