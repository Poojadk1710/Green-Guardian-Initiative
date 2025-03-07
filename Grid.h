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

#ifndef GRID_H
#define GRID_H

#include <array>

#include "Cell.h"

#define SIZE 5 // Macro which defines grid size

class Grid {

private:
  std::array<std::array<Cell*, SIZE>, SIZE> grid;
  unsigned int simulationYear;
  std::vector<Predator*> predators;

  void randomInitialization();
  void fileInitialization();

    // Lifecycle of Plant
  void reproduce();

    // Predator Dynamics
  void movePredator();

public:
  Grid();  // Default Constructor
  ~Grid(); // Destructor


    unsigned int getSimulationYear() { return this->simulationYear; }

    // Simulation environment
    void initializeGrid();

    void progressYear();

    // Other member functions
    void display() const;
};
#endif
