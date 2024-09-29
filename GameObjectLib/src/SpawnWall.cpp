#include "GameObject.h"
#include "Scene.h"
#include <iostream>
#include <random>
#include <chrono>
#include "Components/ObjectName.h"


void SpawnWall(Scene* scene) {
    int largeur = 800;
    int longueur = 800;
    int sizeWall = 50;

    if (scene->GetLevel() == 1)
    {
        Maths::Vector2f wall_pos(sizeWall * 5, sizeWall * 3);
        GameObject* wall1 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 6, sizeWall * 3);
        GameObject* wall2 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 7, sizeWall * 3);
        GameObject* wall3 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 8, sizeWall * 3);
        GameObject* wall4 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 9, sizeWall * 3);
        GameObject* wall5 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 10, sizeWall * 3);
        GameObject* wall6 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 11, sizeWall * 3);
        GameObject* wall7 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 5, sizeWall * 4);
        GameObject* wall8 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 11, sizeWall * 4);

        GameObject* wall9 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 5, sizeWall * 13);
        GameObject* wall10 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 6, sizeWall * 13);
        GameObject* wall11 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 7, sizeWall * 13);
        GameObject* wall12 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 8, sizeWall * 13);
        GameObject* wall13 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 9, sizeWall * 13);
        GameObject* wall14 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 10, sizeWall * 13);
        GameObject* wall15 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 11, sizeWall * 13);
        GameObject* wall16 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 5, sizeWall * 12);
        GameObject* wall17 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 11, sizeWall * 12);
        GameObject* wall18 = scene->CreateWall(ObjectName::WallName, wall_pos);

        std::cout << "facile" << std::endl;
    }
    else if (scene->GetLevel() == 2)
    {
        Maths::Vector2f wall_pos(sizeWall * 6, sizeWall * 2);
        GameObject* wall1 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 7, sizeWall * 2);
        GameObject* wall2 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 8, sizeWall * 2);
        GameObject* wall3 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 9, sizeWall * 2);
        GameObject* wall4 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 10, sizeWall * 2);
        GameObject* wall5 = scene->CreateWall(ObjectName::WallName, wall_pos);

        wall_pos.SetXY(sizeWall * 2, sizeWall * 6);
        GameObject* wall6 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 2, sizeWall * 7);
        GameObject* wall7 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 2, sizeWall * 8);
        GameObject* wall8 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 2, sizeWall * 9);
        GameObject* wall9 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 2, sizeWall * 10);
        GameObject* wall10 = scene->CreateWall(ObjectName::WallName, wall_pos);

        wall_pos.SetXY(sizeWall * 14, sizeWall * 6);
        GameObject* wall11 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 14, sizeWall * 7);
        GameObject* wall12 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 14, sizeWall * 8);
        GameObject* wall13 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 14, sizeWall * 9);
        GameObject* wall14 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 14, sizeWall * 10);
        GameObject* wall15 = scene->CreateWall(ObjectName::WallName, wall_pos);

        wall_pos.SetXY(sizeWall * 6, sizeWall * 14);
        GameObject* wall16 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 7, sizeWall * 14);
        GameObject* wall17 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 8, sizeWall * 14);
        GameObject* wall18 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 9, sizeWall * 14);
        GameObject* wall19 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 10, sizeWall * 14);
        GameObject* wall20 = scene->CreateWall(ObjectName::WallName, wall_pos);

        wall_pos.SetXY(sizeWall * 8, sizeWall * 7);
        GameObject* wall21 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 7, sizeWall * 8);
        GameObject* wall22 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 8, sizeWall * 8);
        GameObject* wall23 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 9, sizeWall * 8);
        GameObject* wall24 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 8, sizeWall * 9);
        GameObject* wall25 = scene->CreateWall(ObjectName::WallName, wall_pos);

        std::cout << "normale" << std::endl;
    }

    else if (scene->GetLevel() == 3)
    {
        Maths::Vector2f wall_pos(sizeWall * 2, sizeWall * 2);
        GameObject* wall1 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 3, sizeWall * 3);
        GameObject* wall2 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 4, sizeWall * 4);
        GameObject* wall3 = scene->CreateWall(ObjectName::WallName, wall_pos);

        wall_pos.SetXY(sizeWall * 8, sizeWall * 2);
        GameObject* wall4 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 8, sizeWall * 3);
        GameObject* wall5 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 8, sizeWall * 4);
        GameObject* wall6 = scene->CreateWall(ObjectName::WallName, wall_pos);

        wall_pos.SetXY(sizeWall * 14, sizeWall * 2);
        GameObject* wall7 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 13, sizeWall * 3);
        GameObject* wall8 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 12, sizeWall * 4);
        GameObject* wall9 = scene->CreateWall(ObjectName::WallName, wall_pos);

        wall_pos.SetXY(sizeWall * 2, sizeWall * 8);
        GameObject* wall10 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 3, sizeWall * 8);
        GameObject* wall11 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 4, sizeWall * 8);
        GameObject* wall12 = scene->CreateWall(ObjectName::WallName, wall_pos);

        wall_pos.SetXY(sizeWall * 12, sizeWall * 8);
        GameObject* wall13 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 13, sizeWall * 8);
        GameObject* wall14 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 14, sizeWall * 8);
        GameObject* wall15 = scene->CreateWall(ObjectName::WallName, wall_pos);

        wall_pos.SetXY(sizeWall * 2, sizeWall * 14);
        GameObject* wall16 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 3, sizeWall * 13);
        GameObject* wall17 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 4, sizeWall * 12);
        GameObject* wall18 = scene->CreateWall(ObjectName::WallName, wall_pos);

        wall_pos.SetXY(sizeWall * 8, sizeWall * 12);
        GameObject* wall19 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 8, sizeWall * 13);
        GameObject* wall20 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 8, sizeWall * 14);
        GameObject* wall21 = scene->CreateWall(ObjectName::WallName, wall_pos);

        wall_pos.SetXY(sizeWall * 12, sizeWall * 12);
        GameObject* wall22 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 13, sizeWall * 13);
        GameObject* wall23 = scene->CreateWall(ObjectName::WallName, wall_pos);
        wall_pos.SetXY(sizeWall * 14, sizeWall * 14);
        GameObject* wall24 = scene->CreateWall(ObjectName::WallName, wall_pos);

        wall_pos.SetXY(sizeWall * 8, sizeWall * 8);
        GameObject* wall25 = scene->CreateWall(ObjectName::WallName, wall_pos);

        std::cout << "difficile" << std::endl;
    }
}