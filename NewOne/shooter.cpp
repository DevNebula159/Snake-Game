//#include <SFML\Window.hpp>
//#include <SFML\System.hpp>
//#include <SFML\Graphics.hpp>
//#include <vector>
//#include <cstdlib>
//#include <iostream>
//using namespace sf;
//using namespace std;
//
//int main()
//{
//	srand(time(NULL));
//
//	RenderWindow window(VideoMode(1280, 720), "Shooter Game", Style::Default);
//	window.setFramerateLimit(60);
//
//	//Balls
//	CircleShape projectile;
//	projectile.setFillColor(Color::Red);
//	projectile.setRadius(5.f);
//
//	RectangleShape enemy;
//	enemy.setFillColor(Color::Blue);
//	enemy.setSize(Vector2f(50.f, 50.f));
//
//	CircleShape player;
//	player.setFillColor(Color::White);
//	player.setRadius(50.f);
//	player.setPosition(window.getSize().x / 2 - player.getRadius(), window.getSize().y - player.getRadius()*2 - 10.f);
//	Vector2f playerCenter;
//	int shootTimer = 0;
//
//	vector<RectangleShape> enemies;
//	enemies.push_back(RectangleShape(enemy));
//	int enemySpawnTimer = 0;
//
//	vector<CircleShape> projectiles;
//	projectiles.push_back(CircleShape(projectile));
//
//	while (window.isOpen())
//	{
//		Event event;
//
//		while (window.pollEvent(event))
//		{
//			if (event.type == event.Closed)
//				window.close();
//			if (event.type == event.KeyPressed && event.key.code == Keyboard::Escape)
//				window.close();
//
//		}
//
//		//Update
//		playerCenter = Vector2f(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());
//		if (shootTimer < 5)
//			shootTimer++;
//
//		player.setPosition(Mouse::getPosition(window).x, player.getPosition().y);
//
//		//Projectiles
//		if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 5) //Shoot
//		{
//			projectile.setPosition(playerCenter);
//			projectiles.push_back(CircleShape(projectile));
//			shootTimer = 0;
//		}
//		for (size_t i = 0; i < projectiles.size(); i++)
//		{
//			projectiles[i].move(0.f, -10.f);
//			if (projectiles[i].getPosition().y <= 0)
//				projectiles.erase(projectiles.begin() + i);
//		}
//
//		//Enemies
//		if (enemySpawnTimer < 35)
//			enemySpawnTimer++;
//
//		if (enemySpawnTimer >= 35)
//		{
//			enemy.setPosition(rand() % int(window.getSize().x - enemy.getSize().x), 0);
//			enemies.push_back(RectangleShape(enemy));
//			enemySpawnTimer = 0;
//		}
//		for (size_t i = 0; i < enemies.size(); i++)
//		{
//			enemies[i].move(0.f, 3.f);
//			if (enemies[i].getPosition().y > window.getSize().y)
//				enemies.erase(enemies.begin() + i);
//		}
//
//		//Collision
//		for (size_t i = 0; i < projectiles.size(); i++)
//		{
//			for (size_t k = 0; k < enemies.size(); k++)
//			{
//				if (projectiles[i].getGlobalBounds().intersects(enemies[k].getGlobalBounds()))
//				{
//					projectiles.erase(projectiles.begin() + i);
//					enemies.erase(enemies.begin() + k);
//					break;
//				}
//			}
//		}
//
//		window.clear(Color::Black);
//		//Draw
//		window.draw(player);
//		for (size_t i = 0; i < enemies.size(); i++)
//		{
//			window.draw(enemies[i]);
//		}
//
//		for (size_t i = 0; i < projectiles.size(); i++)
//		{
//			window.draw(projectiles[i]);
//		}
//		window.display();
//	}
//
//
//	return 0;
//}