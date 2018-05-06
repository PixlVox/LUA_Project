#ifndef GAME_H
#define GAME_H

#include"Level.h"
#include"Camera.h"
#include"InputManager.h"

class Game : public sf::Drawable{

private:

	//Input manager
	InputManager input;

	//Level object
	Level level;

	//Camera
	Camera cam;
	sf::View* camview;

	//Game state
	bool playing;

	//Private functions
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void initLevel(std::string level, float dT);

public:

	Game();
	~Game();

	//Misc
	void update(float dT);

	//Get
	sf::View* getCamView(void);

	//Set



};

#endif // !GAME_H
