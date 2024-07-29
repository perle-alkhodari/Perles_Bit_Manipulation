#include "Input.h"

int Input::GetInt(int min, int max, std::string prompt, std::string errorMessage)
{
	bool invalid = true;
	std::string userInput;
	int result;
	do {
		if (!prompt.empty()) std::cout << prompt;
		getline(std::cin, userInput);
		try {
			result = stoi(userInput);
			if (result >= min && result <= max) {
				invalid = false;
			}
		}
		catch (...) {
			invalid = true;
		}
		if (invalid) { 
			System::Console::ForegroundColor(System::ConsoleColor::Red);
			std::cout << errorMessage << std::endl;
			System::Console::ResetColor();
		}
	} while (invalid);

	return result;
}
