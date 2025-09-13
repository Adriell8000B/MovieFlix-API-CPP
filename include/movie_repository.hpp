#ifndef MOVIE_REPOSITORY_HPP_INCLUDED
#define MOVIE_REPOSITORY_HPP_INCLUDED

#include "movie_model.hpp"
#include <mongocxx/collection-fwd.hpp>
#include <mongocxx/database-fwd.hpp>

class MovieRepository {
	private:
	const Movies& _movie;
	const mongocxx::database& _database;
	const mongocxx::collection& _collection;

	public:
	MovieRepository(
		const Movies& movie,
		const mongocxx::database& database,
		const mongocxx::collection& collection
	);

	void GetMovies();
};

#endif