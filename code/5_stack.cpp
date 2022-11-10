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
#define MAXSIZE 12500 // 最大存储空间

typedef int ElemType;
// 栈下标从0开始
typedef struct {
    int top;
    ElemType *data = NULL;
} SqStack;

void show() {
    system("cls");
    printf("1----初始化为空栈\n");
    printf("2----销毁栈\n");
    printf("3----将栈置空\n");
    printf("4----判断栈是否为空栈\n");
    printf("5----返回栈的长度\n");
    printf("6----求栈顶元素\n");
    printf("7----插入元素，并使其成为栈顶元素\n");
    printf("8----删除栈顶元素，并返回其值\n");
    printf("9----输出栈内元素\n");
    printf("10---退出\n");
    printf("请输入选择：");
}

// 初始化一个空栈
void InitStack(SqStack &S) {
    if(S.data != NULL) {
        printf("栈已创建！");
        return;
    }
    S.top = -1;
    S.data = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
}

// 销毁栈
void DestroyStack(SqStack &S) {
    S.top = -1;
    free(S.data);
    S.data = NULL;
}

// 将栈置空
void ClearStack(SqStack &S) {
    S.top = -1;
}

// 判断栈是否为空栈
bool StackEmpty(SqStack &S) {
    return S.top == -1;
}

// 返回栈的长度
int Length(SqStack &S) {
    return S.top + 1;
}

// 求栈顶元素
int GetTop(SqStack &S) {
    if(StackEmpty(S)) {
        printf("栈顶元素不存在！");
        return NOTEXIST;
    }
    return S.data[S.top];
}

// 插入元素，并使其成为栈顶元素
void Push(SqStack &S, ElemType e) {
    if(S.top == MAXSIZE - 1) {
        printf("超出最大空间！");
        Sleep(1500);
        return;
    }
    S.data[++S.top] = e;
}

// 删除栈顶元素，并返回其值
int Pop(SqStack &S) {
    if(StackEmpty(S)) {
        printf("栈顶元素不存在！");
        return NOTEXIST;
    }
    return S.data[S.top--];
}

// 输出栈内元素
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
            printf("栈未创建！");
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
                printf(StackEmpty(S) ? "栈为空\n" : "栈不为空\n");
                break;
            case 5:
                printf("%d", Length(S));
                break;
            case 6:
                printf("%d", GetTop(S));
                break;
            case 7:
                printf("请输入元素：");
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