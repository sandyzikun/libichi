#ifndef __MIKU_9990463B04BBFDED__ICHI_TREE_H__
#define __MIKU_9990463B04BBFDED__ICHI_TREE_H__

#include "./stdafx.h"
#include "./nodex.h"

namespace Ichi {
    class Tree {
    private:
        struct Ichi::Nodex *root;
        int length;
    public:
        Tree();
        void printall();
        struct Nodex * search(int);
        void append(int);
        void delmin();
        void remove(int);
        void clearall();
    };
} // namespace Ichi

Ichi::Tree::Tree() {
    root = nullptr;
    length = 0;
}

void Ichi::Tree::printall() {
    printf("LLRB Tree:\n");
    Ichi::__print_prorder(root);
    putchar('\n');
    Ichi::__print_inorder(root);
    putchar('\n');
}

struct Ichi::Nodex * Ichi::Tree::search(int _value) {
    return Ichi::__search(root, _value);
}

void Ichi::Tree::append(int _value) {
    root = Ichi::__append(root, _value);
    root->colored = false;
    ++length;
}

void Ichi::Tree::delmin() {
    if (length) {
        root = Ichi::__delmin(root);
        if (root != nullptr)
            root->colored = false;
        --length;
    }
}

void Ichi::Tree::remove(int _value) {
    if (length) {
        root = Ichi::__remove(root, _value);
        if (root != nullptr)
            root->colored = false;
        --length;
    }
}

void Ichi::Tree::clearall() {
    while (length)
        Ichi::Tree::delmin();
}

#endif