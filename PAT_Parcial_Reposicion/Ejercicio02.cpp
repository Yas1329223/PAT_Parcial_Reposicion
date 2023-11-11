#include "Ejercicio02.h"

Node<char>* Ejercicio02::reverseKGroup(Node<char>* head, int k)
{
    #include "Ejercicio02.h"

Node<char>* Ejercicio02::reverseKGroup(Node<char>* head, int k)
{
    Node<char>* current = head;
    int count = 0;

    while (current && count < k) {
        current = current->next;
        count++;
    }

    if (count < k) {
        return head; 
    }
    Node<char>* prev = nullptr;
    current = head;
    int i = 0;

    while (current && i < k) {
        Node<char>* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        i++;
    }

    if (current) {
        head->next = reverseKGroup(current, k);
    }

    return prev;
}
