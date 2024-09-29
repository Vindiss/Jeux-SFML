#include "Components/Achievement.h"

std::string Achievement::SetName(std::string new_name)
{
	name = new_name;
	return name;
}
std::string Achievement::SetDescription(std::string new_description)
{
	description = new_description;
	return description;
}
std::string Achievement::GetName()
{
	return name;
}

bool Achievement::GetUnlocked()
{
	return unlocked;
}

bool Achievement::SetUnlocked(bool etat)
{
	unlocked = etat;
	return unlocked;
}

Achievement* Achievement::CreateAchievement(std::string  _name, std::string  _description, bool _etat)
{
	auto achievement = new Achievement();
	achievement->SetName(_name);
	achievement->SetDescription(_description);
	achievement->SetUnlocked(_etat);
	achievements.push_back(achievement);
	return achievement;
}

