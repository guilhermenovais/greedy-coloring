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
OBJS = $(OBJ)/grafo.o $(OBJ)/lista_encadeada.o $(OBJ)/sorting.o $(OBJ)/tipo_celula.o $(OBJ)/vertice.o $(OBJ)/main.o
HDRS = $(INC)/grafo.hpp $(INC)/lista_encadeada.hpp $(INC)/sorting.hpp $(INC)/tipo_celula.hpp $(INC)/vertice.hpp
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

$(OBJ)/lista_encadeada.o: $(HDRS) $(SRC)/lista_encadeada.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/lista_encadeada.o $(SRC)/lista_encadeada.cpp

$(OBJ)/sorting.o: $(HDRS) $(SRC)/sorting.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/sorting.o $(SRC)/sorting.cpp

$(OBJ)/tipo_celula.o: $(HDRS) $(SRC)/tipo_celula.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tipo_celula.o $(SRC)/tipo_celula.cpp

$(OBJ)/vertice.o: $(HDRS) $(SRC)/vertice.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/vertice.o $(SRC)/vertice.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out

run: all
	./bin/tp2.out

test: all
	valgrind --leak-check=full --show-leak-kinds=all ./bin/tp2.out < teste.txt
	gdb ./bin/tp2.out