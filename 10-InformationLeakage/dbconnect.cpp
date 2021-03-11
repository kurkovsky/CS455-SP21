// this example demonstrates informaton leakage when using a postgres database connection
// based on https://zetcode.com/db/postgresqlc/
// compile with: g++ dbconnect.cpp -I/usr/include/postgresql -lpq

#include <iostream>
#include <postgresql/libpq-fe.h>
using namespace std;

int main() {
    // start the postgres service by using this command:
    // sudo service postgresql start
    cout << "Version of libpq:" << PQlibVersion() << endl;

    // attempt to conenct to the database
    // we do not need the database itself to demonstrate that connection willl fail
    PGconn *connection = PQconnectdb("user=stan password=123 dbname=testdb");
    if(PQstatus(connection) == CONNECTION_BAD) {
        // PQerrorMessage facilitates information leakage: it displays the user name
        cerr << "Connection to database failed: " << PQerrorMessage(connection) << endl;
        PQfinish(connection);
        return 1;
    }

    PQfinish(connection);
    return 0;
}