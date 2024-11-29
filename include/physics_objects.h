#include "constants.h"
#include "physics_utils.h"

class PhysicsObject {
   protected:
    sf::Vector2f _speed = {0.0f, 0.0f};
    float _mass;
    sf::Vector2f _acceleration = {0.0f, 0.0f};

   public:
    sf::Vector2f getPosition();

    sf::Vector2f getSpeed() { return _speed; }

    void setSpeed(sf::Vector2f speed) { _speed = speed; }

    void setAcceleration(sf::Vector2f acceleration) {
        _acceleration = acceleration;
    }

    void setMass(float mass) { _mass = mass; }

    void addForce(sf::Vector2f force) {
        sf::Vector2f acceleration = force / _mass;
        setAcceleration(_acceleration + acceleration);
    }

    void applyGravity() { addForce({0.0f, GRAVITY}); }

    void applyAcceleration() {
        float offset = 1.0f;
        setSpeed(_speed + offset * _acceleration);
        _acceleration = {0.0f, 0.0f};
    }
};

class Ball : public PhysicsObject {
   public:
    sf::CircleShape shape;

    Ball(float radius, sf::Vector2f position, float mass) {
        shape.setRadius(radius);
        shape.setPosition(position);
        setMass(mass);
    };

    sf::Vector2f getPosition() { return shape.getPosition(); }

    sf::Vector2f getCenter() { return shape.getOrigin(); }

    void move() {
        applyGravity();
        applyAcceleration();
        sf::Vector2f position = shape.getPosition();
        // need to check for any collisions in the direction you're moving
        // iterate over each position, and make sure that you're not having some
        // sort of collision
        shape.setPosition(position.x + _speed.x,
                          std::min(position.y + _speed.y,
                                   SCREEN_HEIGHT - 2 * shape.getRadius()));
    }
};

class Box : public PhysicsObject {
   public:
    sf::RectangleShape shape;

    Box(sf::Vector2f rectSize, sf::Vector2f position, float mass) {
        shape.setSize(rectSize);
        shape.setPosition(position);
        setMass(mass);
    };

    sf::Vector2f getPosition() { return shape.getPosition(); }

    void move() {
        applyGravity();
        applyAcceleration();
        sf::Vector2f position = shape.getPosition();
        shape.setPosition(
            position.x + _speed.x,
            std::min(position.y + _speed.y, SCREEN_HEIGHT - shape.getSize().y));
    }
};
