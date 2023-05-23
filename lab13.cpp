// lab12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//template <class T>
class agenda
{
protected:
    contact* contacte;
    int size;
public:
    agenda()
    {
        size = 0;
    }
    contact& searchContactsByName(char* str)
    {
        for (auto i = 1; i <= this->size; i++)
        {
            if (strcmp(str, this->contacte[i].name))
                return this->contacte[i];
        }
    }
    contact* FriendList()
    {
        int p = 1;
        contact* s;
        for (auto i = 1; i <= this->size; i++)
        {
            if (strcmp(contacte[i].tip(), "friends"))
            {
                s[p] = contacte[i];
                p++;
            }
        }
        return s;
    }
    void const DeleteContactByName(char* str)
    {
        bool ok=0;
        for (auto i = 1; i <= this->size; i++)
        {
            if (strcmp(str, this->contacte[i].name) || ok)
            {
                this->contacte[i] = this->contacte[i - 1];
            }
        }
        this->size--;
    }
    void const AddContact(contact contact_new)
    {
        size++;
        this->contacte[size] = contact_new;
    }
};
class friends : protected virtual contact
{
protected:
    char* birthday;
    char* phone;
    char* adress;
public:
    friends();
    ~friends();
    const char* tip()
    {
        const char* text = "friends";
        return text;
    }
};
class known : protected virtual contact
{
protected:
    char* phone;
public:
    known();
    ~known();
    const char* tip()
    {
        const char* text = "NOTfriends";
        return text;
    }
};
class mate : protected virtual contact
{
protected:
    char* firma;
    char* phone;
    char* adress;
public:
    mate();
    ~mate();
    const char* tip()
    {
        const char* text = "NOTfriends";
        return text;
    }
};
class contact
{
public:
    char* name;
    virtual const char* tip();
};
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
