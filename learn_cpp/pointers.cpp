# include <iostream>
# include <string>
using namespace std;

/* ---------------------- POINTERS ---------------------- */
int main()
{
    string food;
    string  *ptr;

    food = "pizza";
    ptr = &food;
    cout << food << endl;
    cout << &food << endl;
    cout << ptr << endl;
    cout << *ptr << endl;
    *ptr = "tajin";
    cout << food << endl;
    cout << *ptr << endl;
    cout << ptr << endl;
    cout << &food << endl;
}