#include <iostream>
#include "AdjacencyList.h"

int main()
{

    int no_of_lines, power_iterations;
    string from, to;
    AdjacencyList created_graph;

    cin >> no_of_lines;
    cin >> power_iterations;

    for (int i = 0; i < no_of_lines; i++)
    {
        cin >> from;
        cin >> to;
        created_graph.InsertEdge(from, to);
    }

    created_graph.PageRank(power_iterations);
}

