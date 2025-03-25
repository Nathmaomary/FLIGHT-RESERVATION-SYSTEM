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
