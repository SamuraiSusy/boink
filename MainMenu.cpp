#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
	sf::Texture texture;
	texture.loadFromFile("include/menu.png");
	sf::Sprite sprite(texture);

	// set up clickable regions

	// play menu item coordinates
	MenuItem playButton;
	playButton.rect.left = 380;
	playButton.rect.top = 228;
	playButton.rect.width = 202;
	playButton.rect.height = 106;
	playButton.action = Play;

	// exit menu item coordinates
	MenuItem exitButton;
	exitButton.rect.left = 398;
	exitButton.rect.top = 419;
	exitButton.rect.width = 160;
	exitButton.rect.height = 78;
	exitButton.action = Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}