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

#include "Grid.h"

#include <iostream>
#include <set>

// Lifecylcle of Plant

void Grid::randomInitialization() {
    srand(time(0));

    // Randomly distribute seeds, rats, gophers, and wolves across the grid
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            // Generate random numbers for each entity
            int numOfSeeds = (rand() % 11)+5; // Random number between 0 and 10
            int numOfRats = (rand() % 7)+1;   // Random number between 0 and 5
            int numOfGophers = (rand() % 5)+3; // Random number between 0 and 3
            int numOfWolves = (rand() % 4)+2;  // Random number between 0 and 3
            int toxicityLevels = (rand() % 5)+3;

            // Generate a random numofseeds in the cells it should happen for whole grid
            Cell *cell = new Cell(i, j, toxicityLevels, numOfSeeds, numOfRats, numOfGophers, numOfWolves);
            this->grid[i][j] = cell;
        }
    }
}

#include <fstream>
#include <sstream>

void Grid::fileInitialization() {
    // Define file paths for each input file
    std::string seedsFile = "seeds.txt";
    std::string ratsFile = "rats.txt";
    std::string toxicityFile = "toxicity.txt";
    std::string gophersFile = "gophers.txt";
    std::string wolvesFile = "wolves.txt";

    // Declare arrays to store data read from files
    std::array<std::array<int, SIZE>, SIZE> toxicityLevelsFromFile;
    std::array<std::array<int, SIZE>, SIZE> seedsPlacementFromFile;
    std::array<std::array<int, SIZE>, SIZE> ratsPlacementFromFile;
    std::array<std::array<int, SIZE>, SIZE> gophersPlacementFromFile;
    std::array<std::array<int, SIZE>, SIZE> wolvesPlacementFromFile;

    // Read data from toxicity file
    std::ifstream toxicityInput(toxicityFile);
    if (toxicityInput.is_open()) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                toxicityInput >> toxicityLevelsFromFile[i][j];
            }
        }
        toxicityInput.close();
    } else {
        // Handle file opening error
        std::cerr << "Unable to open toxicity file\n";
        return;
    }

    // Repeat similar steps for other input files (seeds, rats, gophers, wolves)

    // Populate grid based on file data
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            // Read data from arrays and initialize cells accordingly
            int toxicityLevel = toxicityLevelsFromFile[i][j];
            int numOfSeeds = seedsPlacementFromFile[i][j];
            int numOfRats = ratsPlacementFromFile[i][j];
            int numOfGophers = gophersPlacementFromFile[i][j];
            int numOfWolves = wolvesPlacementFromFile[i][j];

            // Create cell with data from files
            Cell *cell = new Cell(i, j, toxicityLevel, numOfSeeds, numOfRats, numOfGophers, numOfWolves);
            this->grid[i][j] = cell;
        }
    }
}

void Grid::movePredator() {
    // Initialize random seed
    srand(time(nullptr));

    // Data structure to track visited cells
    std::set<std::pair<int, int>> visitedCells;

    // Loop through each cell in the grid
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            // Move rats
            if (grid[i][j]->getRatsCount() > 0) {
                for (int k = 0; k < grid[i][j]->fetRatsCount(); ++k) {

                    Randomize movement direction for rats
                    int dx = rand() % 3 - 1; // Random movement within [-1, 1]
                    int dy = rand() % 3 - 1; // Random movement within [-1, 1]
                    int new_x = i + dx;
                    int new_y = j + dy;
                    if (new_x >= 0 && new_x < SIZE && new_y >= 0 && new_y < SIZE) {
                        // Check if the new cell is empty and not visited
                        if (grid[new_x][new_y]->isEmpty() && visitedCells.find({new_x, new_y}) == visitedCells.end()) {
                            // Move the rat to the new cell
                            grid[new_x][new_y]->addRat();
                            grid[i][j]->removeRat();
                            // Add the new cell to visited cells
                            visitedCells.insert({new_x, new_y});
                        }
                    }

                }
            }

            // Move gophers
            if (grid[i][j]->getNumOfGophers() > 0) {
                for (int k = 0; k < grid[i][j]->getNumOfGophers(); ++k) {
                    // Randomize movement direction for gophers
                    int dx = rand() % 5 - 2; // Random movement within [-2, 2]
                    int dy = rand() % 5 - 2; // Random movement within [-2, 2]
                    int new_x = i + dx;
                    int new_y = j + dy;
                    if (new_x >= 0 && new_x < SIZE && new_y >= 0 && new_y < SIZE) {
                        // Check if the new cell is empty and not visited
                        if (grid[new_x][new_y]->isEmpty() && visitedCells.find({new_x, new_y}) == visitedCells.end()) {
                            // Move the gopher to the new cell
                            grid[new_x][new_y]->addGopher();
                            grid[i][j]->removeGopher();
                            // Add the new cell to visited cells
                            visitedCells.insert({new_x, new_y});
                        }
                    }
                }
            }

            // Move wolves
            if (grid[i][j]->getNumOfWolves() > 0) {
                for (int k = 0; k < grid[i][j]->getNumOfWolves(); ++k) {
                    // Randomize movement direction for wolves
                    int dx = rand() % 11 - 5; // Random movement within [-5, 5]
                    int dy = rand() % 11 - 5; // Random movement within [-5, 5]
                    int new_x = i + dx;
                    int new_y = j + dy;
                    if (new_x >= 0 && new_x < SIZE && new_y >= 0 && new_y < SIZE) {
                        // Check if the new cell is empty and not visited
                        if (grid[new_x][new_y]->isEmpty() && visitedCells.find({new_x, new_y}) == visitedCells.end()) {
                            // Move the wolf to the new cell
                            grid[new_x][new_y]->addWolf();
                            grid[i][j]->removeWolf();
                            // Add the new cell to visited cells
                            visitedCells.insert({new_x, new_y});
                        }
                    }
                }
            }
        }
    }
}


