#include <stdio.h>

typedef struct
{
    int coef;
    int expo;
} polynomial;

int lenA, lenB, lenC;

void inputPoly(polynomial a[], polynomial b[])
{
    char ch = 'y';
    int i = 0;
    printf("Enter number of terms of polynomial a: ");
    scanf("%d", &lenA);
    printf("Enter number of terms of polynomial b: ");
    scanf("%d", &lenB);
    // int con = 1;
    printf("Enter polynomials in decreasing order or exponents: ");
    printf("\nPolynomial A:");
    // while(ch == 'y' || ch == 'Y') {
    while (i < lenA)
    {
        printf("\nEnter coefficient of term %d: ", i);
        scanf("%d", &a[i].coef);
        printf("Enter exponent of term %d: ", i);
        scanf("%d", &a[i].expo);
        /*if (a[i].expo == 0)
        {
            printf("Term entered: %d", a[i].coef);
        }
        else if (a[i].expo == 1)
        {
            printf("Term entered: %dx", a[i].coef);
        }
        else
        {
            printf("Term entered: %dx^%d", a[i].coef, a[i].expo);
        }*/
        i = i + 1;
        // printf("\nDo you wish to continue? (y/n): ");
        // printf("\nDo you wish to continue? (0/1): ");
        // scanf("%c", &ch);
        // scanf("%d", &con);
    }
    lenA = i;
    i = 0;
    // con = 1;
    printf("\nPolynomial B:");
    while (i < lenB)
    {
        printf("\nEnter coefficient of term %d: ", i);
        scanf("%d", &b[i].coef);
        printf("Enter exponent of term %d: ", i);
        scanf("%d", &b[i].expo);
        /*if (a[i].expo == 0)
        {
            printf("Term entered: %d", b[i].coef);
        }
        else if (a[i].expo == 1)
        {
            printf("Term entered: %dx", b[i].coef);
        }
        else
        {
            printf("Term entered: %dx^%d", b[i].coef, b[i].expo);
        }*/
        i = i + 1;
        // printf("\nDo you wish to continue? (y/n): ");
        // printf("\nDo you wish to continue? (0/1): ");
        // scanf("%c", &ch);
        // scanf("%d", &con);
    }
    lenB = i;
}

void displayPoly(polynomial s[], int len)
{
    int i = 0;
    // printf("\nPolynomial %c having %d terms is: ", a, len);
    // printf("%c = ", a);
    while (i < len)
    {
        if (s[i].coef < 0 || i == 0)
        {
            if (s[i].expo == 0)
            {
                printf("%d ", s[i].coef);
            }
            else if (s[i].expo == 1)
            {
                printf("%dx ", s[i].coef);
            }
            else
            {
                printf("%dx^%d ", s[i].coef, s[i].expo);
            }
            // printf("%d^%d ");
        }
        else if (s[i].coef > 0)
        {
            if (s[i].expo == 0)
            {
                printf("+%d ", s[i].coef);
            }
            else if (s[i].expo == 1)
            {
                printf("+%dx ", s[i].coef);
            }
            else
            {
                printf("+%dx^%d ", s[i].coef, s[i].expo);
            }
        }
        i = i + 1;
    }
}

void addPoly(polynomial a[], polynomial b[], polynomial c[], int lA, int lB)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int lC = 0;
    while (i < lA && j < lB)
    {
        if (a[i].expo < b[j].expo)
        {
            c[k].coef = b[j].coef;
            c[k].expo = b[j].expo;
            j = j + 1;
            k = k + 1;
            lC = lC + 1;
        }
        else if (a[i].expo > b[j].expo)
        {
            c[k].coef = a[i].coef;
            c[k].expo = a[i].expo;
            i = i + 1;
            k = k + 1;
            lC = lC + 1;
        }
        else
        {
            c[k].coef = a[i].coef + b[j].coef;
            c[k].expo = a[i].expo;
            i = i + 1;
            j = j + 1;
            k = k + 1;
            lC = lC + 1;
        }
    }
    while (i < lA)
    {
        c[k].coef = a[i].coef;
        c[k].expo = a[i].expo;
        i = i + 1;
        k = k + 1;
        lC = lC + 1;
    }
    while (j < lB)
    {
        c[k].coef = b[j].coef;
        c[k].expo = b[j].expo;
        j = j + 1;
        k = k + 1;
        lC = lC + 1;
    }
    // printf("\n\nc = a + b");
    lenC = lC;
    // return lC;
}

