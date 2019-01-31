//
//  main.cpp
//  quad2Jan31
//
//  Created by Sarah Schuster-Johnson on 1/30/19.
//  Copyright © 2019 Sarah Schuster-Johnsobn. All rights reserved.
//

//
//  main.cpp
//  assignment3
//
//  Created by Sarah Schuster-Johnson on 1/15/19.
//  Copyright © 2019 Sarah Schuster-Johnsobn. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include <cmath>
#include <utility>
#include <math.h>
#define PI 3.14159265
/*
 *coordinate struct holding x and y coordinates for a point
 */
struct point
{
    int x;
    int y;
};
/*
 *Quadrilateral struct
 * contains each point, side, angle and slope (of each length)
 */
struct Quadrilateral
{
    point        p[4];
    float        side[4];
    float        angle[4];
    double       slope [4];
};
/*
 * finds length of each side
 * finds difference between x and y coordinates, and computes pyth
 * to find the length
 * returns length
 */
double length(Quadrilateral& shape, int i1, int i2)
{
    double    dx    = abs(shape.p[i1].x - shape.p[i2].x);
    double    dy    = abs(shape.p[i1].y - shape.p[i2].y);
    return sqrt((double)(dx * dx) + (dy * dy));
}
/*
 * Finds Slope
 * finds the difference between each x value and each y value
 * returns the x dif divided by the y dif
 */
double findSlope(Quadrilateral& shape, int i1, int i2 )
{
    double run =     abs(shape.p[i2].x - shape.p[i1].x);
    double rise =    abs(shape.p[i1].y - shape.p[i2].y);
    return (double) rise / run;
}
/*
 * Find angle
 * Finds the angle using the cross dot product, law of sins and cos,
 * Using atan2
 * returns degree of angle
 */
double angle(Quadrilateral& shape, int i)
{
    // return ange at vertex point i1
    int        iNext        = (i + 1) % 4;            //in positive rotation order
    int        iPrev        = ((i - 1) + 4) % 4;
    double    sideNext    = shape.side[i];        //sides in positive rotation order
    double    sidePrev    = shape.side[iPrev];
    //next vector using points relative to center vertex
    double dxn    = shape.p[iNext].x - shape.p[i].x;
    double dyn    = shape.p[iNext].y - shape.p[i].y;
    //previous vector using points relative to center vertex
    double dxp    = shape.p[iPrev].x - shape.p[i].x;
    double dyp    = shape.p[iPrev].y - shape.p[i].y;
    //dot product used to caclulate cosine of angle subtended by Next,Prev
    // Vnext dot Vprev    = cos(theta) * length(sideNext) * length(sidePrev)
    double co    = (dxn * dxp + dyn * dyp)/(sideNext*sidePrev);
    if (abs(co) == 1)
    {
        std::cout<<"error 4"<<std::endl;
        exit(1);
    }
    //cross product used to caclulate cosine of angle subtended by Next,Prev
    // Vnext cross Vprev    = sin(theta) * length(sideNext) * length(sidePrev)
    double si    = (dxn * dyp - dxp * dyn)/(sideNext*sidePrev);
    
    //use atan2 to get  -180 < angle  < 180
    //    if angle < 180, add 380 to get positive rotation angle size
    double temp2    = atan2(si,co) * 180./M_PI;
    if( temp2 < 0.)
    {
        temp2 += 360.;
    }
    return temp2;
}
/*
 * Fill Data
 * Fills each sides length, angle and slope (of each length)
 */
void fillData(Quadrilateral& shape)
{
    for (int i1 = 0; i1 < 4 ; i1++){
        shape.side[i1] = length(shape, i1, (i1 + 1) % 4 );
    }
    for (int i1 = 0; i1 < 4 ; i1++){
        shape.angle[i1] = angle(shape,i1);
    }
    for (int i1 = 0; i1 < 4 ; i1++){
        shape.slope[i1] = findSlope(shape,i1,(i1 + 1) % 4);
    }
}
/*
 * Fill Coordinates in shape Struct
 * splits string into coordinates seperated by a space
 */


