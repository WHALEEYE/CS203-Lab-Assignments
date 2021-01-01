#include <iostream>
using namespace std;

struct TreeNode {
  int value;
  int idx;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    TreeNode *nodes[n], *tree[n], *temp;
    int ini_idx, val, rear = 0, cur, x = 0, y = 0, pow = 1, copy_idx;
    for (int i = 0; i < n; i++) {
      cin >> val;
      cur = rear;
      temp = new TreeNode{val, rear};
      nodes[i] = temp;
      tree[rear++] = temp;
      while (cur > 0) {
        if (tree[cur]->value > tree[(cur - 1) / 2]->value) {
          tree[cur]->idx = (cur - 1) / 2;
          tree[(cur - 1) / 2]->idx = cur;
          temp = tree[cur];
          tree[cur] = tree[(cur - 1) / 2];
          tree[(cur - 1) / 2] = temp;
          cur = (cur - 1) / 2;
        } else {
          break;
        }
      }
    }
    cin >> ini_idx;
    temp = nodes[ini_idx - 1];
    temp->idx++;
    copy_idx = temp->idx + 1;
    while (temp->idx > 0) {
      x++;
      temp->idx /= 2;
      pow *= 2;
    }
    pow /= 2;
    y = copy_idx - pow;
    cout << x << " " << y << '\n';
  }
  return 0;
}

/*
3
2
2 1
1
3
1 2 3
2
5
3 1 2 2 3
4
*/

/*

                0
        1               2
    3       4       5       6
  7   8   9   10 11   12 13   14



*/