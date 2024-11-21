#include "Menus.h"

/*
* Displays the menu that contains commands for displaying different weapon and shield data
* 
* @param weaponList the list of weapons that will be used in the menu
* @param shieldList the list of shields that will be used in the menu
*/
void weaponMenu(std::vector<Weapon> weaponList, std::vector<Shield> shieldList)
{
    std::string input; // stores user input
    int choice = 0;
    int i = 0;

    while (choice != 99)
    {
        std::cout << "********************************************" << std::endl;
        std::cout << "*           * Weapons & Shields *          *" << std::endl;
        std::cout << "*                                          *" << std::endl;
        std::cout << "*  1. Display All Weapons                  *" << std::endl;
        std::cout << "*  2. Display All Weapons and Attributes   *" << std::endl;
        std::cout << "*  3. Display Weapons by Type              *" << std::endl;
        std::cout << "*  4. Print Individual Weapon Information  *" << std::endl;
        std::cout << "*  5. Display All Shields                  *" << std::endl;
        std::cout << "*  6. Display All Shields and Attributes   *" << std::endl;
        std::cout << "*  7. Display Shields by Type              *" << std::endl;
        std::cout << "*  8. Print Individual Shield Information  *" << std::endl;
        std::cout << "*  99. Return to Main Menu                 *" << std::endl;
        std::cout << "********************************************" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 1)
        {
            std::cout << "\n----------------------------------------------------" << std::endl;
            for (i = 0; i < weaponList.size(); ++i)
            {
                std::cout << weaponList[i].weaponID << ": " << weaponList[i].weaponName << std::endl;
            }
            std::cout << "----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 2)
        {
            std::cout << "\n----------------------------------------------------" << std::endl;
            for (i = 0; i < weaponList.size(); ++i)
            {
                displayWeapon(weaponList.at(i));
            }
            std::cout << "----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 3)
        {
            std::vector<std::string> weaponTypes =
            { "Axe", "Bow", "Claw", "Crossbow", "Curved Greatsword", "Curved Sword",
            "Dagger", "Fist", "Great Hammer", "Greataxe", "Greatbow", "Greatsword",
            "Halberd", "Hammer", "Katana", "Piercing Sword", "Reaper", "Sacred Chime", 
            "Spear", "Staff", "Straight Sword", "Talisman", "Ultra Greatsword", "Whip" };

            std::cout << "Weapon Types:" << std::endl;
            for (i = 0; i < weaponTypes.size(); ++i)
            {
                std::cout << "  " << i + 1 << ". " << weaponTypes.at(i) << std::endl;
                if (i == 23)
                {
                    std::cout << "\n";
                }
            }

            std::cout << "Select Weapon Type: ";
            std::cin >> input;
            std::cout << std::endl;
            if (stoi(input) > 0 && stoi(input) < 25)
            {
                for (i = 0; i < weaponList.size(); ++i)
                {
                    if (weaponList[i].weaponType == weaponTypes.at(stoi(input) - 1))
                    {
                        displayWeapon(weaponList.at(i));
                    }
                }
            }
            else
            {
                std::cout << "nope.\n" << std::endl;
            }
        }

        else if (choice == 4)
        {
            std::cout << "\nEnter the weapon ID to be displayed: ";
            std::cin >> input;
            std::cout << "\n\n";
            for (i = 0; i < weaponList.size(); ++i)
            {
                if (weaponList[i].weaponID == stoi(input))
                {
                    displayWeapon(weaponList.at(i));
                    std::cout << "\n";
                }
                else if (stoi(input) > 189 || stoi(input) < 1)
                {
                    if (i == weaponList.size() - 1)
                    {
                        std::cout << "Weapon ID not found.\n" << std::endl;
                    }
                }
            }
        }

        else if (choice == 5)
        {
            std::cout << "\n----------------------------------------------------" << std::endl;
            for (i = 0; i < shieldList.size(); ++i)
            {
                std::cout << shieldList[i].shieldID << ": " << shieldList[i].shieldName << std::endl;
            }
            std::cout << "----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 6)
        {
            std::cout << "\n----------------------------------------------------" << std::endl;
            for (i = 0; i < shieldList.size(); ++i)
            {
                displayShield(shieldList.at(i));
                if (i < 62)
                {
                    std::cout << "\n--------------------\n" << std::endl;
                }
                else
                {
                    std::cout << "\n" << std::endl;
                }
            }
            std::cout << "----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 7)
        {
            std::vector<std::string> shieldTypes = { "Small Shield", "Standard Shield", "Greatshield" };

            std::cout << "Shield Types:" << std::endl;
            for (i = 0; i < shieldTypes.size(); ++i)
            {
                std::cout << "  " << i + 1 << ". " << shieldTypes.at(i) << std::endl;
                if (i == 2)
                {
                    std::cout << "\n";
                }
            }

            std::cout << "Select Shield Type: ";
            std::cin >> input;
            std::cout << std::endl;
            if (stoi(input) > 0 && stoi(input) < 4)
            {
                for (i = 0; i < shieldList.size(); ++i)
                {
                    if (shieldList[i].shieldType == shieldTypes.at(stoi(input) - 1))
                    {
                        displayShield(shieldList.at(i));
                    }
                }
            }
            else
            {
                std::cout << "nuh uh.\n" << std::endl;
            }
        }

        else if (choice == 8)
        {
            std::cout << "\nEnter the shield ID to be displayed: ";
            std::cin >> input;
            std::cout << "\n\n";
            for (i = 0; i < shieldList.size(); ++i)
            {
                if (shieldList[i].shieldID == stoi(input))
                {
                    displayShield(shieldList.at(i));
                    std::cout << "\n";
                }
                else if (stoi(input) > 63 || stoi(input) < 1)
                {
                    if (i == shieldList.size() - 1)
                    {
                        std::cout << "Shield ID not found.\n" << std::endl;
                    }
                }
            }
        }

        else if (choice != 99)
        {
            std::cout << "\nInvalid choice.\nPlease enter a number corresponding to the menu's available options.\n" << std::endl;
            std::cin.clear();
        }
    }
}

/*
* Displays the menu that contains commands for displaying different armor and ring data
* 
* @param armorList the list of armor that will be used in the menu
* @param ringList the list of rings that will be used in the menu
*/
void armorMenu(std::vector<Armor> armorList, std::vector<Ring> ringList)
{
    std::string input;
    int choice = 0;
    int i = 0;

    while (choice != 99)
    {
        std::cout << "************************************************" << std::endl;
        std::cout << "*               * Armor & Rings *              *" << std::endl;
        std::cout << "*                                              *" << std::endl;
        std::cout << "*  1. Display All Armor                        *" << std::endl;
        std::cout << "*  2. Display All Armor and Attributes         *" << std::endl;
        std::cout << "*  3. Display Armor Sets                       *" << std::endl;
        std::cout << "*  4. Print Individual Armor Information       *" << std::endl;
        std::cout << "*  5. Display All Rings                        *" << std::endl;
        std::cout << "*  6. Display All Rings and Attributes         *" << std::endl;
        std::cout << "*  7. Display Ring Attributes and Acquisition  *" << std::endl;
        std::cout << "*  8. Print Individual Ring Information        *" << std::endl;
        std::cout << "*  99. Return to Main Menu                     *" << std::endl;
        std::cout << "************************************************" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 1)
        {
            std::cout << "\n----------------------------------------------------\n" << std::endl;
            for (i = 0; i < armorList.size(); ++i)
            {
                std::cout << armorList[i].armorID << ": " << armorList[i].armorName << std::endl;
            }
            std::cout << "\n----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 2)
        {
            std::cout << "\n----------------------------------------------------\n" << std::endl;
            for (i = 0; i < armorList.size(); ++i)
            {
                displayArmor(armorList.at(i));
                if (i < armorList.size() - 1)
                {
                    std::cout << "\n--------------------\n" << std::endl;
                }
            }
            std::cout << "\n----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 3)
        {
            std::vector<std::string> armorSets =
            { "Alva Set", "Antiquated Set", "Archdeacon Set", "Aristocrat's Set",
            "Armor of Favor Set", "Armor of the Sun Set", "Armor of Thorns Set", "Assassin Set",
            "Black Set", "Black Hand Set", "Black Iron Set", "Black Knight Set", "Black Leather Set",
            "Brass Set", "Brigand Set", "Catarina Set", "Cathedral Knight Set", "Chain Set", "Clandestine Set",
            "Cleric Set", "Conjurator Set", "Cornyx's Set", "Court Sorcerer Set", "Dancer's Set", "Dark Set",
            "Deacon Set", "Deserter Set", "Dragonscale Set", "Dragonslayer Set", "Drakeblood Set", "Drang Set",
            "Eastern Set", "Elite Knight Set", "Evangelist Set", "Executioner Set", "Exile Set", "Fallen Knight Set",
            "Faraam Set", "Fire Keeper Set", "Fire Witch Set", "Firelink Set", "Follower Set", "Grave Warden Set",
            "Gundyr's Set", "Hard Leather Set", "Havel's Set", "Herald Set", "Jailer Set", "Karla's Set", "Knight Set",
            "Leather Set", "Leonhard's Set", "Loincloth Set", "Lorian's Set", "Lothric Knight Set", "Maiden Set",
            "Master's Set", "Millwood Set", "Mirrah Set", "Mirrah Chain Set", "Morne's Set", "Nameless Knight Set",
            "Northern Set", "Old Sorcerer Set", "Ordained Set", "Outrider Knight Set", "Painting Guarding Set",
            "Pale Shade Set", "Pontiff Knight Set", "Prayer Set", "Pyromancer Set", "Ragged Mask Set", "Sage's Big Hat Set",
            "Scholar's Robe Set", "Sellsword Set", "Shadow Set", "Silver Knight Set", "Slave Set", "Smough's Set",
            "Sorcerer Set", "Sunless Set", "Sunset Set", "Symbol of Avarice Set", "Thrall Set", "Undead Legion Set",
            "Vilhelm's Set", "Winged Knight Set", "Worker Set", "Xanthous Set", "Wolf Knight Set", "Wolnir's Set" };

            std::cout << "Armor Sets:" << std::endl;
            for (i = 0; i < armorSets.size(); ++i)
            {
                std::cout << "  " << i + 1 << ". " << armorSets.at(i) << std::endl;
                if (i == 90)
                {
                    std::cout << "\n";
                }
            }

            std::cout << "Select Armor Set: ";
            std::cin >> input;
            std::cout << std::endl;
            if (stoi(input) > 0 && stoi(input) < 92)
            {
                for (i = 0; i < armorList.size(); ++i)
                {
                    if (armorList[i].armorSet == armorSets.at(stoi(input) - 1))
                    {
                        displayArmor(armorList.at(i));
                    }
                }
            }
            else
            {
                std::cout << "probably not.\n" << std::endl;
            }
        }

        else if (choice == 4)
        {
            std::cout << "\nEnter the armor ID to be displayed: ";
            std::cin >> input;
            std::cout << "\n\n";
            for (i = 0; i < armorList.size(); ++i)
            {
                if (armorList[i].armorID == stoi(input))
                {
                    displayArmor(armorList.at(i));
                    std::cout << "\n";
                }
                else if (stoi(input) > armorList.size() || stoi(input) < 1)
                {
                    if (i == armorList.size() - 1)
                    {
                        std::cout << "Armor ID not found.\n" << std::endl;
                    }
                }
            }
        }

        else if (choice == 5)
        {
            std::cout << "\n----------------------------------------------------\n" << std::endl;
            for (i = 0; i < ringList.size(); ++i)
            {
                std::cout << ringList[i].ringID << ": " << ringList[i].ringName << std::endl;
            }
            std::cout << "\n----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 6)
        {
            std::cout << "\n----------------------------------------------------\n" << std::endl;
            for (i = 0; i < ringList.size(); ++i)
            {
                displayRing(ringList.at(i));
                if (i < ringList.size() - 1)
                {
                    std::cout << "\n--------------------\n" << std::endl;
                }
            }
            std::cout << "\n----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 7)
        {
            std::cout << "\n----------------------------------------------------\n" << std::endl;
            for (i = 0; i < ringList.size(); ++i)
            {
                displayRingWithAcq(ringList.at(i));
                if (i < ringList.size() - 1)
                {
                    std::cout << "\n--------------------\n" << std::endl;
                }
            }
            std::cout << "\n----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 8)
        {
            std::cout << "\nEnter the ring ID to be displayed: ";
            std::cin >> input;
            std::cout << "\n\n";
            for (i = 0; i < ringList.size(); ++i)
            {
                if (ringList[i].ringID == stoi(input))
                {
                    displayRingWithAcq(ringList.at(i));
                    std::cout << "\n";
                }
                else if (stoi(input) > ringList.size() || stoi(input) < 1)
                {
                    if (i == ringList.size() - 1)
                    {
                        std::cout << "Ring ID not found.\n" << std::endl;
                    }
                }
            }
        }

        else if (choice != 99)
        {
            std::cout << "\nInvalid choice.\nPlease enter a number corresponding to the menu's available options.\n" << std::endl;
            std::cin.clear();
        }
    }
}

/*
* Displays the menu that contains commands for displaying different magic data
* 
* @param sorceryList the list of sorceries that will be used in the menu
* @param miracleList the list of miracles that will be used in the menu
* @param pyromancyList the list of pyromancies that will be used in the menu
*/
void magicMenu(std::vector<Sorcery> sorceryList, std::vector<Miracle> miracleList, std::vector<Pyromancy> pyromancyList)
{
    std::string input;
    int choice = 0;
    int i = 0;

    while (choice != 99)
    {
        std::cout << "**********************************************" << std::endl;
        std::cout << "*                  * Magic *                 *" << std::endl;
        std::cout << "*                                            *" << std::endl;
        std::cout << "*  1. Display All Sorceries                  *" << std::endl;
        std::cout << "*  2. Display All Sorceries and Attributes   *" << std::endl;
        std::cout << "*  3. Print Individual Sorcery Information   *" << std::endl;
        std::cout << "*  4. Display All Miracles                   *" << std::endl;
        std::cout << "*  5. Display All Miracles and Attributes    *" << std::endl;
        std::cout << "*  6. Print Individual Miracle Information   *" << std::endl;
        std::cout << "*  7. Display All Pyromancies                *" << std::endl;
        std::cout << "*  8. Display All Pyromancies and Attributes *" << std::endl;
        std::cout << "*  9. Print Individual Pyromancy Information *" << std::endl;
        std::cout << "*  99. Return to Main Menu                   *" << std::endl;
        std::cout << "**********************************************" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cout << "\n";

        if (choice == 1)
        {
            std::cout << "\n----------------------------------------------------\n" << std::endl;
            for (i = 0; i < sorceryList.size(); ++i)
            {
                std::cout << sorceryList[i].sorceryID << ": " << sorceryList[i].sorceryName << std::endl;
            }
            std::cout << "\n----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 2)
        {
            std::cout << "\n----------------------------------------------------\n" << std::endl;
            for (i = 0; i < sorceryList.size(); ++i)
            {
                displaySorcery(sorceryList.at(i));
                if (i < sorceryList.size() - 1)
                {
                    std::cout << "\n--------------------\n" << std::endl;
                }
            }
            std::cout << "\n----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 3)
        {
            std::cout << "\nEnter the Sorcery ID to be displayed: ";
            std::cin >> input;
            std::cout << "\n\n";
            for (i = 0; i < sorceryList.size(); ++i)
            {
                if (sorceryList[i].sorceryID == stoi(input))
                {
                    displaySorcery(sorceryList.at(i));
                    std::cout << "\n";
                }
                else if (stoi(input) > sorceryList.size() || stoi(input) < 1)
                {
                    if (i == sorceryList.size() - 1)
                    {
                        std::cout << "Sorcery ID not found.\n" << std::endl;
                    }
                }
            }
            std::cout << "\n";
        }

        else if (choice == 4)
        {
            std::cout << "\n----------------------------------------------------\n" << std::endl;
            for (i = 0; i < miracleList.size(); ++i)
            {
                std::cout << miracleList[i].miracleID << ": " << miracleList[i].miracleName << std::endl;
            }
            std::cout << "\n----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 5)
        {
            std::cout << "\n----------------------------------------------------\n" << std::endl;
            for (i = 0; i < miracleList.size(); ++i)
            {
                displayMiracle(miracleList.at(i));
                if (i < miracleList.size() - 1)
                {
                    std::cout << "\n--------------------\n" << std::endl;
                }
            }
            std::cout << "\n----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 6)
        {
            std::cout << "\nEnter the Miracle ID to be displayed: ";
            std::cin >> input;
            std::cout << "\n\n";
            for (i = 0; i < miracleList.size(); ++i)
            {
                if (miracleList[i].miracleID == stoi(input))
                {
                    displayMiracle(miracleList.at(i));
                    std::cout << "\n";
                }
                else if (stoi(input) > 38 || stoi(input) < 1)
                {
                    if (i == miracleList.size() - 1)
                    {
                        std::cout << "Miracle ID not found.\n" << std::endl;
                    }
                }
            }
            std::cout << "\n";
        }

        else if (choice == 7)
        {
            std::cout << "\n----------------------------------------------------\n" << std::endl;
            for (i = 0; i < pyromancyList.size(); ++i)
            {
                std::cout << pyromancyList[i].pyromancyID << ": " << pyromancyList[i].pyromancyName << std::endl;
            }
            std::cout << "\n----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 8)
        {
            std::cout << "\n----------------------------------------------------\n" << std::endl;
            for (i = 0; i < pyromancyList.size(); ++i)
            {
                displayPyromancy(pyromancyList.at(i));
                if (i < pyromancyList.size() - 1)
                {
                    std::cout << "\n--------------------\n" << std::endl;
                }
            }
            std::cout << "\n----------------------------------------------------\n" << std::endl;
        }

        else if (choice == 9)
        {
            std::cout << "\nEnter the Pyromancy ID to be displayed: ";
            std::cin >> input;
            std::cout << "\n\n";
            for (i = 0; i < pyromancyList.size(); ++i)
            {
                if (pyromancyList[i].pyromancyID == stoi(input))
                {
                    displayPyromancy(pyromancyList.at(i));
                    std::cout << "\n";
                }
                else if (stoi(input) > 30 || stoi(input) < 1)
                {
                    if (i == pyromancyList.size() - 1)
                    {
                        std::cout << "Pyromancy ID not found.\n" << std::endl;
                    }
                }
            }
            std::cout << "\n";
        }

        else if (choice != 99)
        {
            std::cout << "\nInvalid choice.\nPlease enter a number corresponding to the menu's available options.\n" << std::endl;
            std::cin.clear();
        }
    }
}
