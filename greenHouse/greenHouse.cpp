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
		plantName = "-";
		currentHumidity = 0;
		health = DEAD;
	}
	Plant(std::string plantName, int currentHumidity, healthStatus health) {
		this->plantName = plantName;
		this->currentHumidity = currentHumidity;
		this->health = health;
	}

	void water(int amount) {
		if (currentHumidity + amount > 100) {
			currentHumidity = 100;
		}
		else {
			currentHumidity += amount;
		}
	}

	void updateStatus() {
		int decrease = rand() % 25 + 5;
		currentHumidity -= decrease;
	}

	int getCurrentHumidity() {
		return currentHumidity;
	}
};


class GreenHouseController {
private:
	Plant plants[10];
	int amount;
	int days;
public:
	GreenHouseController() {
		amount = 0;
		days = 0;
	}

	void checkAllPlants() {
		for (Plant &plant : plants) {
			if (plant.getCurrentHumidity() < 50) {
				int waterAmount = rand() % 10 + 5;
				plant.water(waterAmount);
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


void printPlant();
void printStats();
void printMenu();



int main() {
	srand(time(NULL));
	GreenHouseController greenHouse = GreenHouseController();


}


void printPlant() {

}


void printStats() {

}


void printMenu() {

}