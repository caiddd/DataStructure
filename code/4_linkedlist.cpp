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

#define len data // Ϊͷָ���dataȡ������ʵ�ʴ洢����

typedef int ElemType; // Ԫ������
// LinkList Ϊtypedef��ָ��
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} Node, *LinkList;

// ����
void show() {
    system("cls");
    printf("1----��ʼ��һ�����Ա�\n");
    printf("2----�������Ա�\n");
    printf("3----������Ա�\n");
    printf("4----�ж����Ա��Ƿ�Ϊ��\n");
    printf("5----�����Ա���\n");
    printf("6----��ȡ���Ա�ָ��λ��Ԫ��\n");
    printf("7----��ǰ��\n");
    printf("8----����\n");
    printf("9----�����Ա�ָ��λ�ò���Ԫ��\n");
    printf("10---ɾ�����Ա�ָ��λ��Ԫ��\n");
    printf("11---��ʾ���Ա�\n");
    printf("    �˳�������һ��������\n");
    printf("������������룺");
}

// ��ʼ��һ�����Ա�
void CreateList(LinkList &L) {
    if(L != NULL) {
        printf("���Ա��Ѵ�����");
        return;
    }
    L = (LinkList)malloc(sizeof(Node));
    L->len = 0;
    L->next = NULL;
}

// ������Ա�
void ClearList(LinkList &L) {
    while(L->next != NULL) {
        LinkList tmp = L->next;
        L->next = L->next->next;
        free(tmp);
        L->len --;
    }
}

// �������Ա�
void DestroyList(LinkList &L) {
    ClearList(L);
    free(L);
    L = NULL;
}

// �ж����Ա��Ƿ�Ϊ��
bool Empty(LinkList &L) {
    return L->len == 0;
}

// �����Ա���
int Length(LinkList &L) {
    return L->len;
}

// ��ȡ���Ա�ָ��λ��Ԫ��
int GetElem(LinkList &L, int i) {
    if(i < 1 or i > L->len) {
        printf("�����");
        return OVERFLOW;
    }
    LinkList tmp = L;
    while(i--) {
        tmp = tmp->next;
    }
    return tmp->data;
}

// ��ǰ��
int prev(LinkList &L, ElemType e) {
    for(LinkList last = NULL, tmp = L->next; tmp != NULL; last = tmp, tmp = tmp->next) {
        if(tmp->data == e and last != NULL) {
            return last->data;
        }
    }
    printf("Ԫ�ز����ڣ�");
    return NOTEXIST;
}

// ����
int next(LinkList &L, ElemType e) {
    for(LinkList tmp = L->next; tmp != NULL; tmp = tmp->next) {
        if(tmp->data == e and tmp->next != NULL) {
            return tmp->next->data;
        }
    }
    printf("Ԫ�ز����ڣ�");
    return NOTEXIST;
}

// ��ָ��λ�ò���һ��Ԫ��
void ListInsert(LinkList &L, int i, ElemType e) {
    if(i < 1 or i > L->len + 1) {
        printf("�����");
        Sleep(1500);
        return;
    }
    int j = 0;
    for(LinkList tmp = L; tmp != NULL; tmp = tmp->next, ++j) {
        if(i == j + 1) {
            LinkList next = tmp->next;
            tmp->next = (LinkList)malloc(sizeof(Node));
            tmp->next->data = e;
            tmp->next->next = next;
            L->len ++;
            return;
        }
    }
}

// ɾ�����Ա�ָ��λ��Ԫ��
void ListDelete(LinkList &L, int i) {
    if(i < 1 or i > L->len) {
        printf("�����");
        Sleep(1500);
        return;
    }
    int j = 0;
    for(LinkList tmp = L; tmp != NULL; tmp = tmp->next, ++j) {
        if(i == j + 1) {
            LinkList next = tmp->next;
            tmp->next = tmp->next->next;
            free(next);
            L->len --;
            return;
        }
    }
}

// ��ʾ���Ա�
void PrintList(LinkList &L) {
    printf("[ ");
    for(LinkList tmp = L->next; tmp != NULL; tmp = tmp->next) {
        printf("%d", tmp->data);
        if(tmp->next != NULL) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

int main() {
    LinkList L = NULL;
    for(;;) {
        show();
        int opt, i, e;
        scanf("%d", &opt);
        if(1 < opt and opt < 11 and L == NULL) {
            printf("���Ա�δ������");
            Sleep(1500);
            continue;
        }
        if(opt < 0) {
            printf("�˳�");
            Sleep(1500);
            return 0;
        }
        switch (opt) {
            case 1:
                CreateList(L);
                break;
            case 2:
                DestroyList(L);
                break;
            case 3:
                ClearList(L);
                break;
            case 4:
                printf(Empty(L) ? "���Ա�Ϊ��\n" : "���Ա�Ϊ��\n");
                break;
            case 5:
                printf("%d\n", Length(L));
                break;
            case 6:
                printf("�������ѯ��λ��: ");
                scanf("%d", &i);
                printf("%d\n", GetElem(L, i));
                break;
            case 7:
                printf("������Ҫ��ѯǰ����Ԫ��: ");
                scanf("%d", &e);
                printf("%d\n", prev(L, e));
                break;
            case 8:
                printf("������Ҫ��ѯ��̵�Ԫ��: ");
                scanf("%d", &e);
                printf("%d\n", next(L, e));
                break;
            case 9:
                printf("����������λ��: ");
                scanf("%d", &i);
                printf("����������Ԫ��: ");
                scanf("%d", &e);
                ListInsert(L, i, e);
                break;
            case 10:
                printf("������ɾ����λ��: ");
                scanf("%d", &i);
                ListDelete(L, i);
                break;
            case 11:
                PrintList(L);
                break;
            default:
                printf("�����������ڣ����������룡");
                break;
        }
        Sleep(1500);
    }
    return 0;
}