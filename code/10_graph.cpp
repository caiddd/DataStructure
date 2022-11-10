/***
@author: caidd
@edition: C++20
@charset: GBK
@environment: win10 64bit
***/

#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

#define MAXSIZE 100              // ���洢�ռ�

typedef struct Node {            // �������
    int adjvex;                  // ��������
    Node *next;                  // ָ���һ�������ö����ָ��
} Node, *VNode, AdjList[MAXSIZE];
typedef struct {
    AdjList vertices;            // �ڽӱ�
    int vexnum, arcnum;          // ͼ�Ķ������ͱ���
} ALGraph;                       // ���ڽӱ�洢��ͼ����
typedef struct {
    int vexnum, arcnum;          // ͼ�Ķ������ͱ���
    bool Edge[MAXSIZE][MAXSIZE]; // �ڽӾ���
} MGraph;                        // ���ڽӾ���洢��ͼ����
bool vis[MAXSIZE];               // ��¼�Ƿ����

// ����
void show() {
    system("cls");
    printf("������ͼ\n");
    printf("1.������ͼ\n");
    printf("2.����ڽӾ���\n");
    printf("3.�ڽӾ���ת�ڽӱ�\n");
    printf("4.������ȱ���\n");
    printf("5.������ȱ���\n");
    printf("6.�˳�\n");
    printf("������ѡ��");
}

// ����ͼ
void CreateUDG(MGraph &M) {
    printf("������ͼ�Ķ������ͱ�����\n");
    scanf("%d%d", &M.vexnum, &M.arcnum);
    printf("������ߣ�\n");
    memset(M.Edge, 0, sizeof(M.Edge));
    for(int i = 0, u, v; i < M.arcnum; ++i) {
        scanf("%d%d", &u, &v);
        M.Edge[u][v] = true;
        M.Edge[v][u] = true;
    }
}

// ����ڽӾ���
void PrintMGraph(MGraph &M) {
    for(int i = 1; i <= M.vexnum; ++i, printf("\n")) {
        for(int j = 1; j <= M.vexnum; ++j) {
            printf(M.Edge[i][j] ? "1 " : "0 ");
        }
    }
}

// �ڽӱ���ӱ�
void AddEdge(ALGraph &G, int u, int v) {
    VNode tmp = (VNode)malloc(sizeof(Node));
    tmp->adjvex = v;
    tmp->next = G.vertices[u].next;
    G.vertices[u].next = tmp;
}

// �ڽӾ���ת�ڽӱ�
void MGraphToALGraph(MGraph &M, ALGraph &G) {
    G.arcnum = M.arcnum;
    G.vexnum = M.vexnum;
    for(int i = 1; i <= M.vexnum; ++i) {
        G.vertices[i].next = NULL;
    }
    for(int i = 1; i <= M.vexnum; ++i) {
        // ����ʹ�ڽӱ����˳�����ڽӾ���ͬ��
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

// �����������
void DFSTraverse(ALGraph &G) {
    for(int i = 1; i <= G.vexnum; ++i) {
        vis[i] = false;
    }
    // ��ֹͼ����ͨ
    for(int i = 1; i <= G.vexnum; ++i) {
        if(!vis[i]) {
            DFS(G, i);
        }
    }
}

// �����������
void BFSTraverse(ALGraph &G) {
    for(int i = 1; i <= G.vexnum; ++i) {
        vis[i] = false;
    }
    // ��ֹͼ����ͨ
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
                printf("���˳�");
                Sleep(1500);
                return 0;
            default:
                printf("�����������ڣ����������룡");
                break;
        }
        Sleep(1500);
    }
    return 0;
}