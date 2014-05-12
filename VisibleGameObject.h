#pragma once
#ifndef VISIBLEGAMEOBJECT_H
#define VISIBLEGAMEOBJECT_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class VisibleGameObject
{
	public:
		VisibleGameObject();
		virtual ~VisibleGameObject();

		virtual void Load(std::string filename);
		virtual void Draw(sf::RenderWindow &window);

		virtual void SetPosition(float x, float y);

	private:
		sf::Sprite _sprite;
		sf::Texture _texture;
		std::string _filename;
		bool _isLoaded;
};

#endif