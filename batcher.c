#include "batcher.h"

#include "stats.h"

#include <stdio.h>

// int bit_length(int n){
//     int count = 0;
//     while (n){
//         count++;
//         n >>= 1;
//     }
//     return count;
// }

void comparator(Stats *stats, int *A, int x, int y) {
    if (cmp(stats, A[x], A[y]) > 0) {
        swap(stats, &A[x], &A[y]);
    }
}

void batcher_sort(Stats *stats, int *A, int n) {
    if (n == 0) {
        return;
    }
    int t = 0;
    int m = n;
    while (m) {
        t++;
        m >>= 1;
    }
    int p = 1 << (t - 1);
    while (p > 0) {
        int q = 1 << (t - 1);
        int r = 0;
        int d = p;

        while (d > 0) {
            for (int i = 0; i < n - d; i++) {
                if ((i & p) == r) {
                    comparator(stats, A, i, i + d);
                }
            }
            d = q - p;
            q >>= 1;
            r = p;
        }
        p >>= 1;
    }
}

/* Driver program*/

// int main()
// {
//     int i = 63;
//     printf("%d\n", bit_length(i));
//     return 0;
// }
