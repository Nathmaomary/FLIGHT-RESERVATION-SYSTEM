#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    cout << "Welcome to the Flight Reservation System!" << endl;
    // Main program logic will be here in later commits
    return 0;
}
// FlightReservationSystem.h
#ifndef FLIGHT_RESERVATION_SYSTEM_H
#define FLIGHT_RESERVATION_SYSTEM_H

#include <iostream>
#include <vector>

class Flight {
public:
    int flightNumber;
    string origin;
    string destination;
    int totalSeats;
    int availableSeats;

    Flight(int fNum, string orig, string dest, int seats)
        : flightNumber(fNum), origin(orig), destination(dest), totalSeats(seats), availableSeats(seats) {}
};

class Passenger {
public:
    string name;
    int age;
    string passportNumber;
};

class Reservation {
public:
    Flight flight;
    Passenger passenger;

    Reservation(Flight f, Passenger p) : flight(f), passenger(p) {}
};

#endif
// Flight.cpp
#include "FlightReservationSystem.h"

Flight::Flight(int fNum, string orig, string dest, int seats)
    : flightNumber(fNum), origin(orig), destination(dest), totalSeats(seats), availableSeats(seats) {}

void Flight::displayFlightDetails() {
    cout << "Flight Number: " << flightNumber << endl;
    cout << "Origin: " << origin << endl;
    cout << "Destination: " << destination << endl;
    cout << "Total Seats: " << totalSeats << ", Available Seats: " << availableSeats << endl;
}
// Passenger.cpp
#include "FlightReservationSystem.h"

Passenger::Passenger(string n, int a, string pNum) 
    : name(n), age(a), passportNumber(pNum) {}

void Passenger::displayPassengerDetails() {
    cout << "Passenger Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Passport Number: " << passportNumber << endl;
}
// Reservation.cpp
#include "FlightReservationSystem.h"

Reservation::Reservation(Flight f, Passenger p) : flight(f), passenger(p) {}

void Reservation::displayReservationDetails() {
    flight.displayFlightDetails();
    passenger.displayPassengerDetails();
}
void displayAvailableFlights(const vector<Flight>& flights) {
    for (const auto& flight : flights) {
        flight.displayFlightDetails();
        cout << "-----------------------------------" << endl;
    }
}




