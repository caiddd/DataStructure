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

typedef int ElemType; // Ԫ������
typedef struct {
    int i; // �б�
    int j; // �б�
    ElemType v; // �洢����
} Triple;

typedef struct {
    Triple data[MAXSIZE + 1];
    int row; // ����
    int col; // ����
    int num; // ����Ԫ�ظ���
} Matrix;

// չʾ
void show() {
    system("cls");
    printf("*****************************************\n");
	printf("*************  1.��������     ***********\n");
	printf("*************  2.���پ���     ***********\n");
	printf("*************  3.�������M    ***********\n");
	printf("*************  4.ת�þ���     ***********\n");
	printf("*************  5.����ת�þ��� ***********\n");
	printf("*************  6.ת�þ���Ա� ***********\n");
	printf("*************  7.�˳�         ***********\n");
	printf("*****************************************\n");
    printf("������ѡ��");
}

// ��������
void create(Matrix &a) {
    for(;;) {
        printf("����������������");
        scanf("%d", &a.row);
        printf("��������������");
        scanf("%d", &a.col);
        printf("������������Ԫ�صĸ���");
        scanf("%d", &a.num);
        if(a.num > MAXSIZE or a.num > a.row * a.col or a.row * a.col == 0) {
            printf("������Ϣ������������������");
            continue;
        }
        break;
    }
    for(int i = 1; i <= a.num; ++i) {
        for(;;) {
            printf("�������%d��Ԫ�ص��б�: ", i);
            scanf("%d", &a.data[i].i);
            if(a.data[i].i < a.data[i - 1].i) {
                printf("�б������б������0�ҵ������½�");
                continue;
            }
            if(a.data[i].i > a.row) {
                printf("�б������б���С������");
                continue;
            }
            printf("�������%d��Ԫ�ص��б�: ", i);
            scanf("%d", &a.data[i].j);
            if(a.data[i].i == a.data[i - 1].i and a.data[i].j < a.data[i - 1].j) {
                printf("�б������б���ͬ�е������½�");
                continue;
            }
            if(a.data[i].j < 1 or a.data[i].j > a.col) {
                printf("�б������б������0��С�ڵ�������");
                continue;
            }
            printf("�������%d��Ԫ�ص�����: ", i);
            scanf("%d", &a.data[i].v);
            break;
        }
    }
}

// ɾ������
void del(Matrix &a) {
    a.col = a.row = a.num = 0;
}

// �������
void print(Matrix &a) {
    int now = 1;
    for(int i = 1; i <= a.row; ++i) {
        for(int j = 1; j <= a.col; ++j) {
            if(a.data[now].i == i and a.data[now].j == j) {
                printf("%d ", a.data[now].v);
                ++now;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// ��ͨת���㷨
void transpose(Matrix &a, Matrix &b) {
    b.num = 0;
    b.col = a.row;
    b.row = a.col;
    for(int i = 1; i <= a.col; ++i) {
        for(int j = 1; j <= a.num; ++j) {
            if(a.data[j].j == i) {
                b.data[++b.num] = a.data[j];
                swap(b.data[b.num].i, b.data[b.num].j);
            }
        }
    }
    swap(a, b);
}

// ����ת���㷨
void quick_transpose(Matrix &a, Matrix &b) {
    b.col = a.row;
    b.row = a.col;
    b.num = a.num;
    int col[a.col + 1] = {0};
    for(int i = 1; i <= a.num; ++i) {
        col[a.data[i].j] ++;
    }
    for(int i = 1; i <= a.col; ++i) {
        col[i] += col[i - 1];
    }
    for(int i = 1; i <= a.num; ++i) {
        int index = col[a.data[i].j - 1] + 1;
        b.data[index] = a.data[i];
        swap(b.data[index].i, b.data[index].j);
        ++col[a.data[i].j - 1];
    }
    swap(a, b);
}

// չʾ����ǰ��ľ���
void show_transpose_difference(Matrix &a, Matrix &b) {
    printf("������ľ���:\n");
    print(a);
    printf("����ǰ�ľ���:\n");
    print(b);
}

int main() {
    Matrix a, b; // aΪ�޸ĺ����b�����޸�ǰ�ľ���
    a.row = a.col = a.num = b.row = b.col = b.num = 0;
    memset(a.data, 0, sizeof(a.data));
    memset(b.data, 0, sizeof(b.data));
    for(;;) {
        show();
        int opt;
        scanf("%d", &opt);
        if(1 < opt and opt < 7 and a.row * a.col == 0) {
            printf("����δ������");
            Sleep(1500);
            continue;
        }
        switch (opt) {
            case 1:
                create(a);
                break;
            case 2:
                del(a);
                break;
            case 3:
                print(a);
                break;
            case 4:
                transpose(a, b);
                break;
            case 5:
                quick_transpose(a, b);
                break;
            case 6:
                show_transpose_difference(a, b);
                break;
            case 7:
                printf("���˳�");
                Sleep(1500);
                return 0;
            default:
                printf("�����ڸò����������������룡");
                break;
        }
        Sleep(1500); 
    }
    return 0;
}