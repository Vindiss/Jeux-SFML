#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


#include "GameObject.h"
#include "Vector2.h"
#include "WindowConfig.h"
#include "Player.h"
#include "Bullet.h"

class Input
{
protected:

    WindowConfig windowConfig;
    Maths::Vector2f MoveVector = Maths::Vector2f (7.f,7.f);

public:
    enum InputType { Keyboard, Mouse };

    InputType inputType;

    sf::Keyboard::Key key;
    sf::Mouse::Button mouseButton;

    bool inputBool;
    virtual void execute(GameObject* actor, float sizeActor, sf::RenderWindow* window, std::vector<GameObject*>* gameObjects) {};

    // Constructeur pour le clavier
    Input(sf::Keyboard::Key k1, bool ib)
        : inputType(Keyboard), key(k1), mouseButton(sf::Mouse::ButtonCount), inputBool(ib) {}

    // Constructeur pour la souris
    Input(sf::Mouse::Button mb, bool ib)
        : inputType(Mouse), key(sf::Keyboard::Unknown), mouseButton(mb), inputBool(ib) {}
};




class DeplacementUp : public Input
{
public:
    DeplacementUp()
        : Input(sf::Keyboard::Up, false) {}

    void execute(GameObject* actor, float sizeActor, sf::RenderWindow* window, std::vector<GameObject*>* gameObjects) override
    {
        if ((actor->GetPosition().y > (0 + sizeActor / 2)))
        {
            Maths::Vector2f NewPosition = Maths::Vector2f(actor->GetPosition().x, actor->GetPosition().y - MoveVector.y);
            actor->getComponent<Player>()->Move(NewPosition,"up", gameObjects);
        }
    }
};

class DeplacementDown : public Input
{
public:
    DeplacementDown()
        : Input(sf::Keyboard::Down, false) {}

    void execute(GameObject* actor, float sizeActor, sf::RenderWindow* window, std::vector<GameObject*>* gameObjects) override
    {
        if ((actor->GetPosition().y + sizeActor / 2) < windowConfig.longueur)
        {
            Maths::Vector2f NewPosition = Maths::Vector2f(actor->GetPosition().x, actor->GetPosition().y + MoveVector.y);
            actor->getComponent<Player>()->Move(NewPosition, "down", gameObjects);
        }
    }
};

class DeplacementLeft : public Input
{
public:
    DeplacementLeft()
        : Input(sf::Keyboard::Left, false) {}

    void execute(GameObject* actor, float sizeActor, sf::RenderWindow* window, std::vector<GameObject*>* gameObjects) override
    {
        if (actor->GetPosition().x > (0 + sizeActor / 2)) 
        {
            Maths::Vector2f NewPosition = Maths::Vector2f(actor->GetPosition().x - MoveVector.x, actor->GetPosition().y);
            actor->getComponent<Player>()->Move(NewPosition, "left", gameObjects);
        }
    }
};

class DeplacementRight : public Input
{
public:
    DeplacementRight()
        : Input(sf::Keyboard::Right, false) {}

    void execute(GameObject* actor, float sizeActor, sf::RenderWindow* window, std::vector<GameObject*>* gameObjects) override
    {
        if ((actor->GetPosition().x + sizeActor / 2) < windowConfig.largeur)
        {
            Maths::Vector2f NewPosition = Maths::Vector2f(actor->GetPosition().x + MoveVector.x, actor->GetPosition().y);
            actor->getComponent<Player>()->Move(NewPosition, "right", gameObjects);
        }
    }
};

class Shoot : public Input
{
public:
    Shoot()
        : Input(sf::Mouse::Left, false) {}

    void execute(GameObject* actor, float sizeActor, sf::RenderWindow* window, std::vector<GameObject*>* gameObjects) override
    {
        std::cout << "Pan !" << std::endl;
    }
};