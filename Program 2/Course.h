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
    string *courses;

    Registration();

    Registration(string, int, string, string);

    ~Registration();

    



};


#endif