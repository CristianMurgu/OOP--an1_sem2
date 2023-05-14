// lab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <exception>
using namespace std;
class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T>
class ArrayIterator
{
private:
	int Current; // mai adaugati si alte date si functii necesare pentru iterator
	int count=0;
public:
	T* first() const
	{
		return &T[0];
	}
	T* last() const
	{
		return &T[count];
	}
	ArrayIterator();
	ArrayIterator& operator ++ ();
	ArrayIterator& operator -- ();
	bool operator= (ArrayIterator<T>&);
	bool operator!=(ArrayIterator<T>&);
	T* GetElement();
};
class exception1 : public exception
{
	virtual const char* what() const throw()
	{
		return "Out of range";
	}
};
class exception2 : public exception
{
	virtual const char* what() const throw()
	{
		return "this place is occupied";
	}
};
class exception3 : public exception
{
	virtual const char* what() const throw()
	{
		return "this place is empty";
	}
};
template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
	exception1 outOfRange;
	exception2 notEmpty;
	exception3 Empty;
public:
	Array(); // Lista nu e alocata, Capacity si Size = 0
	~Array(); // destructor
	Array(int capacity); // Lista e alocata cu 'capacity' elemente
	Array(const Array<T>& otherArray); // constructor de copiere
	T& operator[] (int index)
	{
		try 
		{
			if (index < this->Capacity || index < 0)
				throw outOfRange;
			else 
			{

			}
		}
		catch (exception& e)
		{
			cout << "imposible because, " << e.what()<<'\n';
		}
	}// arunca exceptie daca index este out of range
	const Array<T>& operator+=(const T& newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
	const Array<T>& Insert(int index, const T& newElem)
	{
		try
		{
			if (this->List[index])
				throw notEmpty;
			else
			{

			}
		}
		catch (exception& e)
		{
			cout << "imposible because, " << e.what() << '\n';
		}
	}
	// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const Array<T> otherArray)
	{
		try
		{
			if (this->List[index])
				throw notEmpty;
			else
			{

			}
		}
		catch (exception& e)
		{
			cout << "imposible because, " << e.what() << '\n';
		}
	}// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Delete(int index)
	{
		try
		{
			if (this->List[index])
				throw Empty;
			else
			{

			}
		}
		catch (exception& e)
		{
			cout << "imposible because, " << e.what() << '\n';
		}
	}// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	bool operator=(const Array<T>& otherArray);
	void Sort(); // sorteaza folosind comparatia intre elementele din T
	void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
	void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie
	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
	int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator
	int Find(const T& elem); // cauta un element in Array
	int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
	int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator
	int GetSize();
	int GetCapacity();
	ArrayIterator<T> GetBeginIterator();
	ArrayIterator<T> GetEndIterator();
};
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
