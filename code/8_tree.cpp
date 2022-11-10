/***
@author: caidd
@edition: C++20
@charset: GBK
@environment: win10 64bit
***/

#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

#define OVERFLOW -1 // ���
#define NOTEXIST -2 // ������

typedef char ElemType; // Ԫ������
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild; // ���Һ���ָ��
}BiTNode, *BiTree;

// ����
void show() {
    system("cls");
    printf("1----����������\n");
    printf("2----�������������\n");
    printf("3----�������������1\n");
    printf("4----�������������2\n");
    printf("5----�������������\n");
    printf("6----�������������\n");
    printf("7----������������\n");
    printf("8----�˳�\n");
    printf("������ѡ��");
}

char Read() {
    char ch = getchar();
    while(ch != ' ' and (ch < 'A' or ch > 'Z')) {
        ch = getchar();
    }
    return ch;
}

// ������������д���������
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

// �������
void PreOrder(BiTree T) {
    if(T == NULL) return;
    putchar(T->data);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

// �������
void InOrder(BiTree T) {
    if(T == NULL) return;
    InOrder(T->lchild);
    putchar(T->data);
    InOrder(T->rchild);
}

// �������
void PostOrder(BiTree T) {
    if(T == NULL) return;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    putchar(T->data);
}

// �������������-�ǵݹ�
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

// �������
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

// �����
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
            printf("������δ������");
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