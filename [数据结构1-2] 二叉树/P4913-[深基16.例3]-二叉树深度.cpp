#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 1;

int maxDepth;

struct Node {
    int left, right;
} node[MAXN];

void dfs(int root, int depth) {
    if (node[root].left == 0 && node[root].right == 0) {
        maxDepth = max(maxDepth, depth);
        return;
    }
    dfs(node[root].left, depth + 1);
    dfs(node[root].right, depth + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &node[i].left, &node[i].right);
    }
    dfs(1, 1);
    printf("%d", maxDepth);
    return 0;
}
