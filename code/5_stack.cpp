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
#define MAXSIZE 12500 // ���洢�ռ�

typedef int ElemType;
// ջ�±��0��ʼ
typedef struct {
    int top;
    ElemType *data = NULL;
} SqStack;

void show() {
    system("cls");
    printf("1----��ʼ��Ϊ��ջ\n");
    printf("2----����ջ\n");
    printf("3----��ջ�ÿ�\n");
    printf("4----�ж�ջ�Ƿ�Ϊ��ջ\n");
    printf("5----����ջ�ĳ���\n");
    printf("6----��ջ��Ԫ��\n");
    printf("7----����Ԫ�أ���ʹ���Ϊջ��Ԫ��\n");
    printf("8----ɾ��ջ��Ԫ�أ���������ֵ\n");
    printf("9----���ջ��Ԫ��\n");
    printf("10---�˳�\n");
    printf("������ѡ��");
}

// ��ʼ��һ����ջ
void InitStack(SqStack &S) {
    if(S.data != NULL) {
        printf("ջ�Ѵ�����");
        return;
    }
    S.top = -1;
    S.data = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
}

// ����ջ
void DestroyStack(SqStack &S) {
    S.top = -1;
    free(S.data);
    S.data = NULL;
}

// ��ջ�ÿ�
void ClearStack(SqStack &S) {
    S.top = -1;
}

// �ж�ջ�Ƿ�Ϊ��ջ
bool StackEmpty(SqStack &S) {
    return S.top == -1;
}

// ����ջ�ĳ���
int Length(SqStack &S) {
    return S.top + 1;
}

// ��ջ��Ԫ��
int GetTop(SqStack &S) {
    if(StackEmpty(S)) {
        printf("ջ��Ԫ�ز����ڣ�");
        return NOTEXIST;
    }
    return S.data[S.top];
}

// ����Ԫ�أ���ʹ���Ϊջ��Ԫ��
void Push(SqStack &S, ElemType e) {
    if(S.top == MAXSIZE - 1) {
        printf("�������ռ䣡");
        Sleep(1500);
        return;
    }
    S.data[++S.top] = e;
}

// ɾ��ջ��Ԫ�أ���������ֵ
int Pop(SqStack &S) {
    if(StackEmpty(S)) {
        printf("ջ��Ԫ�ز����ڣ�");
        return NOTEXIST;
    }
    return S.data[S.top--];
}

// ���ջ��Ԫ��
void PrintStack(SqStack &S) {
    printf("{ ");
    for(int i = 0; i <= S.top; ++i) {
        printf("%d", S.data[i]);
        if(i != S.top) {
            printf(", ");
        }
    }
    printf(" }\n");
}

int main() {
    SqStack S;
    for(;;) {
        show();
        int opt, e;
        scanf("%d", &opt);
        if(1 < opt and opt < 10 and S.data == NULL) {
            printf("ջδ������");
            Sleep(1500);
            continue;
        }
        switch (opt) {
            case 1:
                InitStack(S);
                break;
            case 2:
                DestroyStack(S);
                break;
            case 3:
                ClearStack(S);
                break;
            case 4:
                printf(StackEmpty(S) ? "ջΪ��\n" : "ջ��Ϊ��\n");
                break;
            case 5:
                printf("%d", Length(S));
                break;
            case 6:
                printf("%d", GetTop(S));
                break;
            case 7:
                printf("������Ԫ�أ�");
                scanf("%d", &e);
                Push(S, e);
                break;
            case 8:
                printf("%d", Pop(S));
                break;
            case 9:
                PrintStack(S);
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