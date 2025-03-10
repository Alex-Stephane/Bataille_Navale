#ifndef JEU_H
#define JEU_H

#include "utils.h"

void init(char mer1[][Longueur], char mer2[][Longueur], char mer3[][Longueur], char mer4[][Longueur], char mer5[][Longueur], char mer6[][Longueur], char mer7[][Longueur], char mer8[][Longueur], char mer9[][Longueur], char mer10[][Longueur], char mer11[][Longueur], char mer12[][Longueur]);
void saisir_joueur(char mer1[][Longueur], char mer2[][Longueur], char mer3[][Longueur], char nomj1[Max_l], int nb);
void tir(char merfc[][Longueur], char merf[][Longueur], char mermc[][Longueur], char merm[][Longueur], char mersc[][Longueur], char mers[][Longueur]);
int victoire(char mer1[][Longueur], char mer2[][Longueur], char mer3[][Longueur]);

#endif // JEU_H