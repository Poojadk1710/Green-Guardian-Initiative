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
#ifndef PREDATOR_H
#define PREDATOR_H
#include <vector>
#include <sstream>

enum PredatorType {
    Rat,
    Gopher,
    Wolf,
};

struct Movement {
    int x, y;
};


class Predator {
private:
    int x;
    int y;

    int starvingYears;
    int starvationLimit;

    std::vector<struct Movement> movement;


public:
    Predator(int x, int y, int starvationLimit)
        : x(x), y(y), starvingYears(0), starvationLimit(starvationLimit) {}

    virtual PredatorType getType() const = 0;
    virtual int feedAmount() const = 0;
    void feed() { this->starvingYears = 0; }
    void move(int x, int y) { movement.push_back(Movement{.x = x, .y = y}); }
    void increaseStarvationYears() { this->starvingYears++; }
    bool isStarving() { return starvingYears > 0; }
    bool isDead() { return starvingYears >= starvationLimit; }

};

#endif
