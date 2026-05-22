#include "LProp.hpp"
#include "LColor.hpp"
#include "LConsole.hpp"
#include <cmath> // Для std::abs

int main() {
	bool run = true;
	Prop p;
	p.color = WHITE;
	p.dynamic = true;
	p.visible = true;
	p.p = vec3{ 0.0f, 50.0f, 0.0f };
	p.m = 1.0f;
	p.v = vec3{ 5.0f, 1.0f, 1.0f };
	p.F = vec3{ 0.0f, 0.0f, 0.0f };

	Log("Старт модульной симуляции.", 1);

	while (run) {
		UpdPP(p, 1.0f / 60.0f);

		// Высота пола = 10.0f
		if (p.p.y <= 10.0f) {
			p.p.y = 10.0f;

			// Если скорость прыжков затухла — усыпляем объект и останавливаем цикл
			if (std::abs(p.v.y) < 0.05f) {
				p.v.y = 0.0f;
				p.v.x = 0.0f;
				p.v.z = 0.0f;
				run = false; // Безопасный выход
			}
			else {
				p.v.y *= -0.95f; // Прыгучий отскок (теряет всего 5% энергии)
				p.v.x *= 0.9f;   // Трение о пол
				p.v.z *= 0.9f;
			}
		}
	}

	Log("Симуляция успешно завершена.", 1);
	return 0x0;
}
