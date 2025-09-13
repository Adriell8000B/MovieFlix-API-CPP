#include "movie_model.hpp"
#include "movie_repository.hpp"
#include <mongocxx/collection-fwd.hpp>
#include <mongocxx/database-fwd.hpp>
#include <mongocxx/database.hpp>

MovieRepository::MovieRepository(
	const Movies& movie,
	const mongocxx::database& database,
	const mongocxx::collection& collection
):_movie(movie),
	_database(database),
	_collection(collection)
{}

void MovieRepository::GetMovies() {
	auto cursor = this->_database
	.collection("");
}