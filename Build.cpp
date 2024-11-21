#include "Build.h"

/*
 * Extract a substring from a string by using an offset to determine how many characters of the
 * original string will be skipped before the desired substring begins
 *
 * @param str the string from which the substring will be extracted
 * @param offset the number of characters within string param to skip before desired substring begins
 * @return a substring of the str parameter
 */
std::string extractSubstring(std::string str, int offset)
{
    std::string substr;
    for (int i = offset; i < str.size(); ++i)
    {
        substr.append(str, i, 1);
    }

    return substr;
}

/*
 * Load a .txt file containing build information into a container
 *
 * @param buildFilePath the path to the .txt file to load
 * @return a container holding all the builds read
 */
std::vector<Build> loadBuilds(std::string buildFilePath)
{
    std::vector<Build> buildList;
    std::vector<std::string> fileLines = retrieveFileContents(buildFilePath); // holds individual lines of the .csv being read

    if (fileLines.size() != 0)
    {
        Build build;
        
        for (int i = 0; i < fileLines.size(); ++i)
        {
            if (fileLines.at(i).find('.') != std::string::npos)
            {
                build.buildID = fileLines.at(i)[0];
            }
            else if (fileLines.at(i).find("Name") != std::string::npos)
            {
                build.buildName = extractSubstring(fileLines.at(i), 6);
            }
            else if (fileLines.at(i).find("Right Hand 1") != std::string::npos)
            {
                build.rHand1 = extractSubstring(fileLines.at(i), 14);
            }
            else if (fileLines.at(i).find("Right Hand 2") != std::string::npos)
            {
                build.rHand2 = extractSubstring(fileLines.at(i), 14);
            }
            else if (fileLines.at(i).find("Right Hand 3") != std::string::npos)
            {
                build.rHand3 = extractSubstring(fileLines.at(i), 14);
            }
            else if (fileLines.at(i).find("Left Hand 1") != std::string::npos)
            {
                build.lHand1 = extractSubstring(fileLines.at(i), 13);
            }
            else if (fileLines.at(i).find("Left Hand 2") != std::string::npos)
            {
                build.lHand2 = extractSubstring(fileLines.at(i), 13);
            }
            else if (fileLines.at(i).find("Left Hand 3") != std::string::npos)
            {
                build.lHand3 = extractSubstring(fileLines.at(i), 13);
            }
            else if (fileLines.at(i).find("Armor Head") != std::string::npos)
            {
                build.armorHead = extractSubstring(fileLines.at(i), 12);
            }
            else if (fileLines.at(i).find("Armor Body") != std::string::npos)
            {
                build.armorBody = extractSubstring(fileLines.at(i), 12);
            }
            else if (fileLines.at(i).find("Armor Arms") != std::string::npos)
            {
                build.armorArms = extractSubstring(fileLines.at(i), 12);
            }
            else if (fileLines.at(i).find("Armor Legs") != std::string::npos)
            {
                build.armorLegs = extractSubstring(fileLines.at(i), 12);
            }
            else if (fileLines.at(i).find("Rings") != std::string::npos)
            {
                build.rings = splitString(extractSubstring(fileLines.at(i), 7), ',');
            }
            else if (fileLines.at(i).find("Spells") != std::string::npos)
            {
                build.spells = splitString(extractSubstring(fileLines.at(i), 8), ',');
            }
            else
            {
                buildList.push_back(build);
                build = {};
            }
        }
        std::cout << "Build data has been stored successfully.\n\n" << std::endl;
    }
    else
    {
        std::cout << "Unable to open " << buildFilePath << ".\n" << std::endl;
    }
    fileLines.clear();

    return buildList;
}

/*
 * Take a buildFilePath .txt file and write a buildList into the file such that it is human-readable
 *
 * @param buildFilePath the path to the .txt file to write to
 * @param buildList the list to be written to the .txt file
 */
