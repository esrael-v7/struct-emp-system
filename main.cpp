#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to hold address information
struct Address {
    string street;
    string city;
    string state;
    string zipCode;
};

// Structure to hold department information
struct Department {
    string deptName;
    string description;
};

// Structure to hold employee information
struct Employee {
    int id;
    string name;
    string email;
    string phone;
    Address address;
    Department department;
};

// Structure to manage a list of employees
struct EmployeeManager {
    vector<Employee> employees;
};

// Structure to hold login credentials
struct Login {
    string username;
    string password;
};

// Function declarations
bool authenticate(const Login& login);
void displayLoginPage();
void displayInvalidCredentialsMessage();
void addEmployee(EmployeeManager& manager);
void searchEmployee(const EmployeeManager& manager);
void updateEmployee(EmployeeManager& manager, int id);
void displayEmployees(const EmployeeManager& manager);
void deleteEmployee(EmployeeManager& manager, int id);
void displayEmployeeDetails(const Employee& employee);
void updateEmployeeDetails(Employee& employee);

// Function to authenticate user login
bool authenticate(const Login& login) {
    // Dummy authentication logic
    return (login.username == "admin" && login.password == "password");
}

// Function to display login page
void displayLoginPage() {
    cout << "Welcome to the Employee Registration System!" << endl;
    cout << "Please log in to continue." << endl;
    cout << "Username: ";
}

// Function to display invalid credentials message
void displayInvalidCredentialsMessage() {
    cout << "Invalid username or password. Please try again." << endl;
}

// Function to add a new employee
void addEmployee(EmployeeManager& manager) {
    Employee employee;
    cout << "Enter ID: ";
    cin >> employee.id;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, employee.name);
    cout << "Enter email: ";
    getline(cin, employee.email);
    cout << "Enter phone: ";
    getline(cin, employee.phone);
    cout << "Enter street: ";
    getline(cin, employee.address.street);
    cout << "Enter city: ";
    getline(cin, employee.address.city);
    cout << "Enter state: ";
    getline(cin, employee.address.state);
    cout << "Enter zip code: ";
    getline(cin, employee.address.zipCode);
    cout << "Enter department name: ";
    getline(cin, employee.department.deptName);
    cout << "Enter department description: ";
    getline(cin, employee.department.description);

    manager.employees.push_back(employee);
    cout << "Employee added successfully!" << endl;
}

// Function to search for an employee by ID
void searchEmployee(const EmployeeManager& manager) {
    int id;
    cout << "Enter ID of employee to search: ";
    cin >> id;

    for (const auto& employee : manager.employees) {
        if (employee.id == id) {
            cout << "Employee found:" << endl;
            displayEmployeeDetails(employee);
            return;
        }
    }
    cout << "Employee not found.\n" << "Please enter registered ID and try again. \n" << "Thank you!" << endl;
}

// Function to update an existing employee's details
void updateEmployee(EmployeeManager& manager, int id) {
    for (auto& employee : manager.employees) {
        if (employee.id == id) {
            updateEmployeeDetails(employee);
            cout << "Employee updated successfully!" << endl;
            return;
        }
    }
    cout << "Employee not found." << endl;
}

// Function to display details of all employees
void displayEmployees(const EmployeeManager& manager) {
    cout << "Employee List:" << endl;
    for (const auto& employee : manager.employees) {
        displayEmployeeDetails(employee);
        cout << "------------------------" << endl;
    }
}

// Function to delete an employee by ID
void deleteEmployee(EmployeeManager& manager, int id) {
    for (auto it = manager.employees.begin(); it != manager.employees.end(); ++it) {
        if (it->id == id) {
            manager.employees.erase(it);
            cout << "Employee deleted successfully!" << endl;
            return;
        }
    }
    cout << "Employee not found." << endl;
}

// Function to display details of a single employee
void displayEmployeeDetails(const Employee& employee) {
    cout << "ID: " << employee.id << endl;
    cout << "Name: " << employee.name << endl;
    cout << "Email: " << employee.email << endl;
    cout << "Phone: " << employee.phone << endl;
    cout << "Address: " << employee.address.street << ", " << employee.address.city << ", " << employee.address.state << ", " << employee.address.zipCode << endl;
    cout << "Department: " << employee.department.deptName << endl;
    cout << "Department Description: " << employee.department.description << endl;
}

// Function to update details of a single employee
void updateEmployeeDetails(Employee& employee) {
    cout << "Enter new name: ";
    cin.ignore();
    getline(cin, employee.name);
    cout << "Enter new email: ";
    getline(cin, employee.email);
    cout << "Enter new phone: ";
    getline(cin, employee.phone);
    cout << "Enter new street: ";
    getline(cin, employee.address.street);
    cout << "Enter new city: ";
    getline(cin, employee.address.city);
    cout << "Enter new state: ";
    getline(cin, employee.address.state);
    cout << "Enter new zip code: ";
    getline(cin, employee.address.zipCode);
    cout << "Enter new department name: ";
    getline(cin, employee.department.deptName);
    cout << "Enter new department description: ";
    getline(cin, employee.department.description);
}

int main() {
    EmployeeManager manager;
    Login login;
    bool loggedIn = false;

    // Login loop
    do {
        displayLoginPage();
        cin >> login.username;
        cout << "Password: ";
        cin >> login.password;

        loggedIn = authenticate(login);

        if (!loggedIn) {
            displayInvalidCredentialsMessage();
        }
    } while (!loggedIn);

    int choice;
    // Main menu loop
    do {
        cout << "\nMain Menu" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Search Employee" << endl;
        cout << "3. Update Employee" << endl;
        cout << "4. Display All Employees" << endl;
        cout << "5. Delete Employee" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee(manager);
                break;
            case 2:
                searchEmployee(manager);
                break;
            case 3: {
                int id;
                cout << "Enter ID of employee to update: ";
                cin >> id;
                updateEmployee(manager, id);
                break;
            }
            case 4:
                displayEmployees(manager);
                break;
            case 5: {
                int id;
                cout << "Enter ID of employee to delete: ";
                cin >> id;
                deleteEmployee(manager, id);
                break;
            }
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 6);

    return 0;
}