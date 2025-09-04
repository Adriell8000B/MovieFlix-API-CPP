#ifndef DATABASE_HPP_INCLUDED
#define DATABASE_HPP_INCLUDED

#include <string>

#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/client.hpp>

class Database {
	private:
	mongocxx::instance _instance;
	mongocxx::uri _uri;
	mongocxx::client _client;
	void connect();
	mongocxx::client& getClient();
	
	public:
	void SetupDatabase();
	explicit Database(const std::string& uri);
};

#endif