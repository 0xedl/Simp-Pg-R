#pragma once

#include <vector>
#include <string>
#include <map>

using namespace std;

class AdjacencyList{

private:
    double numVertices; // total number of vertices
    map<string, vector<pair<string, int>>> graph; // from & adjacency list (to, index)
    map<string, pair<double, double>> page_rank_con; // page rank & contributions

public:
   AdjacencyList() : numVertices(0) {} // constructor
   void AddVertex(const string& vert); // adds vertex // helper
   void InsertEdge(const string &from, const string &to); // insert edge
   int Outdegree(const string &vertex); // find out degree // helper
   void CalculateContribution(); // calculates the contribution of each vertex based on outdegree // helper
   void UpdatePageRank(); // updates the page rank // helper
   void PrintPageRank(); // print page ranks // helper
   void PageRank(int n); // calculate, update, and print pagerank

   // TESTING ONLY // NOT INCLUDED IN THE ACTUAL PROJECT
   // THESE ARE FOR TESTING PURPOSES ONLY
   const map<string, pair<double, double>>& GetPageRankCon() const { return page_rank_con; }
    const pair<double, double>& GetPageRankForVertex(const string& vertex) const {return page_rank_con.at(vertex);}

};