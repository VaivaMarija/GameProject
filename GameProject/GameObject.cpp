#include "GameObject.h"


CGameObject::CGameObject()
{

}

void CGameObject::setTexture(const sf::Texture& _texture)
{
/*
	if (textureType == Player)
	{
		//load player texture
		texture.loadFromFile("Content/Textures/Player/playerShip1_blue.png");
	}
	else if (textureType == Enemy)
	{
		//load enemy texture
		texture.loadFromFile("Content/Textures/Enemies/enemyBlack1.png");
	}
	else if (textureType == Meteor)
	{
		//load asteroid texture
		texture.loadFromFile("Content/Textures/Meteors/meteorBrown_med1.png"); // there's a bunch of them tho so idk.
	}
	//add texture to sprite
*/
	sprite.setTexture(_texture);
}

void CGameObject::setType(ETexture type)
{
	textureType = type;
}

void CGameObject::drawTo(sf::RenderTarget& _target)
{
	_target.draw(sprite);
}

void CGameObject::Tick(float _deltaTime)
{
}

void CGameObject::setPosition(sf::Vector2f _position)
{
	sprite.setPosition(_position);
}