/*
 * Checks if opposite angles are equal
 * returns true all opposite angles are equal
 */
bool checkOppositeAnglesEqual(Quadrilateral& shape)
{
    return (shape.angle[0] == shape.angle[2] && shape.angle[1] == shape.angle[3] );
}
/*
 * Checks if diagonal angles bisect
 * returns true if diagonals bisect
 */
bool checkDiagonalsBisect(Quadrilateral& shape)
{
    int runAC = shape.p[2].x / 2;
    int riseAC = shape.p[2].y / 2;
    int runBD = abs(shape.p[1].x - shape.p[3].x) / 2;
    int riseBD = abs(shape.p[1].y - shape.p[3].y) / 2;
    int coordX1 = shape.p[0].x + runAC;
    int coordY1 = shape.p[0].y + riseAC;
    int coordX2 = shape.p[1].x - runBD;
    int coordY2 = shape.p[1].y + riseBD;
    return (coordX1 == coordX2 && coordY1 == coordY2);
}

/*
 * Check if opposite sides are equal
 * returns true if opposite sides are equal
 */
bool checkOppositeSidesEqual(Quadrilateral& shape)
{
    return (shape.side[0] == shape.side[2] && shape.side[1] == shape.side[3]);
}
/*
 * Check if adjacent Angles are Supplementary
 * returns true if adjacent Angles are Supplementary
 */
bool checkAdjacentAnglesSupp(Quadrilateral& shape)
{
    double temp [4];
    for (int i1 = 0; i1 < 4 ; i1++)
        temp[i1] = shape.angle[i1] + shape.angle[(i1+1) % 4];
    double comp = 180;
    double epsilon = 0.001;
    if (std::abs(temp[0] - comp) < epsilon){
        if (std::abs(temp[1] - comp) < epsilon){
            if (std::abs(temp[2] - comp) < epsilon){
                if (std::abs(temp[3] - comp) < epsilon){
                    return true;
                }
            }
        }
    }
    return false;
}
/*
 * Check if lengths are equal
 * returns true if lengths are equal
 */
bool checkEqualLengths(Quadrilateral& shape )
{
    if ( shape.side[0] == shape.side[1] && shape.side[1] == shape.side[2] && shape.side[3] == shape.side[0] ){
        return true;
    }
    return false;
}
/*
 * Check if ALL angles are right angles
 * returns true if ALL angles are right angles
 */
bool checkAllRightAngles ( Quadrilateral& shape )
{
    if (shape.angle[0] == 90 && shape.angle[1] == 90 && shape.angle[2] == 90 && shape.angle[3] == 90){
        return true;
    }
    return false;
}
/*
 * Check if shape is a parallelogram
 * returns true if all conditions are met: opposite sides are equal, oposite angles are equal, adjacent angles are supplementary, diagonals bisect
 */
bool checkIfParallelogram ( Quadrilateral& shape  )
{
    return ( checkAdjacentAnglesSupp(shape) == true && checkDiagonalsBisect(shape) == true && checkOppositeSidesEqual(shape) == true && checkOppositeAnglesEqual(shape) == true );
}
/*
 * Check if shape is a kite
 * returns true if adjacent sides are equal
 */
bool checkIfKite ( Quadrilateral& shape )
{
    if ( (shape.side[1] == shape.side[2] && shape.side[3] == shape.side[0]) ||
         (shape.side[2] == shape.side[3] && shape.side[0] == shape.side[1]) ){
        return true;
    }
    return false;
}
/*
 * Check if shape is a trapazoid
 * returns true if one pair of opposite sides have equal slopes/are parallel
 */
bool checkIfTrapazoid ( Quadrilateral& shape )
{
    double epsilon = 0.001;
    if ( (std::abs(shape.slope[0] - shape.slope[2]) < epsilon) &
        (std::abs(shape.slope[1] - shape.slope[3]) < epsilon) ){
        return true;
    }
    
    return false;
}
/*
 * Check if shape is a rhombus
 * returns true if all lengths are equal
 */
bool checkIfRhombi ( Quadrilateral& shape )
{
    return (checkEqualLengths(shape));
}
/*
 * Identifies which shape it is
 * prints the shape identified
 */
