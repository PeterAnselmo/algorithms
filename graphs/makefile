all: tests bfs kruskal prim
tests: tests.cpp utils.h
	g++ -Wall --std=c++0x -o tests tests.cpp utils.h
bfs: bfs.cpp utils.h
	g++ -Wall --std=c++0x -o bfs bfs.cpp utils.h
kruskal: kruskal.cpp utils.h
	g++ -Wall --std=c++0x -o kruskal kruskal.cpp utils.h
prim: prim.c
	gcc -Wall --std=c99 -o prim prim.c
