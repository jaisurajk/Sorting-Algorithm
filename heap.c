#include "heap.h"

#include "stats.h"

#include <stdbool.h>
#include <stdio.h>

/*Purpose   Instead of this C code...   Use this C code...
*       -------   -------------------------   --------------------------
*       Compare   if (A < B)                  if (cmp(pstats, A, B) < 0)
*       Swap      tmp = A; A = B; B = tmp;    swap(pstats, &A, &B);
*       Move      A = B;                      A = move(pstats, B);
*/

int max_child(Stats *stats, int *A, int first, int last) {
    int left = 2 * first + 1;
    int right = 2 * first + 2;
    if (right <= last && cmp(stats, A[right], A[left]) > 0) {
        return right;
    }
    return left;
}

void fix_heap(Stats *stats, int *A, int first, int last) {
    bool done = false;
    int parent = first;
    while (2 * parent + 1 <= last && !done) {
        int largest_child = max_child(stats, A, parent, last);
        if (cmp(stats, A[parent], A[largest_child]) < 0) {
            swap(stats, &A[parent], &A[largest_child]);
            parent = largest_child;
        } else {
            done = true;
        }
    }
}

void build_heap(Stats *stats, int *A, int first, int last) {
    if (last > 0) {
        for (int i = (int) ((last - 1) / 2); i > first - 1; i--) {
            fix_heap(stats, A, i, last);
        }
    }
}
void heap_sort(Stats *stats, int *A, int n) {
    int first = 0;
    int last = n - 1;
    build_heap(stats, A, first, last);
    for (int i = last; i > first; i--) {
        swap(stats, &A[first], &A[i]);
        fix_heap(stats, A, first, i - 1);
    }
}
