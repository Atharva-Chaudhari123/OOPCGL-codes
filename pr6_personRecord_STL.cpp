#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Struct to store personal records
struct PersonalRecord {
    string name;
    string dob; // Date of Birth
    int telephone; // Changed to int

    // Overloading < operator for sorting by name
    bool operator<(const PersonalRecord& other) const {
        return name < other.name;
    }

    // Overloading == operator for searching by name
    bool operator==(const string& searchName) const {
        return name == searchName;
    }

    // Display the record
    void display() const {
        cout << "Name: " << name 
             << ", DOB: " << dob 
             << ", Telephone: " << telephone << endl;
    }
};

// Function to display all records
void displayRecords(const vector<PersonalRecord>& records) {
    for (const auto& record : records) {
        record.display();
    }
}

// Function to search for a record by name
void searchRecord(const vector<PersonalRecord>& records, const string& name) {
    auto it = find(records.begin(), records.end(), name);

    if (it != records.end()) {
        cout << "Record found: ";
        it->display();
    } else {
        cout << "Record with name \"" << name << "\" not found.\n";
    }
}

int main() {
    vector<PersonalRecord> records;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Record\n";
        cout << "2. Display Records\n";
        cout << "3. Sort Records by Name\n";
        cout << "4. Search Record by Name\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            PersonalRecord record;
            cout << "Enter Name: ";
            cin.ignore(); // To clear input buffer
            getline(cin, record.name);
            cout << "Enter DOB (DD-MM-YYYY): ";
            getline(cin, record.dob);
            cout << "Enter Telephone (numeric only): ";
            cin >> record.telephone; // Changed to int input
            records.push_back(record);
            break;
        }
        case 2:
            cout << "\nPersonal Records:\n";
            displayRecords(records);
            break;

        case 3:
            sort(records.begin(), records.end());
            cout << "\nRecords sorted by name.\n";
            break;

        case 4: {
            string searchName;
            cout << "Enter the name to search: ";
            cin.ignore(); // To clear input buffer
            getline(cin, searchName);
            searchRecord(records, searchName);
            break;
        }

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
