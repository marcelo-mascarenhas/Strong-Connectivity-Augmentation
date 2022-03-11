#include <iostream>
#include <vector>


#include "functions.hpp"
#include "graph.hpp"


int main(int argc, char* argv[]){
  
  Graph graph; Functions calls;

  calls.readInput(graph); graph.kosaraju();

  int answer = graph.minAugmPath();
  
  std::cout << answer << std::endl;
}