void subPoly(polynomial a[], polynomial b[], polynomial c[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    lenC = 0;
    while (i < lenA && j < lenB)
    {
        if (a[i].expo < b[j].expo)
        {
            c[k].coef = -b[j].coef;
            c[k].expo = b[j].expo;
            j = j + 1;
            k = k + 1;
            lenC = lenC + 1;
        }
        else if (a[i].expo > b[j].expo)
        {
            c[k].coef = a[i].coef;
            c[k].expo = a[i].expo;
            i = i + 1;
            k = k + 1;
            lenC = lenC + 1;
        }
        else
        {
            c[k].coef = a[i].coef - b[j].coef;
            c[k].expo = a[i].expo;
            i = i + 1;
            j = j + 1;
            k = k + 1;
            lenC = lenC + 1;
        }
    }
    while (i < lenA)
    {
        c[k].coef = a[i].coef;
        c[k].expo = a[i].expo;
        i = i + 1;
        k = k + 1;
        lenC = lenC + 1;
    }
    while (j < lenB)
    {
        c[k].coef = b[j].coef;
        c[k].expo = b[j].expo;
        j = j + 1;
        k = k + 1;
        lenC = lenC + 1;
    }
    // printf("\n\nc = a - b");
}

void differentiate(polynomial a[], polynomial c[])
{
    int i = 0;
    while (i != lenA)
    {
        c[i].coef = a[i].coef * a[i].expo;
        c[i].expo = a[i].expo - 1;
        i = i + 1;
    }
    lenC = i;
}

void initPoly(polynomial c[])
{
    int i;
    for (i = 0; i < lenC; i++)
    {
        c[i].coef = 0;
        c[i].expo = 0;
    }
}

int copyPoly(polynomial e[], polynomial c[])
{
    int i;
    int lE;
    for (i = 0; i < lenC; i++)
    {
        e[i].coef = c[i].coef;
        e[i].expo = c[i].expo;
        lE = lE + 1;
    }
}

void multiplyPoly(polynomial a[], polynomial b[], polynomial c[])
{
    int i, j, lenE;
    polynomial var, var2;
    polynomial d[20], e[40];
    for (i = 0; i < lenB; i++)
    {
        var = a[i];
        initPoly(d);
        for (j = 0; j < lenA; j++)
        {
            var2 = b[j];
            d[j].coef = var.coef * var2.coef;
            d[j].expo = var.expo + var2.expo;
        }
        // printf("\nd = ");
        // displayPoly(d, lenA);
        // initPoly(e);
        lenE = copyPoly(e, c);
        addPoly(e, d, c, lenE, lenA);
        // printf("\nc = ");
        // displayPoly(c, lenC);
    }
}

int main()
{
    polynomial a[20], b[20], c[40];
    int temp;
    inputPoly(a, b);
    printf("\na = ");
    displayPoly(a, lenA);
    printf("\nb = ");
    displayPoly(b, lenB);
    addPoly(a, b, c, lenA, lenB);
    printf("\na + b = ");
    displayPoly(c, lenC);
    subPoly(a, b, c);
    printf("\na - b = ");
    displayPoly(c, lenC);
    differentiate(a, c);
    printf("\nf'(x) = ");
    displayPoly(c, lenC);
    initPoly(c);
    // printf("\nAfter initializing c\nc = ");
    // displayPoly(c, lenC);
    multiplyPoly(b, a, c);
    printf("\na * b = ");
    displayPoly(c, lenC);
}