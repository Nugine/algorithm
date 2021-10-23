// https://leetcode-cn.com/problems/building-h2o/

#include <atomic>
#include <functional>
#include <semaphore.h>
using namespace std;

class H2O {
    sem_t s1, s2;
    atomic_uint8_t count;

  public:
    H2O() : count(0) {
        sem_init(&s1, 0, 2);
        sem_init(&s2, 0, 0);
    }
    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&s1);
        releaseHydrogen();
        uint8_t cnt = count.fetch_add(1, memory_order_relaxed) + 1;
        if ((cnt & 1) == 0) {
            sem_post(&s2);
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&s2);
        releaseOxygen();
        sem_post(&s1);
        sem_post(&s1);
    }
};