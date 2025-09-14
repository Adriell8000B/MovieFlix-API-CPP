#include "database.hpp"
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/database-fwd.hpp>
#include <mongocxx/exception/exception.hpp>
#include <iostream>
#include <string>

Database::Database(
	const std::string& uri,
	const std::string& database_name
):
_uri(mongocxx::uri{uri}),
_client(mongocxx::client{_uri}),
_database_name(database_name) {}

void Database::connect() {
	try {
		this->getDatabase()
		.run_command(
			bsoncxx::builder::basic::make_document(
				bsoncxx::builder::basic::kvp("ping", 1)
			)
		);
		std::cout << "Mongodb connected!\n";
	} catch(const mongocxx::exception& e) {
		std::cout << "Couldn't connect to Mongodb: " << e.what() << "\n";
	}
}

mongocxx::database Database::getDatabase() {
	return this->_client.database(this->_database_name);
}

void Database::SetupDatabase() {
	this->connect();
}