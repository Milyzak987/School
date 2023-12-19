#include <iostream>
#include <vector>
using namespace std;

bool isValidMove(vector<vector<int>>& grid, int x, int y) {
    int rows = grid.size();
    int cols = grid[0].size();
    return (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 0);
}

bool isPathExists(vector<vector<int>>& grid, int a, int b, int c, int d) {
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    visited[a][b] = true;
    
    vector<pair<int, int>> queue;
    queue.push_back({a, b});
    
    while (!queue.empty()) {
        pair<int, int> current = queue.front();
        queue.erase(queue.begin());
        int x = current.first;
        int y = current.second;
        
        if (x == c && y == d) {
            return true;
        }
        
        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if (isValidMove(grid, newX, newY) && !visited[newX][newY]) {
                visited[newX][newY] = true;
                queue.push_back({newX, newY});
            }
        }
    }
    
    return false;
}

int main() {
    // Przykładowa plansza (możesz zmienić dane wejściowe)
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {0, 1, 0, 0},
        {0, 0, 0, 0}
    };

    int start_x = 0, start_y = 0; // Pole startowe (a, b)
    int end_x = 3, end_y = 3; // Pole docelowe (c, d)
    
    if (isPathExists(grid, start_x, start_y, end_x, end_y)) {
        cout << "Istnieje droga z pola (" << start_x << ", " << start_y << ") do pola (" << end_x << ", " << end_y << ")." << endl;
    } else {
        cout << "Nie istnieje droga z pola (" << start_x << ", " << start_y << ") do pola (" << end_x << ", " << end_y << ")." << endl;
    }
    
    return 0;
}
