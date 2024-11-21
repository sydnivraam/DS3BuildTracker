#include "Displays.h"

/*
 * Display the weapon information to the console (std::out)
 * 
 * @param weapon Weapon to display
 */
void displayWeapon(Weapon weapon)
{
    std::cout << weapon.weaponID << ": " << weapon.weaponName << std::endl;

    if (weapon.buffable == true)
    {
        std::cout << "- Buffable -" << std::endl;
    }
    else
    {
        std::cout << "- Not Buffable -" << std::endl;
    }

    std::cout << "Weapon type: " << weapon.weaponType << std::endl;
    std::cout << "Damage type: " << weapon.damageType << std::endl;
    std::cout << "Weapon skill: " << weapon.weaponSkill << std::endl;

    if (weapon.spellBuff != "")
    {
        std::cout << "Spell buff amount: " << weapon.spellBuff << std::endl;
    }
    std::cout << "Upgrade material: " << weapon.upgradeMat << std::endl;

    std::cout << "\n";

    //if weapon.[thing] is not empty then [thing] gets printed
    if (weapon.reqStr != "")
    {
        std::cout << "Required strength: " << weapon.reqStr << std::endl;
    }
    if (weapon.reqDex != "")
    {
        std::cout << "Required dexterity: " << weapon.reqDex << std::endl;
    }
    if (weapon.reqInt != "")
    {
        std::cout << "Required intelligence: " << weapon.reqInt << std::endl;
    }
    if (weapon.reqFth != "")
    {
        std::cout << "Required faith: " << weapon.reqFth << std::endl;
    }
    if (weapon.weight != "")
    {
        std::cout << "Weight: " << weapon.weight << std::endl;
    }
    if (weapon.crit != "")
    {
        std::cout << "Crit damage multiplier: " << weapon.crit << std::endl;
    }
    if (weapon.AR != "")
    {
        std::cout << "AR: " << weapon.AR << std::endl;
    }
    if (weapon.dmgPhys != "")
    {
        std::cout << "Physical damage: " << weapon.dmgPhys << std::endl;
    }
    if (weapon.dmgMag != "")
    {
        std::cout << "Magic damage: " << weapon.dmgMag << std::endl;
    }
    if (weapon.dmgFire != "")
    {
        std::cout << "Fire damage: " << weapon.dmgFire << std::endl;
    }
    if (weapon.dmgLtn != "")
    {
        std::cout << "Lightning damage: " << weapon.dmgLtn << std::endl;
    }
    if (weapon.dmgDark != "")
    {
        std::cout << "Dark damage: " << weapon.dmgDark << std::endl;
    }
    if (weapon.auxBleed != "")
    {
        std::cout << "Bleed build-up: " << weapon.auxBleed << std::endl;
    }
    if (weapon.auxPoison != "")
    {
        std::cout << "Poison build-up: " << weapon.auxPoison << std::endl;
    }
    if (weapon.auxFrost != "")
    {
        std::cout << "Frost build-up: " << weapon.auxFrost << std::endl;
    }
    if (weapon.scaleStr != "")
    {
        std::cout << "Strength scaling: " << weapon.scaleStr << std::endl;
    }
    if (weapon.scaleDex != "")
    {
        std::cout << "Dexterity scaling: " << weapon.scaleDex << std::endl;
    }
    if (weapon.scaleInt != "")
    {
        std::cout << "Intelligence scaling: " << weapon.scaleInt << std::endl;
    }
    if (weapon.scaleFth != "")
    {
        std::cout << "Faith scaling: " << weapon.scaleFth << std::endl;
    }
    if (weapon.notes != "")
    {
        std::cout << "Extra details: " << weapon.notes << std::endl;
    }
    std::cout << "\n";

    return;
}

/*
 * Display the shield information to the console (std::out)
 * 
 * @param shield Shield to display
 */
void displayShield(Shield shield)
{
    std::cout << shield.shieldID << ": " << shield.shieldName << std::endl;

    std::cout << "Shield type: " << shield.shieldType << std::endl;
    std::cout << "Damage type: " << shield.damageType << std::endl;
    std::cout << "Weapon skill: " << shield.shieldSkill << std::endl;
    std::cout << "Upgrade material: " << shield.upgradeMat << std::endl;

    std::cout << "\nRequired strength: " << shield.reqStr << std::endl;
    if (shield.reqDex != "")
    {
        std::cout << "Required dexterity: " << shield.reqDex << std::endl;
    }
    if (shield.reqInt != "")
    {
        std::cout << "Required intelligence: " << shield.reqInt << std::endl;
    }
    if (shield.reqFth != "")
    {
        std::cout << "Required faith: " << shield.reqFth << std::endl;
    }
    if (shield.weight != "")
    {
        std::cout << "Weight: " << shield.weight << std::endl;
    }
    std::cout << "Stability: " << shield.stability << std::endl;
    std::cout << "\nPhysical damage: " << shield.dmgPhys << std::endl;
    if (shield.dmgFire != "")
    {
        std::cout << "Fire damage: " << shield.dmgFire << std::endl;
    }
    std::cout << "Strength scaling: " << shield.scaleStr << std::endl;
    if (shield.scaleInt != "")
    {
        std::cout << "Intelligence scaling: " << shield.scaleInt << std::endl;
    }
    if (shield.scaleFth != "")
    {
        std::cout << "Faith scaling: " << shield.scaleFth << std::endl;
    }
    if (shield.notes != "")
    {
        std::cout << "Extra details: " << shield.notes << std::endl;
    }
    std::cout << "\n";

    return;
}

