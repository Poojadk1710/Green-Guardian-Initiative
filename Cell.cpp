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

#include "Cell.h"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

#include "Gopher.h"
#include "Rat.h"
#include "Wolf.h"

/**
 * @return array<unsigned int>{seedsCount, maturePlantsCount}
 */
std::array<unsigned int, 2> Cell::getPlantsCount() const {
    unsigned int seedsCount = 0;
    unsigned int maturePlantsCount = 0;
    for (Plant* plant : this->plants) {
        if (plant->isMature()) {
            maturePlantsCount++;
        } else {
            seedsCount++;
        }
    }

    return std::array<unsigned int, 2>{seedsCount, maturePlantsCount};
}

/**
 * @return array<unsinged int, unsigned int>{
 *   { fedRatsCount, starvingRatsCount },
 *   { fedGophersCount, starvingGophersCount },
 *   { fedWolvesCount, starvingWolvesCount }
 * }
 */
std::array<std::array<unsigned int, 2>, 3> Cell::getPredatorsCount() const {
    unsigned int fedRatsCount = 0;
    unsigned int starvingRatsCount = 0;
    unsigned int fedGophersCount = 0;
    unsigned int starvingGophersCount = 0;
    unsigned int fedWolvesCount = 0;
    unsigned int starvingWolvesCount = 0;

    for (Predator* predator : this->predators) {
        bool isStarving = predator->isStarving();

        switch (predator->getType()) {
            case PredatorType::Rat:
                if (isStarving) {
                    starvingRatsCount++;
                } else {
                    fedRatsCount++;
                }
                break;
            case PredatorType::Gopher:
                if (isStarving) {
                    starvingGophersCount++;
                } else {
                    fedGophersCount++;
                }
                break;
            case PredatorType::Wolf:
                if (isStarving) {
                    starvingWolvesCount++;
                } else {
                    fedWolvesCount++;
                }
                break;
            default:
                break;
        }
    }

    return std::array<std::array<unsigned int, 2>, 3>{
        fedRatsCount,    starvingRatsCount,    // rats count
        fedGophersCount, starvingGophersCount, // gophers count
        fedWolvesCount,  starvingWolvesCount,  // wolves count
    };
}

// Initial Setup

Cell::Cell(int x, int y, unsigned int initialToxicityLevel, int numOfSeeds,
           int numOfRats, int numOfGophers, int numOfWolves)
    : x(x), y(y), toxicityLevel(initialToxicityLevel) {
    // Add seeds to the cell
    for (int i = 0; i < numOfSeeds; ++i) {
        Plant* plant = new Plant(x, y);
        this->plants.push_back(plant);
    }

    // Add predators to the cell
    for (int i = 0; i < numOfRats; ++i) {
        class Rat* rat = new class Rat(x, y);
        this->predators.push_back(rat);
    }
    for (int i = 0; i < numOfGophers; ++i) {
        class Gopher* gopher = new class Gopher(x, y);
        this->predators.push_back(gopher);
    }
    for (int i = 0; i < numOfWolves; ++i) {
        class Wolf* wolf = new class Wolf(x, y);
        this->predators.push_back(wolf);
    }
}

// For Debug purposes

void Cell::printCurrentState() {
    std::array<unsigned int, 2> plantsCount = this->getPlantsCount();
    unsigned int seedsCount = plantsCount.at(0);
    unsigned int maturePlantsCount = plantsCount.at(1);

    std::array<std::array<unsigned int, 2>, 3> predatorsCount =
        this->getPredatorsCount();
    unsigned int fedRatsCount = predatorsCount[0][0];
    unsigned int starvingRatsCount = predatorsCount[0][1];
    unsigned int fedGophersCount = predatorsCount[1][0];
    unsigned int starvingGophersCount = predatorsCount[1][1];
    unsigned int fedWolvesCount = predatorsCount[2][0];
    unsigned int starvingWolvesCount = predatorsCount[2][1];

    std::cout << "Cell(" << this->x << ", " << this->y << ")\n";
    std::cout << "\tSeeds 🌱: " << seedsCount << "\n";
    std::cout << "\tMature Plants 🌿: " << maturePlantsCount << "\n";
    std::cout << "\tRats 🐭: " << fedRatsCount << "," << starvingRatsCount
              << "\n";
    std::cout << "\tGophers 🐹: " << fedGophersCount << ","
              << starvingGophersCount << "\n";
    std::cout << "\tWolves 🐺: " << fedWolvesCount << "," << starvingWolvesCount
              << "\n";
    std::cout << std::setfill('-') << std::setw(20) << "\n";
}

