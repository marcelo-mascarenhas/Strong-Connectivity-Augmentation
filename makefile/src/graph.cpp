#include "graph.hpp"

void Graph::addNode(Vertex &vertex){
  int index = _vertices.size();
  
  vertex.setId(index);
  this->_vertices.push_back(vertex);

}

void Graph::fillEmptyGraph(int size){
  if(this->_vertices.size() == 0){
    
    for(int i = 0; i < size; i++){
      Vertex vertice;
      this->addNode(vertice);

    }
  }
}

void Graph::addEdge(int font, int target){

    this->_vertices[font]._edges_out++; this->_vertices[target]._edges_in++; 
    this->_vertices[font].setReference(&_vertices[target]);

}

void Graph::dfsUtil(Vertex &vertex, std::vector<bool> &checked, std::vector<Vertex*> &aux){

  //Functional body of the DFS, used by many algorithms, as the FindGroups.
  int id_num = vertex.getId();
  checked[id_num] = true; 
  
  aux.push_back(&vertex);

  std::vector<Vertex*> link_nodes = vertex.getReference();

  for(const auto& item:link_nodes){
    if(checked[item->getId()] == false){
      dfsUtil(*item, checked, aux);
    }
  }

}

void Graph::dfsUtilStack(Vertex &vertex, std::vector<bool> &checked, std::stack<Vertex*> &aux){

  //Functional body of the DFS, used by many algorithms, as the FindGroups.
  int id_num = vertex.getId();
  checked[id_num] = true; 
  
  std::vector<Vertex*> link_nodes = vertex.getReference();

  for(const auto& item:link_nodes){
    if(checked[item->getId()] == false){
      dfsUtilStack(*item, checked, aux);
    }
  }
  aux.push(&vertex);

}



void Graph::dfsUtilFindNext(Vertex &vertex, std::vector<bool> &checked, std::set<int> &aux){

  //Functional body of the DFS, used by many algorithms, as the FindGroups.
  int id_num = vertex.getId();
  checked[id_num] = true; 

  std::vector<Vertex*> link_nodes = vertex.getReference();

  for(const auto& item:link_nodes){
    if(checked[item->getId()] == false){
      if(item->_group_num == vertex._group_num){
        dfsUtilFindNext(*item, checked, aux);
      }else{
        aux.insert(item->_group_num);
      }
    }
  }

}

int Graph::minAugmPath(){
  int s = 0, t = 0, q = 0;
  
  int counter = -1;

  for(const auto & vec:this->_strong_conn_comps){
    counter++;
    for(const auto& item:vec){
      int ids = item->_id;
      this->_vertices[ids]._group_num = counter;
      }
    }


  Graph *condensated = new Graph();  condensated->fillEmptyGraph(counter+1);
  std::vector <bool> checked(this->_vertices.size(), false);
  
  std::set<int> aux_set;

  int sentinel = 0;
  for(const auto & vec:this->_strong_conn_comps){
    for(const auto& item:vec){
      int ids = item->getId();
      if(checked[ids] == false){
        dfsUtilFindNext(this->_vertices[ids], checked, aux_set);

        for(const auto& element:aux_set){
          condensated->addEdge(sentinel, element);
        }
        break;
      
      }
    }
    aux_set.clear();
    std::fill(checked.begin(), checked.end(), false);
    sentinel++;
  }
  std::vector <Vertex> aux2 = condensated->getVertices();

  for(const auto& item:aux2){
    if(item._edges_out == 0 && item._edges_in == 0){
      q++;
    }
    else if(item._edges_in > 0 && item._edges_out == 0){
      t++;
    }
    else if(item._edges_out > 0 && item._edges_in == 0){
      s++;
    }
  }
  delete condensated;
  return std::max(s+q, q+t);
}

void Graph::kosaraju(){
  std::vector <bool> checked(this->_vertices.size(), false);
  
  this->reverseGraph();

  std::stack<Vertex*> aux;

  for(auto& item:_vertices){  
    int index = item.getId();
    if (checked[index] == false){
      dfsUtilStack(item, checked, aux);
    }
  }
  
  std::vector<Vertex*> connected_comp;
  for(long unsigned int i = 0; i < checked.size(); i++){
    checked[i] = false;
  }


  while(!aux.empty()){
    Vertex* trying = aux.top();
    aux.pop();
    if(checked[trying->_id] == false){
      dfsUtil(reverse[trying->_id], checked, connected_comp);
      this->_strong_conn_comps.push_back(connected_comp);
      connected_comp.clear();
    }

  }

  this->reverse.clear();

}

std::vector<Vertex> Graph::reverseGraph(){
  this->reverse = this->_vertices;
  
  for(auto& item:reverse){
    item._reference.clear();
  }
  int id;
  for(long unsigned int i = 0; i < this->_vertices.size(); i++){
    for(auto& item:this->_vertices[i]._reference){
      id = item->_id;
      reverse[id]._reference.push_back(&reverse[i]);
    }
  }
  return reverse;
}