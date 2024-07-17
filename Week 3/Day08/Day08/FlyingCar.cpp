#include "FlyingCar.h"

std::string FlyingCar::vehicleInformation()
{
    //EXTEND the base method or FULLY-OVERRIDE the base method
    //EXTEND means calling the base method
    std::string combo = Car::vehicleInformation() + 
        "\nMax Altitude: " + std::to_string(maxAltitude_) +
        "  Max Airspeed: " + std::to_string(maxAirspeed_);
    return combo;
}
