#include<bits/stdc++.h>
using namespace std;

void printMaxSumInterval(int prev[], int i, int A[]) {
    if (prev[i] >= 0) {
        printMaxSumInterval(prev, prev[i], A);
    }
    cout << A[i] << " ";
}

void maxSumInterval(int a[], int n) {
    int sum[n];
    int prev[n];
    sum[0] = a[0];
    prev[0] = -1;

    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + a[i];
        prev[i] = i - 1;

        if (a[i] > sum[i]) {
            sum[i] = a[i];
            prev[i] = -1;
        }
    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (sum[i] > sum[maxIndex]) {
            maxIndex = i;
        }
    }

    printMaxSumInterval(prev, maxIndex, a);
}

int main() {
    int A[] = {0, 9, -3, 1, 7, -15, 2, 3, -4, 2, -7, 6, -2, 8, 4, -9};
    int n = sizeof(A) / sizeof(A[0]);

    maxSumInterval(A, n);

    return 0;
}
