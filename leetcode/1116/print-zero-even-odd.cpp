// https://leetcode-cn.com/problems/print-zero-even-odd/

#include <functional>
#include <semaphore.h>
using namespace std;

class ZeroEvenOdd {
    const int n;
    sem_t s[3];

  public:
    ZeroEvenOdd(int n) : n(n) {
        sem_init(&s[0], 0, 1);
        sem_init(&s[1], 0, 0);
        sem_init(&s[2], 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            sem_wait(&s[0]);
            printNumber(0);
            sem_post(&s[(i & 1) + 1]);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            sem_wait(&s[1]);
            printNumber(i);
            sem_post(&s[0]);
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            sem_wait(&s[2]);
            printNumber(i);
            sem_post(&s[0]);
        }
    }
};