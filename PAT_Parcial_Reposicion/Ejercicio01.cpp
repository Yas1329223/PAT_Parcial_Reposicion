#include "Ejercicio01.h"

Node<int>* reverseList(Node<int>* head)
{
    Node<int>* current = head;
    Node<int>* prev = nullptr;
    Node<int>* next = nullptr;
    
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

Node<int>* addTwoNumbers(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2)
{
    Node<int>* l1Reversed = reverseList(l1);
    Node<int>* l2Reversed = reverseList(l2);
    
    Node<int>* l3 = new Node<int>{ 0 };
    Node<int>* l3Current = l3;
    int carry = 0;
    
    while (l1Reversed != nullptr || l2Reversed != nullptr) {
        int sum = carry;
        
        if (l1Reversed != nullptr) {
            sum += l1Reversed->value;
            l1Reversed = l1Reversed->next;
        }
        
        if (l2Reversed != nullptr) {
            sum += l2Reversed->value;
            l2Reversed = l2Reversed->next;
        }
        
        l3Current->next = new Node<int>{ sum % 10 };
        l3Current = l3Current->next;
        carry = sum / 10;
    }
    
    if (carry > 0) {
        l3Current->next = new Node<int>{ carry };
    }
    
    return reverseList(l3->next);
}

