// This program reads a binary file,
// updates grades previously written to the file,
// adds new grades in the file,
// and deletes data previously stored in the file.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

struct StudentData
{
    char studentId[8];
    char lastName[12];
    char firstName[12];
    int grade;
};

enum class Choices { PRINT = 1, UPDATE, NEW, DELETE, END };

// enable user to input menu choice
Choices enterChoice();

// create text file for printing
void createTextFile(fstream& readFromFile);

// update grade in record
void updateRecord(fstream& updateFile);

// add a new grade in record
void newRecord(fstream& insertInFile);

// delete an existing record
void deleteRecord(fstream& deleteFromFile);

// obtain student ID from user
void getID(const char* const prompt, char studentId[]);

int main()
{
    // open file for reading and writing
    fstream inOutGrade("grades.dat", ios::in | ios::out | ios::binary);

    // exit program if fstream cannot open file
    if (!inOutGrade)
    {
        cerr << "File could not be opened." << endl;
        system("pause");
        exit(1);
    }

    Choices choice; // store user choice

    // enable user to specify action
    while ((choice = enterChoice()) != Choices::END)
    {
        switch (choice)
        {
        case Choices::PRINT:
            createTextFile(inOutGrade); // create text file from binary file
            break;
        case Choices::UPDATE:
            updateRecord(inOutGrade); // update grade
            break;
        case Choices::NEW:
            newRecord(inOutGrade); // add a new grade
            break;
        case Choices::DELETE:
            deleteRecord(inOutGrade); // delete existing record
            break;
        default:
            cerr << "Incorrect choice" << endl;
            break;
        }






        cout << endl;
    }

    inOutGrade.close();

    system("pause");
}
// enable user to input menu choice
Choices enterChoice()
{
    // display available options
    cout << "Enter your choice" << endl
        << "1 - store a text file of all students' information" << endl
        << "    called \"grades.txt\" for printing" << endl
        << "2 - update a student's grade" << endl
        << "3 - add a student's grade" << endl
        << "4 - delete a student's information" << endl
        << "5 - end program\n? ";

    int menuChoice;
    cin >> menuChoice;
    return static_cast<Choices>(menuChoice);
}

// create text file for printing
void createTextFile(fstream& readFromFile)
{
    ofstream outFile("text.txt");
    readFromFile.clear();
    readFromFile.seekg(0);
    StudentData sd;
    outFile << left << setw(9) << "ID" << setw(12) << "Last Name" << setw(13) << "First Name" << setw(5) << "Grade" << endl;
    cout << left << setw(9) << "ID" << setw(12) << "Last Name" << setw(13) << "First Name" << setw(5) << "Grade" << endl;
    while (readFromFile.read(reinterpret_cast<char*>(&sd), sizeof(sd))) {
        if (sd.studentId[0] != '\0') {
           outFile << left << setw(9) << sd.studentId 
                << setw(12) << sd.lastName
                << setw(13) << sd.firstName
                << right << setw(5) << sd.grade << endl;
            cout << left << setw(9) << sd.studentId
                << setw(12) << sd.lastName
                << setw(13) << sd.firstName
                << right << setw(5) << sd.grade << endl;
        }
    }  
    outFile.close();
}

// update grade in record
void updateRecord(fstream& updateFile)
{
    char studentId[8];
    getID("\nEnter student ID to update", studentId);
    updateFile.clear();
    updateFile.seekg(0);

    StudentData sd;
    bool find = false;
    while(updateFile.read(reinterpret_cast<char*>(&sd), sizeof(sd))) {
        if (strcmp(sd.studentId, studentId) == 0 && sd.studentId[0] != '\0') {
            find = true;
            cout << endl;
            if (sd.grade == -1) {
                cout << "Student ID " << studentId << " has no grade.\n";
                break;
            }
            cout << left << setw(9) << sd.studentId
                << setw(12) << sd.lastName
                << setw(13) << sd.firstName
                << right << setw(5) << sd.grade << endl;
            cout << "Enter grade: ";
            cin >> sd.grade;
            long offset = -static_cast<long>(sizeof(sd));
            updateFile.seekp(offset, ios::cur);
            updateFile.write(reinterpret_cast<char*>(&sd), sizeof(sd));
            cout << left << setw(9) << sd.studentId
                << setw(12) << sd.lastName
                << setw(13) << sd.firstName
                << right << setw(5) << sd.grade << endl;
            break;
        }
    }
    if (!find) {
        cout << endl << "Student ID " << studentId << " is empty.\n";
    }
}

// add a new grade in record
void newRecord(fstream& insertInFile)
{
    char studentId[8];
    getID("\nEnter student ID to add", studentId);
    insertInFile.clear();
    insertInFile.seekg(0);
    StudentData sd;
    bool find = false;
    while (insertInFile.read(reinterpret_cast<char*>(&sd), sizeof(sd))) {
        if (strcmp(sd.studentId, studentId) == 0) {
            find = true;
            cout << endl << "Enter grade: ";
            cin >> sd.grade;
            long offset = -static_cast<long>(sizeof(sd));
            insertInFile.seekp(offset, ios::cur);
            insertInFile.write(reinterpret_cast<char*>(&sd), sizeof(sd));
            cout << endl << left << setw(9) << sd.studentId
                << setw(12) << sd.lastName
                << setw(13) << sd.firstName
                << right << setw(5) << sd.grade << endl;
            break;
        }
    }
    if (!find) {
        cout << endl << "Student ID " << studentId << " is empty.\n";
    }
}

// delete an existing record
void deleteRecord(fstream& deleteFromFile)
{
    char studentId[8];
    getID("\nEnter student ID to delete", studentId);
    deleteFromFile.clear();
    deleteFromFile.seekg(0);
    StudentData sd;
    bool find = false;
    while (deleteFromFile.read(reinterpret_cast<char*>(&sd), sizeof(sd))) {
        if (strcmp(sd.studentId, studentId) == 0 && sd.studentId[0] != '\0') {
            find = true;
            sd.studentId[0] = '\0';
            long offset = -static_cast<long>(sizeof(sd));
            deleteFromFile.seekp(offset, ios::cur);
            deleteFromFile.write(reinterpret_cast<char*>(&sd), sizeof(sd));
            cout << endl << "Student ID " << studentId << " deleted\n";
            break;
        }
    }
    if (!find) {
        cout << endl << "Student ID " << studentId << " is empty.\n";
    }
}

// obtain student ID from user
void getID(const char* const prompt, char studentId[])
{
    do
    {
        cout << prompt << " ( 1141401 - 1141450 ): ";
        cin >> studentId;
    } while (strcmp(studentId, "1141401") == -1 || strcmp(studentId, "1141451") == 1);
}
