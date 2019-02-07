//
//  main.cpp
//  randomQuad
//
//  Created by Sarah Schuster-Johnson on 2/1/19.
//  Copyright © 2019 Sarah Schuster-Johnsobn. All rights reserved.
//
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
void makeSolFile(std::string fileName, std::string word, int num)
{
    std::ofstream myfile;
    myfile.open (fileName);
    for(int i = 0; i < num ; i++)   myfile <<word<<std::endl;
    myfile.close();
}
void makeFile(std::string fileName, std::string word [])
{
    std::ofstream myfile;
    myfile.open (fileName);
    myfile.close();
}
void randomSquare(int num, int seed)
{
    std::ofstream myfile;
    myfile.open ("square.txt");
    int i = 0;
    for (  ; i < num ; i ++)
    {
        int num= rand() % 100 + 1;
        std::string line [11];
        std::string str = std::to_string(num);
        for (int i = 0 ; i < 11 ; i+=2)                 line [i] =  str;
        line [2] = "0";
        line [8] = "0";
        for (int index = 1 ; index < 10 ; index+=2)     line [index] = " ";
        for(int i = 0; i < 11 ; i++)      myfile << line[i];
        myfile << " " <<std::endl;
    }
    makeSolFile("squareSol.txt", "square", i);
    myfile.close();
}
void randomTrapazoid(int num, int seed)
{
    std::ofstream myfile;
    myfile.open ("trapezoid.txt");
    int i = 0;
    for (  ; i < num ; i ++)
    {
        int a = rand() % 97 + 4;
        int b = rand() % 100 + 1;
        std::string line [11];
        std::string firstX = std::to_string(a);
        std::string secondX = std::to_string(b);
        int c = rand() % a + 1 ;
        int d = (a - c) / 2;
        if (d == 0)                             d++;
        line [0] =  firstX;
        line [2] =  "0";
        line [4] =  std::to_string(a -d);
        line [6] =  secondX;
        line [8] =  std::to_string(d);
        line [10] = secondX;
        for (int index = 1 ; index < 10 ; index+=2)      line [index] = " ";
        for(int i = 0; i < 11 ; i++)                     myfile << line[i];
        myfile << " " <<std::endl;
    }
    makeSolFile("trapezoidSol.txt", "trapezoid", i);
    myfile.close();
}
void randomRhombi(int num, int seed)
{
    std::ofstream myfile;
    myfile.open ("rhombus.txt");
    int i = 0;
    for (  ; i < num ; i ++)
    {
        int a = rand() % 95 + 4;
        int b = rand() % (a-1) + 1;
        int c = (a - b)/2 +1;
        if ( b == c )       c ++;
        std::string line [11];
        std::string A = std::to_string(c);
        std::string B = std::to_string(b);
        std::string C = std::to_string(b + c);
        line [0] =  B;
        line [2] =  A;
        line [4] =  C;
        line [6] =  C;
        line [8] =  A;
        line [10] = B;
        for (int index = 1 ; index < 10 ; index+=2)     line [index] = " ";
        for(int i = 0; i < 11 ; i++)                    myfile << line[i];
        myfile << " " <<std::endl;
    }
    makeSolFile("rhombusSol.txt", "rhombus", i);
    myfile.close();
}
void randomQuadrilateral(int num, int seed)
{
    std::ofstream myfile;
    myfile.open ("quadrilateral.txt");
    int i = 0;
    for (  ; i < num ; i ++)
    {
        int a = rand() % (100 - 75) + 75;
        int b = rand() % (a - 60) + 60;
        int c = rand() % (b - 50) + 50;
        int d = rand() % (c- 30) + 30;
        int e = rand() % (d- 20) +20;
        int f = rand() % (e - 1) +1;
        if ( (double)a/b == (double)d/e)
        {
            a -= 5;
            if (a == b) b += 2;
        }
        std::string line [11];
        line [0] =  std::to_string(c);
        line [2] =  std::to_string(f);
        line [4] =  std::to_string(b);
        line [6] =  std::to_string(a);
        line [8] =  std::to_string(e);
        line [10] =  std::to_string(d);
        for (int index = 1 ; index < 10 ; index+=2)      line [index] = " ";
        for(int i = 0; i < 11 ; i++)                     myfile << line[i];
        myfile << " " <<std::endl;
    }
    myfile.close();
    makeSolFile("quadrilateralSol.txt", "quadrilateral", i);
}
void randomKite1(int num, int seed)
{
    std::ofstream myfile;
    myfile.open ("kite.txt");
    int i = 0;
    for (  ; i < num ; i ++)
    {
        int a = rand() % (98 - 4) +4;
        if ( a % 2 != 0)         a --;
        int b = rand() % (a-3) + 3;
        int c = a - b;
        if (c == b)
        {
            b++;
            c--;
        }
        std::string line [11];
        line [0] =  std::to_string(a);
        line [2] =  "0";
        line [4] =  std::to_string(a);
        line [6] =  std::to_string(a);
        line [8] =std::to_string(b);
        line [10] = std::to_string(c);
        for (int index = 1 ; index < 10 ; index+=2)         line [index] = " ";
        for(int i = 0; i < 11 ; i++)                        myfile << line[i];
        myfile << " " <<std::endl;
    }
    myfile.close();
    makeSolFile("kiteSol.txt", "kite", i);
}
void randomKite2(int num, int seed)
{
    std::ofstream myfile;
    myfile.open ("kite2.txt");
    int i = 0;
    for (  ; i < num ; i ++)
    {
        int b = rand() % (100 -3) + 3;
        int a = rand() % (100 -3) + 3;
        if ( a == b)                                    a -= 1;
        if ( a / 2 == b)                                 a -= 2;
        std::string line [12];
        line [0] =  std::to_string(a);
        line [2] =  "0";
        line [4] =  std::to_string(b);
        line [6] =  std::to_string(b);
        line [8] = "0";
        line [10] = std::to_string(a);
        for (int index = 1 ; index < 10 ; index+=2)     line [index] = " ";
        line [11] = "\n";
        for(int i = 0; i < 11 ; i++)                    myfile << line[i];
        myfile << " " <<std::endl;
    }
    myfile.close();
    makeSolFile("kite2Sol.txt", "kite", i);
}
void randomParalellogram(int num, int seed)
{
    std::ofstream myfile;
    myfile.open ("parallelogram.txt");
    int i = 0;
    for (  ; i < num ; i ++)
    {
        int a = rand() % (99 - 10) +10;
        int aA = a -4;
        int b = rand() % (aA-1) + 1;
        int c = rand() % (a -1) + 1;
        int d = a - b;
        if ( (b*b) == ((c*c) + (d*d)) )         b +=3;
        d = a - b;
        std::string line [11];
        std::string bigger = std::to_string(a);
        std::string smaller = std::to_string(b);
        std::string rise = std::to_string(c);
        line [0] =  smaller;
        line [2] =  "0";
        line [4] =  bigger;
        line [6] =  rise;
        line [8] =  std::to_string(d);
        line [10] = rise;
        for (int index = 1 ; index < 10 ; index+=2)         line [index] = " ";
        for(int i = 0; i < 11 ; i++)                        myfile << line[i];
        myfile << " " <<std::endl;
    }
    myfile.close();
    makeSolFile("parallelogramSol.txt", "parallelogram", i);
}
void randomRectangle(int num, int seed)
{
    std::ofstream myfile;
    myfile.open ("rectangle.txt");
    int i = 0;
    for (  ; i < num ; i ++)
    {
        int num1= rand() % 98 + 2;
        int num2= rand() % (num1-1) + 1;
        std::string line [11];
        std::string str = std::to_string(num1);
        std::string str2 = std::to_string(num2);
        line [2] = "0";
        line [3] = " ";
        line [8] = "0";
        line [9] = " ";
        for (int i = 0 ; i < 6 ; i+=4)                      line [i] = str;
        for (int i = 6 ; i < 12 ; i+=4)                     line [i] = str2;
        for (int index = 1 ; index < 10 ; index+=2)         line [index] = " ";
        for(int i = 0; i < 11 ; i++)    myfile << line[i];
        myfile << " "<<std::endl;
    }
    myfile.close();
    makeSolFile("rectangleSol.txt", "rectangle", i);
}

