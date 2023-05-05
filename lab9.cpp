// 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template <class a, class b>
class Map
{
private:
    struct elem
    {
        a key;
        b value;
        int index;
        b operator=(const b& v)
        {
            value = v;
            return value;
        }
    };
    elem* e = new elem[3];
    int count = 0;
    int nr = 2;
public:
    elem& operator[](const a& key)
    {
        for (int i = 0; i < count; i++)
            if (e[i].key == key)
                return e[i];
        b* aux = new b();
        Set(key, *aux);
        return e[count - 1];
    }
    void Set(const a& key, const b& value)
    {
        for (int i = 0; i < count; i++)
        {
            if (e[i].key == key)
            {
                e[i].value = value;
                return;
            }
        }
        if (nr == count)
        {
            nr = 2 * nr;
            elem* newE = new elem[nr + 1];
            for (int i = 0; i < count; i++)
                newE[i] = e[i];
            delete[] e;
            e = newE;
        }
        e[count++] = { key,value,count };
    }
    elem* begin() const
    {
        return &e[0];
    }

    elem* end() const
    {
        return &e[count];
    }
};
int main()

{

    Map<int, const char*> m;

    m[10] = "C++";

    m[20] = "test";

    m[30] = "Poo";

    for (auto [key, value, index] : m)

    {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    }

    m[20] = "result";

    for (auto [key, value, index] : m)

    {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    }

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
