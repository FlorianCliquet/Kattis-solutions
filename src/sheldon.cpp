#include <bits/stdc++.h>

using namespace std;

set<unsigned long long> ar;

void generate(){
    int i,j,k,l,a,b,T[75];
    for(a = 1; a <= 63; a++){
        for(b = 0; (a+b) <= 63; b++){
            l = 0;
            for(int i = 0;i < a;i++)T[l++] = 1;
            for(int i = 0;i < b;i++)T[l++] = 0;
            for(k = 1; k <= 63; k++){
                if((k%l) == 0 || (k % l) == a){
                    unsigned long long x = 0;
                    for(i = 0; i < k; i++) x = (x*2) + T[i%l];
                    ar.insert(x);
                }
            }
        }
    }
}

int main(){
    generate();
    unsigned long long a,b,res;
    while(scanf("%llu %llu",&a,&b) == 2){
        res = 0;
        for(auto x : ar){
            if(x >= a && x <= b) res++;
        }
        printf("%llu\n",res);
    }
    return 0;
}