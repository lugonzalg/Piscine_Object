#pragma once

#include "Vector2.hpp"

#include <vector>
#include <iostream>

class Graph {

    public:

        Graph(float x, float y);
        bool add_vector2(Vector2 &vector2);
        float get_x() const;
        float get_y() const;
        bool is_point(int x, int y) const;

    private:

        Vector2 _size;
        std::vector<std::vector<Vector2> > _vectors;

};

std::ostream& operator <<(std::ostream& os, const Graph& graph);