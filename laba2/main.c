#include <stdio.h>
#include <windows.h>
#include <math.h>
#define l_max 200

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    printf("Лабораторная работа №2\n");
    printf("Доп.задание\n");
    int n, m;
    int t;
    do {
        printf("Введите размеры матрицы Z от 1 до %d\n",l_max);
        t = scanf("%d %d",&n,&m);
        while(getchar()!='\n');
    } while (n<=0 || n > l_max || m<=0 || m > l_max || t!=2);
    int z[l_max][l_max];
    printf("Введите элементы матрицы Z\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            do {
                t = scanf("%d", &z[i][j]);
            } while (t!=1);
        }
    }

    for(int j=1;j<=m;j++) {
        char to_sort = 1;
        int s = 1;
        while(s<=n && to_sort!=0) {
            if(z[s][j]==0) to_sort = 0;
            s++;
        }
        if(to_sort==1) {
            for (int i = 1; i < n; i++) {
                for (int k = i + 1; k <= n; k++) {
                    if (z[i][j] < z[k][j]) {
                        int tmp = z[i][j];
                        z[i][j] = z[k][j];
                        z[k][j] = tmp;
                    }
                }
            }
        }
    }
    printf("Вывод матрицы Z\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) printf("%d ", z[i][j]);
        printf("\n");
    }


    return 0;
}
