#include "Graph.hpp"

Graph::Graph(float x, float y) : _size(x, y) {
    this->_vectors.resize(int(y + 1));
}

bool Graph::add_vector2(Vector2 &vector2) {
    std::vector<Vector2>::iterator it;
    int y, x;

    y = vector2.get_y();
    x = vector2.get_x();

    if (y > this->_size.get_y() or y < 0) {
        std::cerr << "vector out of y boundary!\n";
        return false;
    }
    if (x > this->_size.get_x() or x < 0) {
        std::cerr << "vector out of x boundary!\n";
        return false;
    }

    for (it = this->_vectors[y].begin();
        it != this->_vectors[y].end() and (*it).get_x() < x;
        it++);

    this->_vectors[y].insert(it, vector2);
    return true;
}

float Graph::get_x() const {
    return this->_size.get_x();
}
float Graph::get_y() const {
    return this->_size.get_y();
}

bool Graph::is_point(int x, int y) const {
    std::vector<Vector2>::const_iterator cit;

    for (cit = this->_vectors[y].begin(); cit != this->_vectors[y].end(); cit++) {
        if ((*cit).get_x() == x)
            return true;
    }
    return false;

}

std::ostream& operator <<(std::ostream& os, const Graph& graph) {
    float y = graph.get_y();
    float x = graph.get_x();
    std::vector<std::vector<Vector2> >::const_iterator cit;
    for (int y2 = y; y2 >= 0; y2--) {

        std::cout << ">& " << y2;
        for (int x2 = 0; x2 <= x; x2++) {
            if (graph.is_point(x2, y2))
                std::cout << " X"; 
            else
                std::cout << " ."; 
        }
        std::cout << std::endl;
    }
    std::cout << ">& ";
    for (int x2 = 0; x2 <= x; x2++) {
        std::cout << " " << x2;
    }
    return os;
}