#include "Ejercicio02.h"

Node<char>* Ejercicio02::reverseKNodes(Node<char>* head, int k) {
    Node<char>* prev = nullptr;
    Node<char>* current = head;
    Node<char>* next = nullptr;

    while (k > 0) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        k--;
    }
    return prev;
}
