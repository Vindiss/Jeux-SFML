#pragma once
#include <string>
#include <vector>

class Achievement
{
public:
	Achievement() = default;
	~Achievement() = default;

	std::string SetName(std::string new_name);
	std::string SetDescription(std::string new_description);
	std::string GetName();
	bool GetUnlocked();
	bool SetUnlocked(bool etat);
	Achievement* CreateAchievement(std::string _name, std::string _description, bool _etat);

private:
	std::string name;
	std::string description;
	bool unlocked;
	std::vector<Achievement*> achievements;
};