#include <vector>
#include <cmath>

using namespace std;

class CountSquares {
private:
    // 2D array to store the frequency of each point.
    // Sized 1005x1005 to safely cover coordinates from 0 to 1000.
    int pointCounts[1005][1005] = {0};
    
    // A list to iterate through all points we've ever added
    vector<pair<int, int>> points;

public:
    CountSquares() {
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        
        pointCounts[x][y]++;
        points.push_back({x, y}); // Save for diagonal iteration
    }
    
    int count(vector<int> point) {
        int qx = point[0];
        int qy = point[1];
        int totalSquares = 0;
        
        // Iterate over all added points to act as the diagonal opposite
        for (auto& p : points) {
            int px = p.first;
            int py = p.second;
            
            // 1. Must not be a point on the same x or y axis (area must be > 0)
            // 2. Must form a perfect square diagonal: width == height
            if (px == qx || py == qy || abs(qx - px) != abs(qy - py)) {
                continue;
            }
            
            // The two implied corners are (qx, py) and (px, qy).
            // Multiply their frequencies. (Notice we don't multiply by pointCounts[px][py] 
            // because our loop is physically looking at one instance of the diagonal point at a time).
            totalSquares += pointCounts[qx][py] * pointCounts[px][qy];
        }
        
        return totalSquares;
    }
};