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

Flight* searchFlight(int flightNumber, vector<Flight>& flights) {
    for (auto& flight : flights) {
        if (flight.flightNumber == flightNumber) {
            return &flight;
        }
    }
    return nullptr; // Flight not found
}

void bookFlight(Flight& flight, Passenger& passenger) {
    if (flight.availableSeats > 0) {
        Reservation reservation(flight, passenger);
        flight.availableSeats--;
        cout << "Flight booked successfully!" << endl;
        reservation.displayReservationDetails();
    } else {
        cout << "Sorry, no available seats on this flight!" << endl;
    }
}
void cancelReservation(Flight& flight) {
    flight.availableSeats++;
    cout << "Reservation cancelled successfully. Seats have been restored." << endl;
}
void showMenu() {
    cout << "1. Show Available Flights" << endl;
    cout << "2. Book a Flight" << endl;
    cout << "3. Cancel a Reservation" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    vector<Flight> flights;
    flights.push_back(Flight(101, "New York", "London", 50));
    flights.push_back(Flight(102, "New York", "Paris", 30));

    int choice;
    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            displayAvailableFlights(flights);
        } else if (choice == 2) {
            // Booking logic goes here
        } else if (choice == 3) {
            // Cancel reservation logic goes here
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid option!" << endl;
        }
    }
    return 0;
}

vector<Reservation> reservations;

void showBookedReservations() {
    if (reservations.empty()) {
        cout << "No reservations yet!" << endl;
        return;
    }
    for (const auto& reservation : reservations) {
        reservation.displayReservationDetails();
        cout << "-----------------------------------" << endl;
    }
}

int getFlightSelection() {
    int flightNumber;
    cout << "Enter the flight number: ";
    cin >> flightNumber;
    return flightNumber;
}

void bookFlight(Flight& flight, Passenger& passenger) {
    if (flight.availableSeats > 0) {
        Reservation reservation(flight, passenger);
        flight.availableSeats--;
        reservations.push_back(reservation); // Store reservation
        cout << "Flight booked successfully!" << endl;
    } else {
        cout << "Sorry, no available seats on this flight!" << endl;
    }
}
vector<Reservation> reservations; // This is already implemented in Commit 11
void displayAllFlights(const vector<Flight>& flights) {
    for (const auto& flight : flights) {
        flight.displayFlightDetails();
    }
}

void displaySpecificFlightDetails(int flightNumber, vector<Flight>& flights) {
    Flight* flight = searchFlight(flightNumber, flights);
    if (flight) {
        flight->displayFlightDetails();
    } else {
        cout << "Flight not found!" << endl;
    }
}
void showReservationSummary(Reservation& reservation) {
    cout << "Reservation Summary:" << endl;
    reservation.displayReservationDetails();
}
void handleFlightBookingError(int flightNumber, vector<Flight>& flights) {
    Flight* flight = searchFlight(flightNumber, flights);
    if (!flight || flight->availableSeats == 0) {
        cout << "Error: Flight is either not available or fully booked." << endl;
    }
}
void modifyBooking(int flightNumber, vector<Flight>& flights) {
    // Modify passenger information or change the flight
}

#include <fstream>

void saveReservationsToFile(const vector<Reservation>& reservations) {
    ofstream outFile("reservations.txt");
    // Save reservations to file
}

void loadReservationsFromFile(vector<Reservation>& reservations) {
    ifstream inFile("reservations.txt");
    // Load reservations from file
}

// Finalize the program with enhanced UI, handling edge cases
cout << "Thank you for using the Flight Reservation System!" << endl;
















