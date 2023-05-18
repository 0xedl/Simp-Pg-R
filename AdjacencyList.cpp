#include <iostream>
#include <utility>
#include <iomanip>
#include "AdjacencyList.h"

void AdjacencyList::AddVertex(const string &vert) {
    if (graph.find(vert) == graph.end()) {
        graph.emplace(vert, vector<pair<string, int>>());
        numVertices += 1;
    }
}

void AdjacencyList::InsertEdge(const string &from, const string &to)
{
    AddVertex(from);
    AddVertex(to);
    graph[from].emplace_back(make_pair(to, graph[from].size()));
}

int AdjacencyList::Outdegree(const string &vert) {
    const auto& iter = graph.find(vert);
    if (iter != graph.end()) {
        return iter->second.size();
    }
    return -1; // not found
}

void AdjacencyList::CalculateContribution() {
    for (const auto& iter : graph) {
        int outdegree = Outdegree(iter.first);
        double con = page_rank_con[iter.first].first / outdegree;
        for (const auto& sec : iter.second) {
            page_rank_con[sec.first].second += con;
        }
    }
}

void AdjacencyList::UpdatePageRank() {
    for (const auto& iter : graph) {
        page_rank_con[iter.first].first = page_rank_con[iter.first].second;
        page_rank_con[iter.first].second = 0;
    }
}

void AdjacencyList::PrintPageRank(){
    for (const auto& iter : page_rank_con) {
        cout << iter.first << " " << fixed << setprecision(2) << iter.second.first << endl;
    }
}

void AdjacencyList::PageRank(int n) {
    for (const auto& iter : graph) {
        page_rank_con[iter.first] = make_pair(1.0 / numVertices, 0.0);
    }

    for (int i = 1; i < n; i++) {
        CalculateContribution();
        UpdatePageRank();
    }

    PrintPageRank();
}
