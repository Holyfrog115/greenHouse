#include <iostream>

enum healthStatus {
	HEALTHY,
	DRY,
	DEAD,
};

void printHealthy();
void printDry();
void printDead();
void printStats(GreenHouseController greenHouse, int water, int seeds);
int getWater();
int getSeeds();
void printMenu();

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

        if (currentHumidity < 20) {
            health = DEAD;
        }
        else if (currentHumidity < 60) {
            health = DRY;
        }
        else {
            health = HEALTHY;
        }
	}

	int getCurrentHumidity() {
		return currentHumidity;
	}

	healthStatus getHealthStatus() {
		return health;
	}
};


class GreenHouseController {
private:
	Plant plants[10];
	int amount;
	int days;
    int selectedPlant;
    bool isControlerEnabled;
public:
	GreenHouseController() {
		amount = 0;
		days = 0;
        selectedPlant = 0;
        isControlerEnabled = false;
	}

	void checkAllPlants() {
		for (Plant &plant : plants) {
			if (plant.getCurrentHumidity() < 50) {
				int waterAmount = rand() % 10 + 5;
				plant.water(waterAmount);
			}
		}
	}


    void updateStatus() {
        for (Plant& plant : plants) {
            plant.updateStatus();
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


	void printPlant(int index) {
		if (plants[index].getHealthStatus() == HEALTHY) {
			printHealthy();
		}
        else if (plants[index].getHealthStatus() == DRY) {
            printDry();
        }
        else if (plants[index].getHealthStatus() == DEAD) {
            printDead();
        }
	}


    int getCurrentHumidity() {
        return plants[selectedPlant].getCurrentHumidity();
    }


    void switchControler() {
        isControlerEnabled = !isControlerEnabled;
    }


    bool getControlerState() {
        return isControlerEnabled;
    }
};


int main() {
	srand(time(NULL));
	GreenHouseController greenHouse = GreenHouseController();
}


void printHealthy() {
	std::cout << R"(
        , .-.-,_,
        )`-.>'` (
       /     `\  |

       |       | |
        \     / /
        `=(\ /.=`
         `-;`.-' 
           `)|     ,
            ||  .-'|
          ,_||  \_,/
    ,      \|| .'
    |\|\  , ||/
   ,_\` |/| |Y_,
    '-.'-._\||/
       >_.-`Y|
       ` .-"||"-.
         \'----'/
          |~~~~|
          |:.  |
         /::::  \
       .:::'     '.
      /:::         \
     ;:::'          ;
     |:::           |
     |:::           |
     |:::           |
     ;:::           ;
     \:::.          /
      ':::..      .'
       `""-----""`
    =====[HEALTHY]=====
)" << std::endl;
}


void printDry() {
	std::cout << R"(
            , .-.-,_,
            )`-.>'` (
           /     `\  |
           |       | |
            \     / /
            `=(\ /.=`
            `-;`.-' 
           `  //     
             //  
          ,_// 
           \||
            ||
   ,_\`     ||
    '-.'-._\||/
       >_.-`Y|
       ` .-"||"-.
         \'----'/
          |~~~~|
          |:.  |
         /::::  \
       .:::'     '.
      /:::         \
     ;:::'          ;
     |:::           |
     |:::           |
     |:::           |
     ;:::           ;
     \:::.          /
      ':::..      .'
       `""-----""`
      =====[DRY]=====
)" << std::endl;
}


void printDead() {
    std::cout << R"(
 
 
      
        
       
            
            
              
           
         
            
             
            //
    '-.'-._\||/
       >_.-`Y|
       ` .-"||"-.
         \'----'/
          |~~~~|
          |:.  |
         /::::  \
       .:::'     '.
      /:::         \
     ;:::'          ;
     |:::           |
     |:::           |
     |:::           |
     ;:::           ;
     \:::.          /
      ':::..      .'
       `""-----""`
     =====[DEAD]=====
)" << std::endl;
}


void printStats(GreenHouseController greenHouse, int water, int seeds) {
    int humidity = greenHouse.getCurrentHumidity();
    bool isControlerEnabled = greenHouse.getControlerState();
    std::cout << "Current humidity: " << humidity;
    std::cout << "Available water: " << water;
    std::cout << "Available seeds: " << seeds;
    std::cout << "Green house control: " << isControlerEnabled ? "ON" : "OFF";
}


int getWater() {
    return rand() % 10 + 1;
}


int getSeeds() {
    return rand() % 3;
}


void printMenu() {
    std::cout << "----------------------------------------------\n";
    std::cout << "1. Start next day\n";
    std::cout << "2. Plant/Change a plant\n";
    std::cout << "3. Water a plant\n";
    std::cout << "4. Turn on/off green house controler\n";
    std::cout << "5. Exit\n";
    std::cout << "----------------------------------------------\n";
}