#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

inline int fast_input() {
    int x = 0;
    char c;
    
    // Skip non-numeric characters
    while ((c = getchar()) < '0' || c > '9');
    
    // Now process the number
    do {
        x = x * 10 + (c - '0');
    } while ((c = getchar()) >= '0' && c <= '9');

    return x;
}

inline void fast_output_progress(int p, int w) {
    putchar('[');

    int pw = (p * w) / 100;

    for (int i = 0; i < pw; ++i) {
        putchar('#');
    }

    for (int i = pw; i < w; ++i) {
        putchar('-');
    }

    putchar(']');
    putchar(' ');
    putchar('|');
    putchar(' ');

    if (p < 10) {
        putchar(' ');
        putchar(' ');
        putchar('0' + p);
        putchar('%');
    } else if (p < 100) {
        putchar(' ');
        putchar('0' + (p / 10));
        putchar('0' + (p % 10));
        putchar('%');
    } else {
        putchar('1');
        putchar('0');
        putchar('0');
        putchar('%');
    }

    putchar('\n');
}

int main() {
    FAST_IO;

    int p = fast_input();
    int w = fast_input();

    fast_output_progress(p, w);

    return 0;
}
