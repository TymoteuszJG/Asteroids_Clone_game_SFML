
#include "Spaceship.h"
//#include <SFML/Graphics.hpp>
const int Spaceship::max_speed = 5;
Spaceship::Spaceship()
{
	//set lives to 3 and set coordinates to half  the size of window
	life = 3;
	
	acceleration = 0;
	
		//creating sprrite
	
	shape.setPointCount(4);
	int x = 512, y = 384;
	shape.setPoint(0, sf::Vector2f(x+0,y+10 ));
	shape.setPoint(1, sf::Vector2f(x+10,y-10 ));
	shape.setPoint(2, sf::Vector2f(x+0, y-5));
	shape.setPoint(3, sf::Vector2f(x-10, y-10));
	shape.setOrigin(x, y);
	
	shape.setFillColor(sf::Color::Black);
	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(1);
	
	shape.setPosition(x, y);
	//shape.setOrigin(512, 384);
	
	//shape.move(512,384);
	float rotation = 0;
}

void Spaceship::draw(sf::RenderTarget& G_window,sf::RenderStates states) const
{
	states.transform *=getTransform();
	G_window.draw(shape, states);
	//auto size = G_window.getSize();
	//sf::CircleShape triangle(50,3);
	//sf::Transform rotations();
	
	//triangle.setPosition(Ss_x , Ss_y );
	//triangle.setRotation(Ss_rotation);
//	triangle.setFillColor(sf::Color(255, 150, 100));
	//G_window.draw(triangle);
}

void Spaceship::reset()
{
	//auto positions=G_window.
	setPosition(1024/2,768/2);
	setRotation(0);
	life -= 1;

	Ss_x = getPosition().x;
	Ss_y = getPosition().y;

	
}
void Spaceship::movement()
{
	if (acceleration > 0)
		acceleration -= 0.05;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		acceleration += 0.1;
		if (acceleration > max_speed)
		{
			acceleration = max_speed;
		}
		

		Ss_x = -acceleration * sin(PI / 180 * getRotation());
		Ss_y = -acceleration * -cos(PI / 180 * getRotation());
		
	
		move(Ss_x, Ss_y);
		auto check = getPosition();
		if (check.x >= 1024 || check.x <= 0)
			move(-Ss_x, 0);
		if (check.y >= 768 || check.y <= 0)
			move(0, -Ss_y);
		Ss_x = getPosition().x;
		Ss_y = getPosition().y;
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if(acceleration>0)
			acceleration -= 0.5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rotate(-4);
		
	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rotate(4);
	}
	
}