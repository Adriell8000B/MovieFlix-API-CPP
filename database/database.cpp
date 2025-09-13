#include "database.hpp"
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/collection-fwd.hpp>
#include <mongocxx/database-fwd.hpp>
#include <mongocxx/exception/exception.hpp>
#include <iostream>
#include <string>

Database::Database(
	const std::string& uri,
	const std::string& database_name,
	const std::string& collection_name
):
_uri(mongocxx::uri{uri}),
_client(mongocxx::client{_uri}),
_database_name(database_name),
_collection_name(collection_name) {}

void Database::connect() {
	try {
		this->_client.database(this->_database_name)
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

mongocxx::collection Database::getCollection() {
	return this->getDatabase().collection(this->_collection_name);
}

void Database::SetupDatabase() {
	this->connect();
	this->getCollection();
}