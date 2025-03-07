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
#include "Simulation.h"
#include <fstream>

Simulation::Simulation() : progressionYear(0) {}

void Simulation::progressYear() {
    if (progressionYear < 7) {
        land.movePredator();
        land.growPlants();
        land.handlePlantDeaths();
        land.reCalculateToxicity();
        progressionYear++;
    }
}

void Simulation::viewStat() const {
    // Open an output file for writing simulation results
    std::ofstream outputFile("simulation_results.txt");

    if (!outputFile.is_open()) {
        std::cerr << "Unable to open the output file." << std::endl;
        return;
    }

    outputFile << "Simulation Results:\n";

    // Calculate and print toxicity levels of each cell
    outputFile << "Toxicity Levels:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            outputFile << "Cell (" << i << ", " << j << "): " << land.getToxicityLevel(i, j) << "\n";
        }
    }

    // Calculate statistics on seeds produced and eaten
    outputFile << "\nStatistical Summary:\n";
    outputFile << "Year: " << progressionYear << "\n";

    // Calculate the total number of seeds produced and eaten
    unsigned int totalSeedsProduced = 0;
    unsigned int totalSeedsEaten = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::array<unsigned int, 2> plantsCount = land.getPlantsCount(i, j);
            totalSeedsProduced += plantsCount[0];
            totalSeedsEaten += (land.getInitialSeedsCount(i, j) - plantsCount[0]);
        }
    }

    outputFile << "Total Seeds Produced: " << totalSeedsProduced << "\n";
    outputFile << "Total Seeds Eaten: " << totalSeedsEaten << "\n";

    // Close the output file
    outputFile.close();
}
