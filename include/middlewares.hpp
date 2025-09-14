#ifndef MIDDLEWARES_HPP_INCLUDED
#define MIDDLEWARES_HPP_INCLUDED

#include "crow_all.h"
#include <string>

class Middlewares {
	private:
	crow::App<crow::CORSHandler>& _app;
	const std::string& _ALLOWED_ORIGIN;
	void configureCORS();
	crow::CORSHandler& getCORS();

	public:
	Middlewares(
		crow::App<crow::CORSHandler>& app,
		const std::string& ALLOWED_ORIGIN
	);
	void SetupMiddlewares();
};

#endif