#include <vector>

using namespace std;

// Standard Disjoint Set Union (Union-Find) class
class UnionFind {
private:
    vector<int> parent;
    vector<int> size;
    int components;

public:
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        components = n;
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            // Union by size
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            components--;
        }
    }
    
    int getComponents() {
        return components;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        
        UnionFind uf(n);
        
        // Max value in nums is 100,000 according to problem constraints.
        // We use an array instead of a hash map for faster lookups.
        // Maps a prime number to the index in 'nums' where it was first seen.
        vector<int> primeToIndex(100005, -1);
        
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            
            // The number 1 shares no prime factors > 1 with any other number.
            // If the array has more than 1 element, this permanently isolates it.
            if (val == 1) return false;
            
            // Find all prime factors of 'val'
            for (int d = 2; d * d <= val; ++d) {
                if (val % d == 0) {
                    // If we've seen this prime factor before, unite the indices
                    if (primeToIndex[d] != -1) {
                        uf.unite(i, primeToIndex[d]);
                    } else {
                        // Otherwise, record that we saw this prime at index 'i'
                        primeToIndex[d] = i;
                    }
                    
                    // Divide out this prime factor completely
                    while (val % d == 0) {
                        val /= d;
                    }
                }
            }
            
            // If 'val' is still > 1, it means the remaining value is a prime itself
            if (val > 1) {
                if (primeToIndex[val] != -1) {
                    uf.unite(i, primeToIndex[val]);
                } else {
                    primeToIndex[val] = i;
                }
            }
        }
        
        // If everything is connected, we should have exactly 1 component remaining
        return uf.getComponents() == 1;
    }
};