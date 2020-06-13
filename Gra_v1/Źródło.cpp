
#include "Spaceship.h"
#include "Projectile.h"
#include "Asteroid.h"
#include <iostream>
using namespace std;

int main()
{
	srand(time(NULL));

	//system("dir");
	sf::Texture background;
	sf::Sprite sprite;
	//try to load backgrount from file
	if (!background.loadFromFile("Background.png"))
	{
		cout << "error";
	}
	//set backgruound
	sprite.setTexture(background);
	
	double distance;
	double distance1;
	double distance2;
	double distance3;
	double distance4;
	double distance5;
	double distance6;

	//create window
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Astro by Tymoteusz J-G");
	//create spaceship object
	Spaceship spaces;
	projectile bullet;
	window.setFramerateLimit(60);
	Asteroid astro(2);
	Asteroid astro1(2);
	Asteroid astro2(2);
	Asteroid astro3(1);
	Asteroid astro4(1);
	Asteroid astro5(0);
	Asteroid astro6(0);

	bullet.reset();
	
	while (window.isOpen())
	{
		
		
		sf::Event event;
	
		while (window.pollEvent(event))
		{
		
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);

	
		window.draw(sprite);
		auto otr = spaces.getOrigin();
		
		if (otr.x == 0 && otr.y == 0)
		{
		
			spaces.setOrigin(512, 384);
			spaces.move(512, 384);
		}
		

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			
			if (bullet.B_x ==3000 && bullet.B_y ==3000)
			{ 
				auto helper = spaces.getPosition();
				auto helper_rot = spaces.getRotation();
				bullet.Shoot(helper.x,helper.y,helper_rot);
				
				
			}
		}
		//auto hef = astro.getPosition();
	//	cout << hef.x << endl << hef.y << endl;
		
	
		bullet.movement();
		spaces.movement();
		astro.movement();
		astro1.movement();
		astro2.movement();
		astro3.movement();
		astro4.movement();
		astro5.movement();
		astro6.movement();
		if (bullet.B_x >= 1024 || bullet.B_x <= 0 || bullet.B_y >= 768 || bullet.B_y <= 0)
		{
			bullet.reset();
		}
		
	
	


		window.draw(bullet);
		window.draw(spaces);
	
		window.draw(astro);
		window.draw(astro1);
		window.draw(astro2);
		window.draw(astro3);
		window.draw(astro4);
		window.draw(astro5);
		window.draw(astro6);
	
		distance = sqrt(pow(astro.A_x -bullet.B_x , 2) + pow(astro.A_y - bullet.B_y, 2) * 1.0);
		distance1 = sqrt(pow(astro1.A_x - bullet.B_x, 2) + pow(astro1.A_y - bullet.B_y, 2) * 1.0);
		distance2 = sqrt(pow(astro2.A_x - bullet.B_x, 2) + pow(astro2.A_y - bullet.B_y, 2) * 1.0);
		distance3 = sqrt(pow(astro3.A_x - bullet.B_x, 2) + pow(astro3.A_y - bullet.B_y, 2) * 1.0);
		distance4 = sqrt(pow(astro4.A_x - bullet.B_x, 2) + pow(astro4.A_y - bullet.B_y, 2) * 1.0);
		distance5 = sqrt(pow(astro5.A_x - bullet.B_x, 2) + pow(astro5.A_y - bullet.B_y, 2) * 1.0);
		distance6 = sqrt(pow(astro6.A_x - bullet.B_x, 2) + pow(astro6.A_y - bullet.B_y, 2) * 1.0);
	
		if (distance<astro.radius[astro.rem_lvl])
		{
		
			
			bullet.reset();
			astro.death();
		}
		if (distance1 < astro1.radius[astro1.rem_lvl])
		{
			//spaces.life -= 1;

		
			bullet.reset();
			astro1.death();
		}
		if (distance2 < astro2.radius[astro2.rem_lvl])
		{
			//spaces.life -= 1;

			
			bullet.reset();
			astro2.death();
		}
		if (distance3 < astro3.radius[astro3.rem_lvl])
		{
			//spaces.life -= 1;

			
			bullet.reset();
			astro3.death();
		}
		if (distance4 < astro4.radius[astro4.rem_lvl])
		{
			//spaces.life -= 1;

			bullet.reset();
			astro4.death();
		}
		if (distance5 < astro5.radius[astro5.rem_lvl])
		{
			//spaces.life -= 1;

			
			bullet.reset();
			astro5.death();
		}
		if (distance6 < astro6.radius[astro6.rem_lvl])
		{
			//spaces.life -= 1;

			bullet.reset();
			astro6.death();
		}
		distance = sqrt(pow(astro.A_x - spaces.Ss_x, 2) + pow(astro.A_y - spaces.Ss_y, 2) * 1.0);
		distance1 = sqrt(pow(astro1.A_x - spaces.Ss_x, 2) + pow(astro1.A_y - spaces.Ss_y, 2) * 1.0);
		distance2 = sqrt(pow(astro2.A_x - spaces.Ss_x, 2) + pow(astro2.A_y - spaces.Ss_y, 2) * 1.0);
		distance3 = sqrt(pow(astro3.A_x - spaces.Ss_x, 2) + pow(astro3.A_y - spaces.Ss_y, 2) * 1.0);
		distance4 = sqrt(pow(astro4.A_x - spaces.Ss_x, 2) + pow(astro4.A_y - spaces.Ss_y, 2) * 1.0);
		distance5 = sqrt(pow(astro5.A_x - spaces.Ss_x, 2) + pow(astro5.A_y - spaces.Ss_y, 2) * 1.0);
		distance6 = sqrt(pow(astro6.A_x - spaces.Ss_x, 2) + pow(astro6.A_y - spaces.Ss_y, 2) * 1.0);
		if (distance < astro.radius[astro.rem_lvl])
		{
			
			
			spaces.reset();
			astro.reset();
			astro1.reset();
			astro2.reset();
			astro3.reset();
			astro4.reset();
			astro5.reset();
			astro6.reset();
			
			//cout << "shit got hit" << endl << spaces.life;
		}
		if (distance1 < astro1.radius[astro1.rem_lvl])
		{


			spaces.reset();
			astro.reset();
			astro1.reset();
			astro2.reset();
			astro3.reset();
			astro4.reset();
			astro5.reset();
			astro6.reset();
			//cout << "shit got hit" << endl << spaces.life;
		}
		if (distance2 < astro2.radius[astro2.rem_lvl])
		{


			spaces.reset();
			astro.reset();
			astro1.reset();
			astro2.reset();
			astro3.reset();
			astro4.reset();
			astro5.reset();
			astro6.reset();
			//cout << "shit got hit" << endl << spaces.life;
		}
		if (distance3 < astro3.radius[astro3.rem_lvl])
		{


			spaces.reset();
			astro.reset();
			astro1.reset();
			astro2.reset();
			astro3.reset();
			astro4.reset();
			astro5.reset();
			astro6.reset();
			//cout << "shit got hit" << endl << spaces.life;
		}
		if (distance4 < astro4.radius[astro4.rem_lvl])
		{


			spaces.reset();
			astro.reset();
			astro1.reset();
			astro2.reset();
			astro3.reset();
			astro4.reset();
			astro5.reset();
			astro6.reset();
			//cout << "shit got hit" << endl << spaces.life;
		}
		if (distance5 < astro5.radius[astro5.rem_lvl])
		{


			spaces.reset();
			astro.reset();
			astro1.reset();
			astro2.reset();
			astro3.reset();
			astro4.reset();
			astro5.reset();
			astro6.reset();
			//cout << "shit got hit" << endl << spaces.life;
		}
		if (distance6 < astro6.radius[astro6.rem_lvl])
		{


			spaces.reset();
			astro.reset();
			astro1.reset();
			astro2.reset();
			astro3.reset();
			astro4.reset();
			astro5.reset();
			astro6.reset();
			//cout << "shit got hit" << endl << spaces.life;
		}
		astro.out_of_bounds();
		astro1.out_of_bounds();
		astro2.out_of_bounds();
		astro3.out_of_bounds();
		astro4.out_of_bounds();
		astro5.out_of_bounds();
		astro6.out_of_bounds();
		window.display();
	
		if (spaces.life == 0)
		{
			break;
		}
	}


	return 0;
}