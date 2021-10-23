// https://leetcode-cn.com/problems/the-dining-philosophers/

#include <algorithm>
#include <functional>
#include <semaphore.h>
using namespace std;

constexpr int N = 5;

class DiningPhilosophers {
    sem_t forks[N];

  public:
    DiningPhilosophers() {
        for (int i = 0; i < N; ++i) {
            sem_init(&forks[i], 0, 1);
        }
    }

    void wantsToEat(                    //
        int philosopher,                //
        function<void()> pickLeftFork,  //
        function<void()> pickRightFork, //
        function<void()> eat,           //
        function<void()> putLeftFork,   //
        function<void()> putRightFork   //
    ) {
        sem_t &left = forks[philosopher];
        sem_t &right = forks[(philosopher + 1) % N];

        if (philosopher & 1) {
            sem_wait(&left);
            sem_wait(&right);
            pickLeftFork();
            pickRightFork();
            eat();
            putRightFork();
            putLeftFork();
            sem_post(&right);
            sem_post(&left);
        } else {
            sem_wait(&right);
            sem_wait(&left);
            pickRightFork();
            pickLeftFork();
            eat();
            putLeftFork();
            putRightFork();
            sem_post(&left);
            sem_post(&right);
        }
    }
};