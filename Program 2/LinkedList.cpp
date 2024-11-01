#include <iostream>
#include "LinkedList.h"
using namespace std;


template<typename T>
void LinkedList<T>::append(const T& data){
    listNode *newNode;
    newNode = new listNode;
    

}

template<typename T>
T getNodeValue(int num){
    Node *nodePtr;
    if(!head)
        return -1;
    else{
        if(num == 0){
            return head->data;
              
        }
        nodePtr = head;
        int Position = 0;
        while(num >= Position && nodePtr != NULL ){
            if(num == Position){
                return nodePtr->data;
            }
            num++;
            nodePtr = nodePtr->next;
        }
    }
    
}


template<typename T>
void LinkedList<T>::removeNode(const T& data){
    Node *nodeptr;
    Node *previoousNode;

    if(!head)
        return;

    if(head->value == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodeptr;
    }
    else
    {
        nodePtr = head;

        while (nodePtr != NULL && nodePtr->value != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if(nodePtr)
        {
            {
                tail = previousNode;
            }
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}