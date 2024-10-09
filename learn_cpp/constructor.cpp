# include <iostream>
# include <string>
using namespace std;


/* --------------------- CONSTRUCTORS ---------------------- */
class constructor {
    public :
        int x;
    constructor (){
        cout << "This is just a test\n";
    }
};

int main()
{
    constructor obj; // the "constructor" in the class is a constructor means that if i declare an object
              // it will execute automatically 
}