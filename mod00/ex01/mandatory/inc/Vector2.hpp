#pragma once

struct Vector2 {

    public:

        Vector2(float x, float y);
        float get_x() const;
        float get_y() const;

    private:

        float _x;
        float _y;

};