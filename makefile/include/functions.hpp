#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

#include "graph.hpp"

class Functions{
  /*
  Classe que possui métodos suplementares ao programa.
  Métodos
  ------
  readInput: Recebe um grafo e o preenche de acordo com o arquivo passado na entrada padrão.
  
  */
  public:
    void readInput(Graph &grafo);
};



#endif