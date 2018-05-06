#ifndef PLATFORM_H
#define PLATFORM_H

#include"SFML\Graphics.hpp"
#include"Settings.h"
#include<string>

class Platform : public sf::Drawable{

private:

	sf::RectangleShape body;
	sf::Texture texture;
	std::string id;

	//Private functions
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:

	Platform(std::string id, sf::Vector2i index);
	~Platform();

	//Get
	std::string getID(void) const;
	sf::RectangleShape* getBody(void);

	//Set
	

};

#endif // !PLATFORM_H

