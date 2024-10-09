# include <iostream>
# include <string>
using namespace std;

/* --------------------------- ACCESS SPECIFIER -------------------------------- */
class Employee {
    private:
        int salary;

    public:
        void setSalary(int salary) {
            this->salary = salary;
        }

        int getSalary() {
            return (salary);
        }
    Employee () {
        cout << "hello world\n";
    }
};

int main()
{
    Employee obj;

    cout << obj.getSalary() << "\n";
    obj.setSalary(10000);
    cout << obj.getSalary() << "\n";
}