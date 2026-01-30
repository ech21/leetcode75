class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(), cols = maze[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;

        int sx = entrance[0], sy = entrance[1];
        dist[sx][sy] = 0;
        q.push({sx, sy});

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (!(x == sx && y == sy) &&
                (x == 0 || y == 0 || x == rows - 1 || y == cols - 1))
                return dist[x][y];

            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (0 <= nx && nx < rows && 0 <= ny && ny < cols &&
                    maze[nx][ny] == '.' && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return -1;
    }
};
/*
Iterative BFS that incoudes a distance vector, where 
distance[x][y] = -1 if x, y is unvisited, otherwise it's the distance from entrance.  
Directions are put in a vector to simplify the code and turn it into a for loop. 

Where r = row count, c = col count
Time complexity:O(r * c), worst case we check every coordinate. 
Space complexity: O(r * c), the distance array holds all coord's distances. 



*/