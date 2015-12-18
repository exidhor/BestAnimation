#include <SFML/Graphics.hpp>

// TO DO :
// TESTER ET IMPLEMENTER UNE ANIMATION BASIQUE, GENRE CLIGNOTEMENT
// DO ACTUALIZE DANS PERSONALMANAGER
//finir dans l'arbo pour afficher
//afficher les fps dans le titre de la fenetre

// animation textureRect
// actualize dans rotation
// animation translation

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}