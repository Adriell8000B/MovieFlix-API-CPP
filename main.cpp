#include "crow_all.h"
#include "database.hpp"
#include "movie_controller.hpp"
#include "movie_model.hpp"
#include "movie_repository.hpp"
#include "server.hpp"
#include "utils.hpp"
#include <mongocxx/collection-fwd.hpp>
#include <cstdint>
#include <string>

int main(void) {
  setup_enviroment();
  const std::string uri = get_env("MONGODB_URI");
  const std::string database_name = get_env("DATABASE_NAME");
  const std::string collection_name = get_env("COLLECTION_NAME");
  
  crow::App<crow::CORSHandler> app;
  Movies movies;
  
  Database database(uri, database_name);
  
  MovieRepository movie_repository(
    movies,
    uri,
    database_name,
    collection_name
  );
  MovieController movie_controller(movie_repository);

  Router router(
    app,
    movie_controller
  );

  Server server(
    app,
    router,
    database,
    static_cast<uint16_t>(std::stoi(get_env("PORT")))
  );

  server.Init();
}