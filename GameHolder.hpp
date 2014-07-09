#ifndef GAMEHOLDER_HPP
#define GAMEHOLDER_HPP

#include "Core.hpp"
#include "Error.hpp"

class GameRunner;

template <typename T>
class GameHolder {
public:
	static T& GetInstance() {
		if (instance == NULL) {
			throw Error("Null game holder instance");
		}
		return *instance;
	}

private:
	static void CreateInstance() {
		instance = new T();
	}

	static void DestroyInstance() {
		delete instance;
		instance = NULL;
	}

private:
	static T* instance;

	DISABLE_COPY(GameHolder);
	DISABLE_CREATE(GameHolder);

	friend class GameRunner;
};

template <typename T>
T* GameHolder<T>::instance = NULL;

#endif
