#include <SFML/Graphics.hpp>

using namespace std;

#ifdef LOCAL
#include "../custom/debugger.h"
#else
#define debug(...) 42;
#endif

// TODO consider whether you want the slope to be two different points or not
float distanceBetweenTwoPoints(sf::Vector2f a, sf::Vector2f b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
pair<float, float> calculateSlopeOfLine(sf::Vector2f a, sf::Vector2f b) {
    return {b.x - a.x, b.y - a.y};
}

pair<float, float> normalizeSlope(pair<float, float> slope) {
    return {slope.first / (slope.first + slope.second),
            slope.second / (slope.first + slope.second)};
}
// traverses the line to check if the line has points present both inside and
// outside the circle
bool checkLineIntersectionWithCircle(sf::Vector2f a, sf::Vector2f b,
                                     sf::Vector2f circleTopLeft,
                                     float circleRadius) {
    pair<float, float> slope = normalizeSlope(calculateSlopeOfLine(a, b));
    sf::Vector2f cur = a;
    int jumps = (int)((b.x - a.x) / slope.first);
    bool inside = false;
    bool outside = false;
    if (circleTopLeft.y > 490 && circleTopLeft.y < 530) {
        // should be some sort of intersection
        debug(circleTopLeft, a, b);
    }
    sf::Vector2f circleCenter = {circleTopLeft.x + circleRadius,
                                 circleTopLeft.y + circleRadius};

    if ((distanceBetweenTwoPoints(a, circleCenter) <= circleRadius) ||
        (distanceBetweenTwoPoints(b, circleCenter) <= circleRadius))
        inside = true;
    if ((distanceBetweenTwoPoints(a, circleCenter) > circleRadius) ||
        (distanceBetweenTwoPoints(b, circleCenter) > circleRadius))
        outside = true;
    for (int i = 0; i < jumps; i++) {
        if (distanceBetweenTwoPoints(cur, circleCenter) <= circleRadius)
            return true;
        else
            outside = true;
    }

    return inside && outside;
}

/* void detectCollisions() {
    // for ball-box collisions
    for (auto chosenBall : ballObjectList) {
        for (auto chosenBox : boxObjectList) {
            sf::Vector2f pos1 = chosenBall->getPosition();
            sf::Vector2f pos2 = chosenBox->getPosition();
            // standard collision detection will only work if the rectangle
            // can only rotate by 90 degrees. If not, this will simply not
            // work. looks like sfml uses rectangles for most intersection.
            // I've implemented my own, even though I probably will not use
            // it
            sf::FloatRect boxRect = chosenBox->shape.getGlobalBounds();
            pair<sf::Vector2f, sf::Vector2f> boxLines[4];
            boxLines[0] = {{boxRect.left, boxRect.top},
                           {boxRect.left + boxRect.width, boxRect.top}};
            boxLines[1] = {{boxRect.left, boxRect.top},
                           {boxRect.left, boxRect.top + boxRect.height}};
            boxLines[2] = {
                {boxRect.left + boxRect.width, boxRect.top},
                {boxRect.left + boxRect.width, boxRect.top + boxRect.height}};
            boxLines[3] = {
                {boxRect.left, boxRect.top + boxRect.height},
                {boxRect.left + boxRect.width, boxRect.top + boxRect.height}};
            // debug(boxRect.top, boxRect.height, boxRect.top +
            boxRect.height);
            // debug(chosenBall->getPosition());
            // debug(boxLines[0], boxLines[1], boxLines[2], boxLines[3]);
            for (int i = 0; i < 4; i++) {
                if (checkLineIntersectionWithCircle(
                        boxLines[i].first, boxLines[i].second,
                        chosenBall->getPosition(),
                        chosenBall->shape.getRadius())) {
                    debug("Collision detected!!");
                }
            }
        }
    }
} */
