#include "libichi.h"
int arr[] = { 2, 0, 1, 7, 3, 9, 6, 5 };
class Ichi::List l1st;
class Ichi::Tree t2ee;
int main(int argc, char *argv[]) {
    for (int &x : arr) {
        t2ee.append(x);
        t2ee.printall();
    }
    t2ee.delmin();
    t2ee.printall();
    t2ee.remove(3);
    t2ee.printall();
    t2ee.clearall();
    t2ee.printall();
    printf("Sharing the World!\n");
    return 0;
}