// #pragma GCC optimize("O2")
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct Edge
{
    int idx, st, ed;
    ll weight;
    Edge(int st, int ed, ll weight) : st(st), ed(ed), weight(weight) {}
};

struct Path
{
    ll totalW;
    Edge *last;
};

void quickSort(vector<Edge *> seq, int l, int r);
Edge *pivot;
int i, j;

class SmallHeap
{
public:
    int rear, con, curidx, min;
    Path **hp, *temp;
    SmallHeap(int con) : rear(0), con(con)
    {
        hp = new Path *[con];
    }

    ~SmallHeap()
    {
        delete hp;
    }

    Path *deleteTop()
    {
        if (rear == 0)
        {
            return NULL;
        }
        rear--;
        Path *top = hp[0];
        hp[0] = hp[rear];
        curidx = 0;
        while (true)
        {
            if (2 * curidx + 2 >= rear)
            {
                min = 2 * curidx + 1;
            }
            else
            {
                min = hp[2 * curidx + 1]->totalW > hp[2 * curidx + 2]->totalW ? (2 * curidx + 2) : (2 * curidx + 1);
            }
            if (hp[curidx]->totalW > hp[min]->totalW)
            {
                temp = hp[curidx];
                hp[curidx] = hp[min];
                hp[min] = temp;
                curidx = min;
            }
            else
            {
                break;
            }
            if (2 * curidx + 1 >= rear)
            {
                break;
            }
        }
        return top;
    }

    void insertHeap(Path *val)
    {
        curidx = rear;
        hp[rear++] = val;
        while (curidx > 0)
        {
            if (hp[curidx]->totalW < hp[(curidx - 1) / 2]->totalW)
            {
                temp = hp[curidx];
                hp[curidx] = hp[(curidx - 1) / 2];
                hp[(curidx - 1) / 2] = temp;
                curidx = (curidx - 1) / 2;
            }
            else
            {
                break;
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, qnum, qmax, u, v;
    ll w, newW, oldW;
    Path *temp_path, *new_path;
    Edge *new_edge;
    cin >> t;
    while (t--)
    {
        qmax = 0;
        cin >> n >> m >> qnum;
        int *qry = new int[qnum];
        vector<Edge *> *vertices = new vector<Edge *>[n + 1];
        // vector<Edge *> vertices[n + 1];
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            vertices[u].push_back(new Edge(u, v, w));
        }
        for (int i = 0; i < qnum; i++)
        {
            cin >> qry[i];
            qmax = (qry[i] > qmax) ? qry[i] : qmax;
        }
        ll *qrst = new ll[qmax];
        for (int i = 1; i <= n; i++)
        {
            if (vertices[i].size() != 0)
            {
                quickSort(vertices[i], 0, vertices[i].size() - 1);
                for (int j = 0; j < vertices[i].size(); j++)
                {
                    vertices[i][j]->idx = j;
                }
            }
        }
        SmallHeap *sh = new SmallHeap(2 * n + 5);
        for (int i = 1; i <= n; i++)
        {
            if (vertices[i].size() != 0)
            {
                sh->insertHeap(new Path{(vertices[i][0])->weight, vertices[i][0]});
            }
        }
        for (int i = 0; i < qmax; i++)
        {
            temp_path = sh->deleteTop();
            qrst[i] = temp_path->totalW;
            if (vertices[temp_path->last->st].size() > temp_path->last->idx + 1)
            {
                oldW = temp_path->last->weight;
                new_edge = vertices[temp_path->last->st][temp_path->last->idx + 1];
                newW = new_edge->weight;
                new_path = new Path{temp_path->totalW - oldW + newW, new_edge};
                sh->insertHeap(new_path);
            }
            if (vertices[temp_path->last->ed].size() != 0)
            {
                new_edge = vertices[temp_path->last->ed][0];
                newW = new_edge->weight;
                new_path = new Path{temp_path->totalW + newW, new_edge};
                sh->insertHeap(new_path);
            }
            // delete temp_path;
        }
        for (int i = 0; i < qnum; i++)
        {
            cout << qrst[qry[i] - 1] << '\n';
        }
    }
    return 0;
}

void quickSort(vector<Edge *> seq, int l, int r)
{
    if (l < r)
    {
        i = l;
        j = r;
        pivot = seq[l];
        while (i < j)
        {
            while (i < j && seq[j]->weight >= pivot->weight)
            {
                j--;
            }
            if (i < j)
            {
                seq[i] = seq[j];
            }
            while (i < j && seq[i]->weight < pivot->weight)
            {
                i++;
            }
            if (i < j)
            {
                seq[j] = seq[i];
            }
        }
        seq[i] = pivot;
        quickSort(seq, l, i - 1);
        quickSort(seq, i + 1, r);
    }
}

/*
1
3 3 3
1 2 1
1 3 1
2 3 2
1 2 3
*/