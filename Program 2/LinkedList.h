#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>
using namespace std;

struct Node 
{
    string courseName;
    Node* next;

    Node(const string& name){
        courseName = name;
        next = nullptr;
    }

};

class LinkedList 
{  
    private:
    Node* head;
    Node* tail;

    public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }

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

    int getLength() const
    {
        int counter = 0;
        Node *nodePtr;

        nodePtr = head;

        while(nodePtr != tail){
            counter++;
            nodePtr =nodePtr->next;
            if(nodePtr == tail){
                counter++;
            }
            
        }
        return counter;
        
    }

    int search(string courseName)
    {
        Node *nodePtr;
        int num;

        nodePtr = head;
        num = 0;

        while(nodePtr){
            if(nodePtr->courseName == courseName){
                return num;
            }

            num++;

            nodePtr = nodePtr->next;
        }

    }

    void swap(int position1, int position2)
    {
        Node *nodePtr1 = NULL;
        Node *nodePtr2 = NULL;
        string temp;

        nodePtr1 = head;

        int position;
        while(nodePtr1 != NULL && position1 != position){
            nodePtr1 = nodePtr1->next;
            position++;
        }

        nodePtr2 = head;
        position = 0;
        while(nodePtr2 != NULL && position2 != position){
            nodePtr2  = nodePtr2->next;
            position++;
        }

        temp = nodePtr1->courseName;
        nodePtr1->courseName = nodePtr2->courseName;
        nodePtr2->courseName = temp;
    };
};


#endif
