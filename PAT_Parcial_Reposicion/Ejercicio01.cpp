#include "Ejercicio01.h"

Node<int>* Ejercicio01::addTwoNumbers(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2)
{
    Node<int>* dummyHead = new Node<int>(0);
    Node<int>* current = dummyHead;  
    int carry = 0;  

    while (l1 || l2) {
        int x = (l1) ? l1->data : 0;
        int y = (l2) ? l2->data : 0;
        int sum = x + y + carry;

        carry = sum / 10;  
        current->next = new Node<int>(sum % 10); 
        current = current->next;  

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    if (carry > 0) {
        current->next = new Node<int>(carry); 
    }

    return dummyHead->next; 
}
