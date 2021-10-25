#include <array>
#include <cstdio>
#include <tuple>
using namespace std;
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))

const int M = 3;
const int N = 5;

array<int, M> available = {3, 3, 2};

array<int, M> max_allocation[N] = {
    {7, 5, 3}, //
    {3, 2, 2}, //
    {9, 0, 2}, //
    {2, 2, 2}, //
    {4, 3, 3}, //
};

array<int, M> allocation[N] = {
    {0, 1, 0}, //
    {2, 0, 0}, //
    {3, 0, 2}, //
    {2, 1, 1}, //
    {0, 0, 2}, //
};

array<int, M> need[N];
void calc_need() {
    int i, j;
    rng(i, 0, N) {
        rng(j, 0, M) { need[i][j] = max_allocation[i][j] - allocation[i][j]; }
    }
}

enum class ErrorCode {
    Ok = 0,
    Invalid = 1,
    NotEnough = 2,
    Unsafe = 3,
};

template <typename T, unsigned long L>
void print_array(const char *name, const array<T, L> &arr) {
    printf("%s = [", name);
    int i;
    rng(i, 0, L) { printf("%d, ", arr[i]); }
    printf("]");
}

template <typename T, unsigned long L>
bool all_less_equal(const array<T, L> &lhs, const array<T, L> &rhs) {
    int i;
    const T *l = lhs.data(), *r = rhs.data();
    rng(i, 0, L) {
        if (!(l[i] <= r[i])) {
            break;
        }
    }
    return i == L;
}

template <typename T, unsigned long L>
void add_assign(array<T, L> &lhs, const array<T, L> &rhs) {
    T *l = lhs.data();
    const T *r = rhs.data();
    int i;
    rng(i, 0, L) { l[i] += r[i]; }
}

template <typename T, unsigned long L>
void sub_assign(array<T, L> &lhs, const array<T, L> &rhs) {
    T *l = lhs.data();
    const T *r = rhs.data();
    int i;
    rng(i, 0, L) { l[i] -= r[i]; }
}

ErrorCode check_safety();

ErrorCode allocate(int i, const array<int, M> &request) {
    int j;
    if (!all_less_equal(request, need[i])) {
        return ErrorCode::Invalid;
    }
    if (!all_less_equal(request, available)) {
        return ErrorCode::NotEnough;
    }
    sub_assign(available, request);
    sub_assign(need[i], request);
    add_assign(allocation[i], request);
    ErrorCode err = check_safety();
    if (err != ErrorCode::Ok) {
        add_assign(available, request);
        add_assign(need[i], request);
        sub_assign(allocation[i], request);
    }
    return err;
}

ErrorCode check_safety() {
    array<int, M> work;
    array<int, N> finish;
    int i, j;

    work = available;
    fill(finish.begin(), finish.end(), false);

    printf("checking safety...\n");

    int not_finished = N;
    while (not_finished > 0) {
        rng(i, 0, N) {
            if (finish[i] == false && all_less_equal(need[i], work)) {
                break;
            }
        }
        if (i < N) {
            add_assign(work, allocation[i]);
            finish[i] = true;
            not_finished -= 1;
            printf("finish %d\n", i);
            print_array("work", work);
            printf("\n");
        } else {
            return ErrorCode::Unsafe;
        }
    }
    return ErrorCode::Ok;
}

int main() {
    calc_need();

    tuple<int, array<int, M>> requests[3] = {
        {1, {1, 0, 2}}, //
        {4, {3, 3, 0}}, //
        {0, {0, 2, 0}}, //
    };

    ErrorCode err;
    err = check_safety();
    if (err != ErrorCode::Ok) {
        exit(1);
    }
    printf("\n");

    int j;
    for (const auto &[i, request] : requests) {
        printf("allocate i = %d, ", i);
        print_array("request", request);
        printf("\n");

        err = allocate(i, request);

        printf("err = %d\n", int(err));
        printf("\n");
        if (err == ErrorCode::Unsafe) {
            break;
        }
    }
}