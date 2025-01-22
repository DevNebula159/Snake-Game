//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Audio.hpp>
//#include <cstdlib>
//#include <vector>
//#include <fstream>
//#include <Windows.h>
//#include <iostream>
//using namespace sf;
//using namespace std;
//
//// Window and Grid sizing etc.
//int dir;
//int width = 1920;
//int height = 1080;
//int gridSize = 30;
//
//int cellX = width / gridSize;
//int cellY = height / gridSize;
//
//// BackGround Image
//Texture bgTexture;
//Sprite bgSprite;
//Texture bg1Texture;
//Sprite bg1Sprite;
//Image sI;
//
//// For Sounds
//SoundBuffer scrollBuffer;
//Sound scrollSound;
//
//// Game States
//int gameState = 0;
//int check;
//
//// Font
//Font font;
//Font heading;
//
//// For FUN
//RectangleShape fade(Vector2f(cellX, cellY));
//
//
//// Snake
//RectangleShape snakeHead;
//int snakeX[100] = { cellX / 2 };
//int snakeY[100] = { cellY / 2 };
//int snakeLength = 1;
//
//// For Color Selection of Snake
//RectangleShape tempSnake(Vector2f(gridSize - 1, gridSize - 1));
//int tempSnakeLength = 8;
//int tempSnakeX = cellX / 2 - 4;
//int tempSnakeY = cellY / 2;
//vector<Vector2i> tempSnake1;
//
//// Snake Color
//int red1, green1, blue1;
//
//// Food
//RectangleShape food(Vector2f(gridSize, gridSize));
//int foodX;
//int foodY;
//
//// Score
//int score = 0;
//Text scoreText;
//
//// Obstacles
//vector <vector<Vector2i>> obstacles;
//int numObstacles = 2;
//int obstacleLength = 8;
//RectangleShape block(Vector2f(gridSize - 1, gridSize - 1));
//int startX;
//int startY;
//
//// Customize Obstacles
//struct ObstacleNew 
//{
//    int x, y;
//};
//
//vector<ObstacleNew> obstaclesNew;
//
//// Speed
//int speed = 80;
//
//// Custom Speed
//int custom_speed = 100;
//int red = 0, green = 255, blue = 0;
//RectangleShape spB(Vector2f(gridSize, gridSize));
//Text sp("Select Speed", font, 60);
//int speedX = cellX / 2 - 5;
//int speedY = cellY / 2;
//int numspBlocks = 10;
//int activeBlocks = 0;
//vector<Vector2i> spBlocks;
//
//// Game Over
//bool gameOver = false;
//
//// Options for Menu
//int menu1option = 0;
//int menu2option = 0;
//int menu3option = 0;
//int pauseOption = 0;
//int gOption = 0;
//
//// Functions to call before the position of their body
//void reset(RenderWindow& window);
//void reset1();
//void createObstacles(RenderWindow& window);
//void respawnObstacles();
//
//// Function to set text in Middle of window
//void setTextInMiddle(Text& text, RenderWindow& window)
//{
//    Vector2u windowSize = window.getSize();
//    FloatRect textBounds = text.getLocalBounds();
//    text.setPosition( (windowSize.x - textBounds.width) / 2, (windowSize.y - textBounds.height) / 2);
//}
//
//// To save High Score
//void saveHighScore(int highScore)
//{
//    if (check == 3)
//    {
//        ofstream saver("highScores/endless_scores.txt", ios::app);
//        vector<int> endlessHighS;
//        //int highScore = score;
//        
//        if (saver.is_open())
//        {
//            saver << highScore << endl;
//            endlessHighS.push_back(highScore);
//            saver.close();
//        }
//        else
//            cout << "Error: Could not Save High Score of Endless Mode!" << endl;
//    }
//    if (check == 4)
//    {
//        ofstream saver1("highScores/level_scores.txt", ios::app);
//        vector<int> levelHighS;
//        //int highScore = score;
//
//        if (saver1.is_open())
//        {
//            saver1 << highScore << endl;
//            levelHighS.push_back(highScore);
//            saver1.close();
//        }
//        else
//            cout << "Error: Could not Save High Score of Level Mode!" << endl;
//    }
//}
//
//// To Load High Scores
//void loadHighScore(RenderWindow& window)
//{
//    window.clear();
//
//    window.setMouseCursorVisible(false);
//    window.draw(bgSprite);
//	Event load;
//	while (window.pollEvent(load)) 
//    {
//		if (load.type == Event::Closed)
//			window.close();
//        if (load.type == Event::KeyPressed && load.key.code == Keyboard::Escape)
//            gameState = 0;
//	}
//
//    Text Return("Press Escape to Return to Main Menu", font, 40);
//    Return.setFillColor(Color(160, 160, 160));
//    Return.setLetterSpacing(1.7f);
//    setTextInMiddle(Return, window);
//    Return.setPosition(Vector2f(Return.getPosition().x, Return.getPosition().y + 350));
//    window.draw(Return);
//
//    ifstream loader("highScores/endless_scores.txt"), loader1("highScores/level_scores.txt");
//    if (!loader || !loader1) 
//    {
//        Text error("Error loading score files", font, 40);
//        error.setFillColor(Color::Red);
//        setTextInMiddle(error, window);
//        window.draw(error);
//        return;
//    }
//
//    // To Display high scores of Endless Mode
//    vector<int> endlessScores;
//    int endlessScore;
//    while (loader >> endlessScore)
//        endlessScores.push_back(endlessScore);
//
//    sort(endlessScores.begin(), endlessScores.end(), greater<int>());
//
//    string endlessText0 = "1. ";
//    string endlessText1 = "2. ";
//    string endlessText2 = "3. ";
//
//    if (endlessScores.size() > 0) endlessText0 += to_string(endlessScores[0]);
//    if (endlessScores.size() > 1) endlessText1 += to_string(endlessScores[1]);
//    if (endlessScores.size() > 2) endlessText2 += to_string(endlessScores[2]);
//
//    Text endlessDisplay("Endless Mode High Scores", font, 50);
//    endlessDisplay.setFillColor(Color::White);
//    setTextInMiddle(endlessDisplay, window);
//    endlessDisplay.setPosition(Vector2f(endlessDisplay.getPosition().x / 2.8, endlessDisplay.getPosition().y - 200));
//    window.draw(endlessDisplay);
//
//    Text endlessDisplay0(endlessText0, font, 40);
//    endlessDisplay0.setFillColor(Color(224, 224, 224));
//    setTextInMiddle(endlessDisplay0, window);
//    endlessDisplay0.setPosition(Vector2f(endlessDisplay0.getPosition().x / 2, endlessDisplay0.getPosition().y - 70));
//    window.draw(endlessDisplay0);
//
//    Text endlessDisplay1(endlessText1, font, 40);
//    endlessDisplay1.setFillColor(Color(224, 224, 224));
//    setTextInMiddle(endlessDisplay1, window);
//    endlessDisplay1.setPosition(Vector2f(endlessDisplay1.getPosition().x / 2, endlessDisplay1.getPosition().y));
//    window.draw(endlessDisplay1);
//
//    Text endlessDisplay2(endlessText2, font, 40);
//    endlessDisplay2.setFillColor(Color(224, 224, 224));
//    setTextInMiddle(endlessDisplay2, window);
//    endlessDisplay2.setPosition(Vector2f(endlessDisplay2.getPosition().x / 2, endlessDisplay2.getPosition().y + 80));
//    window.draw(endlessDisplay2);
//
//
//    // To display High Scores of Level Mode
//    vector<int> levelScores;
//    int levelScore;
//    while (loader1 >> levelScore)
//        levelScores.push_back(levelScore);
//
//    sort(levelScores.begin(), levelScores.end(), greater<int>());
//
//    string levelText0 = "1. ";
//    string levelText1 = "2. ";
//    string levelText2 = "3. ";
//
//    if (levelScores.size() > 0) levelText0 += to_string(levelScores[0]);
//    if (levelScores.size() > 1) levelText1 += to_string(levelScores[1]);
//    if (levelScores.size() > 2) levelText2 += to_string(levelScores[2]);
//
//    Text levelDisplay("Level Mode High Scores", font, 50);
//    levelDisplay.setFillColor(Color::White);
//    setTextInMiddle(levelDisplay, window);
//    levelDisplay.setPosition(Vector2f(levelDisplay.getPosition().x * 1.65, levelDisplay.getPosition().y - 200));
//    window.draw(levelDisplay);
//
//    Text levelDisplay0(levelText0, font, 40);
//    levelDisplay0.setFillColor(Color(224, 224, 224));
//    setTextInMiddle(levelDisplay0, window);
//    levelDisplay0.setPosition(Vector2f(levelDisplay0.getPosition().x  * 1.5, levelDisplay0.getPosition().y- 80));
//    window.draw(levelDisplay0);
//
//    Text levelDisplay1(levelText1, font, 40);
//    levelDisplay1.setFillColor(Color(224, 224, 224));
//    setTextInMiddle(levelDisplay1, window);
//    levelDisplay1.setPosition(Vector2f(levelDisplay1.getPosition().x  * 1.5, levelDisplay1.getPosition().y));
//    window.draw(levelDisplay1);
//
//    Text levelDisplay2(levelText2, font, 40);
//    levelDisplay2.setFillColor(Color(224, 224, 224));
//    setTextInMiddle(levelDisplay2, window);
//    levelDisplay2.setPosition(Vector2f(levelDisplay2.getPosition().x  * 1.5, levelDisplay2.getPosition().y + 80));
//    window.draw(levelDisplay2);
//}
//
//// For Movement of Snake
//void snakeMovement()
//{
//    for (int i = snakeLength; i > 0; i--)
//    {
//        snakeX[i] = snakeX[i - 1];
//        snakeY[i] = snakeY[i - 1];
//    }
//    if (dir == 1)
//        snakeY[0]--;  //UP
//    else if (dir == 2)
//        snakeY[0]++;  //Down
//    else if (dir == 3)
//        snakeX[0]++;  //Right
//    else if (dir == 4)
//        snakeX[0]--;  //LEFT
//    if (gameState != 9)
//        Sleep(speed);
//    else
//        Sleep(custom_speed);
//}
//
//// Function to emerge snake from the other side in case of collision with one side of window
//void wallCollision()
//{
//    if (snakeX[0] >= cellX)
//        snakeX[0] = 0;
//    if (snakeX[0] < 0)
//        snakeX[0] = cellX - 1;
//    if (snakeY[0] >= cellY)
//        snakeY[0] = 0;
//    if (snakeY[0] < 0)
//        snakeY[0] = cellY - 1;
//}
//
//// To display Score during gameplay
//void Score()
//{
//    scoreText.setString("Score: " + to_string(score));
//    scoreText.setFont(font);
//    scoreText.setCharacterSize(24);
//    scoreText.setFillColor(Color::White);
//    scoreText.setPosition(10.f, 10.f);
//}
//
//// To check for food or obstacles on snake body
//bool isNotOnSnake(int x, int y) 
//{
//    for (int i = 0; i < snakeLength; i++) 
//    {
//        if (snakeX[i] == x && snakeY[i] == y)
//            return false;
//    }
//    return true;
//}
//
//// Obstacles which can be regenerated and spawned again
//void respawnObstacles() 
//{
//    vector<Vector2i> obstacle;
//
//    for (int i = 0; i < numObstacles; i++) 
//    {
//        bool valid = false;
//        while (!valid) 
//        {
//            valid = true; 
//            obstacle.clear();
//
//            startX = rand() % cellX;
//            startY = rand() % cellY;
//
//            for (int j = 0; j < obstacleLength; j++) 
//            {
//                int newX = startX;
//                int newY = startY;
//
//                if (i % 2 == 0)
//                    newX = startX + j; 
//                else
//                    newY = startY + j;
//
//                if (!isNotOnSnake(newX, newY))
//                    valid = false;
//                else
//                    obstacle.push_back(Vector2i(newX, newY));
//            }
//        }
//        obstacles.push_back(obstacle);
//    }
//}
//
//// To draw Respawned Obstacles( which are used to increase level )
//void drawObstacles1(RenderWindow& window)
//{
//    block.setFillColor(Color(204, 0, 0));
//
//    for (auto& obstacle : obstacles)
//    {
//        for (auto& part : obstacle)
//        {
//            block.setPosition(part.x * gridSize, part.y * gridSize);
//            window.draw(block);
//        }
//    }
//}
//
//// To go to gameOver State in case of collision with obstacle
//void obstacleCollision(RenderWindow& window)
//{
//    if (gameState == 4)
//    {
//        for (auto& obstacle : obstacles)
//        {
//            for (auto& part1 : obstacle)
//            {
//                if (snakeX[0] == part1.x && snakeY[0] == part1.y)
//                {
//                    check = gameState;
//                    saveHighScore(score);
//                    
//                    gameState = 6;
//                }
//            }
//        }
//    }
//    if (gameState == 9)
//    {
//        for (auto& obstacle2 : obstaclesNew)
//        { 
//            if (snakeX[0] == obstacle2.x && snakeY[0] == obstacle2.y)
//            {
//                check = gameState;
//                saveHighScore(score);
//                
//                gameState = 6;
//            }
//        }
//    }
//}
//
//// To Check for position of food for obstacles
//bool isPositionAvailable(int x, int y)
//{
//    bool isAvailable = true;
//    if (gameState == 4)
//    {
//        if (score == 0)
//        {
//            for (auto& obstacle : obstacles)
//            {
//                for (auto& part : obstacle)
//                {
//                    if (x == part.x && y == part.y && isAvailable == true)
//                        isAvailable = false;
//                }
//            }
//        }
//    }
//
//    if (gameState == 9)
//    {
//        for (auto& obstacle2 : obstaclesNew)
//        {
//            if (x == obstacle2.x && y == obstacle2.y && isAvailable == true)
//                isAvailable = false;
//        }
//    }
//    return isAvailable;
//}
//
//// To Spawn food at random Position avoiding Obstacles and Snake's body
//void foodSpawn(RenderWindow& window) 
//{
//    bool validPosition = false;
//
//    while (!validPosition) 
//    {
//        foodX = rand() % cellX;
//        foodY = rand() % cellY;
//
//        bool snakeCheck = isNotOnSnake(foodX, foodY);
//        bool obstacleCheck = isPositionAvailable(foodX, foodY);
//
//        if (snakeCheck && obstacleCheck) 
//            validPosition = true;
//    }
//
//    food.setPosition(Vector2f(foodX * gridSize, foodY * gridSize));
//}
//
//
//// Increase of snakeLength and score etc. when snake eats food
//void foodCollision(RenderWindow& window)
//{
//    if (snakeX[0] == foodX && snakeY[0] == foodY)
//    {
//        foodSpawn(window);
//        score += 10;
//        snakeLength++;
//        if (speed > 20)
//            speed --;
//    }
//}
//
//// To Change gameState to gameOver when snake collides with itself
//void snakeCollision(RenderWindow& window)
//{
//    if (snakeLength > 1)
//    {
//        for (int i = 1; i <= snakeLength; i++)
//        {
//            if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i] )
//            {
//                check = gameState;
//                saveHighScore(score);
//                
//                gameState = 6;
//            }
//        }
//    }
//    if (Keyboard::isKeyPressed(Keyboard::G))
//    {
//        check = gameState;
//        saveHighScore(score);
//        
//        gameState = 6;
//    }   
//}
//
//// 1st Menu which asks user to go to Play Saved Game, New Game or to Exit the Program gameState (0)
//void menu1(RenderWindow& window)
//{
//    window.setMouseCursorVisible(false);
//    Text name("Snake Game", heading, 150);
//    name.setLetterSpacing(3);
//    name.setFillColor(Color(0, 153, 76));
//    setTextInMiddle(name, window);
//    name.setPosition(Vector2f(name.getPosition().x, name.getPosition().y - 350));
//
//    vector<string> menu1options = { "New Game", "Play Saved Game", "High Scores", "Exit" };
//    Event event;
//
//    while (window.pollEvent(event))
//    {
//        if (event.type == Event::Closed)
//            window.close();
//        if (event.type == Event::KeyPressed)
//        {
//            if (event.key.code == Keyboard::Escape)
//                window.close();
//
//            else if (event.key.code == Keyboard::W)
//            {
//                scrollSound.setPitch(2);
//                scrollSound.play();
//                menu1option--;
//                if (menu1option < 0)
//                    menu1option = menu1options.size() - 1;
//            }
//
//            else if (event.key.code == Keyboard::S)
//            {
//                scrollSound.setPitch(2);
//                scrollSound.play();
//                menu1option++;
//                if (menu1option >= menu1options.size())
//                    menu1option = 0;
//            }
//
//            else if (event.key.code == Keyboard::Enter)
//            {
//                scrollSound.setPitch(1.9f);
//                scrollSound.play();
//                if (menu1option == 0)
//                {
//                    reset(window);
//                    reset1();
//                    gameState = 1;
//                }
//                else if (menu1option == 1)
//                {
//                    gameState = 0;
//                }
//                else if (menu1option == 2)
//                    gameState = 10;
//                else if (menu1option == 3)
//                    window.close();
//            }
//        }
//    }
//
//    int m1pChecker = -120;
//    vector<Text> menu1Texts;
//    for (int i = 0; i < menu1options.size(); i++)
//    {
//        Text menu1Text;
//        menu1Text.setFont(font);
//        menu1Text.setString(menu1options[i]);
//        menu1Text.setCharacterSize(50);
//        menu1Text.setLetterSpacing(1.7f);
//        setTextInMiddle(menu1Text, window);
//        menu1Text.setPosition(Vector2f(menu1Text.getPosition().x, menu1Text.getPosition().y + m1pChecker));
//        menu1Texts.push_back(menu1Text);
//        m1pChecker += 80;
//    }
//
//    for (int i = 0; i < menu1Texts.size(); i++)
//    {
//        if (i == menu1option)
//            menu1Texts[i].setFillColor(Color(0, 102, 102));
//        else
//            menu1Texts[i].setFillColor(Color::White);
//    }
//
//    //Update
//    window.clear();
//
//    // Draw
//    window.draw(bgSprite);
//    window.draw(name);
//    for (auto& text : menu1Texts)
//        window.draw(text);
//}
//
//// 2nd Menu which asks for Endless Mode and Level Mode gameState (1)
//void menu2(RenderWindow& window)
//{
//    window.setMouseCursorVisible(false);
//    Text selectMode("Select Mode", font, 100);
//    selectMode.setFillColor(Color(0, 102, 102));
//    selectMode.setLetterSpacing(1.7f);
//    setTextInMiddle(selectMode, window);
//    selectMode.setPosition(Vector2f(selectMode.getPosition().x, selectMode.getPosition().y - 300));
//
//    vector<string> menu2options = { "Endless Mode", "Level Mode", "Custom Mode", "Back" };
//    Event event;
//
//    while (window.pollEvent(event))
//    {
//        if (event.type == Event::Closed)
//            window.close();
//        if (event.type == Event::KeyPressed)
//        {
//            if (event.key.code == Keyboard::Escape)
//                gameState = 0;
//
//            else if (event.key.code == Keyboard::W)
//            {
//                scrollSound.setPitch(2);
//                scrollSound.play();
//                menu2option--;
//                if (menu2option < 0)
//                    menu2option = menu2options.size() - 1;
//            }
//
//            else if (event.key.code == Keyboard::S)
//            {
//                scrollSound.setPitch(2);
//                scrollSound.play();
//                menu2option++;
//                if (menu2option >= menu2options.size())
//                    menu2option = 0;
//            }
//
//            else if (event.key.code == Keyboard::Enter)
//            {
//                scrollSound.setPitch(1.9f);
//                scrollSound.play();
//                if (menu2option == 0)
//                {
//                    check = 3;
//                    gameState = 2;
//                }
//                else if (menu2option == 1)
//                {
//                    check = 4;
//                    gameState = 2;
//                }
//                else if (menu2option == 2)
//                {
//                    check = 9;
//                    gameState = 7;
//                }
//                else if (menu2option == 3)
//                    gameState = 0;
//            }
//        }
//    }
//    int m2pChecker = -120;
//    vector<Text> menu2Texts;
//    for (int i = 0; i < menu2options.size(); i++)
//    {
//        Text menu2Text;
//        menu2Text.setFont(font);
//        menu2Text.setString(menu2options[i]);
//        menu2Text.setCharacterSize(50);
//        menu2Text.setLetterSpacing(1.7f);
//        setTextInMiddle(menu2Text, window);
//        menu2Text.setPosition(Vector2f(menu2Text.getPosition().x, menu2Text.getPosition().y + m2pChecker));
//        menu2Texts.push_back(menu2Text);
//        m2pChecker += 80;
//    }
//
//    for (int i = 0; i < menu2Texts.size(); i++)
//    {
//        if (i == menu2option)
//            menu2Texts[i].setFillColor(Color(0, 102, 102));
//        else
//            menu2Texts[i].setFillColor(Color::White);
//    }
//
//    //Update
//    window.clear();
//
//    // Draw
//    window.draw(bgSprite);
//    window.draw(selectMode);
//    for (auto& text : menu2Texts)
//        window.draw(text);
//}
//
//// 3rd Menu which asks for color of snake gameState (2)
//void menu3(RenderWindow& window)
//{
//    window.setMouseCursorVisible(false);
//    for (int i = 0; i < tempSnakeLength; i++)
//        tempSnake1.push_back(Vector2i(tempSnakeX + i, tempSnakeY));
//
//    Text selectColor("Select Snake Color", font, 90);
//    selectColor.setFillColor(Color(0, 102, 102));
//    selectColor.setLetterSpacing(1.7f);
//    setTextInMiddle(selectColor, window);
//    selectColor.setPosition(Vector2f(selectColor.getPosition().x, selectColor.getPosition().y - 310));
//
//    Text Return1("Press Escape to Select Mode", font, 50);
//    Return1.setFillColor(Color(224, 224, 224));
//    Return1.setLetterSpacing(1.7f);
//    setTextInMiddle(Return1, window);
//    Return1.setPosition(Vector2f(Return1.getPosition().x, Return1.getPosition().y + 350));
//
//    vector<string> menu3options = { "Green", "Red", "Blue", "Purple", "White", "Pink", "Gray"};
//    Event event;
//
//    while (window.pollEvent(event))
//    {
//        if (event.type == Event::Closed)
//            window.close();
//        if (event.type == Event::KeyPressed)
//        {
//            if (event.key.code == Keyboard::Escape)
//                gameState = 1;
//
//            else if (event.key.code == Keyboard::W)
//            {
//                scrollSound.setPitch(2);
//                scrollSound.play();
//                menu3option--;
//                if (menu3option < 0)
//                    menu3option = menu3options.size() - 1;
//            }
//
//            else if (event.key.code == Keyboard::S)
//            {
//                scrollSound.setPitch(2);
//                scrollSound.play();
//                menu3option++;
//                if (menu3option >= menu3options.size())
//                    menu3option = 0;
//            }
//
//            else if (event.key.code == Keyboard::Enter)
//            {
//                scrollSound.setPitch(1.9f);
//                scrollSound.play();
//                gameState = check;
//            }
//        }
//    }
//
//    int m3pChecker = -180;
//    vector<Text> menu3Texts;
//    for (int i = 0; i < menu3options.size(); i++)
//    {
//        Text menu3Text;
//        menu3Text.setFont(font);
//        menu3Text.setString(menu3options[i]);
//        menu3Text.setCharacterSize(40);
//        menu3Text.setLetterSpacing(1.7f);
//        setTextInMiddle(menu3Text, window);
//        menu3Text.setPosition(Vector2f(menu3Text.getPosition().x / 2, menu3Text.getPosition().y + m3pChecker));
//        menu3Texts.push_back(menu3Text);
//        m3pChecker += 60;
//    }
//
//    for (int i = 0; i < menu3Texts.size(); i++)
//    {
//        if (i == menu3option)
//        {
//            if (i == 0)
//            {
//                red1 = 0; green1 = 204; blue1 = 0;
//                menu3Texts[i].setFillColor(Color(red1, green1, blue1));
//                tempSnake.setFillColor(Color(red1, green1, blue1));               
//            }
//            if (i == 1)
//            {
//                red1 = 230; green1 = 0; blue1 = 0;
//                menu3Texts[i].setFillColor(Color(red1, green1, blue1));
//                tempSnake.setFillColor(Color(red1, green1, blue1));
//            }
//            if (i == 2)
//            {
//                red1 = 0; green1 = 0; blue1 = 153;
//                menu3Texts[i].setFillColor(Color(red1, green1, blue1));
//                tempSnake.setFillColor(Color(red1, green1, blue1));
//            }
//            if (i == 3)
//            {
//                red1 = 204; green1 = 0; blue1 = 204;
//                menu3Texts[i].setFillColor(Color(red1, green1, blue1));
//                tempSnake.setFillColor(Color(red1, green1, blue1));
//            }
//            if (i == 4)
//            {
//                red1 = 255; green1 = 255; blue1 = 255;
//                menu3Texts[i].setFillColor(Color(red1, green1, blue1));
//                tempSnake.setFillColor(Color(red1, green1, blue1));
//            }
//            if (i == 5)
//            {
//                red1 = 255; green1 = 102; blue1 = 178;
//                menu3Texts[i].setFillColor(Color(red1, green1, blue1));
//                tempSnake.setFillColor(Color(red1, green1, blue1));
//            }
//            if (i == 6)
//            {
//                red1 = 192; green1 = 192; blue1 = 192;
//                menu3Texts[i].setFillColor(Color(red1, green1, blue1));
//                tempSnake.setFillColor(Color(red1, green1, blue1));
//            }
//        }
//        else
//            menu3Texts[i].setFillColor(Color(150, 150, 150));
//    }
//
//    //Update
//
//    window.clear();
//    
//    // Draw
//    window.draw(bgSprite);
//    window.draw(Return1);
//    window.draw(selectColor);
//    for (auto& text : menu3Texts)
//        window.draw(text);
//    for (int i = 0; i < tempSnakeLength; i++)
//    {
//        tempSnake.setPosition(Vector2f(tempSnake1[i].x * gridSize, tempSnake1[i].y * gridSize));
//        window.draw(tempSnake);
//    }
//}
//
//// Endless Mode State (3)
//void mainGame(RenderWindow& window)
//{
//    window.setMouseCursorVisible(false);
//    //Snake Head
//    snakeHead.setPosition(Vector2f(snakeX[0] * gridSize, snakeY[0] * gridSize));
//    snakeHead.setFillColor(Color(red1, green1, blue1));
//    snakeHead.setSize(Vector2f(gridSize -1, gridSize -1));
//
//    //Food
//    food.setFillColor(Color::Blue);
//
//    Event event;
//    while (window.pollEvent(event))
//    {
//        if (event.type == event.Closed)
//            window.close();
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::W)
//            dir = 1;
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::S)
//            dir = 2;
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::D)
//            dir = 3;
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::A)
//            dir = 4;
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::Escape)
//        {
//            
//            gameState = 5;
//        }
//    }
//
//    // Update
//    snakeMovement();
//    wallCollision();
//    Score();
//    foodCollision(window);
//    snakeCollision(window);
//
//    window.clear();
//
//    // Draw
//
//    for (int i = 0; i < snakeLength; i++)
//    {
//        snakeHead.setPosition(Vector2f(snakeX[i] * gridSize, snakeY[i] * gridSize));
//        window.draw(snakeHead);
//    }
//
//    window.draw(food);
//    window.draw(scoreText);
//}
//
//// Level Mode State (4)
//void levelGame(RenderWindow& window)
//{
//    window.setMouseCursorVisible(false);
//    //Snake Head
//    snakeHead.setPosition(Vector2f(snakeX[0] * gridSize, snakeY[0] * gridSize));
//    snakeHead.setFillColor(Color(red1, green1, blue1));
//    snakeHead.setSize(Vector2f(gridSize - 1, gridSize - 1));
//
//    //Food
//    food.setFillColor(Color::Blue);
//
//    Event event;
//    while (window.pollEvent(event))
//    {
//        if (event.type == event.Closed)
//            window.close();
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::Escape)
//        {
//            
//            gameState = 5;
//        }
//        /*if (event.type == event.KeyPressed && event.key.code == Keyboard::F)
//            foodSpawn(window);
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::O)
//            respawnObstacles();*/
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::W)
//            dir = 1;
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::S)
//            dir = 2;
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::D)
//            dir = 3;
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::A)
//            dir = 4;
//    }
//
//    // Update
//    snakeMovement();
//    wallCollision();
//    Score();
//    snakeCollision(window);
//    obstacleCollision(window);
//
//    // Draw
//
//    static int lastScore = 1;
//    // Respawn Obstacles for New Level
//    if (score % 100 == 0 && score != lastScore) 
//    {
//        respawnObstacles();
//        lastScore = score;
//        if (numObstacles <= 4)
//            numObstacles++;
//        if (numObstacles > 4)
//            numObstacles = 2;
//        speed -= 5;
//        obstacleLength++;
//    }
//    foodCollision(window);
//
//    window.clear();
//    drawObstacles1(window);
//
//    // Draw Snake
//    for (int i = 0; i < snakeLength; i++)
//    {
//        snakeHead.setPosition(Vector2f(snakeX[i] * gridSize, snakeY[i] * gridSize));
//        window.draw(snakeHead);
//    }
//
//    window.draw(food);
//    window.draw(scoreText);
//}
//
//// To get grid Position of Mouse
//Vector2i getGridPosition(Vector2i mousePosition) 
//{
//    return Vector2i(mousePosition.x / gridSize, mousePosition.y / gridSize);
//}
//
//// To draw new obstacles
//void drawObstacles2(RenderWindow& window)
//{
//    for (auto& obstacle2 : obstaclesNew)
//    {
//        block.setPosition(obstacle2.x * gridSize, obstacle2.y * gridSize);
//        if (gameState == 7)
//            block.setFillColor(Color(128, 128, 128));
//        else if (gameState == 9)
//            block.setFillColor(Color(204, 0, 0));
//        window.draw(block);
//    }
//}
//
//// To control Visibility etc. of Mouse while Creating Obstacles
//void mouseCursor(RenderWindow& window)
//{
//    window.setMouseCursorGrabbed(true);
//    window.setMouseCursorVisible(true);
//}
//
//// To customize obstacles; gameState(7)
//void createObstacles(RenderWindow& window)
//{
//    Event creation;
//
//    while (window.pollEvent(creation))
//    {
//        if (creation.type == Event::Closed)
//            window.close();
//        if (creation.type == Event::KeyPressed && creation.key.code == Keyboard::Enter)
//            gameState = 8;
//    }
//
//    if (Mouse::isButtonPressed(Mouse::Left))
//    {
//        Vector2i cursorP = Mouse::getPosition(window);
//        Vector2i gridP = getGridPosition(cursorP);
//        obstaclesNew.push_back({ gridP.x, gridP.y });
//    }
//    
//    Text askForCreation("Create Obstacles", font, 30);
//    askForCreation.setFillColor(Color::White);
//    askForCreation.setPosition(Vector2f(gridSize, gridSize));
//
//    // Update
//    mouseCursor(window);
//    window.clear();
//
//    // Draw
//    drawObstacles2(window);
//    window.draw(askForCreation);
//}
//
//// For Coloring of Speed Navigation Bar
//void speedNavigation(RenderWindow& window)
//{
//    spB.setOutlineColor(Color(160, 160, 160));
//    spB.setOutlineThickness(2);
//
//    for (int i = 0; i < numspBlocks; i++)
//    {
//        if (i <= activeBlocks)
//            spB.setFillColor(Color(red, green, blue));
//        else
//            spB.setFillColor(Color(160, 160, 160));
//
//        spB.setPosition(Vector2f((speedX + i) * gridSize, speedY * gridSize));
//        window.draw(spB);
//    }
//}
//
//// For Customization of Snake Speed gameState (8)
//void customSpeed(RenderWindow& window)
//{
//    window.clear();
//    window.draw(bgSprite);
//    window.setMouseCursorVisible(false);
//    Event cSpeed;
//
//    while (window.pollEvent(cSpeed))
//    {
//        if (cSpeed.type == Event::Closed)
//            window.close();
//        if (cSpeed.type == Event::KeyPressed && cSpeed.key.code == Keyboard::Enter)
//            gameState = 2;
//    }
//
//    sp.setCharacterSize(70);
//    sp.setFillColor(Color(0, 102, 102));
//    setTextInMiddle(sp, window);
//    sp.setPosition(sp.getPosition().x, sp.getPosition().y - 150);
//
//    speedNavigation(window);
//
//    if (Keyboard::isKeyPressed(Keyboard::D) && activeBlocks < numspBlocks - 1 && red <= 227)
//    {
//        red += 28;
//        green -= 28;
//        blue = 0;
//        activeBlocks++;
//        if (custom_speed >= 20)
//            custom_speed -= 8;
//        Sleep(150);
//    }
//
//    if (Keyboard::isKeyPressed(Keyboard::A) && activeBlocks > 0 && red >= 28)
//    {
//        red -= 28;
//        green += 28;
//        blue = 0;
//        activeBlocks--;
//        if (custom_speed <= 100)
//            custom_speed += 8;
//        Sleep(150);
//    }
//
//    window.draw(sp);
//}
//
//
//// gameState Custom (9)
//void customGame(RenderWindow& window) 
//{
//    window.setMouseCursorVisible(false);
//    snakeHead.setPosition(Vector2f(snakeX[0] * gridSize, snakeY[0] * gridSize));
//    snakeHead.setFillColor(Color(red1, green1, blue1));
//    snakeHead.setSize(Vector2f(gridSize -1, gridSize -1));
//
//    //Food
//    food.setFillColor(Color::Blue);
//
//    Event event;
//    while (window.pollEvent(event))
//    {
//        if (event.type == event.Closed)
//            window.close();
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::W)
//            dir = 1;
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::S)
//            dir = 2;
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::D)
//            dir = 3;
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::A)
//            dir = 4;
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::Escape)
//        {
//            
//            gameState = 5;
//        }
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::F)
//            foodSpawn(window);
//    }
//
//    // Update
//    snakeMovement();
//    wallCollision();
//    Score();
//    snakeCollision(window);
//    obstacleCollision(window);
//    foodCollision(window);
//    window.clear();
//
//    // Draw
//    drawObstacles2(window);
//
//    for (int i = 0; i < snakeLength; i++)
//    {
//        snakeHead.setPosition(Vector2f(snakeX[i] * gridSize, snakeY[i] * gridSize));
//        window.draw(snakeHead);
//    }
//
//    window.draw(food);
//    window.draw(scoreText);   
//}
//
//// Text which is shown in gameOver State
//void deadText(RenderWindow& window)
//{
//    // GameOver Text
//    Text dead;
//    dead.setFont(font);
//    dead.setCharacterSize(100);
//    dead.setFillColor(Color(202, 30, 30));
//    dead.setString("Game Over!");
//    dead.setLetterSpacing(1.7f);
//    setTextInMiddle(dead, window);
//    dead.setPosition(Vector2f(dead.getPosition().x, dead.getPosition().y - 300));
//    window.draw(dead);
//
//    // Total Score
//    scoreText.setString("Score: " + to_string(score));
//    scoreText.setFont(font);
//    scoreText.setCharacterSize(50);
//    scoreText.setLetterSpacing(1.7f);
//    scoreText.setFillColor(Color::White);
//    setTextInMiddle(scoreText, window);
//    scoreText.setPosition(Vector2f(scoreText.getPosition().x, scoreText.getPosition().y + 300));
//    window.draw(scoreText);
//}
//
//// To reset game
//void reset(RenderWindow& window)
//{
//    window.clear();
//    speed = 80;
//	dir = 0;	
//	for (int i = 0; i < snakeLength; i++)
//	{
//		snakeX[i] = 0;
//		snakeY[i] = 0;
//	}
//	snakeX[0] = cellX / 2;
//	snakeY[0] = cellY / 2;
//	snakeLength = 1;
//    score = 0;
//	foodSpawn(window);
//    if (check == 4)
//    {
//        numObstacles = 2;
//        obstacleLength = 8;
//        obstacles.clear();
//        respawnObstacles();
//    }
//}
//
//// To reset the items of Custom Mode
//void reset1()
//{
//    obstaclesNew.clear();
//    custom_speed = 100;
//    activeBlocks = 0;
//    red = 0; green = 255; blue = 0;
//}
//
//// Restarts the game on command of User
//void Restart(RenderWindow& window)
//{
//    if (Keyboard::isKeyPressed(Keyboard::Space))
//    {
//        reset(window);
//        gameState = check;
//    }
//}
//
//// PauseGame State (5)
//void pauseGame(RenderWindow& window)
//{
//	window.clear();
//
//    window.draw(bg1Sprite);
//    window.setMouseCursorVisible(false);
//	vector<string> pauseOptions = { "Resume", "Restart", "Return to Main Menu", "Exit"};
//
//	Event pause;
//
//	while (window.pollEvent(pause))
//	{
//		if (pause.type == Event::Closed)
//			window.close();
//		if (pause.type == Event::KeyPressed)
//		{
//			if (pause.key.code == Keyboard::W)
//			{
//                scrollSound.setPitch(2);
//                scrollSound.play();
//				pauseOption--;
//				if (pauseOption < 0)
//					pauseOption = pauseOptions.size() - 1;
//			}
//
//			else if (pause.key.code == Keyboard::S)
//			{
//                scrollSound.setPitch(2);
//                scrollSound.play();
//				pauseOption++;
//				if (pauseOption >= pauseOptions.size())
//					pauseOption = 0;
//			}
//
//			else if (pause.key.code == Keyboard::Enter)
//			{
//                scrollSound.setPitch(1.9f);
//                scrollSound.play();
//                if (pauseOption == 0)
//                    gameState = check;
//                else if (pauseOption == 1)
//                {
//                    reset(window);
//                    gameState = check;
//                }
//                else if (pauseOption == 2)
//                    gameState = 0;
//                else if (pauseOption == 3)
//                    window.close();
//                pauseOption = 0;
//			}
//			else if (pause.key.code == Keyboard::Escape)
//            {
//                gameState = check;
//                pauseOption = 0;
//            }
//		}
//	}
//
//    int ppChecker = -120;
//	vector<Text> menuTexts;
//	for (int i = 0; i < pauseOptions.size(); i++)
//	{
//		Text menuText;
//		menuText.setFont(font);
//		menuText.setString(pauseOptions[i]);
//		menuText.setCharacterSize(50);
//        menuText.setLetterSpacing(1.7f);
//		setTextInMiddle(menuText, window);
//		menuText.setPosition(Vector2f(menuText.getPosition().x, menuText.getPosition().y + ppChecker));
//		menuTexts.push_back(menuText);
//        ppChecker += 80;
//	}
//
//	for (int i = 0; i < menuTexts.size(); i++)
//	{
//		if (i == pauseOption)
//            menuTexts[i].setFillColor(Color(0, 153, 76));
//		else
//			menuTexts[i].setFillColor(Color::White);
//	}
//
//	for (auto& text : menuTexts)
//	    window.draw(text);
//	Score();
//
//    window.draw(scoreText);
//}
//
//// gameOver State (6)
//void Game_Over(RenderWindow& window)
//{
//    window.clear();
//
//    window.draw(bg1Sprite);
//    window.setMouseCursorVisible(false);
//
//    vector<string> gOptions = {"Return To Main Menu", "Restart", "Exit" };
//
//	Event Over;
//
//	while (window.pollEvent(Over))
//	{
//		if (Over.type == Event::Closed)
//			window.close();
//        if (Over.type == Event::KeyPressed)
//        {
//            if (Over.key.code == Keyboard::Escape)
//                window.close();
//
//            else if (Over.key.code == Keyboard::W)
//            {
//                scrollSound.setPitch(2);
//                scrollSound.play();
//                gOption--;
//                if (gOption < 0)
//                    gOption = gOptions.size() - 1;
//            }
//
//            else if (Over.key.code == Keyboard::S)
//            {
//                scrollSound.setPitch(2);
//                scrollSound.play();
//                gOption++;
//                if (gOption >= gOptions.size())
//                    gOption = 0;
//            }
//
//            else if (Over.key.code == Keyboard::Enter)
//            {
//                scrollSound.setPitch(1.9f);
//                scrollSound.play();
//                if (gOption == 0)
//                    gameState = 0;
//                else if (gOption == 1)
//                {
//                    reset(window);
//                    gameState = check;
//                }
//                else if (gOption == 2)
//                    window.close();
//                gOption = 0;
//                menu1option = 0;
//                menu2option = 0;
//                menu3option = 0;
//            }
//        }
//	}
//
//    int gopChecker = -80;
//    vector<Text> gMenuTexts;
//    for (int i = 0; i < gOptions.size(); i++)
//    {
//        Text gMenuText;
//        gMenuText.setFont(font);
//        gMenuText.setString(gOptions[i]);
//        gMenuText.setCharacterSize(50);
//        gMenuText.setLetterSpacing(1.7f);
//        setTextInMiddle(gMenuText, window);
//        gMenuText.setPosition(Vector2f(gMenuText.getPosition().x, gMenuText.getPosition().y + gopChecker));
//        gMenuTexts.push_back(gMenuText);
//        gopChecker += 80;
//    }
//
//    for (int i = 0; i < gMenuTexts.size(); i++)
//    {
//        if (i == gOption)
//            gMenuTexts[i].setFillColor(Color(202, 30, 30));
//        else
//            gMenuTexts[i].setFillColor(Color::White);
//    }
//       
//    // Update
//    deadText(window);
//
//    // Draw
//    for (auto& gText : gMenuTexts)
//        window.draw(gText);
//}
//
//int main()
//{
//    srand(time(NULL));
//
//    // Load Simple Font
//    if (!font.loadFromFile("Fonts/AovelSans.ttf"))
//        cout << "Error loading font!" << endl;
//
//    // Load Title Font
//    if (!heading.loadFromFile("Fonts/a-box-for.ttf"))
//        cout << "Error loading font!" << endl;
//
//    // Load Background Image
//    if (!bgTexture.loadFromFile("BG/bg2.png"))
//        cout << "Error: Failed to Load Background Image.";
//    bgSprite.setTexture(bgTexture);
//    
//    // Load Image
//    if (!bg1Texture.loadFromFile("BG/bg3.png"))
//        cout << "Error: Failed to Load Background Image.";
//    bg1Sprite.setTexture(bg1Texture);
//
//    // Load Icon
//    if (!sI.loadFromFile("BG/icon1.png"))
//        cout << "Error: Failed to load Icon File!";
//
//    // Load Scroll Sound
//    if (!scrollBuffer.loadFromFile("Sound/soundEffect.wav"))
//        cout << "Error: Failed to load Scroll Sound!";
//    scrollSound.setBuffer(scrollBuffer);
//    scrollSound.setVolume(15);
//    scrollSound.setPitch(2);
//
//    RenderWindow window(VideoMode(width, height), "Snake Game", Style::Fullscreen);
//    window.setFramerateLimit(60);
//    window.setMouseCursorVisible(false);
//
//    window.setIcon(sI.getSize().x, sI.getSize().y, sI.getPixelsPtr());
//    foodSpawn(window);
//    respawnObstacles();
//    
//    while (window.isOpen())
//    {
//        // Change of States
//        if (gameState == 0)
//            menu1(window);
//        else if (gameState == 1)
//            menu2(window);
//        else if (gameState == 2)
//            menu3(window);
//        else if (gameState == 3)
//            mainGame(window);
//        else if (gameState == 4)
//            levelGame(window);
//        else if (gameState == 5)
//            pauseGame(window);
//        else if (gameState == 6)
//            Game_Over(window);
//        else if (gameState == 7)
//            createObstacles(window);
//        else if (gameState == 8)
//            customSpeed(window);
//        else if (gameState == 9)
//            customGame(window);
//        else if (gameState == 10)
//            loadHighScore(window);
//        
//        window.display();
//    }
//    return 0;
//}
