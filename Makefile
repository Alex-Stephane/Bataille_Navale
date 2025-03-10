# Compiler
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -I.

# Fichiers objets
OBJ = main.o jeu.o utils.o

# Nom de l'exécutable
EXEC = bataille_navale

# Règle par défaut
all: $(EXEC)

# Règle pour créer l'exécutable
$(EXEC): $(OBJ)
    $(CC) $(OBJ) -o $(EXEC)

# Règle pour compiler main.c
main.o: main.c jeu.h utils.h
    $(CC) $(CFLAGS) -c main.c

# Règle pour compiler jeu.c
jeu.o: jeu.c jeu.h utils.h
    $(CC) $(CFLAGS) -c jeu.c

# Règle pour compiler utils.c
utils.o: utils.c utils.h
    $(CC) $(CFLAGS) -c utils.c

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
    rm -f $(OBJ) $(EXEC)