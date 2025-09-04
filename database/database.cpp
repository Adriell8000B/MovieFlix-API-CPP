#include "database.hpp"
#include <iostream>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/exception/exception.hpp>

Database::Database(const std::string& uri):
_uri(mongocxx::uri{uri}), _client(mongocxx::client{_uri}) {}

void Database::connect() {
	try {
		this->_client.database("MovieFlix").run_command(bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("ping", 1)));
		std::cout << "Mongodb connected!\n";
	} catch(const mongocxx::exception& e) {
		std::cout << "Couldn't connect to Mongodb: " << e.what() << "\n";
	}
}

mongocxx::client& Database::getClient() {
	return this->_client;
}

void Database::SetupDatabase() {
	this->connect();
}