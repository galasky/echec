NAME		=	echecs

CXXFLAGS	=	-I include/ -Wextra -Wall -fpermissive

LDFLAGS		=	-lm

CC		=	g++
RM		=	rm -fv

SRC		=	src/main.cpp		\
			src/serveur.cpp		\
			src/client.cpp		\
			src/my_ia.cpp		\
			src/piece.cpp		\
			src/plateau.cpp		\
			src/arbre.cpp		\
			src/pion.cpp		\
			src/tour.cpp		\
			src/cavalier.cpp	\
			src/fou.cpp		\
			src/roi.cpp		\
			src/reine.cpp		\
			src/rien.cpp

OBJ		=	$(SRC:.cpp=.o)

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CXXFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
