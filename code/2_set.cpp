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
    int len;
    ElemType data[MAXSIZE + 1];
} Vector;

void create(Vector &a) {
    a.len = 0;
    memset(a.data, 0, sizeof(a.data));
}

void check(Vector &a) {
    for(int i = 1; i <= a.len; ++i) {
        for(int j = i + 1; j <= a.len; ++j) {
            if(a.data[i] == a.data[j]) {
                printf("集合元素重复！");
                Sleep(1500);
                exit(0);
            }
        }
    }
}

void print(Vector &a) {
    printf("{ ");
    for(int i = 1; i <= a.len; ++i) {
        printf("%d", a.data[i]);
        if(i != a.len) {
            printf(", ");
        }
    }
    printf(" }\n");
}

int main() {
    Vector a, b;
    create(a);
    create(b);
    int x;
    for(;;) {
        cin >> x;
        if(x < 0) {
            break;
        }
        if(a.len == MAXSIZE) {
            printf("已经超出最大存储！");
            Sleep(1500);
            return 0;
        }
        a.data[++a.len] = x;
    }
    check(a);
    for(;;) {
        cin >> x;
        if(x < 0) {
            break;
        }
        if(b.len == MAXSIZE) {
            printf("已经超出最大存储！");
            Sleep(1500);
            return 0;
        }
        b.data[++b.len] = x;
    }
    check(b);
    Vector c, d, e; // c存交集，d存并集，e存差
    create(c);
    create(d);
    create(e);
    
    for(int i = 1; i <= a.len; ++i) {
        for(int j = 1; j <= b.len; ++j) {
            if(a.data[i] == b.data[j]) {
                c.data[++c.len] = a.data[i];
                break;
            }
        }
    }
    
    d = c;
    for(int i = 1; i <= a.len; ++i) {
        bool tag = true;
        for(int j = 1; j <= c.len; ++j) {
            if(a.data[i] == c.data[j]) {
                tag = false;
                break;
            }
        }
        if(tag) {
            e.data[++e.len] = a.data[i];
            d.data[++d.len] = a.data[i];
        }
    }

    for(int i = 1; i <= b.len; ++i) {
        bool tag = true;
        for(int j = 1; j <= c.len; ++j) {
            if(b.data[i] == c.data[j]) {
                tag = false;
                break;
            }
        }
        if(tag) {
            d.data[++d.len] = b.data[i];
        }
    }

    printf("A交B = ");
    print(c);
    printf("A并B = ");
    print(d);
    printf("A - B = ");
    print(e);
    Sleep(1500);
    return 0;
}