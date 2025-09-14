#include "middlewares.hpp"
#include "crow_all.h"
#include "utils.hpp"

Middlewares::Middlewares(
	crow::App<crow::CORSHandler>& app,
	const std::string& ALLOWED_ORIGIN
):
_app(app),
_ALLOWED_ORIGIN(ALLOWED_ORIGIN) {}

void Middlewares::configureCORS() {
	auto& cors = this->getCORS();

	cors.global()
	.origin(get_env(this->_ALLOWED_ORIGIN))
	.allow_credentials()
	.methods("G"_method);
}

crow::CORSHandler& Middlewares::getCORS() {
	return this->_app.get_middleware<crow::CORSHandler>();
}

void Middlewares::SetupMiddlewares() {
	this->configureCORS();
}