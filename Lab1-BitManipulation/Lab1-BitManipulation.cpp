#include <vector>
#include "Input.h"

unsigned int bitField = 19;
std::string bits = "";

// Professor, if you like my work please let me know :D,
// it motivates me a lottttt. Thanks.

enum options {
	eTurnOn=1,
	eTurnOff,
	eToggle,
	eNegate,
	eLeftShift,
	eRightShift,
	eExit
};

void TurnOn(int bit) {
	unsigned int placeholder = (1 << bit);
	bitField |= placeholder;
}

void TurnOff(int bit) {
	unsigned int placeholder = (1 << bit);
	bitField &= (~placeholder);
	// come back to this later
}

void Toggle(int bit) {
	unsigned int placeholder = (1 << bit);
	bitField ^= placeholder;
}

void Negate() {
	bitField = ~bitField;
}

void LeftShift() {
	bitField = bitField << 1;
}

void RightShift() {
	bitField = bitField >> 1;
}

void ToBits() {
	unsigned int n = bitField;
	std::vector<int> binaryVec;
	for (int i = 0; i < 32; i++) {
		binaryVec.insert(binaryVec.begin(), n % 2);
		n /= 2;
	}
	bits = "";
	for (int i = 0; i < binaryVec.size(); i++) {
		if (i % 4 == 0) {
			bits += " ";
		}
		bits += std::to_string(binaryVec.at(i));
	}
}

int main() {
	bool on = true;
	int operation;
	int index;
	
	// Do while on.
	do {
		// Update bits.
		ToBits();

		// Clear screen and prompt user.
		std::cout << u8"\033[2J\033[1;1H";
		std::cout << "bitField: " << bitField << std::endl;
		std::cout << "Bits:" << bits << std::endl;
		std::cout << "Turn On = " << eTurnOn << ", Turn Off = " << eTurnOff << ", Toggle = "
			<< eToggle << ", Negate = " << eNegate << ", Left Shift = " << eLeftShift << ", Right Shift = "
			<< eRightShift << ", Exit = " << eExit << "\n" << std::endl;
		operation = Input::GetInt(eTurnOn, eExit, "Choose operation: ");

		// Operations.
		switch (operation) {

		case eTurnOn:
			index = Input::GetInt(0, 31, "Choose bit index: ", "Index out of range.");
			TurnOn(index);
			break;

		case eTurnOff:
			index = Input::GetInt(0, 31, "Choose bit index: ", "Index out of range.");
			TurnOff(index);
			break;

		case eToggle:
			index = Input::GetInt(0, 31, "Choose bit index: ", "Index out of range.");
			Toggle(index);
			break;

		case eNegate:
			Negate();
			break;

		case eLeftShift:
			LeftShift();
			break;

		case eRightShift:
			RightShift();
			break;

		case eExit:
			on = false;
			break;
		}
	} while (on);

}