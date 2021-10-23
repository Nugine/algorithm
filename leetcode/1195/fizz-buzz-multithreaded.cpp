// https://leetcode-cn.com/problems/fizz-buzz-multithreaded/

#include <atomic>
#include <functional>
#include <semaphore.h>
using namespace std;

class FizzBuzz {
    const int n;
    atomic_uint32_t count;
    sem_t s[4];

  public:
    FizzBuzz(int n) : n(n), count(1) {
        sem_init(s + 0, 0, 0);
        sem_init(s + 1, 0, 0);
        sem_init(s + 2, 0, 0);
        sem_init(s + 3, 0, 1);
    }

    void next() {
        count += 1;
        if (count > n) {
            for (int i = 0; i < 4; ++i) {
                sem_post(s + i);
            }
            return;
        }
        uint8_t state = uint8_t(count % 3 == 0) * 2 + uint8_t(count % 5 == 0);
        switch (state) {
        case 2:
            sem_post(s + 0);
            break;
        case 1:
            sem_post(s + 1);
            break;
        case 3:
            sem_post(s + 2);
            break;
        case 0:
            sem_post(s + 3);
        }
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for (;;) {
            sem_wait(s + 0);
            if (count > n) {
                break;
            }
            printFizz();
            next();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (;;) {
            sem_wait(s + 1);
            if (count > n) {
                break;
            }
            printBuzz();
            next();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        for (;;) {
            sem_wait(s + 2);
            if (count > n) {
                break;
            }
            printFizzBuzz();
            next();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (;;) {
            sem_wait(s + 3);
            if (count > n) {
                break;
            }
            printNumber(count);
            next();
        }
    }
};