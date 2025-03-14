#pragma once

class GameObject {
private:
	char texture, type;
public:
	GameObject();
	GameObject(char texture, char type);
	
	char getTexture();
	char getType();
};