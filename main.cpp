#include <iostream>
#include <cstring>

using namespace std;

bool vis[9][9];
int ans = 0;

bool check(int x, int y) {
    for (int i = 1; i <= 8; i++) {
        if (vis[i][x]) {
            return false;
        }
    }
    int tx = x, ty = y, type = 1, flag = 1;
    while (flag) {
        if (flag && vis[ty][tx]) {
            return false;
        }
        switch (type) {
            case 1:
                tx--, ty--;
                if (tx <= 0 || ty <= 0) {
                    tx = x, ty = y;
                    type++;
                }
                break;
            case 2:
                tx++, ty++;
                if (tx > 8 || ty > 8) {
                    tx = x, ty = y;
                    type++;
                }
                break;
            case 3:
                tx++, ty--;
                if (tx > 8 || ty <= 0) {
                    tx = x, ty = y;
                    type++;
                }
                break;
            case 4:
                tx--, ty++;
                if (tx <= 0 || ty > 8) {
                    flag = 0;
                }
                break;
        }
    }
    return true;
}

void dfs(int count) {
    if (count <= 8) {
        for (int i = 1; i <= 8; i++) {
            if (check(i, count)) {
                vis[count][i] = 1;
                dfs(count + 1);
                vis[count][i] = 0;
            }
        }
    } else {
        ans++;
    }
}

int main(int argc, char** argv) {
    cout << "Start processing Eight Queen problem" << endl;
    memset(vis, false, sizeof(vis));
    dfs(1);
    cout << "Total solutions of Eight Queen problem: " << ans;
	return 0;
}
