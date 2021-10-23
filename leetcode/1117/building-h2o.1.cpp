// https://leetcode-cn.com/problems/building-h2o/

#include <condition_variable>
#include <functional>
#include <mutex>
using namespace std;

class H2O {
    mutex lock;
    condition_variable cond_var;
    uint8_t state;

  public:
    H2O() : state(0) {}

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> guard(lock);
        cond_var.wait(guard, [this]() { return (state >> 1) < 2; });
        state += 2;
        releaseHydrogen();
        if (state == 5) {
            state = 0;
        }
        cond_var.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> guard(lock);
        cond_var.wait(guard, [this]() { return (state & 1) == 0; });
        state |= 1;
        releaseOxygen();
        if (state == 5) {
            state = 0;
        }
        cond_var.notify_all();
    }
};