std::string checkShape( Quadrilateral& shape)
{
    if ( checkAllRightAngles(shape) ){
        if ( checkEqualLengths(shape) ){
            return "square";
        }
        return "rectangle";
    }
    else
        if ( checkIfParallelogram(shape) ){
            if ( checkIfRhombi(shape) ){
                return "rhombi";
            }
            return "parallelogram";
        }
        else{
            if ( checkIfKite(shape) ){
                return "kite";
            }
            if ( checkIfTrapazoid(shape)){
                return "trapazoid";
            }
        }
    return "quadrilateral";
}
void lineValidity(int numValues)
{
    if ((numValues > 5) | (numValues < 5))
    {
        std::cout<<"error 1"<<std::endl;
        exit(1);
    }
}
void checkCollision(Quadrilateral& shape)
{
    bool check = true;
    int i = 0;
    for (int i1 = 1; i1 < 4; i1++){
        if(( (shape.p[i].x-shape.p[i1].x) == 0)
           & ((shape.p[i].y - shape.p[i1].y) == 0)){
            check =false;
        }
    }
    i = 2;
    for (int i1 = 1; i1 < 4; i1+=2){
        if( (shape.p[i].x == shape.p[i1].x) &
           (shape.p[i].y == shape.p[i1].y)){
            check =false;
        }
    }
    if((shape.p[3].x == shape.p[1].x)
       &(shape.p[3].y == shape.p[1].y)){
        check =false;
    }
    if (check == false)
    {
        std::cout<<"error 2"<<std::endl;
        exit(1);
    }
}
void checkIntersection(Quadrilateral& shape)
{
    if (checkOppositeSidesEqual(shape) == true)
    {
        return;
    }
    float a = shape.angle[0] + shape.angle[1] + shape.angle[2] + shape.angle[3];
    if ( a > 700) {
        std::cout<<"error 3"<<std::endl;
        exit(1);
    }
}
std::string saveCoordinates( std::string line, Quadrilateral& shape)
{
    std::string strWords[line.length()-6];
    int counter = 0;
    for(int i=0 ; i<line.length()-1 ; i++){
        if(line[i] == ' '){
            counter++;
            i++;
        }
        strWords[counter] += line[i];
    }
    lineValidity(counter);
    int num;
    int num2;
    for (int i = 1, j = 0 ; i < 4 ; i++, j+=2)
    {
        if ( (std::istringstream ( strWords[j] ) >> num).fail() )
        {
            std::cout<<"error 1"<<std::endl;
            exit(1);
        };
        if ( (std::istringstream ( strWords[j+1 ] ) >> num2).fail())
        {
            std::cout<<"error 1"<<std::endl;
            exit(1);
        };
        if (num > 100 | num2 > 100 | num < 0 | num2 < 0)
        {
            std::cout<<"error 1"<<std::endl;
            exit(1);
        }
        shape.p[i].x = num;
        shape.p[i].y = num2;
    }
    fillData(shape);
    checkCollision(shape) ;
    checkIntersection(shape);
    return checkShape(shape);
}
/*
 * read file containing coordinates to each shape
 * interprests data and prints each shape identified
 */
void readFile( const std::string filename, const std::string solution  )
{
    std::string          line;
    std::ifstream        infile(filename);
    std::string          solLine;
    std::ifstream        inSolFile(solution);
    struct Quadrilateral shape;
    shape.p[0].x = 0;
    shape.p[0].y = 0;
    int count = 0;
    std::string  temp [20];
    for ( std::string solLine; getline( inSolFile, solLine );){
        temp [count] = solLine;
        count++;
    }
    count = 0;
    for( std::string line; getline( infile, line ); ){
        std::string check = saveCoordinates(line, shape);
        if (check != temp [count]){
            std::cout<<"wrong"<<std::endl;
        }
        else{
            std::cout<<check<<std::endl;
        }
        count++;
    }
}
int main(int argc, const char * argv[])
{
    if(argc > 2){
        readFile(argv[1], argv[2]);
    }
    readFile("quad1.txt", "sol1.txt");
    return 0;
}
