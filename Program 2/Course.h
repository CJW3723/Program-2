#ifndef COURSE_H
#define COURSE_H

#include <iostream>

using namespace std;

class Registration
{
    public:
    string *name;
    int *grade;
    string *major;
    string *course;

    //Default Constructor
    Registration()
    {
        name = new string("");
        grade = new int(0); 
        major = new string(""); 
        course = new string(""); 
    }

    //Parameterized Constructor
    Registration(string n = NULL, int g = NULL, string m = NULL, string c = NULL)
    {
        name = new string(n); 
        grade = new int(g); 
        major = new string(m); 
        course = new string(c); 
    }

    //Destructor
    ~Registration()
    {
        delete name; 
        delete grade; 
        delete major; 
        delete course;  
    }

    // Overloaded 
    bool operator < (const Registration& other) const
    {
        return *name < *(other.name); 
    }

    bool operator > (const Registration& other) const
    {
        return *name > *(other.name); 
    }

    bool operator == (const Registration& other) const
    {
        return *name == *(other.name); 
    }

    //insertion operator
    friend ostream& operator<<(ostream& os, const Registration& reg)
    {
        os << "Name: " << *(reg.name) << ", Grade: " << *(reg.grade) 
        << ", Major: " << *(reg.major) << ", Courses: " << *(reg.course);

        return os;
    }
    
};


#endif