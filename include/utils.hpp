#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED

#include <string>

void godotenv();
void setup_enviroment();
const std::string get_env(const std::string& env_name);

#endif