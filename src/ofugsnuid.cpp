#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

const int MAX_BUFFER = 1 << 20;  // 1 MB buffer for input
char input_buffer[MAX_BUFFER];
int input_pos = 0, input_len = 0;

// Fast buffered getchar-like input
inline char get_char() {
    if (input_pos == input_len) {
        input_pos = 0;
        input_len = fread(input_buffer, 1, MAX_BUFFER, stdin);
        if (input_len == 0) return EOF;  // End of input
    }
    return input_buffer[input_pos++];
}

// Fast integer reading
inline int fast_input() {
    int x = 0;
    char c;
    
    // Skip non-numeric characters
    while ((c = get_char()) < '0' || c > '9');
    
    // Now process the number
    do {
        x = x * 10 + (c - '0');
    } while ((c = get_char()) >= '0' && c <= '9');

    return x;
}

char output_buffer[MAX_BUFFER];
int output_pos = 0;

// Fast buffered putchar-like output
inline void put_char(char c) {
    if (output_pos == MAX_BUFFER) {
        fwrite(output_buffer, 1, output_pos, stdout);
        output_pos = 0;
    }
    output_buffer[output_pos++] = c;
}

// Fast integer output
inline void fast_output(int x) {
    if (x == 0) {
        put_char('0');
    } else {
        char buffer[10];  // Enough to store any int
        int len = 0;
        while (x > 0) {
            buffer[len++] = '0' + (x % 10);
            x /= 10;
        }
        for (int i = len - 1; i >= 0; --i) {
            put_char(buffer[i]);
        }
    }
    put_char('\n');
}

int main() {
    FAST_IO;
    
    int t = fast_input();
    int arr[t];

    for (int i = t - 1; i >= 0; --i) {
        arr[i] = fast_input();
    }

    for (int i = 0; i < t; ++i) {
        fast_output(arr[i]);
    }

    if (output_pos > 0) {
        fwrite(output_buffer, 1, output_pos, stdout);
    }

    return 0;
}
