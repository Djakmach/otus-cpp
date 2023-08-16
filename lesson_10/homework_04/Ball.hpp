#pragma once
#include "Painter.h"
#include "Point.h"
#include "Velocity.h"

class Ball {
public:
    Ball (Point& center, Velocity& velocity, Color& color, double& radius, bool isCollidable)
        :_center{center}, _velocity{velocity}, _color{color}, _radius{radius}, _isCollidable{isCollidable} {
            _mass = M_PI * pow(_radius, 3.0) * 4.0 / 3.0;
        };
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
    bool getisCollidable() const;
    
private:
    Velocity _velocity;
    Point _center;
    double _radius;
    double _mass;
    Color _color;
    bool _isCollidable;
};
