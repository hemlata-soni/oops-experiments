#include <iostream>
#include <string>

using namespace std;

class Passenger {
private:
    string name;
    int age;
    int ticketNumber;

public:
    Passenger() : name(" "), age(0), ticketNumber(0) {}

    Passenger(string name, int age, int ticketNumber) {
        this->name = name;
        this->age = age;
        this->ticketNumber = ticketNumber;
    }

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    int getTicketNumber() const {
        return ticketNumber;
    }

    void displayPassenger() const {
        cout << "Name: " << name
             << ", Age: " << age
             << ", Ticket Number: " << ticketNumber << endl;
    }
};

class TicketReservationSystem {
private:
    Passenger* passengers[100];
    int currentSize;

public:
    TicketReservationSystem() : currentSize(0) {
        for (int i = 0; i < 100; i++) {
            passengers[i] = nullptr;
        }
    }

    ~TicketReservationSystem() {
        for (int i = 0; i < currentSize; i++) {
            delete passengers[i];
        }
    }

    void addPassenger(string name, int age, int ticketNumber) {
        if (currentSize < 100) {
            passengers[currentSize] = new Passenger(name, age, ticketNumber);
            currentSize++;
            cout << "Passenger added successfully.\n";
        } else {
            cout << "Reservation system is full. Cannot add more passengers.\n";
        }
    }

    void searchPassengerByTicket(int ticketNumber) const {
        for (int i = 0; i < currentSize; ++i) {
            if (passengers[i]->getTicketNumber() == ticketNumber) { // Accessing through pointer
                cout << "Passenger found:\n";
                passengers[i]->displayPassenger();
                return;
            }
        }
        cout << "No passenger found with Ticket Number: " << ticketNumber << "\n";
    }

    void displayAllPassengers() const {
        if (currentSize == 0) {
            cout << "No passengers in the system.\n";
            return;
        }
        cout << "Passenger List:\n";
        for (int i = 0; i < currentSize; ++i) {
            passengers[i]->displayPassenger();
        }
    }
};

int main() {
    TicketReservationSystem system;

    system.addPassenger("Akash", 21, 10001);
    system.addPassenger("Chtean", 20, 10002);
    system.addPassenger("Arnav", 21, 10003);

    cout << "\nDisplaying all passengers:\n";
    system.displayAllPassengers();

    cout << "\nSearching for passenger with Ticket Number 10002:\n";
    system.searchPassengerByTicket(10002);

    cout << "\nSearching for passenger with Ticket Number 104:\n";
    system.searchPassengerByTicket(10003);

    return 0;
}



/*Answer 1. Allows dynamic memory allocation, avoids object copying, supports polymorphism, and provides better memory management. 
  Answer 2. It traverse loops through the array of passenger pointers, checks each passenger's ticket number, and displays the details if a match is found. If no match, it shows an error message.
  Answer 3. Here are some points that why we did not use an array of pointer to manage the passengers
    -> Memory allocated dynamically - if in the any conditon the current size of our passenger array is less than the size of array than we can't extend the size of array manually
    -> Requires manual deallocation (destructor)- we have to delete items explicitlly
*/
