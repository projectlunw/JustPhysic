#pragma once
#include "LPhysic.hpp"
#include <iostream>

struct Prop {
	bool dynamic;
	bool visible;
	int color;
	vec3 p;
	float m;
	vec3 com;
	vec3 v;
	vec3 F;
	vec3 a;
};

inline void UpdPP(Prop& prop, float dt) {
	if (!prop.dynamic || prop.m <= 0.0f) return;

	float drag = 0.05f;
	prop.F -= prop.v * drag;

	prop.a = prop.F / prop.m; // a=F/m
	prop.a.y += G;
	prop.v += prop.a * dt; // v=a*dt
	prop.p += prop.v * dt; //p=v*dt
	prop.F = vec3(0.0f, 0.0f, 0.0f);
	std::cout << prop.p.x << ' ' << prop.p.y << ' ' << prop.p.z << std::endl;
}
