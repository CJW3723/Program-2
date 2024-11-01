#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template <typename T>
class LinkedList{
    private:
        struct Node
        {
            T data;
            struct Node* next;
            node(const T& data);
            
        };

        Node* head;
        Node* tail;
        int size; 


    public:
        
        Node();
        Node(const T& classData){
                data = classData;
                head = nullptr;
                tail = nullptr;
                
            }


        ~linkedList();

        void append(const T& data);
        T getNodeValue(int);
        void removeNode(const T& data);
        void displayList() const;
        int search(const T& data);
        bool isEmpty();
        void insertNode(int, const T& data);


        
};

#include <LinkedList.cpp>




#endif