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

typedef int ElemType; // 元素类型
typedef struct {
    int i; // 行标
    int j; // 列标
    ElemType v; // 存储类型
} Triple;

typedef struct {
    Triple data[MAXSIZE + 1];
    int row; // 行数
    int col; // 列数
    int num; // 非零元素个数
} Matrix;

// 展示
void show() {
    system("cls");
    printf("*****************************************\n");
	printf("*************  1.创建矩阵     ***********\n");
	printf("*************  2.销毁矩阵     ***********\n");
	printf("*************  3.输出矩阵M    ***********\n");
	printf("*************  4.转置矩阵     ***********\n");
	printf("*************  5.快速转置矩阵 ***********\n");
	printf("*************  6.转置矩阵对比 ***********\n");
	printf("*************  7.退出         ***********\n");
	printf("*****************************************\n");
    printf("请输入选择：");
}

// 创建矩阵
void create(Matrix &a) {
    for(;;) {
        printf("请输入矩阵的行数：");
        scanf("%d", &a.row);
        printf("请输入矩阵的列数");
        scanf("%d", &a.col);
        printf("请输入矩阵非零元素的个数");
        scanf("%d", &a.num);
        if(a.num > MAXSIZE or a.num > a.row * a.col or a.row * a.col == 0) {
            printf("矩阵信息输入有误，请重新输入");
            continue;
        }
        break;
    }
    for(int i = 1; i <= a.num; ++i) {
        for(;;) {
            printf("请输入第%d个元素的行标: ", i);
            scanf("%d", &a.data[i].i);
            if(a.data[i].i < a.data[i - 1].i) {
                printf("行标有误，行标需大于0且单调不下降");
                continue;
            }
            if(a.data[i].i > a.row) {
                printf("行标有误，行标需小于行数");
                continue;
            }
            printf("请输入第%d个元素的列标: ", i);
            scanf("%d", &a.data[i].j);
            if(a.data[i].i == a.data[i - 1].i and a.data[i].j < a.data[i - 1].j) {
                printf("列标有误，列标需同行单调不下降");
                continue;
            }
            if(a.data[i].j < 1 or a.data[i].j > a.col) {
                printf("列标有误，列标需大于0，小于等于列数");
                continue;
            }
            printf("请输入第%d个元素的数据: ", i);
            scanf("%d", &a.data[i].v);
            break;
        }
    }
}

// 删除矩阵
void del(Matrix &a) {
    a.col = a.row = a.num = 0;
}

// 输出矩阵
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

// 普通转置算法
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

// 快速转置算法
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

// 展示操作前后的矩阵
void show_transpose_difference(Matrix &a, Matrix &b) {
    printf("操作后的矩阵:\n");
    print(a);
    printf("操作前的矩阵:\n");
    print(b);
}

int main() {
    Matrix a, b; // a为修改后矩阵，b保存修改前的矩阵
    a.row = a.col = a.num = b.row = b.col = b.num = 0;
    memset(a.data, 0, sizeof(a.data));
    memset(b.data, 0, sizeof(b.data));
    for(;;) {
        show();
        int opt;
        scanf("%d", &opt);
        if(1 < opt and opt < 7 and a.row * a.col == 0) {
            printf("矩阵未创建！");
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
                printf("已退出");
                Sleep(1500);
                return 0;
            default:
                printf("不存在该操作数，请重新输入！");
                break;
        }
        Sleep(1500); 
    }
    return 0;
}