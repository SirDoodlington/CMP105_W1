#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	rect.setSize(sf::Vector2f(50, 5));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	rectBot.setSize(sf::Vector2f(150, 150));
	rectBot.setPosition(300, 300);
	rectBot.setFillColor(sf::Color::Cyan);

	rectMid.setSize(sf::Vector2f(100, 100));
	rectMid.setPosition(325, 325);
	rectMid.setFillColor(sf::Color::Magenta);

	rectTop.setSize(sf::Vector2f(50, 50));
	rectTop.setPosition(350, 350);
	rectTop.setFillColor(sf::Color::Yellow);

	circle.setRadius(45);
	circle.setPosition(sf::Vector2f(600, 350));
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineThickness(5);
	circle.setOutlineColor(sf::Color::Red);

	if (!font.loadFromFile("font/Arial.ttf"))
	{
		std::cout << "Error loading font";
	}

	text.setFont(font);
	text.setString("Hello world");
	text.setCharacterSize(24);
	text.setPosition(500, 100);
	text.setFillColor(sf::Color::Magenta);

	rectPsych.setFillColor(sf::Color::Green);
	rectPsych.setSize(sf::Vector2f(100, 100));
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u botRight = window->getSize();
	botRight.x -= rectPsych.getSize().x;
	botRight.y -= rectPsych.getSize().y;

	sf::Vector2f pos;
	pos.x = botRight.x;
	pos.y = botRight.y;

	rectPsych.setPosition(pos);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(rect);
	window->draw(circle);

	window->draw(rectBot);
	window->draw(rectMid);
	window->draw(rectTop);

	window->draw(text);

	window->draw(rectPsych);
	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}