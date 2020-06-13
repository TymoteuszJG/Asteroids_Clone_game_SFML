#include "Asteroid.h"
const float Asteroid::speed[3] = { 1, 2, 3 };
const float Asteroid::radius[3] = { 80.0f, 40.0f, 20.0f };
const float Asteroid::side[4] = {1024,-700,764,-300  };
const float Asteroid::hp[3] = {3,2,1};
Asteroid::Asteroid(int lvl)
{
	shape.setPointCount(8);
	shape.setRadius(radius[lvl]);
	shape.setFillColor(sf::Color::Black);
	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(2);
	shape.setOrigin(radius[lvl], radius[lvl]);
	randomside=rand()% 2;
	A_x = side[randomside]+rand() % 500;
	A_y = side[randomside+2]+rand() % 250;

	hps = hp[lvl];
	A_rotation = rand() % 360;
	rem_lvl = lvl;
	size_temp = lvl;
	setPosition(A_x, A_y);
	
}
void Asteroid::out_of_bounds()
{
	auto helper = getPosition();
	if (helper.x > 2000 || helper.x < -1000 || helper.y>1500 || helper.y < -500)
	{
		randomside = rand() % 2;
		A_x = side[randomside] + rand() % 500;
		A_y = side[randomside + 2] + rand() % 250;
		A_rotation = rand() % 360;
		setPosition(A_x, A_y);
	
	}
	
}
void Asteroid::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	states.transform *= getTransform();
	target.draw(shape, states);

}
void Asteroid::movement()
{
	A_x = speed[rem_lvl] * -sin(PI / 180 * A_rotation);
	A_y = -speed[rem_lvl] * -cos(PI / 180 * A_rotation);
	move(A_x, A_y);
	A_x = getPosition().x;
	A_y = getPosition().y;
}
void Asteroid::death()
{
	hps -= 1;
	if(hps==0)
	{

	
		rem_lvl += 1;
		
		if (rem_lvl==3)
		{

			rem_lvl = size_temp;
			hps = hp[rem_lvl];
			randomside = rand() % 2;
			A_x = side[randomside] + rand() % 500;
			A_y = side[randomside + 2] + rand() % 250;
			shape.setRadius(radius[rem_lvl]);
			setPosition(A_x, A_y);
		}
		else
		{
			hps = hp[rem_lvl];
			shape.setRadius(radius[rem_lvl]);
		}
	}
}
void Asteroid::reset()
{
	randomside = rand() % 2;
	A_x = side[randomside] + rand() % 500;
	A_y = side[randomside + 2] + rand() % 250;
	shape.setRadius(radius[rem_lvl]);
	setPosition(A_x, A_y);
}
