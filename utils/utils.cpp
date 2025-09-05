#include "utils.hpp"
#include "dotenv.h"
#include <cstdlib>
#include <iostream>
#include <string>

void godotenv() {
	dotenv::init();
}

void setup_enviroment() {
	const char* env_ptr = std::getenv("ENV");
	if (env_ptr != nullptr && std::string(env_ptr) == "DEV") {
		std::cout << "Developmet enviroment detected!\n";
		godotenv();
	}
}
