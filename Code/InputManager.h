#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include<vector>
#include"SFML\Graphics.hpp"

enum GameState { MENU, GAME, EDITOR };

class InputManager {

private:

	//State
	GameState gS;

	//Input buffer
	std::vector<std::string> inputBuffer;

	//Input values
	sf::Vector2i mousePos;

	//Private functions
	void readInputMenu(void);
	void readInputGame(void);
	void readInputEditor(void);

public:

	InputManager(GameState gS = MENU);
	~InputManager();

	//Misc
	void readInput(void);

	//Get
	std::vector<std::string>& getInputBuffer(void);
	sf::Vector2i getMousePos(void) const;

	//Set
	void setState(GameState state);


};

#endif // !INPUTMANAGER_H