void randomError1(int num)
{
    std::ofstream myfile;
    myfile.open ("error1.txt");
    int i = 0;
    for (  ; i < 1 ; i ++)
    {
        int numNumbers= (rand() % 10 + 1);
        if ( numNumbers == 6) numNumbers --;
        int size = (numNumbers *2) -1;
        std::string line [size-1];
        for (int i = 0 ; i<size-1 ; i+=2)
        {
            int a = (rand() % 100 + 0) ;
            line[i] = std::to_string(a);
        }
        for (int i = 1 ; i < size-1; i+=2)    line [i] = " ";
        for(int i = 0; i < size-1; i++)       myfile << line [i];
        myfile << " "<<std::endl;
    }
    myfile.close();
    makeSolFile("error1Sol.txt", "error 1", i);
}
void randomError1a(int num)
{
    std::ofstream myfile;
    myfile.open ("error1a.txt");
    int i = 0;
    for (  ; i < 1 ; i ++)
    {
        int size = 6 *2 ;
        std::string line [size-1];
        for (int i = 0 ; i< size-1 ; i+=2)
        {
            int a = (rand() % 100 + 0) ;
            line[i] = std::to_string(a);
        }
        int placeChar = (rand() % 6 + 0) ;
        char cch = 'a' + rand()%26;
        line [placeChar*2] = cch;
        for (int i = 1 ; i < size-1; i+=2)    line [i] = " ";
        for(int i = 0; i < size-1; i++)       myfile << line [i];
        myfile << " "<<std::endl;
    }
    myfile.close();
    makeSolFile("error1Sola.txt", "error 1", i);
}
void randomError1b(int num)
{
    std::ofstream myfile;
    myfile.open ("error1b.txt");
    int p = 0;
    for (  ; p < 1 ; p ++)
    {
        int numNumbers= 6 ;
        int size = (numNumbers *2);
        std::string line [size -1];
        for (int t = 0 ; t<size-1 ; t+=2)
        {
            int a = (rand() % 100 + 0) ;
            line[t] = std::to_string(a);
        }
        int a = rand() % (201 - 101) + 200;
        int index= (rand() % 6 + 0);
        line[index*2] = std::to_string(a);
        for (int i = 1 ; i < size-1; i+=2)    line [i] = " ";
        for(int i = 0; i < size-1; i++)       myfile << line [i];
        myfile << " "<<std::endl;
    }
    myfile.close();
    makeSolFile("error1Solb.txt", "error 1", p);
}
void randomError2(int num)
{
    std::ofstream myfile;
    myfile.open ("error2.txt");
    int i = 0;
    for (  ; i < 1 ; i ++)
    {
        int indexCoincide= (rand() % 3 + 0) ;
        std::string line [11];
        for (int i = 0 ; i<11 ; i+=2)
        {
            int a = (rand() % 100 + 0) ;
            line[i] = std::to_string(a);
        }
        if (indexCoincide == 0 )
        {
            line[0] = "0";
            line[2] = "0";
        }
        if (indexCoincide == 1 )
        {
            line[4] = "0";
            line[6] = "0";
        }
        if (indexCoincide == 2 )
        {
            line[8] = "0";
            line[10] = "0";
        }
        for (int i = 1 ; i < 11; i+=2)    line [i] = " ";
        for(int i = 0; i < 11; i++)       myfile << line[i];
        myfile << " " <<std::endl;
    }
    myfile.close();
    makeSolFile("error2Sol.txt", "error 2", i);
}
void randomError3(int num)
{
    std::ofstream myfile;
    myfile.open ("error3.txt");
    int i = 0;
    for (  ; i < 1 ; i ++)
    {
        std::string line [11];
        int a  = 100;
        int b = 75;
        int c = a;
        for (int i = 8, j=2 ; i>=0  ; i-=4, j+=4)
        {
            c = rand() % (c - b) + b;
            line[i] = std::to_string(c);
            line[j] = std::to_string(c);
            c = b;
            b = b-25;
        }
        for (int i = 1 ; i < 11; i+=2)    line [i] = " ";
        for(int i = 0; i < 11; i++)       myfile << line[i];
        myfile << " " <<std::endl;
    }
    myfile.close();
    makeSolFile("error3Sol.txt", "error 3", i);
}
void randomError4(int num)
{
    std::ofstream myfile;
    myfile.open ("error4.txt");
    std::string line [11];
    int i = 0;
    for (  ; i < 1 ; i ++)
    {
        for (int i = 0 ; i<11 ; i+=2)
        {
            line[i] = std::to_string( rand() % 100 + 0);
            line[i+=2] = "0";
        }
        for (int i = 1 ; i < 11; i+=2)    line [i] = " ";
        for(int i = 0; i < 11 ; i++)      myfile << line[i];
        myfile << " " <<std::endl;
    }
    myfile.close();
    makeSolFile("error4Sol.txt", "error 4", i);
}
int main(int argc, const char * argv[]) {
    int a;
    if (argc > 1)       a = atoi(argv[1]);
    else                a =80;
    srand (time(NULL));
    randomSquare(500, a);
    randomTrapazoid(500, a);
    randomRhombi(500, a);
    randomQuadrilateral(500, a);
    randomKite1(500, a);
    randomKite2(500, a);
    randomParalellogram(500, a);
    randomRectangle(500, a);
    randomError1(a);
    randomError1a(a);
    randomError1b(a);
    randomError2(a);
    randomError3(a);
    randomError4(a);
    
    return 0;
}

