# include <iostream>
# include <string>
using namespace std;

/* -------------------------- CLASS ------------------------------ */
class car {
    public:
        string model;
        int year;
        string brand;
        void    method();
};

void    car::method() {
    cout << "hellobbb\n";
}

int main()
{
    car car1;
    car car2;

    car1.brand = "mercedes";
    car1.model = "gla";
    car1.year = 2024;

    car2.brand = "aito";
    car2.model = "m5";
    car2.year = 2023;

    cout << car1.brand << " " << car1.model << " " << car1.year << endl;
    cout << car2.brand << " " << car2.model << " " << car2.year << endl;
    car1.method();
}