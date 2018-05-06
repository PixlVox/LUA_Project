#include"Camera.h"

Camera::Camera(sf::Vector2f center, float speed) {

	this->centerPos = center;
	this->scrollSpeed = 0.0f;

	this->view.setCenter(this->centerPos);

}

Camera::~Camera() {



}

////////////////////////////////////MISC////////////////////////////////////////
void Camera::scroll(void) {

	this->view.move(sf::Vector2f(this->scrollSpeed, 0.0f));

}

void Camera::centerCam(sf::Vector2f center) {

	this->view.setCenter(center);
	this->centerPos = center;

}

////////////////////////////////////Get//////////////////////////////////////////
sf::View* Camera::getView(void) {

	return &this->view;

}

sf::Vector2f Camera::getCenter(void) const{

	return this->centerPos;

}

float Camera::getSpeed(void) const{

	return this->scrollSpeed;

}

////////////////////////////////////Set//////////////////////////////////////////
void Camera::setScrollSpeed(float speed) {

	this->scrollSpeed = speed;

}