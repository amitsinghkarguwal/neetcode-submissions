#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

// Standard Disjoint Set Union (Union-Find) class
class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); // Fills 0, 1, 2, ..., n-1
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
            parent[rootY] = rootX;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);
        
        // Maps an email to the index of the first account it belongs to
        unordered_map<string, int> emailToIndex;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                
                // If we've seen this email before, union the current account
                // with the account that previously contained this email.
                if (emailToIndex.count(email)) {
                    uf.unite(i, emailToIndex[email]);
                } else {
                    emailToIndex[email] = i;
                }
            }
        }
        
        // Group emails by their root parent account index
        unordered_map<int, vector<string>> mergedAccounts;
        for (auto& [email, idx] : emailToIndex) {
            int root = uf.find(idx);
            mergedAccounts[root].push_back(email);
        }
        
        // Format the result
        vector<vector<string>> result;
        for (auto& [rootIndex, emails] : mergedAccounts) {
            sort(emails.begin(), emails.end());
            
            // Reconstruct the account: Name followed by sorted emails
            vector<string> account;
            account.push_back(accounts[rootIndex][0]); // The name
            account.insert(account.end(), emails.begin(), emails.end());
            
            result.push_back(account);
        }
        
        return result;
    }
};