#include <stdio.h>
#include <string.h>
#include "jeu.h"
#include "utils.h"

void init(char mer1[][Longueur], char mer2[][Longueur], char mer3[][Longueur], char mer4[][Longueur], char mer5[][Longueur], char mer6[][Longueur], char mer7[][Longueur], char mer8[][Longueur], char mer9[][Longueur], char mer10[][Longueur], char mer11[][Longueur], char mer12[][Longueur])
{
    init_board(mer1); init_board(mer4);
    init_board(mer2); init_board(mer5);
    init_board(mer3); init_board(mer6);

    init_board(mer7); init_board(mer10);
    init_board(mer8); init_board(mer11);
    init_board(mer9);  init_board(mer12);
}

void saisir_joueur(char mer1[][Longueur], char mer2[][Longueur], char mer3[][Longueur], char nomj[Max_l], int nb)
{
    printf("Entrer votre nom joueur %d : ", nb);
    fflush(stdin);
    fgets(nomj, Max_l, stdin);
    nomj[strcspn(nomj, "\n")] = 0;

    for (int i = 0; i < 3; i++)
    {
        int profondeur;
        do
        {
            printf("Entrer la profondeur du navire %d (0 = fond, 1 = milieu, 2 = surface) : ", i + 1);
            scanf("%d", &profondeur);
        } while (profondeur < 0 || profondeur > 2);

        int taille;
        do
        {
            printf("Entrer la taille du navire : ");
            scanf("%d", &taille);
        } while (taille < 1 || taille > 3);

        remplir_navire(profondeur, taille, mer1, mer2, mer3, 'X');
        printf("\n");
    }
}

/*void tir(char merfc[][Longueur], char merf[][Longueur], char mermc[][Longueur], char merm[][Longueur], char mersc[][Longueur], char mers[][Longueur])
{
    int x, y, pro;

    do {
        printf("Entrer les coordonnées du tir (x y) : ");
        scanf("%d %d", &x, &y);
    } while (x < 0 || x >= Largeur || y < 0 || y >= Longueur);

    do {
        printf("Entrer la profondeur (0 = fond, 1 = milieu, 2 = surface) : ");
        scanf("%d", &pro);
    } while (pro < 0 || pro > 2);

    if (pro == 0)
    {
        if (merfc[x][y] == 'X') merf[x][y] = 'T';
        else merf[x][y] = 'R';
        if (x > 0 && merfc[x-1][y] == 'X') merf[x-1][y] = 'V';
        if (x < Largeur-1 && merfc[x+1][y] == 'X') merf[x+1][y] = 'V';
        if (y > 0 && merfc[x][y-1] == 'X') merf[x][y-1] = 'V';
        if (y < Longueur-1 && merfc[x][y+1] == 'X') merf[x][y+1] = 'V';
        if (mermc[x][y] == 'X' && merm[x][y] != 'V') merm[x][y] = 'V';
        coulee(merf, merfc);
    }
    else if (pro == 1)
    {
        if (mermc[x][y] == 'X') merm[x][y] = 'T';
        else merm[x][y] = 'R';
        if (x > 0 && mermc[x-1][y] == 'X') merm[x-1][y] = 'V';
        if (x < Largeur-1 && mermc[x+1][y] == 'X') merm[x+1][y] = 'V';
        if (y > 0 && mermc[x][y-1] == 'X') merm[x][y-1] = 'V';
        if (y < Longueur-1 && mermc[x][y+1] == 'X') merm[x][y+1] = 'V';
        if (merfc[x][y] == 'X' && merf[x][y] != 'V') merf[x][y] = 'V';
        coulee(merm, mermc);
    }
    else if (pro == 2)
    {
        if (mersc[x][y] == 'X') mers[x][y] = 'T';
        else mers[x][y] = 'R';
        if (x > 0 && mersc[x-1][y] == 'X') mers[x-1][y] = 'V';
        if (x < Largeur-1 && mersc[x+1][y] == 'X') mers[x+1][y] = 'V';
        if (y > 0 && mersc[x][y-1] == 'X') mers[x][y-1] = 'V';
        if (y < Longueur-1 && mersc[x][y+1] == 'X') mers[x][y+1] = 'V';
        if (mermc[x][y] == 'X' && merm[x][y] != 'V') merm[x][y] = 'V';
        coulee(mers, mersc);
    }
}*/

/*int victoire(char mer1[][Longueur], char mer2[][Longueur], char mer3[][Longueur])
{
    for (int i = 0; i < Largeur; i++)
    {
        for (int j = 0; j < Longueur; j++)
        {
            if (mer1[i][j] == 'X' || mer2[i][j] == 'X' || mer3[i][j] == 'X')
            {
                return 0;
            }
        }
    }
    return 1;
}*/

void tir(char merfc[][Longueur], char merf[][Longueur], char mermc[][Longueur], char merm[][Longueur], char mersc[][Longueur], char mers[][Longueur])
{
    int x, y, pro;

    do {
        printf("Entrer les coordonnées du tir (x y) : ");
        scanf("%d %d", &x, &y);
    } while (x < 0 || x >= Largeur || y < 0 || y >= Longueur);

    do {
        printf("Entrer la profondeur (0 = fond, 1 = milieu, 2 = surface) : ");
        scanf("%d", &pro);
    } while (pro < 0 || pro > 2);

    char (*mer_cac)[Longueur];  
    char (*mer)[Longueur];      

    if (pro == 0) {
        mer_cac = merfc;
        mer = merf;
    } else if (pro == 1) {
        mer_cac = mermc;
        mer = merm;
        if(merfc[x][y] == 'X') merf[x][y] = 'V';
    } else {
        mer_cac = mersc;
        mer = mers;
        if(mermc[x][y] == 'X') merm[x][y] = 'V';
    }

    if (mer[x][y] == 'T' || mer[x][y] == 'R') {
        printf("Vous avez déja tirer a cet endroit !\n");
        return;
    }

    if (mer_cac[x][y] == 'X') {
        mer[x][y] = 'T';  
        printf("Point touche!\n");
    }
        
    else {
        mer[x][y] = 'R';  
        printf("Dommage vous avez rate !\n");
    }
    if (x > 0 && mer_cac[x-1][y] == 'X') mer[x-1][y] = 'V';
    if (x < Largeur-1 && mer_cac[x+1][y] == 'X') mer[x+1][y] = 'V';
    if (y > 0 && mer_cac[x][y-1] == 'X') mer[x][y-1] = 'V';        
    if (y < Longueur-1 && mer_cac[x][y+1] == 'X') mer[x][y+1] = 'V';

    coulee(mer, mer_cac);
}
int victoire(char mer1[][Longueur], char mer2[][Longueur], char mer3[][Longueur])
{
    int c = 0;
    for (int i = 0; i < Largeur; i++)
    {
        for (int j = 0; j < Longueur; j++)
        {
            if (mer1[i][j] == 'X' || mer2[i][j] == 'X' || mer3[i][j] == 'X')
            {
                c++;
            }
        }
    }
    return c;
}
