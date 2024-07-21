#include "Graph.hpp"

int main() {
    Graph graph = Graph(5, 5);
    Vector2 v1 = Vector2(0,0);
    Vector2 v2 = Vector2(2,2);
    Vector2 v3 = Vector2(4,2);
    Vector2 v4 = Vector2(2,4);

    graph.add_vector2(v1);
    graph.add_vector2(v2);
    graph.add_vector2(v3);
    graph.add_vector2(v4);
    std::cout << graph << std::endl;
    return 0;
}