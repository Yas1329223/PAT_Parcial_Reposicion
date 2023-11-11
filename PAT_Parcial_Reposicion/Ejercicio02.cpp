#include "Ejercicio02.h"

Node<char>* Ejercicio02::reverseKGroup(Node<char>* head, int k)
{
    Node<char>* current = head;
    int count = 0;

    while (current != nullptr && count < k) {
        current = current->next;
        count++;
    }

    if (count == k) {
        current = reverseKNodes(head, k);
        head->next = reverseKGroup(current, k);
        return current;
    }
    return head;
}

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
