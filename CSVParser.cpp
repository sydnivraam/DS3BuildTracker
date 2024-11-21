#include "CSVParser.h"

/*
 * method for string splitting in loading methods
 * reference: https://stackoverflow.com/a/46931770/19361783
 *
 * @param str String to be split
 * @param delimiter Char used to determine where the string is to be split
 */
std::vector<std::string> splitString(std::string str, char delimiter)
{
    std::vector<std::string> results; // stores individual substrings of str param resulting from the split
    std::stringstream ss(str); // creates stream to parse the string in str param 
    std::string item; // holds the current substring to be stored in results vector

    while (getline(ss, item, delimiter))
    {
        results.push_back(item);
    }

    return results;
}

/*
 * method for reading the contents of a .csv file
 *
 * @param csvPath .csv file to be read
 * @return a container of lines from the file
 */
std::vector<std::string> retrieveFileContents(std::string csvPath)
{
    std::cout << "--- Loading file " << csvPath << " ---\n" << std::endl;

    std::vector<std::string> fileLines; // holds individual lines of the .csv being read
    std::ifstream csvFile; // instance to load the .csv
    csvFile.open(csvPath);

    if (csvFile.is_open())
    {
        while (csvFile.good())
        {
            std::string line; // holds the current line being read
            std::getline(csvFile, line);
            // add the line to fileLines if the line is not empty/blank
            if (line != "")
            {
                fileLines.push_back(line);
            }
        }
        csvFile.close();

        // checks that data was actually read from the file
        // i.e. if fileLines is empty, then nothing was read from the file
        if (fileLines.size() == 0)
        {
            std::cout << "No data was found in " << csvPath << "." << std::endl;
        }
    }

    return fileLines;
}

/*
 * Load a .csv file containing weapon information into a container
 *
 * @param csvPath the path to the .csv file to load
 * @return a container holding all the weapons read
 */
std::vector<Weapon> loadWeapons(std::string csvPath)
{
    std::vector<Weapon> weaponList;
    std::vector<std::string> fileLines = retrieveFileContents(csvPath); // holds individual lines of the .csv being read

    // if fileLines isn't empty, data will be allocated to weapon objects
    if (fileLines.size() != 0)
    {
        // iterate through each element of fileLines past the first two header lines
        for (int i = 2; i < fileLines.size(); ++i)
        {
            Weapon weapon; // new weapon object
            std::string currLine = fileLines.at(i); // holds the current element of fileLines
            // a vector is created using the splitString() function
            // the vector brokenStrings will hold the substrings obtained from the string held in currLine
            std::vector<std::string> brokenStrings = splitString(currLine, ',');
            // if there are no elements in brokenStrings, then the file is not formatted correctly and the function terminates
            if (brokenStrings.size() == 0)
            {
                std::cout << "Incorrect file format." << std::endl;
                return weaponList;
            }

            // allocate brokenStrings data to weapon data
            weapon.weaponID = i - 1;
            weapon.weaponName = brokenStrings.at(0);
            if (brokenStrings.at(1) != "")
            {
                weapon.reqStr = brokenStrings.at(1);
            }
            if (brokenStrings.at(2) != "")
            {
                weapon.reqDex = brokenStrings.at(2);
            }
            if (brokenStrings.at(3) != "")
            {
                weapon.reqInt = brokenStrings.at(3);
            }
            if (brokenStrings.at(4) != "")
            {
                weapon.reqFth = brokenStrings.at(4);
            }
            if (brokenStrings.at(5) != "")
            {
                weapon.weight = brokenStrings.at(5);
            }
            if (brokenStrings.at(6) != "")
            {
                weapon.crit = brokenStrings.at(6);
            }
            if (brokenStrings.at(7) != "")
            {
                weapon.dmgPhys = brokenStrings.at(7);
            }
            if (brokenStrings.at(8) != "")
            {
                weapon.dmgMag = brokenStrings.at(8);
            }
            if (brokenStrings.at(9) != "")
            {
                weapon.dmgFire = brokenStrings.at(9);
            }
            if (brokenStrings.at(10) != "")
            {
                weapon.dmgLtn = brokenStrings.at(10);
            }
            if (brokenStrings.at(11) != "")
            {
                weapon.dmgDark = brokenStrings.at(11);
            }
            if (brokenStrings.at(12) != "")
            {
                weapon.auxBleed = brokenStrings.at(12);
            }
            if (brokenStrings.at(13) != "")
            {
                weapon.auxPoison = brokenStrings.at(13);
            }
            if (brokenStrings.at(14) != "")
            {
                weapon.auxFrost = brokenStrings.at(14);
            }
            if (brokenStrings.at(15) != "")
            {
                weapon.scaleStr = brokenStrings.at(15);
            }
            if (brokenStrings.at(16) != "")
            {
                weapon.scaleDex = brokenStrings.at(16);
            }
            if (brokenStrings.at(17) != "")
            {
                weapon.scaleInt = brokenStrings.at(17);
            }
            if (brokenStrings.at(18) != "")
            {
                weapon.scaleFth = brokenStrings.at(18);
            }
            if (brokenStrings.at(19) != "")
            {
                weapon.weaponType = brokenStrings.at(19);
            }
            if (brokenStrings.at(20) != "")
            {
                weapon.damageType = brokenStrings.at(20);
            }
            if (brokenStrings.at(21) != "")
            {
                weapon.weaponSkill = brokenStrings.at(21);
            }
            if (brokenStrings.at(22) != "")
            {
                weapon.spellBuff = brokenStrings.at(22);
            }
            if (brokenStrings.at(23) == "Y")
            {
                weapon.buffable = true;
            }
            if (brokenStrings.at(24) != "")
            {
                weapon.upgradeMat = brokenStrings.at(24);
            }
            if (brokenStrings.at(25) != "")
            {
                weapon.AR = brokenStrings.at(25);
            }
            if (brokenStrings.size() == 27)
            {
                weapon.notes = brokenStrings.at(26);
            }
            // empty the brokenStrings vector
            brokenStrings.clear();
            // weapon is then added to the container
            weaponList.push_back(weapon);
        }
        std::cout << "Weapon data has been stored successfully.\n\n" << std::endl;
    }
    else
    {
        std::cout << "Unable to open " << csvPath << ".\n" << std::endl;
    }
    //empty the fileLines vector
    fileLines.clear();

    return weaponList;
}

