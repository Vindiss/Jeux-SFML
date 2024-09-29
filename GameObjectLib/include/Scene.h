#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>

#include "Components/ObjectName.h"
#include "Maths/Vector2.h"

class GameObject;

class Scene
{
public:
	Scene() = default;
	virtual ~Scene() = default;

	std::vector<GameObject*>* GetGameObjects() { return &gameObjects; }
	std::unordered_map<std::string, sf::Texture> GetTetxure() { return texture; }
	int GetLevel() { return level; }

	void Update(float deltaTimeMillisecondes);
	void Render(sf::RenderWindow* _window);

	GameObject* CreateGameObject(const ObjectName& _name);

	GameObject* CreatePlayer(const ObjectName& name, const Maths::Vector2<float>& position, int hp, int speed, int damage);

	GameObject* CreateEnemy(const ObjectName& name, const Maths::Vector2<float>& position, int hp, int speed, int damage);

	GameObject* CreateBulletGameObject(const ObjectName& name, const Maths::Vector2<float>& position, float& deltaTimeMilliseconds, const sf::Color color, Maths::Vector2f vector_director, GameObject* player);

	GameObject* CreateWall(const ObjectName& name, const Maths::Vector2<float>& position);

	int SetTexture(std::string nom_texture, std::string chemin_fichier);
	void SetLevel(int new_level) { level = new_level; }

	GameObject* CreateButton(const ObjectName& name, const Maths::Vector2<float>& position, const sf::Color color, const sf::Color colorHover, const sf::Color colorClick, sf::Vector2f size, std::string type);

private:
	std::vector<GameObject*> gameObjects;
	std::unordered_map<std::string, sf::Texture> texture;
	int level = 0;
};
