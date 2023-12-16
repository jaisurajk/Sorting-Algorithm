#include "quick.h"

#include "stats.h"

#include <stdio.h>

/*Purpose   Instead of this C code...   Use this C code...
*       -------   -------------------------   --------------------------
*       Compare   if (A < B)                  if (cmp(pstats, A, B) < 0)
*       Swap      tmp = A; A = B; B = tmp;    swap(pstats, &A, &B);
*       Move      A = B;                      A = move(pstats, B);
*/

int partition(Stats *stats, int *A, int lo, int hi) {
    int i = lo - 1;
    for (int j = lo; j < hi; j++) {
        if (cmp(stats, A[j], A[hi]) < 0) {
            i += 1;
            swap(stats, &A[i], &A[j]);
        }
    }
    i += 1;
    swap(stats, &A[i], &A[hi]);
    return i;
}

void quick_sorter(Stats *stats, int *A, int lo, int hi) {
    if (cmp(stats, lo, hi) < 0) {
        int p = partition(stats, A, lo, hi);
        quick_sorter(stats, A, lo, p - 1);
        quick_sorter(stats, A, p + 1, hi);
    }
}

void quick_sort(Stats *stats, int *A, int n) {
    quick_sorter(stats, A, 0, n - 1);
}
