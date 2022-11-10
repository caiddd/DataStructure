/***
@author: caidd
@edition: C++20
@charset: GBK
@environment: win10 64bit
***/

#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

#define MAXSIZE 27 // 字符集的大小
#define READSIZE 100 // 最多读入字符串的长度

typedef int ElemType; // 元素类型
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *parent, *lchild, *rchild; // 父指针，左、右孩子指针
}BiTNode, *BiTree;

int weight[MAXSIZE]; // HuffmanTree的权重
char* code[MAXSIZE]; // HuffmaxTree的编码表
char charset[MAXSIZE]; // HuffmanTree的字符参数
BiTree leaf[MAXSIZE << 1]; // HuffmanTree的结点

// 界面
void show() {
    system("cls");
    printf("1----输入HuffmanTree的参数(含有26字母及空格)\n");
    printf("2----初始化HuffmanTree的参数\n");
    printf("3----创建HuffmanTree和编码表\n");
    printf("4----输出编码表\n");
    printf("5----输入编码，并翻译为字符\n");
    printf("6----输入字符，并实现转码\n");
    printf("7----退出\n");
    printf("请输入选择：");
}

char Read() {
    char ch = getchar();
    while(ch != ' ' and (ch < 'a' or ch > 'z')) {
        ch = getchar();
    }
    return ch;
}

// 输入HuffmanTree的字符参数
void InputHuffmanTree() {
    for(int i = 0; i < MAXSIZE; ++i) {
        charset[i] = Read();
    }
}

// 初始化HuffmanTree
void InitHuffmanTree() {
    for(int i = 0; i < MAXSIZE; ++i) {
        scanf("%d", &weight[i]);
        leaf[i] = (BiTree)malloc(sizeof(BiTNode));
        leaf[i]->data = weight[i];
        leaf[i]->lchild = leaf[i]->rchild = leaf[i]->parent = NULL;
    }
}

// 创建HuffmanTree和编码表
void CreateHuffmanTree() {
    // 创建HuffmanTree
    for(int i = MAXSIZE; i < MAXSIZE * 2 - 1; ++i) {
        BiTree a = NULL, b = NULL;
        int Min_a = INT_MAX, Min_b = INT_MAX;
        // 循环选出权值最小的两个结点
        for(int j = 0; j < i; ++j) {
            if(leaf[j]->parent != NULL) continue; // 已被选
            if(leaf[j]->data < Min_a) {
                b = a, Min_b = Min_a;
                a = leaf[j], Min_a = a->data;
            } else if(leaf[j]->data < Min_b) {
                b = leaf[j], Min_b = b->data;
            }
        }
        leaf[i] = (BiTree)malloc(sizeof(BiTNode));
        leaf[i]->data = a->data + b->data;
        leaf[i]->lchild = a;
        leaf[i]->rchild = b;
        a->parent = leaf[i];
        b->parent = leaf[i];
        leaf[i]->parent = NULL;
    }
    // 最后huffman树的根结点是最后一个指针

    // 创建编码表
    for(int i = 0; i < MAXSIZE; ++i) {
        int len = 0;
        BiTree tmp = leaf[i];
        leaf[i]->data = (int)charset[i]; // 此时权值无用，用来存储字符
        code[i] = (char *)malloc(sizeof(char) * MAXSIZE);
        while(tmp->parent != NULL) {
            code[i][len++] = (tmp->parent->rchild == tmp) + '0';
            tmp = tmp->parent;
        }
        code[i][len] = '\0'; // 补上结束符
        // 翻转
        for(int j = 0; j < (len >> 1); ++j) {
            swap(code[i][j], code[i][len - j - 1]);
        }
    }
}

// 输出编码表
void PrintCode() {
    for(int i = 0; i < MAXSIZE; ++i) {
        printf("%c: %s\n", charset[i], code[i]);
    }
}

// 编码转字符
void DeCode(char *s) {
    int len = strlen(s);
    for(int i = 0; i < len; ) {
        BiTree root = leaf[MAXSIZE * 2 - 2];
        for(; root->lchild != NULL; ++i) {
            root = (s[i] == '0' ? root->lchild : root->rchild);
        }
        printf("%c", (char)root->data);
    }
};

// 字符转编码
void EnCode(char *s) {
    int len = strlen(s);
    for(int i = 0; i < len; ++i) {
        for(int j = 0; j < MAXSIZE; ++j) {
            if(charset[j] == s[i]) {
                printf("%s", code[j]);
                break;
            }
        }
    }
}

int main() {
    char s[READSIZE];
    for(;;) {
        show();
        int opt;
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                InputHuffmanTree();
                break;
            case 2:
                InitHuffmanTree();
                break;
            case 3:
                CreateHuffmanTree();
                break;
            case 4:
                PrintCode();
                break;
            case 5:
                printf("请输入编码：");
                getchar(); // 读取尾换行符
                gets(s);
                DeCode(s);
                break;
            case 6:
                printf("请输入字符：");
                getchar(); // 读取尾换行符
                gets(s);
                EnCode(s);
                break;
            case 7:
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