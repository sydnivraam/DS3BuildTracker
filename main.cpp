//============================================================================
// Name        : DS3BuildTracker
// Author      : Syd Nivraam
// Version     : 0.3
// Description : Hello World in C++, Ansi-style; reads data from .csv files in order for user to create and save DS3 builds.
// 
// Credits     : Weapons spreadsheet by u/D_VoN on reddit https://www.reddit.com/r/darksouls3/comments/4fo66t/dark_souls_iii_weapons_spreadsheet/
//             : Armor spreadsheet by naiyt on GoogleDocs https://docs.google.com/spreadsheets/d/1OVGVtjCgkoFPEvtCKHx7dh9tXVplMbft4iUSY_Inm_I/edit#gid=0
//             : Rings spreadsheet self made using data from https://darksouls3.wiki.fextralife.com/Rings
//             : Sorceries spreadsheet self made using data from https://darksouls3.wiki.fextralife.com/Sorceries
//             : Miracles spreadsheet self made using data from https://darksouls3.wiki.fextralife.com/Miracles
//             : Pyromancies spreadsheet self made using data from https://darksouls3.wiki.fextralife.com/Pyromancies
//             : Data from https://darksouls.fandom.com/wiki/Category:Dark_Souls_III is used for some elements where FextraLife was lacking in data
//============================================================================

#include "CSVParser.h"
#include "Menus.h"
#include "Displays.h"
#include "Build.h"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

const string CSV_PATH_WEAPON = "assets/Dark_Souls_3_Weapons_Normal.csv";
const string CSV_PATH_SHIELD = "assets/Dark_Souls_3_Shields.csv";
const string CSV_PATH_ARMOR = "assets/Dark_Souls_3_Armor_Data.csv";
const string CSV_PATH_RING = "assets/Dark_Souls_3_Rings.csv";
const string CSV_PATH_SORCERY = "assets/Dark_Souls_3_Sorceries.csv";
const string CSV_PATH_MIRACLE = "assets/Dark_Souls_3_Miracles.csv";
const string CSV_PATH_PYROMANCY = "assets/Dark_Souls_3_Pyromancies.csv";
const string TXT_PATH_BUILD = "assets/Your_Saved_Builds.txt";

//============================================================================
// Main function
//============================================================================

int main()
{
    vector<Weapon> weaponList = loadWeapons(CSV_PATH_WEAPON);
    vector<Shield> shieldList = loadShields(CSV_PATH_SHIELD);
    vector<Armor> armorList = loadArmor(CSV_PATH_ARMOR);
    vector<Ring> ringList = loadRings(CSV_PATH_RING);
    vector<Sorcery> sorceryList = loadSorceries(CSV_PATH_SORCERY);
    vector<Miracle> miracleList = loadMiracles(CSV_PATH_MIRACLE);
    vector<Pyromancy> pyromancyList = loadPyromancies(CSV_PATH_PYROMANCY);
    vector<Build> buildList = loadBuilds(TXT_PATH_BUILD);

    int choice = 0;

    cout << "Welcome to Dark Souls 3 Build Tracker\n" << endl;
    while (choice != 99)
    {
        cout << "********************************************" << endl;
        cout << "*                  ******                  *" << endl;
        cout << "*              ~* Main Menu *~             *" << endl;
        cout << "*                  ******                  *" << endl;
        cout << "*                                          *" << endl;
        cout << "*  1. Weapons & Shields                    *" << endl;
        cout << "*  2. Armor & Rings                        *" << endl;
        cout << "*  3. Magic                                *" << endl;
        cout << "*  4. Build Management                     *" << endl;
        cout << "*                                          *" << endl;
        cout << "*  99. Exit                                *" << endl;
        cout << "*                                          *" << endl;
        cout << "********************************************" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << "\n";

        if (choice == 1)
        {
            weaponMenu(weaponList, shieldList);
        }

        else if (choice == 2)
        {
            armorMenu(armorList, ringList);
        }

        
        else if (choice == 3)
        {
            magicMenu(sorceryList, miracleList, pyromancyList);
        }

        else if (choice == 4)
        {
            buildMenu(TXT_PATH_BUILD, buildList, weaponList, shieldList, armorList, ringList, sorceryList, miracleList, pyromancyList);
        }
         
        else if (choice != 99)
        {
            cout << "\nInvalid choice.\nPlease enter a number corresponding to the menu's available options.\n" << endl;
            cin.clear();
        }
    }

    cout << "\nGood bye.\n";
    return 0;
}
