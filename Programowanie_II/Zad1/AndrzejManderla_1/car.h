
#include <string>

class Car {
private:
    std::string make;
    std::string model;
    int year;

public:
    // Default constructor
    Car();

    // Parametric constructor
    Car(std::string m, std::string mo, int y);

    // Destructor
    ~Car();

    void displayInfo();
};