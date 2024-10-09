# include <iostream>
# include <string>
using namespace std;

/* -------------------------- POINTERS AND FUNCTIONS --------------------------- */
void    myFunction(int &a, int &b)
{
    int x;

    x = a;
    a = b;
    b = x;
}

int main()
{
    int first = 11;
    int second = 22;

    cout << "Before: " << "\n";
    cout << first << second << "\n";

    myFunction(first, second);
    cout << "After: " << "\n";
    cout << first << second << "\n";
}

// void    swap(int *a, int *b)
// {
//     int tmp;

//     tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// int main()
// {
//     int a = 9;
//     int b = 10;
//     cout << a << " " << b << "\n";
//     swap(&a, &b);
//     cout << a << " " << b << "\n";
// }