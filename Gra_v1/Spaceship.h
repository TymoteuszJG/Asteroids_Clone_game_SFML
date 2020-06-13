#pragma once
#ifndef Spaceship_h
#define Spaceship_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class Spaceship : public sf::Drawable, public sf::Transformable
{
public:
	static const int max_speed;
	float acceleration;
	const double PI = std::atan(1.0) * 4;

	//Spaceship(sf::RenderWindow&);
	Spaceship();
	~Spaceship()=default;
	float Ss_x, Ss_y, life;
	float Ss_speed;
	float Ss_rotation;
	sf::ConvexShape shape;
	virtual void draw(sf::RenderTarget& G_window, sf::RenderStates states) const;
	void reset();
	void movement();
};
#endif /* Spaceship_h */
 