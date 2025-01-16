#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} MaxHeap;


MaxHeap* createHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->arr = (int*)malloc(capacity * sizeof(int));
    return heap;
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(MaxHeap* heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left] > heap->arr[largest])
        largest = left;

    if (right < heap->size && heap->arr[right] > heap->arr[largest])
        largest = right;

    if (largest != i) {
        swap(&heap->arr[i], &heap->arr[largest]);
        heapify(heap, largest);
    }
}


void insert(MaxHeap* heap, int key) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->arr[i] = key;

    while (i != 0 && heap->arr[(i - 1) / 2] < heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


int extractMax(MaxHeap* heap) {
    if (heap->size <= 0)
        return -1;
    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}


void delete(MaxHeap* heap, int i) {
    heap->arr[i] = heap->arr[heap->size - 1];
    heap->size--;
    heapify(heap, i);
}


void printHeap(MaxHeap* heap) {
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->arr[i]);
    printf("\n");
}

int main() {
    MaxHeap* heap = createHeap(10);

    insert(heap, 3);
    insert(heap, 2);
    insert(heap, 15);
    insert(heap, 5);
    insert(heap, 4);
    insert(heap, 45);

    printf("Max Heap array: ");
    printHeap(heap);

    printf("Extracted max: %d\n", extractMax(heap));
    printf("Heap after extraction: ");
    printHeap(heap);

    delete(heap, 1);
    printf("Heap after deletion: ");
    printHeap(heap);

    return 0;
}