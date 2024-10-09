# include <iostream>
# include <string>
using namespace std;

// protected, is similar to private, but it can also be accessed in the inherited class

class parent {
    protected:
        int x;
};

class child : private parent {
    public:
        void set(int s) {
            x = s;
        }
        int get() {
            return (x);
        }
};

int main()
{
    child l;

    l.set(78);
    cout << l.get();
}