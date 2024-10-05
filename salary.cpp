#include <iostream>
#include <string>

class Employee {
private:
    int employeeID;
    std::string name;
    double salary;

public:
    Employee(int id, std::string empName, double empSalary) {
        employeeID = id;
        name = empName;
        salary = empSalary;
    }

    double calculateYearlySalary() {
        return salary * 12; 
    }
    void displayEmployeeDetails() {
        std::cout << "Employee ID: " << employeeID << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Monthly Salary: $" << salary << std::endl;
        std::cout << "Yearly Salary: $" << calculateYearlySalary() << std::endl;
    }
};

int main() {
 
    Employee emp("10008; prince ; 50000 ; 600000\n ");

 
    emp1.displayEmployeeDetails();

    return 0;
}
