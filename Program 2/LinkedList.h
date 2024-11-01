#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>
using namespace std;

struct Node 
{
    string courseName;
    Node* next;

    Node(const string& name) : courseName(name), next(nullptr) {}
};

class LinkedList 
{  
    private:
    Node* head;

    public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() 
    {
        Node* current = head;
        while (current) 
        {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }

    void addCourse(const string& courseName) 
    {
        Node* newNode = new Node(courseName);
        newNode->next = head;
        head = newNode;
    }

    bool removeCourse(const string& courseName) 
    {
        Node* current = head;
        Node* previous = nullptr;

        while (current) {
            if (current->courseName == courseName) 
            {
                if (previous) 
                {
                    previous->next = current->next;
                } 
                else 
                {
                    head = current->next;
                }

                delete current;
                return true;
            }

            previous = current;
            current = current->next;
        }
        return false;

    }

    void displayCourses() const 
    {
        Node* temp = head;
        int index = 1;

        while (temp) 
        {
            cout << index++ << ". " << temp->courseName << endl;
            temp = temp->next;
        }
    }

    Node* getHead() const 
    {
        return head;
    }

    void setHead(Node* newHead)
    {
        head = newHead; 
    }

    bool isEmpty() const 
    {
        return head == nullptr;
    }
};


#endif
