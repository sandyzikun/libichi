#ifndef __MIKU_9990463B04BBFDED__ICHI_NODE_H__
#define __MIKU_9990463B04BBFDED__ICHI_NODE_H__

#include "./stdafx.h"

namespace Ichi {
    struct Node {
        int val;
        struct Node *prev;
        struct Node *next;
    };
    struct Node * new_node(int);
    struct Node * __insert(struct Node*, int);
    struct Node * __delete(struct Node*);
} // namespace Ichi

struct Ichi::Node * Ichi::new_node(int _value=39) {
    struct Ichi::Node * q = (struct Ichi::Node *)malloc(sizeof(struct Ichi::Node));
    q->val = _value;
    q->prev = nullptr;
    q->next = nullptr;
    return q;
}

struct Ichi::Node * Ichi::__insert(struct Ichi::Node *h, int _value=39) {
    struct Ichi::Node * q = Ichi::new_node(_value);
    q->prev = h;
    q->next = h->next;
    q->next->prev = q;
    q->prev->next = q;
    return q;
}

struct Ichi::Node * Ichi::__delete(struct Ichi::Node *h) {
    h->prev->next = h->next;
    h->next->prev = h->prev;
    h->next = nullptr;
    h->prev = nullptr;
    return h;
}

#endif