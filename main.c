#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

void GenerateArray(int* array, size_t size){
    for (size_t i = 0; i < size; i++){
        array[i] = -100 + rand() * time(NULL) % 20;
    }
}

void Swap(int* first, int* second){
    int tmp = *first;
    *first = * second;
    *second = tmp;
}


void ChoiceSort(int* array, size_t size){
    size_t minPos = 0;
    int tmp = 0;
    for (size_t i = 0; i < size; i++){
        minPos = i;
        for (size_t j = i + 1; j < size; j++){
            if (array[minPos] > array[j]) minPos = j;
        }
        Swap(&array[minPos], &array[i]);
    }
}


void BubbleSort(int* array, size_t size){
    int noSwap = 0;
    int tmp = 0;
    for (size_t i = size - 1; i >= 0; i--){
        noSwap = 1;
        for (size_t j = 0; j < i; j++){
            if (array[j] > array[j + 1]){
                Swap(&array[j + 1], &array[j]);
                noSwap = 0;
            } 
        }
        if (noSwap == 1) return;
    }
}


void QuickSort(int* array, size_t b, size_t e){
    int left = b, right = e;
    int pivot = array[(left+right)/2];
    while (left <= right){
        while (array[left] < pivot) left++;
        while (array[right] > pivot) right--;
        if (left <= right) Swap(&array[left++], &array[right--]);
    }
    if (b < right) QuickSort(array, b, right);
    if (e > left) QuickSort(array, left, e);
}

int comp (const int *, const int *);

int main(){
    size_t size = 10;
    int* array = malloc(sizeof(int) * 10);
    GenerateArray(array, size);
    // QuickSort(array, 0, size - 1);
    qsort(array, size, sizeof(int), (int (*) (const void *, const void *)) comp);
    for (size_t i = 0; i < size; i++){
        printf("%d\n", array[i]);
    }
    return 0;
}


int comp (const int *i, const int *j){
    return *i - *j;
}