void Grid::reproduce() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            Cell* cell = this->grid[i][j];
            unsigned int seedsGenerated = cell->growPlants();
        }
    }
}

// Constructor implementation
Grid::Grid() : simulationYear(0) {}

// Destructor
Grid::~Grid() {}

void Grid::initializeGrid() {

  srand(time(0));

  std::array<std::array<unsigned int, SIZE>, SIZE> toxicityLevels;

  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      int toxicityLevel = rand() % 5 + 3;
      toxicityLevels[i][j] = toxicityLevel;
    }
  }
/* distribution range 10-15 */
    unsigned int seedsCount = 10;
    std::array<std::array<int, SIZE>, SIZE> seedsPlacement = {
        1, 0, 1, 0, 1, // grid[0][]
        1, 0, 0, 0, 0, // grid[1][]
        1, 0, 0, 1, 0, // grid[2][]
        0, 2, 0, 0, 0, // grid[3][]
        1, 0, 0, 0, 1  // grid[4][]
    };

    /* distribution range 5-9 */
    unsigned int ratsCount = 9;
    std::array<std::array<int, SIZE>, SIZE> ratsPlacement = {
        1, 0, 1, 0, 1, // grid[0][]
        1, 0, 2, 0, 0, // grid[1][]
        1, 0, 0, 0, 0, // grid[2][]
        0, 1, 0, 0, 0, // grid[3][]
        1, 0, 0, 0, 1  // grid[4][]
    };

    /* distribution range 3-7 */
    unsigned int gophersCount = 6;
    std::array<std::array<int, SIZE>, SIZE> gophersPlacement = {
        1, 0, 1, 0, 1, // grid[0][]
        1, 0, 0, 0, 0, // grid[1][]
        1, 0, 0, 0, 0, // grid[2][]
        0, 0, 0, 0, 0, // grid[3][]
        1, 0, 0, 0, 0  // grid[4][]
    };

    /* distribution range 2-5 */
    unsigned int wolvesCount = 3;
    std::array<std::array<int, SIZE>, SIZE> wolvesPlacement = {
        1, 0, 0, 0, 0, // grid[0][]
        0, 0, 0, 0, 1, // grid[1][]
        0, 0, 0, 0, 0, // grid[2][]
        0, 1, 0, 0, 0, // grid[3][]
        0, 0, 0, 0, 0  // grid[4][]
    };

  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      int toxicityLevel = toxicityLevels[i][j];
      int numOfSeeds = seedsCount[i][j];
      int numOfRats = ratsCount[i][j];
      int numOfGophers = gophersCount[i][j];
      int numOfWolves = wolvesCount[i][j];
      Cell *cell = new Cell(i, j, toxicityLevel, numOfSeeds, numOfRats,
                            numOfGophers, numOfWolves);
        this->grid[i][j] = cell;
    }
  }
}

// void Grid::progressYear() {
//     // Increment simulationYear

//     // grow and reproduce plants

//     // Feed the predators

//     // move predators if required
// }

void Grid::progressYear() {
    // Increment simulation year
    simulationYear++;

    // Grow and reproduce plants
    reproduce();

    // Feed predators and move them
    movePredator();

    // Update cell toxicity
    // updateToxicity();

    // Handle predator starvation
    handlePredatorStarvation();

    // Check if simulation year limit is reached
    if (simulationYear >= 7) {
        endSimulation();
    }
}


void Grid::display() const {
    std::stringstream ss;
    std::string line;
    for (int i = 0; i < SIZE; i++) {
        std::array<std::stringstream, SIZE> cellStreams;
        for (int j = 0; j < SIZE; j++) {
            cellStreams[j] = this->grid[i][j]->displayStrStream();
        }

        while(true) {
            bool done = false;
            for(int j = 0; j < SIZE; j++) {
                if (std::getline(cellStreams[j], line)) {
                    ss << line;
                } else {
                    done = true;
                    break;
                }
            }
            if (done) {
                break;
            }
            ss << "\n";
        }
    }

    std::cout << ss.str();
}


