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

typedef int ElemType; // 元素类型
typedef struct Node { // 链式队列结点
    ElemType data;
    struct Node *next;
} Node, *LinkNode;
typedef struct { // 链式队列
    int len;
    LinkNode front = NULL; // 队头
    LinkNode rear = NULL; // 队尾
} LinkQueue;

// 界面
void show() {
    system("cls");
    printf("1----初始化队列\n");
    printf("2----销毁队列\n");
    printf("3----清空队列\n");
    printf("4----判断队列是否为空\n");
    printf("5----返回队列中元素个数\n");
    printf("6----返回队列队头元素\n");
    printf("7----插入新的队尾元素\n");
    printf("8----删除队头元素\n");
    printf("9----输出队列元素\n");
    printf("10---退出\n");
    printf("请输入选择：");
}

// 初始化一个队列
void InitQueue(LinkQueue &Q) {
    if(Q.front != NULL) {
        printf("队列已创建");
        return;
    }
    Q.len = 0;
    Q.front = Q.rear = (LinkNode)malloc(sizeof(Node));
    Q.front->next = NULL;
}

// 判断队列是否为空
bool Empty(LinkQueue &Q) {
    return Q.front == Q.rear;
}

// 返回队列中元素个数
int Length(LinkQueue &Q) {
    return Q.len;
}

// 返回队列队头元素
int GetFront(LinkQueue &Q) {
    if(Empty(Q)) {
        printf("队头元素不存在！");
        return NOTEXIST;
    }
    return Q.front->next->data;
}

// 插入新的队尾元素
void Push(LinkQueue &Q, ElemType e) {
    LinkNode tmp = (LinkNode)malloc(sizeof(Node));
    tmp->data = e;
    tmp->next = NULL;
    Q.rear->next = tmp;
    Q.rear = tmp;
    Q.len ++;
}

// 删除队头元素
void Pop(LinkQueue &Q) {
    if(Empty(Q)) {
        printf("队头元素不存在！");
        return;
    }
    LinkNode tmp = Q.front->next;
    Q.front->next = tmp->next;
    if(Q.rear == tmp) {
        Q.rear = Q.front; // 万万注意，否则释放完最后一个元素，队尾指针变为野指针
    }
    Q.len --;
    free(tmp);
}

// 清空队列
void ClearQueue(LinkQueue &Q) {
    while(!Empty(Q)) {
        Pop(Q);
    }
}

// 销毁队列
void DestroyQueue(LinkQueue &Q) {
    ClearQueue(Q);
    free(Q.front);
    Q.front = Q.rear = NULL;
}

// 输出队列元素
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
            printf("队列未创建！");
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
                printf(Empty(Q) ? "队列为空\n" : "队列不为空\n");
                break;
            case 5:
                printf("%d\n", Length(Q));
                break;
            case 6:
                printf("%d\n", GetFront(Q));
                break;
            case 7:
                printf("请输入要插入元素: ");
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