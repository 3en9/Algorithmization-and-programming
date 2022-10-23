#include <stdio.h>
#include <windows.h>
#include <math.h>
#define l_max 200

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    printf("Лабораторная работа №2\n");
    printf("Задание №1\n");
    int n, m, k;
    int t;
    do {
        printf("Введите размеры матрицы Z от 1 до %d\n",l_max);
        t = scanf("%d %d",&n,&m);
        while(getchar()!='\n');
    } while (n<=0 || n > l_max || m<=0 || m > l_max || t!=2);
    do {
        printf("Введите длину массива X от 1 до %d\n",l_max);
        t = scanf("%d",&k);
        while(getchar()!='\n');
    } while (k<=0 || k > l_max || t!=1);
    int z[l_max][l_max];
    int x[l_max];
    printf("Введите элементы матрицы Z\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            do {
                t = scanf("%d", &z[i][j]);
            } while (t!=1);
        }
    }
    printf("Введите элементы массива X\n");
    for(int i=1;i<=k;i++) {
        do {
            t = scanf("%d", &x[i]);
        } while (t!=1);
    }
    printf("Вывод матрицы Z\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) printf("%d ", z[i][j]);
        printf("\n");
    }
    printf("Вывод массива X\n");
    for(int i=1;i<=k;i++) printf("%d ",x[i]);
    printf("\n\n");
    int count = 0;
    // находим максимум в каждой строке, проверяем его наличие в массиве
    for(int i=1;i<=n;i++) {
        int maximum = 1;
        for(int j=2;j<=m;j++) {
            if(abs(z[i][j]) > abs(z[i][maximum])) maximum = j;
        }
        char todel = 0;
        int s = 1;
        while(todel==0 && s<=k) {
            if(x[s]==z[i][maximum]) todel = 1;
            s++;
        }
        if(todel == 0) {
            z[i][maximum] = 0;
            count ++;
        }
    }
    if(count!=0) {
        printf("Вывод измененной матрицы\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) printf("%d ", z[i][j]);
            printf("\n");
        }
    }
    else printf("Обнуления не происходило, матрица не изменилась");

    return 0;
}
