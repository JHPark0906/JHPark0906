#include <stdio.h>
#include <stdlib.h>

// Increasing order.
int comp(const void *elem1, const void *elem2);

// Returns the number of cards.
int findCards(int cards[], int len, int num);

// Returns first index.
int getFirstIndex(int cards[], int first, int last, int num);

// Returns last index.
int getLastIndex(int cards[], int first, int last, int num);

int main(void) {
    // Receive input values.
    int input, search;
    scanf("%d", &input);
    int *cards = (int *)malloc(sizeof(int) * input);
    for (int i = 0; i < input; i++) scanf("%d", &cards[i]);
    scanf("%d", &search);
    int *searches = (int *)malloc(sizeof(int) * search);
    for (int i = 0; i< search; i++) scanf("%d", &searches[i]);

    // Sort cards.
    qsort(cards, input, sizeof(int), comp);

    // Print results.
    for (int i = 0; i < search; i++) printf("%d ", findCards(cards, input, searches[i]));

    // Memory free.
    free(cards);
    free(searches);
    return 0;
}

int comp(const void *elem1, const void *elem2) {
    // Increasing order.
    return *(int *)elem1 - *(int *)elem2;
}

int findCards(int cards[], int len, int num) {
    int first = 0, last = len - 1, idx, tmpFirst, tmpLast, cnt = 0;
    idx = (first + last) / 2;

    // Find the range of num.
    while (cards[idx] != num) {
        if (cards[idx] > num) last = idx - 1;
        else first = idx + 1;
        if (first > last) return 0;
        else if (first == last) {
            if (cards[first] == num) break;
            else return 0;
        }
        idx = (first + last) / 2;
    }

    // Returns result.
    return getLastIndex(cards, first, last, num) - getFirstIndex(cards, first, last, num) + 1;
}

int getFirstIndex(int cards[], int first, int last, int num) {
    int idx = (first + last) / 2;
    while (first <= last) {
        if (cards[idx] < num) {
            first = idx + 1;
        } else {
            last = idx - 1;
        }
        idx = (first + last) / 2;
    }
    if (cards[idx] != num) return idx + 1;
    return idx;
}

int getLastIndex(int cards[], int first, int last, int num) {
    int idx = (first + last) / 2;
    while (first <= last) {
        if (cards[idx] > num) {
            last = idx - 1;
        } else {
            first = idx + 1;
        }
        idx = (first + last) / 2;
    }
    if (cards[idx] != num) return idx - 1;
    return idx;
}