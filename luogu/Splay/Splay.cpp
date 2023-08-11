#include <iostream>
#include <cstring>
#include <cstdio>
#define N 100005

using namespace std;

struct Node
{
    int fa;    // 节点父亲
    int val;   // 节点权值
    int cnt;   // 权值出现次数
    int size;  // 子树大小
    int ch[2]; // 左儿子与右儿子（方便运算）
    Node()
    {
        fa = 0;
        val = 0;
        cnt = 0;
        size = 0;
        ch[0] = ch[1] = 0;
    }
    Node(int Fa, int Val, int Cnt, int Size, int R, int L)
    {
        fa = Fa;
        val = Val;
        cnt = Cnt;
        size = Size;
        ch[0] = L;
        ch[1] = R;
    }
} tree[N];
int tot;  // 不算重的节点个数
int root; // 根节点

bool get(int u) { return u == tree[u].ch[1]; }

void maintain(int u) { tree[u].size = tree[tree[u].ch[0]].size + tree[tree[u].ch[1]].size + tree[u].cnt; }

void clear(int u) { tree[u].ch[0] = tree[u].ch[1] = tree[u].fa = tree[u].fa = tree[u].size = tree[u].cnt = 0; }

void rotate(int u)
{
    int v = tree[u].fa;
    // int u_fa = tree[u].fa;           // u_fa = v;
    int v_fa = tree[v].fa;              // u的目标父亲
    int son_u = get(u);                 // u在其父亲的位置
    int son_v = get(v);                 // v在其父亲的位置
    int change = tree[u].ch[son_u ^ 1]; // 获取u中需要更改的子树节点
    // 把这颗子树接到v的u位置：
    tree[change].fa = v;
    tree[v].ch[son_u] = change;
    // 把v接到u中不同的位置
    tree[v].fa = u;
    tree[u].ch[son_u ^ 1] = v;
    // 把u接到v原来的父亲中
    tree[u].fa = v_fa;
    tree[v_fa].ch[son_v] = u;
    maintain(u); // 维护u的size
    maintain(v); // 维护v的size
}

void splay(int u, int v)
{
    v = tree[v].fa; // 方便写下面的代码
    while (tree[u].fa != v)
    {
        if (tree[tree[u].fa].fa == v) rotate(u);
        else if (get(u) == get(tree[u].fa)) rotate(tree[u].fa), rotate(x);
        else rotate(u), rotate(u);
        root = u;
    }
}

void insert(int k)
{
    int now = root; // 从根节点开始
    if (root == 0)  // 如果没有根节点就新建一个
    {
        tree[++tot].fa = 0;                 // 根节点没有父亲
        tree[tot].val = k;                  // 初始化值
        tree[tot].cnt = tree[tot].size = 1; // 初始化cnt与size
        root = tot;                         // 把根定为现在加入的新节点
    }
    else
    {
        while (1)
        {
            tree[now].size++;       // 走过这个点，代表它的大小增加了
            if (tree[now].val == k) // 如果k值与这个点相同，就放进去
            {
                tree[now].cnt++;  // 值的个数加一
                splay(now, root); // 把更新的点旋转到根
                return;
            }
            int nxt = k < tree[now].val ? 0 : 1; // 按照BST找节点
            if (!tree[now].ch[nxt])              // 如果找不到就加一个新的
            {
                tree[++tot].fa = now;               // 新节点的父亲就是当前的
                tree[tot].val = k;                  // 初始化值
                tree[tot].cnt = tree[tot].size = 1; // 初始化cnt与size
                tree[now].ch[nxt] = tot;            // 加入当前节点的儿子
                splay(tot, root);                   // 把新节点移动到根
                return;
            }
            now = tree[now].ch[nxt]; // 向下走
        }
    }
}

int rank(int k)
{
    int ans = 0;    // 累计答案
    int now = root; // 从根开始
    while (1)
    {
        if (k < tree[now].val) // 如果比它小就向左找
        {
            now = tree[now].ch[0];
        }
        else
        {
            ans += tree[tree[now].ch[0]].size; // 否则加上左子树的大小
            if (k == tree[now].val)             // 如果找到了
            {
                splay(now, root); // 把找到的节点移动到根
                return ans + 1;   // 返回答案
            }
            ans += tree[now].cnt;  // 否则加上这个点的权值数
            now = tree[now].ch[1]; // 然后继续向右找
        }
    }
}

int kth(int k)
{
    int now = root; // 从根开始
    while (1)
    {
        if (tree[now].ch[0] && k <= tree[tree[now].ch[0]].size) // 如果在左子树中
        {
            now = tree[now].ch[0]; // 向左找
        }
        else
        {
            k -= tree[now].cnt + tree[tree[now].ch[0]].size; // 减去当前的和左子树的和
            if (k <= 0)                                      // 如果减完了，说明在当前节点
            {
                splay(now, root);     // 把找到的节点移动到根
                return tree[now].val; // 返回真实值
            }
            now = tree[now].ch[1]; // 否则继续向右找
        }
    }
}

int pre()
{
    int now = tree[root].ch[0];
    if (!now) return now;                          // 如果没有左子树，直接返回
    while (tree[now].ch[1]) now = tree[now].ch[1]; // 在左子树中一直向右走
    splay(now, root);                              // 把找到的节点移动到根
    return now;
}

int nxt()
{
    int now = tree[root].ch[1];
    if (!now) return now;                          // 如果没有右子树，直接返回
    while (tree[now].ch[0]) now = tree[now].ch[0]; // 在右子树中一直向左走
    splay(now, root);                              // 把找到的节点移动到根
    return now;
}

void del(int k)
{
    rank(k);
    if (tree[root].cnt > 1) // 如果此节点数量足够
    {
        tree[root].cnt--; // 仅仅把cnt减一
        maintain(root);
        return;
    }
    if (!tree[root].ch[0] && !tree[root].ch[1]) // 如果只有一个点
    {
        clear(root); // 直接删掉
        root = 0;
        return;
    }
    if (!tree[root].ch[0]) // 如果没有左子树
    {
        int now = root;          // 从根开始
        root = tree[root].ch[1]; // 定义新根为右儿子
        tree[root].fa = 0;       // 重置父亲
        clear(now);              // 删掉原来的根
        return;
    }
    if (!tree[root].ch[1]) // 如果没有右子树
    {
        int now = root;          // 从根开始
        root = tree[root].ch[0]; // 定义新根为左儿子
        tree[root].fa = 0;       // 重置父亲
        clear(now);              // 删掉原来的根
        return;
    }
    // 如果左右子树都存在
    int now = root, x = pre();       // 从根开始，同时获得新根
    tree[tree[now].ch[1]].fa = x;    // 定义原根右儿子的父亲为新根
    tree[x].ch[1] = tree[now].ch[1]; // 定义新根的右儿子为原根右儿子
    clear(now);                      // 删掉原来的根
    maintain(root);                  // 重置新根
}

int main()
{
    return 0;
}