void writeBuildToFile(std::string buildFilePath, std::vector<Build> buildList)
{
    int j = 0;
    std::ofstream outputFile;
    outputFile.open(buildFilePath, std::ofstream::out | std::ofstream::trunc);

    if (outputFile.is_open())
    {
        if (buildList.size() != 0)
        {
            for (int i = 0; i < buildList.size(); ++i)
            {
                outputFile << buildList.at(i).buildID << ".\nName: " << buildList.at(i).buildName << '\n';
                if (buildList.at(i).rHand1 != "")
                {
                    outputFile << "\nRight Hand 1: " << buildList.at(i).rHand1;
                }
                if (buildList.at(i).rHand2 != "")
                {
                    outputFile << "\nRight Hand 2: " << buildList.at(i).rHand2;
                }
                if (buildList.at(i).rHand3 != "")
                {
                    outputFile << "\nRight Hand 3: " << buildList.at(i).rHand3;
                }
                if (buildList.at(i).lHand1 != "")
                {
                    outputFile << "\nLeft Hand 1: " << buildList.at(i).lHand1;
                }
                if (buildList.at(i).lHand2 != "")
                {
                    outputFile << "\nLeft Hand 2: " << buildList.at(i).lHand2;
                }
                if (buildList.at(i).lHand3 != "")
                {
                    outputFile << "\nLeft Hand 3: " << buildList.at(i).lHand3;
                }
                outputFile << '\n';
                if (buildList.at(i).armorHead != "")
                {
                    outputFile << "\nArmor Head: " << buildList.at(i).armorHead;
                }
                if (buildList.at(i).armorBody != "")
                {
                    outputFile << "\nArmor Body: " << buildList.at(i).armorBody;
                }
                if (buildList.at(i).armorArms != "")
                {
                    outputFile << "\nArmor Arms: " << buildList.at(i).armorArms;
                }
                if (buildList.at(i).armorLegs != "")
                {
                    outputFile << "\nArmor Legs: " << buildList.at(i).armorLegs;
                }
                if (buildList.at(i).rings.size() > 0)
                {
                    outputFile << "\nRings: ";
                    for (j = 0; j < buildList.at(i).rings.size(); ++j)
                    {
                        outputFile << buildList.at(i).rings.at(j);
                        if (j != buildList.at(i).rings.size() - 1)
                        {
                            outputFile << ", ";
                        }
                    }
                    outputFile << '\n';
                }
                if (buildList.at(i).spells.size() > 0)
                {
                    outputFile << "\nSpells: ";
                    for (j = 0; j < buildList.at(i).spells.size(); ++j)
                    {
                        outputFile << buildList.at(i).spells.at(j);
                        if (j != buildList.at(i).spells.size() - 1)
                        {
                            outputFile << ", ";
                        }
                    }
                }
                outputFile << "\n-\n";
            }
        }
        else
        {
            std::cout << "There are no builds to write to " << buildFilePath << std::endl;
        }
        outputFile.close();
    }
    else
    {
        std::cout << "Can't open file " << buildFilePath << std::endl;
    }
}

/*
 * Display the build information to the console (std::out)
 *
 * @param build Build to display
 */
void displayBuild(Build build)
{
    int i = 0;
    std::cout << "ID: " << build.buildID << std::endl;
    std::cout << "Name: " << build.buildName << '\n' << std::endl;
    if (build.rHand1 != "")
    {
        std::cout << "Right Hand 1: " << build.rHand1 << std::endl;
    }
    if (build.rHand2 != "")
    {
        std::cout << "Right Hand 2: " << build.rHand2 << std::endl;
    }
    if (build.rHand3 != "")
    {
        std::cout << "Right Hand 3: " << build.rHand3 << std::endl;
    }
    if (build.lHand1 != "")
    {
        std::cout << "Left Hand 1: " << build.lHand1 << std::endl;
    }
    if (build.lHand2 != "")
    {
        std::cout << "Left Hand 2: " << build.lHand2 << std::endl;
    }
    if (build.lHand3 != "")
    {
        std::cout << "Left Hand 3: " << build.lHand3 << std::endl;
    }
    std::cout << '\n';
    if (build.armorHead != "")
    {
        std::cout << "Armor Head: " << build.armorHead << std::endl;
    }
    if (build.armorBody != "")
    {
        std::cout << "Armor Body: " << build.armorBody << std::endl;
    }
    if (build.armorArms != "")
    {
        std::cout << "Armor Arms: " << build.armorArms << std::endl;
    }
    if (build.armorLegs != "")
    {
        std::cout << "Armor Legs: " << build.armorLegs << std::endl;
    }
    if (build.rings.size() > 0)
    {
        std::cout << "Rings: ";
        for (i = 0; i < build.rings.size(); ++i)
        {
            std::cout << build.rings.at(i);
            if (i != build.rings.size() - 1)
            {
                std::cout << ", ";
            }
            else
            {
                std::cout << '\n';
            }
        }
        std::cout << '\n';
    }
    if (build.spells.size() > 0)
    {
        std::cout << "Spells: ";
        for (i = 0; i < build.spells.size(); ++i)
        {
            std::cout << build.spells.at(i);
            if (i != build.spells.size() - 1)
            {
                std::cout << ", ";
            }
            else
            {
                std::cout << '\n';
            }
        }
    }
}

