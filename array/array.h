//
// Created by Dima on 06.02.2022.
//

#ifndef INC_5B_ARRAY_H
#define INC_5B_ARRAY_H

#include <stdlib.h>
#include <time.h>

int compare_ints(const void *a, const void *b);

//ввод массива data размера n
void inputArray_(int *a, size_t n);

// вывод массива data размера n
void outputArray_(const int *a, size_t n);

// возвращает значение первого вхождения элемента x
// в массиве a размера n при его наличии, иначе - n
size_t linearSearch_(const int *a, const size_t n, int x);

// возвращает позицию вхождения элемента x
// в отсортированном массиве a размера n при его наличии, иначе - SIZE_MAX
size_t binarySearch_(const int *a, const size_t n, int x);

// возвращает позицию первого элемента равного или большего x
// в отсортированном массиве a размера n
// при отсутствии такого элемента возвращает n
size_t binarySearchMoreOrEqual_(const int *a, const size_t n, int x);

// возвращает позицию последнего элемента меньшего или равного x
// (вернёт -1, если все числа больше x)
int binarySearchLessOrEqual_(const int *a, const int n, const int x);

// вставка элемента со значением value
// в массив data размера n на позицию pos
void insert_(int *a, size_t *n, size_t pos, int value);

// добавление элемента value в конец массива data размера n
void append_(int *a, size_t *n, int value);

//копирует массив a в массив b размера n
void copyArray(int *b, const int *a, size_t n);

// удаление из массива data размера n элемента на позиции pos
// с сохранением порядка оставшихся элементов
void deleteByPosSaveOrder_(int *a, size_t *n, size_t pos);

// удаление из массива data размера n элемента на позиции pos
// без сохранения порядка оставшихся элементов
// размер массива data уменьшается на единицу
void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos);

// возвращает значение ’истина’ если все элементы
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int all_(const int *a, size_t n, int (*predicate )(int));

// возвращает значение ’истина’ если хотя бы один элемент
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int any_(const int *a, size_t n, int (*predicate )(int));

// применяет функцию predicate ко всем элементам массива source
// размера n и сохраняет результат в массиве dest размера n
void forEach_(const int *source, int *dest, size_t n, const int (*
predicate )(int));

// возвращает количество элементов массива data размера n
// удовлетворяющих функции-предикату predicate
int countIf_(const int *a, size_t n, int (*predicate )(int));

// удаляет из массива data размера n все элементы, удовлетворяющие
// функции-предикату deletePredicate, записывает в n новый размер
// массива
void deleteIf_(int *a, size_t *n, int (*deletePredicate )(int));

//сортировка слиянием
void merge(const int *a, const int n,
           const int *b, const int m, int *c);

//обменивает значения переменных a и b
void swap(int *a, int *b);

int firstMinElementSearch(const int *const a, const size_t n);

int negativeElementsCount(int *a, int n);

int isOrdered(const int *a, const size_t n);

//сортировка пузырьком массива a размера n
void bubbleSort(int *a, const size_t n);

//сортировка выбором массива a размера n
void selectionSort(int *a, const size_t n);

//сортировка вставками массива a размера n
void insertionSort(int *a, const size_t size);

//сортировка расчёской массива а размера n
void combsort(int *a, const size_t size);

//сортировка Шелла массива а размера n
void shellSort(int *a, const size_t size);

//сортировка подсчётом массива a размера n
void countSort(int *a, const size_t size);

//цифровая сортировка массива a размера n
void radixSort(int *a, const size_t size);

void generateRandomArray(int *a, size_t size);

void generateOrderedArray(int *a, size_t size);

void generateOrderedBackwards(int *a, size_t size);


unsigned long long getBubbleSortNComps(int *a, const size_t n);


unsigned long long getSelectionSortNComps(int *a, const size_t n);


unsigned long long getInsertionSortNComps(int *a, const size_t size);


unsigned long long getCombsortNComps(int *a, const size_t size);


unsigned long long getShellSortNComps(int *a, const size_t size);


unsigned long long getCountSortNComps(int *a, const size_t size);


unsigned long long getRadixSortNComps(int *a, const size_t size);


#endif //INC_5B_ARRAY_H
