#include "Save.h"
#include <fstream>
#include <iostream>

void Save::ecrireHighscore(int valeur) {
    std::ofstream fichier("Highscore.txt");

    if (fichier.is_open()) {
        fichier << valeur << std::endl;
        fichier.close();
    }
}

int Save::readHighscore() {
    int highscore = 0;
    std::ifstream fichier("Highscore.txt");

    if (fichier.is_open()) {
        fichier >> highscore;
        fichier.close();
    }

    return highscore;
}

void Save::deleteHighscore() {
    std::ofstream fichier("Highscore.txt");
    
    bool reset = false;
    if (fichier.is_open() && reset == true) {
        fichier << "" << std::endl;
        fichier.close();
  }
}