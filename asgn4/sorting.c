#include "batcher.h"
#include "gaps.h"
#include "heap.h"
#include "insert.h"
#include "quick.h"
#include "set.h"
#include "shell.h"
#include "stats.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// #define seed 13371453
#define OPTIONS "Hahbsqin:p:r:"
// #define length 100
// #define num_elem 100

int main(int argc, char **argv) {
    int seed = 13371453;
    int length = 100;
    int num_elem = 100;
    enum sort_type { a, h, b, s, q, i };
    Stats stats;
    Set set = set_empty();
    int opt;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a': set = set_insert(set, a); break;
        case 'h': set = set_insert(set, h); break;
        case 'b': set = set_insert(set, b); break;
        case 's': set = set_insert(set, s); break;
        case 'q': set = set_insert(set, q); break;
        case 'i': set = set_insert(set, i); break;
        case 'n':
            // printf("%s an opt argument1", optarg);
            length = atoi(optarg);
            break;
        case 'p':
            // printf("%s an opt argument2", optarg);
            num_elem = atoi(optarg);
            break;
        case 'r':
            // printf("%s an opt argument2", optarg);
            seed = atoi(optarg);
            break;
        case 'H':
            printf("%s\n", "SYNOPSIS");
            printf("%s\n", "   A collection of comparison-based sorting algorithms.");
            printf("\n%s\n", "USAGE");
            printf("%s\n", "   ./sorting [-Hahbsqi] [-n length] [-p elements] [-r seed]");
            printf("\n%s\n", "OPTIONS");
            printf("%s\n", "   -H              Display program help and usage.");
            printf("%s\n", "   -a              Enable all sorts.");
            printf("%s\n", "   -h              Enable Heap Sort.");
            printf("%s\n", "   -b              Enable Batcher Sort.");
            printf("%s\n", "   -s              Enable Shell Sort.");
            printf("%s\n", "   -q              Enable Quick Sort.");
            printf("%s\n", "   -i              Enable Insertion Sort.");
            printf("%s\n", "   -n length       Specify number of array elements (default: 100).");
            printf(
                "%s\n", "   -p elements     Specify number of elements to print (default: 100).");
            printf("%s\n", "   -r seed         Specify random seed (default: 13371453).");
            return 0;
        default:
            printf("%s\n", "SYNOPSIS");
            printf("%s\n", "   A collection of comparison-based sorting algorithms.");
            printf("\n%s\n", "USAGE");
            printf("%s\n", "   ./sorting [-Hahbsqi] [-n length] [-p elements] [-r seed]");
            printf("\n%s\n", "OPTIONS");
            printf("%s\n", "   -H              Display program help and usage.");
            printf("%s\n", "   -a              Enable all sorts.");
            printf("%s\n", "   -h              Enable Heap Sort.");
            printf("%s\n", "   -b              Enable Batcher Sort.");
            printf("%s\n", "   -s              Enable Shell Sort.");
            printf("%s\n", "   -q              Enable Quick Sort.");
            printf("%s\n", "   -i              Enable Insertion Sort.");
            printf("%s\n", "   -n length       Specify number of array elements (default: 100).");
            printf(
                "%s\n", "   -p elements     Specify number of elements to print (default: 100).");
            printf("%s\n", "   -r seed         Specify random seed (default: 13371453).");
            return 0;
        }
    }
    if (!set) {
        return 0;
    }
    if (num_elem > length) {
        num_elem = length;
    }
    srandom(seed);
    int *arr = malloc(length * sizeof(int));
    // int *t_arr = malloc(length * sizeof(uint32_t));
    // int *arr = arr[length];
    // int arr[length];
    for (int i = 0; i < length; i++) {
        arr[i] = rand() & 0x3FFFFFFF;
    }
    if (set_member(set, a)) {
        reset(&stats);
        insertion_sort(&stats, arr, length);
        print_stats(&stats, "Insertion Sort", length);
        for (int i = 0; i < num_elem; i++) {
            if (i != 0 && i % 5 == 0) {
                printf("\n");
            }
            printf("%13d", arr[i]);
        }
        if (num_elem != 0) {
            printf("\n");
        }
        reset(&stats);
        heap_sort(&stats, arr, length);
        print_stats(&stats, "Heap Sort", length);
        for (int i = 0; i < num_elem; i++) {
            if (i != 0 && i % 5 == 0) {
                printf("\n");
            }
            printf("%13d", arr[i]);
        }
        if (num_elem != 0) {
            printf("\n");
        }
        reset(&stats);
        shell_sort(&stats, arr, length);
        print_stats(&stats, "Shell Sort", length);
        for (int i = 0; i < num_elem; i++) {
            if (i != 0 && i % 5 == 0) {
                printf("\n");
            }
            printf("%13d", arr[i]);
        }
        if (num_elem != 0) {
            printf("\n");
        }
        reset(&stats);
        quick_sort(&stats, arr, length);
        print_stats(&stats, "Quick Sort", length);
        for (int i = 0; i < num_elem; i++) {
            if (i != 0 && i % 5 == 0) {
                printf("\n");
            }
            printf("%13d", arr[i]);
        }
        if (num_elem != 0) {
            printf("\n");
        }
        reset(&stats);
        batcher_sort(&stats, arr, length);
        print_stats(&stats, "Batcher Sort", length);
        for (int i = 0; i < num_elem; i++) {
            if (i != 0 && i % 5 == 0) {
                printf("\n");
            }
            printf("%13d", arr[i]);
        }
        if (num_elem != 0) {
            printf("\n");
        }
    } else if (set_member(set, h)) {
        reset(&stats);
        heap_sort(&stats, arr, length);
        print_stats(&stats, "Heap Sort", length);
        for (int i = 0; i < num_elem; i++) {
            if (i != 0 && i % 5 == 0) {
                printf("\n");
            }
            printf("%13d", arr[i]);
        }
        if (num_elem != 0) {
            printf("\n");
        }
    } else if (set_member(set, b)) {
        reset(&stats);
        batcher_sort(&stats, arr, length);
        print_stats(&stats, "Batcher Sort", length);
        for (int i = 0; i < num_elem; i++) {
            if (i != 0 && i % 5 == 0) {
                printf("\n");
            }
            printf("%13d", arr[i]);
        }
        if (num_elem != 0) {
            printf("\n");
        }
    } else if (set_member(set, s)) {
        reset(&stats);
        shell_sort(&stats, arr, length);
        print_stats(&stats, "Shell Sort", length);
        for (int i = 0; i < num_elem; i++) {
            if (i != 0 && i % 5 == 0) {
                printf("\n");
            }
            printf("%13d", arr[i]);
        }
        if (num_elem != 0) {
            printf("\n");
        }
    } else if (set_member(set, q)) {
        reset(&stats);
        quick_sort(&stats, arr, length);
        print_stats(&stats, "Quick Sort", length);
        for (int i = 0; i < num_elem; i++) {
            if (i != 0 && i % 5 == 0) {
                printf("\n");
            }
            printf("%13d", arr[i]);
        }
        if (num_elem != 0) {
            printf("\n");
        }
    } else if (set_member(set, i)) {
        reset(&stats);
        insertion_sort(&stats, arr, length);
        print_stats(&stats, "Insertion Sort", length);
        for (int i = 0; i < num_elem; i++) {
            if (i != 0 && i % 5 == 0) {
                printf("\n");
            }
            printf("%13d", arr[i]);
        }
        if (num_elem != 0) {
            printf("\n");
        }
    }
    free(arr);
    return 0;
}
