TP_Graphe: main.o graph.o
	g++ -std=c++11 main.o graph.o -o TP_Graphe

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

graph.o: graph.cpp
	g++ -std=c++11 -c graph.cpp

clean:
	rm -f *.o

mrproper: clean
	rm -f TP_Graphe
