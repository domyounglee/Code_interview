#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_N 32000
using namespace std;

int n, m, a, b, in[MAX_N + 1];
vector<vector<int> > vt;
priority_queue<int> pq;

int main() {
    scanf("%d%d", &n, &m);

    vt.resize(n + 1);
    
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        vt[a].push_back(b);
        in[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (!in[i])
            pq.push(-i);
    }
    while (pq.size()) {
        int here = -pq.top();
        pq.pop();
        printf("%d ", here);
        for (int there : vt[here]) {
            in[there]--;
            if (!in[there])
                pq.push(-there);
        }
    }
    return 0;
}

