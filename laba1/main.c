#include <stdio.h>
#include <windows.h>
#include <math.h>
#define lmax 200

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int n;
    double r[lmax];
    float a,x,h;
    printf("Лабораторная работа №1\n");
    printf("Задание №1\n");
    // Задание 1
    do {
        printf("Введите длину массива R от 1 до %d\n",lmax);
        scanf("%d",&n);
    } while (n<=0 || n > lmax);
    printf("Введите x,h,a:");
    scanf("%f",&x);
    scanf("%f",&h);
    scanf("%f",&a);
    for(int i=1;i<=n;i++) {
        r[i] = 1.25 * sin(3 * a * x - i * h);
    }
    printf("Массив R из %d элементов:\n",n);
    for(int i=1;i<=n;i++) {
        printf("%f ",r[i]);
    }
    printf("\n");
    // Задание 2
    printf("Задание №2\n");
    int m=0;
    for (int i = 1; i <= n; i++) {
        if (!(r[i]>0 && r[i]<i/3.0)) {
            m ++;
            r[m] = r[i];
        }
    }
    int k;
    k = m;
    if(k==0) printf("Удалены все элементы");
    else {
        if(k!=n) {
            printf("Массив R из %d элементов:\n", k);
            for (int i = 1; i <= k; i++) {
                printf("%f ", r[i]);
            }
        }
        else printf("Удаления не происходило");
        printf("\n");
        // Задание №3
        printf("Задание №3\n");
        int last = -1;
        for (int i = 1; i <= k; i++) {
            if (r[i] > 0) last = i;
        }
        if (last != -1) {
            double sum = 0;
            for (int i = last + 1; i <= k; i++) {
                sum += r[i];
            }
            if (sum != 0) {
                double sr = sum / (k - last);
                printf("sr = %f", sr);
            } else {
                printf("После последнего положительного элемента больше нет элементов");
            }
        } else {
            printf("В массиве нет положительных элементов");
        }
    }

    return 0;
}
