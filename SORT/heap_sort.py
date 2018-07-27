def KthLargest(L, N, K):
    for i in range(N // 2 - 1, -1, -1):
        heapify(L, N, i)

    for i in range(N - 1, N - K - 1, -1):
        L[0], L[i] = L[i], L[0]
        heapify(L, i, 0)


    print(L)
    print(L[N - K])


def heapify(L, N, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2

    if (l < N and L[l] > L[largest]):
        largest = l
    if r < N and L[r] > L[largest]:
        largest = r

    if largest != i:
        L[largest], L[i] = L[i], L[largest]
        heapify(L, N, largest)


L = list(map(int, input().split()))
N = L[0]
K = int(input())
KthLargest(L[1:], N, K)


