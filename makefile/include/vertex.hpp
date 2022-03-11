#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>
#include <memory>

class Vertex{
  /*
  Classe base para a classe Grafo. 
  
  Métodos
  -------
  Apenas métodos setters, getters, e construtores.

  Atributos
  ---------
  _edges_in: Sinalize se possui arestas de entrada.
  _edges_out: Sinaliza se possui arestas de saída.
  _id: Número do vértice.
  _number_of_edges: Número de vértices de saída.
  _reference: Lista de adjacência, para ser utilizada com a classe 'Graph'.


  */
  public:
    Vertex(): _edges_in(0), _edges_out(0), _group_num(-1){};
    Vertex(int ei, int eo): _edges_in(ei), _edges_out(eo){}; 


    void setEdgesIn(int a){ this->_edges_in = a; }
    int getEdgesIn() const { return this->_edges_in;}

    void setEdgesOut(int a){ this->_edges_out = a; }
    int getEdgesOut()const { return this->_edges_out;}
    
    
    void setId(int a){ this->_id = a; }
    int getId() const{ return this->_id;}


    void setGroupNum(int a){ this->_group_num = a; }
    int getGroupNum() const{ return this->_group_num;}

    void setReference(Vertex* a){ this->_reference.push_back(a);}
    const std::vector<Vertex*>& getReference() const{ return _reference; }


  private:
    int _edges_in, _edges_out, _id, _group_num;
    std::vector<Vertex*> _reference;
    
    friend class Graph;

};


#endif