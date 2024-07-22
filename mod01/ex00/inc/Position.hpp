#pragma once

struct Position {

    private:

        int _x;
        int _y;
        int _z;

    public:

        Position(int x, int y, int z);
        ~Position();
        int get_x() const;
        int get_y() const;
        int get_z() const;
    
};