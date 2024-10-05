#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    int id;
    string name;
    int age;

    Student(int id, string name, int age) : id(id), name(name), age(age) {}
};

class StudentRecord {
private:
    vector<Student> students;

public:
    void addStudent(int id, string name, int age) {
        students.push_back(Student(id, name, age));
        cout << "Student added successfully." << endl;
    }

    void displayStudents() {
        for (const auto& student : students) {
            cout << "ID: " << student.id << ", Name: " << student.name << ", Age: " << student.age << endl;
        }
    }

    void searchStudent(int id) {
        for (const auto& student : students) {
            if (student.id == id) {
                cout << "ID: " << student.id << ", Name: " << student.name << ", Age: " << student.age << endl;
                return;
            }
        }
        cout << "Student not found." << endl;
    }
};

int main() {
    StudentRecord record;
    int choice, id, age;
    string name;

    do {
        cout << "1. Add Student\n2. Display Students\n3. Search Student\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            record.addStudent(id, name, age);
            break;

        case 2:
            record.displayStudents();
            break;

        case 3:
            cout << "Enter ID to search: ";
            cin >> id;
            record.searchStudent(id);
            break;

        case 4:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
