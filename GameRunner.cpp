#include "GameRunner.hpp"

#include <iostream>

#include "Iw2D.h"

void GameRunner::Initialize() {
	Iw2DInit();
}

void GameRunner::Terminate() {
	Iw2DTerminate();
}

void GameRunner::HandleError(const std::string& error) {
	std::string out("Error occurred");

	if (!error.empty()) {
		out += ": " + error;
	}

	std::cerr << out << std::endl;
}