/*
 * Load a .csv file containing shield information into a container
 *
 * @param csvPath the path to the .csv file to load
 * @return a container holding all the shields read
 */
std::vector<Shield> loadShields(std::string csvPath)
{
    std::vector<Shield> shieldList;
    std::vector<std::string> fileLines = retrieveFileContents(csvPath); // holds individual lines of the .csv being read

    if (fileLines.size() != 0)
    {
        for (int i = 2; i < fileLines.size(); ++i)
        {
            Shield shield;
            std::string currLine = fileLines.at(i);
            std::vector<std::string> brokenStrings = splitString(currLine, ',');
            if (brokenStrings.size() == 0)
            {
                std::cout << "Incorrect file format." << std::endl;
                return shieldList;
            }

            shield.shieldID = i - 1;
            shield.shieldName = brokenStrings.at(0);
            shield.reqStr = brokenStrings.at(1);
            if (brokenStrings.at(2) != "")
            {
                shield.reqDex = brokenStrings.at(2);
            }
            if (brokenStrings.at(3) != "")
            {
                shield.reqInt = brokenStrings.at(3);
            }
            if (brokenStrings.at(4) != "")
            {
                shield.reqFth = brokenStrings.at(4);
            }
            shield.weight = brokenStrings.at(5);
            shield.dmgPhys = brokenStrings.at(6);
            if (brokenStrings.at(7) != "")
            {
                shield.dmgFire = brokenStrings.at(7);
            }
            shield.defPhys = brokenStrings.at(8);
            shield.defMag = brokenStrings.at(9);
            shield.defFire = brokenStrings.at(10);
            shield.defLight = brokenStrings.at(11);
            shield.defDark = brokenStrings.at(12);
            shield.stability = brokenStrings.at(13);
            shield.scaleStr = brokenStrings.at(14);
            if (brokenStrings.at(15) != "")
            {
                shield.scaleInt = brokenStrings.at(15);
            }
            if (brokenStrings.at(16) != "")
            {
                shield.scaleFth = brokenStrings.at(16);
            }
            shield.shieldType = brokenStrings.at(17);
            shield.damageType = brokenStrings.at(18);
            shield.shieldSkill = brokenStrings.at(19);
            shield.upgradeMat = brokenStrings.at(20);
            if (brokenStrings.size() == 22)
            {
                shield.notes = brokenStrings.at(21);
            }
            brokenStrings.clear();
            shieldList.push_back(shield);
        }
        std::cout << "Shield data has been stored successfully.\n\n" << std::endl;
    }
    else
    {
        std::cout << "Unable to open " << csvPath << ".\n" << std::endl;
    }
    fileLines.clear();

    return shieldList;
}

