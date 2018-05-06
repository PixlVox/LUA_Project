#ifndef CAMERA_H
#define CAMERA_H

#include"SFML\Graphics.hpp"

class Camera {

private:

	sf::Vector2f centerPos;
	sf::View view;

	float  scrollSpeed;

public:

	Camera(sf::Vector2f center = sf::Vector2f(0.0f, 0.0f), float speed = 0.0f);
	~Camera();

	//Misc
	void scroll(void);
	void centerCam(sf::Vector2f center);

	//Get
	sf::View* getView(void);
	sf::Vector2f getCenter(void) const;
	float getSpeed(void) const;

	//Set
	void setScrollSpeed(float speed);

};

#endif // !CAMERA_H
