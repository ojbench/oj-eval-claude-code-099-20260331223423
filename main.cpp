#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
vector<vector<int>> grid;
vector<vector<bool>> visited;

// DFS to explore connected water cells
int dfs(int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n) {
        return 0; // Out of bounds
    }
    if (visited[i][j] || grid[i][j] == 0) {
        return 0; // Already visited or land
    }

    visited[i][j] = true;
    int fish = grid[i][j];

    // Explore 4 adjacent cells
    fish += dfs(i + 1, j);
    fish += dfs(i - 1, j);
    fish += dfs(i, j + 1);
    fish += dfs(i, j - 1);

    return fish;
}

int main() {
    cin >> m >> n;

    grid.resize(m, vector<int>(n));
    visited.resize(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int maxFish = 0;

    // Try starting from each water cell
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0 && !visited[i][j]) {
                int fish = dfs(i, j);
                maxFish = max(maxFish, fish);
            }
        }
    }

    cout << maxFish << endl;

    return 0;
}
