#pragma once
#include <math.h>
#include <SFML/Graphics.hpp>
#include <iostream>
class Asteroid :public sf::Drawable, public sf::Transformable 
{
public:
	static const float speed[3];
	static const float radius[3];
	static const float hp[3];
	static const float side[4];
	int hps;
	float A_x, A_y;
	float A_rotation;
	int rem_lvl,randomside,size_temp;

	const double PI = std::atan(1.0) * 4;
	sf::CircleShape shape;
	Asteroid(int lvl);
	~Asteroid()=default;
	void movement();
	void death();
	void out_of_bounds();
	void reset();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

