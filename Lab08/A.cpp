#include <iostream>
using namespace std;

struct TreeNode
{
    int value;
    bool isRoot;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *const nul = new TreeNode{-1, false, NULL, NULL};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        cs++;
        int n;
        bool invalid = false, bigRoot;
        cin >> n;
        int **relation = new int *[2], rear = 0, front = 0, count = 0, value, parent, son;
        relation[1] = new int[n - 1];
        relation[0] = new int[n - 1];
        TreeNode **tree = new TreeNode *[n], *root, **queue = new TreeNode *[2 * n];
        for (int i = 0; i < n; i++)
        {
            cin >> value;
            tree[i] = new TreeNode{value, true, nul, nul};
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> parent >> son;
            relation[0][i] = parent - 1;
            relation[1][i] = son - 1;
            tree[relation[1][i]]->isRoot = false;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (tree[relation[0][i]]->left == nul)
            {
                tree[relation[0][i]]->left = tree[relation[1][i]];
            }
            else if (tree[relation[0][i]]->right == nul)
            {
                tree[relation[0][i]]->right = tree[relation[1][i]];
            }
            else
            {
                invalid = true;
                break;
            }
        }
        if (invalid)
        {
            cout << "Case #" << cs << ": NO\n";
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            if (tree[i]->isRoot == true)
            {
                root = tree[i];
                break;
            }
        }
        queue[0] = root;
        rear++;
        bigRoot = (root->value > root->left->value);
        while (count < n)
        {
            if (queue[front] == nul)
            {
                front++;
                continue;
            }
            if ((((queue[front]->value < queue[front]->left->value && queue[front]->left != nul) || (queue[front]->value < queue[front]->right->value && queue[front]->right != nul)) && bigRoot) ||
                (((queue[front]->value > queue[front]->left->value && queue[front]->left != nul) || (queue[front]->value > queue[front]->right->value && queue[front]->right != nul)) && !bigRoot))
            {
                invalid = true;
                break;
            }
            queue[rear++] = queue[front]->left;
            queue[rear++] = queue[front++]->right;
            count++;
        }
        if (invalid)
        {
            cout << "Case #" << cs << ": NO\n";
            continue;
        }
        count = 0;
        int k = 0;
        while (count < n)
        {
            if (queue[k++] != nul)
            {
                count++;
            }
            else
            {
                invalid = true;
                break;
            }
        }
        if (invalid)
        {
            cout << "Case #" << cs << ": NO\n";
            continue;
        }
        cout << "Case #" << cs << ": YES\n";
    }
    return 0;
}