#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, i;
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);
    int arr[n];
    printf("Masukkan %d angka:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array sebelum disorting: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Array setelah Selection Sort: ");
    printArray(arr, n);
    return 0;
}

