//      n*m
//TC: 4^
//SC: m*n

class Solution{
public:
    vector<vector<bool>> visited;
    vector<string> ansarr;
    
    bool issafe(int newx, int newy, vector<vector<int>> &m, int n){
        if(newx >= 0 && newx < n && newy >= 0 && newy < n && 
           !visited[newx][newy] && m[newx][newy] == 1){
            return true;
        }
        return false;
    }
    
    void helper(int x, int y, string tempans, vector<vector<int>> &m, int n){
        if(x == n-1 && y == n-1){
            ansarr.push_back(tempans);
            return;
        }
        
        // down
        if(issafe(x + 1, y, m, n)){
            visited[x + 1][y] = true;
            helper(x + 1, y, tempans + "D", m, n);
            visited[x + 1][y] = false;
        }
        // right
        if(issafe(x, y + 1, m, n)){
            visited[x][y + 1] = true;
            helper(x, y + 1, tempans + "R", m, n);
            visited[x][y + 1] = false;
        }
        // left
        if(issafe(x, y - 1, m, n)){
            visited[x][y - 1] = true;
            helper(x, y - 1, tempans + "L", m, n);
            visited[x][y - 1] = false;
        }
        // up
        if(issafe(x - 1, y, m, n)){
            visited[x - 1][y] = true;
            helper(x - 1, y, tempans + "U", m, n);
            visited[x - 1][y] = false;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        ansarr.clear();                             //<---- this two streps are very imp
        visited.assign(n, vector<bool>(n, false));  //<----
        
        if(m[0][0] == 0) return ansarr;  // If the start point is blocked
        
        int x = 0, y = 0;
        string tempans = "";
        visited[0][0] = true;
        helper(x, y, tempans, m, n);
        return ansarr;
    }
};