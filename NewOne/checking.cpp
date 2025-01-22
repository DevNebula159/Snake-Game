//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/System.hpp>
//#include <string>
//#include <fstream>
//#include <cstdlib>
//#include <windows.h>
//#include <iostream>
//
////namespace of sfml and c++ to avoid std:: and sf::
//
//using namespace std;
//using namespace sf;
//
//
////Dimensions of window and Grid size
//
//int dir;
//int width = 1920;
//int height = 1080;
//int gridsize = 30;
//
////defining dimensions with pixels
//
//int cellX = width / gridsize;
//int cellY = height / gridsize;
//
////for transition between game states
//
//int gamestate = 0;
//int flag;
//
////font for main title of game and other strings
//
//Font font;
//Font heading;
//
////to enter the name of player
//
//string pname;
//
//// declaration of high scores
//
//const int maxscores = 3;
//int highscores[maxscores] = { 0 };
//
////Declaration of snake
//
//RectangleShape snakehead;
//int snakeX[200] = { cellX / 2 };
//int snakeY[200] = { cellY / 2 };
//int sankelength = 1;
//
////A small snake segment at color selection menu
//
//RectangleShape tempsnake(Vector2f(gridsize - 1, gridsize - 1));
//const int tempsnakelength = 8;
//int tempsnakeX = cellX / 2 - 4;
//int tempsnakeY = cellY / 2;
//int tempsnake1[tempsnakelength];
//
//
////for snake color selection
//
//int tempdir = 0;
//int tempsize = 0;
//
////snake colors combination variables
//
//int red1, green1, blue1;
//
////declaration of food
//
//RectangleShape food(Vector2f(gridsize, gridsize));
//int foodX;
//int foodY;
//
//// Bonus food
//
//RectangleShape bonus(Vector2f(gridsize * 2, gridsize * 2));
//int bonusX;
//int bonusY;
//
//// declaration of score
//
//int score = 0;
//Text scoretext;
//int remaining_score = 100;
//Text levelscoretext;
//
//// declration and parameters of obstacles
//
//RectangleShape block(Vector2f(gridsize - 1, gridsize - 1));
//int startX;
//int startY;
//int newX;
//int newY;
//const int maxobstacles = 20;
//const int maxobslength = 5;
//int numincrease = 16;
//int obstacleX[maxobstacles * maxobslength];
//int obstacleY[maxobstacles * maxobslength];
//int obsstart[maxobstacles];
//int obslengths[maxobstacles];
//int start;
//int lengths;
//int ObstacleX;
//int ObstacleY;
//int obsindex;
//int cindex;
//
////user customizeable obstacles
//
//int maxobstacles1 = cellX * cellY;
//int obstaclecount = 0;
//int obstaclesnewX[2000];
//int obstaclesnewY[2000];//indicators for customization
//
////speed of snake
//
//int speed = 60;
//
////custom speed variables
//int custom_speed = 50;
//int red = 0;
//int green = 255;
//int blue = 0;
//RectangleShape loader(Vector2f(gridsize, gridsize));
//Text speed1("Customize your speed", font, 60);
//int speedX = cellX / 2 - 5;
//int speedY = cellY / 2;
//const int cellno = 10;
//int  scells = 0;
//int lader[cellno];
//
//// Global game over variable
//
//bool gameover = false;
//
////menu option variables for different
//
//int mainmenuoptions = 0;
//int modemenuoptions = 0;
//int colormenuoptions = 0;
//int ceaseoption = 0;
//int gameoption;
//
//// declaration of Functions by using headers to be called first in another function
//
//void Score();
////void nameinput();
//void reset(RenderWindow& window);
//void reset1();
//void createobstacles(RenderWindow& window);
//void wallcollision();
//void boxwallcollision();
//void respawnObstacles();
//void foodspawn(RenderWindow& window);
//void foodcollision(RenderWindow& window);
//
////to set position of text in middle
//
//void setTextInMiddle(Text& text, RenderWindow& window)
//{
//    float textwidth = text.getLocalBounds().width;
//    float textheight = text.getLocalBounds().height;
//
//    float textX = (window.getSize().x - textwidth) / 2;
//    float textY = (window.getSize().y - textheight) / 2;
//
//
//    text.setPosition(textX, textY);
//}
//
//
//void savegame()
//{
//
//}
//
////to save high score before game is over
//
//void savehighscores(int score)
//{
//
//}
//
//// for snake movement
//
//void snakemovement()
//{
//
//    for (int i = sankelength; i > 0; i--)
//    {
//
//        snakeX[i] = snakeX[i - 1];
//        snakeY[i] = snakeY[i - 1];
//    }
//
//    if (dir == 1)
//    {
//        snakeY[0]--; //moves the snake upward
//    }
//    else if (dir == 2)
//    {
//        snakeY[0]++; //moves the snake downward
//    }
//    else if (dir == 3)
//    {
//        snakeX[0]++; //moves the snake rightwards
//    }
//    else if (dir == 4)
//    {
//        snakeX[0]--; //moves the snake leftwards
//    }
//
//
//    if (gamestate != 9)
//    {
//        Sleep(speed);
//    }
//    else
//    {
//        Sleep(custom_speed);
//    }
//
//}
//
//
////collision with the wall in endless mode to teleport it from opposite side
//
//void wallcollision()
//{
//
//    if (snakeX[0] >= cellX)
//    {
//        snakeX[0] = 0;
//    }
//    if (snakeY[0] >= cellY)
//    {
//        snakeY[0] = 0;
//    }
//    if (snakeX[0] < 0)
//    {
//        snakeX[0] = cellX - 1;
//    }
//    if (snakeY[0] < 0)
//    {
//        snakeY[0] = cellY - 1;
//    }
//
//}
//
////collosion of snake with the walls in box mode
//
//void boxwallcollision()
//{
//
//    if (snakeX[0] >= cellX || snakeX[0] < 0 || snakeY[0] >= cellY || snakeY[0] < 0)
//	{
//		flag = gamestate;
//		gamestate = 6;
//    }
//
//}
//
////fuction to display score of the gamplay
//
//void Score()
//{
//    scoretext.setString("SCORE: " + to_string(score));
//    scoretext.setFont(font);
//    scoretext.setCharacterSize(25);
//    scoretext.setLetterSpacing(1.7f);
//    scoretext.setFillColor(Color(0, 255, 0));
//    scoretext.setPosition(10.f, 10.f);
//
//    levelscoretext.setString("REMAINING: " + to_string(remaining_score));
//    levelscoretext.setFont(font);
//    levelscoretext.setCharacterSize(25);
//    levelscoretext.setLetterSpacing(1.7f);
//    levelscoretext.setFillColor(Color(0, 255, 0));
//    levelscoretext.setPosition(10.f, 40.f);
//
//
//}
//
//// to flag the food is not propduced notb on the body of snake
//
//bool isNotonsnake(int x, int y)
//{
//    for (int i = 0; i < sankelength; i++)
//    {
//        if (snakeX[i] == x && snakeY[i] == y)
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//// to flag obstacles production on snake body
//
//bool isNotonsnake1(int x, int y)
//{
//    for (int i = 0; i < sankelength; i++)
//    {
//        if (snakeX[i] == x && snakeY[i] == y)
//        {
//            return false;
//        }
//    }
//    return true;
//}
//
//// obstacles that can be regenrated anr spawned again
//
//void respawnObstacles()
//{
//    obsindex = 0;
//    for (int i = 0; i < (maxobstacles - numincrease); i++)
//    {
//        bool valid = false;
//        obsstart[i] = obsindex;
//        obslengths[i] = 0;
//        while (!valid)
//        {
//            valid = true;
//            cindex = obsindex;
//
//            startX = rand() % cellX;
//            startY = rand() % cellY;
//
//            for (int j = 0; j < maxobslength; j++)
//            {
//                newX = startX;
//                newY = startY;
//
//                if (i % 2 == 0)
//                {
//                    newX = startX + j;
//                }
//                else
//                {
//                    newY = startY + j;
//                }
//
//                if (!isNotonsnake1(newX, newY) && valid == true)
//                {
//                    valid = false;
//
//                }
//                else
//                {
//                    obstacleX[cindex] = newX;
//                    obstacleY[cindex] = newY;
//                    cindex++;
//                    obslengths[i]++;
//                }
//            }
//
//            if (!valid)
//            {
//                obsindex = obsstart[i];
//                obslengths[i] = 0;
//            }
//            else
//            {
//                obsindex = cindex;
//            }
//        }
//
//    }
//} //remain
//
//void drawobstacles1(RenderWindow& window)
//{
//    block.setFillColor(Color(0, 144, 144));
//
//    for (int i = 0; i < (maxobstacles - numincrease); i++)
//    {
//        start = obsstart[i];
//        lengths = obslengths[i];
//
//        for (int j = 0; j < lengths; j++)
//        {
//            ObstacleX = obstacleX[start + j];
//            ObstacleY = obstacleY[start + j];
//
//            block.setPosition(ObstacleX * gridsize, ObstacleY * gridsize);
//            window.draw(block);
//
//        }
//    }
//
//}
//
//// game over when collide with obstacle
//
//void obstaclecollision(RenderWindow& window)
//{
//    if (gamestate == 4)
//    {
//        for (int i = 0; i < (maxobstacles - numincrease); i++)
//        {
//            start = obsstart[i];
//            lengths = obslengths[i];
//
//            for (int j = 0; j < lengths; j++)
//            {
//                ObstacleX = obstacleX[start + j];
//                ObstacleY = obstacleY[start + j];
//
//                if (snakeX[0] == ObstacleX && snakeY[0] == ObstacleY)
//                {
//                    flag = gamestate;
//                    /*flaghigh();*/
//
//                    for (int i = 0; i < maxscores; i++)
//                    {
//                        if (score > highscores[i])
//                        {
//                            gamestate = 15;
//                        }
//                        else
//                        {
//                            gamestate = 6;
//                        }
//                    }
//                    return;
//                }
//            }
//        }
//    }
//
//    if (gamestate == 9)
//    {
//        for (int i = 0; i < obstaclecount; i++)
//        {
//
//            if (snakeX[0] == obstaclesnewX[i] && snakeY[0] == obstaclesnewY[i])
//            {
//                flag = gamestate;
//                /*flaghigh();*/
//
//                for (int i = 0; i < maxscores; i++)
//                {
//                    if (score > highscores[i])
//                    {
//                        gamestate = 9;
//                    }
//                    else
//                    {
//                        gamestate = 6;
//                    }
//                }
//                return;
//            }
//        }
//    }
//
//}
//
////to flag position of food on obstacle
//
//bool ispositionavailable(int x, int y)
//{
//
//    bool isavailable = true;
//    if (gamestate == 4)
//    {
//        for (int i = 0; i < maxobstacles; i++)
//        {
//            start = obsstart[i];
//            lengths = obslengths[i];
//
//            for (int j = 0; j < lengths; j++)
//            {
//                ObstacleX = obstacleX[start + j];
//                ObstacleY = obstacleY[start + j];
//
//                if (x == ObstacleX && y == ObstacleY && isavailable == true)
//                {
//                    isavailable = false;
//                }
//
//            }
//        }
//    }
//
//    if (gamestate == 9)
//    {
//        for (int i = 0; i < obstaclecount; i++)
//        {
//            if (x == ObstacleX && y == ObstacleY && isavailable == true)
//            {
//                isavailable = false;
//            }
//
//        }
//    }
//    return isavailable;
//}
//
//
////to generate food at valid random places
//
//void foodspawn(RenderWindow& window)
//{
//    bool validposition = false;
//
//    while (!validposition)
//    {
//        foodX = rand() % cellX;
//        foodY = rand() % cellY;
//
//        bool flagsnake = isNotonsnake(foodX, foodY);
//        bool flagobstacle = ispositionavailable(foodX, foodY);
//
//        if (flagsnake && flagobstacle)
//        {
//            validposition = true;
//        }
//    }
//
//    food.setPosition(Vector2f(foodX * gridsize, foodY * gridsize));
//}
//
//// to generate a big bonus food
//
//void bonusspawn(RenderWindow& window)
//{
//
//    bool validposition = false;
//
//    while (!validposition)
//    {
//        bonusX = rand() % cellX - 1;
//        bonusY = rand() % cellY - 1;
//
//        bool flagsnake = isNotonsnake(bonusX, bonusY);
//        bool flagobstacle = ispositionavailable(bonusX, bonusY);
//
//        if (flagsnake && flagobstacle)
//        {
//            validposition = true;
//        }
//    }
//
//    food.setPosition(Vector2f(bonusX * gridsize, bonusY * gridsize));
//}
//
//// flag snake eats the food and increase length and score
//
//void foodcollision(RenderWindow& window)
//{
//
//    if (snakeX[0] == foodX && snakeY[0] == foodY)
//    {
//        foodspawn(window);
//        score += 10;
//
//        if (gamestate == 4)
//        {
//
//            remaining_score -= 10;
//
//            if (remaining_score == 0)
//            {
//                //gamestate 13;
//                remaining_score = 100;
//            }
//        }
//
//        if (sankelength < 199)
//        {
//            sankelength++;
//
//        }
//
//        if (speed > 10)
//        {
//            speed--;
//        }
//    }
//}
//
////flag collision with the either side of the bonus
//
//void bonuscollision(RenderWindow& window)
//{
//
//    if ((snakeX[0] == bonusX && snakeY[0] == bonusY) || (snakeX[0] == bonusX + 1 && snakeY[0] == bonusY) || (snakeX[0] == bonusX && snakeY[0] == bonusY + 1) || (snakeX[0] == bonusX + 1 && snakeY[0] == bonusY + 1))
//    {
//
//        bonusspawn(window);
//        score += 40;
//
//        if (sankelength < 198)
//        {
//            sankelength += 1;
//        }
//
//        if (speed > 10)
//        {
//            speed -= 3;
//        }
//
//        savegame();
//    }
//}
//
//// to flag the collision of snake with itself and true then gameover
//
//void snakecollision(RenderWindow& window)
//{
//
//    if (sankelength > 1)
//    {
//        for (int i = 1; i <= sankelength; i++)
//        {
//
//            if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
//            {
//				flag = gamestate;
//				gamestate = 6;
//
//            }
//        }
//    }
//}
//
////Menu 1 with different options
//
//void mainmenu(RenderWindow& window)
//{
//
//    Text title("SNAKE GAME", heading, 150);
//    title.setFillColor(Color(0, 35, 67));
//    setTextInMiddle(title, window);
//    title.setPosition(Vector2f(title.getPosition().x, title.getPosition().y - 350));
//
//    const int menu1size = 5;
//
//    string menu1options[menu1size] = { "New Game","Cotinue","High Score","Instructons","Exit" };
//
//    Event event;
//
//    while (window.pollEvent(event))
//    {
//
//        if (event.type == Event::Closed)
//        {
//            window.close();
//        }
//
//        if (event.type == Event::KeyPressed)
//        {
//
//            if (event.key.code == Keyboard::Escape)
//            {
//                window.close();
//            }
//            else if (event.key.code == Keyboard::W)
//            {
//                mainmenuoptions--;
//
//                if (mainmenuoptions < 0)
//                {
//                    mainmenuoptions = menu1size - 1;
//                }
//            }
//            else if (event.key.code == Keyboard::S)
//            {
//                mainmenuoptions++;
//
//                if (mainmenuoptions >= menu1size)
//                {
//                    mainmenuoptions = 0;
//                }
//            }
//            else if (event.key.code == Keyboard::Enter)
//            {
//
//                if (mainmenuoptions == 0)
//                {
//                    reset(window);
//                    reset1();
//                    gamestate = 1;
//                }
//                else if (mainmenuoptions == 1)
//                {
//                    gamestate = 11;
//                }
//                else if (mainmenuoptions == 2)
//                {
//                    gamestate = 10;
//                }
//                else if (mainmenuoptions == 3)
//                {
//                    gamestate = 14;
//                }
//                else if (mainmenuoptions == 4)
//                {
//                    window.close();
//                }
//            }
//        }
//    }
//
//    int m1pflager = -160;
//    Text menu1text[menu1size];
//
//    for (int i = 0; i < menu1size; i++)
//    {
//        menu1text[i].setFont(font);
//        menu1text[i].setString(menu1options[i]);
//        menu1text[i].setCharacterSize(50);
//        menu1text[i].setLetterSpacing(1.7f);
//        setTextInMiddle(menu1text[i], window);
//        menu1text[i].setPosition(Vector2f(menu1text[i].getPosition().x, menu1text[i].getPosition().y + m1pflager));
//        m1pflager += 80;
//
//    }
//
//    for (int i = 0; i < menu1size; i++)
//    {
//        if (i == mainmenuoptions)
//        {
//            menu1text[i].setFillColor(Color(0, 255, 0));
//        }
//        else
//        {
//            menu1text[i].setFillColor(Color(0, 0, 0));
//        }
//    }
//
//    //Update
//
//    window.clear(Color::White);
//
//    //Draw
//
//    window.draw(title);
//    for (int i = 0; i < menu1size; i++)
//    {
//        window.draw(menu1text[i]);
//    }
//}
//
////menu2 for mode selection
//
//void modemenu(RenderWindow& window)
//{
//
//    Text title("Select Mode", heading, 150);
//    title.setLetterSpacing(1.7f);
//    title.setFillColor(Color(0, 35, 67));
//    setTextInMiddle(title, window);
//    title.setPosition(Vector2f(title.getPosition().x, title.getPosition().y - 300));
//
//    const int menu2size = 5;
//    string menu2options[menu2size] = { "Endless Mode","Level Mode","Custom Mode","Box mode","Exit" };
//
//    Event event;
//
//    while (window.pollEvent(event))
//    {
//
//        if (event.type == Event::Closed)
//        {
//            window.close();
//        }
//
//        if (event.type == Event::KeyPressed)
//        {
//
//            if (event.key.code == Keyboard::Escape)
//            {
//                window.close();
//            }
//            else if (event.key.code == Keyboard::W)
//            {
//                modemenuoptions--;
//
//                if (modemenuoptions < 0)
//                {
//                    modemenuoptions = menu2size - 1;
//                }
//            }
//            else if (event.key.code == Keyboard::S)
//            {
//                modemenuoptions++;
//
//                if (modemenuoptions >= menu2size)
//                {
//                    modemenuoptions = 0;
//                }
//            }
//            else if (event.key.code == Keyboard::Enter)
//            {
//
//                if (modemenuoptions == 0)
//                {
//                    flag = 3;
//                    gamestate = 2;
//                }
//                else if (modemenuoptions == 1)
//                {
//                    flag = 4;
//                    gamestate = 2;
//                }
//                else if (modemenuoptions == 2)
//                {
//                    flag = 9;
//                    gamestate = 7;
//                }
//                else if (modemenuoptions == 3)
//                {
//                    flag = 12;
//                    gamestate = 2;
//                }
//                else if (modemenuoptions == 4)
//                {
//                    gamestate = 0;
//                }
//            }
//        }
//    }
//
//    int m2pflager = -160;
//    Text menu2text[menu2size];
//
//    for (int i = 0; i < menu2size; i++)
//    {
//        menu2text[i].setFont(font);
//        menu2text[i].setString(menu2options[i]);
//        menu2text[i].setCharacterSize(50);
//        menu2text[i].setLetterSpacing(1.7f);
//        setTextInMiddle(menu2text[i], window);
//        menu2text[i].setPosition(Vector2f(menu2text[i].getPosition().x, menu2text[i].getPosition().y + m2pflager));
//        m2pflager += 80;
//
//    }
//
//    for (int i = 0; i < menu2size; i++)
//    {
//        if (i == modemenuoptions)
//        {
//            menu2text[i].setFillColor(Color(0, 255, 0));
//        }
//        else
//        {
//            menu2text[i].setFillColor(Color(0, 0, 0));
//        }
//    }
//
//    //Update
//
//    window.clear(Color::White);
//
//    //Draw
//
//    window.draw(title);
//    for (int i = 0; i < menu2size; i++)
//    {
//        window.draw(menu2text[i]);
//    }
//}
//
//void menu2load(RenderWindow& window)
//{
//
//    Text title("Select Mode", heading, 150);
//    title.setLetterSpacing(1.7f);
//    title.setFillColor(Color(0, 35, 67));
//    setTextInMiddle(title, window);
//    title.setPosition(Vector2f(title.getPosition().x, title.getPosition().y - 300));
//
//    const int menu2size = 5;
//    string menu2options[menu2size] = { "Endless Mode","Level Mode","Custom Mode","Box mode","Exit" };
//
//    Event event;
//
//    while (window.pollEvent(event))
//    {
//
//        if (event.type == Event::Closed)
//        {
//            window.close();
//        }
//
//        if (event.type == Event::KeyPressed)
//        {
//
//            if (event.key.code == Keyboard::Escape)
//            {
//                gamestate = 0;
//            }
//            else if (event.key.code == Keyboard::W)
//            {
//                modemenuoptions--;
//
//                if (modemenuoptions < 0)
//                {
//                    modemenuoptions = menu2size - 1;
//                }
//            }
//            else if (event.key.code == Keyboard::S)
//            {
//                modemenuoptions++;
//
//                if (modemenuoptions >= menu2size)
//                {
//                    modemenuoptions = 0;
//                }
//            }
//            else if (event.key.code == Keyboard::Enter)
//            {
//
//                if (modemenuoptions == 0)
//                {
//                    flag = 3;
//                    /*loadgame();*/
//                    gamestate = flag;
//                }
//                else if (modemenuoptions == 1)
//                {
//                    flag = 4;
//                    /*loadgame();*/
//                    gamestate = flag;
//                }
//                else if (modemenuoptions == 2)
//                {
//                    flag = 9;
//                    /*loadgame();*/
//                    gamestate = flag;
//                }
//                else if (modemenuoptions == 3)
//                {
//                    flag = 12;
//                    //loadgame();
//                    gamestate = flag;
//                }
//                else if (modemenuoptions == 4)
//                {
//                    gamestate = 0;
//                }
//            }
//        }
//    }
//
//    int m2pflager = -160;
//    Text menu2text[menu2size];
//
//    for (int i = 0; i < menu2size; i++)
//    {
//        menu2text[i].setFont(font);
//        menu2text[i].setString(menu2options[i]);
//        menu2text[i].setCharacterSize(50);
//        menu2text[i].setLetterSpacing(1.7f);
//        setTextInMiddle(menu2text[i], window);
//        menu2text[i].setPosition(Vector2f(menu2text[i].getPosition().x, menu2text[i].getPosition().y + m2pflager));
//        m2pflager += 80;
//
//    }
//
//    for (int i = 0; i < menu2size; i++)
//    {
//        if (i == modemenuoptions)
//        {
//            menu2text[i].setFillColor(Color(0, 56, 96));
//        }
//        else
//        {
//            menu2text[i].setFillColor(Color(0, 57, 57));
//        }
//    }
//
//    //Update
//
//    window.clear();
//
//    //Draw
//
//    window.draw(title);
//    for (int i = 0; i < menu2size; i++)
//    {
//        window.draw(menu2text[i]);
//    }
//}
//
////snake color selection menu before game is loaded
//
//void colormenu(RenderWindow& window)
//{
//
//    for (int i = 0; i < tempsnakelength; i++)
//    {
//        tempsnake1[i] = i;
//
//    }
//    tempsnake.setPosition(Vector2f(tempsnakeX - 4, tempsnakeY));
//
//    Text title("Select snake Color", font, 90);
//    title.setFillColor(Color(0, 98, 67));
//    title.setLetterSpacing(1.7f);
//    setTextInMiddle(title, window);
//    title.setPosition(Vector2f(title.getPosition().x, title.getPosition().y - 310));
//
//    Text back("Press escape to return to mode selection menu", font, 90);
//    back.setFillColor(Color(0, 6, 34));
//    back.setLetterSpacing(1.7f);
//    setTextInMiddle(back, window);
//    back.setPosition(Vector2f(back.getPosition().x, back.getPosition().y + 350));
//
//    const int menu3size = 7;
//    string menu3options[menu3size] = { "Green","Red","Blue","Purple","White","Pink","Grey" };
//
//    Event event;
//    while (window.pollEvent(event))
//    {
//
//        if (event.type == Event::Closed)
//        {
//            window.close();
//        }
//
//        if (event.type == Event::KeyPressed)
//        {
//
//            if (event.key.code == Keyboard::Escape)
//            {
//                gamestate = 1;
//            }
//            else if (event.key.code == Keyboard::W)
//            {
//                colormenuoptions--;
//
//                if (colormenuoptions < 0)
//                {
//                    colormenuoptions = menu3size - 1;
//                }
//            }
//            else if (event.key.code == Keyboard::S)
//            {
//                colormenuoptions++;
//
//                if (colormenuoptions >= menu3size)
//                {
//                    colormenuoptions = 0;
//                }
//            }
//            else if (event.key.code == Keyboard::Enter)
//            {
//                gamestate = flag;
//            }
//        }
//    }
//
//    int n3pflager = -180;
//    Text menu3text[menu3size];
//
//    for (int i = 0; i < menu3size; i++)
//    {
//        menu3text[i].setFont(font);
//        menu3text[i].setString(menu3options[i]);
//        menu3text[i].setCharacterSize(40);
//        menu3text[i].setLetterSpacing(1.7f);
//        setTextInMiddle(menu3text[i], window);
//        menu3text[i].setPosition(Vector2f(menu3text[i].getPosition().x / 2, menu3text[i].getPosition().y + n3pflager));
//        n3pflager += 60;
//    }
//
//    for (int i = 0; i < menu3size; i++)
//    {
//
//        if (i == colormenuoptions)
//        {
//            if (i == 0)
//            {
//                red1 = 0; green1 = 255; blue1 = 0;
//                menu3text[i].setFillColor(Color(red1, green1, blue1));
//                tempsnake.setFillColor(Color(red1, green1, blue1));
//            }
//            if (i == 1)
//            {
//                red1 = 227; green1 = 0; blue1 = 0;
//                menu3text[i].setFillColor(Color(red1, green1, blue1));
//                tempsnake.setFillColor(Color(red1, green1, blue1));
//            }
//            if (i == 2)
//            {
//                red1 = 0; green1 = 0; blue1 = 167;
//                menu3text[i].setFillColor(Color(red1, green1, blue1));
//                tempsnake.setFillColor(Color(red1, green1, blue1));
//            }
//            if (i == 3)
//            {
//                red1 = 284; green1 = 0; blue1 = 284;
//                menu3text[i].setFillColor(Color(red1, green1, blue1));
//                tempsnake.setFillColor(Color(red1, green1, blue1));
//            }
//            if (i == 4)
//            {
//                red1 = 255; green1 = 255; blue1 = 255;
//                menu3text[i].setFillColor(Color(red1, green1, blue1));
//                tempsnake.setFillColor(Color(red1, green1, blue1));
//            }
//            if (i == 5)
//            {
//                red1 = 255; green1 = 105; blue1 = 155;
//                menu3text[i].setFillColor(Color(red1, green1, blue1));
//                tempsnake.setFillColor(Color(red1, green1, blue1));
//            }
//            if (i == 6)
//            {
//                red1 = 128; green1 = 128; blue1 = 128;
//                menu3text[i].setFillColor(Color(red1, green1, blue1));
//                tempsnake.setFillColor(Color(red1, green1, blue1));
//            }
//
//        }
//        else
//        {
//            menu3text[i].setFillColor(Color(155, 155, 150));
//        }
//
//    }
//
//    //Update
//
//    window.clear(Color::White);
//
//    //Draw
//
//    window.draw(back);
//    window.draw(title);
//
//    //text of color selection
//
//    for (int i = 0; i < menu3size; i++)
//    {
//        window.draw(menu3text[i]);
//    }
//
//    //for snake segment on color selection menu
//
//    for (int i = 0; i < tempsnakelength; i++)
//    {
//        tempsnake.setPosition(Vector2f((tempsnakeX + i) * gridsize, tempsnakeY * gridsize));
//        window.draw(tempsnake);
//    }
//}
//
//// to draw instruction
//
//void instructions(RenderWindow& window)
//{
//
//    window.clear();
//
//    Event displayinstructions;
//
//    while (window.pollEvent(displayinstructions))
//    {
//        if (displayinstructions.type == Event::Closed)
//        {
//            window.close();
//        }
//
//        if (displayinstructions.type == Event::KeyPressed)
//        {
//            if (displayinstructions.key.code == Keyboard::Escape)
//            {
//                gamestate = 0;
//            }
//        }
//    }
//
//    Text text("How to play game", font, 60);
//    text.setFillColor(Color(0, 120, 120));
//    text.setLetterSpacing(1.7f);
//    setTextInMiddle(text, window);
//    text.setPosition(Vector2f(text.getPosition().x, text.getPosition().y - 370));
//
//    Text text1("Press ESCAPE to return to main menu", font, 70);
//    text1.setFillColor(Color(0, 120, 120));
//    text1.setLetterSpacing(1.7f);
//    setTextInMiddle(text1, window);
//    text1.setPosition(Vector2f(text.getPosition().x, text.getPosition().y + 400));
//
//    const int displaysize = 6;
//    string instructions[displaysize] = { "W -> TO MOVE UP","S -> TO MOVE DOWN","D -> TO MOVE RIGHT","A -> TO MOVE LEFT" };
//
//    Text textinstructions[displaysize];
//    int cc = -160;
//
//    for (int i = 0; i < displaysize; i++)
//    {
//        textinstructions[i].setFont(font);
//        textinstructions[i].setString(instructions[i]);
//        textinstructions[i].setCharacterSize(37);
//        textinstructions[i].setLetterSpacing(1.7f);
//        textinstructions[i].setPosition(Vector2f((cellX / 2.6) * gridsize, (cellY / 2) * gridsize));
//        textinstructions[i].setPosition(Vector2f(textinstructions[i].getPosition().x, textinstructions[i].getPosition().y + cc));
//        cc += 80;
//    }
//
//    //Draw
//
//    window.draw(text);
//    window.draw(text1);
//
//    for (int i = 0; i < displaysize; i++)
//    {
//        window.draw(textinstructions[i]);
//    }
//}
//
////endless mode with gamestate=3
//
//void endlessmode(RenderWindow& window)
//{
//
//    //head of snake
//
//    snakehead.setPosition(Vector2f(snakeX[0] * gridsize, snakeY[0] * gridsize));
//    snakehead.setFillColor(Color(red1, green1, blue1));
//    snakehead.setSize(Vector2f(gridsize - 1, gridsize - 1));
//
//    //random food
//
//    //food.setFillColor(Color(240, 122, 234));
//    food.setPosition(Vector2f(foodX * gridsize, foodY * gridsize));
//
//    Event event;
//
//
//    while (window.pollEvent(event))
//    {
//
//        if (event.type == event.Closed)
//        {
//            window.close();
//        }
//
//        if (event.type == event.KeyPressed)
//        {
//
//            if (event.key.code == Keyboard::W)
//            {
//                dir = 1;
//            }
//            if (event.key.code == Keyboard::S)
//            {
//                dir = 2;
//            }
//            if (event.key.code == Keyboard::D)
//            {
//                dir = 3;
//            }
//            if (event.key.code == Keyboard::A)
//            {
//                dir = 4;
//            }
//            if (event.key.code == Keyboard::Escape)
//            {
//                gamestate = 5;
//            }
//        }
//    }
//
//    //Update
//
//    snakemovement();
//    wallcollision();
//    Score();
//    foodcollision(window);
//    bonuscollision(window);
//    snakecollision(window);
//
//
//    window.clear(Color::White);
//
//    // Draw
//
//    for (int i = 0; i < sankelength; i++)
//    {
//        snakehead.setPosition(Vector2f(snakeX[i] * gridsize, snakeY[i] * gridsize));
//        window.draw(snakehead);
//    }
//
//    window.draw(food);
//    //window.draw(bonus);
//    window.draw(scoretext);
//
//}
//
//void levelmode(RenderWindow& window)
//{
//
//}
//
//
//bool ispositionoccupied(int x, int y, int obstaclesnewX[], int obstaclesnewY[], int obstaclecount, int gridsize)
//{
//    for (int i = 0; i < obstaclecount; i++)
//    {
//        if (obstaclesnewX[i] == x && obstaclesnewY[i] == y)
//        {
//            return true;
//        }
//    }
//    return false;
//}
//
////draw new obstacles after everylevel in infinite levels
//
//void drawobstacles2(RenderWindow& window, int obstaclenewX[], int obstaclenewY[], int obstaclecount, int gridsize)
//{
//    for (int i = 0; i < obstaclecount; i++)
//    {
//        block.setPosition(obstaclesnewX[i] * gridsize, obstaclesnewY[i] * gridsize);
//
//        if (gamestate == 7)
//        {
//            block.setFillColor(Color(128, 128, 128));
//        }
//        else if (gamestate == 9)
//        {
//            block.setFillColor(Color(0, 144, 140));
//        }
//
//        window.draw(block);
//    }
//}
//
////to create customizable  obstacles
//
//void createobstacles(RenderWindow& window)
//{
//    RectangleShape indicator(Vector2f(gridsize - 1, gridsize - 1));
//    int indicatorX = Mouse::getPosition(window).x / gridsize;
//    int indicatorY = Mouse::getPosition(window).y / gridsize;
//    indicator.setFillColor(Color(64, 65, 67));
//    indicator.setPosition(Vector2f(indicatorX * gridsize, indicatorY * gridsize));
//
//    Event event;
//
//    while (window.pollEvent(event))
//    {
//        if (event.type == Event::Closed)
//        {
//            window.close();
//        }
//        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
//        {
//            gamestate = 9;
//        }
//    }
//
//    if (Mouse::isButtonPressed(Mouse::Left))
//    {
//        int pointX = Mouse::getPosition(window).x;
//        int pointY = Mouse::getPosition(window).y;
//
//        int blockX = pointX / gridsize;
//        int blockY = pointY / gridsize;
//
//        if (obstaclecount < maxobstacles1 && !ispositionoccupied(blockX, blockY, obstaclesnewX, obstaclesnewY, obstaclecount, gridsize))
//        {
//            obstaclesnewX[obstaclecount] = blockX;
//            obstaclesnewY[obstaclecount] = blockY;
//            obstaclecount++;
//        }
//    }
//
//    Text text("Draw Obstacles", font, 30);
//    text.setFillColor(Color::White);
//    text.setPosition(Vector2f(gridsize, gridsize));
//
//    //update
//
//    snakehead.setPosition(Vector2f(snakeX[0] * gridsize, snakeY[0] * gridsize));
//    snakehead.setFillColor(Color(0, 200, 0));
//    snakehead.setSize(Vector2f(gridsize - 1, gridsize - 1));
//    /*cursorS.setPosition;*/
//    window.setMouseCursorGrabbed(true);
//
//    window.clear(Color::White);
//
//    //Draw
//    window.draw(indicator);
//    drawobstacles2(window, obstaclesnewX, obstaclesnewY, obstaclecount, gridsize);
//    window.draw(text);
//    window.draw(snakehead);
//    /*window.draw(cursor);*/
//
//}
//
////speedometer color
//
//void speedometercolor(RenderWindow& window)
//{
//
//
//}
//
////custom mode fuctionality
//
//void custommode(RenderWindow& window)
//{
//
//    //snake drawn
//
//    snakehead.setPosition(Vector2f(snakeX[0] * gridsize, snakeY[0] * gridsize));
//    snakehead.setFillColor(Color(red1, green1, blue1));
//    snakehead.setSize(Vector2f(gridsize - 1, gridsize - 1));
//
//    food.setPosition(Vector2f(foodX * gridsize, foodY * gridsize));
//
//    Event event;
//
//    while (window.pollEvent(event))
//    {
//        if (event.type == event.Closed)
//        {
//            window.close();
//        }
//
//        if (event.type == event.KeyPressed)
//        {
//            if (event.key.code == Keyboard::W)
//            {
//                dir = 1;
//            }
//            if (event.key.code == Keyboard::S)
//            {
//                dir = 2;
//            }
//            if (event.key.code == Keyboard::D)
//            {
//                dir = 3;
//            }
//            if (event.key.code == Keyboard::A)
//            {
//                dir = 4;
//            }
//            if (event.key.code == Keyboard::Escape)
//            {
//                gamestate = 5;
//            }
//        }
//    }
//
//    //update
//
//    snakemovement();
//    wallcollision();
//    Score();
//    snakecollision(window);
//    obstaclecollision(window);
//    foodcollision(window);
//
//    window.clear(Color::White);
//
//    //Draw
//    drawobstacles2(window, obstaclesnewX, obstaclesnewY, obstaclecount, gridsize);
//
//    for (int i = 0; i < sankelength; i++)
//    {
//        snakehead.setPosition(Vector2f(snakeX[i] * gridsize, snakeY[i] * gridsize));
//        window.draw(snakehead);
//    }
//    window.draw(food);
//    window.draw(scoretext);
//
//}
//
////Basic box mode fuctionality
//
//void boxmode(RenderWindow& window)
//{
//
//    //snake drawn
//
//    snakehead.setPosition(Vector2f(snakeX[0] * gridsize, snakeY[0] * gridsize));
//    snakehead.setFillColor(Color(red1, green1, blue1));
//    snakehead.setSize(Vector2f(gridsize - 1, gridsize - 1));
//
//    food.setPosition(Vector2f(foodX * gridsize, foodY * gridsize));
//
//    Event event;
//
//    while (window.pollEvent(event))
//    {
//        if (event.type == event.Closed)
//        {
//            window.close();
//        }
//
//        if (event.type == event.KeyPressed)
//        {
//            if (event.key.code == Keyboard::W)
//            {
//                dir = 1;
//            }
//            if (event.key.code == Keyboard::S)
//            {
//                dir = 2;
//            }
//            if (event.key.code == Keyboard::D)
//            {
//                dir = 3;
//            }
//            if (event.key.code == Keyboard::A)
//            {
//                dir = 4;
//            }
//            if (event.key.code == Keyboard::Escape)
//            {
//                gamestate = 5;
//            }
//        }
//    }
//
//    //update
//
//    snakemovement();
//    boxwallcollision();
//    Score();
//    snakecollision(window);
//    //bonuscollision(window);
//    foodcollision(window);
//
//    window.clear(Color::White);
//
//    for (int i = 0; i < sankelength; i++)
//    {
//        snakehead.setPosition(Vector2f(snakeX[i] * gridsize, snakeY[i] * gridsize));
//        window.draw(snakehead);
//    }
//    window.draw(food);
//    window.draw(scoretext);
//
//}
//
////to reset game
//
//void reset(RenderWindow& window)
//{
//    window.clear();
//
//    mainmenuoptions = 0;
//    modemenuoptions = 0;
//    colormenuoptions = 0;
//
//    speed = 70;
//    dir = 0;
//    for (int i = 0; i < sankelength; i++)
//    {
//        snakeX[i] = 0;
//        snakeY[i] = 0;
//    }
//    snakeX[0] = cellX / 2;
//    snakeY[0] = cellY / 2;
//    sankelength = 1;
//    tempsnakeX = cellX / 2 - 5;
//    tempsnakeY = cellY / 2;
//    tempdir = 0;
//    tempsize = 0;
//    score = 0;
//    /*nameS = { "" };*/
//
//    if (flag == 4)
//    {
//        remaining_score = 100;
//        numincrease = 16;
//        respawnObstacles();
//    }
//    foodspawn(window);
//    bonusspawn(window);
//}
//
////to reset custom mode
//
//void reset1()
//{
//    obstaclecount = 0;
//    custom_speed = 90;
//    scells = 0;
//    red = 0;
//    green = 255;
//    blue = 0;
//}
//
//// to pause game (5)
//
//void ceasegame(RenderWindow& window)
//{
//
//    window.clear(Color::White);
//
//    const int pms = 4;
//    string poptions[pms] = { "Resume","New Game","Return to Main Menu","Exit" };
//
//    Event event;
//
//    while (window.pollEvent(event))
//    {
//        if (event.type == Event::Closed)
//        {
//            window.close();
//        }
//        if (event.type == Event::KeyPressed)
//        {
//
//            if (event.key.code == Keyboard::W)
//            {
//                ceaseoption--;
//                if (ceaseoption < 0)
//                {
//                    ceaseoption = pms - 1;
//                }
//            }
//            else if (event.key.code == Keyboard::S)
//            {
//                ceaseoption++;
//                if (ceaseoption >= pms)
//                {
//                    ceaseoption = 0;
//                }
//            }
//            else if (event.key.code == Keyboard::Enter)
//            {
//                if (ceaseoption == 0)
//                {
//                    gamestate = flag;
//                }
//                else if (ceaseoption == 1)
//                {
//                    reset(window);
//                    gamestate = flag;
//                }
//                else if (ceaseoption == 2)
//                {
//                    savegame();
//                    gamestate = 0;//q
//                }
//                else if (ceaseoption == 3)
//                {
//                    savegame();
//                    window.close();
//                }
//                ceaseoption = 0;
//            }
//            else if (event.key.code == Keyboard::Escape)
//            {
//                gamestate = flag;
//                ceaseoption = 0;
//            }
//        }
//    }
//
//    int cpc = -120;
//    Text mt[pms];
//
//    for (int i = 0; i < pms; i++)
//    {
//        mt[i].setFont(font);
//        mt[i].setString(poptions[i]);
//        mt[i].setCharacterSize(50);
//        mt[i].setLetterSpacing(1.7f);
//        setTextInMiddle(mt[i], window);
//        mt[i].setPosition(Vector2f(mt[i].getPosition().x, mt[i].getPosition().y + cpc));
//        cpc += 80;
//    }
//
//    for (int i = 0; i < pms; i++)
//    {
//        if (i == ceaseoption)
//        {
//            mt[i].setFillColor(Color(0, 130, 130));
//        }
//        else
//        {
//            mt[i].setFillColor(Color::Black);
//        }
//    }
//
//    for (int i = 0; i < pms; i++)
//    {
//        window.draw(mt[i]);
//    }
//    Score();
//
//    window.draw(scoretext);
//}
//
//// game over state(6)
//
//void Gameover(RenderWindow& window)
//{
//    window.clear(Color::White);
//
//    const int gms = 3;
//    string gop[gms] = { "Restart","Back to Main Menu","Exit" };
//
//    Event event;
//
//    while (window.pollEvent(event))
//    {
//        if (event.type == Event::Closed)
//        {
//            window.close();
//        }
//        if (event.type == Event::KeyPressed)
//        {
//            if (event.key.code == Keyboard::Escape)
//            {
//                gamestate = 0;
//            }
//            else if (event.key.code == Keyboard::Escape)
//            {
//                gameoption--;
//                if (gameoption < 0)
//                {
//                    gameoption = gms - 1;
//                }
//            }
//            else if (event.key.code == Keyboard::W)
//            {
//                gameoption--;
//                if (gameoption < 0)
//                    gameoption = gms - 1;
//            }
//            else if (event.key.code == Keyboard::S)
//            {
//                gameoption++;
//                if (gameoption >= gms)
//                {
//                    gameoption = 0;
//                }
//            }
//            else if (event.key.code == Keyboard::Enter)
//            {
//                if (gameoption == 0)
//                {
//                    reset(window);
//                    gamestate = flag;
//                }
//                else if (gameoption == 1)
//                {
//                    gamestate = 0;
//                }
//                else if (gameoption == 2)
//                {
//                    window.close();
//                    gameoption = 0;
//                    mainmenuoptions = 0;
//                    modemenuoptions = 0;
//                    colormenuoptions = 0;
//                }
//
//            }
//
//
//        }
//    }
//
//    int gpc = -80;
//    Text gm[gms];
//    for (int i = 0; i < gms; i++)
//    {
//        gm[i].setFont(font);
//        gm[i].setString(gop[i]);
//        gm[i].setCharacterSize(50);
//        gm[i].setLetterSpacing(1.7f);
//        setTextInMiddle(gm[i], window);
//        gm[i].setPosition(Vector2f(gm[i].getPosition().x, gm[i].getPosition().y + gpc));
//        gpc += 80;
//    }
//
//    for (int i = 0; i < gms; i++)
//    {
//        if (i == gameoption)
//        {
//            gm[i].setFillColor(Color(202, 30, 30));
//        }
//        else
//        {
//            gm[i].setFillColor(Color::Black);
//        }
//    }
//
//    //Update
//    //deadtext(window);
//
//    //Draw
//    for (int i = 0; i < gms; i++)
//    {
//        window.draw(gm[i]);
//    }
//}
////main fuction
//
//int main()
//{
//    //for real time
//    srand(time(NULL));
//
//    // to laod text font
//    if (!font.loadFromFile("font/arial.ttf"))
//    {
//        cout << "Error could not load the font! " << endl;
//    }
//
//    // to load game title font
//    if (!heading.loadFromFile("font/science.ttf"))
//    {
//        cout << "Error could not load the font! " << endl;
//    }
//
//    // making window
//
//    RenderWindow window(VideoMode(width, height), "SFML SNAKE GAME", Style::Fullscreen);
//    window.setFramerateLimit(40);
//    /*window.setMouseCursorVisible(false);*/
//
//    respawnObstacles();
//
//    foodspawn(window);
//    food.setFillColor(Color::Red);
//    food.setPosition(Vector2f(foodX * gridsize, foodY * gridsize));
//    bonus.setPosition(Vector2f(bonusX * gridsize, bonusY * gridsize));
//    bonus.setFillColor(Color(255, 0, 255));
//    /*bonusspawn(window);*/
//
//    while (window.isOpen())
//    {
//        //game state changes according to the selected option on window
//
//        if (gamestate == 0)
//        {
//            mainmenu(window);
//        }
//        else if (gamestate == 1)
//        {
//            modemenu(window);
//        }
//        else if (gamestate == 2)
//        {
//            colormenu(window);
//        }
//        else if (gamestate == 3)
//        {
//            endlessmode(window);
//        }
//        else if (gamestate == 4)
//        {
//            levelmode(window);
//        }
//        else if (gamestate == 5)
//        {
//            ceasegame(window);
//        }
//        else if (gamestate == 6)
//        {
//            Gameover(window);
//        }
//        else if (gamestate == 7)
//        {
//            createobstacles(window);
//        }
//        else if (gamestate == 8)
//        {
//            /*customspeed(window);*/
//        }
//        else if (gamestate == 9)
//        {
//            custommode(window);
//        }
//        else if (gamestate == 10)
//        {
//            /*loadhighscore(window);*/
//        }
//        else if (gamestate == 11)
//        {
//            menu2load(window);
//        }
//        else if (gamestate == 12)
//        {
//            boxmode(window);
//        }
//        else if (gamestate == 14)
//        {
//            instructions(window);
//        }
//
//        window.display();
//    }
//
//
//
//    return 0;
//}
