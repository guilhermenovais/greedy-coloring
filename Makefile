#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o analisador de coloração gulosa
# Autor		: Guilherme Novais de Souza
# Histórico	: 2023-11-05 arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo e executa o exemplo
#			: make clean - remove objetos e executável
#			: make test - compila tudo e executa o teste com o
#			  valgrind e o gdb
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/grafo.o $(OBJ)/lista.o $(OBJ)/sorting.o $(OBJ)/vertice.o $(OBJ)/main.o
HDRS = $(INC)/grafo.hpp $(INC)/lista.hpp $(INC)/sorting.hpp $(INC)/vertice.hpp
CFLAGS = -c -g -I $(INC)

EXE = $(BIN)/tp2.out

mkdir:
	[ -d obj ] || mkdir obj
	[ -d bin ] || mkdir bin

all: mkdir $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/grafo.o: $(HDRS) $(SRC)/grafo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/grafo.o $(SRC)/grafo.cpp

$(OBJ)/lista.o: $(HDRS) $(SRC)/lista.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/lista.o $(SRC)/lista.cpp

$(OBJ)/sorting.o: $(HDRS) $(SRC)/sorting.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/sorting.o $(SRC)/sorting.cpp

$(OBJ)/vertice.o: $(HDRS) $(SRC)/vertice.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/vertice.o $(SRC)/vertice.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out

run: all
	./bin/tp2.out

test: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/tp2.out < teste.txt
	gdb ./bin/tp2.out