class Solution {
    const vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
public:
    int minMoves(vector<string>& classroom, int energy) {
        const int m = classroom.size(), n = classroom[0].length();
        vector<vector<int>> id(m, vector<int>(n, -1));
        int x = -1, y = -1, p = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    x = i;
                    y = j;
                } else if (classroom[i][j] == 'L') {
                    id[i][j] = p++;
                }
                
            }
        }
        if (p == 0) return 0;
        const int out = (1 << p) - 1;
        vector<vector<vector<vector<int>>>> save(m, vector<vector<vector<int>>>(n, vector<vector<int>>(energy + 1, vector<int>(out + 1, -1))));
        save[x][y][energy][out] = 0;
        queue<int> q;
        for (q.push((x << 22) | (y << 16) | (energy << 10) | out); !q.empty();) {
            int x = q.front() >> 22, y = (q.front() >> 16) & 63, now = (q.front() >> 10) & 63, s = q.front() & 1023;
            q.pop();
            if (s == 0) return save[x][y][now][s];
            const int step = save[x][y][now][s] + 1;
            if (--now < 0) continue;
            for (int i = 0; i < 4; ++i) {
                const int xx = x + dx[i], yy = y + dy[i];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n || classroom[xx][yy] == 'X') {
                    continue;
                }
                const int e = classroom[xx][yy] == 'R' ? energy : now, mask = classroom[xx][yy] == 'L' ? (1 << id[xx][yy]) : 0, state = (s & mask) ? (s ^ mask) : s;
                if (save[xx][yy][e][state] < 0) {
                    save[xx][yy][e][state] = step;
                    q.push((xx << 22) | (yy << 16) | (e << 10) | state);
                    
                }
            
            }
        }
        return -1;
        
    }
};