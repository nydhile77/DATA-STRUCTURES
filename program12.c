#include <stdio.h>

#define MAX 20

int ht[MAX];
int m;

/* Hash Function */
int hash(int key) {
    return key % m;
}

int main() {
    int n, key, index, i;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    /* Initialize hash table */
    for (i = 0; i < m; i++)
        ht[i] = -1;

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter 4-digit employee key: ");
        scanf("%d", &key);

        index = hash(key);

        /* Linear Probing for collision resolution */
        while (ht[index] != -1) {
            index = (index + 1) % m;
        }

        ht[index] = key;
    }

    /* Display Hash Table */
    printf("\nHash Table Contents:\n");
    printf("Address\tKey\n");
    for (i = 0; i < m; i++) {
        if (ht[i] != -1)
            printf("%d\t%d\n", i, ht[i]);
        else
            printf("%d\t--\n", i);
    }

    return 0;
}
