# include <iostream>
# include <string>
using namespace std;

class animal {
    public:
    animal() {
        cout << "I love cats\n";
    }
};

class cat : public animal { 
    public:
    cat() {
        cout << "hello I'm a cat\n";
    }
};
// means that the class cat has the same members that animal class has but just the public ones

int main()
{
    cat Cat;
}

/* --------------------- MULTILEVEL INHERETENCE ------------------- */
// means that a class can also be derived from one class, which is already derived from another class.
// ex:
//
// class MyClass {
//   public:
//       void myFunction() {
//          cout << "Some content in parent class." ;
//     }
// };
//
// class MyChild: public MyClass {
// };
//
// class MyGrandChild: public MyChild {
// };


/* ---------------------- MULTIPLE INHERETENCE ----------------------- */
// means a class can also be derived from more than one base class, using a comma-separated list:
// ex:
// class MyClass {
//   public:
//     void myFunction() {
//       cout << "Some content in parent class." ;
//     }
// };

// class MyOtherClass {
//   public:
//     void myOtherFunction() {
//       cout << "Some content in another class." ;
//     }
// };

// class MyChildClass: public MyClass, public MyOtherClass {
// };