/**
* @file anuj.c
* @brief  This program basically creates a student database system students is the struct which has the data
*   There are functions to insert node delete them sort them by name and print functions mainly also there is a queue which stores unsused roll no.
*
* @author Anuj Gupta
* @date 31/07/2019
*/

#include <stdio.h>
#include <stdlib.h>

/**
* @brief returns pixel values
*/
void pixelValue(int x, int y, int **r, int **b, int **g)
{
    printf("At (%d,%d):\n", x, y);
    printf("Red=%d, Blue=%d, Green=%d", r[x - 1][y - 1], b[x - 1][y - 1], g[x - 1][y - 1]);
}

/**
* @brief removes red
*/
void remred(int **r, int **b, int **g)
{
    for (int i = 0; i < 953; i++)
    {
        for (int j = 0; j < 1268; j++)
        {
            if ((r[i][j] > b[i][j]) && (r[i][j] > g[i][j]))
                r[i][j] = 0;
        }
    }
}

/**
* @brief removes green
*/
void remgreen(int **r, int **b, int **g)
{
    for (int i = 0; i < 953; i++)
    {
        for (int j = 0; j < 1268; j++)
        {
            if ((g[i][j] > b[i][j]) && (g[i][j] > r[i][j]))
                g[i][j] = 0;
        }
    }
}

/**
* @brief removes blue
*/
void remblue(int **r, int **b, int **g)
{
    for (int i = 0; i < 953; i++)
    {
        for (int j = 0; j < 1268; j++)
        {
            if ((b[i][j] > r[i][j]) && (b[i][j] > g[i][j]))
                b[i][j] = 0;
        }
    }
}

/**
* @brief preserves red
*/
void redon(int **r, int **b, int **g)
{
    remblue(r, b, g);
    remgreen(r, b, g);
}

/**
* @brief preserves blue only
*/
void blueon(int **r, int **b, int **g)
{
    remred(r, b, g);
    remgreen(r, b, g);
}

/**
* @brief preserves green only
*/
void greenon(int **r, int **b, int **g)
{
    remblue(r, b, g);
    remred(r, b, g);
}

int main()
{
    FILE *ri, *bi, *gi, *ro, *bo, *go;
    ri = fopen("Q3_ip_Red.dat", "r");
    gi = fopen("Q3_ip_Green.dat", "r");
    bi = fopen("Q3_ip_Blue.dat", "r");
    ro = fopen("Q3_op1_Red.dat", "w");
    bo = fopen("Q3_op1_Blue.dat", "w");
    go = fopen("Q3_op1_Green.dat", "w");
    int row = 953;
    int column = 1268;
    int **r = (int *)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
        r[i] = (int *)malloc(column * sizeof(int));
    int **b = (int *)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
        b[i] = (int *)malloc(column * sizeof(int));
    int **g = (int *)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
        g[i] = (int *)malloc(column * sizeof(int));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            fscanf(ri, "%d,", &r[i][j]);
            fscanf(bi, "%d,", &b[i][j]);
            fscanf(gi, "%d,", &g[i][j]);
        }
    }
    greenon(r, b, g);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            fprintf(ro, "%d,", r[i][j]);
            fprintf(bo, "%d,", b[i][j]);
            fprintf(go, "%d,", g[i][j]);
        }
        fprintf(ro, "\n");
        fprintf(bo, "\n");
        fprintf(go, "\n");
    }

    pixelValue(320, 650, r, b, g);
     pixelValue(21,122, r, b, g);
     pixelValue(550,1190, r, b, g);
    return 0;
}

