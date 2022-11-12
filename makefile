#--------------------------------------------------
#---------- Propriété de Ethan et Renato ----------
#--------------------------------------------------

CC=gcc
CFLAGS= -W -Wall
RM=rm -f bin/*.o
srcdir= src/
bindir= bin/
docdir= doc/
SRC=$(wildcard $(srcdir)*.c)
HEAD=$(wildcard $(srcdir)*.h)
OBJ=$(subst $(srcdir), $(bindir), $(SRC:.c=.o))
PROG=habitationLocation

$(PROG): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Créer tous les fichiers .o
bin/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

# Supprime les fichiers .o dans bin
.PHONY: clean
clean:
	$(RM)