/*
 * Load a .csv file containing armor information into a container
 *
 * @param csvPath the path to the .csv file to load
 * @return a container holding all the armor objects read
 */
std::vector<Armor> loadArmor(std::string csvPath)
{
    std::vector<Armor> armorList;
    std::vector<std::string> fileLines = retrieveFileContents(csvPath);

    if (fileLines.size() != 0)
    {
        for (int i = 5; i < fileLines.size(); ++i)
        {
            Armor armor;
            std::string currLine = fileLines.at(i);
            std::vector<std::string> brokenStrings = splitString(currLine, ',');
            if (brokenStrings.size() == 0)
            {
                std::cout << "Incorrect file format." << std::endl;
                return armorList;
            }

            armor.armorID = i - 4;
            armor.armorName = brokenStrings.at(0);
            armor.weight = brokenStrings.at(1);
            armor.physDef = brokenStrings.at(2);
            armor.defStrike = brokenStrings.at(3);
            armor.defSlash = brokenStrings.at(4);
            armor.defThrust = brokenStrings.at(5);
            armor.defMag = brokenStrings.at(6);
            armor.defFire = brokenStrings.at(7);
            armor.defLtn = brokenStrings.at(8);
            armor.defDark = brokenStrings.at(9);
            armor.defBleed = brokenStrings.at(10);
            armor.defPoison = brokenStrings.at(11);
            armor.defFrost = brokenStrings.at(12);
            armor.defCurse = brokenStrings.at(13);
            armor.poise = brokenStrings.at(14);
            armor.armorType = brokenStrings.at(15);
            armor.armorSet = brokenStrings.at(16);

            brokenStrings.clear();
            armorList.push_back(armor);
        }
        std::cout << "Armor data has been stored successfully.\n\n" << std::endl;
    }
    else
    {
        std::cout << "Unable to open " << csvPath << ".\n" << std::endl;
    }
    fileLines.clear();

    return armorList;
}

/*
 * Load a .csv file containing ring information into a container
 *
 * @param csvPath the path to the .csv file to load
 * @return a container holding all the rings read
 */
std::vector<Ring> loadRings(std::string csvPath)
{
    std::vector<Ring> ringList;
    std::vector<std::string> fileLines = retrieveFileContents(csvPath);

    if (fileLines.size() != 0)
    {
        for (int i = 1; i < fileLines.size(); ++i)
        {
            Ring ring;
            std::string currLine = fileLines.at(i);
            std::vector<std::string> brokenStrings = splitString(currLine, ',');
            if (brokenStrings.size() == 0)
            {
                std::cout << "Incorrect file format." << std::endl;
                return ringList;
            }

            ring.ringID = i;
            ring.ringName = brokenStrings.at(0);
            ring.weight = brokenStrings.at(1);
            ring.ringDesc = brokenStrings.at(2);
            ring.acquisition = brokenStrings.at(3);

            brokenStrings.clear();
            ringList.push_back(ring);
        }
        std::cout << "Ring data has been stored successfully.\n\n" << std::endl;
    }
    else
    {
        std::cout << "Unable to open " << csvPath << ".\n" << std::endl;
    }
    fileLines.clear();

    return ringList;
}

/*
 * Load a .csv file containing sorcery information into a container
 *
 * @param csvPath the path to the .csv file to load
 * @return a container holding all the sorceries read
 */
