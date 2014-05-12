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

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for(it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if(menuItemRect.top + menuItemRect.height > y
			&& menuItemRect.top < y
			&& menuItemRect.left < x
			&& menuItemRect.left + menuItemRect.height) // olis voinu k�ytt�� aivoi enemm�..
		{
			return (*it).action;
		}
	}

	return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;

	while(true)
	{
		while(window.pollEvent(menuEvent))
		{
			if(menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x,
									menuEvent.mouseButton.y);
			}
			if(menuEvent.type == sf::Event::Closed)
				return Exit;
		}
	}
}