#include <bits/stdc++.h>
using namespace std;

int main(){
    string input;
    getline(cin,input);
    int total_vowels = count(input.begin(), input.end(), 'a') + 
                       count(input.begin(), input.end(), 'A') + 
                       count(input.begin(), input.end(), 'e') + 
                       count(input.begin(), input.end(), 'E') + 
                       count(input.begin(), input.end(), 'i') + 
                       count(input.begin(), input.end(), 'I') + 
                       count(input.begin(), input.end(), 'o') + 
                       count(input.begin(), input.end(), 'O') + 
                       count(input.begin(), input.end(), 'u') + 
                       count(input.begin(), input.end(), 'U');
    cout << total_vowels << endl; 
    return 0;
}
