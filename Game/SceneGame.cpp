﻿#include <chrono>

#include "eventGame.h"
#include "Scenes.h"
#include "Game.h"
#include "LevelChoice.h"
#include "EnemySpawn.h"
#include "Button.h"

int SceneGame::LoopGame(sf::RenderWindow* window)
{
	Game game;
	Scene scene;
	EventFunctionsGame eventFunction;

	// Bouton Pause
	Button buttonClass;
	GameObject* buttonPause = buttonClass.createButtonObj(&scene, "Pause");
	if (buttonPause == nullptr) {
		return 1;
	}
	eventFunction.buttonList.push_back(buttonPause);

	LevelChoice(&scene);
	GameObject* player = scene.CreatePlayer(ObjectName::PlayerName, Maths::Vector2f(375, 5), 200, 20, 30);

	sf::Clock clock;
	auto time_for_enemy_spawn = std::chrono::high_resolution_clock::now();

	sf::Texture background = scene.GetTetxure()["texture_floor"];

	// Cr�er un sprite avec la texture charg�e
	sf::Sprite sprite(background);

	clock.restart();

	bool sceneOn = true;
	bool pause = false;
	while (sceneOn)
	{
		if (player->getComponent<Player>()->isDead(scene.GetGameObjects()))
		{
			return 0;
		}
		player->getComponent<Player>()->SetAngle(window);
		// R�cup�rer la taille de la fen�tre
		sf::Vector2u windowSize = window->getSize();

		// Redimensionner le sprite pour qu'il remplisse la fen�tre
		sprite.setScale((float)windowSize.x / sprite.getTexture()->getSize().x, (float)windowSize.y / sprite.getTexture()->getSize().y);

		sf::Time deltaTime = clock.restart();
		float deltaTimeMilliseconds = deltaTime.asMilliseconds();

		if (pause == false)
		{
			sceneOn = eventFunction.loopEvent(player, 50, window, game.HorizontalOrigin, game.VerticalOrigin, &scene, deltaTimeMilliseconds, &pause); //Enlever pour pause

			time_for_enemy_spawn = CheckIfIsTimeToEnemySpawn(&scene, time_for_enemy_spawn); //Enlever pour pause

			scene.Update(deltaTimeMilliseconds); //Enlever pour pause
		}
		

		window->clear();
		// Dessiner le sprite
		window->draw(sprite);

		scene.Render(window);
		window->display();
	}
	return 0;
}
