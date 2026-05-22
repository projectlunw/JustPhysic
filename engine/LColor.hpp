#pragma once
#include "LProp.hpp" // Подключаем, чтобы класс Color видел структуру Prop

enum EColor {
	BLACK = 0x000000,
	WHITE = 0xffffff
};

class Color {
public:
	int get(const Prop& prop) {
		return prop.color;
	}
};
