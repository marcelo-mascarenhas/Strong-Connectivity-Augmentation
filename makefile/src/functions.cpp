#include "functions.hpp"



void Functions::readInput(Graph &grafo){
  
  std::string aux_string; int airport_num, route_num, nd1, nd2;
  std::getline(std::cin, aux_string);

  std::stringstream flow(aux_string);

  flow >> airport_num >> route_num;
  
  grafo.fillEmptyGraph(airport_num);

  for(int i = 0; i < route_num; i++){
    std::getline(std::cin, aux_string);
    
    std::stringstream flow2(aux_string);

    flow2 >> nd1 >> nd2;
    nd1--; nd2--;
    
    grafo.addEdge(nd1, nd2);
  }

}
