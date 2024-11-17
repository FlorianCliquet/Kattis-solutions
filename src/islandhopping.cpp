#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

struct Edge {
    int u, v;
    double weight;
    Edge(int u, int v, double weight) : u(u), v(v), weight(weight) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct Point {
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
};

// Function to calculate Euclidean distance between two points
double calculateDistance(const Point& a, const Point& b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Disjoint Set Union-Find with path compression and union by rank
class UnionFind {
public:
    std::vector<int> parent, rank;
    
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);  // path compression
        }
        return parent[u];
    }
    
    bool unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            // union by rank
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            return true;
        }
        return false;
    }
};

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        
        std::vector<Point> islands;
        for (int i = 0; i < n; i++) {
            double x, y;
            std::cin >> x >> y;
            islands.emplace_back(x, y);
        }
        
        std::vector<Edge> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dist = calculateDistance(islands[i], islands[j]);
                edges.emplace_back(i, j, dist);
            }
        }
        
        // Sort all edges by weight
        std::sort(edges.begin(), edges.end());
        
        // Kruskal's algorithm to find MST
        UnionFind uf(n);
        double totalLength = 0.0;
        for (const auto& edge : edges) {
            if (uf.unionSets(edge.u, edge.v)) {
                totalLength += edge.weight;
            }
        }
        
        // Output result with precision
        std::cout << std::fixed << std::setprecision(9) << totalLength << std::endl;
    }
    
    return 0;
}
