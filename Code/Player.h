#ifndef PLAYER_H
#define PLAYER_H

#include"SFML\Graphics.hpp"
#include"Settings.h"

class Player : public sf::Drawable {

private:

	//Visual
	sf::RectangleShape body;
	sf::Texture texture;

	//Movement
	sf::Vector2f vel;
	sf::Vector2f acc;
	float velCap;

	//Collision
	bool grounded;

	//Private functions
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void handleInput(std::vector<std::string>& inputBuffer, float dT);
	void applyGravity(float dT);

public:

	Player();
	~Player();

	//Misc
	void move(float dT);
	void update(std::vector<std::string>& inputBuffer, float dT);

	//Get
	sf::RectangleShape* getBody(void);
	sf::Vector2f getVel(void) const;
	sf::Vector2f getAcc(void) const;
	bool isGrounded(void) const;

	//Set
	void setVel(sf::Vector2f vel);
	void setAcc(sf::Vector2f acc);
	void setGrounded(bool grounded);
	void setStartPos(sf::Vector2i tileIndex);

};

#endif // !PLAYER_H
