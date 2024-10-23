#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Pairs(vector<int> &arr, int target) {
    vector<vector<int>> res;
      int n = arr.size();
      
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {

        int complement = target - arr[i];
        if(complement == arr[i])res.push_back({arr[i], arr[i]});
        if (complement == arr[i]) {
            if (freq[complement] == 1) 
                res.push_back({arr[i], arr[i]});
        }
          else if (freq[complement] > 0 && freq[arr[i]] == 0) {
            int first = min(arr[i], complement);
            int second = max(arr[i], complement);
            res.push_back({first, second});
        }
      
        freq[arr[i]]++;
    }
    sort(res.begin(), res.end());
      return res;
}

vector<int> process_prime(int tmp){
    // Sieve of Eratosthenes
    vector<bool> isPrime(tmp + 1, true);
    vector<int> ans;
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= tmp; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= tmp; i += p)
                isPrime[i] = false;

        }
    }
   for (int p = 2; p <= tmp; p++) {
        if (isPrime[p]) {
            ans.push_back(p);
        }
    }
    return ans;
}
int main(){
    int n,tmp; cin >> n;
    while(n--){
        cin >> tmp;
        vector<int> primeLessThanTmp = process_prime(tmp);
        vector<vector<int>> res = Pairs(primeLessThanTmp, tmp);
        int size = res.size();
        cout << tmp << " has " << size << " representation(s)" << "\n";
        for(const auto &v : res){
            cout << v[0] << "+" << v[1] << "\n";
        }
        cout << "\n";
    }
    return 0;
}