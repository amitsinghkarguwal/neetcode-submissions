/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }

private:
    Node* build(const vector<vector<int>>& grid, int r, int c, int length) {
        bool allSame = true;
        int firstVal = grid[r][c];

        for (int i = r; i < r + length; i++) {
            for (int j = c; j < c + length; j++) {
                if (grid[i][j] != firstVal) {
                    allSame = false;
                    break;
                }
            }
            if (!allSame) break; // Early exit optimization
        }
        
        if (allSame) {
            return new Node(firstVal == 1, true);
        }

        int half = length / 2;
        return new Node(
            false,  // val can be anything for an internal node, typically false
            false,  // isLeaf is false
            build(grid, r, c, half),                 // Top Left
            build(grid, r, c + half, half),          // Top Right
            build(grid, r + half, c, half),          // Bottom Left
            build(grid, r + half, c + half, half)    // Bottom Right
        );
    }
};