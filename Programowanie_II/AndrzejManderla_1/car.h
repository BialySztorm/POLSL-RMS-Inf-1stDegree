
#include <string>

class Car {
private:
    static int ID;
    std::string make;
    std::string model;
    int year;
    int id;

public:
    // Default constructor
    Car();

    // Parametric constructor
    Car(std::string m, std::string mo, int y);

    // Destructor
    ~Car();

    void displayInfo();
};

