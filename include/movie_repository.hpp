#ifndef MOVIE_REPOSITORY_HPP_INCLUDED
#define MOVIE_REPOSITORY_HPP_INCLUDED

#include "movie_model.hpp"
#include <mongocxx/client.hpp>
#include <mongocxx/collection-fwd.hpp>
#include <mongocxx/uri.hpp>
#include <string>
#include <vector>

class MovieRepository {
	private:
	const Movies& _movie;
	mongocxx::uri _uri;
	mongocxx::client _client;
	const std::string& _database_name;
	const std::string& _collection_name;

	public:
	explicit MovieRepository(
		const Movies& movie,
		const std::string& uri,
		const std::string& database_name,
		const std::string& collection_name
	);

	std::vector<std::string> RetrieveMovies();
};

#endif