/*
 * Display the armor information to the console (std::out)
 * 
 * @param armor Armor to display
 */
void displayArmor(Armor armor)
{
    std::cout << armor.armorID << ": " << armor.armorName << std::endl;
    std::cout << "Armor set: " << armor.armorSet << std::endl;
    std::cout << "Armor type: " << armor.armorType << std::endl;
    std::cout << "Weight: " << armor.weight << std::endl;
    std::cout << "Poise: " << armor.poise << std::endl;
    std::cout << "\nPhysical damage protection: " << armor.physDef << std::endl;
    std::cout << "Vs. strike protection: " << armor.defStrike << std::endl;
    std::cout << "Vs. slash protection: " << armor.defSlash << std::endl;
    std::cout << "Vs. thrust protection: " << armor.defThrust << std::endl;
    std::cout << "Magic protection: " << armor.defMag << std::endl;
    std::cout << "Fire protection: " << armor.defFire << std::endl;
    std::cout << "Lightning protection: " << armor.defLtn << std::endl;
    std::cout << "Dark protection: " << armor.defDark << std::endl;
    std::cout << "Bleed protection: " << armor.defBleed << std::endl;
    std::cout << "Poison protection: " << armor.defPoison << std::endl;
    std::cout << "Frost protection: " << armor.defFrost << std::endl;
    std::cout << "Curse protection: " << armor.defCurse << std::endl;

    return;
}

/*
 * Display the ring information to the console (std::out)
 * 
 * @param ring Ring to display
 */
void displayRing(Ring ring)
{
    std::cout << ring.ringID << ": " << ring.ringName << std::endl;
    std::cout << "Weight: " << ring.weight << std::endl;
    std::cout << "\nDescription:" << std::endl;
    // Some ring descriptions require newlines so I'm taking these descriptions and
    // storing them in a vector in order to search for a delimiter to place newlines
    // so that they'll show up in the console with better readability
    if (ring.ringDesc.find("^") != std::string::npos)
    {
        std::vector<std::string> descriptionStrings = splitString(ring.ringDesc, ' ');

        // All rings have a description so the size of the descriptionStrings vector should not be empty
        if (descriptionStrings.size() == 0)
        {
            std::cout << "Something bad happened." << std::endl;
        }
        else
        {
            for (int i = 0; i < descriptionStrings.size(); ++i)
            {
                // check if the string contains the delimiter for adding newline
                if (descriptionStrings.at(i).find("^") != std::string::npos)
                {
                    // split the string using the delimiter
                    std::vector<std::string> descriptionSubstr = splitString(descriptionStrings.at(i), '^');
                    // cout subtring, add newline, cout next subtring
                    std::cout << descriptionSubstr.at(0) << "\n" << descriptionSubstr.at(1) << " ";
                    // empty the subtring vector
                    descriptionSubstr.clear();
                }
                else
                {
                    // cout the current string and a space when it does not contain the delimiter
                    std::cout << descriptionStrings.at(i) << " ";
                }
            }
            std::cout << "\n";
        }
        // clear the descriptionStrings vector
        descriptionStrings.clear();
    }
    // cout the description as normal if it does not contain any delimiters
    else
    {
        std::cout << ring.ringDesc << std::endl;
    }

    return;
}

/*
 * Display the ring information with acquisition descriptions to the console (std::out)
 * Ring acquisition methods are very lengthy and detailed, so this extra method felt necessary to include
 * so that the user may choose whether or not to view acquisition information
 * 
 * @param ring Ring to display
 */
void displayRingWithAcq(Ring ring)
{
    displayRing(ring);
    std::cout << "\nAcquisition:" << std::endl;
    std::vector<std::string> acquisitionStrings = splitString(ring.acquisition, ' ');

    if (acquisitionStrings.size() == 0)
    {
        std::cout << "Something bad happened." << std::endl;
    }
    else
    {
        for (int i = 0; i < acquisitionStrings.size(); ++i)
        {
            if (acquisitionStrings.at(i).find('@') != std::string::npos)
            {
                std::vector<std::string> acquisitionSubstr = splitString(acquisitionStrings.at(i), '@');
                std::cout << acquisitionSubstr.at(0) << "\n\n" << acquisitionSubstr.at(1) << " ";
                acquisitionSubstr.clear();
            }
            else if (acquisitionStrings.at(i).find('^') != std::string::npos)
            {
                std::vector<std::string> acquisitionSubstr = splitString(acquisitionStrings.at(i), '^');
                std::cout << acquisitionSubstr.at(0) << "\n" << acquisitionSubstr.at(1) << " ";
                acquisitionSubstr.clear();
            }
            else
            {
                std::cout << acquisitionStrings.at(i) << " ";
            }
        }
        std::cout << "\n";
    }

    acquisitionStrings.clear();
}

