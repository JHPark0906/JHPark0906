#include <stdio.h>

#define MAX 5000

typedef struct queue {
    int arr[MAX];
    int start, elem;
} queue;

queue queue1;

void josephus(int n, int k);
void push(int n);
int pop();

int main(void) {
    queue1.start = 0; queue1.elem = 0;
    int n, k;
    scanf("%d%d", &n, &k);
    josephus(n, k);
    return 0;
}

void josephus(int n, int k) {
    int tmp;
    for (int i = 1; i <= n; i++) {
        push(i);
    }
    printf("<");
    while (queue1.elem) {
        for (int i = 0; i < k; i++) {
            tmp = pop();
            if (i != k - 1) {
                push(tmp);
            } else {
                printf("%d", tmp);
                if (queue1.elem) {
                    printf(", ");
                } else {
                    printf(">");
                    return;
                }
            }
        }
    }
}

void push(int n) {
    queue1.arr[(queue1.start + queue1.elem++) % MAX] = n;
}

int pop() {
    if (queue1.elem) {
        int n = queue1.arr[queue1.start];
        queue1.start = (queue1.start + 1) % MAX;
        queue1.elem--;
        return n;
    }
    return -1;
}