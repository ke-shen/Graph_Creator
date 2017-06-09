//Graph Creator
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct vertex {
  char* label;
  vector<pair<vertex*,int>* >  *adjacency;
};

void add_vertex(vector<vertex*>* list);
void add_edge(vector<vertex*>* list);
//checks if the vertex is located within the vector storing all vertices
bool check_vertex(vector<vertex*>* list, char* label);


int main() {
  int i = 5;
  vector<vertex*> * list = new vector<vertex*>;
  add_vertex(list);
  add_vertex(list);
  add_vertex(list);
  add_vertex(list);
  add_vertex(list);
  add_vertex(list);
  add_vertex(list);


  return 0;
}

void add_vertex(vector<vertex*>* list)
{
  char c[10];
  cout << "Enter a label for the vertex (1 character): " << flush;
  cin >> c;
  if(!check_vertex(list, c)) {
    vertex* n_vertex = new vertex;
    //label is the first character of the input
    strcpy(n_vertex->label, c);
    list->push_back(n_vertex);
    return;
  }
  else {
    cout << "The label you entered is already in use in the graph. " << endl;
    return;
  }
}

void add_edge(vector<vertex*>* list)
{
  char temp[50];
  cout << "Enter label of first vertex: " << flush;
  cin >> temp;
}

bool check_vertex(vector<vertex*>* list, char* label)
{
    for(int i = 0; i < list->size(); i++)
      if(!strcmp(list->at(i)->label, label)) return true;
    return false;
}
