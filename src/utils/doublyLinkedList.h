//
// Created by joan on 10/05/22.
//
#ifndef PAINT_DOUBLYLINKEDLIST_H
#define PAINT_DOUBLYLINKEDLIST_H
#include <iostream>

template<typename T>
class doublyLinkedList {
public:
    T data;
    doublyLinkedList<T> *nextNode = nullptr;
    doublyLinkedList<T> *prevNode = nullptr;

    /**
     * @brief Insierta el nuevo nodo al principio. El nodo nuevo nodo pasa a ser el head.
     * @param head_ref
     * @param new_data
     */
    void insertNode(doublyLinkedList<T> **head_ref, T new_data) {
        doublyLinkedList<T> *new_node = new doublyLinkedList<T>();

        new_node->data = new_data;

        new_node->nextNode = (*head_ref);
        new_node->prevNode = NULL;

        if ((*head_ref) != NULL)
            (*head_ref)->prevNode = new_node;
        (*head_ref) = new_node;
    }

    /**
     * Inisiert gusto despues del nodo que recibe. Y corre sus hermanos a la derecha el nuevo nodo.
     * @param prev_node
     * @param new_data
     */
    void insertAfter(doublyLinkedList<T> *prev_node, T new_data) {
        if (prev_node == NULL) {
            std::cout << "The given node cannot be NULL";
            return;
        }
        doublyLinkedList<T> *new_node = new doublyLinkedList<T>();

        new_node->data = new_data;

        new_node->nextNode = prev_node->nextNode;

        prev_node->nextNode = new_node;

        new_node->prevNode = prev_node;

        if (new_node->nextNode != NULL)
            new_node->nextNode->prevNode = new_node;

    };

    /**
     * @brief Insierta hasta al final el dato. No cambia el head.
     * @param prev_node
     * @param new_data
     */
    void append(doublyLinkedList<T> **head_ref, T new_data) {
        doublyLinkedList<T> *new_node = new doublyLinkedList<T>();

        doublyLinkedList<T> *last = *head_ref;

        new_node->data = new_data;

        new_node->nextNode = NULL;

        if (*head_ref == NULL) {
            new_node->prevNode = NULL;
            *head_ref = new_node;
            return;
        }
        while (last->nextNode != NULL) {
            last = last->nextNode;
        }
        last->nextNode = new_node;

        new_node->prevNode = last;
        return;
    };

    void printList(doublyLinkedList<T> *node) {
        doublyLinkedList<T> *last;
        std::cout << "\nTraversal in forward direction\n";
        while (last != NULL) {
            std::cout << " " << last->data << " ";
            last = last->prevNode;
        };
    }

    ~doublyLinkedList() {
        if(this->nextNode != nullptr)
            delete this->nextNode;
    };
};

#endif //PAINT_DOUBLYLINKEDLIST_H