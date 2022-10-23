#include <stdio.h>
#include <windows.h>
#include <math.h>
#define l_max 200

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    printf("Лабораторная работа №2\n");
    printf("Задание №2\n");
    int t;
    int k;
    do {
        printf("Введите размеры исходного массива от 1 до %d\n",l_max);
        k = scanf("%d",&t);
        while(getchar()!='\n');
    } while (t<=0 || t > l_max || k!=1);
    int l[l_max];
    printf("Введите иходный массив\n");
    for (int i = 1; i <= t; i++) {
        scanf("%d",&l[i]);
    }
    int r[l_max];
    int j = 1;
    int a,s,tmp,last_digit;
    for(int i=1;i<=t;i++) {
        s = 0;
        a = l[i];
        tmp = 0;
        while(a!=0) {
            last_digit = a % 10;
            if(tmp%2==0) s += last_digit;
            else s-=last_digit;
            tmp++;
            a /= 10;
        }
        if(s==0) {
            r[j] = l[i];
            j++;
        }

    }
    if(j>1) {
        for (int m = 1; m < j; m++) {
            printf("%d ", r[m]);
        }
    }
    else printf("В массиве 0 элементов");

    return 0;
}
