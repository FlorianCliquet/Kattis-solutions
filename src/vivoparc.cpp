#include <bits/stdc++.h>
#define MAX 100
int N, solution[MAX]; 
bool edge[MAX*MAX];

bool vivopark(int p) {
    if (p == N) return true;
    for (int animal = 1; animal <= 4; animal++) {
        bool possible = true;
        for (int i = 0; i < p; i++)
            if (edge[p * N + i] && solution[i] == animal) {
                possible = false;
                break;
            }
        if (possible) {
            solution[p] = animal;
            if (vivopark(p + 1)) return true;
        }
    }
    return false;
}

int main() {
    int a, b;
    scanf("%d", &N);
    memset(edge, 0, N * N * sizeof(bool));
    while (scanf("%d-%d", &a, &b) == 2)
        edge[(a - 1) * N + b - 1] = edge[(b - 1) * N + a - 1] = true;
    if (vivopark(0))
        for (int i = 0; i < N; i++) printf("%d %d\n", i + 1, solution[i]);
    else
        printf("Impossible assignation\n");
}
