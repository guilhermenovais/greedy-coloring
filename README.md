# Greedy Coloring Checker

## About
This project implements an algorithm that receives a graph with a coloring and defines whether or not the coloring of this graph can be obtained using a greedy algorithm. Furthermore, the prerequisite for the problem is to order the vertices of the graph before checking whether or not it is greedy. The sorting methods Bubble sort, Selection sort, Insertion sort, Quick sort, Merge sort, Heap sort and Radix sort were implemented.

## Implementation
The graph was represented using a sequential linear list of vertices, with each vertex also having a sequential linear list with its adjacent vertices.
To check whether the coloring of the graph can be obtained by a greedy algorithm, a method was created at the vertex that checks if there is at least one adjacent vertex that has each of the colors smaller than its own. This way, vertices with a smaller color have a greater probability of finding their smaller colors faster, which justifies the ordering by colors.
For this, a class of static methods called 'Sorting' was implemented, where all methods related to the ordering of the vertices in the list were grouped.

## Instructions to compile and execute
To compile the program, simply run the `make all` command.

To run the program, simply execute the command `./bin/tp2.out < teste.txt`.

To clean the ‘.o’ files and the executable, simply run the `make clean` command.

To run tests with Valgrind and gdb, simply run the `make test` command.
