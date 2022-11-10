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

#define len data // 为头指针的data取别名，实际存储长度

typedef int ElemType; // 元素类型
// LinkList 为typedef的指针
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} Node, *LinkList;

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
void CreateList(LinkList &L) {
    if(L != NULL) {
        printf("线性表已创建！");
        return;
    }
    L = (LinkList)malloc(sizeof(Node));
    L->len = 0;
    L->next = NULL;
}

// 清空线性表
void ClearList(LinkList &L) {
    while(L->next != NULL) {
        LinkList tmp = L->next;
        L->next = L->next->next;
        free(tmp);
        L->len --;
    }
}

// 销毁线性表
void DestroyList(LinkList &L) {
    ClearList(L);
    free(L);
    L = NULL;
}

// 判断线性表是否为空
bool Empty(LinkList &L) {
    return L->len == 0;
}

// 求线性表长度
int Length(LinkList &L) {
    return L->len;
}

// 获取线性表指定位置元素
int GetElem(LinkList &L, int i) {
    if(i < 1 or i > L->len) {
        printf("溢出！");
        return OVERFLOW;
    }
    LinkList tmp = L;
    while(i--) {
        tmp = tmp->next;
    }
    return tmp->data;
}

// 求前驱
int prev(LinkList &L, ElemType e) {
    for(LinkList last = NULL, tmp = L->next; tmp != NULL; last = tmp, tmp = tmp->next) {
        if(tmp->data == e and last != NULL) {
            return last->data;
        }
    }
    printf("元素不存在！");
    return NOTEXIST;
}

// 求后继
int next(LinkList &L, ElemType e) {
    for(LinkList tmp = L->next; tmp != NULL; tmp = tmp->next) {
        if(tmp->data == e and tmp->next != NULL) {
            return tmp->next->data;
        }
    }
    printf("元素不存在！");
    return NOTEXIST;
}

// 在指定位置插入一个元素
void ListInsert(LinkList &L, int i, ElemType e) {
    if(i < 1 or i > L->len + 1) {
        printf("溢出！");
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

// 删除线性表指定位置元素
void ListDelete(LinkList &L, int i) {
    if(i < 1 or i > L->len) {
        printf("溢出！");
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

// 显示线性表
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