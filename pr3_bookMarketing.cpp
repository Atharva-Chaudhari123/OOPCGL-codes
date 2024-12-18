#include <iostream>
#include <string>
#include <exception>

using namespace std;

// Base class Publication
class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0f) {}

    void input() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore(); // To ignore the newline character left in the input buffer
    }

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

// Derived class Book
class Book : public Publication {
private:
    int pageCount;

public:
    Book() : pageCount(0) {}

    void input() {
        Publication::input();
        cout << "Enter page count: ";
        cin >> pageCount;
        cin.ignore(); // To ignore the newline character left in the input buffer
    }

    void display() const {
        Publication::display();
        cout << "Page Count: " << pageCount << endl;
    }
};

// Derived class Tape
class Tape : public Publication {
private:
    float playingTime;

public:
    Tape() : playingTime(0.0f) {}

    void input() {
        Publication::input();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
        cin.ignore(); // To ignore the newline character left in the input buffer
    }

    void display() const {
        Publication::display();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    try {
        Book book;
        Tape tape;

        cout << "Enter Book details:" << endl;
        book.input();

        cout << "\nEnter Tape details:" << endl;
        tape.input();

        cout << "\nBook details:" << endl;
        book.display();

        cout << "\nTape details:" << endl;
        tape.display();
    }
    catch (exception &e) {
        cout << "Exception caught: " << e.what() << endl;
        // Set all data members to zero
        Book book;
        Tape tape;
        cout << "Data reset to zero values." << endl;

        // Displaying zeroed data
        cout << "\nBook details:" << endl;
        book.display();

        cout << "\nTape details:" << endl;
        tape.display();
    }

    return 0;
}
