#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

struct State {
    int x, y, turns;
};
vector<string> road;
deque<State> q;
int width, height, maxTurns;
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {0, 0}};
/**
 * moves[0] = left, moves[1] = right, moves[2] = up, moves[3] = down, moves[4] = stay
 */
bool visited[51][22][51];
/**
 * numbers of lanes : 1 <= n <= 20
 * length of each lane : 1 <= m <= 50
 * each string is max m characters long
 * bool visited[lanes][length][string.length()]
 */

inline bool carPresent(int x, int y, int turns){
    // Calculate offset based on the distance and the row (y)
    int offset = (y % 2 == 1) ? width - (turns % width) : (turns % width);
    /**
     * offset calculation:
     * if y is odd, the car moves from right to left -> offset = width - (turns % width)
     * if y is even, the car moves from left to right -> offset = turns % width
     */

    /**
     * Check if the car is present at the given position, adjust the x position based on the offset
     */
    return road[height + 1 - y][(x + offset) % width] == 'X';
}

inline void tryState(int x, int y, int turns){
    // Check if the state is within bounds, not visited, and no car is present
    if(x >= 0 && x < width && y >= 0 && y <= height + 1 && turns <= maxTurns && !visited[x][y][turns % width] && !carPresent(x, y, turns)){
        visited[x][y][turns % width] = true;
        q.push_back({x, y, turns});
    }
}

int BFS(){
    // Initialize visited array and queue
    memset(visited, 0, sizeof(visited));
    q.clear();

    // Find the start and goal positions
    int startX = road[height + 1].find('F');
    int goalX = road[0].find('G');

    // Add the starting position to the queue
    q.push_back({startX, 0, 0});
    visited[startX][0][0] = true;

    // Iterate through the queue
    while(!q.empty()){
        // Get the front element and pop it
        State s = q.front();
        q.pop_front();

        // If the goal is reached, return the turns taken
        if(s.x == goalX && s.y == height + 1) return s.turns;

        // Explore possible moves
        int nextTurns = s.turns + 1;
        for(auto move : moves)tryState(s.x + move.first, s.y + move.second, nextTurns);
    }
    return -1; // No solution found
}
int main(){
    FAST_IO;
    int n; cin >> n; // Read the number of test cases
    road.reserve(22); // 20 lanes + 1 start + 1 goal
    string s;
    while(n--){
        road.clear(); // clear the road for each test case
        cin >> maxTurns >> height >> width; // Read the width, height, and maxTurns
        for(int i = 0; i < height + 2; i++){cin >> s; road.push_back(s);} // Populate the road with the lanes
        int minTurns = BFS();
        if(minTurns >= 0) cout << "The minimum number of turns is " << minTurns << ".\n";
        else cout << "The problem has no solution.\n";
    }
    return 0;
}