Build buildModificationMenu(std::vector<Build> buildList, std::vector<Weapon> weaponList,
    std::vector<Shield> shieldList, std::vector<Armor> armorList, std::vector<Ring> ringList,
    std::vector<Sorcery> sorceryList, std::vector<Miracle> miracleList, std::vector<Pyromancy> pyromancyList, Build build = Build())
{
    int choice = 0;
    int i = 0;
    std::string input;
    bool buildComplete = false;

    if (build.buildID == "0")
    {
        build.buildID = std::to_string(buildList.size() + 1);
    }

    while (!buildComplete && choice != 99)
    {
        std::cout << "----------------------------------------------" << std::endl;
        std::cout << "      ID: " << build.buildID << std::endl;
        std::cout << "   1. Name: " << build.buildName << std::endl;
        std::cout << "\n   2. Right Hand 1: " << build.rHand1 << std::endl;
        std::cout << "   3. Right Hand 2: " << build.rHand2 << std::endl;
        std::cout << "   4. Right Hand 3: " << build.rHand3 << std::endl;
        std::cout << "   5. Left Hand 1: " << build.lHand1 << std::endl;
        std::cout << "   6. Left Hand 2: " << build.lHand2 << std::endl;
        std::cout << "   7. Left Hand 3: " << build.lHand3 << std::endl;
        std::cout << "\n   8. Armor Head: " << build.armorHead << std::endl;
        std::cout << "   9. Armor Body: " << build.armorBody << std::endl;
        std::cout << "   10. Armor Arms: " << build.armorArms << std::endl;
        std::cout << "   11. Armor Legs: " << build.armorLegs << std::endl;
        std::cout << "   12. Rings: ";
        if (build.rings.size() > 1)
        {
            for (i = 0; i < build.rings.size(); ++i)
            {
                if (i != build.rings.size() - 1)
                {
                    std::cout << build.rings.at(i) << ", ";
                }
                else
                {
                    std::cout << build.rings.at(i) << std::endl;
                }
            }
        }
        else
        {
            std::cout << '\n';
        }
        std::cout << "\n   13. Spells: ";
        if (build.spells.size() > 1)
        {
            for (i = 0; i < build.spells.size(); ++i)
            {
                if (i != build.spells.size() - 1)
                {
                    std::cout << build.spells.at(i) << ", ";
                }
                else
                {
                    std::cout << build.spells.at(i) << std::endl;
                }
            }
        }
        else
        {
            std::cout << '\n';
        }
        std::cout << "\n   14. Save Build" << std::endl;
        std::cout << "\n   99. Exit" << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cout << "\n";

        if (choice == 1)
        {
            std::cin.ignore();
            std::cout << "Enter build name: ";
            std::getline(std::cin, input);
            build.buildName = input;
            std::cout << '\n';
        }

        else if (choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7)
        {
            std::cin.ignore();
            std::cout << "Enter 'w' for weapon or 's' for shield: ";
            std::cin >> input;
            if (input == "w" || input == "W")
            {
                std::cout << "\n----------------------------------------------------" << std::endl;
                for (i = 0; i < weaponList.size(); ++i)
                {
                    std::cout << weaponList[i].weaponID << ": " << weaponList[i].weaponName << std::endl;
                }
                std::cout << "----------------------------------------------------\n" << std::endl;
                std::cin.ignore();
                std::cout << "\nEnter weapon ID: ";
                std::cin >> input;
                std::cout << "\n\n";
                for (i = 0; i < weaponList.size(); ++i)
                {
                    if (weaponList[i].weaponID == stoi(input))
                    {
                        if (choice == 2)
                        {
                            build.rHand1 = weaponList.at(i).weaponName;
                        }
                        else if (choice == 3)
                        {
                            build.rHand2 = weaponList.at(i).weaponName;
                        }
                        else if (choice == 4)
                        {
                            build.rHand3 = weaponList.at(i).weaponName;
                        }
                        else if (choice == 5)
                        {
                            build.lHand1 = weaponList.at(i).weaponName;
                        }
                        else if (choice == 6)
                        {
                            build.lHand2 = weaponList.at(i).weaponName;
                        }
                        else if (choice == 7)
                        {
                            build.lHand3 = weaponList.at(i).weaponName;
                        }
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
            else if (input == "s" || input == "S")
            {
                std::cout << "\n----------------------------------------------------" << std::endl;
                for (i = 0; i < shieldList.size(); ++i)
                {
                    std::cout << shieldList[i].shieldID << ": " << shieldList[i].shieldName << std::endl;
                }
                std::cout << "----------------------------------------------------\n" << std::endl;
                std::cin.ignore();
                std::cout << "\nEnter shield ID: ";
                std::cin >> input;
                std::cout << "\n\n";
                for (i = 0; i < shieldList.size(); ++i)
                {
                    if (shieldList[i].shieldID == stoi(input))
                    {
                        if (choice == 2)
                        {
                            build.rHand1 = shieldList.at(i).shieldName;
                        }
                        else if (choice == 3)
                        {
                            build.rHand2 = shieldList.at(i).shieldName;
                        }
                        else if (choice == 4)
                        {
                            build.rHand3 = shieldList.at(i).shieldName;
                        }
                        else if (choice == 5)
                        {
                            build.lHand1 = shieldList.at(i).shieldName;
                        }
                        else if (choice == 6)
                        {
                            build.lHand2 = shieldList.at(i).shieldName;
                        }
                        else if (choice == 7)
                        {
                            build.lHand3 = shieldList.at(i).shieldName;
                        }
                    }
                    else if (stoi(input) > 189 || stoi(input) < 1)
                    {
                        if (i == shieldList.size() - 1)
                        {
                            std::cout << "Shield ID not found.\n" << std::endl;
                        }
                    }
                }
            }
        }

        else if (choice == 14)
        {
            buildComplete = true;
        }

        else if (choice != 99)
        {
            std::cout << "\nInvalid choice.\nPlease enter a number corresponding to the menu's available options.\n" << std::endl;
            std::cin.clear();
        }
    }

    input = "";
    while (input != "Y" && input != "y" && input != "N" && input != "n")
    {
        std::cin.ignore();
        std::cout << "Build will be committed to Build List and output .txt file.\nType 'Y' to confirm or 'N' to cancel: ";
        std::cin >> input;
        if (input == "N" || input == "n")
        {
            build.buildID = "-1";
        }
        else if (input != "Y" && input != "y")
        {
            std::cout << "\nIncorrect input.\n\n\n" << std::endl;
        }
    }

    return build;
}

/*
* Displays the menu that contains commands for displaying and saving build data
*
* @param buildFilePath the path to the .txt file to write to
* @param buildList the list of builds that will be used and modified in the menu
* @param weaponList the list of weapons that will be used in the menu
* @param shieldList the list of shields that will be used in the menu
* @param armorList the list of armor that will be used in the menu
* @param ringList the list of rings that will be used in the menu
* @param sorceryList the list of sorceries that will be used in the menu
* @param miracleList the list of miracles that will be used in the menu
* @param pyromancyList the list of pyromancies that will be used in the menu
*/
void buildMenu(std::string buildFilePath, std::vector<Build> buildList, std::vector<Weapon> weaponList,
    std::vector<Shield> shieldList, std::vector<Armor> armorList, std::vector<Ring> ringList,
    std::vector<Sorcery> sorceryList, std::vector<Miracle> miracleList, std::vector<Pyromancy> pyromancyList)
{
    std::string input;
    int choice = 0;
    int i = 0;

    while (choice != 99)
    {
        std::cout << "**************************************************" << std::endl;
        std::cout << "*              * Build Management *              *" << std::endl;
        std::cout << "*                                                *" << std::endl;
        if (buildList.size() > 0)
        {
            std::cout << "*  1. Display All Currently Saved Builds         *" << std::endl;
        }
        else
        {
            std::cout << "*  1. [Save some builds to use this option!]     *" << std::endl;
        }
        std::cout << "*  2. Display Individual Build by ID             *" << std::endl;
        std::cout << "*  3. Create a New Build                         *" << std::endl;
        std::cout << "*  4. Update a Build                             *" << std::endl;
        std::cout << "*  5. Delete a Build                             *" << std::endl;
        std::cout << "*  99. Return to Main Menu                       *" << std::endl;
        std::cout << "**************************************************" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 1)
        {
            if (buildList.size() > 0)
            {
                std::cout << "\n----------------------------------------------------\n" << std::endl;
                for (i = 0; i < buildList.size(); ++i)
                {
                    displayBuild(buildList.at(i));
                    if (i < buildList.size() - 1)
                    {
                        std::cout << "\n--------------------\n" << std::endl;
                    }
                }
                std::cout << "\n----------------------------------------------------\n" << std::endl;
            }
            else
            {
                std::cout << "There are currently no builds to be displayed." << std::endl;
            }
        }

        else if (choice == 2)
        {
            std::cin.ignore();
            std::cout << "\nEnter the Build ID to be displayed: ";
            std::cin >> input;
            std::cout << "\n\n";
            for (i = 0; i < buildList.size(); ++i)
            {
                if (buildList[i].buildID == input)
                {
                    displayBuild(buildList.at(i));
                    std::cout << "\n";
                }
                else if (stoi(input) > buildList.size() || stoi(input) < 1)
                {
                    if (i == buildList.size() - 1)
                    {
                        std::cout << "Build ID not found.\n" << std::endl;
                    }
                }
            }
            std::cout << "\n";
        }

        else if (choice == 3)
        {
            Build build = buildModificationMenu(buildList, weaponList, shieldList, armorList, ringList, sorceryList, miracleList, pyromancyList);

            if (build.buildID != "-1")
            {
                buildList.push_back(build);
                writeBuildToFile(buildFilePath, buildList);
                std::cout << "\n\nBuild was succesfully saved and exported to file." << std::endl;
            }
            else
            {
                std::cout << "\n\nBuild creation was canceled." << std::endl;
            }
        }

        else if (choice == 4)
        {
            std::cin.ignore();
            std::cout << "Enter the build ID to be modified: ";
            std::cin >> input;
            Build build = buildList.at(stoi(input) - 1);
            Build updatedBuild = buildModificationMenu(buildList, weaponList, shieldList, armorList, ringList, sorceryList, miracleList, pyromancyList, build);

            if (build.buildID != "-1")
            {
                buildList.at(stoi(input) - 1) = updatedBuild;
                writeBuildToFile(buildFilePath, buildList);
                std::cout << "\n\nBuild was succesfully saved and exported to file." << std::endl;
            }
            else
            {
                std::cout << "\n\nBuild update was canceled." << std::endl;
            }
        }

        else if (choice == 5)
        {
            std::cin.ignore();
            std::cout << "Enter the build ID to delete: ";
            std::cin >> input;
            int buildDeleteID = stoi(input) - 1;
            std::cout << "\nAre you sure you want to delete the build " + buildList.at(buildDeleteID).buildName << "?" << std::endl;
            std::cin.ignore();
            std::cout << "Type 'Y' to confirm or 'N' to cancel: ";
            std::cin >> input;
            if (input == "y" || input == "Y")
            {
                buildList.erase(buildList.begin() + (buildDeleteID));
                for (i = 0; i < buildList.size(); ++i)
                {
                    int newID = i + 1;
                    buildList.at(i).buildID = std::to_string(newID);
                }
                writeBuildToFile(buildFilePath, buildList);
            }
            else
            {
                std::cout << "\nBuild deletion was canceled.\n" << std::endl;;
            }
        }
    }
}
