//Graph Creator
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;

static const float noEdge = -99;
void add_vertex(char* vertex_list[20], int &vertex_count, char label[20]);
void addEdge(char* vertex_list[20], float adj_table[20][20], float weight, char label1[20], char label2[20]);
int vertex_index(char* vertex_list[20], char label[20]);
void remove_edge(char* vertex_list[20], float adj_table[20][20], char label1[20], char label[20]);
void remove_vertex(char* vertex_list[20], char label[20], float adj_table[20][20]);

int main() {


  return 0;
}
//adds a vertex to the graph
void add_vertex(char* vertex_list[20], int &vertex_count, char label[20])
{
    int length = strlen(label);

    //first check if the chosen label already is in use in the vertex_list
    for(int i = 0; i < 20; i++) {
      if(!strcmp(vertex_list[i], (char*) label)) {
        cout << "Chosen label already exists in the graph" << endl;
        return;
      }
    }

    vertex_list[vertex_count] = new char[length +1];
    strcpy(vertex_list[vertex_count], label);
    vertex_count++;
    cout << "Vertex " << label << "was added. " << endl;
}

void addEdge(char* vertex_list[20], float adj_table[20][20], float weight, char label1[20], char label2[20])
{
  //initialize these to -1 because easy check at the end if a vertex was not present in the list
  int index1 = -1;
  int index2 = -1;

  //finds the indices of the vertices
  index1 = vertex_index(vertex_list, label1);
  index2 = vertex_index(vertex_list, label2);

  if(index1 != -1 && index2 != -1)
  {
    adj_table[index1][index2] = weight;
  }
  else {
    cout << "Vertices entered were not in the graph. " << endl;
  }
}

// lookup vertex label for the array position
// returns -1 if the vertex isn't there, otherwise returns index
int vertex_index(char* vertex_list[20], char label[20])
{
  int index = -1;
  for (int i = 0; i < 20; i++) {
    if (vertex_list[i] != NULL && !strcmp(vertex_list[i], label)) return index;
  }

  return index;
}
//removes an edge between any two vertices, keeping the vertices intact
void remove_edge(char* vertex_list[20], float adj_table[20][20], char label1[20], char label2[20])
{
  int index1 = -1;
  int index2 = -1;

  //finds the indices of the vertices
  index1 = vertex_index(vertex_list, label1);
  index2 = vertex_index(vertex_list, label2);

  //sets the corresponding place in the adjacency table to noEdge (-99)
  if(index1 != -1 && index2 != -1) {
    adj_table[index1][index2] = noEdge;
  }
}
//removes a vertex and all edges to and from that vertex
void remove_vertex(char* vertex_list[20], char label[20], float adj_table[20][20])
{
  int index = -1;
  //finds the index of vertex to be removed
  index = vertex_index(vertex_list, label);

  //if the vertex is present, clear all the edges that point from that vertex
  //as well as all edges that point to that vertex

  if(index != -1)
  {
    delete vertex_list[index];
    vertex_list[index];
    for(int i = 0; i < 20; i++) {
      adj_table[i][index] = noEdge;
      adj_table[index][i] = noEdge;
    }
    cout << "Vertex and edges to and from the vertex have been cleared" << endl;
  }
  else {
    cout << "Vertex was not found" << endl;
    return;
  }
}




/*
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
*?
*/
