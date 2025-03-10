#include "utils.h"
#include <stdio.h>

void init_board(char mer[][Longueur])
{
    for (int i = 0; i < Largeur; i++)
    {
        for (int j = 0; j < Longueur; j++)
            mer[i][j] = ' ';
    }
}

#include <stdio.h>

#define RESET   "\x1b[0m"
#define BLUE_BG "\x1b[44m"  // Fond bleu pour l'eau
#define RED_BG  "\x1b[41m"  // Fond rouge pour tir réussi
#define YELLOW_BG "\x1b[43m" // Fond jaune pour tir manqué
#define GREEN_BG "\x1b[42m" // Fond vert pour navire coulé
#define WHITE_BG "\x1b[47m" // Fond blanc pour les autres cas

void print_board(char mer[][Longueur])
{
    printf("   ");
    for (int i = 0; i < Longueur; i++)
        printf(" %d  ", i);
    printf("\n   ---+---+---+---+---+---+---+---+---+---\n");

    for (int i = 0; i < Largeur; i++)
    {
        printf("%d |", i);
        for (int j = 0; j < Longueur; j++)
        {
            if (mer[i][j] == ' ') {
                printf(BLUE_BG "   " RESET);
            } else if (mer[i][j] == 'X') {
                printf(RED_BG " X " RESET);
            } else if (mer[i][j] == 'O') {
                printf(YELLOW_BG " O " RESET);
            } else if (mer[i][j] == 'C') {
                printf(GREEN_BG " C " RESET);
            } else {
                printf(WHITE_BG " %c " RESET);
            }
            printf("|");
        }
        printf("\n   ---+---+---+---+---+---+---+---+---+---\n");
    }
    printf("\n");
}


