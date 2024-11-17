#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    // Fast input/output
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    int N, M;
    cin >> N >> M;  // N = number of people, M = number of events

    // Probability vector: prob[i] represents the probability of the state 'i' (a bitmask)
    vector<double> prob(1 << N, 0), nextProb;
    prob[0] = 1;  // Initially, no one is dead

    // Processing each event
    for (int i = 0; i < M; ++i) {
        int a, b;
        double p;
        cin >> a >> b >> p;
        --a, --b;  // Adjust to zero-indexing
        
        nextProb.assign(1 << N, 0);  // Reset nextProb for this event

        // Update probabilities for each state (bitmask)
        for (int bitmask = 0; bitmask < (1 << N); ++bitmask) {
            if (bitmask & ((1 << a) | (1 << b))) {
                // Either 'a' or 'b' is dead, so no change in the state
                nextProb[bitmask] += prob[bitmask];
            } else {
                // Update the state when 'b' dies, or remains unchanged
                nextProb[bitmask | (1 << b)] += prob[bitmask] * p;
                nextProb[bitmask] += prob[bitmask] * (1 - p);
            }
        }
        
        // Swap current and next probabilities
        swap(nextProb, prob);
    }

    // Calculate the probability that each person is still alive
    vector<double> deadProbability(N, 0.0);
    for (int bitmask = 0; bitmask < (1 << N); ++bitmask) {
        for (int i = 0; i < N; ++i) {
            if (bitmask & (1 << i)) {
                // Person 'i' is dead in this bitmask, add the corresponding probability
                deadProbability[i] += prob[bitmask];
            }
        }
    }

    // Output the probability that each person is still alive
    for (int i = 0; i < N; ++i) {
        cout << fixed << setprecision(10) << 1 - deadProbability[i] << endl;
    }

    return 0;
}
