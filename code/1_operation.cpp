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
    int len;
    ElemType data[MAXSIZE + 1];
} Vector;

void create(Vector &a) {
    a.len = 0;
    memset(a.data, 0, sizeof(a.data));
}

int main() {
    int x;
    Vector a;
    create(a);
    for(;;) {
        scanf("%d", &x);
        if(x < 0) {
            break;
        }
        if(a.len == MAXSIZE) {
            printf("�Ѿ��������洢��");
            Sleep(1500);
            return 0;
        }
        a.data[++a.len] = x;
    }
    if(!a.len) {
        printf("����Ϊ�գ�");
        Sleep(1500);
        return 0;
    }
    int sum = 0, mi = INT_MAX, mx = INT_MIN;
    for(int i = 1; i <= a.len; ++i) {
        sum += a.data[i];
        mi = min(mi, a.data[i]);
        mx = max(mx, a.data[i]);
    }
    printf("�ܺ�=%d��ƽ��ֵ=%.2lf�����ֵ=%d����Сֵ=%d\n", sum, 1. * sum / a.len, mx, mi);
    Sleep(1500);
    return 0;
}