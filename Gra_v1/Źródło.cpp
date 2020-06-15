
#include "Spaceship.h"
#include "Projectile.h"
#include "Asteroid.h"
#include <iostream>
using namespace std;

int main()
{
	srand(time(NULL));
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "error";
	}
	sf::Text Points_now;
	sf::Text Lives;
	sf::Text Instrukcja;
	//system("dir");
	sf::Texture background;
	sf::Sprite sprite;
	int instruct;
	long int points{};

	
	//try to load backgrount from file
	if (!background.loadFromFile("Background.png"))
	{
		cout << "error";
	}
	//set backgruound
	sprite.setTexture(background);
	
	double distance[7];

	//create window
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Astro by Tymoteusz J-G",sf::Style::Close);
	//create spaceship object
	Spaceship spaces;
	projectile bullet;
	window.setFramerateLimit(60);
	//create 7 asteroids
	Asteroid astro(2);
	Asteroid astro1(2);
	Asteroid astro2(2);
	Asteroid astro3(1);
	Asteroid astro4(1);
	Asteroid astro5(0);
	Asteroid astro6(0);

	//create array of pointers to objects
	Asteroid* table[7];
	table[0] = &astro;
	table[1] = &astro1;
	table[2] = &astro2;
	table[3] = &astro3;
	table[4] = &astro4;
	table[5] = &astro5;
	table[6] = &astro6;
	bullet.reset();
	Points_now.setFont(font);
	Instrukcja.setFont(font);
	Lives.setFont(font);
	Lives.setPosition(900, 50);
	Instrukcja.setPosition(500, 380);
	Points_now.setPosition(50, 50);
	Lives.setCharacterSize(20.0f);
	Instrukcja.setCharacterSize(50);
	Points_now.setCharacterSize(20.0f);


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
		//kliknij/trzymaj z ¿eby strzelaæ pociski
		if (window.hasFocus())
		{

		
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
				{
			
					if (bullet.B_x ==3000 && bullet.B_y ==3000)
					{ 
						auto helper = spaces.getPosition();
						auto helper_rot = spaces.getRotation();
						bullet.Shoot(helper.x,helper.y,helper_rot);
				
				
					}
				}
			//Spraw ¿eby obiekty zmienia³y pozycjê
				bullet.movement();
				spaces.movement();
		
				for (int i = 0; i < 7; i++)
				{
					table[i]->movement();
				}
		}
		//kiedy pocisk wychodzi poza ekran zresetuj go
		if (bullet.B_x >= 1024 || bullet.B_x <= 0 || bullet.B_y >= 768 || bullet.B_y <= 0)
		{
			bullet.reset();
		}
		Points_now.setString("Points: " + to_string(points));
		
		Lives.setString("Lives: " + to_string(spaces.life));

		//narysuj wszystkie obiekty
		window.draw(Points_now);
		window.draw(bullet);
		window.draw(Lives);
		window.draw(spaces);
		for (int i = 0; i < 7; i++)
		{
			window.draw(*table[i]);
		}
	//kolizja
		for (int i = 0; i < 7; i++)
		{
		distance[i] = sqrt(pow(table[i]->A_x- bullet.B_x, 2) + pow(table[i]->A_y - bullet.B_y, 2) * 1.0);
		}
	
		for (int i = 0; i < 7; i++)
		{
				if (distance[i]<table[i]->radius[table[i]->rem_lvl])
				{	
					bullet.reset();
					table[i]->death();
					points += 100 * (3-table[i]->rem_lvl);
				}
		}

		for (int i = 0; i < 7; i++)
		{
			distance[i] = sqrt(pow(table[i]->A_x - spaces.Ss_x, 2) + pow(table[i]->A_y - spaces.Ss_y, 2) * 1.0);
		}
	
		for (int i = 0; i < 7; i++)
		{ 
				if (distance[i] < table[i]->radius[table[i]->rem_lvl])
				{
					spaces.reset();
					for (int i = 0; i < 7; i++)
					{
						//usuñ szystkie obiekty z ekranu w momêcie resetu
						table[i]->reset();
					}		
				}
		}
		//jeœli osteroida wychodzi poza obszar zresetuj j¹
		
		for (int i = 0; i < 7; i++)
		{
			table[i]->out_of_bounds();
		}

		
		window.display();
	//jeœli ¿ycia s¹ równe 0 wy³¹cz grê
		if (spaces.life == 0)
		{
			break;
		}
	}


	return 0;
}


