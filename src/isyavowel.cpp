#include <bits/stdc++.h>
using namespace std;

int main(){
    string input;
    cin >> input;
    int total_vowels = count(input.begin(), input.end(), 'a') + 
                       count(input.begin(), input.end(), 'e') + 
                       count(input.begin(), input.end(), 'i') + 
                       count(input.begin(), input.end(), 'o') + 
                       count(input.begin(), input.end(), 'u');
    cout << total_vowels << " "<< total_vowels + count(input.begin(),input.end(), 'y') << endl; 
    return 0;
}
