#include "movie_model.hpp"
#include "movie_repository.hpp"
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/document/view-fwd.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/collection-fwd.hpp>
#include <mongocxx/database.hpp>
#include <mongocxx/uri.hpp>
#include <string>
#include <vector>

using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_document;

MovieRepository::MovieRepository(const Movies &movie, const std::string &uri,
                                 const std::string &database_name,
                                 const std::string &collection_name)
    : _uri(mongocxx::uri{uri}), _client(mongocxx::client{_uri}), _movie(movie),
      _database_name(database_name), _collection_name(collection_name) {}

std::vector<std::string> MovieRepository::RetrieveMovies(int limit) {
  auto cursor = this->_client.database(this->_database_name)
                    .collection(this->_collection_name)
                    .find({});

  std::vector<std::string> movies;

  for (auto &&doc : cursor) {
    movies.push_back(bsoncxx::to_json(doc));
  }

  return movies;
}

std::string MovieRepository::RetrieveMovie(std::string movie_name) {
  std::string regex_pattern = ".*" + movie_name + ".*";

  auto filter = bsoncxx::builder::stream::document{}
                << "movie_name" << open_document << "$regex" << regex_pattern
                << "$options" << "i" << // 'i' for case-insensitive search
                close_document << finalize;

  std::string results_json = "[";

  try {
    mongocxx::cursor cursor = this->_client.database(this->_database_name)
                                  .create_collection(this->_collection_name)
                                  .find(filter.view());

    for (auto doc : cursor) {
      // Convert the BSON document to a JSON string
      results_json += bsoncxx::to_json(doc) + ",";
    }
    std::cout<< results_json << "\n";

    // Clean up: remove the trailing comma if results were found
    if (results_json.length() > 1) {
      results_json.pop_back();
    }
  } catch (const std::exception &e) {
    std::cerr << "MongoDB Query Error: " << e.what() << std::endl;
    // In a real app, log the error and return a proper error JSON response
    return "[]";
  }

  results_json += "]";
  return results_json;
}