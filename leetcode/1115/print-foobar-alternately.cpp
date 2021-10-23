// https://leetcode-cn.com/problems/print-foobar-alternately/

#include <functional>
#include <semaphore.h>
using namespace std;

class FooBar {
    const int n;
    sem_t s1, s2;

  public:
    FooBar(int n) : n(n) {
        sem_init(&s1, 0, 1);
        sem_init(&s2, 0, 0);
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            sem_wait(&s1);
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            sem_post(&s2);
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            sem_wait(&s2);
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            sem_post(&s1);
        }
    }
};