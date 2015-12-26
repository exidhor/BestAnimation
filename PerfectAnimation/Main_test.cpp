#include <SFML/Graphics.hpp>
#include <iostream>
#include "DrawableObject.hpp"

// ---------------------------------------------------------------------------------------------------------------------------

// WAITING : 

// animation textureRect : implementation du code dans le .cpp
// reflexion sur le stockage de la taille de la texture ainsi que la facon de charger les textures

// ---------------------------------------------------------------------------------------------------------------------------

// WAS DOING :

// Tile : retourner un IntRect pour le textureRect
// implementer le polymorphisme pour que les animPerFrame et celle avec les tiles soient facilement interchangeable

// CHargement des Textures
// Reflexion sur le chargement des textures :
//		-> Faire 3 chargements de textures differents (une texture dans chaque sf::texture 

// ---------------------------------------------------------------------------------------------------------------------------

// TO DO :

// faire un template d'une file d'attente avec son start, repeat(possibilité de mettre un nombre), etc
// Pouvoir mettre une file de transformation -> travaille sur le polymorphisme dans les Transformations
// animation textureRect
// implementer une superClasse qui gere plusieurs DrawableObject

// ---------------------------------------------------------------------------------------------------------------------------

int main()
{
	std::string titleWindow("The Next Gen of the Animation (hope)");
	sf::RenderWindow window(sf::VideoMode(500, 500), titleWindow);
	window.setFramerateLimit(150);

	sf::Clock clock;
	double timeLeft = 0;
	clock.restart();

	/*
	// 1ere technique : image -> loadFromImage
	sf::Image imageTile;
	if (!imageTile.loadFromFile("img/tile.png"))
	{
		return -1;
	}
	timeLeft = clock.getElapsedTime().asSeconds();
	std::cout << "Time left : " << timeLeft << std::endl;
	std::vector <sf::Texture*> textures;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			sf::Texture* texture = new sf::Texture();
			if (!texture->loadFromImage(imageTile, sf::IntRect(j*32, i*48, 32, 48)))
			{
				return -1;
			}
			textures.push_back(texture);
		}
	}

	timeLeft = clock.getElapsedTime().asSeconds();
	std::cout << "Time left : " << timeLeft << std::endl;

	for (int i = 0; i < 96; i++)
	{
		sf::Texture texture;
		if (!texture.loadFromFile("img/tile.png"))
		{
			return -1;
		}
	}*/

	timeLeft = clock.getElapsedTime().asSeconds();
	std::cout << "Time left : " << timeLeft << std::endl;

	
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

	AnimationPerFrame* animation = new AnimationPerFrame(frames);

	std::vector <AnimationPerFrame*> animations;
	animations.push_back(animation);

	DrawableObject objectTest(animations);
	objectTest.startAnimation();
	objectTest.setRepeatAnimation(true);
	objectTest.setPosition(100, 100);
	objectTest.startTranslationWithSpeed(2, sf::Vector2f(100, 0));
	objectTest.startRotationWithTime(100, 2);

	//objectTest.startTranslationWithTargetPoint(3, sf::Vector2f(100, 50));
	

	sf::RectangleShape shape(sf::Vector2f(100, 200));
	shape.setOrigin(sf::Vector2f(100, 100));
	shape.setPosition(300, 250);

	int fps = 0;

	double timeStop = 5;
	double timeRestart = 10;
	double timeReset = 15;
	
	while (window.isOpen())
	{
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		timeLeft = clock.getElapsedTime().asSeconds();
		clock.restart();
		
		
		// TEST ROTATION 

		/*
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
			//objectTest.startRotationWithTime(100, 5);
			timeRestart = 100000;
		}
		if (timeReset < 0)
		{
			objectTest.restartAnimation();
			timeReset = 10000;
		}
		*/
		
		objectTest.actualize(timeLeft);

		window.clear();
		objectTest.draw(&window);
		window.display();
	
	}

	return 0;
}