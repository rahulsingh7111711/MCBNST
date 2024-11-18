#include <stdio.h>
#include <stdlib.h>

int main() {
    float x, u1, u, y;
    int i, j, n, fact;
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    float **a = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++) {
        a[i] = (float *)malloc((n + 1) * sizeof(float));
    }

    printf("Enter values of X:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &a[i][0]);
    }

    printf("Enter values of Y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &a[i][1]);
    }

    printf("Enter the value of x for which you want y: ");
    scanf("%f", &x);


    float h = a[1][0] - a[0][0];
    for (i = 1; i < n; i++) {
        if (a[i][0] - a[i-1][0] != h) {
            printf("Can not perform Newton Forward interpolation as it is not equally spaced.\n");
  
            for (i = 0; i < n; i++) {
                free(a[i]);
            }
            free(a);
            return 1;
        }
    }

    // Find the Difference Table    
    for (j = 2; j <= n; j++) {
        for (i = 0; i < n - j + 1; i++) {
            a[i][j] = a[i + 1][j - 1] - a[i][j - 1];
        }
    }

    // Print the Difference Table
    printf("The Difference Table is as follows:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n - i; j++) {
            printf("%.4f ", a[i][j]);
        }
        printf("\n");
    }

    // Find u
    u = (x - a[0][0]) / h; 
    // Initial y, u1, k
    y = a[0][1];
    u1 = u;
    fact = 1;

    for (i = 2; i <= n; i++) {
        y += (u1 * a[0][i]) / fact;

        fact *= i;
        u1 *= (u - (i - 1));
    }

    printf("\nValue at X = %g is = %.4f\n", x, y);

    // Free allocated memory
    for (i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}
