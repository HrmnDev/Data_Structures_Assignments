#include <iostream>
using namespace std;

//HEAPIFY FUNCTION
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left  = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapify(arr, n, largest);
    }
}

//HEAP SORT (INCREASING)
void heapSortIncreasing(int arr[], int n) {
    // Build max-heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements
    for (int i = n-1; i >= 0; i--) {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;

        heapify(arr, i, 0);
    }
}

//HEAP SORT (DECREASING)
void heapSortDecreasing(int arr[], int n) {
    heapSortIncreasing(arr, n);

    // Reverse array manually (no algorithm)
    for (int i = 0; i < n/2; i++) {
        int t = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = t;
    }
}

//PRIORITY QUEUE(MAX HEAP)
class PriorityQueue {
public:
    int arr[100];
    int size;

    PriorityQueue() {
        size = 0;
    }

    void push(int x) {
        arr[size] = x;
        int i = size;
        size++;

        // Sift-up
        while (i > 0) {
            int parent = (i-1)/2;
            if (arr[parent] < arr[i]) {
                int t = arr[parent];
                arr[parent] = arr[i];
                arr[i] = t;
                i = parent;
            } else break;
        }
    }

    int top() {
        if (size == 0) return -1;
        return arr[0];
    }

    void pop() {
        if (size == 0) return;

        arr[0] = arr[size-1];
        size--;

        // Sift-down
        int i = 0;
        while (true) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int largest = i;

            if (left < size && arr[left] > arr[largest])
                largest = left;
            if (right < size && arr[right] > arr[largest])
                largest = right;

            if (largest != i) {
                int t = arr[i];
                arr[i] = arr[largest];
                arr[largest] = t;
                i = largest;
            } else break;
        }
    }

    bool empty() {
        return size == 0;
    }
};


//MAIN
int main() {
    int arr[8] = {12, 3, 5, 7, 19, -1, 0, 2};
    int n = 8;

    cout << "Heapsort Increasing: ";
    heapSortIncreasing(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    int arr2[8] = {12, 3, 5, 7, 19, -1, 0, 2};
    cout << "Heapsort Decreasing: ";
    heapSortDecreasing(arr2, n);
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << "\n\n";

    cout << "Priority Queue (Max-Heap): ";
    PriorityQueue pq;
    pq.push(5);
    pq.push(1);
    pq.push(7);
    pq.push(3);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
