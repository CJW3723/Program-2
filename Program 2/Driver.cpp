
#include "LinkedList.h"
#include "SortClasses.h"
#include "Course.h"
#include <iostream>
#include <fstream>

using namespace std;

void showMenu() 
{
    cout << "\nMenu:\n";
    cout << "1. Add Course\n";
    cout << "2. Remove Course\n";
    cout << "3. Display Selected Courses\n";
    cout << "4. Exit Program\n";
    cout << "Please enter your choice (1-4): ";
}

void loadCoursesFromFile(LinkedList& availableCourses) 
{
    string courseName;

    ifstream file("ClassList.txt");
    if (!file.is_open()) 
    {
        cerr << "Failed to open ClassList.txt\n";
        return;
    }

    while (getline(file, courseName)) 
    {
        if (!courseName.empty()) 
        {
            availableCourses.addCourse(courseName);
        }
    }
    file.close();
}

void addCourse(LinkedList& availableCourses, LinkedList& studentCourses) 
{
    int choice;
    int index = 1;

    if (availableCourses.isEmpty()) 
    {
        cout << "No available courses to select from.\n";
        return;
    }

    cout << "\nAvailable Courses:\n";
    availableCourses.displayCourses();

    cout << "Enter the number of the course you want to add: ";
    cin >> choice;

    Node* temp = availableCourses.getHead();
    
    while (temp && index < choice) 
    {
        temp = temp->next;
        index++;
    }

    if (temp) 
    {
        studentCourses.addCourse(temp->courseName);
        cout << "Course \"" << temp->courseName << "\" added successfully.\n";
    } 
    else 
    {
        cout << "Invalid selection. Please try again.\n";
    }
}

void removeCourse(LinkedList& studentCourses) 
{
    int choice;
    int index = 1;

    if (studentCourses.isEmpty()) 
    {
        cout << "No courses available to remove.\n";
        return;
    }

    cout << "\nSelected Courses:\n";
    studentCourses.displayCourses();

    cout << "Enter the number of the course you want to remove: ";
    cin >> choice;

    Node* temp = studentCourses.getHead();
    Node* previous = nullptr;

    while (temp && index < choice) 
    {
        previous = temp;
        temp = temp->next;
        index++;
    }

    if (temp) 
    {
        string courseName = temp->courseName;
        if (previous) 
        {
            previous->next = temp->next;
        } 
        else 
        {
            studentCourses.setHead(temp->next); 
        }

        delete temp;
        cout << "Course \"" << courseName << "\" removed successfully.\n";
    } 
    else 
    {
        cout << "Invalid selection. Please try again.\n";
    }
}

void displayCourses(LinkedList& studentCourses) 
{
    if (studentCourses.isEmpty()) 
    {
        cout << "No courses available to display.\n";
        return;
    }

    sortCoursesAlphabetically(studentCourses);

    cout << "\nSelected Courses (Alphabetical Order):\n";
    studentCourses.displayCourses();
}

int main() 
{
    string name, major; 
    int choice, grade; 

    LinkedList availableCourses;  
    LinkedList studentCourses; 

    cout << "Sudent registration details: " << endl; 

    cout << "Student name: ";
    cin.ignore(); 
    getline(cin,name);

    cout << "Student grade: ";
    cin >> grade; 

    cout << "Enter student major: "; 
    cin.ignore(); 
    getline(cin, major); 

    Registration<string> student(name, grade, major); 
     

    loadCoursesFromFile(availableCourses);

    while (true) 
    {
        showMenu();
        cin >> choice;

        switch (choice) 
        {
            case 1:
                addCourse(availableCourses, studentCourses);
                break;
            case 2:
                removeCourse(studentCourses);
                break;
            case 3:
                displayCourses(studentCourses);
                break;
            case 4:
                cout << "Exiting course selection. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}
