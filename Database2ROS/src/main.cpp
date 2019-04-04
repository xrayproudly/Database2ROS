#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

#include <unistd.h>

int main(int argc, char **argv) {

    try{
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "12345678");
        con->setSchema("psa_pintura");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT x, y FROM defects");
        while (res->next()) {
            std::cout << "[X]: ";
            std::cout << res->getString(1);
            std::cout << "[Y]: ";
            std::cout << res->getString(2);
            std::cout << std::endl; 
        }
        delete res;
        delete stmt;
        delete con;
    }
    catch(sql::SQLException &err){
        std::cout << "ERROR: " << err.what() << std::endl;
    }
    pause();
    return 0;
}