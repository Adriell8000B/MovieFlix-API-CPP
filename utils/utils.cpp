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

const std::string get_env(const std::string& env_name) {
	const char* env_ptr = std::getenv(env_name.c_str());

	if(env_ptr == nullptr) {
		std::cout << "Couldn't load " << env_name << "\n";
		return "";
	}

	return std::string(env_ptr);
}