#include "Course.h"
#include "LinkedList.h"


#include <iostream>
using namespace std;


void showMenu(){

        cout << "1. Add Cours\n";
        cout << "2. Remove Course\n";
        cout << "3. View Courses\n";
        cout << "4. Exit\n";
        cout << "Please enter you choice (1-4): ";
    }

    void addCourse(LinkedList<Registration>& courseList, const string&name)
    {
        string course; 
        cout << "Enter course name: ";
        cin.ignore();
        getline(cin, course);

        courseList.append(Registration(course)); 

    }

    void removeCourse(LinkedList<Registration>& courseList, const string&name)
    {
        string course; 
        cout << "Select a course to remove: "; 


    }

    void viewCourse(const Registration* reg) 
    {
        cout << "Registration Details: " << endl; 
        cout << "Name: " << *(reg->name) << endl; 
        cout << "Grade: " << *(reg->grade) << endl; 
        cout << "Major: " << *(reg->major) << endl; 
        cout << "Courses: " << *(reg->courses) << endl; 

    }
    


int main(){
    
    LinkedList<Registration> courseList;
    int choice, grade; 
    string name, major, course;

    cout << "Enter student name: " ; 
    getline(cin, name); 

    cout << "Enter grade: "; 
    cin >> grade; 

    cout << "Enter Major: "; 
    cin.ignore();
    getline(cin, major); 

    cout << "Enter courses: "; 
    getline(cin, course); 

    Registration* reg = new Registration(name, grade, major, course); 


    while(true){
        showMenu();
        
        cin >> choice;

        switch (choice)
        {
        case 1: {
            cout << "Enter a course that you want to add.\n";
            addCourse(courseList);
            break;
        }

        case 2: {
            cout << "Enter a course that you want to delete.\n"; 
            removeCourse(courseList); 

            break;
        }

        case 3:
        {

            cout << "Here are your current courses you are enrolled in.\n";
            viewCourse(reg);

            break;
        }

        case 4: {
            cout << "Bye!\n";
            break;
        }
            
        
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    //memory clean up
    delete reg; 
    
    return 0;
}