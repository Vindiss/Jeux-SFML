#include "LevelChoice.h"
#include "Scene.h"
#include <random>
#include <chrono>
#include "SpawnWall.h"

void LevelChoice(Scene* scene)
{
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937 gen(seed);
	std::uniform_int_distribution<int> dist(1, 3);
	scene->SetLevel(dist(gen));

	if (scene->GetLevel() == 1)
	{
		scene->SetTexture("texture_floor", "Assets/Image/floor-1.png");
		scene->SetTexture("texture_enemy", "Assets/Image/zombie.png");
		scene->SetTexture("texture_player", "Assets/Image/player.png");
		scene->SetTexture("texture_life_bar", "Assets/Image/life_bar.png");
		scene->SetTexture("texture_wall-1", "Assets/Image/wall-1.png");
		scene->SetTexture("texture_bullet", "Assets/Image/bullet.png");

		SpawnWall(scene);
	}
	else if (scene->GetLevel() == 2)
	{
		scene->SetTexture("texture_floor", "Assets/Image/floor-2.png");
		scene->SetTexture("texture_enemy", "Assets/Image/ghost.png");
		scene->SetTexture("texture_player", "Assets/Image/player.png");
		scene->SetTexture("texture_life_bar", "Assets/Image/life_bar.png");
		scene->SetTexture("texture_wall-1", "Assets/Image/wall-2.png");
		scene->SetTexture("texture_bullet", "Assets/Image/bullet.png");

		SpawnWall(scene);
	}
	else if (scene->GetLevel() == 3)
	{
		scene->SetTexture("texture_floor", "Assets/Image/floor-3.png");
		scene->SetTexture("texture_enemy", "Assets/Image/demon.png");
		scene->SetTexture("texture_player", "Assets/Image/player.png");
		scene->SetTexture("texture_life_bar", "Assets/Image/life_bar.png");
		scene->SetTexture("texture_wall-1", "Assets/Image/wall-3.png");
		scene->SetTexture("texture_bullet", "Assets/Image/bullet.png");

		SpawnWall(scene);
	}
}
