# Greenhouse project on C++

## The project's description

The program draws a potted plant in the console in 3 different types:
1. Healthy plant (no problem)
2. A drying plant (the plant looks sick, fallen, requires watering)
3. Dead plant (the plant is dead and cannot be restored)

After the drawing, it is suggested to choose one of the program options:
1. Start the next day (reduces humidity by a random number)
2. Plant/Change the plant 
3. View the list of plants
4. Water the plant (moisturizes by 20%)
5. Enable/Turn off the greenhouse controller (humidifies all plants by 5-15%, random value)
6. Exit

There is a random number of units of water available each day. 1 watering requires 1 unit of water, the greenhouse controller requires half of the total water (rounded up).

Also, 0-2 seeds are given out every day, which can be spent on new plants.

## Interface
<img width="245" height="630" alt="plants-states" src="https://github.com/user-attachments/assets/abc077bc-c19e-4da2-88f7-d193f522bdb3" />

3 States of plants

<img width="438" height="324" alt="image" src="https://github.com/user-attachments/assets/175705e1-3e95-405a-924d-bda5dfe5170d" />

Main menu Interface
