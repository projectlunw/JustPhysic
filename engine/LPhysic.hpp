#pragma once
#include <iostream>

#define G -0.1f

struct vec3 {
	float x; float y; float z;

	bool operator == (const vec3& other) const { return (x == other.x) && (y == other.y) && (z == other.z); }
	bool operator != (const vec3& other) const { return !(*this == other); }
	vec3 operator + (const vec3& other) const { return vec3{ x + other.x, y + other.y, z + other.z }; }
	vec3& operator += (const vec3& other) { x += other.x; y += other.y; z += other.z; return *this; }
	vec3 operator - (const vec3& other) const { return vec3{ x - other.x, y - other.y, z - other.z }; }
	vec3& operator -= (const vec3& other) { x -= other.x; y -= other.y; z -= other.z; return *this; }
	vec3 operator * (const vec3& other) const { return vec3{ x * other.x, y * other.y, z * other.z }; }
	vec3& operator *= (const vec3& other) { x *= other.x; y *= other.y; z *= other.z; return *this; }
	vec3 operator / (const vec3& other) const { return vec3{ x / other.x, y / other.y, z / other.z }; }
	vec3& operator /= (const vec3& other) { x /= other.x; y /= other.y; z /= other.z; return *this; }
	vec3 operator * (float scalar) const { return vec3{ x * scalar, y * scalar, z * scalar }; }
	vec3& operator *= (float scalar) { x *= scalar; y *= scalar; z *= scalar; return *this; }
	vec3 operator / (float scalar) const {
		if (scalar == 0.0f) return vec3{ 0.0f, 0.0f, 0.0f };
		return vec3{ x / scalar, y / scalar, z / scalar };
	}
	vec3& operator /= (float scalar) {
		if (scalar != 0.0f) { x /= scalar; y /= scalar; z /= scalar; }
		else { x = 0.0f; y = 0.0f; z = 0.0f; }
		return *this;
	}
};
