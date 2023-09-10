#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 递归方式求解
int grtBestGoldMining(int w, int n, vector<int> p, vector<int> g){
    if (w == 0 || n == 0){
        return 0;
    }
    // 当前工人总数量小于此金矿需要的人数
    // 换下一座金矿
    if (w < p[n-1]){
        return grtBestGoldMining(w, n-1, p, g);
    }
    return max(grtBestGoldMining(w, n - 1, p, g), grtBestGoldMining(w - p[n-1], n - 1, p, g) + g[n - 1]);

}

// 数组
int grtBestGoldMining1(int w, int n, vector<int> p, vector<int> g){
    vector<vector<int>> resultTable(g.size() + 1, vector<int>(w+1));
    // 填充表格
    for (int i = 1; i <= g.size(); ++ i){
        for (int j = 1; j <= w; ++ j){
            if (j < p[i - 1]){
                resultTable[i][j] = resultTable[i - 1][j];
            }else{
                resultTable[i][j] = max(resultTable[i - 1][j], resultTable[i - 1][j-p[i - 1]] + g[i - 1]);
            }
        }
    }
    return resultTable[g.size()][w];
}

int grtBestGoldMining2(int w, int n, vector<int> p, vector<int> g){
    vector<int> resultTable(w+1);
    // 填充表格
    for (int i = 1; i <= g.size(); ++ i){
        for (int j = w; j >= 1; -- j){
            if (j >= p[i - 1]){
                resultTable[j] = max(resultTable[j], resultTable[j - p[i - 1]] + g[i - 1]);
            }
        }
    }
    return resultTable[w];
}

int main(){
    int w = 10;
    vector<int> p = {5, 5, 3, 4, 3};
    vector<int> g = {400, 500, 200, 300, 350};

    cout << grtBestGoldMining2(w, g.size(), p, g);

    return 0;
}