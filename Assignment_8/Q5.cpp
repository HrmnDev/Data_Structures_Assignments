#include <iostream>
using namespace std;

// --- heapify for max-heap (used by increasing-order heapsort) ---
void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    while (true) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[largest]) largest = l;
        if (r < n && arr[r] > arr[largest]) largest = r;

        if (largest == i) break;
        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;
        i = largest;
    }
}

// --- heapify for min-heap (used by decreasing-order heapsort) ---
void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    while (true) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] < arr[smallest]) smallest = l;
        if (r < n && arr[r] < arr[smallest]) smallest = r;

        if (smallest == i) break;
        int tmp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = tmp;
        i = smallest;
    }
}

// --- Heapsort that produces increasing order (uses max-heap) ---
void heapSortIncreasing(int arr[], int n) {
    if (n <= 1) return;
    // Build max-heap
    for (int i = n / 2 - 1; i >= 0; --i)
        heapifyMax(arr, n, i);
    // Extract one by one
    for (int i = n - 1; i > 0; --i) {
        // move current root (largest) to end
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        // heapify reduced heap
        heapifyMax(arr, i, 0);
    }
}

// --- Heapsort that produces decreasing order (uses min-heap) ---
void heapSortDecreasing(int arr[], int n) {
    if (n <= 1) return;
    // Build min-heap
    for (int i = n / 2 - 1; i >= 0; --i)
        heapifyMin(arr, n, i);
    // Extract one by one
    for (int i = n - 1; i > 0; --i) {
        // move current root (smallest) to end
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        // heapify reduced heap
        heapifyMin(arr, i, 0);
    }
}

// --- utility to print an array ---
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << arr[i];
    }
    cout << '\n';
}

int main() {
    int a1[] = {12, 3, 5, 7, 19, -1, 0, 2};
    const int n = sizeof(a1) / sizeof(a1[0]);

    // Increasing order
    int b[n];
    for (int i = 0; i < n; ++i) b[i] = a1[i];
    heapSortIncreasing(b, n);
    cout << "Heapsort (Increasing): ";
    printArray(b, n);

    // Decreasing order
    int c[n];
    for (int i = 0; i < n; ++i) c[i] = a1[i];
    heapSortDecreasing(c, n);
    cout << "Heapsort (Decreasing): ";
    printArray(c, n);

    return 0;
}
