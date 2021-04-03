OBJS	= options.o grille.o jeux.o main.o souris_jeux.o ia_jeux.o menu.o verification.o bouton.o
SRC	= %(willcard*.c)
OUT	= blocus
CC	 = gcc	
FLAGS	 = -g -c 
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS) -lgraph

options.o: options.c
	$(CC) $(FLAGS) options.c 

grille.o: grille.c
	$(CC) $(FLAGS) grille.c 

jeux.o: jeux.c
	$(CC) $(FLAGS) jeux.c 

main.o: main.c
	$(CC) $(FLAGS) main.c 

souris_jeux.o: souris_jeux.c
	$(CC) $(FLAGS) souris_jeux.c 

ia_jeux.o: ia_jeux.c
	$(CC) $(FLAGS) ia_jeux.c 

menu.o: menu.c
	$(CC) $(FLAGS) menu.c 

verification.o: verification.c
	$(CC) $(FLAGS) verification.c 

bouton.o: bouton.c
	$(CC) $(FLAGS) bouton.c 


clean:
	rm -f $(OBJS) $(OUT) 