std::vector<Sorcery> loadSorceries(std::string csvPath)
{
    std::vector<Sorcery> sorceryList;
    std::vector<std::string> fileLines = retrieveFileContents(csvPath);

    if (fileLines.size() != 0)
    {
        for (int i = 1; i < fileLines.size(); ++i)
        {
            Sorcery sorcery;
            std::string currLine = fileLines.at(i);
            std::vector<std::string> brokenStrings = splitString(currLine, ',');
            if (brokenStrings.size() == 0)
            {
                std::cout << "Incorrect file format." << std::endl;
                return sorceryList;
            }

            sorcery.sorceryID = i;
            sorcery.sorceryName = brokenStrings.at(0);
            sorcery.fpCost = brokenStrings.at(1);
            sorcery.slotsReq = brokenStrings.at(2);
            sorcery.intReq = brokenStrings.at(3);
            sorcery.sorceryDesc = brokenStrings.at(4);
            sorcery.acquisition = brokenStrings.at(5);
            if (brokenStrings.size() == 7)
            {
                sorcery.notes = brokenStrings.at(6);
            }

            brokenStrings.clear();
            sorceryList.push_back(sorcery);
        }
        std::cout << "Sorcery data has been stored successfully.\n\n" << std::endl;
    }
    else
    {
        std::cout << "Unable to open " << csvPath << ".\n" << std::endl;
    }
    fileLines.clear();

    return sorceryList;
}

/*
 * Load a .csv file containing miracle information into a container
 *
 * @param csvPath the path to the .csv file to load
 * @return a container holding all the miracles read
 */
std::vector<Miracle> loadMiracles(std::string csvPath)
{
    std::vector<Miracle> miracleList;
    std::vector<std::string> fileLines = retrieveFileContents(csvPath);

    if (fileLines.size() != 0)
    {
        for (int i = 1; i < fileLines.size(); ++i)
        {
            Miracle miracle;
            std::string currLine = fileLines.at(i);
            std::vector<std::string> brokenStrings = splitString(currLine, ',');
            if (brokenStrings.size() == 0)
            {
                std::cout << "Incorrect file format." << std::endl;
                return miracleList;
            }

            miracle.miracleID = i;
            miracle.miracleName = brokenStrings.at(0);
            miracle.fpCost = brokenStrings.at(1);
            miracle.slotsReq = brokenStrings.at(2);
            miracle.faithReq = brokenStrings.at(3);
            miracle.miracleDesc = brokenStrings.at(4);
            miracle.acquisition = brokenStrings.at(5);
            if (brokenStrings.size() == 7)
            {
                miracle.notes = brokenStrings.at(6);
            }

            brokenStrings.clear();
            miracleList.push_back(miracle);
        }
        std::cout << "Miracle data has been stored successfully.\n\n" << std::endl;
    }
    else
    {
        std::cout << "Unable to open " << csvPath << ".\n" << std::endl;
    }
    fileLines.clear();

    return miracleList;
}

/*
 * Load a .csv file containing pyromancy information into a container
 *
 * @param csvPath the path to the .csv file to load
 * @return a container holding all the pyromancies read
 */
std::vector<Pyromancy> loadPyromancies(std::string csvPath)
{
    std::vector<Pyromancy> pyromancyList;
    std::vector<std::string> fileLines = retrieveFileContents(csvPath);

    if (fileLines.size() != 0)
    {
        for (int i = 1; i < fileLines.size(); ++i)
        {
            Pyromancy pyromancy;
            std::string currLine = fileLines.at(i);
            std::vector<std::string> brokenStrings = splitString(currLine, ',');
            if (brokenStrings.size() == 0)
            {
                std::cout << "Incorrect file format." << std::endl;
                return pyromancyList;
            }

            pyromancy.pyromancyID = i;
            pyromancy.pyromancyName = brokenStrings.at(0);
            pyromancy.fpCost = brokenStrings.at(1);
            pyromancy.slotsReq = brokenStrings.at(2);
            pyromancy.intReq = brokenStrings.at(3);
            pyromancy.faithReq = brokenStrings.at(4);
            pyromancy.pyromancyDesc = brokenStrings.at(5);
            pyromancy.acquisition = brokenStrings.at(6);
            if (brokenStrings.size() == 8)
            {
                pyromancy.notes = brokenStrings.at(7);
            }

            brokenStrings.clear();
            pyromancyList.push_back(pyromancy);
        }
        std::cout << "Pyromancy data has been stored successfully.\n\n" << std::endl;
    }
    else
    {
        std::cout << "Unable to open " << csvPath << ".\n" << std::endl;
    }
    fileLines.clear();

    return pyromancyList;
}
