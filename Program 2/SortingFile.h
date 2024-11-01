#ifndef SORTINGFILE_H
#define SORTINGFILE_H

#include <memory>
#include "LinkedList.h"

using namespace std;

//Helper functions 
template <typename T>
shared_ptr<typename LinkedList<T>::Node> mergeSort(shared_ptr<typename LinkedList<T>::Node> node);

template <typename T>
shared_ptr<typename LinkedList<T>::Node> merge(shared_ptr<typename LinkedList<T>::Node> left,shared_ptr<typename LinkedList<T>::Node> right);

template <typename T>
shared_ptr<typename LinkedList<T>::Node> getMiddle(shared_ptr<typename LinkedList<T>::Node> node);


template <typename T>
void sortLinkedList(LinkedList<T>& list) 
{
    list.head = mergeSort(list.head);
}

//Merge Sort 
template <typename T>
shared_ptr<typename LinkedList<T>::Node> mergeSort(shared_ptr<typename LinkedList<T>::Node> node) 
{
    if (!node || !node->next) 
    {
        return node;
    }

    //1st half
    shared_ptr<typename LinkedList<T>::Node> middle = getMiddle(node);
    shared_ptr<typename LinkedList<T>::Node> nextOfMiddle = middle->next;
    middle->next = nullptr;

    //2nd half
    shared_ptr<typename LinkedList<T>::Node> left = mergeSort(node);
    shared_ptr<typename LinkedList<T>::Node> right = mergeSort(nextOfMiddle);

    //Merging halves
    return merge(left, right);
}

// Helper functions
template <typename T>
shared_ptr<typename LinkedList<T>::Node> merge(shared_ptr<typename LinkedList<T>::Node> left,shared_ptr<typename LinkedList<T>::Node> right) 
{
    if (!left) return right;
    if (!right) return left;

    shared_ptr<typename LinkedList<T>::Node> result;
    if (left->data < right->data) 
    {
        result = left;
        result->next = merge(left->next, right);
    } 
    else 
    {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

template <typename T>
shared_ptr<typename LinkedList<T>::Node> getMiddle(shared_ptr<typename LinkedList<T>::Node> node) 
{
    if (!node) return node;

    shared_ptr<typename LinkedList<T>::Node> slow = node;
    shared_ptr<typename LinkedList<T>::Node> fast = node->next;

    while (fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

#endif
