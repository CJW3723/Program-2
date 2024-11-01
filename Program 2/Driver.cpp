#include "Course.h"
#include "LinkedList.h"

#include <iostream>
using namespace std;


void showMenu(){

        cout << "1. Add Cours\n";
        cout << "2. Remove Course\n";
        cout << "3. View Courses\n";
        cout << "4. Exit\n";
    }

int main(){

    LinkedList<Course> courtseList;
    int choice;

    while(true){
        cin >> choice

        switch (choice)
        {
        case 1 {

            break;
        }

        case 2 {


            break;
        }

        case 3 {

            break;
        }

        case 4 {
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