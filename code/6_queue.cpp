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

typedef int ElemType; // Ԫ������
typedef struct Node { // ��ʽ���н��
    ElemType data;
    struct Node *next;
} Node, *LinkNode;
typedef struct { // ��ʽ����
    int len;
    LinkNode front = NULL; // ��ͷ
    LinkNode rear = NULL; // ��β
} LinkQueue;

// ����
void show() {
    system("cls");
    printf("1----��ʼ������\n");
    printf("2----���ٶ���\n");
    printf("3----��ն���\n");
    printf("4----�ж϶����Ƿ�Ϊ��\n");
    printf("5----���ض�����Ԫ�ظ���\n");
    printf("6----���ض��ж�ͷԪ��\n");
    printf("7----�����µĶ�βԪ��\n");
    printf("8----ɾ����ͷԪ��\n");
    printf("9----�������Ԫ��\n");
    printf("10---�˳�\n");
    printf("������ѡ��");
}

// ��ʼ��һ������
void InitQueue(LinkQueue &Q) {
    if(Q.front != NULL) {
        printf("�����Ѵ���");
        return;
    }
    Q.len = 0;
    Q.front = Q.rear = (LinkNode)malloc(sizeof(Node));
    Q.front->next = NULL;
}

// �ж϶����Ƿ�Ϊ��
bool Empty(LinkQueue &Q) {
    return Q.front == Q.rear;
}

// ���ض�����Ԫ�ظ���
int Length(LinkQueue &Q) {
    return Q.len;
}

// ���ض��ж�ͷԪ��
int GetFront(LinkQueue &Q) {
    if(Empty(Q)) {
        printf("��ͷԪ�ز����ڣ�");
        return NOTEXIST;
    }
    return Q.front->next->data;
}

// �����µĶ�βԪ��
void Push(LinkQueue &Q, ElemType e) {
    LinkNode tmp = (LinkNode)malloc(sizeof(Node));
    tmp->data = e;
    tmp->next = NULL;
    Q.rear->next = tmp;
    Q.rear = tmp;
    Q.len ++;
}

// ɾ����ͷԪ��
void Pop(LinkQueue &Q) {
    if(Empty(Q)) {
        printf("��ͷԪ�ز����ڣ�");
        return;
    }
    LinkNode tmp = Q.front->next;
    Q.front->next = tmp->next;
    if(Q.rear == tmp) {
        Q.rear = Q.front; // ����ע�⣬�����ͷ������һ��Ԫ�أ���βָ���ΪҰָ��
    }
    Q.len --;
    free(tmp);
}

// ��ն���
void ClearQueue(LinkQueue &Q) {
    while(!Empty(Q)) {
        Pop(Q);
    }
}

// ���ٶ���
void DestroyQueue(LinkQueue &Q) {
    ClearQueue(Q);
    free(Q.front);
    Q.front = Q.rear = NULL;
}

// �������Ԫ��
void PrintQueue(LinkQueue &Q) {
    printf("{ ");
    for(LinkNode tmp = Q.front->next; tmp != NULL; tmp = tmp->next) {
        printf("%d", tmp->data);
        if(tmp->next != NULL) {
            printf(", ");
        }
    }
    printf(" }\n");
}

int main() {
    LinkQueue Q;
    for(;;) {
        show();
        int opt, e;
        scanf("%d", &opt);
        if(1 < opt and opt < 10 and Q.front == NULL) {
            printf("����δ������");
            Sleep(1500);
            continue;
        }
        switch (opt) {
            case 1:
                InitQueue(Q);
                break;
            case 2:
                DestroyQueue(Q);
                break;
            case 3:
                ClearQueue(Q);
                break;
            case 4:
                printf(Empty(Q) ? "����Ϊ��\n" : "���в�Ϊ��\n");
                break;
            case 5:
                printf("%d\n", Length(Q));
                break;
            case 6:
                printf("%d\n", GetFront(Q));
                break;
            case 7:
                printf("������Ҫ����Ԫ��: ");
                scanf("%d", &e);
                Push(Q, e);
                break;
            case 8:
                Pop(Q);
                break;
            case 9:
                PrintQueue(Q);
                break;
            case 10:
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