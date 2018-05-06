#ifdef _DEBUG
#pragma comment(lib, "LuaLibd.lib")
#else
#pragma comment(lib, "Lualib.lib")
#endif

#include <lua.hpp>
#include <Windows.h>
#include <iostream>
#include <thread>
#include "lua.hpp"

#include"Game.h"

void ConsoleThread(lua_State* L) {
	char command[1000];
	while(GetConsoleWindow()) {
		memset(command, 0, 1000);
		std::cin.getline(command, 1000);
		if( luaL_loadstring(L, command) || lua_pcall(L, 0, 0, 0) )
			std::cout << lua_tostring(L, -1) << '\n';
	}
}

int main(){

	//LUA
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	std::thread conThread(ConsoleThread, L);

	//SFML Window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "LUA_Project");

	//Game object
	Game game;

	//Deltatime
	sf::Clock deltaClock;
	float deltaTime = 0.0;

	//Game Loop
	while (window.isOpen()){

		//Update deltaTime
		deltaTime = deltaClock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed)
				window.close();
		
		}

		//Update game
		game.update(deltaTime);

		//Set view
		window.setView(*game.getCamView());

		//Draw game
		window.clear();

		window.draw(game);

		window.display();
	}

	conThread.join();
	return 0;
}