// Life cycle of plants

unsigned int Cell::growPlants() {
    unsigned int seedsGenerated = 0;
    for (Plant* plant : plants) {
        unsigned int seeds = plant->grow();
        this->seedsProduced += seeds;
        seedsGenerated += seeds;
    }

    return seedsGenerated;
}

bool isPlantDead(Plant* plant) { return plant->isDead(); }

void Cell::handlePlantDeaths() {
    // Remove dead plants from the cell
    std::remove_if(this->plants.begin(), this->plants.end(), isPlantDead);

    /*
  for(Plant* plant: this->plants) {
      if (plant->isDead()) {
          auto pos = std::find(plants.begin(), plants.end(), plant);
          delete plant;
          this->plants.erase(pos);
      }
  }
*/
     std::vector<Plant*> deadPlants;
    for (Plant* plant : this->plants) {
        if (plant->isDead()) {
            deadPlants.push_back(plant);
            this->deadPlants++;
        }
    }

    for (Plant* plant : deadPlants) {
        auto plant_itr =
            std::find(this->plants.begin(), this->plants.end(), plant);
        if (plant_itr != this->plants.end()) {
            this->plants.erase(plant_itr);
        }

        if (plant != nullptr) {
            delete plant;
        }
    }
}

void Cell::reCalculateToxicity() {
    std::array<unsigned int, 2> plantsCount = this->getPlantsCount();
    unsigned int maturePlantsCount = plantsCount.at(1);

    unsigned int toxicityReduction = std::floor(maturePlantsCount / 5);
    this->toxicityLevel -= toxicityReduction;
}

void Cell::addPlant() {
    Plant* plant = new Plant(this->x, this->y);
    plants.push_back(plant);
}

// Predator dynamics

bool isSeed(Plant* plant) { return !plant->isMature(); }

bool isWolfFeed(Predator* predator) {
    PredatorType type = predator->getType();
    return type == PredatorType::Rat || type == PredatorType::Gopher;
}

void Cell::predatorsFeed() {
    // Feed rats and gophers
    for (Predator* predator : this->predators) {
        PredatorType type = predator->getType();
        if (type == PredatorType::Rat || type == PredatorType::Gopher) {
            // Find seed to feed
            int feedAmount = predator->feedAmount();
            int i;
            for (i = 0; i < feedAmount; i++) {
                auto plant_itr = std::find_if(this->plants.begin(),
                                              this->plants.end(), isSeed);

                if (plant_itr == this->plants.end()) {
                    break;
                }

                // Delete seed
                delete (*plant_itr);
                this->plants.erase(plant_itr);
            }

            // Feed rat or gopher
            if (i == 0) {
                // feed not found
                predator->increaseStarvationYears();
            } else {
                predator->feed();
            }
        }
    }

    // Feed wolf
    std::vector<Predator*> wolfFeeds;
    for (Predator* predator : this->predators) {
        if (predator->getType() == PredatorType::Wolf) {
            Predator* wolf = predator;
            // Feed on rat or gopher
            auto wolfFeed = std::find_if(this->predators.begin(),
                                         this->predators.end(), isWolfFeed);
            // Wolf feed found
            if (wolfFeed == this->predators.end()) {
                wolf->increaseStarvationYears();
            } else {
                wolfFeeds.push_back(*wolfFeed);
                wolf->feed();
            }
        }
    }

    // Remove wolfFeeds
    for (Predator* wolfFeed : wolfFeeds) {
        auto wolfFeed_itr =
            std::find(this->predators.begin(), this->predators.end(), wolfFeed);
        if (wolfFeed_itr != this->predators.end()) {
            this->predators.erase(wolfFeed_itr);
        }
    }
}

