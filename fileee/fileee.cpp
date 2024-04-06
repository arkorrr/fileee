#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template<class T>
class MyString		//Task3
{
	T* str;
public:
	MyString(T* str = nullptr) :str(str) {}

	~MyString()
	{
		delete str;
	}

	MyString(MyString&& x) : str(x.str)
	{
		x.str = nullptr;
	}

	MyString& operator=(const MyString& x)
	{
		if (&x == this)
			return *this;

		delete str;

		str = new T;
		*str = *x.str;

		return *this;
	}

	MyString& operator=(MyString&& x)
	{
		if (&x == this)
			return *this;

		delete str;

		str = x.str;
		x.str = nullptr;

		return *this;
	}

	T& operator*() const { return *str; }
	T* operator->() const { return str; }
	bool isNull() const { return str == nullptr; }

	friend ostream& operator<<(ostream& os, const MyString& myStr)
	{
		os << *myStr.str;
		return os;
	}
};

class Item
{
public:
	Item() { cout << "Item acquired\n"; }
	~Item() { cout << "Item destroyed\n"; }

	friend ostream& operator<<(ostream& os, const Item& item)
	{
		os << "Item";
		return os;
	}
};

MyString<Item> generateItem()
{
	MyString<Item> item(new Item);
	return item;
}

int main()
{
    ifstream file1("Text.txt");     //Task1
    ofstream file("Text1.txt");
    string word;

    if (file1.is_open())
    {
        while (file1 >> word)
        {
            if (word.length() >= 7)
            {
                file << word << ' ';
            }
        }
    }
    //Task2
    ofstream file2("Text2.txt");
    file2 << file1.rdbuf();
	//Task3
	MyString<Item> mainStr;
	mainStr = generateItem();

	cout << mainStr << endl;
}


