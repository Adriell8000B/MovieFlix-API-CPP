#include "crow_all.h"
#include "database.hpp"
#include "router.hpp"
#include "server.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <string>

int main(void) {
  setup_enviroment();

  crow::SimpleApp app;
  Router router(app);
  Database database(std::string(std::getenv("MONGODB_URI")));

  Server server(
    app,
    router,
    database,
    18080
  );

  server.Init();
}