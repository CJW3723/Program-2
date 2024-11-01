#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <LinkedList.cpp>

template <typename T>
class LinkedList{
    private:
        struct Node
        {
            T data;
            Node* next;
            node(const T& data);
            
        };

        node* head;
        node* tail;
        int size;

    public:
        
        Node();
        Node(const T& classData){
                data = classData;
                head = nullptr;
                tail = nullptr;
                
            }

    public:
        
        Node();
        Node(const T& classData){
                data = classData;
                head = nullptr;
                tail = nullptr;
                
            }


        ~linkedList();

        void append(const T& data);
        T getNodeValue(const T& data);
        void removeNode(const T& data);
        void displayList() const;
        int search(const T& data);
        bool isEmpty();
        void insertNode(int, const T& data);


        
};




#endif