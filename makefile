#--------------------------------------------------
#---------- Propriété de Ethan et Renato ----------
#--------------------------------------------------

CC=gcc
CFLAGS= -W -Wall
PARAMMATH= -lm
RM=rm -f bin/*.o
srcdir= src/
bindir= bin/
docdir= doc/
SRC=$(wildcard $(srcdir)*.c)
HEAD=$(wildcard $(srcdir)*.h)
OBJ=$(subst $(srcdir), $(bindir), $(SRC:.c=.o))
PROG=Habitation_Location

# Créer l'executable
$(PROG): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ -lm $(PARAMMATH)

# Créer tous les fichiers .o
bin/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

# Supprime les fichiers .o dans bin
.PHONY: clean
clean:
	$(RM)

# Supprime les fichiers .o dans bin et l'exectuable
.PHONY: clean_all
clean_all: clean
	$(RM) $(PROG)

# Lancer le programme
.PHONY: run
run: $(PROG)
	./$(PROG)

# Que peut on faire avec un makefile ?
.PHONY: help
help:
	@echo "make : compile le programme"
	@echo "make run : compile et lance le programme"
	@echo "make clean : supprime les fichiers .o"
	@echo "make clean_all : supprime les fichiers .o et l'exectuable"
	@echo "make help : affiche ce message"