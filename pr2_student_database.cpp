#include <iostream>
#include <string>
using namespace std;

class student
{
private:
    string name;
    int roll;
    string cls;
    char division;
    string dob;
    string blood;
    long int contact;
    string address;
    long int telephone;
    string drivingL;

    static int studentCount; // Static member to count students

public:
    // Default Constructor
    student()
    {
        name = "Unknown";
        roll = 0;
        cls = "Unknown";
        division = 'A';
        dob = "00-00-0000";
        blood = "Unknown";
        contact = 0;
        address = "Unknown";
        telephone = 0;
        drivingL = "Unknown";
        studentCount++; // Increment student count
    }

    // Parameterized Constructor
    student(string name, int roll, string cls, char division, string dob, string blood, 
            long int contact, string address, long int telephone, string drivingL)
    {
        this->name = name;
        this->roll = roll;
        this->cls = cls;
        this->division = division;
        this->dob = dob;
        this->blood = blood;
        this->contact = contact;
        this->address = address;
        this->telephone = telephone;
        this->drivingL = drivingL;
        studentCount++; // Increment student count
    }

    // Copy Constructor
    student(const student &s)
    {
        name = s.name;
        roll = s.roll;
        cls = s.cls;
        division = s.division;
        dob = s.dob;
        blood = s.blood;
        contact = s.contact;
        address = s.address;
        telephone = s.telephone;
        drivingL = s.drivingL;
        studentCount++; // Increment student count
    }

    // Destructor
    ~student()
    {
        studentCount--; // Decrement student count
    }

    // Function to Input Details
    void inputDetails()
    {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> roll;
        cout << "Enter Class: ";
        cin.ignore();
        getline(cin, cls);
        cout << "Enter Division: ";
        cin >> division;
        cout << "Enter Date of Birth (DD-MM-YYYY): ";
        cin.ignore();
        getline(cin, dob);
        cout << "Enter Blood Group: ";
        getline(cin, blood);
        cout << "Enter Contact Number: ";
        cin >> contact;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter Telephone Number: ";
        cin >> telephone;
        cout << "Enter Driving License Number: ";
        cin.ignore();
        getline(cin, drivingL);
    }

    // Inline Function to Display Details
    inline void displayDetails() const
    {
        cout << "\nStudent Details:\n";
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll << endl;
        cout << "Class: " << cls << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << blood << endl;
        cout << "Contact: " << contact << endl;
        cout << "Address: " << address << endl;
        cout << "Telephone: " << telephone << endl;
        cout << "Driving License: " << drivingL << endl;
    }

    // Static Member Function
    static void displayStudentCount()
    {
        cout << "\nCurrent number of students in the database: " << studentCount << endl;
    }

    // Friend Class
    friend class admin;
};

// Initialize Static Member
int student::studentCount = 0;

// Friend Class Definition
class admin
{
public:
    void showStudentDetails(const student &s)
    {
        cout << "\nAdmin Access - Student Details:\n";
        cout << "Name: " << s.name << endl;
        cout << "Roll Number: " << s.roll << endl;
        cout << "Class: " << s.cls << endl;
        cout << "Division: " << s.division << endl;
        cout << "Date of Birth: " << s.dob << endl;
        cout << "Blood Group: " << s.blood << endl;
        cout << "Contact: " << s.contact << endl;
        cout << "Address: " << s.address << endl;
        cout << "Telephone: " << s.telephone << endl;
        cout << "Driving License: " << s.drivingL << endl;
    }
};

int main()
{
    try
    {
        // Dynamic memory allocation
        student *s1 = new student();
        student *s2 = new student("John Doe", 101, "12th Grade", 'B', "15-08-2005", 
                                   "O+", 9876543210, "123 Elm Street", 1122334455, "DL12345");

        cout << "Enter student details:" << endl;
        s1->inputDetails(); // Input student details

        cout << "\nDisplaying details of first student:";
        s1->displayDetails(); // Display student details

        cout << "\nDisplaying details of second student:";
        s2->displayDetails(); // Display student details

        // Static member function to display student count
        student::displayStudentCount();

        // Friend class usage
        admin adminAccess;
        adminAccess.showStudentDetails(*s2);

        // Delete dynamically allocated memory
        delete s1;
        delete s2;

        // Display student count after deletion
        student::displayStudentCount();
    }
    catch (bad_alloc &e)
    {
        cerr << "Memory allocation failed: " << e.what() << endl;
    }

    return 0;
}
