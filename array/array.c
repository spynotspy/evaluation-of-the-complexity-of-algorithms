//
// Created by Dima on 06.02.2022.
//
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include "array.h"


int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

void inputArray_(int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void outputArray_(const int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void append_(int *const a, size_t *const n, const int value) {
    a[*n] = value;
    (*n)++;
}

void copyArray(int *b, const int *a, size_t n) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i];
    }
}


void insert_(int *const a, size_t *const n, const size_t pos,
             const int value) {
    assert(pos < *n);
    if (*n != 0) {
        size_t lowBound = (pos == 0) ? SIZE_MAX : pos;

        (*n)++;
        for (size_t i = *n; i != lowBound; i--)
            a[i] = a[i - 1];
        a[pos] = value;
    } else {
        (*n)++;
        a[pos] = value;
    }
}


void deleteByPosSaveOrder_(int *a, size_t *n, const size_t pos) {
    for (size_t i = pos + 1; i < *n; i++)
        a[i] = a[i + 1];
    (*n)--;
}

void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos) {
    a[pos] = a[*n - 1];
    (*n)--;
}

size_t linearSearch_(const int *a, const size_t n, int x) {
    for (size_t i = 0; i < n; i++)
        if (a[i] == x)

            return i;

    return n;

}


int any_(const int *a, size_t n, int (*predicate )(int)) {

    for (size_t i = 0; i < n; i++)

        if (predicate(a[i]))

            return 1;

    return 0;

}


int all_(const int *a, size_t n, int (*predicate )(int)) {

    for (size_t i = 0; i < n; i++)

        if (!predicate(a[i]))

            return 0;

    return 1;

}


int countIf_(const int *const a, const size_t n, int (*predicate )(int)) {

    int count = 0;

    for (size_t i = 0; i < n; i++)

        count += predicate(a[i]);

    return count;

}


void deleteIf_(int *const a, size_t *const n, int (*deletePredicate )(
        int)) {
    size_t iRead = 0;

    while (iRead < *n && !deletePredicate(a[iRead]))

        iRead++;

    size_t iWrite = iRead;

    while (iRead < *n) {

        if (!deletePredicate(a[iRead])) {

            a[iWrite] = a[iRead];

            iWrite++;


        }

        iRead++;

    }
    *n = iWrite;

}


void forEach_(const int *source, int *dest, const size_t n, const int (*
predicate )(int)) {

    for (size_t i = 0; i < n; i++)

        dest[i] = predicate(source[i]);

}


size_t binarySearch_(const int *a, const size_t n, int x) {
    if (n == 0)
        return n;

    size_t left = 0;

    size_t right = n - 1;

    while (left <= right) {

        size_t middle = left + (right - left) / 2;

        if (a[middle] < x)

            left = middle + 1;
        else if (a[middle] > x)
            right = middle - 1;
        else
            return middle;
    }
    return n;
}

size_t binarySearchMoreOrEqual_(const int *a, size_t n, int x) {
    if (a[0] >= x)
        return 0;
    size_t left = 0;
    size_t right = n;
    while (right - left > 1) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle;
        else
            right = middle;
    }
    return right;
}

int binarySearchLessOrEqual_(const int *a, const int n, const int x) {
    int left = -1;
    int right = n;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (a[middle] <= x)
            left = middle;
        else
            right = middle;
    }
    return left;
}


void merge(const int *a, const int n,
           const int *b, const int m, int *c) {
    int i = 0, j = 0;
    while (i < n || j < m) {
        if (j == m || i < n && a[i] < b[j]) {
            c[i + j] = a[i];
            i++;
        } else {
            c[i + j] = b[j];
            j++;
        }
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


int firstMinElementSearch(const int *const a, const size_t n) {
    int firstIndexMin = 0;
    int min = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] < min) {
            firstIndexMin = i;
            min = a[i];
        }
    }
    return firstIndexMin;
}

int negativeElementsCount(int *a, int n) {
    int count = 0;
    for (size_t i = 0; i < n; i++) {
        if (a[i] < 0)
            count++;
    }
    return count;
}

int isOrdered(const int *a, const size_t n) {
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1])
            return 0;
    }
    return 1;
}

//???????????????? ???????????????????? ?????????????? a ?????????????? size
void bubbleSort(int *a, const size_t size) {
    for (int i = 0; i < size; ++i)
        for (int j = i; j < size; ++j)
            if (a[i] > a[j])
                swap(&a[i], &a[j]);
}

//???????????????????? ?????????????? a ?????????????? size ??????????????
void selectionSort(int *a, const size_t size) {
    int min;
    for (size_t i = 0; i < size - 1; i++) {
        min = i;
        for (size_t j = i + 1; j < size; j++) {
            if (a[j] < a[min])
                min = j;
        }
        swap(&a[i], &a[min]);
    }
}

//???????????????????? ?????????????????? ?????????????? a ?????????????? size
void insertionSort(int *a, const size_t size) {
    for (size_t i = 1; i < size; i++) {
        int t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

//???????????????????? ?????????????????? ?????????????? a ?????????????? size
void combsort(int *a, const size_t size) {
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size; ++i, ++j)
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }
}

//???????????????????? ?????????? ?????????????? a ?????????????? size
void shellSort(int *a, size_t size) {
    for (int step = size / 2; step > 0; step /= 2)
        for (int i = step; i < size; ++i)
            for (int j = i - step; j >= 0 && a[j] > a[j + step]; j -= step)
                swap(&a[j], &a[j + step]);

}


void getMinMax(const int *a, size_t size, int *min, int *max) {
    *min = a[0];
    *max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] < *min)
            *min = a[i];
        else if (a[i] > *max)
            *max = a[i];
    }
}

