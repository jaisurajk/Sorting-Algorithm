#include "shell.h"

#include "gaps.h"
#include "stats.h"

#include <stdio.h>

#define GAPS 142

void shell_sort(Stats *stats, int *A, int n) {
    for (int i = 0; i < GAPS; i++) {
        for (int j = gaps[i]; j < n; j++) {
            int k = j;
            int temp = move(stats, A[j]);
            while (k >= gaps[i] && cmp(stats, temp, A[k - gaps[i]]) < 0) {
                A[k] = move(stats, A[k - gaps[i]]);
                k -= gaps[i];
            }
            A[k] = move(stats, temp);
        }
    }
}