// UNECESSERY CODE
/*
		distance = sqrt(pow(astro.A_x -bullet.B_x , 2) + pow(astro.A_y - bullet.B_y, 2) * 1.0);
		distance1 = sqrt(pow(astro1.A_x - bullet.B_x, 2) + pow(astro1.A_y - bullet.B_y, 2) * 1.0);
		distance2 = sqrt(pow(astro2.A_x - bullet.B_x, 2) + pow(astro2.A_y - bullet.B_y, 2) * 1.0);
		distance3 = sqrt(pow(astro3.A_x - bullet.B_x, 2) + pow(astro3.A_y - bullet.B_y, 2) * 1.0);
		distance4 = sqrt(pow(astro4.A_x - bullet.B_x, 2) + pow(astro4.A_y - bullet.B_y, 2) * 1.0);
		distance5 = sqrt(pow(astro5.A_x - bullet.B_x, 2) + pow(astro5.A_y - bullet.B_y, 2) * 1.0);
		distance6 = sqrt(pow(astro6.A_x - bullet.B_x, 2) + pow(astro6.A_y - bullet.B_y, 2) * 1.0);
	*/

	/*
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

		*/
		/*
			distance = sqrt(pow(astro.A_x - spaces.Ss_x, 2) + pow(astro.A_y - spaces.Ss_y, 2) * 1.0);
			distance1 = sqrt(pow(astro1.A_x - spaces.Ss_x, 2) + pow(astro1.A_y - spaces.Ss_y, 2) * 1.0);
			distance2 = sqrt(pow(astro2.A_x - spaces.Ss_x, 2) + pow(astro2.A_y - spaces.Ss_y, 2) * 1.0);
			distance3 = sqrt(pow(astro3.A_x - spaces.Ss_x, 2) + pow(astro3.A_y - spaces.Ss_y, 2) * 1.0);
			distance4 = sqrt(pow(astro4.A_x - spaces.Ss_x, 2) + pow(astro4.A_y - spaces.Ss_y, 2) * 1.0);
			distance5 = sqrt(pow(astro5.A_x - spaces.Ss_x, 2) + pow(astro5.A_y - spaces.Ss_y, 2) * 1.0);
			distance6 = sqrt(pow(astro6.A_x - spaces.Ss_x, 2) + pow(astro6.A_y - spaces.Ss_y, 2) * 1.0);

			*/


		/*
						astro.reset();
						astro1.reset();
						astro2.reset();
						astro3.reset();
						astro4.reset();
						astro5.reset();
						astro6.reset();
						*/

						/*
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
								*/
								/*
										astro.out_of_bounds();
										astro1.out_of_bounds();
										astro2.out_of_bounds();
										astro3.out_of_bounds();
										astro4.out_of_bounds();
										astro5.out_of_bounds();
										astro6.out_of_bounds();
										*/

										/*
												astro.movement();
												astro1.movement();
												astro2.movement();
												astro3.movement();
												astro4.movement();
												astro5.movement();
												astro6.movement();
												*/
												/*
													window.draw(astro);
													window.draw(astro1);
													window.draw(astro2);
													window.draw(astro3);
													window.draw(astro4);
													window.draw(astro5);
													window.draw(astro6);
													*/
													/*
													double distance;
													double distance1;
													double distance2;
													double distance3;
													double distance4;
													double distance5;
													double distance6;
													*/