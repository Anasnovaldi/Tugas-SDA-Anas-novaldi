#include <stdio.h>

void printArray(int arr[], int size, int step) {
    int i;
    printf("Langkah %d: ", step);
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx, step = 1, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
        printArray(arr, n, step++);
    }
}

int main() {
    int n, i;
    int arr[100];

    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Masukkan angka ke-%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array awal: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    selectionSort(arr, n);

    printf("Array terurut: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}

