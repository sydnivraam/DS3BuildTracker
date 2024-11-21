# DS3BuildTracker

DS3 Build Tracker is a C++ program that aims to create a space for users to save builds for the game Dark Souls 3. This may be beneficial for those who wish to respec temporarily without forgetting a prior build's attributes and equipment.

DS3 Build Tracker reads .csv files in order to save data for weapons, armor, sorceries, miracles, pyromancies, and rings. Through various menus, the user has the ability to read the names and attributes of any of these aforementioned build elements. The user can then save these elements to a new Build object using unique ID's corresponding to the different options available for each element.

Certain .csv files were created by other users; they are credited within the heading of the main.cpp, and any .csv files made by me use data gathered from https://darksouls3.wiki.fextralife.com/Dark+Souls+3+Wiki , https://darksouls.fandom.com/wiki/Category:Dark_Souls_III , and the game itself. Editing of .csv files is NOT recommended as it can cause unintended behavior by the program.

As of the most recent update, the .csv files are now contained within the /assets folder; this path is coded into the main.cpp and allows the program to find them. Be sure that the /assets folder is placed within the same directory that contains all of the .cpp and .h files.

# Motivation
Before anything else, this is mainly a personal project to gain and show experience with the C++ programming language. However, I've also found it difficult to impossible to find an already established Dark Souls 3 reference application or software that includes an option to save builds; either this feature is non-existent or locked behind a paywall.

If you're like me, you've probably put hundreds of hours into Dark Souls 3 and opt for new ways to play the game. Imagine: you have an already established character with a build you've admired for some time, but you want to branch out and try something new. You head to Rosaria, respec, and equip an entirely different set of gear. Time passes, and you miss that old build. You go back to Rosaria to respec and realize... I don't remember the equipment my old build was using! As such, I intend for this to be a free to use, open source option for those wishing to save their builds (once it is complete).

Aside from build saving, the datasheets include extensive information about individual weapons, armors, spells, etc. As such, I imagine this can serve as a miniature companion app for the game that can help you to keep track of armament specifications and acquisition methods of various spells and rings.

# Current State
Intake data for weapons, shields, armor, and magic

Access different menus to view weapons, shields, armor, and magic

Each menu has the option to list all names of elements (weapons, shields, armor, magic), all names and attributes of elements, or find a specific element within the current element type

Weapon/Shield and Armor menus also provide an option for viewing elements by weapon/shield type or armor set

Rings and magic will also provide acquisition descriptions, allowing this application to also serve as a guide for finding these objects in the game

Build saving is now implemented but only provides functionality for weapons and shields currently. Work is underway on armor, rings, and spells.

# Roadmap/To-Do

Implement armor, rings, and spells within build saving module

Implement proper input error handling

Some DLC content (among other things like the pyromancy flame) may be amiss from the datasheets I did not curate myself, so I will likely need to analyze and edit them at some point
