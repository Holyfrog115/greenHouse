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


	Plant(const std::string& plantName, int currentHumidity, healthStatus health) {
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


	void updateWaterStatus() {
		int decrease = rand() % 25 + 5;
		currentHumidity -= decrease;
	}


    void updateHealthStatus() {
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


    std::string printHealthStatus() {
        switch (health) {
            case HEALTHY:
                return "Healthy";
            case DRY:
                return "Dry";
            case DEAD:
                return "Dead";
            default:
                return "Unknown";
        }
    }


    void printStats() {
        std::cout << " - " << plantName << "; " << currentHumidity << "%; " << printHealthStatus() << std::endl;
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


    void updateStatus() {
        for (Plant& plant : plants) {
            plant.updateWaterStatus();
            if (isControlerEnabled && plant.getHealthStatus() != DEAD) {
                int waterAmount = rand() % 10 + 5;
                plant.water(waterAmount);
            }
            plant.updateHealthStatus();
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


	void printPlant() {
		if (plants[selectedPlant].getHealthStatus() == HEALTHY) {
			printHealthy();
		}
        else if (plants[selectedPlant].getHealthStatus() == DRY) {
            printDry();
        }
        else if (plants[selectedPlant].getHealthStatus() == DEAD) {
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


    void printGreenHouse() {
        std::cout << "N; Plant name; Current humidity; Health status\n";
        for (int i = 0; i < 10; i++) {
            std::cout << i + 1 << "; ";
            plants[i].printStats();
        }
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


int getMenuChoice() {
    int choice = 0;
    do {
        std::cout << "Enter function number: ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error. Please enter a valid number.\n";
            continue;
        }
    } while (choice < 1 || choice > 5);

    return choice;
}


void mainMenu(GreenHouseController& greenHouse, int& water, int& seeds) {
    bool isRunning = true;
    int choice = 0;

    while (isRunning) {
        std::cout << "\033[2J\033[H" << std::flush;
        greenHouse.printPlant();
        printStats(greenHouse, water, seeds);
        printMenu();

        choice = getMenuChoice();
        if (choice == 1) {
            greenHouse.updateStatus();
        }
        else if (choice == 2) {
            greenHouse.printGreenHouse();
        }
    }
}