#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "vertex.hpp"
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <utility>
#include <set>

class Graph{
  /*
  Classe que representa um grafo direcional, não ponderado, através de listas de adjacência, 
  projetada especificamente para  atender as especificidades do trabalho.
  Por isso, algumas funções que tornariam a classe numa biblioteca
  completamente funcional podem não estar presentes.
  A classe apresenta dependência funcional da classe 'Vertex'.


  Atributos
  ---------
  _vertices: Vetor de vértices, representando o grafo.
  _groups: Parâmetro é preenchido somente quando o método 'findGroups' é chamado. Contém os componentes
  conectados de um grafo.

  Métodos
  --------
  fillEmptyGraph: Inicializa o vetor de vértices com 'size' objetos da classe Vertex.
  addNode: Adiciona um nó no vetor vértices.
  addEdge: Adiciona uma aresta, colocando o vértice de destino na lista de adjacência do vértice de origem.
  findGroups: Acha e salva os componentes conectados de um grafo no vetor _groups.
  getVertices & getGroups: Retorna uma referência constante dos vetores. 

  */
  
  
  public:

    void fillEmptyGraph(int size);
    
    void addNode(Vertex &vertex);
    
    void addEdge(int font, int target);

    int minAugmPath();

    void kosaraju();
    
    const std::vector<Vertex>& getVertices() const{ return _vertices;}

    const std::vector<std::vector<Vertex*>>& getGroups() const{ return _strong_conn_comps;}


    
  private:

    std::vector<Vertex> _vertices;
    
    std::vector<Vertex> reverse;

    std::vector<std::vector<Vertex*>> _strong_conn_comps;

    void dfsUtil(Vertex &vertex, std::vector<bool> &checked, std::vector<Vertex*> &aux);
    
    void dfsUtilStack(Vertex &vertex, std::vector<bool> &checked, std::stack<Vertex*> &aux);
    
    void dfsUtilFindNext(Vertex &vertex, std::vector<bool> &checked, std::set<int> &aux);

    std::vector<Vertex>reverseGraph();

};



#endif