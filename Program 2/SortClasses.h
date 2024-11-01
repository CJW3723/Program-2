#ifndef SORTCLASSES_H
#define SORTCLASSES_H

#include "LinkedList.h"  

//selection sort 
void sortCoursesAlphabetically(LinkedList& list) 
{
    Node* start = list.getHead();
    if (!start) return;

    for (Node* i = start; i != nullptr; i = i->next) 
    {
        Node* minNode = i;
        for (Node* j = i->next; j != nullptr; j = j->next) 
        {
            if (j->courseName < minNode->courseName) 
            {
                minNode = j;
            }
        }
        if (minNode != i) 
        {
            swap(i->courseName, minNode->courseName);
        }
    }
}

#endif
