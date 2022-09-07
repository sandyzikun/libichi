#ifndef __MIKU_9990463B04BBFDED__ICHI_NODEX_H__
#define __MIKU_9990463B04BBFDED__ICHI_NODEX_H__

#include "./stdafx.h"

namespace Ichi {
    struct Nodex {
        // without pointer to parent
        int val;
        struct Nodex *parent;
        struct Nodex *lchild;
        struct Nodex *rchild;
        bool colored;
    };
    struct Nodex * new_nodex(int, bool);
    void __print_element(struct Nodex*);
    void __print_prorder(struct Nodex*);
    void __print_inorder(struct Nodex*);
    void __print_poorder(struct Nodex*);
    bool __exist_colored(struct Nodex*);
    void __color_flip(struct Nodex*);
    int __getmin(struct Nodex*);
    struct Nodex * __search(struct Nodex*, int);
    struct Nodex * __rotate(struct Nodex*);
    struct Nodex * __rotrev(struct Nodex*);
    struct Nodex * __fix_up(struct Nodex*);
    struct Nodex * __append(struct Nodex*, int);
    struct Nodex * __leften(struct Nodex*);
    struct Nodex * __delmin(struct Nodex*);
    struct Nodex * __remove(struct Nodex*, int);
} // namespace Ichi

struct Ichi::Nodex * Ichi::new_nodex(int _value=39, bool _color=false) {
    struct Ichi::Nodex * q = (struct Ichi::Nodex *)malloc(sizeof(struct Ichi::Nodex));
    q->val = _value;
    q->parent = nullptr;
    q->lchild = nullptr;
    q->rchild = nullptr;
    q->colored = _color;
    return q;
}

void Ichi::__print_element(struct Ichi::Nodex *h) {
    if (h->colored)
        printf("[%d]\t", h->val);
    else
        printf(" %d \t", h->val);
}

void Ichi::__print_prorder(struct Ichi::Nodex *h) {
    if (h != nullptr) {
        Ichi::__print_element(h);
        Ichi::__print_prorder(h->lchild);
        Ichi::__print_prorder(h->rchild);
    }
}

void Ichi::__print_inorder(struct Ichi::Nodex *h) {
    if (h != nullptr) {
        Ichi::__print_inorder(h->lchild);
        Ichi::__print_element(h);
        Ichi::__print_inorder(h->rchild);
    }
}

void Ichi::__print_poorder(struct Ichi::Nodex *h) {
    if (h != nullptr) {
        Ichi::__print_poorder(h->lchild);
        Ichi::__print_poorder(h->rchild);
        Ichi::__print_element(h);
    }
}

bool Ichi::__exist_colored(struct Ichi::Nodex *h) {
    if (h != nullptr)
        return h->colored;
    else
        return false;
}

void Ichi::__color_flip(struct Ichi::Nodex *h) {
    h->colored         = !h->colored;
    h->lchild->colored = !h->lchild->colored;
    h->rchild->colored = !h->rchild->colored;
}

int Ichi::__getmin(struct Ichi::Nodex *h) { // assert that h != nullptr
    return (h->lchild != nullptr) ? Ichi::__getmin(h->lchild) : (h->val);
}

struct Ichi::Nodex * Ichi::__search(struct Ichi::Nodex *h, int _value) {
    if (h != nullptr
     && h->val != _value) {
        if (_value < h->val)
            return Ichi::__search(h->lchild, _value);
        else
            return Ichi::__search(h->rchild, _value);
    }
    return h;
}

struct Ichi::Nodex * Ichi::__rotate(struct Ichi::Nodex *h) {
    // left rotate a red link
    // |      [h]                   [q]      |
    // |     /   \        L        /   \     |
    // |    *     [q]    ==>    [h]     *    |
    // |         /   \         /   \         |
    // |        *     *       *     *        |
    // assume h != nullptr
    struct Ichi::Nodex * q = h->rchild;
    if (q != nullptr) {
        // Parsing Pointers of Children
        h->rchild = q->lchild;
        q->lchild = h;
        // Parsing Colors
        q->colored = h->colored;
        h->colored = true;
    }
    return q;
}

struct Ichi::Nodex * Ichi::__rotrev(struct Ichi::Nodex *h) {
    struct Ichi::Nodex * q = h->lchild;
    if (q != nullptr) {
        h->lchild = q->rchild;
        q->rchild = h;
        q->colored = h->colored;
        h->colored = true;
    }
    return q;
}

struct Ichi::Nodex * Ichi::__fix_up(struct Ichi::Nodex *h) {
    if (Ichi::__exist_colored(h->rchild)
    && !Ichi::__exist_colored(h->lchild))
        h = Ichi::__rotate(h);
    if (Ichi::__exist_colored(h->lchild)
     && Ichi::__exist_colored(h->lchild->lchild))
        h = Ichi::__rotrev(h);
    if (Ichi::__exist_colored(h->lchild)
     && Ichi::__exist_colored(h->rchild))
        Ichi::__color_flip(h);
    return h;
}

struct Ichi::Nodex * Ichi::__append(struct Ichi::Nodex *h, int _value) {
    if (h != nullptr) {
        if (_value != h->val) {
            if (_value < h->val)
                h->lchild = Ichi::__append(h->lchild, _value);
            else
                h->rchild = Ichi::__append(h->rchild, _value);
        }
        return Ichi::__fix_up(h);
    } else
        return Ichi::new_nodex(_value, true);
}

struct Ichi::Nodex * Ichi::__leften(struct Ichi::Nodex *h) {
    Ichi::__color_flip(h);
    if (Ichi::__exist_colored(h->rchild->lchild)) {
        h->rchild = Ichi::__rotrev(h->rchild);
        h = Ichi::__rotate(h);
        Ichi::__color_flip(h);
    }
    return h;
}

struct Ichi::Nodex * Ichi::__delmin(struct Ichi::Nodex *h) {
    if (h->lchild != nullptr) {
        if (!Ichi::__exist_colored(h->lchild)
         && !Ichi::__exist_colored(h->lchild->lchild))
            h = Ichi::__leften(h);
        h->lchild = Ichi::__delmin(h->lchild);
        return Ichi::__fix_up(h);
    } else {
        free(h);
        return nullptr;
    }
}

struct Ichi::Nodex * Ichi::__remove(struct Ichi::Nodex *h, int _value) {
    if (_value < h->val) {
        if (!Ichi::__exist_colored(h->lchild)
         && !Ichi::__exist_colored(h->lchild->lchild))
            h = Ichi::__leften(h);
        h->lchild = Ichi::__remove(h->lchild, _value);
    } else {
        if (Ichi::__exist_colored(h->lchild))
            h = Ichi::__rotrev(h);
        if (_value == h->val && h->rchild == nullptr) {
            free(h);
            return nullptr;
        }
        if (!Ichi::__exist_colored(h->rchild)
         && !Ichi::__exist_colored(h->rchild->lchild))
            h = __leften(h);
        if (_value == h->val) {
            h->val = Ichi::__getmin(h->rchild);
            h->rchild = Ichi::__delmin(h->rchild);
        } else
            h->rchild = Ichi::__remove(h->rchild, _value);
    }
    return __fix_up(h);
}

#endif