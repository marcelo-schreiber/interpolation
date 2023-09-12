PROJ_NAME=interpola
 
# .c files
C_SOURCE=$(wildcard *.c)
 
# .h files
H_SOURCE=$(wildcard *.h)
 
# Object files
OBJ=$(C_SOURCE:.c=.o)
 
# Compiler
CC=gcc
 
# Flags for compiler
CC_FLAGS=-c         \
         -Wall      \
 
DISTFILES = *.c *.h README* Makefile
DISTDIR = `basename ${PWD}`

#
# Compilation and linking
#
all: $(PROJ_NAME)
 
$(PROJ_NAME): $(OBJ)
		$(CC) -o $@ $^
 
%.o: %.c %.h
		$(CC) -o $@ $< $(CC_FLAGS) -lm
 
main.o: main.c $(H_SOURCE)
		$(CC) -o $@ $< $(CC_FLAGS)
 
clean:
		@echo "Limpando sujeira ..."
		@rm -f *~ *.bak

purge:  clean
		@echo "Limpando tudo ..."
		@rm -f $(PROG) *.o core a.out interpola $(DISTDIR) $(DISTDIR).tar

dist: purge
		@echo "Gerando arquivo de distribuição ($(DISTDIR).tar) ..."
		@ln -s . $(DISTDIR)
		@tar -cvf $(DISTDIR).tar $(addprefix ./$(DISTDIR)/, $(DISTFILES))
		@rm -f $(DISTDIR)

.PHONY: all clean purge dist