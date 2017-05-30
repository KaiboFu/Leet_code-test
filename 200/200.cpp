#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int dx[4] = {1,-1,0, 0};
int dy[4] = {0, 0, 1, -1};
int numIslands1(vector<vector<char>>& grid){// 非递归实现有些问题， 这个代码 适用于 facebook 面试题 桌上的战舰
    //http://mp.weixin.qq.com/s?__biz=MzA5MzE4MjgyMw==&mid=2649455890&idx=1&sn=11291f4b9f80f043ed8cd66b54fcf943&chksm=887e131abf099a0cc18799f24cb2dfbc3225f0d52ab613225ef000bac633101f69cc161a2083&scene=0#wechat_redirect
    if(grid.empty())
        return 0;
    int res = 0;
    int len = grid.size();
    int len1 = grid[0].size();
    for(int i = 0; i < len; i++)
        for(int j = 0; j < len1; j++){
            if('1' == grid[i][j]){
                res ++;
                grid[i][j] = 'x';
                int pos = i;
                int pos1 = j;
                for(int d =0; d < 4; d++){
                    cout << "in "<< pos << ends << pos1 <<endl;
                     while(pos + dx[d] >=0 && pos + dx[d] < grid.size() && pos1 + dy[d] >= 0
                           && pos1 +dy[d] < grid[0].size() && grid[pos+dx[d]][pos1+dy[d]] == '1'){
                            grid[pos + dx[d]][pos1 + dy[d]] = 'x';
                            pos += dx[d]; pos1 += dy[d];

                          }
                    cout << "out "<< pos << ends << pos1 <<endl;
                }
        cout << res <<endl;
        for (int i1 = 0; i1 < grid.size(); i1++){
            for(int j1 = 0 ;j1 < grid[0].size(); j1++)
                cout << grid[i1][j1] << ends;
            cout << endl;
        }
    }
    }
    return res;
}
void dfs(vector<vector<char>>& grid, int i, int j){
    grid[i][j] = 'x';
    for(int d =0; d < 4; d++)
        if(i + dx[d] >=0 && i + dx[d] < grid.size() && j + dy[d] >= 0 && j +dy[d] < grid[0].size() && grid[i+dx[d]][j+dy[d]] == '1')
            dfs(grid, i + dx[d], j + dy[d]);
}
int numIslands(vector<vector<char>>& grid){// 正确代码，递归调用 DFS
    if(grid.empty())
        return 0;
    int res = 0;
    int len = grid.size();
    int len1 = grid[0].size();
    for(int i = 0; i < len; i++)
        for(int j = 0; j < len1; j++){
            if('1' == grid[i][j]){
                res ++;
                dfs(grid, i, j);

/*    for (int i1 = 0; i1 < grid.size(); i1++){
        for(int j1 = 0 ;j1 < grid[0].size(); j1++)
            cout << grid[i1][j1] << ends;
        cout << endl;
    }*/

            }
        }
    return res;
}

int main(){
    vector<vector<char>> grid = { {'1','1','0','0','0'},{'1','1','0','0','0'},
    {'0','0','1','0','0'},{'0','0','0','1','1'}};
    vector<vector<char>> grid1 = { {'1','1','0','0','0'},{'1','1','0','0','0'},
    {'0','0','1','0','0'},{'0','0','0','1','1'}};
    cout << numIslands(grid) <<endl;
    for (int i1 = 0; i1 < grid.size(); i1++){
        for(int j1 = 0 ;j1 < grid[0].size(); j1++)
            cout << grid[i1][j1] << ends;
        cout << endl;
    }


    cout << numIslands1(grid1) <<endl;
    for (int i1 = 0; i1 < grid1.size(); i1++){
    for(int j1 = 0 ;j1 < grid1[0].size(); j1++)
            cout << grid1[i1][j1] << ends;
        cout << endl;
    }
    return 0;

}