bool Cell::predatorOccupancy() const {
    std::array<std::array<unsigned int, 2>, 3> predatorsCount =
        this->getPredatorsCount();
    unsigned int ratsCount = predatorsCount[0][1] + predatorsCount[0][1];
    unsigned int gophersCount = predatorsCount[1][1] + predatorsCount[1][1];
    unsigned int wolvesCount = predatorsCount[2][1] + predatorsCount[2][1];

    return ratsCount <= 3 && gophersCount <= 1 && wolvesCount <= 1;
}

std::stringstream Cell::displayStrStream() const {
    std::array<unsigned int, 2> plantsCount = this->getPlantsCount();
    unsigned int seedsCount = plantsCount.at(0);
    unsigned int maturePlantsCount = plantsCount.at(1);

    std::array<std::array<unsigned int, 2>, 3> predatorsCount =
        this->getPredatorsCount();
    unsigned int fedRatsCount = predatorsCount[0][0];
    unsigned int starvingRatsCount = predatorsCount[0][1];
    unsigned int fedGophersCount = predatorsCount[1][0];
    unsigned int starvingGophersCount = predatorsCount[1][1];
    unsigned int fedWolvesCount = predatorsCount[2][0];
    unsigned int starvingWolvesCount = predatorsCount[2][1];

    // std::cout << "+--------+\n";
    // std::cout << "|🌱      |\n";
    // std::cout << "|🌿      |\n";
    // std::cout << "|🐭🐭🐭  |\n";
    // std::cout << "|🐹🐺    |\n";
    // std::cout << "+--------+\n";
    std::stringstream ss;


    ss << "+--------+\n";

    // Showing toxicity level
    ss << "|☠ " << std::setfill(' ') << std::setw(6) << this->toxicityLevel
       << "|\n";

    // Showing seeds count
    ss << "|🌱" << std::setfill(' ') << std::setw(2) << seedsCount;
    // Showing mature plants count
    ss << "🌿" << std::setfill(' ') << std::setw(2) << maturePlantsCount
       << "|\n";

    // showing fed and starving rats
    ss << "|";
    for (unsigned int i = 0; i < fedRatsCount; i++) {
        ss << "🐭";
    }
    unsigned int spacesCount = 4 - (fedRatsCount + starvingRatsCount);
    for (unsigned int i = 0; i < spacesCount; i++) {
        ss << "  ";
    }
    for (unsigned int i = 0; i < starvingRatsCount; i++) {
        ss << "🐭";
    }
    ss << "|\n";

    // showing fed and starving gophers and wolves
    ss << "|";
    // showing fed gopher
    for (unsigned int i = 0; i < fedGophersCount; i++) {
        ss << "🐹";
    }
    // showing fed wolve
    for (unsigned int i = 0; i < fedWolvesCount; i++) {
        ss << "🐺";
    }

    spacesCount = 4 - (fedGophersCount + fedWolvesCount + starvingGophersCount +
                       starvingWolvesCount);
    for (unsigned int i = 0; i < spacesCount; i++) {
        ss << "  ";
    }

    // showing starving gopher
    for (unsigned int i = 0; i < starvingGophersCount; i++) {
        ss << "🐹";
    }
    // showing starving wolves
    for (unsigned int i = 0; i < starvingWolvesCount; i++) {
        ss << "🐺";
    }
    ss << "|\n";

    ss << "+--------+\n";

    return ss;
}
