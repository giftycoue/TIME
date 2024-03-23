#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Clock");

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return 1;
    }

    sf::Text clockText;
    clockText.setFont(font);
    clockText.setCharacterSize(24);
    clockText.setFillColor(sf::Color::White);
    clockText.setPosition(50, 50);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Get current time
        time_t now = time(0);
        tm *ltm = localtime(&now);

        // Format time as HH:MM:SS
        char currentTime[9];
        strftime(currentTime, sizeof(currentTime), "%H:%M:%S", ltm);

        clockText.setString(currentTime);

        window.clear();
        window.draw(clockText);
        window.display();
    }

    return 0;
}

