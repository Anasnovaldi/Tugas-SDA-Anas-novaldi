#include <stdio.h>

void printArray(int arr[], int size, const char *msg) {
    int i;
    printf("%s: ", msg);
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int l, int m, int r, int size) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[100], R[100];
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    printArray(arr, size, "Setelah merge");
}

void mergeSort(int arr[], int l, int r, int size) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, size);
        mergeSort(arr, m + 1, r, size);
        merge(arr, l, m, r, size);
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
    mergeSort(arr, 0, n - 1, n);
    printArray(arr, n, "Array terurut");
    return 0;
}

