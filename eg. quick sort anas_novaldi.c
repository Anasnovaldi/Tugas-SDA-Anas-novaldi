#include <stdio.h>

void printArray(int arr[], int size, const char *msg) {
    int i;
    printf("%s: ", msg);
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high, int size) {
    int pivot = arr[high];
    int i = low - 1;
    int j;
    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    printArray(arr, size, "Setelah partisi");
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int size) {
    if (low < high) {
        int pi = partition(arr, low, high, size);
        quickSort(arr, low, pi - 1, size);
        quickSort(arr, pi + 1, high, size);
    }
}

int main() {
    int arr[100], n, i;

    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Masukkan angka ke-%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printArray(arr, n, "Array awal");
    quickSort(arr, 0, n - 1, n);
    printArray(arr, n, "Array terurut");
    return 0;
}

