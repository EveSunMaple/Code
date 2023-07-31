#define MAX 数组长度
int head[MAX];//代表一个节点，也是子节点链的起点
int edge[MAX]/*如果是无向图开双倍空间*/;//储存边的值
int son[MAX]/*如果是无向图开双倍空间*/;//子节点链
int ver[MAX]/*如果是无向图开双倍空间*/;//代表有向边