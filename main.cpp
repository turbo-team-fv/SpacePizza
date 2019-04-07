#include <SFML/Graphics.hpp>

#include <Mapa.h>

int main()
{

    Mapa * mapa = new Mapa();

    // Create the main window
    sf::RenderWindow * app;
    app = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

	// Start the game loop
    while (app->isOpen())
    {
        // Process events
        sf::Event event;
        while (app->pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app->close();
        }

        // Clear screen
        app->clear();

        // Draw the sprite
        mapa->draw(app);

        // Update the window
        app->display();
    }

    return EXIT_SUCCESS;
}
