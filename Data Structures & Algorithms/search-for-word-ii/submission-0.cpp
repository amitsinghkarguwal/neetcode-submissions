#include <vector>
#include <string>

using namespace std;

// Step 1: Define the Trie Node
class TrieNode {
public:
    TrieNode* children[26];
    string word; // Stores the complete word at the leaf node
    
    TrieNode() {
        word = "";
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Solution {
private:
    TrieNode* root;
    vector<string> result;
    
    // Helper function to build the Trie from the dictionary
    void buildTrie(const vector<string>& words) {
        root = new TrieNode();
        for (const string& word : words) {
            TrieNode* curr = root;
            for (char c : word) {
                int index = c - 'a';
                if (curr->children[index] == nullptr) {
                    curr->children[index] = new TrieNode();
                }
                curr = curr->children[index];
            }
            curr->word = word; // Store the word at the end of the path
        }
    }
    
    // DFS Backtracking algorithm
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* curr) {
        // Bounds check and visited check
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#') {
            return;
        }
        
        char c = board[i][j];
        int index = c - 'a';
        
        // If there is no dictionary word starting with this path, abort instantly!
        if (curr->children[index] == nullptr) {
            return;
        }
        
        // Move the Trie pointer down
        curr = curr->children[index];
        
        // Did we find a complete word?
        if (curr->word != "") {
            result.push_back(curr->word);
            curr->word = ""; // Remove the word to avoid duplicate discoveries
        }
        
        // Mark the current cell as visited
        board[i][j] = '#';
        
        // Explore all 4 directions
        dfs(board, i + 1, j, curr); // Down
        dfs(board, i - 1, j, curr); // Up
        dfs(board, i, j + 1, curr); // Right
        dfs(board, i, j - 1, curr); // Left
        
        // Backtrack: Restore the original character
        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        buildTrie(words);
        
        int m = board.size();
        int n = board[0].size();
        
        // Start a simultaneous Trie-DFS sweep from every single cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }
        
        return result;
    }
};