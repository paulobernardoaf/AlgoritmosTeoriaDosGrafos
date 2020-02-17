all: dijkstra bellmanford kruskal prim

dijkstra : ./src/Dijkstra/dijkstra.cpp ./src/Graph.cpp ./include/Graph.hpp
	g++ ./src/Dijkstra/dijkstra.cpp ./src/Graph.cpp -o dijkstra 
	
bellmanford : ./src/BellmanFord/bellmanford.cpp ./src/Graph.cpp ./include/Graph.hpp
	g++ ./src/BellmanFord/bellmanford.cpp ./src/Graph.cpp -o bellmanford 

kruskal : ./src/Kruskal/kruskal.cpp ./src/Graph.cpp ./include/Graph.hpp
	g++ ./src/Kruskal/kruskal.cpp ./src/Graph.cpp -o kruskal 
	
prim : ./src/Prim/prim.cpp ./src/Graph.cpp ./include/Graph.hpp
	g++ ./src/Prim/prim.cpp ./src/Graph.cpp -o prim