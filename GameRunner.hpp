#ifndef GAMERUNNER_HPP
#define GAMERUNNER_HPP

#include <string>

#include "Error.hpp"
#include "GameHolder.hpp"

class GameRunner {
public:
	template <typename T>
	static void Run() {
		Initialize();
		GameHolder<T>::CreateInstance();

		try {
			GameHolder<T>::GetInstance().Run();
		} catch (const Error& error) {
			HandleError(error.GetMessage());
		} catch (...) {
			HandleError("Unknown error");
		}

		GameHolder<T>::DestroyInstance();
		Terminate();
	}

private:
	static void Initialize();
	static void Terminate();

	static void HandleError(const std::string& error);
};

#endif
