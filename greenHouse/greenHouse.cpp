#include <iostream>
#include <limits>

enum healthStatus {
	HEALTHY,
	DRY,
	DEAD,
    UNKNOWN,
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
        health = UNKNOWN;
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
        if (currentHumidity - decrease < 0) {
            currentHumidity = 0;
        }
        else {
            currentHumidity -= decrease;
        }
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
        std::cout << plantName << "; " << currentHumidity << "%; " << printHealthStatus() << std::endl;
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
            if (isControlerEnabled && plant.getHealthStatus() != DEAD && plant.getHealthStatus() != UNKNOWN) {
                int waterAmount = rand() % 10 + 5;
                plant.water(waterAmount);
            }
            if (plant.getHealthStatus() != UNKNOWN) {
                plant.updateHealthStatus();
            }
        }
    }


	void addPlant(std::string plantName = "Sunflower", int currentHumidity = 100, healthStatus health = HEALTHY) {
		plants[selectedPlant] = Plant(plantName, currentHumidity, health);
	}


    void printPlant();


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
        std::cout << "===============================================\n";
        for (int i = 0; i < 10; i++) {
            std::cout << i + 1 << "; ";
            plants[i].printStats();
        }
        std::cout << "===============================================\n";
    }


    void updateDays() {
        days++;
    }


    int getDays() {
        return days;
    }


    void changePlant(int index, int& seeds);


    void waterPlant(int amount) {
        plants[selectedPlant].water(amount);
        plants[selectedPlant].updateHealthStatus();
    }


    healthStatus getCurrentHealthState() {
        return plants[selectedPlant].getHealthStatus();
    }
};


void printStats(GreenHouseController greenHouse, int water, int seeds);
int getWater();
int getSeeds();
void printMenu(GreenHouseController greenHouse, int water, int seeds);
int getMenuChoice();
void mainMenu(GreenHouseController& greenHouse, int& water, int& seeds);
void printHealthy();
void printDry();
void printDead();
void waitEnterKey();


void GreenHouseController::printPlant() {
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

void GreenHouseController::changePlant(int index, int& seeds) {
    if ((plants[index].getHealthStatus() == DEAD || plants[index].getHealthStatus() == UNKNOWN) && seeds > 0) {
        selectedPlant = index;
        addPlant();
        seeds--;
    }
    else if ((plants[index].getHealthStatus() == DEAD || plants[index].getHealthStatus() == UNKNOWN) && seeds == 0) {
        std::cout << "Not enough seeds to plant a new plant.\n";
        waitEnterKey();
    }
    else {
        selectedPlant = index;
    }
}


int main() {
	srand(time(NULL));

	GreenHouseController greenHouse = GreenHouseController();
    int water = 0;
    int seeds = 0;
    greenHouse.addPlant();

    mainMenu(greenHouse, water, seeds);

    return 0;
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
    bool isControlerEnabled = greenHouse.getControlerState();
    std::cout << "======== S T A T S ========\n";
    std::cout << "Day: " << greenHouse.getDays() << '\n';
    std::cout << "Available water: " << water << '\n';
    std::cout << "Available seeds: " << seeds << '\n';
    std::cout << "Greenhouse control: " << (isControlerEnabled ? "ON" : "OFF") << "\n";
    std::cout << "===========================\n\n";
}


int getWater() {
    return rand() % 10 + 1;
}


int getSeeds() {
    return rand() % 3;
}


void printMenu(GreenHouseController greenHouse, int water, int seeds) {
    printStats(greenHouse, water, seeds);
    std::cout << "============= M A I N   M E N U ==============\n";
    std::cout << "1. See plant\n";
    std::cout << "2. Start next day\n";
    std::cout << "3. Plant/Change a plant\n";
    std::cout << "4. Water current plant\n";
    std::cout << "5. Turn on/off green house controler\n";
    std::cout << "6. Exit\n";
    std::cout << "==============================================\n";
}


int getMenuChoice() {
    int choice = 0;
    do {
        std::cout << "Enter a function number: ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error. Please enter a valid number.\n";
            continue;
        }
    } while (choice < 1 || choice > 6);

    return choice;
}


int getPlantPlaceNumber() {
    int choice = 0;
    do {
        std::cout << "Enter a plant number: ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error. Please enter a valid number.\n";
            continue;
        }
    } while (choice < 1 || choice > 10);

    return choice;
}


void waitEnterKey() {
    // stops program until enter is pressed

    std::cout << "Press enter to continue..." << std::endl;
    std::cin.get();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


void mainMenu(GreenHouseController& greenHouse, int& water, int& seeds) {
    // Main menu logic
    bool isRunning = true;
    int choice = 0;

    while (isRunning) {
        std::cout << "\033[2J\033[H" << std::flush;
        printMenu(greenHouse, water, seeds);

        choice = getMenuChoice();
        if (choice == 1) {
            // See plant
            std::cout << "\033[2J\033[H" << std::flush;
            greenHouse.printPlant();
            std::cout << "Current humidity: " << greenHouse.getCurrentHumidity() << "%\n\n";
            waitEnterKey();
        }
        else if (choice == 2) {
            // Start next day
            water = getWater();
            seeds += getSeeds();
            greenHouse.updateStatus();
            greenHouse.updateDays();
        }
        else if (choice == 3) {
            // Plant/change a plant
            std::cout << "\033[2J\033[H" << std::flush;
            greenHouse.printGreenHouse();
            int plant = getPlantPlaceNumber();
            greenHouse.changePlant(plant - 1, seeds);
        }
        else if (choice == 4) {
            // Water current plant
            if (water == 0) {
                std::cout << "Not enough water.\n";
                waitEnterKey();
            }
            else if (greenHouse.getCurrentHealthState() == DEAD) {
                std::cout << "You can't water dead plants to increase humidity.\n";
                waitEnterKey();
            }
            else {
                greenHouse.waterPlant(20);
                water--;
            }
        }
        else if (choice == 5) {
            // Turn on/off greenhouse controller
        }
        else if (choice == 6) {
            // Exit
            isRunning = false;
        }
    }
}