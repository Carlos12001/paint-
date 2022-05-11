//
// Created by joan on 10/05/22.
//

#ifndef PAINT_DOUBLYLINKEDLIST_H
#define PAINT_DOUBLYLINKEDLIST_H

template<typename T>
class doublyLinkedList{
    public:
        T data;
        doublyLinkedList* nextNode;
        doublyLinkedList* prevNode;

        void insertNode(doublyLinkedList** head_ref, T new_data);
        void insertAfter(doublyLinkedList* prev_node, T new_data);
        void append(doublyLinkedList** head_ref,T new_data);
        void printList(doublyLinkedList* node);

#endif //PAINT_DOUBLYLINKEDLIST_H
