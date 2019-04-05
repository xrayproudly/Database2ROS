#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

#include <unistd.h>
#include <sstream>
#include <iostream>
#include <iomanip>

int main(int argc, char **argv) {

    int inspNo = 0;

    try{
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "12345678");
        con->setSchema("psa_pintura");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT id_inspection, x, y FROM defects ORDER BY id_inspection ASC");
        while (res->next()) {
            if(res->getInt(1) != inspNo) {
                std::cout << "\n[ID]: ";
                std::cout << res->getInt(1);
            }
            std::cout << "\n   [X]: ";
            std::cout << std::setw(5) << res->getInt(2);
            std::cout << " [Y]: ";
            std::cout << std::setw(5) << res->getInt(3);

            inspNo = res->getInt(1);
        }
        std::cout << std::endl;

        delete res;
        delete stmt;
        delete con;
    }
    catch(sql::SQLException &err){
        std::cout << "ERROR: " << err.what() << std::endl;
    }
    return 0;
}