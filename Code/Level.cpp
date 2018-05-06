#include"Level.h"

Level::Level() {



}

Level::~Level() {



}

///////////////////////////MISC////////////////////////////
void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const{

	//Draw platforms
	for (int i = 0; i < this->platforms.size(); i++) {

		target.draw(this->platforms.at(i));

	}

	//Draw player
	target.draw(this->player);

}

void Level::update(std::vector<std::string>& inputBuffer, float dT) {

	//Update player
	this->player.update(inputBuffer, dT);

}

std::string Level::readFileData(std::string line, int& index) {

	std::string tempLine = "";

	while (line.at(index) != ',') {

		tempLine += line.at(index);
		index++;

	}

	return tempLine;

}

void Level::loadLevel(std::string level) {

	//Open file
	this->inFile.open("Levels\\Level1.txt");

	//Load the level info
	int platformCount = 0;
	std::string line = "";

	//Get number of platforms
	std::getline(inFile, line);
	platformCount = std::stoi(line);

	//Load the platforms
	line = "";
	std::string platformType = "";
	sf::Vector2i platformIndex = sf::Vector2i(0, 0);
	int lineIndex = 0;
	for (int i = 0; i < platformCount; i++) {

		//Read line
		std::getline(inFile, line);

		//Store platform type
		platformType = this->readFileData(line, lineIndex);
		lineIndex++;	//Skip comma(data separator in file)

		//Store platform x index
		platformIndex.x = std::stoi(this->readFileData(line, lineIndex));
		lineIndex++;	//Skip comma(data separator in file)

		//Store platform y index
		platformIndex.y = std::stoi(this->readFileData(line, lineIndex));

		//Create the platform
		this->platforms.push_back(Platform(platformType, platformIndex));

		//Reset vars
		line = "";
		lineIndex = 0;
		platformType = "";
		platformIndex = sf::Vector2i(0, 0);

	}

	inFile.close();

}

/////////////////////////////////Get////////////////////////////////////
sf::Vector2f Level::getPlayerPos(void) {

	return this->player.getBody()->getPosition();

}


/////////////////////////////////Set/////////////////////////////////////

