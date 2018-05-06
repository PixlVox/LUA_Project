#include"Game.h"

Game::Game() {

	this->playing = false;
	this->camview = this->cam.getView();

}

Game::~Game() {



}

////////////////////////////MISC///////////////////////////////////
void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const{

	if (this->playing) {

		target.draw(this->level);

	}

}

void Game::update(float dT) {

	if (playing) {

		//Read input
		this->input.readInput();

		//Update camera view
		this->cam.setScrollSpeed(25.0f * dT);
		this->cam.scroll();

		//Update level
		this->level.update(this->input.getInputBuffer(), dT);

	}
	else {

		this->initLevel("Level1", dT);

	}

}

void Game::initLevel(std::string level, float dT) {

	//Load level
	this->level.loadLevel(level);

	//Init camera
	this->cam.centerCam(this->level.getPlayerPos());
	this->cam.setScrollSpeed(25.0f * dT);

	//Set input state
	this->input.setState(GAME);

	//Set state
	playing = true;

}

/////////////////////////////GET////////////////////////////////////
sf::View* Game::getCamView(void) {

	return this->camview;

}


//////////////////////////////SET///////////////////////////////////


