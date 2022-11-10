/***
@author: caidd
@edition: C++20
@charset: GBK
@environment: win10 64bit
***/

#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

#define MAXSIZE 12500
#define OVERFLOW -1 // ���
#define EXCEEDED -2 // �������ռ�
#define NOTEXIST -3 // ������


typedef int ElemType; // Ԫ������
// ���Ա��±�� 1 ��ʼ
typedef struct {
    int len;
    ElemType *data = NULL;
} SqList;

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
void CreateList(SqList &L) {
    if(L.data != NULL) {
        printf("���Ա��Ѵ�����");
        return;
    }
    L.len = 0;
    L.data = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
}

// �������Ա�
void DestroyList(SqList &L) {
    L.len = 0;
    free(L.data);
    L.data = NULL;
}

// ������Ա�
void ClearList(SqList &L) {
    L.len = 0;
}

// �ж����Ա��Ƿ�Ϊ��
bool Empty(SqList &L) {
    return L.len == 0;
}

// �����Ա���
int Length(SqList &L) {
    return L.len;
}

// ��ȡ���Ա�ָ��λ��Ԫ��
int GetElem(SqList &L, int i) {
    if(i < 1 or i > L.len) {
        printf("�����");
        return OVERFLOW;
    }
    return L.data[i];
}

// ��ȡδ֪Ԫ�������Ա��λ��
int LocateElem(SqList &L, ElemType e) {
    for(int i = 1; i <= L.len; ++i) {
        if(L.data[i] == e) {
            return i;
        }
    }
    printf("���ҵ�Ԫ�ز����ڣ� ");
    return NOTEXIST;
}

// ��ǰ��
int prev(SqList &L, ElemType e) {
    int i = LocateElem(L, e);
    if(i == 1 or i == NOTEXIST) {
        printf("���ҵ�Ԫ�ز����ڣ� ");
        return NOTEXIST;
    }
    return L.data[i - 1];
}

// ����
int next(SqList &L, ElemType e) {
    int i = LocateElem(L, e);
    if(i == L.len or i == NOTEXIST) {
        printf("���ҵ�Ԫ�ز����ڣ� ");
        return NOTEXIST;
    }
    return L.data[i + 1];
}

// ��ָ��λ�ò���һ��Ԫ��
void ListInsert(SqList &L, int i, ElemType e) {
    if(i < 1 or i > L.len + 1) {
        printf("�����");
        Sleep(1500);
        return;
    }
    if(L.len == MAXSIZE - 1) {
        printf("�������ռ䣡");
        Sleep(1500);
        return;
    }
    for(int j = L.len + 1; j >= i + 1; j --) {
        L.data[j] = L.data[j - 1];
    }
    L.len ++;
    L.data[i] = e;
}

// ɾ�����Ա�ָ��λ��Ԫ��
void ListDelete(SqList &L, int i) {
    if(i < 1 or i > L.len) {
        printf("�����");
        Sleep(1500);
        return;
    }
    for(int j = i; j < L.len; j ++) {
        L.data[j] = L.data[j + 1];
    }
    L.len --;
}

// ��ʾ���Ա�
void PrintList(SqList &L) {
    printf("[ ");
    for(int i = 1; i <= L.len; ++i) {
        printf("%d", L.data[i]);
        if(i != L.len) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

int main() {
    SqList L;
    for(;;) {
        show();
        int opt, i, e;
        scanf("%d", &opt);
        if(1 < opt and opt < 11 and L.data == NULL) {
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