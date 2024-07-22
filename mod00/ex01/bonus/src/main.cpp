#include "Graph.hpp"

int main() {
    Graph graph = Graph(5, 5);
    Vector2 v1 = Vector2(0,0);
    Vector2 v2 = Vector2(2,2);
    Vector2 v3 = Vector2(4,2);
    Vector2 v4 = Vector2(2,4);
    Vector2 v42 = Vector2(2,4);
    Vector2 v5 = Vector2(-2,4);
    Vector2 v6 = Vector2(-2,-4);
    Vector2 v7 = Vector2(2,-4);
    Vector2 v8 = Vector2(999,999);

    graph.add_vector2(v1);
    graph.add_vector2(v2);
    graph.add_vector2(v3);
    graph.add_vector2(v4);
    graph.add_vector2(v42);
    graph.add_vector2(v5);
    graph.add_vector2(v6);
    graph.add_vector2(v7);
    graph.add_vector2(v8);
    std::cout << graph << std::endl;
    return 0;
}