// LAB5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
#include <deque>
#include <iostream>
#include "lab5.h"
#include <string.h>
#define NM 101

void Number::GenerateVal()
{
    int p = 0;
    for (short i = strlen(number) - 1; i >= 0; i++)
    {
        val = pow(baseNumber, p)*(int)number[i];
        p++;
    }
}
bool operator==(Number const& v1, Number const& v2)
{
    return (v1.val == v2.val);
}
bool operator>(Number const& v1, Number const& v2)
{
    return (v1.val > v2.val);
}
bool operator<(Number const& v1, Number const& v2)
{
    return (v1.val > v2.val);
}
bool operator>= (Number const& v1, Number const& v2)
{
    return (v1.val >= v2.val);
}
bool operator<= (Number const& v1, Number const& v2)
{
    return (v1.val <= v2.val);
}
Number::Number(const char* value, int base)
{
    number = (char*)value;
    baseNumber = base;
}
void Number::Print()
{
    std::cout << number << '\n';
}
int Number::GetDigitsCount()
{
    return strlen(number);
}
int Number::GetBase()
{
    return baseNumber;
}
void Number::SwitchBase(int newBase)
{
    std::deque <char*> v;
    GenerateVal();
    baseNumber = newBase;
    while (val)
    {
        switch (val % newBase)
        {
        case 0:
            v.push_back((char*)"0");
            break;
        case 1:
            v.push_back((char*)"1");
            break;
        case 2:
            v.push_back((char*)"2");
            break;
        case 3:
            v.push_back((char*)"3");
            break;
        case 4:
            v.push_back((char*)"4");
            break;
        case 5:
            v.push_back((char*)"5");
            break;
        case 6:
            v.push_back((char*)"6");
            break;
        case 7:
            v.push_back((char*)"7");
            break;
        case 8:
            v.push_back((char*)"8");
            break;
        case 9:
            v.push_back((char*)"9");
            break;
        case 10:
            v.push_back((char*)"A");
        case 11:
            v.push_back((char*)"B");
            break;
        case 12:
            v.push_back((char*)"C");
            break;
        case 13:
            v.push_back((char*)"D");
            break;
        case 14:
            v.push_back((char*)"E");
        case 15:
            v.push_back((char*)"F");
            break;
        default:
            std::cout << "imposibil" << '\n';
            return;
        }
        val /= newBase;
    }
    while (v.size())
    {
        delete[] number;
        number = new char[NM];
        int p = v.size();
        for (short i = 0; i < p; i++)
        {
            number[i]=(char)v.front();
            v.pop_front();
        }
    }
}

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
