
// ------------------------------------------------------------
// LOAD TEXTURE FROM FILE AND SET TEXTURE OF SPRITE
// ------------------------------------------------------------

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

void CreateSpriteWithTextureFromFile()
{
	// Create texture object and call load from file with the relative path of the image file
	sf::Texture texture;
	texture.loadFromFile("Content/Textures/playerShip1_red.png");

	// Create sprite object and set its texture
	sf::Sprite sprite;
	sprite.setTexture(texture);
}

// ------------------------------------------------------------
// READ INPUT 
// ------------------------------------------------------------

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

void ReadKeyboardInput()
{
	// Use the sf::Keyboard to check for keyboard input
	// sf::Keyboard::Key enum containing all keys
	bool wIsDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);

	// Use sf::Mouse to check for mouse input
	// sf::Mouse:: enum containing all buttons
	bool LMBDown = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

// ------------------------------------------------------------
// Draw sprite at a position to render target
// ------------------------------------------------------------

#include <SFML/Graphics/RenderTarget.hpp>

// Will need a sprite and a target
void DrawToTarget(sf::Sprite& sprite, sf::RenderTarget& target)
{
	// Set position before rendering!
	sf::Vector2f position;
	sprite.setPosition(position);

	// Simply call draw on the target with the sprite
	// A render window is a render target!
	target.draw(sprite);
}


