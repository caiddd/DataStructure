/***
@author: caidd
@edition: C++20
@charset: GBK
@environment: win10 64bit
***/

#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

#define OVERFLOW -1 // 溢出
#define NOTEXIST -2 // 不存在

typedef char ElemType; // 元素类型
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild; // 左、右孩子指针
}BiTNode, *BiTree;

// 界面
void show() {
    system("cls");
    printf("1----创建二叉树\n");
    printf("2----先序遍历二叉树\n");
    printf("3----中序遍历二叉树1\n");
    printf("4----中序遍历二叉树2\n");
    printf("5----后序遍历二叉树\n");
    printf("6----层序遍历二叉树\n");
    printf("7----求二叉树的深度\n");
    printf("8----退出\n");
    printf("请输入选择：");
}

char Read() {
    char ch = getchar();
    while(ch != ' ' and (ch < 'A' or ch > 'Z')) {
        ch = getchar();
    }
    return ch;
}

// 由先序遍历序列创建二叉树
void CreateTree(BiTree &T) {
    char ch = Read();
    if(ch == ' ') {
        T = NULL;
        return;
    }
    T = (BiTree)malloc(sizeof(BiTNode));
    T->data = ch;
    CreateTree(T->lchild);
    CreateTree(T->rchild);
}

// 先序遍历
void PreOrder(BiTree T) {
    if(T == NULL) return;
    putchar(T->data);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

// 中序遍历
void InOrder(BiTree T) {
    if(T == NULL) return;
    InOrder(T->lchild);
    putchar(T->data);
    InOrder(T->rchild);
}

// 后序遍历
void PostOrder(BiTree T) {
    if(T == NULL) return;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    putchar(T->data);
}

// 中序遍历二叉树-非递归
void InOrderNonRecur(BiTree T) {
    if(T == NULL) return;
    stack<BiTree> S;
    while(!S.empty() or T != NULL) {
        if(T != NULL) {
            S.push(T);
            T = T->lchild;
        } else {
            T = S.top();
            putchar(T->data);

            S.pop();
            T = T->rchild;
        }
    }
}

// 层序遍历
void LevelOrder(BiTree T) {
    queue<BiTree> Q;
    Q.push(T);
    while(!Q.empty()) {
        T = Q.front(); Q.pop();
        putchar(T->data);
        if(T->lchild != NULL) {
            Q.push(T->lchild);
        }
        if(T->rchild != NULL) {
            Q.push(T->rchild);
        }
    }
}

// 求深度
int GetDepth(BiTree T) {
    if(T == NULL) return 0;
    return max(GetDepth(T->lchild), GetDepth(T->rchild)) + 1;
}

int main() {
    BiTree T = NULL;
    for(;;) {
        show();
        int opt;
        scanf("%d", &opt);
        if(1 < opt and opt < 8 and T == NULL) {
            printf("二叉树未创建！");
            Sleep(1500);
            continue;
        }
        switch (opt) {
            case 1:
                CreateTree(T);
                break;
            case 2:
                PreOrder(T);
                break;
            case 3:
                InOrder(T);
                break;
            case 4:
                InOrderNonRecur(T);
                break;
            case 5:
                PostOrder(T);
                break;
            case 6:
                LevelOrder(T);
                break;
            case 7:
                printf("%d", GetDepth(T));
                break;
            case 8:
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