void remplir_navire(int profondeur, int taille, char mer1[][Longueur], char mer2[][Longueur], char mer3[][Longueur], char X)
{
    int x, y;
    do {
        printf("Entrer les coordonnées du navire (x y) : ");
        scanf("%d %d", &x, &y);
    } while (x < 0 || x >= Largeur || y < 0 || y >= Longueur);

    int orientation = 0;
    if (taille > 1)
    {
        do {
            printf("Entrer l'orientation du navire (0 = vertical, 1 = horizontal) : ");
            scanf("%d", &orientation);
        } while (orientation < 0 || orientation > 1);
    }

    if (profondeur == 0)
    {
        if (taille == 1)
        {
            mer1[x][y] = X;
        }
        else if (taille == 2)
        {
            if (orientation == 0)
            {
                if (x <= Largeur - 2)
                {
                    mer1[x][y] = X;
                    mer1[x + 1][y] = X;
                }
                else
                {
                    mer1[x][y] = X;
                    mer1[x - 1][y] = X;
                }
            }
            else
            {
                if (y <= Longueur - 2)
                {
                    mer1[x][y] = X;
                    mer1[x][y + 1] = X;
                }
                else
                {
                    mer1[x][y] = X;
                    mer1[x][y - 1] = X;
                }
            }
        }
        else if (taille == 3)
        {
            if (orientation == 0)
            {
                if (x <= Largeur - 3)
                {
                    mer1[x][y] = X;
                    mer1[x + 1][y] = X;
                    mer1[x + 2][y] = X;
                }
                else
                {
                    mer1[x][y] = X;
                    mer1[x - 1][y] = X;
                    mer1[x - 2][y] = X;
                }
            }
            else
            {
                if (y <= Longueur - 3)
                {
                    mer1[x][y] = X;
                    mer1[x][y + 1] = X;
                    mer1[x][y + 2] = X;
                }
                else
                {
                    mer1[x][y] = X;
                    mer1[x][y - 1] = X;
                    mer1[x][y - 2] = X;
                }
            }
        }
    }

    if (profondeur == 1)
    {
        if (taille == 1)
        {
            mer2[x][y] = X;
        }
        else if (taille == 2)
        {
            if (orientation == 0)
            {
                if (x <= Largeur - 2)
                {
                    mer2[x][y] = X;
                    mer2[x + 1][y] = X;
                }
                else
                {
                    mer2[x][y] = X;
                    mer2[x - 1][y] = X;
                }
            }
            else
            {
                if (y <= Longueur - 2)
                {
                    mer2[x][y] = X;
                    mer2[x][y + 1] = X;
                }
                else
                {
                    mer2[x][y] = X;
                    mer2[x][y - 1] = X;
                }
            }
        }
        else if (taille == 3)
        {
            if (orientation == 0)
            {
                if (x <= Largeur - 3)
                {
                    mer2[x][y] = X;
                    mer2[x + 1][y] = X;
                    mer2[x + 2][y] = X;
                }
                else
                {
                    mer2[x][y] = X;
                    mer2[x - 1][y] = X;
                    mer2[x - 2][y] = X;
                }
            }
            else
            {
                if (y <= Longueur - 3)
                {
                    mer2[x][y] = X;
                    mer2[x][y + 1] = X;
                    mer2[x][y + 2] = X;
                }
                else
                {
                    mer2[x][y] = X;
                    mer2[x][y - 1] = X;
                    mer2[x][y - 2] = X;
                }
            }
        }
    }

    if (profondeur == 2)
    {
        if (taille == 1)
        {
            mer3[x][y] = X;
        }
        else if (taille == 2)
        {
            if (orientation == 0)
            {
                if (x <= Largeur - 2)
                {
                    mer3[x][y] = X;
                    mer3[x + 1][y] = X;
                }
                else
                {
                    mer3[x][y] = X;
                    mer3[x - 1][y] = X;
                }
            }
            else
            {
                if (y <= Longueur - 2)
                {
                    mer3[x][y] = X;
                    mer3[x][y + 1] = X;
                }
                else
                {
                    mer3[x][y] = X;
                    mer3[x][y - 1] = X;
                }
            }
        }
        else if (taille == 3)
        {
            if (orientation == 0)
            {
                if (x <= Largeur - 3)
                {
                    mer3[x][y] = X;
                    mer3[x + 1][y] = X;
                    mer3[x + 2][y] = X;
                }
                else
                {
                    mer3[x][y] = X;
                    mer3[x - 1][y] = X;
                    mer3[x - 2][y] = X;
                }
            }
            else
            {
                if (y <= Longueur - 3)
                {
                    mer3[x][y] = X;
                    mer3[x][y + 1] = X;
                    mer3[x][y + 2] = X;
                }
                else
                {
                    mer3[x][y] = X;
                    mer3[x][y - 1] = X;
                    mer3[x][y - 2] = X;
                }
            }
        }
    }
}

void coulee(char mer[][Longueur], char mer_cac[][Longueur])
{
    for (int i = 0; i < Largeur; i++)
    {
        for (int j = 0; j < Longueur; j++)
        {
            if (mer_cac[i][j] == 'X')
            {
                int coule = 1;
                if (i > 0 && mer_cac[i-1][j] == 'X' && mer[i-1][j] != 'T') coule = 0;
                if (i < Largeur-1 && mer_cac[i+1][j] == 'X' && mer[i+1][j] != 'T') coule = 0;
                if (j > 0 && mer_cac[i][j-1] == 'X' && mer[i][j-1] != 'T') coule = 0;
                if (j < Longueur-1 && mer_cac[i][j+1] == 'X' && mer[i][j+1] != 'T') coule = 0;

                if (coule)
                {
                    mer[i][j] = 'C';
                    if (i > 0 && mer_cac[i-1][j] == 'X') mer[i-1][j] = 'C';
                    if (i < Largeur-1 && mer_cac[i+1][j] == 'X') mer[i+1][j] = 'C';
                    if (j > 0 && mer_cac[i][j-1] == 'X') mer[i][j-1] = 'C';
                    if (j < Longueur-1 && mer_cac[i][j+1] == 'X') mer[i][j+1] = 'C';
                }
            }
        }
    }
}