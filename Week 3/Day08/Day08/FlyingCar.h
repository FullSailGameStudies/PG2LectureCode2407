#pragma once
#include "Car.h"
class FlyingCar : public Car
{
public:
	FlyingCar(int year, std::string make, std::string model, int maxAltitude, int maxAirspeed)
		: 
		Car(year,make,model) //MUST call a base ctor
		, maxAltitude_(maxAltitude)
		, maxAirspeed_(maxAirspeed)
	{
		mModel = model;
	}
	std::string vehicleInformation() override;

	int MaxAltitude() { return maxAltitude_; }
	int MaxAirspeed() { return maxAirspeed_; }
	void MaxAltitude(int newMax) {
		if (newMax > 0 && newMax < 10000)
			maxAltitude_ = newMax;
	}
	void MaxAirspeed(int newMax) {
		if (newMax > 0 && newMax < 200)
			maxAirspeed_ = newMax;
	}
private:
	int maxAltitude_, maxAirspeed_;

};

