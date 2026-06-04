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
	Plant() {
		plantName = "";
		currentHumidity = 0;
		health = DEAD;
	}
	Plant(std::string plantName, int currentHumidity, healthStatus health) {
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

	int getCurrentHumidity() {
		return currentHumidity;
	}

	void updateCurrentHumidity(int humidity) {
		currentHumidity += humidity;
	}
};


class GreenHouseController {
private:
	Plant plants[10];
	int amount;
public:
	GreenHouseController() {
		amount = 0;
	}

	void checkAllPlants() {
		for (Plant plant : plants) {
			if (plant.getCurrentHumidity() < 50) {
				int waterAmount = rand() % 10 + 5;
				plant.updateCurrentHumidity(waterAmount);
			}
		}
	}

	void addPlant(std::string plantName = "Sunflower", int currentHumidity = 100, healthStatus health = HEALTHY) {
		if (amount == 10) {
			std::cout << "Green house is full.\n";
		}
		else {
			plants[amount] = Plant(plantName, currentHumidity, health);
			amount++;
		}
	}
};


int main() {

}