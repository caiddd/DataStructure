/***
@author: caidd
@edition: C++20
@charset: GBK
@environment: win10 64bit
***/

#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

#define MAXSIZE 100              // 最大存储空间

typedef struct Node {            // 顶点表结点
    int adjvex;                  // 顶点数据
    Node *next;                  // 指向第一条依附该顶点的指针
} Node, *VNode, AdjList[MAXSIZE];
typedef struct {
    AdjList vertices;            // 邻接表
    int vexnum, arcnum;          // 图的顶点数和边数
} ALGraph;                       // 以邻接表存储的图类型
typedef struct {
    int vexnum, arcnum;          // 图的顶点数和边数
    bool Edge[MAXSIZE][MAXSIZE]; // 邻接矩阵
} MGraph;                        // 以邻接矩阵存储的图类型
bool vis[MAXSIZE];               // 记录是否访问

// 界面
void show() {
    system("cls");
    printf("无向网图\n");
    printf("1.构建网图\n");
    printf("2.输出邻接矩阵\n");
    printf("3.邻接矩阵转邻接表\n");
    printf("4.深度优先遍历\n");
    printf("5.广度优先遍历\n");
    printf("6.退出\n");
    printf("请输入选择：");
}

// 创建图
void CreateUDG(MGraph &M) {
    printf("请输入图的顶点数和边数：\n");
    scanf("%d%d", &M.vexnum, &M.arcnum);
    printf("请输入边：\n");
    memset(M.Edge, 0, sizeof(M.Edge));
    for(int i = 0, u, v; i < M.arcnum; ++i) {
        scanf("%d%d", &u, &v);
        M.Edge[u][v] = true;
        M.Edge[v][u] = true;
    }
}

// 输出邻接矩阵
void PrintMGraph(MGraph &M) {
    for(int i = 1; i <= M.vexnum; ++i, printf("\n")) {
        for(int j = 1; j <= M.vexnum; ++j) {
            printf(M.Edge[i][j] ? "1 " : "0 ");
        }
    }
}

// 邻接表添加边
void AddEdge(ALGraph &G, int u, int v) {
    VNode tmp = (VNode)malloc(sizeof(Node));
    tmp->adjvex = v;
    tmp->next = G.vertices[u].next;
    G.vertices[u].next = tmp;
}

// 邻接矩阵转邻接表
void MGraphToALGraph(MGraph &M, ALGraph &G) {
    G.arcnum = M.arcnum;
    G.vexnum = M.vexnum;
    for(int i = 1; i <= M.vexnum; ++i) {
        G.vertices[i].next = NULL;
    }
    for(int i = 1; i <= M.vexnum; ++i) {
        // 逆序使邻接表遍历顺序与邻接矩阵同序
        for(int j = M.vexnum; j >= 1; --j) {
            if(M.Edge[i][j]) {
                AddEdge(G, i, j);
            }
        }
    }
}

void DFS(ALGraph &G, int u) {
    vis[u] = true;
    printf("%d ", u);
    for(VNode tmp = G.vertices[u].next; tmp != NULL; tmp = tmp->next) {
        if(!vis[tmp->adjvex]) {
            DFS(G, tmp->adjvex);
        }
    }
}

// 深度优先搜索
void DFSTraverse(ALGraph &G) {
    for(int i = 1; i <= G.vexnum; ++i) {
        vis[i] = false;
    }
    // 防止图非联通
    for(int i = 1; i <= G.vexnum; ++i) {
        if(!vis[i]) {
            DFS(G, i);
        }
    }
}

// 广度优先搜索
void BFSTraverse(ALGraph &G) {
    for(int i = 1; i <= G.vexnum; ++i) {
        vis[i] = false;
    }
    // 防止图非联通
    for(int i = 1; i <= G.vexnum; ++i) {
        if(!vis[i]) {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while(!q.empty()) {
                int u = q.front(); q.pop();
                printf("%d ", u);
                for(VNode tmp = G.vertices[u].next; tmp != NULL; tmp = tmp->next) {
                    if(!vis[tmp->adjvex]) {
                        vis[tmp->adjvex] = true;
                        q.push(tmp->adjvex);
                    }
                }
            }
        }
    }
}

int main() {
    MGraph M;
    ALGraph G;
    for(;;) {
        show();
        int opt;
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                CreateUDG(M);
                break;
            case 2:
                PrintMGraph(M);
                break;
            case 3:
                MGraphToALGraph(M, G);
                break;
            case 4:
                DFSTraverse(G);
                break;
            case 5:
                BFSTraverse(G);
                break;
            case 6:
                printf("已退出");
                Sleep(1500);
                return 0;
            default:
                printf("操作数不存在，请重新输入！");
                break;
        }
        Sleep(1500);
    }
    return 0;
}