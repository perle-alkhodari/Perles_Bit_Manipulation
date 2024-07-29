#pragma once
#include "Console.h"
#include <string>

class Input
{
public:
	static int GetInt(int min, int max, std::string prompt = "", std::string errorMessage = "Invalid input.");
};

