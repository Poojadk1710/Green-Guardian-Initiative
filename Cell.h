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

#ifndef CELL_H
#define CELL_H

#include <array>
#include <vector>

#include "Plant.h"
#include "Predator.h"

class Cell {
    // Member variables
    int x, y;
    unsigned int toxicityLevel;
    unsigned int seedsProduced;
    unsigned int seedsEaten;
    unsigned int deadPlants;


    std::vector<Plant*> plants;
    std::vector<Predator*> predators;

    /** \brief Returns different plants count */
    std::array<unsigned int, 2> getPlantsCount() const;

    /** \brief Returns predators count */
    std::array<std::array<unsigned int, 2>, 3> getPredatorsCount() const;

public:
    // Initial Setup
    Cell(int x, int y, unsigned int initialToxicityLevel, int numOfSeeds,
         int numOfRats, int numOfGophers, int numOfWolves);

    // For Debug purposes
    void printCurrentState();

    // Life Cycle of Plant
    /** Grow plants and returns count of generated seeds */
    unsigned int growPlants();
    /** Removes plants who've grown past year 3 */
    void handlePlantDeaths();
    /** Reduce toxicity level with mature plants */
    void reCalculateToxicity();
    /** Add a new plant */
    void addPlant();

    // Predator Dynamics
    /** Feed all the predators */
    void predatorsFeed();
    /** Check correct count of predators in the cell */
    bool predatorOccupancy() const;

    std::stringstream displayStrStream() const;
};

#endif
