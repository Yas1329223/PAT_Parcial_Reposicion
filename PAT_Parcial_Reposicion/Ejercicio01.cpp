#include "Ejercicio01.h"

Node<int>* Ejercicio01::addTwoNumbers(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2)
{
    Node<int>* resultHead = nullptr;
    Node<int>** current = &resultHead;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->value;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->value;
            l2 = l2->next;
        }

        carry = sum / 10;
        *current = new Node<int>(sum % 10);
        current = &((*current)->next);
    }

    if (carry > 0) {
        *current = new Node<int>(carry);
    }

    return resultHead;
}
