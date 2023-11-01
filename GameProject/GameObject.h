#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


enum class ETexture {Player, Enemy, Meteor};

class CGameObject
{
public:
	CGameObject();

	ETexture textureType;
	void setType(ETexture type);

	void setTexture(const sf::Texture& _texture);

	void drawTo(sf::RenderTarget& _target);

	void setPosition(sf::Vector2f _position);

	virtual void Tick(float _deltaTime);


	// function that destroys the objects once they're out of screen bounds.


protected:
	sf::Sprite sprite;

private:

};
