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

void drawLines(sf::RenderWindow&, const int, const int);
int findPrecision(const int);


int main()
{
    const int WINDOW_WIDTH = 1000, WINDOW_HEIGHT = 100; // Size at launch

    // Setup window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
        "Ruler");

    // Create ruler
    sf::RectangleShape ruler(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    ruler.setFillColor(sf::Color::Yellow);

    while (window.isOpen())
    {
        sf::Event event;

        // Close window
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(ruler); // Draw ruler background
        drawLines(window, WINDOW_WIDTH, WINDOW_HEIGHT);

        window.display();
    }

    return 0;
}


// Draw lines on ruler
void drawLines(sf::RenderWindow& window, const int WINDOW_WIDTH, 
    const int WINDOW_HEIGHT)
{
    int divisor = 1, maxDivisor = findPrecision(window.getSize().x);
    double lineHeight = WINDOW_HEIGHT * 0.9; // Biggest line is 90% of window

    // Iterate through each divisor
    while (divisor <= (maxDivisor / 2))
    {
        // Iterate through each possible line with specified divisor
        for (int i = 1; i <= (divisor * 2); i++)
        {
            // Check if divisible to prevent duplicate lines from being drawn
            if ((i % divisor) != 0 || (i == 1))
            {
                // Create line and set at midpoint
                sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f((WINDOW_WIDTH * i) / (divisor * 2),
                        0), sf::Color::Black),
                    sf::Vertex(sf::Vector2f((WINDOW_WIDTH * i) / (divisor * 2),
                        lineHeight), sf::Color::Black)
                };
                window.draw(line, 2, sf::Lines); // Draw line
            }
        }

        divisor *= 2; // Increase divisor
        lineHeight *= 0.75; // Adjust height of lines
    }
}


// Return the greatest precision value that's visually appealing
int findPrecision(const int currentWidth)
{
    return (int) (currentWidth / 29);
}
