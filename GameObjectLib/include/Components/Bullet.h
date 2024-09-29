#pragma once

#include "GameObject.h"
#include "SFML/Audio.hpp"

class Bullet : public Component
{
public:
	Bullet();
	~Bullet();

	void SetVectorDirector(Maths::Vector2<float> new_vector_director) { vector_director = new_vector_director; }
	Maths::Vector2f GetVectorDirector() { return vector_director; }

	void SetPlayer(GameObject* new_player) { player = new_player;  }
	GameObject* GetPlayer() { return player; }

	void Move(std::vector<GameObject*> gameObjects, float deltaTimeMillisecondes);
	//void Delete(std::vector<GameObject*> gameObjects);
	void PlaySound();
	void StopSound();
	void Move(std::vector<GameObject*>* gameObjects, float deltaTimeMillisecondes);
	void Update(float deltaTimeMillisecondes, std::vector<GameObject*>* gameObjects) override;
	bool Delete(std::vector<GameObject*>* gameObjects);
	void isOut(std::vector<GameObject*>* gameObjects);

private:
	Maths::Vector2f vector_director;
	float deltaTimeMillisecondes;
	float sizeWindow;
	float tailleParDefault = 50;
	sf::SoundBuffer* soundBufferBullet;
	sf::Sound* soundBullet;
	GameObject* player;
};

