/* Demo Game 2 */
#include "player.h"

void Player::initVariables()
{
    this->movementSpeed = 10.f;
}

void Player::initShapes()
{
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setSize(sf::Vector2f(50.f,50.f));
}

Player::Player(float x, float y)
{
    this->shape.setPosition(x,y);

    this->initVariables();
    this->initShapes();
}

Player::~Player()
{

}

void Player::updateInput()
{
    // Keyboard Input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->shape.move(-this->movementSpeed,0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->shape.move(this->movementSpeed,0.f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->shape.move(0.f,-this->movementSpeed);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->shape.move(0.f,this->movementSpeed);
    }
}

void Player::updateWindowBounceCollision(const sf::RenderTarget* target)
{
    // Left
    sf::FloatRect playerBounds = this->shape.getGlobalBounds();
    if(playerBounds.left <= 0.f)
    {
        this->shape.setPosition(0.f,playerBounds.top);
    }
    // Right
    else if((playerBounds.left + playerBounds.width) >= target->getSize().x)
    {
        this->shape.setPosition(target->getSize().x-playerBounds.width,playerBounds.top);
    }

    // Top
    if(playerBounds.top <= 0.f)
    {
        this->shape.setPosition(playerBounds.left,0.f);
    }
    // Bottom
    else if((playerBounds.top + playerBounds.height) >= target->getSize().y)
    {
        this->shape.setPosition(playerBounds.left,target->getSize().y-playerBounds.height);
    }
}

void Player::update(const sf::RenderTarget* target)
{
    this->updateInput();

    // Window Bounce Collision
    this->updateWindowBounceCollision(target);
}

void Player::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}
