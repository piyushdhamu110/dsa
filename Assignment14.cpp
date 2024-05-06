#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Student {
    int rollNo;
    char name[50];
    char division;
    char address[100];
};

// Function to add a new student record
void addStudent() {
    ofstream outFile("students.dat", ios::binary | ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    Student newStudent;
    cout << "Enter Roll No: ";
    cin >> newStudent.rollNo;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(newStudent.name, 50);
    cout << "Enter Division: ";
    cin >> newStudent.division;
    cout << "Enter Address: ";
    cin.ignore();
    cin.getline(newStudent.address, 100);

    outFile.write(reinterpret_cast<char*>(&newStudent), sizeof(Student));

    cout << "Student added successfully." << endl;

    outFile.close();
}

// Function to delete a student record by roll number
void deleteStudent(int rollNo) {
    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    ofstream tempFile("temp.dat", ios::binary);
    if (!tempFile) {
        cerr << "Error: Unable to create temp file." << endl;
        return;
    }

    Student student;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNo != rollNo) {
            tempFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    if (found) {
        remove("students.dat");
        rename("temp.dat", "students.dat");
        cout << "Student with roll number " << rollNo << " deleted successfully." << endl;
    } else {
        remove("temp.dat");
        cout << "Student with roll number " << rollNo << " not found." << endl;
    }
}

// Function to search for a student record by roll number
void searchStudent(int rollNo) {
    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    Student student;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNo == rollNo) {
            cout << "Roll No: " << student.rollNo << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with roll number " << rollNo << " not found." << endl;
    }

    inFile.close();
}

int main() {
    int choice, rollNo;
    cout << "Student Information System" << endl;
    cout << "1. Add Student\n2. Delete Student\n3. Search Student\n4. Exit" << endl;
    
    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                cout << "Enter Roll No to delete: ";
                cin >> rollNo;
                deleteStudent(rollNo);
                break;
            case 3:
                cout << "Enter Roll No to search: ";
                cin >> rollNo;
                searchStudent(rollNo);
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
