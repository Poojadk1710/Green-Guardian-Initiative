/*******************************************************
Name      :  Pooja Kulkarni
Class     :  CSCI 2312 Section 001
PA#       :  Project
Due Date  :  04/29/2024
*******************************************************/

/*********************************************************
* Summary: This file includes the implementation for Address.cpp.
*
* Author: Pooja Kulkarni
* Student ID : 111024438
* Created: April 19, 2024
* Summary of Modifications [if applicable]:
*      April 19, 2024 - Initial implementation attempt
*      April 20, 2024- Completed implementation of all functions
*      April 21, 2024 - Resolved compilation issues and successfully compiled the code
*      April 22, 2024 - Added coding style, comments and committed the code
*      April 25, 2024 - Conducted thorough testing and ensured functionality according to specifications
*      April 29, 2024 - Finalized documentation and submission for Project
*******************************************************/

#include <iostream>
#include <fstream>
#include "Grid.h"
#include "Simulation.h"

int main() {
    Grid grid;
    grid.randomInitialization();
    grid.display();
    grid.progressYear();
    // Display the updated state of the grid after progressing the year
    grid.display();

    // Plant objects
    Plant plant1(0, 0);
    Plant plant2(1, 1);

    //Performs operations on these plants, like growing them
    unsigned int seedsGenerated1 = plant1.grow();
    unsigned int seedsGenerated2 = plant2.grow();

    // Check the stage of the plants
    bool isMature1 = plant1.isMature();
    bool isDead2 = plant2.isDead();


    Cell cell(1, 1, 5, 5, 2, 1, 1);
    cell.printCurrentState();
    std::cout << cell.displayStrStream().str(); // Use displayStrStream() to print cell state
    cell.predatorsFeed(); // Corrected function name from `predatorFeed` to `predatorsFeed`
    cell.growPlants();
    cell.printCurrentState();
    std::cout << cell.displayStrStream().str(); // Use displayStrStream() to print cell state
    cell.predatorsFeed(); // Corrected function name from `predatorFeed` to `predatorsFeed`
    cell.growPlants();
    cell.printCurrentState();
    std::cout << cell.displayStrStream().str(); // Use displayStrStream() to print cell state

    std::cout << "🌱🌿🐺🐭🐹\n";

    // Example usage of Simulation
    Simulation simulation;
    // Progress the simulation for 7 years
    for (int year = 0; year < 7; ++year) {
        simulation.progressYear();
    }

    // View statistics of the simulation
    simulation.viewStat();
    return 0;
}
