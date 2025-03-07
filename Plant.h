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
#ifndef PLANT_H
#define PLANT_H

enum PlantStage{
    Seed =  0,
    Year1 = 1,
    Year2 = 2,
    Year3 = 3,
    Year4 = 4,
};

class Plant {
private:
    int x;
    int y;
    PlantStage plantStage;

public:
    Plant(int x, int y);
    ~Plant();

    /** Grows plant and returns count of seed generated */
    unsigned int grow();

    /** If the plant is mature */
    bool isMature() const;

    /** If the seed is dead */
    bool isDead() const;
};

#endif