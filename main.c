#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "utils.h"

int main()
{
    int choix;
    int temp2;

    char mer_surfacej1[Largeur][Longueur]; char mer_surfacecacj1[Largeur][Longueur];
    char mer_milieuj1[Largeur][Longueur]; char mer_milieucacj1[Largeur][Longueur];
    char mer_fondj1[Largeur][Longueur]; char mer_fondcacj1[Largeur][Longueur];

    char mer_surfacej2[Largeur][Longueur]; char mer_surfacecacj2[Largeur][Longueur];
    char mer_milieuj2[Largeur][Longueur]; char mer_milieucacj2[Largeur][Longueur];
    char mer_fondj2[Largeur][Longueur]; char mer_fondcacj2[Largeur][Longueur];

    char nomj1[Max_l], nomj2[Max_l];

    do
    {
        printf(" 1 : Faire une partie en local\n");
        printf(" 2 : Faire une partie en ligne\n");
        printf(" 3 : Sauvegarder une partie\n");
        printf(" 4 : Charger une partie\n");
        printf(" 0 : Quitter\n");
        printf("Entrer votre choix : ");
        do {
            scanf("%d", &choix);
        } while (choix < 0 || choix > 1);

        switch (choix)
        {
            case 1:
                init(mer_fondcacj1, mer_fondcacj2, mer_fondj1, mer_fondj2, mer_milieucacj1, mer_milieucacj2, mer_milieuj1, mer_milieuj2, mer_surfacecacj1, mer_surfacecacj2, mer_surfacej1, mer_surfacej2);

                saisir_joueur(mer_fondcacj1, mer_milieucacj1, mer_surfacecacj1, nomj1, 1);
                printf("Enregistrement des coordonnees du joueur 1 effectué\n");
                print_board(mer_surfacecacj1);
                print_board(mer_milieucacj1);
                print_board(mer_fondcacj1);
                printf("Taper un chiffre pour enregistrer le second joueur\n");
                scanf("%d",&temp2);
                system("cls");

                saisir_joueur(mer_fondcacj2, mer_milieucacj2, mer_surfacecacj2, nomj2, 2);
                printf("Enregistrement des coordonnees du joueur 2 effectué\n");
                print_board(mer_surfacecacj2);
                print_board(mer_milieucacj2);
                print_board(mer_fondcacj2);
                printf("Taper un chiffre pour commencer a jouer\n");
                scanf("%d",&temp2);
                system("cls");

            
                do
                {   
                    printf("%s a vous de jouer \n",nomj1);
                    tir(mer_fondcacj2, mer_fondj2, mer_milieucacj2, mer_milieuj2, mer_surfacecacj2, mer_surfacej2);
                    printf("Vous avez tire sur \n");
                    printf("Surface j2\n");
                    print_board(mer_surfacej2);
                    print_board(mer_milieuj2);
                    print_board(mer_fondj2);

                    printf("%s a vous de jouer",nomj2);
                    tir(mer_fondcacj1, mer_fondj1, mer_milieucacj1, mer_milieuj1, mer_surfacecacj1, mer_surfacej1);
                    printf("Surface j1\n");
                    print_board(mer_surfacej1);
                    print_board(mer_milieuj1);
                    print_board(mer_fondj1);
                }while (victoire(mer_fondj1, mer_milieuj1, mer_surfacej1) != 6 && victoire(mer_fondj2, mer_milieuj2, mer_surfacej2) != 6 );


                if (victoire(mer_fondj1, mer_milieuj1, mer_surfacej1) == 6)
                {
                    printf("%s a gagné!\n", nomj1);
                }
                if (victoire(mer_fondj2, mer_milieuj2, mer_surfacej2) == 6)
                {                
                    printf("%s a gagné!\n", nomj2);
                }

                break;

            case 2:
                break;

            default:
                break;
        }
    } while (choix != 0);

    return 0;
}