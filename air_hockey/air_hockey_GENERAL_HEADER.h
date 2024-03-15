#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
//#include <Windows.h>
#include "SFML-2.5.1-x64/include/SFML/Graphics.hpp"
#include "SFML-2.5.1-x64/include/SFML/Window.hpp"
#include "SFML-2.5.1-x64/include/SFML/System.hpp"


/*** using statements for convinence ***/

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::getline;
using std::ostream;
using std::to_string;

/*** color for the terminal ***/

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

/*** general defined numbers ***/

#define MAX_PUCK_VELOCITY 10
#define PUCK_MASS 5
#define MALLET_MASS 50
#define MALLET_MOVEMENT_SPEED 5
#define MM_BUTTON_X_SIZE 250
#define MM_BUTTON_Y_SIZE 60
#define KEY_PARAMETER 30
#define DELAY_NUMBER 30

void sleep(int count);