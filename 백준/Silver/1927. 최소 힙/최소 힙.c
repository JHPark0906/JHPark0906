#include <stdio.h>

#define MAX 100000

int heap[MAX], size = 0;

int pop();
void push(int num);
void make_heap(int parent);
void swap(int a, int b);

int main(void)
{
    int iteration, command;
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        scanf("%d", &command);
        if (command == 0)
            printf("%d\n", pop());
        else
            push(command);
        make_heap(0);
    }
    return 0;
}

int pop()
{
    if (size == 0)
        return 0;
    int result = heap[0];
    size--;
    swap(0, size);
    make_heap(0);
    return result;
}

void push(int num)
{
    heap[size++] = num;
    int i = size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[i] >= heap[parent])
            break;
        swap(i, parent);
        i = parent;
    }
}

void make_heap(int parent)
{
    int left_child = parent * 2 + 1;
    int right_child = parent * 2 + 2;

    int smallest = parent;
    if (left_child < size && heap[left_child] < heap[smallest])
        smallest = left_child;
    if (right_child < size && heap[right_child] < heap[smallest])
        smallest = right_child;

    if (smallest != parent) {
        swap(parent, smallest);
        make_heap(smallest);
    }
}

void swap(int a, int b) {
    int tmp = heap[a];
    heap[a] = heap[b];
    heap[b] = tmp;
}