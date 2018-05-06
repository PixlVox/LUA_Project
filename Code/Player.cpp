#include"Player.h"

Player::Player() {

	//Movement
	this->vel = sf::Vector2f(0.0f, 0.0f);
	this->acc = sf::Vector2f(50.0f, 125.0f);
	this->velCap = 250.0f;

	//Texture
	this->texture.loadFromFile("Textures//Player.png");

	//Rect
	this->body.setSize(sf::Vector2f(TILE_WIDTH, TILE_HEIGHT * 2));
	this->body.setPosition(sf::Vector2f(0.0f, 0.0f));
	this->body.setFillColor(sf::Color::Green);

	//Collision
	this->grounded = true;

}

Player::~Player() {



}

///////////////////////////MISC//////////////////////////////////
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const{

	target.draw(this->body);

}

void Player::move(float dT) {

	this->body.move((this->vel.x * dT), (this->vel.y * dT));

}

void Player::handleInput(std::vector<std::string>& inputBuffer, float dT) {

	if (!inputBuffer.empty()) {

		if (inputBuffer.front() == "Left") {

			//Break speed when changing direction
			if (this->vel.x >= 0.0f) {

				this->vel.x = 0.0f;

			}

			//Apply acceleration
			if (this->vel.x >= -this->velCap) {

				this->vel.x += (-this->acc.x * dT);
				inputBuffer.erase(inputBuffer.begin());

			}

		}
		else if (inputBuffer.front() == "Right") {

			//Break speed when changing direction
			if (this->vel.x <= 0.0f) {

				this->vel.x = 0.0f;

			}

			//Apply acceleration
			if (this->vel.x <= this->velCap) {

				this->vel.x += (this->acc.x * dT);
				inputBuffer.erase(inputBuffer.begin());

			}

		}
		else if (inputBuffer.front() == "Jump") {

			//Apply jump acceleration
			if (this->grounded) {

				this->vel.y += (-this->acc.y * dT);
				inputBuffer.erase(inputBuffer.begin());

			}

		}

	}

}

void Player::applyGravity(float dT) {

	if (!this->grounded) {

		this->vel.y += 9.88f * dT;

	}

}

void Player::update(std::vector<std::string>& inputBuffer, float dT) {

	//Apply gravity
	this->applyGravity(dT);

	//Handle input
	this->handleInput(inputBuffer, dT);

	//Move player
	this->move(dT);

}


/////////////////////////////GET///////////////////////////////////
sf::RectangleShape* Player::getBody(void) {

	return &this->body;

}

sf::Vector2f Player::getVel(void) const{

	return this->vel;

}

sf::Vector2f Player::getAcc(void) const{

	return this->acc;

}

bool Player::isGrounded(void) const{

	return this->grounded;

}

////////////////////////////SET///////////////////////////////////////////
void Player::setVel(sf::Vector2f vel) {

	this->vel = vel;

}

void Player::setAcc(sf::Vector2f acc) {

	this->acc = acc;

}

void Player::setGrounded(bool grounded) {

	this->grounded = grounded;

}

void Player::setStartPos(sf::Vector2i tileIndex) {

	this->body.setPosition(sf::Vector2f(TILE_WIDTH * tileIndex.x,
		TILE_HEIGHT * tileIndex.y));

}