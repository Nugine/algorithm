from typing import List, Tuple
import numpy as np
from pprint import pprint

M = 3
N = 5

available: np.ndarray = np.array([3, 3, 2])

max_allocation: np.ndarray = np.array(
    [
        [7, 5, 3],
        [3, 2, 2],
        [9, 0, 2],
        [2, 2, 2],
        [4, 3, 3],
    ]
)

allocation: np.ndarray = np.array(
    [
        [0, 1, 0],
        [2, 0, 0],
        [3, 0, 2],
        [2, 1, 1],
        [0, 0, 2],
    ]
)


need = max_allocation - allocation

print(f"need = {need}")


def check_safety():
    global available
    global need
    work = np.copy(available)
    finish = np.full((N,), False)

    print("checking safety...")

    not_finished = N
    while not_finished > 0:
        target = None
        for i in range(0, N):
            if not finish[i] and all(need[i] <= work):
                target = i
                break
        if target is not None:
            work += allocation[i]
            finish[i] = True
            not_finished -= 1
            print(f"finished {i}")
            print(f"work = {work}")
        else:
            raise Exception("unsafe")


def allocate(i: int, request: np.ndarray):
    global available
    global need
    global allocation
    if not all(request <= need[i]):
        raise Exception("invalid")
    if not all(request <= available):  # type: ignore
        raise Exception("not enough")

    available -= request  # type: ignore
    need[i] -= request
    allocation[i] += request

    try:
        check_safety()
    except Exception as e:
        available += request  # type: ignore
        need[i] += request
        allocation[i] -= request
        raise e


if __name__ == "__main__":
    check_safety()
    print()

    requests: List[Tuple[int, np.ndarray]] = [
        (1, np.array([1, 0, 2])),
        (4, np.array([3, 3, 0])),
        (0, np.array([0, 2, 0])),
    ]

    for (i, request) in requests:
        print(f"allocate i = {i}, request = {request}")
        try:
            allocate(i, request)
        except Exception as e:
            print(e)
        print()
