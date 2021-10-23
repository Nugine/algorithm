// https://leetcode-cn.com/problems/the-dining-philosophers/

#include <algorithm>
#include <condition_variable>
#include <functional>
#include <mutex>
using namespace std;

constexpr int N = 5;

class DiningPhilosophers {
    bool forks[N];
    mutex lock;
    condition_variable cond_var;

  public:
    DiningPhilosophers() { fill(forks, forks + N, true); }

    void wantsToEat(                    //
        int philosopher,                //
        function<void()> pickLeftFork,  //
        function<void()> pickRightFork, //
        function<void()> eat,           //
        function<void()> putLeftFork,   //
        function<void()> putRightFork   //
    ) {
        bool &left = forks[philosopher];
        bool &right = forks[(philosopher + 1) % N];

        {
            unique_lock<mutex> guard(lock);
            cond_var.wait(guard, [&]() { return left && right; });
            left = right = false;
            pickLeftFork();
            pickRightFork();
        }
        eat();
        {
            unique_lock<mutex> guard(lock);
            putLeftFork();
            putRightFork();
            left = right = true;
            cond_var.notify_all();
        }
    }
};