/*
 * Display the sorcery information to the console (std::out)
 * 
 * @param sorcery Sorcery to display
 */
void displaySorcery(Sorcery sorcery)
{
    std::cout << sorcery.sorceryID << ": " << sorcery.sorceryName << std::endl;
    std::cout << "FP cost: " << sorcery.fpCost << std::endl;
    std::cout << "Slots required: " << sorcery.slotsReq << std::endl;
    std::cout << "Intelligence required: " << sorcery.intReq << std::endl;
    std::cout << "\nDescription:\n" << sorcery.sorceryDesc << std::endl;
    std::cout << "\nAcquisition:" << std::endl;

    // Similar newline placement finding as in the displayRing() method
    std::vector<std::string> acquisitionStrings = splitString(sorcery.acquisition, ' ');

    if (acquisitionStrings.size() == 0)
    {
        std::cout << "Something bad happened." << std::endl;
    } 
    else
    {
        for (int i = 0; i < acquisitionStrings.size(); ++i)
        {
            if (acquisitionStrings.at(i).find('^') != std::string::npos)
            {
                std::vector<std::string> acquisitionSubstr = splitString(acquisitionStrings.at(i), '^');
                std::cout << acquisitionSubstr.at(0) << "\n" << acquisitionSubstr.at(1) << " ";
                acquisitionSubstr.clear();
            }
            else
            {
                std::cout << acquisitionStrings.at(i) << " ";
            }
        }
        std::cout << "\n";
    }

    acquisitionStrings.clear();

    if (sorcery.notes != "")
    {
        std::cout << "\nNotes: " << sorcery.notes << std::endl;
    }

    return;
}

/*
 * Display the miracle information to the console (std::out)
 * 
 * @param miracle Miracle to display
 */
void displayMiracle(Miracle miracle)
{
    std::cout << miracle.miracleID << ": " << miracle.miracleName << std::endl;
    std::cout << "FP cost: " << miracle.fpCost << std::endl;
    std::cout << "Slots required: " << miracle.slotsReq << std::endl;
    std::cout << "Faith required: " << miracle.faithReq << std::endl;
    std::cout << "\nDescription:\n" << miracle.miracleDesc << std::endl;
    std::cout << "\nAcquisition:" << std::endl;

    std::vector<std::string> acquisitionStrings = splitString(miracle.acquisition, ' ');

    if (acquisitionStrings.size() == 0)
    {
        std::cout << "Something bad happened." << std::endl;
    }
    else {
        for (int i = 0; i < acquisitionStrings.size(); ++i)
        {
            if (acquisitionStrings.at(i).find('^') != std::string::npos)
            {
                std::vector<std::string> acquisitionSubstr = splitString(acquisitionStrings.at(i), '^');
                std::cout << acquisitionSubstr.at(0) << "\n" << acquisitionSubstr.at(1) << " ";
                acquisitionSubstr.clear();
            }
            else
            {
                std::cout << acquisitionStrings.at(i) << " ";
            }
        }
        std::cout << "\n";
    }

    acquisitionStrings.clear();

    if (miracle.notes != "")
    {
        if (miracle.notes.find('^') != std::string::npos)
        {
            std::vector<std::string> notesStrings = splitString(miracle.notes, ' ');

            if (notesStrings.size() == 0)
            {
                std::cout << "Something bad happened." << std::endl;
            }
            else
            {
                std::cout << "\nNotes:" << std::endl;
                for (int i = 0; i < notesStrings.size(); ++i)
                {
                    std::vector<std::string> notesSubstr = splitString(notesStrings.at(i), '^');
                    if (notesStrings.at(i).find('^') != std::string::npos)
                    {
                        std::cout << notesSubstr.at(0) << "\n" << notesSubstr.at(1) << " ";
                        notesSubstr.clear();
                    }
                    else
                    {
                        std::cout << notesStrings.at(i) << " ";
                    }
                    notesSubstr.clear();
                }
                std::cout << "\n";
            }

            notesStrings.clear();
        }

        else
        {
            std::cout << "\nNotes: " << miracle.notes << std::endl;
        }
    }

    return;
}

/*
 * Display the pyromancy information to the console (std::out)
 * 
 * @param pyromancy Pyromancy to display
 */
void displayPyromancy(Pyromancy pyromancy)
{
    std::cout << pyromancy.pyromancyID << ": " << pyromancy.pyromancyName << std::endl;
    std::cout << "FP cost: " << pyromancy.fpCost << std::endl;
    std::cout << "Slots required: " << pyromancy.slotsReq << std::endl;
    std::cout << "Intelligence required: " << pyromancy.intReq << std::endl;
    std::cout << "Faith required: " << pyromancy.faithReq << std::endl;
    std::cout << "\nDescription:\n" << pyromancy.pyromancyDesc << std::endl;
    std::cout << "\nAcquisition:\n" << pyromancy.acquisition << std::endl;

    if (pyromancy.notes != "")
    {
        std::cout << "\nNotes: " << pyromancy.notes << std::endl;
    }

    return;
}
