#ifndef d2r
    #define d2r

    #include <jdbc/mysql_driver.h>
    #include <jdbc/mysql_connection.h>
    #include <jdbc/cppconn/resultset.h>
    #include <jdbc/cppconn/statement.h>

    #include <unistd.h>
    #include <sstream>
    #include <iostream>
    #include <iomanip>

    #include <ros.h>
    #include <visualization_msgs/MarkerArray.h>

#endif

class Vec2D {

    public:
    int x;
    int y;

};

class Defect {

    public:
    int id_inspection;
    int x;
    int y;
    int weight;
    int kind;
    int area;
};

class DefectType {

    public:
    void moveDefects(class Vec2D vecSpeed, double elapsedTime);
    std::vector<class Defect> Defects;
};



