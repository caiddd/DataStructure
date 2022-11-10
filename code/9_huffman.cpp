/***
@author: caidd
@edition: C++20
@charset: GBK
@environment: win10 64bit
***/

#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

#define MAXSIZE 27 // �ַ����Ĵ�С
#define READSIZE 100 // �������ַ����ĳ���

typedef int ElemType; // Ԫ������
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *parent, *lchild, *rchild; // ��ָ�룬���Һ���ָ��
}BiTNode, *BiTree;

int weight[MAXSIZE]; // HuffmanTree��Ȩ��
char* code[MAXSIZE]; // HuffmaxTree�ı����
char charset[MAXSIZE]; // HuffmanTree���ַ�����
BiTree leaf[MAXSIZE << 1]; // HuffmanTree�Ľ��

// ����
void show() {
    system("cls");
    printf("1----����HuffmanTree�Ĳ���(����26��ĸ���ո�)\n");
    printf("2----��ʼ��HuffmanTree�Ĳ���\n");
    printf("3----����HuffmanTree�ͱ����\n");
    printf("4----��������\n");
    printf("5----������룬������Ϊ�ַ�\n");
    printf("6----�����ַ�����ʵ��ת��\n");
    printf("7----�˳�\n");
    printf("������ѡ��");
}

char Read() {
    char ch = getchar();
    while(ch != ' ' and (ch < 'a' or ch > 'z')) {
        ch = getchar();
    }
    return ch;
}

// ����HuffmanTree���ַ�����
void InputHuffmanTree() {
    for(int i = 0; i < MAXSIZE; ++i) {
        charset[i] = Read();
    }
}

// ��ʼ��HuffmanTree
void InitHuffmanTree() {
    for(int i = 0; i < MAXSIZE; ++i) {
        scanf("%d", &weight[i]);
        leaf[i] = (BiTree)malloc(sizeof(BiTNode));
        leaf[i]->data = weight[i];
        leaf[i]->lchild = leaf[i]->rchild = leaf[i]->parent = NULL;
    }
}

// ����HuffmanTree�ͱ����
void CreateHuffmanTree() {
    // ����HuffmanTree
    for(int i = MAXSIZE; i < MAXSIZE * 2 - 1; ++i) {
        BiTree a = NULL, b = NULL;
        int Min_a = INT_MAX, Min_b = INT_MAX;
        // ѭ��ѡ��Ȩֵ��С���������
        for(int j = 0; j < i; ++j) {
            if(leaf[j]->parent != NULL) continue; // �ѱ�ѡ
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
    // ���huffman���ĸ���������һ��ָ��

    // ���������
    for(int i = 0; i < MAXSIZE; ++i) {
        int len = 0;
        BiTree tmp = leaf[i];
        leaf[i]->data = (int)charset[i]; // ��ʱȨֵ���ã������洢�ַ�
        code[i] = (char *)malloc(sizeof(char) * MAXSIZE);
        while(tmp->parent != NULL) {
            code[i][len++] = (tmp->parent->rchild == tmp) + '0';
            tmp = tmp->parent;
        }
        code[i][len] = '\0'; // ���Ͻ�����
        // ��ת
        for(int j = 0; j < (len >> 1); ++j) {
            swap(code[i][j], code[i][len - j - 1]);
        }
    }
}

// ��������
void PrintCode() {
    for(int i = 0; i < MAXSIZE; ++i) {
        printf("%c: %s\n", charset[i], code[i]);
    }
}

// ����ת�ַ�
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

// �ַ�ת����
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
                printf("��������룺");
                getchar(); // ��ȡβ���з�
                gets(s);
                DeCode(s);
                break;
            case 6:
                printf("�������ַ���");
                getchar(); // ��ȡβ���з�
                gets(s);
                EnCode(s);
                break;
            case 7:
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