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
#define OVERFLOW -1 // 溢出
#define EXCEEDED -2 // 超出最大空间
#define NOTEXIST -3 // 不存在


typedef int ElemType; // 元素类型
// 线性表下标从 1 开始
typedef struct {
    int len;
    ElemType *data = NULL;
} SqList;

// 界面
void show() {
    system("cls");
    printf("1----初始化一个线性表\n");
    printf("2----销毁线性表\n");
    printf("3----清空线性表\n");
    printf("4----判断线性表是否为空\n");
    printf("5----求线性表长度\n");
    printf("6----获取线性表指定位置元素\n");
    printf("7----求前驱\n");
    printf("8----求后继\n");
    printf("9----在线性表指定位置插入元素\n");
    printf("10---删除线性表指定位置元素\n");
    printf("11---显示线性表\n");
    printf("    退出，输入一个负数！\n");
    printf("请输入操作代码：");
}

// 初始化一个线性表
void CreateList(SqList &L) {
    if(L.data != NULL) {
        printf("线性表已创建！");
        return;
    }
    L.len = 0;
    L.data = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
}

// 销毁线性表
void DestroyList(SqList &L) {
    L.len = 0;
    free(L.data);
    L.data = NULL;
}

// 清空线性表
void ClearList(SqList &L) {
    L.len = 0;
}

// 判断线性表是否为空
bool Empty(SqList &L) {
    return L.len == 0;
}

// 求线性表长度
int Length(SqList &L) {
    return L.len;
}

// 获取线性表指定位置元素
int GetElem(SqList &L, int i) {
    if(i < 1 or i > L.len) {
        printf("溢出！");
        return OVERFLOW;
    }
    return L.data[i];
}

// 获取未知元素在线性表的位置
int LocateElem(SqList &L, ElemType e) {
    for(int i = 1; i <= L.len; ++i) {
        if(L.data[i] == e) {
            return i;
        }
    }
    printf("查找的元素不存在！ ");
    return NOTEXIST;
}

// 求前驱
int prev(SqList &L, ElemType e) {
    int i = LocateElem(L, e);
    if(i == 1 or i == NOTEXIST) {
        printf("查找的元素不存在！ ");
        return NOTEXIST;
    }
    return L.data[i - 1];
}

// 求后继
int next(SqList &L, ElemType e) {
    int i = LocateElem(L, e);
    if(i == L.len or i == NOTEXIST) {
        printf("查找的元素不存在！ ");
        return NOTEXIST;
    }
    return L.data[i + 1];
}

// 在指定位置插入一个元素
void ListInsert(SqList &L, int i, ElemType e) {
    if(i < 1 or i > L.len + 1) {
        printf("溢出！");
        Sleep(1500);
        return;
    }
    if(L.len == MAXSIZE - 1) {
        printf("超出最大空间！");
        Sleep(1500);
        return;
    }
    for(int j = L.len + 1; j >= i + 1; j --) {
        L.data[j] = L.data[j - 1];
    }
    L.len ++;
    L.data[i] = e;
}

// 删除线性表指定位置元素
void ListDelete(SqList &L, int i) {
    if(i < 1 or i > L.len) {
        printf("溢出！");
        Sleep(1500);
        return;
    }
    for(int j = i; j < L.len; j ++) {
        L.data[j] = L.data[j + 1];
    }
    L.len --;
}

// 显示线性表
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
            printf("线性表未创建！");
            Sleep(1500);
            continue;
        }
        if(opt < 0) {
            printf("退出");
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
                printf(Empty(L) ? "线性表为空\n" : "线性表不为空\n");
                break;
            case 5:
                printf("%d\n", Length(L));
                break;
            case 6:
                printf("请输入查询的位置: ");
                scanf("%d", &i);
                printf("%d\n", GetElem(L, i));
                break;
            case 7:
                printf("请输入要查询前驱的元素: ");
                scanf("%d", &e);
                printf("%d\n", prev(L, e));
                break;
            case 8:
                printf("请输入要查询后继的元素: ");
                scanf("%d", &e);
                printf("%d\n", next(L, e));
                break;
            case 9:
                printf("请输入插入的位置: ");
                scanf("%d", &i);
                printf("请输入插入的元素: ");
                scanf("%d", &e);
                ListInsert(L, i, e);
                break;
            case 10:
                printf("请输入删除的位置: ");
                scanf("%d", &i);
                ListDelete(L, i);
                break;
            case 11:
                PrintList(L);
                break;
            default:
                printf("操作数不存在，请重新输入！");
                break;
        }
        Sleep(1500);
    }
    return 0;
}