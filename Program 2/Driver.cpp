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

    void addCourse(LinkedList<Registration>& courseList){

        string course, code;

        cout << "Enter course name: ";
        cin.ignore();
        getline(cin, course);
        courseList.append(Registration(name))

    }

int main(){

    LinkedList<Registration> courseList;
    int choice;



    cout << "What is your name: ";
    cin >> name;

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


            break;
        }

        case 3: {

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