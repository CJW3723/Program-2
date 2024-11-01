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

    void viewCourse()
    {
        
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

        case 3: {
            cout << "Here are your current courses you are enrolled in.\n";
            viewCourse(courseList); 
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


    return 0;
}