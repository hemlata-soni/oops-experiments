#include <iostream>
using namespace std;

class Fahrenheit; // Forward declaration

class Celsius {
private:
    double temperature;
public:
    Celsius(double temp) {
        this->temperature=temp;
    }

    operator Fahrenheit();

    void display() const {
        cout << "Temperature in Celsius: " << temperature << " C" << endl;
    }
};

class Fahrenheit {
private:
    double temperature;
public:
    Fahrenheit(double temp) {
        this->temperature=temp;
    }
    operator Celsius();

    void display() const {
        cout << "Temperature in Fahrenheit: " << temperature << " F" << endl;
    }
};

Celsius::operator Fahrenheit() {
    return Fahrenheit((temperature * 9.0 / 5.0) + 32); 
}

Fahrenheit::operator Celsius() {
    return Celsius((temperature - 32) * 5.0 / 9.0); 
}

int main() {
    Celsius celsiusTemp(943.9);
    Fahrenheit fahrenheitTemp = celsiusTemp; 
    fahrenheitTemp.display(); 

    Fahrenheit fahrTemp(77.0);
    Celsius celsiusTempFromFahr = fahrTemp;
    celsiusTempFromFahr.display(); // Use display function to show temperature in Celsius

    return 0;
}


// class A{
//     int x,y;

//     public:
//     A(int x, int y): x(x), y(y){}

//     operator int() const{
//         return x+y;
//     }

// };
// int main(){
//     A a1(10,12);
//     int res=a1; // ---> implicit type casting
//     cout<<a1;
// }


/*hw question: 2 class with name celcius and faranite typecast both with their objects.*/
