#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare card values
int compare(const void *a, const void *b) {
    char cardA = *(char *)a;
    char cardB = *(char *)b;
    char order[] = "123456789JQK";

    int indexA = strchr(order, cardA) - order;
    int indexB = strchr(order, cardB) - order;

    return indexA - indexB;
}

// Function to perform selection sort and display exchanges
int sortCards(int n, char cards[]) {
    int steps = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (compare(&cards[j], &cards[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            char temp = cards[i];
            cards[i] = cards[minIndex];
            cards[minIndex] = temp;
            steps++;
            // Display the exchange
            printf("Pertukaran %d: ", steps);
            for (int k = 0; k < n; k++) {
                printf("%c ", cards[k]);
            }
            printf("\n");
        }
    }
    return steps;
}

int main() {
    int n;
    printf("Masukkan jumlah kartu: ");
    scanf("%d", &n);

    char cards[n];
    printf("Masukkan nilai kartu (1-10, J, Q, K dipisahkan dengan spasi): ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &cards[i]);
    }

    int steps = sortCards(n, cards);

    printf("\nJumlah langkah untuk menyortir kartu: %d\n", steps);
    printf("Urutan kartu setelah disortir: ");
    for (int i = 0; i < n; i++) {
        printf("%c ", cards[i]);
    }
    printf("\n");

    return 0;
}
