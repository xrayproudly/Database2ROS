#include "d2r.h"

void DefectType::moveDefects (class Vec2D vecSpeed, double elapsedTime) {

    int i = 0;
    while (i <= this->Defects.size()) {
        this->Defects.at(i).x =+ vecSpeed.x * elapsedTime;
        this->Defects.at(i).y =+ vecSpeed.y* elapsedTime;
    }

}

int main(int argc, char **argv) {

    int inspNo = 0;
    std::map <int, class DefectType> DefectTypes;

    Defect* pntDef = NULL;
    DefectType* pntDefType = NULL;

    try{
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "12345678");
        con->setSchema("psa_pintura");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * FROM defects ORDER BY id_inspection ASC");
        while (res->next()) {

            if(res->getInt(1) != inspNo) {
                if (pntDefType != NULL) {
                    DefectTypes.insert(std::pair<int, class DefectType>(inspNo, *pntDefType));
                }
                pntDefType = new DefectType;
            }

            pntDef = new Defect;
            pntDef->id_inspection = res->getInt(1);
            pntDef->x = res->getInt(2);
            pntDef->y = res->getInt(3);
            pntDef->weight = res->getInt(4);
            pntDef->kind = res->getInt(5);
            pntDef->area = res->getInt(6);

            pntDefType->Defects.push_back(*pntDef);

            pntDef = NULL;

            /*std::cout << "\n   [X]: ";
            std::cout << std::setw(5) << res->getInt(2);
            std::cout << " [Y]: ";
            std::cout << std::setw(5) << res->getInt(3);*/

            inspNo = res->getInt(1);
        }
        std::cout << std::endl;

        delete pntDef;
        delete pntDefType;

        delete res;
        delete stmt;
        delete con;
    }
    catch(sql::SQLException &err){
        std::cout << "ERROR: " << err.what() << std::endl;
    }

        ros::init(argc, argv, "defect_viz");
        ros::NodeHandle n;
        ros::Publisher defects_pub = n.advertise<visualization_msgs::MarkerArray("visualization_marker", 0);

        ros::Rate rate(30);

        while(ros::ok) {
            visualization_msgs::MarkerArray array;
        }


    return 0;
}