void countSort(int *a, const size_t size) {
    int min, max;
    getMinMax(a, size, &min, &max);
    int k = max - min + 1;

    // ?????????????????? ???????????? ?????? ???????????????????????? ???????????? ???? k ??????????????????,
    // ?????? ???????????? ???? ?????????????????? ?????????? 0
    int *b = (int *) calloc(k, sizeof(int));
    for (int i = 0; i < size; i++)
        b[a[i] - min]++;

    int ind = 0;
    for (int i = 0; i < k; i++) {
        int x = b[i];
        for (int j = 0; j < x; j++)
            a[ind++] = min + i;
    }

    // ???????????????????????? ????????????, ???????????????????? ?????? ???????????????????????? ????????????
    free(b);
}

int digit(int n, int k, int N, int M) {
    return (n >> (N * k) & (M - 1));
}


void _radixSort(int *l, int *r, int N) {
    int k = (32 + N - 1) / N;
    int M = 1 << N;
    int sz = r - l;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < M; j++)
            c[j] = 0;

        for (int *j = l; j < r; j++)
            c[digit(*j, i, N, M)]++;

        for (int j = 1; j < M; j++)
            c[j] += c[j - 1];

        for (int *j = r - 1; j >= l; j--)
            b[--c[digit(*j, i, N, M)]] = *j;

        int cur = 0;
        for (int *j = l; j < r; j++)
            *j = b[cur++];
    }
    free(b);
    free(c);
}

//???????????????? ???????????????????? ?????????????? a ?????????????? size
void radixSort(int *a, size_t size) {
    _radixSort(a, a + size, 8);
}

unsigned long long getBubbleSortNComps(int *a, const size_t n) {
    unsigned long long nComps = 0;
    for (int i = 0; ++nComps && i < n; ++i)
        for (int j = i; ++nComps && j < n; ++j)
            if (++nComps && a[i] > a[j]) {
                swap(&a[i], &a[j]);
            }

    return nComps;
}

unsigned long long getSelectionSortNComps(int *a, size_t n) {
    unsigned long long nComps = 0;
    for (int i = 0; ++nComps && i < n; i++) {
        int min = a[i];
        int minIndex = i;
        for (int j = i + 1; ++nComps && j < n; j++)
            if (++nComps && a[j] < min) {
                min = a[j];
                minIndex = j;
            }
        if (++nComps && i != minIndex) {
            swap(&a[i], &a[minIndex]);
        }
    }
    return nComps;
}


unsigned long long getInsertionSortNComps(int *a, const size_t size) {
    unsigned long long nComps = 0;
    for (size_t i = 1; ++nComps && i < size; i++) {
        int t = a[i];
        int j = i;
        while (++nComps && j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }

    return nComps;
}


unsigned long long getCombsortNComps(int *a, const size_t size) {
    size_t step = size;
    int swapped = 1;
    unsigned long long nComps = 2;
    while (++nComps && step > 1 || swapped) {
        if (++nComps && step > 1) {
            step /= 1.24733;
        }
        swapped = 0;
        for (size_t i = 0, j = i + step; ++nComps && j < size; ++i, ++j)
            if (++nComps && a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }

    return nComps;
}


unsigned long long getShellSortNComps(int *a, const size_t size) {
    unsigned long long nComps = 0;
    for (int step = size / 2; ++nComps && step > 0; step /= 2)
        for (int i = step; ++nComps && i < size; ++i)
            for (int j = i - step; ++nComps && j >= 0 && ++nComps && a[j] > a[j + step]; j -= step)
                swap(&a[j], &a[j + step]);

    return nComps;
}

unsigned long long getCountSortNComps(int *a, const size_t size) {
    int min, max;
    getMinMax(a, size, &min, &max);
    int k = max - min + 1;

    // ?????????????????? ???????????? ?????? ???????????????????????? ???????????? ???? k ??????????????????,
    // ?????? ???????????? ???? ?????????????????? ?????????? 0
    int *b = (int *) calloc(k, sizeof(int));
    for (int i = 0; i < size; i++)
        b[a[i] - min]++;

    int ind = 0;
    for (int i = 0; i < k; i++) {
        int x = b[i];
        for (int j = 0; j < x; j++)
            a[ind++] = min + i;
    }

    // ???????????????????????? ????????????, ???????????????????? ?????? ???????????????????????? ????????????
    free(b);
}

unsigned long long getRadixSortNComps(int *a, const size_t size) {
    int N = 8;
    int *l = a;
    int *r = a + size;
    int k = (32 + N - 1) / N;
    int M = 1 << N;
    int sz = r - l;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    unsigned long long nComps = 0;
    for (int i = 0; ++nComps && i < k; i++) {
        for (int j = 0; ++nComps && j < M; j++) {
            c[j] = 0;
        }
        for (int *j = l; ++nComps && j < r; j++) {
            c[digit(*j, i, N, M)]++;
        }
        for (int j = 1; ++nComps && j < M; j++) {
            c[j] += c[j - 1];
        }

        for (int *j = r - 1; ++nComps && j >= l; j--) {
            b[--c[digit(*j, i, N, M)]] = *j;
        }
        int cur = 0;
        for (int *j = l; ++nComps && j < r; j++) {
            *j = b[cur++];
        }
    }
    free(b);
    free(c);

    return nComps;
}

void generateRandomArray(int *a, size_t size) {
    for (int i = 0; i < size; ++i)
        a[i] = rand() % (1000 - 1 + 1) + 1;
}

void generateOrderedArray(int *a, size_t size) {
    for (int i = 0; i < size; i++)
        a[i] = i;
}

void generateOrderedBackwards(int *a, size_t size) {
    int i = 0;
    int j = size - 1;
    while (j != 0)
        a[i++] = j--;
}