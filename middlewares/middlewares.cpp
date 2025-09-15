#include "middlewares.hpp"
#include "crow_all.h"

Middlewares::Middlewares(
	crow::App<crow::CORSHandler>& app,
	const std::string& ALLOWED_ORIGIN,
	const std::string& ALLOWED_HEADER
):
_app(app),
_ALLOWED_ORIGIN(ALLOWED_ORIGIN),
_ALLOWED_HEADER(ALLOWED_ORIGIN) {}

void Middlewares::configureCORS() {
	auto& cors = this->getCORS()
	.global()
	.origin(this->_ALLOWED_ORIGIN)
	.allow_credentials()
	.methods("GET"_method)
	.headers(this->_ALLOWED_HEADER);
}

crow::CORSHandler& Middlewares::getCORS() {
	return this->_app.get_middleware<crow::CORSHandler>();
}

void Middlewares::SetupMiddlewares() {
	this->configureCORS();
}