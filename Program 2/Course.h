#ifndef COURSE_H
#define COURSE_H

#include <iostream>

using namespace std;

template <typename T>
class Registration 
{
    public:
    T *name;
    int *grade;
    T *major;

    // Default Constructor
    Registration() 
    {
        name = new T("");
        grade = new int(0);
        major = new T("");
        
    }

    // Parameterized Constructor
    Registration(string n = "", int g = 0, string m = "") 
    {
        name = new T(n);
        grade = new int(g);
        major = new T(m);
    }

    // Destructor
    ~Registration() 
    {
        delete name;
        delete grade;
        delete major;
    }

    // Overloaded operators
    bool operator<(const Registration& other) const 
    {
        return *name < *(other.name);
    }

    bool operator>(const Registration& other) const 
    {
        return *name > *(other.name);
    }

    bool operator==(const Registration& other) const 
    {
        return *name == *(other.name);
    }

    // Insertion operator
    friend ostream& operator<<(ostream& os, const Registration& reg) 
    {
        os << "Name: " << *(reg.name) << ", Grade: " << *(reg.grade)
           << ", Major: " << *(reg.major); 
        return os;
    }
};

#endif
