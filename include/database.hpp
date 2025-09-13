#ifndef DATABASE_HPP_INCLUDED
#define DATABASE_HPP_INCLUDED

#include <mongocxx/collection-fwd.hpp>
#include <mongocxx/database-fwd.hpp>
#include <string>

#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/client.hpp>

class Database {
	private:
	mongocxx::instance _instance;
	mongocxx::uri _uri;
	mongocxx::client _client;
	const std::string& _database_name;
	const std::string& _collection_name;

	void connect();
	mongocxx::database getDatabase();
	mongocxx::collection getCollection();
	
	public:
	void SetupDatabase();
	explicit Database(
		const std::string& uri,
		const std::string& _database_name,
		const std::string& _collection_name
	);
};

#endif