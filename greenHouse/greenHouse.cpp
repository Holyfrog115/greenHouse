#include <iostream>

enum healthStatus {
	HEALTHY,
	DRY,
	DEAD,
};


class Plant {
private:
	std::string plantName;
	int currentHumidity;
	healthStatus health;
public:
	Plant(std::string plantName = "Sunflower", int currentHumidity = 100, healthStatus health = HEALTHY) {
		this->plantName = plantName;
		this->currentHumidity = currentHumidity;
		this->health = health;
	}

	void water() {
		if (currentHumidity + 20 > 100) {
			currentHumidity = 100;
		}
		else {
			currentHumidity += 20;
		}
	}

	void updateStatus() {
		int decrease = rand() % 25 + 5;
		currentHumidity -= decrease;
	}
};


class greenHouseController {
private:
	Plant plants[10];
public:
	void checkAllPlants() {
		for (Plant plant : plants) {

		}
	}
};


int main() {

}