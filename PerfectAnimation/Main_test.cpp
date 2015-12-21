#include <SFML/Graphics.hpp>
#include <iostream>
#include "DrawableObject.hpp"

// WAS DOING : 
// initTranslationByTime -> calcul de la vitesse en fonction du targetPoint et du temps
// reflexion sur l'utilité de TimeAnim dans translation

// TO DO :

// refactoring pour les methodes rotate -> duplication de code
// implementer les translations dans DrawableObject
// animation translation -> implementer la classe TranslationTransformation
// animation textureRect
// implementer une superClasse qui gere plusieurs DrawableObject

int main()
{
	std::string titleWindow("SFML works! FPS : ");
	sf::RenderWindow window(sf::VideoMode(200, 200), titleWindow);
	window.setFramerateLimit(150);

	sf::Texture* texture1 = new sf::Texture();
	if (!texture1->loadFromFile("img/feu_1.png"))
	{
		std::cerr << "Erreur lors du chargement de la 1ere texture" << std::endl;
	}
	Frame* frame1 = new Frame(texture1, 0.1);

	sf::Texture* texture2 = new sf::Texture();
	if (!texture2->loadFromFile("img/feu_2.png"))
	{
		std::cerr << "Erreur lors du chargement de la 2eme texture" << std::endl;
	}
	Frame* frame2 = new Frame(texture2, 0.1);

	sf::Texture* texture3 = new sf::Texture();
	if (!texture3->loadFromFile("img/feu_3.png"))
	{
		std::cerr << "Erreur lors du chargement de la 3eme texture" << std::endl;
	}
	Frame* frame3 = new Frame(texture3, 0.1);

	std::vector <Frame*> frames;
	frames.push_back(frame1);
	frames.push_back(frame2);
	frames.push_back(frame3);

	Animation* animation = new Animation(frames);

	std::vector <Animation*> animations;
	animations.push_back(animation);

	DrawableObject objectTest(animations);
	objectTest.startAnimation();
	objectTest.setRepeatAnimation(true);
	objectTest.startRotationWithTime(-100, 5);
	objectTest.setPosition(100, 100);
	objectTest.setOriginCenter();
	//objectTest.setInfiniteRotation(true);

	sf::Clock clock;
	double timeLeft = 1;
	int fps = 0;

	double timeStop = 5;
	double timeRestart = 10;
	double timeReset = 15;

	while (window.isOpen())
	{
		fps =(int) 1 / timeLeft;
		//std::cout << "fps : " << fps << std::endl;
		//titleWindow = titleWindow + std::to_string(fps);
		window.setTitle(titleWindow);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		timeLeft = clock.getElapsedTime().asSeconds();
		clock.restart();
		
		timeStop -= timeLeft;
		timeRestart -= timeLeft;
		timeReset -= timeLeft;

		if (timeStop < 0)
		{
			objectTest.stopAnimation();
			timeStop = 100000;
		}
		if (timeRestart < 0)
		{
			objectTest.startAnimation();
			objectTest.startRotationWithTime(100, 5);
			timeRestart = 100000;
		}
		if (timeReset < 0)
		{
			objectTest.restartAnimation();
			timeReset = 10000;
		}
	

		objectTest.actualize(timeLeft);

		window.clear();
		objectTest.draw(&window);
		window.display();
	}

	return 0;
}