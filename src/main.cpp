#include <chrono>
#include <iostream>
#include <thread>

#include "physics_objects.h"

/* TODO
    2. bounce off objects
        - this is a response to a collision, so it'd be nice to have some
   collision detection
    3. rigidbody
    4. move things to base class
*/

Ball ball(10.f, {0, 0}, 1.0f);
Box box({1920.0f, 20.0f}, {0, 500.0f}, 1.0f);
// PhysicsObject* physicsObjectList[MAX_OBJECT_COUNT];
vector<Ball*> ballObjectList;
vector<Box*> boxObjectList;

void init() {
    ball.shape.setFillColor(sf::Color::Green);
    ball.shape.setPointCount(500);
    box.shape.setFillColor(sf::Color::Red);
    ballObjectList.push_back(&ball);
    boxObjectList.push_back(&box);
}

void processEvent(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        float ySpeed;
        switch (event.key.code) {
            case sf::Keyboard::Space:
                // ball.addForce({0.0f, -5.0f});
                ySpeed = ball.getSpeed().y;
                if (ySpeed > 0) ySpeed = 0;
                ball.setSpeed({ball.getSpeed().x, ySpeed - 5.0f});
                break;
            case sf::Keyboard::A:
            case sf::Keyboard::H:
                ball.setSpeed({-4, ball.getSpeed().y});
                break;
            case sf::Keyboard::D:
            case sf::Keyboard::L:
                ball.setSpeed({4, ball.getSpeed().y});
                break;
            default:
                break;
        }
    } else if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
            case sf::Keyboard::A:
            case sf::Keyboard::H:
                ball.setSpeed({0, ball.getSpeed().y});
                break;
            case sf::Keyboard::D:
            case sf::Keyboard::L:
                ball.setSpeed({0, ball.getSpeed().y});
                break;
            default:
                break;
        }
    }
}

void run(sf::Event& event) {
    ball.move();
    // detectCollisions();
}

void drawShapes(sf::RenderWindow& window, sf::Text& applicationFrameRate) {
    window.draw(ball.shape);
    window.draw(box.shape);
    window.draw(applicationFrameRate);
}

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Physics Simulation??",
                            sf::Style::Default, settings);
    sf::Clock runtimeClock;
    sf::Clock frameRateDisplayClock;

    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        debug("Failed to load font");
    }

    sf::Text applicationFrameRateText;
    applicationFrameRateText.setFont(font);
    applicationFrameRateText.setCharacterSize(24);

    // configuration since I only have version 2.1 available with my LSP
#if SFML_MINOR_VERSION == 1
    applicationFrameRateText.setColor(sf::Color::Red);
#else
    applicationFrameRateText.setFillColor(sf::Color::Red);
#endif

    init();

    int applicationFrameRate = 0;
    int displayFrameRate = 0;
    while (window.isOpen()) {
        if (frameRateDisplayClock.getElapsedTime() > sf::seconds(1)) {
            frameRateDisplayClock.restart();
            displayFrameRate = applicationFrameRate;
            applicationFrameRate = 0;
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) window.close();
            }
            processEvent(event);
        }

        window.clear();
        applicationFrameRateText.setString(to_string(displayFrameRate));
        run(event);
        drawShapes(window, applicationFrameRateText);
        window.display();

        applicationFrameRate++;
        if (runtimeClock.getElapsedTime() < sf::milliseconds(TIME_PER_FRAME)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(
                (sf::milliseconds(TIME_PER_FRAME) - runtimeClock.restart())
                    .asMilliseconds()));
        } else {
            runtimeClock.restart();
        }
    }
    return 0;
}
