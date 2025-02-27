//#include <iostream>
//#include <SFML\System.hpp>
//#include <SFML\Window.hpp>
//#include <SFML\Graphics.hpp>
//using namespace sf;
//
//int main()
//{
//	RenderWindow window(VideoMode(640, 480), "Shooting_Game", Style::Default);
//	window.setFramerateLimit(60);
//
//	CircleShape hoop(50.f);
//	int dir = 0;
//	hoop.setFillColor(Color::Black);
//	hoop.setOutlineThickness(2.f);
//	hoop.setOutlineColor(Color::Blue);
//	hoop.setPosition(0, 50.f);
//
//	CircleShape ball;
//	bool isShot = false;
//	ball.setRadius(20.f);
//	ball.setFillColor(Color::Red);
//	ball.setPosition(Vector2f(0, window.getSize().y - ball.getRadius() * 3));
//
//	while (window.isOpen())
//	{
//
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
//		//Update hoop
//		if (hoop.getPosition().x < 0)
//			dir = 1;
//		else if (hoop.getPosition().x + (2 * hoop.getRadius()) >= window.getSize().x)
//			dir = 0;
//		if (dir == 0)
//			hoop.move(-5.f, 0);
//		else
//			hoop.move(5.f, 0);
//
//		//Update ball
//		if (Mouse::isButtonPressed(Mouse::Left))
//			isShot = true;
//		if (!isShot)
//			ball.setPosition(Mouse::getPosition(window).x, ball.getPosition().y);
//		else
//			ball.move(0, -5.f);
//
//		//Collision ball
//		if (ball.getPosition().y <= 0 || ball.getGlobalBounds().intersects(hoop.getGlobalBounds()))
//		{
//			isShot = false;
//			ball.setPosition(ball.getPosition().x, window.getSize().y - ball.getRadius() * 3);
//
//		}
//
//
//		window.clear(Color::White);
//
//		//Draw
//		window.draw(hoop);
//		window.draw(ball);
//
//		window.display();
//	}
//
//	return 0;
//}