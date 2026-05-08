#include <iostream>
using namespace std;

class MovieTicket {
private:
    int ticketMap[1001][1001];
    int seatsLeft[1001];

public:
    MovieTicket() {
        for (int row = 0; row <= 1000; row++) {
            seatsLeft[row] = 100;
            for (int col = 0; col <= 1000; col++) {
                ticketMap[row][col] = 0;
            }
        }
    }

    bool BOOK(int uid, int mid) {
        if (ticketMap[uid][mid] == 1 || seatsLeft[mid] == 0) {
            return false;
        }
        ticketMap[uid][mid] = 1;
        seatsLeft[mid]--;
        return true;
    }

    bool CANCEL(int uid, int mid) {
        if (ticketMap[uid][mid] == 0) {
            return false;
        }
        ticketMap[uid][mid] = 0;
        seatsLeft[mid]++;
        return true;
    }

    bool IS_BOOKED(int uid, int mid) {
        return ticketMap[uid][mid] == 1;
    }

    int AVAILABLE_TICKETS(int mid) {
        return seatsLeft[mid];
    }
};

int main() {
    int queries;
    cout << "Enter number of queries: ";
    cin >> queries;

    MovieTicket system;

    for (int i = 0; i < queries; i++) {
        string cmd;
        cout << "\nEnter query (BOOK/CANCEL/IS_BOOKED/AVAILABLE_TICKETS): ";
        cin >> cmd;

        if (cmd == "BOOK") {
            int user, movie;
            cout << "Enter User ID and Movie ID: ";
            cin >> user >> movie;

            if (system.BOOK(user, movie))
                cout << "Booking successful (true)" << endl;
            else
                cout << "Booking failed (false)" << endl;
        }
        else if (cmd == "CANCEL") {
            int user, movie;
            cout << "Enter User ID and Movie ID: ";
            cin >> user >> movie;

            if (system.CANCEL(user, movie))
                cout << "Cancellation successful (true)" << endl;
            else
                cout << "Cancellation failed (false)" << endl;
        }
        else if (cmd == "IS_BOOKED") {
            int user, movie;
            cout << "Enter User ID and Movie ID: ";
            cin >> user >> movie;

            if (system.IS_BOOKED(user, movie))
                cout << "Ticket is booked (true)" << endl;
            else
                cout << "Ticket is not booked (false)" << endl;
        }
        else if (cmd == "AVAILABLE_TICKETS") {
            int movie;
            cout << "Enter Movie ID: ";
            cin >> movie;

            cout << "Available tickets: " << system.AVAILABLE_TICKETS(movie) << endl;
        }
        else {
            cout << "Invalid command!" << endl;
        }
    }
    return 0;
}
