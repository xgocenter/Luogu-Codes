#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4, INF = 2147483647;

struct Node {
    int val, left, right, weight, num;
} node[MAXN];

int idx = 1, root;

int newNode(int v) {
    node[idx] = Node({v, 0, 0, 1, 1});
    return idx++;
}

void update(int root) {
    int left = node[root].left, right = node[root].right;
    node[root].weight = node[left].weight + node[right].weight + node[root].num;
}

int getRank(int x, int root) {
    if (root) {
        if (x < node[root].val) 
            return getRank(x, node[root].left);
        if (x > node[root].val) 
            return getRank(x, node[root].right) + node[node[root].left].weight + node[root].num;
        return node[node[root].left].weight + node[root].num;
    }
    return 1;
}

int getNum(int x, int root) {
    if (x <= node[node[root].left].weight) 
        return getNum(x, node[root].left);
    else if (x <= node[node[root].left].weight + node[root].num) 
        return node[root].val;
    else 
        return getNum(x - node[node[root].left].weight - node[root].num, node[root].right);
}

int findPrev(int root) {

}

int findNext(int root) {

}

void insertNode(int &root, int x) {
    if (!root) {
        root = newNode(x);
        return;
    }
    if (x < node[root].val) insertNode(node[root].left, x);
    else if (x > node[root].val) insertNode(node[root].right, x);
    else node[root].num++;
    update(root);
}

int main() {
    int q;
    scanf("%d", &q);
    node[0] = Node({0, 0, 0, 0, 0});
    while (q--) {
        int op, x;
        scanf("%d %d", &op, &x);
        if (op == 1) printf("%d\n", getRank(x, root));
        else if (op == 2) printf("%d\n", getNum(x, root));
        else if (op == 3) printf("%d\n", findPrev(x, root));
        else if (op == 4) printf("%d\n", findNext(x, root));
        else if (op == 5) insertNode(root, x);
    }
    return 0;
}
