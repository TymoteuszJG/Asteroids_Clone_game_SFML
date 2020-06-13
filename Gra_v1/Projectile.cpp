#include "Projectile.h"

projectile::projectile()
{
	
	B_speed = 0;
	shape= sf::CircleShape (2);
	shape.setFillColor(sf::Color::Cyan);
//	shape.setPosition(1027, 770);
	//B_x = 1200;
	//B_y = 800;
	box = shape.getGlobalBounds();
}
void projectile::draw(sf::RenderTarget& G_window, sf::RenderStates states) const
{
	states.transform *= getTransform();
	G_window.draw(shape, states);
}
void projectile::reset()
{
	
	
	
		
		setPosition(3000, 3000);
		B_y = 3000;
		B_x = 3000;
		B_speed = 0;
	
}
void projectile::Shoot(float P_x, float P_y, float P_rotation)
{
	B_rotation = P_rotation;
B_x = P_x  -15 * sin(PI / 180 *B_rotation);
B_y = P_y - 15 * -cos(PI / 180 * B_rotation);


setPosition(B_x,B_y);

}
void projectile::movement()
{
	if(B_x!=3000&&B_y!=3000)
		B_speed = 12;
	B_x=B_speed*-sin(PI / 180 * B_rotation);
	B_y=-B_speed *-cos(PI / 180 * B_rotation);
	move(B_x, B_y);
	B_x = getPosition().x;
	B_y = getPosition().y;
}