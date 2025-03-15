#include "GameObject.h"

GameObject::GameObject() {
	this->texture = ' ';
	this->type = 'e';
}

GameObject::GameObject(char texture, char type) {
	this->texture = texture;
	this->type = type;
}

char GameObject::getTexture() {
	return texture;
}
char GameObject::getType() {
	return this->type;
}