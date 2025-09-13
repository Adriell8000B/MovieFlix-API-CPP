#ifndef MOVIE_REPOSITORY_HPP_INCLUDED
#define MOVIE_REPOSITORY_HPP_INCLUDED

#include "movie_model.hpp"
#include <mongocxx/collection-fwd.hpp>
#include <mongocxx/database-fwd.hpp>
#include <string>
#include <vector>

class MovieRepository {
	private:
	const Movies& _movie;
	const mongocxx::database& _database;
	mongocxx::collection& _collection;

	public:
	MovieRepository(
		const Movies& movie,
		const mongocxx::database& database,
		mongocxx::collection& collection
	);

	std::vector<std::string> GetMovies();
};

#endif