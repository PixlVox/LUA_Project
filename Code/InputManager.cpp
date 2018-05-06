#include"InputManager.h"

InputManager::InputManager(GameState gS) {

	this->gS = MENU;
	this->mousePos = sf::Vector2i(0, 0);

}

InputManager::~InputManager() {



}

//////////////////////////MISC//////////////////////////////////
void InputManager::readInputMenu(void) {

	//Mouse Input
	this->mousePos = sf::Mouse::getPosition();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		this->inputBuffer.push_back("Select");

	}

	//Keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

		this->inputBuffer.push_back("Up");

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

		this->inputBuffer.push_back("Down");

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

		this->inputBuffer.push_back("Up");

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

		this->inputBuffer.push_back("Down");

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {

		this->inputBuffer.push_back("Select");

	}

}

void InputManager::readInputGame(void) {

	//Read Keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

		this->inputBuffer.push_back("Left");

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

		this->inputBuffer.push_back("Right");

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

		this->inputBuffer.push_back("Jump");

	}

}

void InputManager::readInputEditor() {



}

void InputManager::readInput(void) {

	switch(gS){
	case MENU:
		this->readInputMenu();
		break;
	case GAME:
		this->readInputGame();
		break;
	case EDITOR:
		this->readInputEditor();
		break;
	default:
		break;
	}

}


//////////////////////////GET///////////////////////////////////
std::vector<std::string>& InputManager::getInputBuffer(void) {

	return this->inputBuffer;

}

sf::Vector2i InputManager::getMousePos(void) const{

	return this->mousePos;

}

//////////////////////////SET///////////////////////////////////
void InputManager::setState(GameState state){

	this->gS = state;

}
