#ifndef LEVEL_H
#define LEVEL_H

#include"Player.h"
#include"Platform.h"
#include<fstream>

class Level : public sf::Drawable{

private:

	//Level objects
	Player player;
	std::vector<Platform> platforms;

	//File reading
	std::ifstream inFile;

	//Private functions
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::string readFileData(std::string line, int& index);

public:

	Level();
	~Level();

	//Misc
	void loadLevel(std::string level);
	void update(std::vector<std::string>& inputBuffer, float dT);

	//Get
	sf::Vector2f getPlayerPos(void);

	//Set


};

#endif // !LEVEL_H

