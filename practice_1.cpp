#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {
        cout << "Constructor called for " << name << " (Age: " << age << ")" << std::endl;
    }

    ~Person() {
        cout << "Destructor called for " << name << std::endl;
    }

    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    Person person1("Alice", 30);
    person1.displayInfo();
    return 0;
}
