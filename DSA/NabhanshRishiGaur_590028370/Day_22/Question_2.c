#include <stdio.h>

int main() {
    int cards[100] = {4, 1, 2, 10};
    int n = 4;
    int p1 = 0, p2 = 0;
    int turn = 0;

    while (n > 0) {
        int picked;

        if (cards[0] >= cards[n - 1]) {
            picked = cards[0];

            for (int i = 0; i < n - 1; i++)
                cards[i] = cards[i + 1];
        } else {
            picked = cards[n - 1];
        }

        n--;

        if (turn == 0)
            p1 += picked;
        else
            p2 += picked;

        turn = 1 - turn;
    }

    printf("%d %d\n", p1, p2);

    return 0;
}
