// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NM 101
#include <string.h>
class Car
{
private:
    int color;
    char* id;
public:
    Car(int c, char* text);
    Car();//to reserve
    int getColor();
};
Car::Car(int c, char* text)
{
    color = c;
    strcpy(id, text);
}
Car::Car()
{
    color = -1;
    strcpy(id, "reserved");
}
int Car::getColor()
{
    return color;
}
class parking_spot
{
private:
    bool busy;
    Car vehicle;
    int color_restrict;
public:
    void isParked(int c, char* text);
    void isReserved();
    parking_spot(int color_restrict);
};
void parking_spot::isParked(int c, char* text)
{
    Car vehicle(int c, char* text);
}
void parking_spot::isReserved()
{
    Car vehicle();
}
parking_spot::parking_spot(int color)
{
    color_restrict = color;
}
class park
{
private:
    parking_spot map[NM][NM];
public:
    void checkIsReserved(parking_spot p);
};
void park::checkIsReserved(parking_spot p);


int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
