/*
Name: Andrew Kim
Date: March 2, 2021
Program: Rule the World

I hereby certify that this program represents my
work and that the design and logic was completed
without outside assistance.

Signature: Andrew Kim
*/

#include <SFML/Graphics.hpp>

void drawLine(sf::RenderWindow&, const int, const int, int&, int&);


int main()
{
    const int WINDOW_WIDTH = 1000, WINDOW_HEIGHT = 100; // Size at launch
    int divisor, 
        lineHeight = WINDOW_HEIGHT / 10 * 9; // Biggest line is 90% of window

    // Setup window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
        "Ruler");

    // Create ruler
    sf::RectangleShape ruler(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    ruler.setFillColor(sf::Color::Yellow);

    while (window.isOpen())
    {
        sf::Event event;

        // Draw ruler background
        window.clear();
        window.draw(ruler);

        divisor = 1; // Reset initial divisor

        // Close window
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Create line and set at midpoint
        drawLine(window, WINDOW_WIDTH, WINDOW_HEIGHT, lineHeight, divisor);
        /*
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(WINDOW_WIDTH / 2, 0), sf::Color::Black),
            sf::Vertex(sf::Vector2f(WINDOW_WIDTH / 2, lineHeight / divisor), sf::Color::Black)
        };
        window.draw(line, 2, sf::Lines);*/

        divisor *= 2;

        // Create a line at each fraction
        for (int i = 1; i <= (divisor * 2); i++)
        {
            sf::Vertex lineFraction[] =
            {
                sf::Vertex(sf::Vector2f(WINDOW_WIDTH * i / 4, 0), sf::Color::Black),
                sf::Vertex(sf::Vector2f(WINDOW_WIDTH * i / 4, lineHeight / divisor), sf::Color::Black)
            };
            window.draw(lineFraction, 2, sf::Lines);
        }
        /*
        sf::Vertex lineTwo[] =
        {
            sf::Vertex(sf::Vector2f(WINDOW_WIDTH * 1 / 4, 0), sf::Color::Black),
            sf::Vertex(sf::Vector2f(WINDOW_WIDTH * 1 / 4, lineHeight / divisor), sf::Color::Black)
        };
        window.draw(lineTwo, 2, sf::Lines);


        sf::Vertex lineThree[] =
        {
            sf::Vertex(sf::Vector2f(WINDOW_WIDTH * 3 / 4, 0), sf::Color::Black),
            sf::Vertex(sf::Vector2f(WINDOW_WIDTH * 3 / 4, lineHeight / divisor), sf::Color::Black)
        };

        window.draw(lineThree, 2, sf::Lines);
        */


        //window.draw(line, 2, sf::Lines);
        window.display();
    }

    return 0;
}


// Comment goes here
void drawLine(sf::RenderWindow& window, const int WINDOW_WIDTH, 
    const int WINDOW_HEIGHT, int& lineHeight, int& divisor)
{
    // Create line and set at midpoint
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(WINDOW_WIDTH / 2, 0), sf::Color::Black),
        sf::Vertex(sf::Vector2f(WINDOW_WIDTH / 2, lineHeight / divisor), sf::Color::Black)
    };
    window.draw(line, 2, sf::Lines); // Draw line
}
