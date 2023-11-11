#include "Ejercicio01.h"

Node<int>* Ejercicio01::addTwoNumbers(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2)
{
     Node<int>* result = nullptr; // Inicializamos la lista resultante como vacía
    Node<int>* current = nullptr; // Inicializamos el nodo actual como vacío
    int carry = 0; // Inicializamos el acarreo como cero

    while (l1 != nullptr || l2 != nullptr) {
        int val1 = (l1 != nullptr) ? l1->data : 0;
        int val2 = (l2 != nullptr) ? l2->data : 0;
        int sum = val1 + val2 + carry;

        carry = sum / 10;

        Node<int>* newNode = new Node<int>(sum % 10);
        if (result == nullptr) {
            result = newNode;
            current = result;
        } else {
            current->next = newNode;
            current = current->next;
        }

        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }

    if (carry > 0) {
        Node<int>* newNode = new Node<int>(carry);
        current->next = newNode;
    }

    return result;
}
