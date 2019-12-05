/***************************************
 * AUTHOR                : Justin Kuhn, Anna Ma, Kevin Prada
 * Project 2             : I Love Baseball
 * CLASS                 : CS8
 * SECTION               : MW 9:45-11:10AM TTH 9:45-11:50AM
 * Due Date              : 12/5/19
 * *************************************/

#ifndef STADIUMCOORDINATES_H
#define STADIUMCOORDINATES_H
#include <string>
using namespace std;
/*******************************************************************
 *  stadimCoordinates structute
 *     Coordinates associated with each staium,
 * *****************************************************************/

struct StadiumCoordinates
{
    string stadiumName;     //ATT- name of stadium
    int x;                  //ATT - x coord on map
    int y;                  //ATT - y coord on map
};


#endif // STADIUMCOORDINATES_H
