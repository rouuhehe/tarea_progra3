//
// Created by rudri on 10/11/2020.
//

#include "bag.h"



namespace structures{
    bag::bag() : head(nullptr), tail(nullptr){} //la bolsa empieza vacia
    
    void bag::add(int elem){
        node *n = new node;
        n->data = elem; 
        n->next = head; // el nodo apunta al primer elemento de la lista
        head = n; // el nuevo nodo se convierte en el pimero de la lista
        s++;

    }

    node *bag::begin(){
        return head; //returns the first elem of the linked list
    }
    node *bag::end(){
        return nullptr;
    }
    int bag::size() const{
        return s; //returns the size of the bag
    }
    bag::~bag() {
        node *current = head;
        while (current != nullptr) {
            node *next = current->next;
            delete current; //delete the current node
            current = next; //move to the next node
        }
    }
}

