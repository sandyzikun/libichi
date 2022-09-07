#ifndef __MIKU_9990463B04BBFDED__ICHI_LIST_H__
#define __MIKU_9990463B04BBFDED__ICHI_LIST_H__

#include "./stdafx.h"
#include "./node.h"

namespace Ichi {
    class List {
    private:
        struct Node *head;
        struct Node *tail;
        int length;
    public:
    List();
        void printall();
        void append(int);
        void remove(int);
    };
} // namespace Ichi

Ichi::List::List() {
    head = Ichi::new_node();
    tail = Ichi::new_node();
    head->next = tail;
    tail->prev = head;
    length = 0;
}

void Ichi::List::printall() {
    printf("Linked List:\n");
    if (length) {
        struct Ichi::Node * q = head->next;
        while (q != tail) {
            printf("%d ", q->val);
            q = q->next;
        }
    }
    putchar('\n');
}

void Ichi::List::append(int _value) {
    struct Ichi::Node * q = head;
    while (q->next != tail
        && q->next->val <= _value)
        q = q->next;
    Ichi::__insert(q, _value);
    ++length;
}

void Ichi::List::remove(int _value) {
    if (length) {
        struct Ichi::Node * q = head->next;
        while (q->next != tail && q->val != _value)
            q = q->next;
        if (q != tail) {
            q = Ichi::__delete(q);
            free(q);
            --length;
        }
    }
}

#endif
