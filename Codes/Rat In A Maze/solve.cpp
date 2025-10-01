#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, auto &arr, int n, auto &vis)
{
    if(x < 0 || x >= n || y < 0 || y >= n)  return false;
    if(vis[x][y])   return false;
    return arr[x][y];
}

void solve(int x, int y, auto &arr, int n, auto &ans, auto &vis, string path)
{
    if(x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    vis[x][y] = true;

    if(isSafe(x + 1, y, arr, n, vis)) {
        solve(x + 1, y, arr, n, ans, vis, path + 'D');
    }

    if(isSafe(x, y - 1, arr, n, vis)) {
        solve(x, y - 1, arr, n, ans, vis, path + 'L');
    }

    if(isSafe(x, y + 1, arr, n, vis)) {
        solve(x, y + 1, arr, n, ans, vis, path + 'R');
    }

    if(isSafe(x - 1, y, arr, n, vis)) {
        solve(x - 1, y, arr, n, ans, vis, path + 'U');  
    }

    vis[x][y] = false;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    string path = "";
    if(arr[0][0] == 0) return ans;

    solve(0, 0, arr, n, ans, vis, path);
    return ans;
}