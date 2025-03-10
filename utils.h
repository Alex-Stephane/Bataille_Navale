#ifndef UTILS_H
#define UTILS_H

#define Max_l 20
#define Largeur 5
#define Longueur 10

void init_board(char mer[][Longueur]);
void print_board(char mer[][Longueur]);
void remplir_navire(int profondeur, int taille, char mer1[][Longueur], char mer2[][Longueur], char mer3[][Longueur], char X);
void coulee(char mer[][Longueur], char mer_cac[][Longueur]);

#endif // UTILS_H