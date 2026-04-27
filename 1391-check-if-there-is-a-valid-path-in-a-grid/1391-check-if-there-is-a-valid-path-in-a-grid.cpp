class Solution {
public:
    // directions: up, down, left, right
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    
    // valid connections for each street type
    unordered_map<int, vector<int>> mp = {
        {1, {2,3}},      // left-right
        {2, {0,1}},      // up-down
        {3, {2,1}},      // left-down
        {4, {3,1}},      // right-down
        {5, {2,0}},      // left-up
        {6, {3,0}}       // right-up
    };

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m,false));
        queue<pair<int,int>> q;

        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();

            if(x == n-1 && y == m-1) return true;

            int type = grid[x][y];

            for(int d : mp[type]){
                int nx = x + dirs[d][0];
                int ny = y + dirs[d][1];

                if(nx<0 || ny<0 || nx>=n || ny>=m || vis[nx][ny]) continue;

                int nextType = grid[nx][ny];

                // check reverse connection
                for(int rev : mp[nextType]){
                    if(nx + dirs[rev][0] == x && ny + dirs[rev][1] == y){
                        vis[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
        }

        return false;
    }
};