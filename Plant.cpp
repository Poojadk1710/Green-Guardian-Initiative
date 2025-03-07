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
#include "Plant.h"

Plant::Plant(int x, int y) : x(x), y(y), plantStage(PlantStage::Seed) {}

Plant::~Plant() { this->plantStage = PlantStage::Seed; }

unsigned int Plant::grow() {
    unsigned int seedsGenerated = 0;
    if (this->plantStage < PlantStage::Year4) {
        switch (this->plantStage) {
            case PlantStage::Seed:
                this->plantStage = PlantStage::Year1;
                break;
            case PlantStage::Year1:
                this->plantStage = PlantStage::Year2;
                break;
            case PlantStage::Year2:
                this->plantStage = PlantStage::Year3;
                seedsGenerated = 1;
                break;
            case PlantStage::Year3:
                this->plantStage = PlantStage::Year4;
                seedsGenerated = 2;
                break;
            default:
                this->plantStage = PlantStage::Year4;
                break;
        }
    }

    return seedsGenerated;
}

// This is required for Toxicity reduction
bool Plant::isMature() const {
    return this->plantStage > PlantStage::Seed &&
           this->plantStage < PlantStage::Year4;
}

bool Plant::isDead() const { return this->plantStage == PlantStage::Year4; }
