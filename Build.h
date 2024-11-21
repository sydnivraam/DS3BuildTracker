#ifndef BUILD
#define BUILD

#include "CSVParser.h"

struct Build
{
	std::string buildID = "0";
	std::string buildName, rHand1, rHand2, rHand3, lHand1, lHand2, lHand3, armorHead, armorBody, armorArms, armorLegs = "";
	std::vector<std::string> rings;
	std::vector<std::string> spells;
};

std::string extractSubstring(std::string str, int offset);
std::vector<Build> loadBuilds(std::string buildFilePath);
void writeBuildToFile(std::string buildFilePath, std::vector<Build> buildList);
void displayBuild(Build build);
Build buildModificationMenu(std::vector<Build> buildList, std::vector<Weapon> weaponList,
	std::vector<Shield> shieldList, std::vector<Armor> armorList, std::vector<Ring> ringList,
	std::vector<Sorcery> sorceryList, std::vector<Miracle> miracleList, std::vector<Pyromancy> pyromancyList, Build build);
void buildMenu(std::string buildFilePath, std::vector<Build> buildList, std::vector<Weapon> weaponList,
	std::vector<Shield> shieldList, std::vector<Armor> armorList, std::vector<Ring> ringList,
	std::vector<Sorcery> sorceryList, std::vector<Miracle> miracleList, std::vector<Pyromancy> pyromancyList);

#endif
