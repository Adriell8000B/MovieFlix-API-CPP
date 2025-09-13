#include "crow_all.h"
#include "database.hpp"
#include "router.hpp"
#include "server.hpp"
#include "utils.hpp"
#include <cstdint>
#include <string>

int main(void) {
  setup_enviroment();

  crow::App<crow::CORSHandler> app;
  Router router(app);
  Database database(
    get_env("MONGODB_URI"),
    get_env("DATABASE_NAME"),
    get_env("COLLECTION_NAME")
  );

  Server server(
    app,
    router,
    database,
    static_cast<uint16_t>(std::stoi(get_env("PORT")))
  );

  server.Init();
}