#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
class projectile : public sf::Drawable, public sf::Transformable
{
public:
	float B_x, B_y, life;
	sf::FloatRect box;
	float B_speed;
	float B_rotation;
	
	const double PI = std::atan(1.0) * 4;
	projectile();
	~projectile() = default;
	sf::CircleShape shape;
	virtual void draw(sf::RenderTarget& G_window, sf::RenderStates states) const;
	void Shoot(float P_x, float P_y, float P_rotation);
	void movement();
	void reset();
};