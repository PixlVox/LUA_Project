#include"Platform.h"

Platform::Platform(std::string id, sf::Vector2i index) {

	//Store id
	this->id = id;
	
	//Load correct texture
	this->texture.loadFromFile("Textures//" + this->id + ".png");

	//Set size and pos
	this->body.setFillColor(sf::Color::Red);
	this->body.setSize(sf::Vector2f(TILE_WIDTH, TILE_HEIGHT));
	this->body.setPosition(sf::Vector2f(TILE_WIDTH * index.x, TILE_HEIGHT * index.y));

}

Platform::~Platform() {



}

////////////////////////////MISC///////////////////////////////
void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	target.draw(this->body);

}

//////////////////////////////GET//////////////////////////////
std::string Platform::getID(void) const{

	return this->id;

}

sf::RectangleShape* Platform::getBody(void){

	return &this->body;

}