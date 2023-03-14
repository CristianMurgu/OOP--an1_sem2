// laborator4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdarg>
#include "Sort.h"
#include <string.h>
Sort::Sort(int elements, int minVal, int maxVal)
{
    size = elements;
    for (int i = 0; i < elements; ++i)
        list[i] = rand() % maxVal + minVal;
}
Sort::Sort()
{
    std::cin >> size;
    for (int i = 0; i < size; ++i)
        std::cin >> list[i];
}
Sort::Sort(int* vector, int n)
{
    list = vector;
    size = n;
}
Sort::Sort(int elements,...)
{
    va_list arg;
    size = elements;
    va_start(arg,elements);
    for (int i = 0; i < elements;i++)
        list[i] = va_arg(arg, int);
    va_end(arg);
}
Sort::Sort(char* string)
{
    int elements = 0;
    char *p;
    if (strtok(string, ","))
    {
        p = strtok(string, ",");
        //list[elements] = (int)p;
        ++elements;
    }
    while (p != NULL)
    {
        p = strtok(NULL, ",");
        //list[elements] = (int)p;
        ++elements;
    }
    --elements;
    size = elements;
}
void Sort::InsertSort(bool ascendent)
{
    for (int i = 1; i < this->size; i++)
    {
        int num = this->list[i];
        int j = i - 1;
        if (ascendent)
        {
            while (j >= 0 && this->list[j] > num)
            {
                std::swap(this->list[j], this->list[j + 1]);
                j--;
            }
        }
        else
        {
            while (j >= 0 && this->list[j] < num)
            {
                std::swap(this->list[j], this->list[j + 1]);
                j--;
            }

        }

        if (this->list[j + 1] != num)
            this->list[j + 1] = num;
    }
}
void Sort::QuickSortREC(int minPos, int maxPos, bool ascendent)
{
    int piv = this->list[minPos];
    int i = minPos + 1;
    int j = maxPos;

    while (i <= j)
    {
        if (ascendent)
        {
            if (this->list[i] <= piv)
                i++;
            if (this->list[j] >= piv)
                j--;
            if (this->list[i] > piv && this->list[j] < piv && i < j)
            {
                std::swap(this->list[i], this->list[j]);
                i++;
                j--;

            }

        }
        else
        {
            if (this->list[i] >= piv)
                i++;
            if (this->list[j] <= piv)
                j--;
            if (this->list[i] < piv && this->list[j] > piv && i < j)
            {
                std::swap(this->list[i], this->list[j]);
                i++;
                j--;

            }
        }
    }
    i--;
    std::swap(this->list[minPos], this->list[i]);

    if (i - 1 > minPos)
        QuickSortREC(minPos, i - 1, ascendent);
    if (i + 1 < maxPos)
        QuickSortREC(i + 1, maxPos, ascendent);
}
void Sort::QuickSort(bool ascendent)
{
    QuickSortREC(0, this->size - 1, ascendent);
}
void Sort::BubbleSort(bool ascendent)
{
    int finalPos = this->size - 1;
    while (finalPos > 0)
    {
        int n = finalPos; finalPos = 0;

        for (int i = 0; i < n; i++)
        {
            if (ascendent)
            {
                if (this->list[i] > this->list[i + 1])
                {
                    std::swap(this->list[i], this->list[i + 1]);
                    finalPos = i + 1;
                }

            }
            else
            {
                if (this->list[i] < this->list[i + 1])
                {
                    std::swap(this->list[i], this->list[i + 1]);
                    finalPos = i + 1;
                }
            }
        }

    }
}
void Sort::stalinSort(bool ascendent)
{
    for (int i = 1; i < this->size; i++)
    {
        if (this->list[i - 1] > this->list[i])
        {
            for (int j = i + 1; j < this->size; j++)
                this->list[j - 1] = this->list[j];
            --size;
        }
    }
}
bool check(Sort a)
{
    for (int i = 1; i < a.size; i++)
    {
        if (a.list[i - 1] > a.list[i])
            return false;
    }
    return true;
}
void Sort::bogoSort(bool ascendent)
{
    bool ok = 0;
    int a, b;
    while (!ok)
    {
        ok=check(*this);
        a = rand() % this->size + 0;
        b = rand() % this->size + 0;
        std::swap(a, b);
    }
}
void Sort::quantumSort(bool ascendent)
{
    if (!check(*this))
    {
        _asm
        {
            mov ax, 5307;
            mov bx, 0001;
            mov cx, 0003;
            INT 15;
        }
    }
}
int main()
{
    return 0;
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
