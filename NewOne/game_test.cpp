//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Audio.hpp>
//#include <cstdlib>
//#include <string>
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
//Texture gBGTexture;
//Sprite gBGSprite;
//Image sI;
//
//// For Sounds
//SoundBuffer scrollBuffer;
//Sound scrollSound;
//Music music;
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
//
//// Snake
//RectangleShape snakeHead;
//int snakeX[200] = { cellX / 2 };
//int snakeY[200] = { cellY / 2 };
//int snakeLength = 1;
//
//// For Color Selection of Snake
//RectangleShape tempSnake(Vector2f(gridSize - 1, gridSize - 1));
//const int tempSnakeLength = 8;
//int tempSnakeX = cellX / 2 - 4;
//int tempSnakeY = cellY / 2;
//int tempSnake1[tempSnakeLength];
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
//int remaining_score = 100;
//Text levelScoreText;
//
//// Obstacles
//RectangleShape block(Vector2f(gridSize - 1, gridSize - 1));
//int startX;
//int startY;
//int newX, newY;
//const int maxObstacles = 20;
//const int maxObsLength = 5;
//int numIncrease = 16;
//int obstacles[maxObstacles * maxObsLength][2];
//int obsStart[maxObstacles];
//int obsLengths[maxObstacles];
//int start, length0, obstacleX, obstacleY;
//int obsIndex, cIndex;
//
//// Customize Obstacles
//int maxObstacles1 = cellX * cellY;
//int obstacleCount = 0;
//int obstaclesNew[1920 * 1080][2];
//
//// Speed
//int speed = 70;
//int speedCheck = 70;
//
//// Custom Speed
//int custom_speed = 100;
//int red = 0, green = 255, blue = 0;
//RectangleShape spB(Vector2f(gridSize, gridSize));
//Text sp("Select Speed", font, 60);
//int speedX = cellX / 2 - 5;
//int speedY = cellY / 2;
//const int numspBlocks = 10;
//int cBlocks = 0;
//int spBlocks[numspBlocks];
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
//void Score();
////void nextLevel(RenderWindow& window);
//void reset(RenderWindow& window);
//void reset1();
//void createObstacles(RenderWindow& window);
//void wallCollision();
//void boxWallCollision();
//void respawnObstacles();
//void foodSpawn(RenderWindow& window);
//void foodCollision(RenderWindow& window);
//
//// Function to set text in Middle of window
//void setTextInMiddle(Text& text, RenderWindow& window)
//{
//    float textWidth = text.getLocalBounds().width;
//    float textHeight = text.getLocalBounds().height;
//
//    float textX = (window.getSize().x - textWidth) / 2;
//    float textY = (window.getSize().y - textHeight) / 2;
//
//    text.setPosition(textX, textY);
//}
//
//
//void sortingD(int arr[], int size) 
//{
//    for (int i = 0; i < size - 1; i++) 
//    {
//        for (int j = 0; j < size - i - 1; j++) 
//        {
//            if (arr[j] < arr[j + 1]) 
//            {
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
//
//void saveHighScore(int score)
//{
//    const int maxScores = 3;
//    int highScores[maxScores] = { 0 };
//    string myFile;
//
//    if (check == 3)
//        myFile = "highScores/endless_scores.txt";
//    else if (check == 4)
//        myFile = "highScores/level_scores.txt";
//    else if (check == 12)
//        myFile = "highScores/box_scores.txt";
//
//    ifstream fin(myFile);
//    int index = 0;
//
//    if (fin.is_open())
//    {
//        while (index < maxScores&& fin >> highScores[index])
//            index++;
//        fin.close();
//    }
//
//    for (int i = 0; i < maxScores; i++)
//    {
//        if (score > highScores[i])
//        {
//            for (int j = maxScores - 1; j > i; j--)
//                highScores[j] = highScores[j - 1];
//
//            highScores[i] = score;
//            break;
//        }
//    }
//
//    ofstream fout(myFile);
//    if (fout.is_open())
//    {
//        for (int i = 0; i < maxScores; i++)
//            fout << highScores[i] << endl;
//        fout.close();
//    }
//    else
//        cout << "Error: Could not save high scores!" << endl;
//}
//
//// To Load High Scores
//void loadHighScore(RenderWindow& window)
//{
//    window.clear();
//    window.setMouseCursorVisible(false);
//    window.draw(bgSprite);
//    Event load;
//
//    while (window.pollEvent(load))
//    {
//        if (load.type == Event::Closed)
//            window.close();
//        if (load.type == Event::KeyPressed && load.key.code == Keyboard::Escape)
//            gameState = 0;
//    }
//
//    Text highS("High Scores", font, 70);
//    highS.setFillColor(Color(0, 102, 102));
//    highS.setLetterSpacing(1.7f);
//    setTextInMiddle(highS, window);
//    highS.setPosition(Vector2f(highS.getPosition().x, highS.getPosition().y - 310));
//    window.draw(highS);
//
//    Text Return("Press Escape to Return to Main Menu", font, 40);
//    Return.setFillColor(Color(160, 160, 160));
//    Return.setLetterSpacing(1.7f);
//    setTextInMiddle(Return, window);
//    Return.setPosition(Vector2f(Return.getPosition().x, Return.getPosition().y + 350));
//    window.draw(Return);
//
//    // Load scores for Endless Mode
//    int endlessScores[3] = { 0 };
//    ifstream endlessLoader("highScores/endless_scores.txt");
//    if (!endlessLoader)
//    {
//        Text error("Error: Could not load Endless Mode High Scores", font, 40);
//        error.setFillColor(Color::Red);
//        setTextInMiddle(error, window);
//        window.draw(error);
//        return;
//    }
//
//    for (int i = 0; i < 3 && endlessLoader >> endlessScores[i]; i++);
//    endlessLoader.close();
//
//    Text endlessDisplay("Endless Mode", font, 45);
//    endlessDisplay.setLetterSpacing(1.7f);
//    endlessDisplay.setFillColor(Color(0, 150, 150));
//    setTextInMiddle(endlessDisplay, window);
//    endlessDisplay.setPosition(Vector2f(endlessDisplay.getPosition().x / 3, endlessDisplay.getPosition().y - 150));
//    window.draw(endlessDisplay);
//
//    for (int i = 0; i < 3; i++)
//    {
//        string scoreText = to_string(i + 1) + ". " + to_string(endlessScores[i]);
//        Text scoreDisplay(scoreText, font, 40);
//        scoreDisplay.setFillColor(Color(224, 224, 224));
//        setTextInMiddle(scoreDisplay, window);
//        scoreDisplay.setPosition(Vector2f(scoreDisplay.getPosition().x / 2.5, scoreDisplay.getPosition().y - 70 + (i * 80)));
//        window.draw(scoreDisplay);
//    }
//
//    // Load Scores for Box Mode
//    int boxScores[3] = { 0 };
//    ifstream boxLoader("highScores/box_scores.txt");
//    if (!boxLoader)
//    {
//        Text error("Error: Could not load Bpx Mode High Scores", font, 40);
//        error.setFillColor(Color::Red);
//        setTextInMiddle(error, window);
//        window.draw(error);
//        return;
//    }
//
//    for (int i = 0; i < 3 && boxLoader >> boxScores[i]; i++);
//    boxLoader.close();
//
//    Text boxDisplay("Box Mode", font, 45);
//    boxDisplay.setLetterSpacing(1.7f);
//    boxDisplay.setFillColor(Color(0, 150, 150));
//    setTextInMiddle(boxDisplay, window);
//    boxDisplay.setPosition(Vector2f(boxDisplay.getPosition().x, boxDisplay.getPosition().y - 150));
//    window.draw(boxDisplay);
//
//    for (int i = 0; i < 3; i++)
//    {
//        string BSText = to_string(i + 1) + ". " + to_string(boxScores[i]);
//        Text BSDisplay(BSText, font, 40);
//        BSDisplay.setFillColor(Color(224, 224, 224));
//        setTextInMiddle(BSDisplay, window);
//        BSDisplay.setPosition(Vector2f(BSDisplay.getPosition().x, BSDisplay.getPosition().y - 70 + (i * 80)));
//        window.draw(BSDisplay);
//    }
//
//    // Load scores for Level Mode
//    int levelScores[3] = { 0 };
//    ifstream levelLoader("highScores/level_scores.txt");
//    if (!levelLoader)
//    {
//        Text error("Error: Could not load Level Mode High Scores", font, 40);
//        error.setFillColor(Color::Red);
//        setTextInMiddle(error, window);
//        window.draw(error);
//        return;
//    }
//
//    for (int i = 0; i < 3 && levelLoader >> levelScores[i]; i++);
//    levelLoader.close();
//
//    Text levelDisplay("Level Mode", font, 45);
//    boxDisplay.setLetterSpacing(1.7f);
//    levelDisplay.setFillColor(Color(0, 150, 150));
//    setTextInMiddle(levelDisplay, window);
//    levelDisplay.setPosition(Vector2f(levelDisplay.getPosition().x * 1.64, levelDisplay.getPosition().y - 150));
//    window.draw(levelDisplay);
//
//    for (int i = 0; i < 3; i++)
//    {
//        string scoreText = to_string(i + 1) + ". " + to_string(levelScores[i]);
//        Text scoreDisplay(scoreText, font, 40);
//        scoreDisplay.setFillColor(Color(224, 224, 224));
//        setTextInMiddle(scoreDisplay, window);
//        scoreDisplay.setPosition(Vector2f(scoreDisplay.getPosition().x * 1.6, scoreDisplay.getPosition().y - 80 + (i * 80)));
//        window.draw(scoreDisplay);
//    }
//}
//
//void saveGame()
//{
//    if (check == 3)
//    {
//        ofstream saveFile("highScores/endless_save.txt");
//
//        if (saveFile.is_open())
//        {
//            saveFile << snakeLength << endl;
//            saveFile << score << endl;
//            saveFile << speed << endl;
//
//            for (int i = 0; i < snakeLength; i++)
//                saveFile << snakeX[i] << endl << snakeY[i] << endl;
//
//            saveFile << foodX << endl << foodY << endl;
//
//            saveFile << red1 << endl << green1 << endl << blue1 << endl;
//            saveFile << dir << endl;
//
//            saveFile << check << endl;
//
//            saveFile.close();
//            cout << "Game saved!" << endl;
//        }
//        else
//            cout << "Error: Endless Game Not saved!" << endl;
//    }
//
//    if (check == 4) 
//    { 
//        ofstream saveFile1("highScores/level_save.txt");
//
//        if (saveFile1.is_open()) 
//        {
//            saveFile1 << snakeLength << endl;
//            saveFile1 << score << endl;
//            saveFile1 << remaining_score << endl;
//            saveFile1 << speed << endl;
//
//            for (int i = 0; i < snakeLength; i++)
//                saveFile1 << snakeX[i] << endl << snakeY[i] << endl;
//
//            saveFile1 << numIncrease << endl;
//
//            saveFile1 << obstacleCount << endl;
//            for (int i = 0; i < (maxObstacles - numIncrease); i++) 
//            {
//                saveFile1 << obsStart[i] << endl;
//                saveFile1 << obsLengths[i] << endl;
//                for (int j = 0; j < obsLengths[i]; j++) 
//                {
//                    saveFile1 << obstacles[obsStart[i] + j][0] << endl;
//                    saveFile1 << obstacles[obsStart[i] + j][1] << endl;
//                }
//            }
//
//            saveFile1 << foodX << endl << foodY << endl;
//
//            saveFile1 << red << endl << green << endl << blue << endl;
//            saveFile1 << red1 << endl << green1 << endl << blue1 << endl;
//            saveFile1 << dir << endl;
//
//            saveFile1 << check << endl;
//            saveFile1.close();
//            cout << "Game saved!" << endl;
//        }
//        else
//            cout << "Error: Level Game Not saved!" << endl;
//    }
//    if (check == 9)
//    {
//        ofstream saveFile2("highScores/custom_save.txt");
//        if (saveFile2.is_open())
//        {
//            saveFile2 << snakeLength << endl;
//            saveFile2 << score << endl;
//            saveFile2 << custom_speed << endl;
//
//            for (int i = 0; i < snakeLength; i++)
//                saveFile2 << snakeX[i] << endl << snakeY[i] << endl;
//
//            saveFile2 << obstacleCount << endl;
//            for (int i = 0; i < obstacleCount; i++)
//                saveFile2 << obstaclesNew[i][0] << endl << obstaclesNew[i][1] << endl;
//
//            saveFile2 << foodX << endl << foodY << endl;
//
//            saveFile2 << red << endl << green << endl << blue << endl;
//            saveFile2 << red1 << endl << green1 << endl << blue1 << endl;
//            saveFile2 << dir << endl;
//            saveFile2 << check << endl;
//
//            saveFile2.close();
//            cout << "Game saved!" << endl;
//        }
//        else
//            cout << "Error: Custom Game Not saved!" << endl;
//    }
//    if (check == 12)
//    {
//        ofstream saveFile3("highScores/box_save.txt");
//
//        if (saveFile3.is_open())
//        {
//            saveFile3 << snakeLength << endl;
//            saveFile3 << score << endl;
//            saveFile3 << speed << endl;
//
//            for (int i = 0; i < snakeLength; i++)
//                saveFile3 << snakeX[i] << endl << snakeY[i] << endl;
//
//            saveFile3 << foodX << endl << foodY << endl;
//
//            saveFile3 << red1 << endl << green1 << endl << blue1 << endl;
//            saveFile3 << dir << endl;
//
//            saveFile3 << check << endl;
//
//            saveFile3.close();
//            cout << "Game saved!" << endl;
//        }
//        else
//            cout << "Error: Box Game Not saved!" << endl;
//    }
//}
//
//void loadGame()
//{
//    if (check == 3)
//    {
//        ifstream loadFile("highScores/endless_save.txt");
//
//        if (loadFile.is_open())
//        {
//            loadFile >> snakeLength;
//            loadFile >> score;
//            loadFile >> speed;
//
//            for (int i = 0; i < snakeLength; i++)
//                loadFile >> snakeX[i] >> snakeY[i];
//
//            loadFile >> foodX >> foodY;
//
//            loadFile >> red1 >> green1 >> blue1;
//            loadFile >> dir;
//
//            loadFile >> check;
//
//            loadFile.close();
//            cout << "Game loaded!" << endl;
//        }
//        else
//            cout << "Error: Endless Game Not loaded!" << endl;
//    }
//
//    if (check == 4) 
//    {
//        ifstream loadFile1("highScores/level_save.txt");
//
//        if (loadFile1.is_open())
//        {
//            loadFile1 >> snakeLength;
//            loadFile1 >> score;
//            loadFile1 >> remaining_score;
//            loadFile1 >> speed;
//
//            for (int i = 0; i < snakeLength; i++)
//                loadFile1 >> snakeX[i] >> snakeY[i];
//
//            loadFile1 >> numIncrease;
//
//            loadFile1 >> obstacleCount;
//            for (int i = 0; i < (maxObstacles - numIncrease); i++)
//            {
//                loadFile1 >> obsStart[i];
//                loadFile1 >> obsLengths[i];
//                for (int j = 0; j < obsLengths[i]; j++)
//                {
//                    loadFile1 >> obstacles[obsStart[i] + j][0]; 
//                    loadFile1 >> obstacles[obsStart[i] + j][1]; 
//                }
//            }
//
//            loadFile1 >> foodX >> foodY;
//
//            loadFile1 >> red >> green >> blue;
//            loadFile1 >> red1 >> green1 >> blue1;
//            loadFile1 >> dir;
//
//            loadFile1 >> check;
//
//            loadFile1.close();
//            cout << "Game loaded!" << endl;
//        }
//        else
//            cout << "Error: Level Game Not loaded!" << endl;
//    }
//
//    if (check == 9)
//    {
//        ifstream loadFile2("highScores/custom_save.txt");
//
//        if (loadFile2.is_open())
//        {
//            loadFile2 >> snakeLength;
//            loadFile2 >> score;
//            loadFile2 >> custom_speed;
//
//            for (int i = 0; i < snakeLength; i++)
//            {
//                loadFile2 >> snakeX[i];
//                loadFile2 >> snakeY[i];
//            }
//
//            loadFile2 >> obstacleCount;
//
//            for (int i = 0; i < obstacleCount; i++)
//            {
//                loadFile2 >> obstaclesNew[i][0];
//                loadFile2 >> obstaclesNew[i][1];
//            }
//
//            loadFile2 >> foodX >> foodY;
//            loadFile2 >> red >> green >> blue;
//            loadFile2 >> red1 >> green1 >> blue1;
//            loadFile2 >> dir;
//            loadFile2 >> check;
//
//            loadFile2.close();
//            cout << "Game loaded!" << endl;
//        }
//        else
//            cout << "Error: Custom Game Not loaded!" << endl;
//    }
//
//    if (check == 12)
//    {
//        ifstream loadFile3("highScores/box_save.txt");
//
//        if (loadFile3.is_open())
//        {
//            loadFile3 >> snakeLength;
//            loadFile3 >> score;
//            loadFile3 >> speed;
//
//            for (int i = 0; i < snakeLength; i++)
//                loadFile3 >> snakeX[i] >> snakeY[i];
//
//            loadFile3 >> foodX >> foodY;
//
//            loadFile3 >> red1 >> green1 >> blue1;
//            loadFile3 >> dir;
//
//            loadFile3 >> check;
//
//            loadFile3.close();
//            cout << "Game loaded!" << endl;
//        }
//        else
//            cout << "Error: Endless Game Not loaded!" << endl;
//    }
//}
//
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
//
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
//// Collision of Snake with walls in Box Mode
//void boxWallCollision()
//{
//    if (snakeX[0] >= cellX || snakeX[0] < 0 || snakeY[0] >= cellY || snakeY[0] < 0)
//    {
//        check = gameState;
//        saveHighScore(score);
//        gameState = 6;
//    }
//}
//
//// To display Score during gameplay
//void Score()
//{
//    scoreText.setString("Score: " + to_string(score));
//    scoreText.setFont(font);
//    scoreText.setCharacterSize(25);
//    scoreText.setLetterSpacing(1.7f);
//    scoreText.setFillColor(Color(0, 130, 130));
//    scoreText.setPosition(10.f, 10.f);   
//
//    levelScoreText.setString("Remaining: " + to_string(remaining_score));
//    levelScoreText.setFont(font);
//    levelScoreText.setCharacterSize(25);
//    levelScoreText.setLetterSpacing(1.7f);
//    levelScoreText.setFillColor(Color(0, 130, 130));
//    levelScoreText.setPosition(10.f, 40.f);
//}
//
//// To check for food on snake body
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
//// To check for obstacle on snake body
//bool isNotOnSnake1(int x, int y)
//{
//    for (int i = 0; i < snakeLength; i++)
//    {
//        if (snakeX[i] == x && snakeY[i] == y)
//            return false;
//        if (snakeX[0] == x || snakeY[0] == y)
//            return false;
//    }
//    return true;
//}
//
//// Obstacles which can be regenerated and spawned again
//void respawnObstacles()
//{
//    obsIndex = 0;
//    for (int i = 0; i < (maxObstacles - numIncrease); i++)
//    {
//        bool valid = false;
//        obsStart[i] = obsIndex;
//        obsLengths[i] = 0;
//
//        while (!valid)
//        {
//            valid = true;
//            cIndex = obsIndex;
//
//            startX = rand() % cellX;
//            startY = rand() % cellY;
//
//            for (int j = 0; j < maxObsLength; j++)
//            {
//                newX = startX;
//                newY = startY;
//
//                if (i % 2 == 0)
//                    newX = startX + j;
//                else
//                    newY = startY + j;
//
//                if (!isNotOnSnake1(newX, newY) && valid == true)
//                    valid = false;
//                else
//                {
//                    obstacles[cIndex][0] = newX;
//                    obstacles[cIndex][1] = newY;
//                    cIndex++;
//                    obsLengths[i]++;
//                }
//            }
//
//            if (!valid)
//            {
//                obsIndex = obsStart[i];
//                obsLengths[i] = 0;
//            }
//            else
//                obsIndex = cIndex;
//        }
//    }
//}
//
//void drawObstacles1(RenderWindow& window)
//{
//    block.setFillColor(Color(0, 140, 140));
//
//    for (int i = 0; i < (maxObstacles - numIncrease); i++)
//    {
//        start = obsStart[i];
//        length0 = obsLengths[i];
//
//        for (int j = 0; j < length0; j++)
//        {
//            obstacleX = obstacles[start + j][0];
//            obstacleY = obstacles[start + j][1];
//
//            block.setPosition(obstacleX * gridSize, obstacleY * gridSize);
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
//        for (int i = 0; i < (maxObstacles - numIncrease); i++) 
//        {
//            start = obsStart[i];
//            length0 = obsLengths[i];
//
//            for (int j = 0; j < length0; j++) 
//            {
//                obstacleX = obstacles[start + j][0]; 
//                obstacleY = obstacles[start + j][1];
//
//                if (snakeX[0] == obstacleX && snakeY[0] == obstacleY) 
//                {
//                    check = gameState;
//                    saveHighScore(score);
//
//                    gameState = 6;
//                    return;                    
//                }
//            }
//        }
//    }
//    if (gameState == 9)
//    {
//        for (int i = 0; i < obstacleCount; i++)
//        {
//            if (snakeX[0] == obstaclesNew[i][0] && snakeY[0] == obstaclesNew[i][1])
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
//        for (int i = 0; i < maxObstacles; i++) 
//        {
//            start = obsStart[i];
//            length0 = obsLengths[i];
//
//            for (int j = 0; j < length0; j++) 
//            {
//                obstacleX = obstacles[start + j][0];
//                obstacleY = obstacles[start + j][1];
//
//                if (x == obstacleX && y == obstacleY && isAvailable == true)
//                    isAvailable = false;
//            }
//        }
//    }
//
//    if (gameState == 9)
//    {
//        for (int i = 0; i < obstacleCount; i++)
//        {
//            if (x == obstaclesNew[i][0] && y == obstaclesNew[i][1] && isAvailable == true)
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
//
//        if (gameState == 4)
//        {
//            remaining_score -= 10;
//            if (remaining_score == 0)
//            {
//                //gameState = 13;
//                remaining_score = 100;
//            }
//        }
//
//        if (snakeLength < 199)
//            snakeLength++;
//
//        if (speed > 10)
//            speed--;
//        saveGame();
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
//            if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
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
//    const int menu1Size = 5;
//    string menu1options[menu1Size] = {"New Game", "Play Saved Game", "High Scores", "Controls", "Exit"};
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
//                    menu1option = menu1Size - 1;
//            }
//
//            else if (event.key.code == Keyboard::S)
//            {
//                scrollSound.setPitch(2);
//                scrollSound.play();
//                menu1option++;
//                if (menu1option >= menu1Size)
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
//                    gameState = 11;
//                else if (menu1option == 2)
//                    gameState = 10;
//                else if (menu1option == 3)
//                    gameState = 14;
//                else if (menu1option == 4)
//                    window.close();
//            }
//        }
//    }
//
//    int m1pChecker = -160;
//    Text menu1Texts[menu1Size];
//    for (int i = 0; i < menu1Size; i++)
//    {
//        menu1Texts[i].setFont(font);
//        menu1Texts[i].setString(menu1options[i]);
//        menu1Texts[i].setCharacterSize(50);
//        menu1Texts[i].setLetterSpacing(1.7f);
//        setTextInMiddle(menu1Texts[i], window);
//        menu1Texts[i].setPosition(Vector2f(menu1Texts[i].getPosition().x, menu1Texts[i].getPosition().y + m1pChecker));
//        m1pChecker += 80;
//    }
//
//    for (int i = 0; i < menu1Size; i++)
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
//    for (int i = 0; i < menu1Size; i++)
//        window.draw(menu1Texts[i]);
//}
//
//// 2nd Menu which asks for selection of different kinds of modes: gameState (1)
//void menu2(RenderWindow& window)
//{
//    window.setMouseCursorVisible(false);
//    Text selectMode("Select Mode", font, 100);
//    selectMode.setFillColor(Color(0, 102, 102));
//    selectMode.setLetterSpacing(1.7f);
//    setTextInMiddle(selectMode, window);
//    selectMode.setPosition(Vector2f(selectMode.getPosition().x, selectMode.getPosition().y - 300));
//
//    const int menu2Size = 5;
//    string menu2options[menu2Size] = {"Endless Mode", "Level Mode", "Custom Mode", "Box Mode", "Back"};
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
//                    menu2option = menu2Size - 1;
//            }
//
//            else if (event.key.code == Keyboard::S)
//            {
//                scrollSound.setPitch(2);
//                scrollSound.play();
//                menu2option++;
//                if (menu2option >= menu2Size)
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
//                {
//                    check = 12;
//                    gameState = 2;
//                }
//                else if (menu2option == 4)
//                    gameState = 0;
//            }
//        }
//    }
//    int m2pChecker = -160;
//    Text menu2Texts[menu2Size];
//    for (int i = 0; i < menu2Size; i++)
//    {
//        menu2Texts[i].setFont(font);
//        menu2Texts[i].setString(menu2options[i]);
//        menu2Texts[i].setCharacterSize(50);
//        menu2Texts[i].setLetterSpacing(1.7f);
//        setTextInMiddle(menu2Texts[i], window);
//        menu2Texts[i].setPosition(Vector2f(menu2Texts[i].getPosition().x, menu2Texts[i].getPosition().y + m2pChecker));
//        m2pChecker += 80;
//    }
//
//    for (int i = 0; i < menu2Size; i++)
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
//    for (int i = 0; i < menu2Size; i++)
//        window.draw(menu2Texts[i]);
//}
//
//void menu2load(RenderWindow& window)
//{
//    window.setMouseCursorVisible(false);
//    Text selectMode("Select Mode", font, 100);
//    selectMode.setFillColor(Color(0, 102, 102));
//    selectMode.setLetterSpacing(1.7f);
//    setTextInMiddle(selectMode, window);
//    selectMode.setPosition(Vector2f(selectMode.getPosition().x, selectMode.getPosition().y - 300));
//
//    const int menu2Size = 5;
//    string menu2options[menu2Size] = { "Endless Mode", "Level Mode", "Custom Mode", "Box Mode", "Back" };
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
//                    menu2option = menu2Size - 1;
//            }
//
//            else if (event.key.code == Keyboard::S)
//            {
//                scrollSound.setPitch(2);
//                scrollSound.play();
//                menu2option++;
//                if (menu2option >= menu2Size)
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
//                    loadGame();
//                    gameState = check;
//                }
//                else if (menu2option == 1)
//                {
//                    check = 4;
//                    loadGame();
//                    gameState = check;
//                }
//                else if (menu2option == 2)
//                {
//                    check = 9;
//                    loadGame();
//                    gameState = check;
//                }
//                else if (menu2option == 3)
//                {
//                    check = 12;
//                    loadGame();
//                    gameState = check;
//                }
//                else if (menu2option == 4)
//                    gameState = 0;
//            }
//        }
//    }
//    int m2pChecker = -160;
//    Text menu2Texts[menu2Size];
//    for (int i = 0; i < menu2Size; i++)
//    {
//        menu2Texts[i].setFont(font);
//        menu2Texts[i].setString(menu2options[i]);
//        menu2Texts[i].setCharacterSize(50);
//        menu2Texts[i].setLetterSpacing(1.7f);
//        setTextInMiddle(menu2Texts[i], window);
//        menu2Texts[i].setPosition(Vector2f(menu2Texts[i].getPosition().x, menu2Texts[i].getPosition().y + m2pChecker));
//        m2pChecker += 80;
//    }
//
//    for (int i = 0; i < menu2Size; i++)
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
//    for (int i = 0; i < menu2Size; i++)
//        window.draw(menu2Texts[i]);
//}
//
//// 3rd Menu which asks for color of snake gameState (2)
//void menu3(RenderWindow& window)
//{
//    window.setMouseCursorVisible(false);
//
//    for (int i = 0; i < tempSnakeLength; i++)
//        tempSnake1[i] = i;
//    tempSnake.setPosition(Vector2f(tempSnakeX - 4, tempSnakeY));
//
//    Text selectColor("Select Snake Color", font, 90);
//    selectColor.setFillColor(Color(0, 102, 102));
//    selectColor.setLetterSpacing(1.7f);
//    setTextInMiddle(selectColor, window);
//    selectColor.setPosition(Vector2f(selectColor.getPosition().x, selectColor.getPosition().y - 310));
//
//    Text Return1("Press Esc to return to Mode Menu", font, 40);
//    Return1.setFillColor(Color(192, 192, 192));
//    Return1.setLetterSpacing(1.7f);
//    setTextInMiddle(Return1, window);
//    Return1.setPosition(Vector2f(Return1.getPosition().x, Return1.getPosition().y + 350));
//
//    const int menu3Size = 7;
//    string menu3options[menu3Size] = {"Green", "Red", "Blue", "Purple", "White", "Pink", "Gray"};
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
//                    menu3option = menu3Size - 1;
//            }
//
//            else if (event.key.code == Keyboard::S)
//            {
//                scrollSound.setPitch(2);
//                scrollSound.play();
//                menu3option++;
//                if (menu3option >= menu3Size)
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
//    Text menu3Texts[menu3Size];
//    for (int i = 0; i < menu3Size; i++)
//    {
//        menu3Texts[i].setFont(font);
//        menu3Texts[i].setString(menu3options[i]);
//        menu3Texts[i].setCharacterSize(40);
//        menu3Texts[i].setLetterSpacing(1.7f);
//        setTextInMiddle(menu3Texts[i], window);
//        menu3Texts[i].setPosition(Vector2f(menu3Texts[i].getPosition().x / 2, menu3Texts[i].getPosition().y + m3pChecker));
//        m3pChecker += 60;
//    }
//
//    for (int i = 0; i < menu3Size; i++)
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
//                red1 = 128; green1 = 128; blue1 = 128;
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
//    for (int i = 0; i < menu3Size; i++)
//        window.draw(menu3Texts[i]);
//    for (int i = 0; i < tempSnakeLength; i++)
//    {
//        tempSnake.setPosition(Vector2f((tempSnakeX + i) * gridSize, tempSnakeY * gridSize));
//        window.draw(tempSnake);
//    }
//}
//
//void controls(RenderWindow& window)
//{
//    window.clear();
//    window.draw(bgSprite);
//
//    Event controlDisplay;
//
//    while (window.pollEvent(controlDisplay))
//    {
//        if (controlDisplay.type == Event::Closed)
//            window.close();
//        if (controlDisplay.type == Event::KeyPressed && controlDisplay.key.code == Keyboard::Escape)
//            gameState = 0;
//    }
//    Text simpleText("Controls", font, 70);
//    simpleText.setFillColor(Color(0, 102, 102));
//    simpleText.setLetterSpacing(1.7f);
//    setTextInMiddle(simpleText, window);
//    simpleText.setPosition(Vector2f(simpleText.getPosition().x, simpleText.getPosition().y - 370));
//
//    Text Return("Press Escape to Return to Main Menu", font, 40);
//    Return.setFillColor(Color(160, 160, 160));
//    Return.setLetterSpacing(1.7f);
//    setTextInMiddle(Return, window);
//    Return.setPosition(Vector2f(Return.getPosition().x, Return.getPosition().y + 400));
//
//    const int controlSize = 6;
//    string controls[controlSize] = { "W -          Move/Navigate Up", "S -           Move/Navigate Down", "A -           Move/Navigate Left", "D -           Move/Navigate Right", "Escape -   Pause/Return", "Enter -      Confirm" };
//    
//    Text controlTexts[controlSize];
//    int controlChecker = -180;
//    for (int i = 0; i < controlSize; i++)
//    {
//        controlTexts[i].setFont(font);
//        controlTexts[i].setString(controls[i]);
//        controlTexts[i].setCharacterSize(37);
//        controlTexts[i].setLetterSpacing(1.7f);
//        controlTexts[i].setPosition(Vector2f((cellX / 2.6) * gridSize, (cellY / 2) * gridSize));
//        controlTexts[i].setPosition(Vector2f(controlTexts[i].getPosition().x, controlTexts[i].getPosition().y + controlChecker));
//        controlChecker += 80;
//    }
//
//    // Draw
//    window.draw(simpleText);
//    window.draw(Return);
//    for (int i = 0; i < controlSize; i++)
//        window.draw(controlTexts[i]);
//}
//
//// Endless Mode State (3)
//void mainGame(RenderWindow& window)
//{
//    window.setMouseCursorVisible(false);
//    //Snake Head
//    snakeHead.setPosition(Vector2f(snakeX[0] * gridSize, snakeY[0] * gridSize));
//    snakeHead.setFillColor(Color(red1, green1, blue1));
//    snakeHead.setSize(Vector2f(gridSize - 1, gridSize - 1));
//
//    //Food
//    food.setFillColor(Color(240, 128, 128));
//    food.setPosition(Vector2f(foodX * gridSize, foodY * gridSize));
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
//            gameState = 5;
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
//    window.draw(gBGSprite);
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
//    food.setFillColor(Color(240, 128, 128));
//    food.setPosition(Vector2f(foodX * gridSize, foodY * gridSize));
//
//    Event event;
//    while (window.pollEvent(event))
//    {
//        if (event.type == event.Closed)
//            window.close();
//        if (event.type == event.KeyPressed && event.key.code == Keyboard::Escape)
//            gameState = 5;
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
//    foodCollision(window);
//
//    static int lastScore = 0;
//    if (score % 100 == 0 && score != lastScore)
//	{
//		numIncrease -= 2;
//		respawnObstacles();
//        foodSpawn(window);
//		speed -= 5;
//		lastScore = score;
//	}
//
//    //Draw
//	window.clear();
//    window.draw(gBGSprite);
//	drawObstacles1(window);
//
//	// Draw Snake
//	for (int i = 0; i < snakeLength; i++)
//	{
//		snakeHead.setPosition(Vector2f(snakeX[i] * gridSize, snakeY[i] * gridSize));
//		window.draw(snakeHead);
//	}
//
//	window.draw(food);
//	window.draw(scoreText);
//    window.draw(levelScoreText);
//}
//
//// To convert mouse position to grid position
//void getGridPosition(int mousePosition[2], int gridPosition[2], int gridSize)
//{
//    gridPosition[0] = mousePosition[0] / gridSize;
//    gridPosition[1] = mousePosition[1] / gridSize;
//}
//
//bool isPositionOccupied(int x, int y, int obstaclesNew[][2], int obstacleCount)
//{
//    for (int i = 0; i < obstacleCount; i++)
//    {
//        if (obstaclesNew[i][0] == x && obstaclesNew[i][1] == y)
//            return true;
//    }
//    return false;
//}
//
//// To draw new obstacles
//void drawObstacles2(RenderWindow& window, int obstaclesNew[][2], int obstacleCount, int gridSize)
//{
//    for (int i = 0; i < obstacleCount; i++)
//    {
//        block.setPosition(obstaclesNew[i][0] * gridSize, obstaclesNew[i][1] * gridSize);
//
//        if (gameState == 7)
//            block.setFillColor(Color(128, 128, 128));
//        else if (gameState == 9)
//            block.setFillColor(Color(0, 140, 140));
//
//        window.draw(block);
//    }
//}
//
//// To control visibility and cursor while creating obstacles
//void mouseCursor(RenderWindow& window)
//{
//    window.setMouseCursorGrabbed(true);
//    window.setMouseCursorVisible(true);
//}
//
//// To create obstacles (gameState 7)
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
//        int cursorX = Mouse::getPosition(window).x;
//        int cursorY = Mouse::getPosition(window).y;
//
//        int mGridX = cursorX / gridSize;
//        int mGridY = cursorY / gridSize;
//
//        if (obstacleCount < maxObstacles1 && !isPositionOccupied(mGridX, mGridY, obstaclesNew, obstacleCount))
//        {
//            obstaclesNew[obstacleCount][0] = mGridX;
//            obstaclesNew[obstacleCount][1] = mGridY;
//            obstacleCount++;
//        }
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
//    drawObstacles2(window, obstaclesNew, obstacleCount, gridSize);
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
//        if (i <= cBlocks)
//            spB.setFillColor(Color(red, green, blue));
//        else
//            spB.setFillColor(Color(0, 0, 0));
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
//    if (Keyboard::isKeyPressed(Keyboard::D) && cBlocks < numspBlocks - 1 && red <= 227)
//    {
//        red += 28;
//        green -= 28;
//        blue = 0;
//        cBlocks++;
//        if (custom_speed >= 10)
//            custom_speed -= 8;
//        Sleep(160);
//    }
//
//    if (Keyboard::isKeyPressed(Keyboard::A) && cBlocks > 0 && red >= 28)
//    {
//        red -= 28;
//        green += 28;
//        blue = 0;
//        cBlocks--;
//        if (custom_speed <= 90)
//            custom_speed += 8;
//        Sleep(160);
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
//    snakeHead.setSize(Vector2f(gridSize - 1, gridSize - 1));
//
//    //Food    
//    food.setPosition(Vector2f(foodX * gridSize, foodY * gridSize));
//    food.setFillColor(Color(240, 128, 128));
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
//            check = gameState;
//            gameState = 5;
//        }
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
//    window.draw(gBGSprite);
//    drawObstacles2(window, obstaclesNew, obstacleCount, gridSize);
//
//    for (int i = 0; i < snakeLength; i++)
//    {
//        snakeHead.setPosition(Vector2f(snakeX[i] * gridSize, snakeY[i] * gridSize));
//        window.draw(snakeHead);
//    }
//    window.draw(food);
//    window.draw(scoreText);
//}
//
//void boxMode(RenderWindow& window)
//{
//    window.setMouseCursorVisible(false);
//    //Snake Head
//    snakeHead.setPosition(Vector2f(snakeX[0] * gridSize, snakeY[0] * gridSize));
//    snakeHead.setFillColor(Color(red1, green1, blue1));
//    snakeHead.setSize(Vector2f(gridSize - 1, gridSize - 1));
//
//    //Food
//    food.setFillColor(Color(240, 128, 128));
//    food.setPosition(Vector2f(foodX * gridSize, foodY * gridSize));
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
//            gameState = 5;
//    }
//
//    // Update
//    snakeMovement();
//    boxWallCollision();
//    Score();
//    foodCollision(window);
//    snakeCollision(window);
//
//    window.clear();
//
//    // Draw
//    window.draw(gBGSprite);
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
//// To ask Player to go to next Level (Currently not in use)
////void nextLevel(RenderWindow& window)
////{
////    window.clear();
////    window.draw(gBGSprite);
////
////    Event event;
////    while (window.pollEvent(event))
////    {
////        if (event.type == event.Closed)
////            window.close();
////        if (event.type == event.KeyPressed && event.key.code == Keyboard::Space)
////            gameState = 4;
////    }
////    Text next_level("Press Space to Proceed to next Level", font, 50);
////    next_level.setFillColor(Color(150, 150, 150));
////    next_level.setLetterSpacing(1.7f);
////    setTextInMiddle(next_level, window);
////    window.draw(next_level);
////}
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
//
//    speed = 70;
//    dir = 0;
//    for (int i = 0; i < snakeLength; i++)
//    {
//        snakeX[i] = 0;
//        snakeY[i] = 0;
//    }
//    snakeX[0] = cellX / 2;
//    snakeY[0] = cellY / 2;
//    snakeLength = 1;
//    score = 0;
//
//    if (check == 4)
//    {
//        remaining_score = 100;
//        numIncrease = 16;
//        respawnObstacles();
//    }
//    foodSpawn(window);
//}
//
//// To reset the items of Custom Mode
//void reset1()
//{
//    obstacleCount = 0;
//    custom_speed = 90;
//    cBlocks = 0;
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
//    window.clear();
//
//    window.draw(bg1Sprite);
//    window.setMouseCursorVisible(false);
//    const int pauseMenuSize = 4;
//    string pauseOptions[pauseMenuSize] = {"Resume", "Restart", "Return to Main Menu", "Exit"};
//
//    Event pause;
//
//    while (window.pollEvent(pause))
//    {
//        if (pause.type == Event::Closed)
//            window.close();
//        if (pause.type == Event::KeyPressed)
//        {
//            if (pause.key.code == Keyboard::W)
//            {
//                scrollSound.setPitch(2);
//                scrollSound.play();
//                pauseOption--;
//                if (pauseOption < 0)
//                    pauseOption = pauseMenuSize - 1;
//            }
//
//            else if (pause.key.code == Keyboard::S)
//            {
//                scrollSound.setPitch(2);
//                scrollSound.play();
//                pauseOption++;
//                if (pauseOption >= pauseMenuSize)
//                    pauseOption = 0;
//            }
//
//            else if (pause.key.code == Keyboard::Enter)
//            {
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
//                {
//                    saveGame();
//                    gameState = 0;
//                }
//                else if (pauseOption == 3)
//                {
//                    saveGame();
//                    window.close();
//                }
//                pauseOption = 0;
//            }
//            else if (pause.key.code == Keyboard::Escape)
//            {
//                gameState = check;
//                pauseOption = 0;
//            }
//        }
//    }
//
//    int ppChecker = -120;
//    Text menuTexts[pauseMenuSize];
//    for (int i = 0; i < pauseMenuSize; i++)
//    {
//        menuTexts[i].setFont(font);
//        menuTexts[i].setString(pauseOptions[i]);
//        menuTexts[i].setCharacterSize(50);
//        menuTexts[i].setLetterSpacing(1.7f);
//        setTextInMiddle(menuTexts[i], window);
//        menuTexts[i].setPosition(Vector2f(menuTexts[i].getPosition().x, menuTexts[i].getPosition().y + ppChecker));
//        ppChecker += 80;
//    }
//
//    for (int i = 0; i < pauseMenuSize; i++)
//    {
//        if (i == pauseOption)
//            menuTexts[i].setFillColor(Color(0, 153, 76));
//        else
//            menuTexts[i].setFillColor(Color::White);
//    }
//
//    for (int i = 0; i < pauseMenuSize; i++)
//        window.draw(menuTexts[i]);
//    Score();
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
//    const int gMenuSize = 3;
//    string gOptions[gMenuSize] = {"Restart", "Return to Main Menu", "Exit"};
//
//    Event Over;
//
//    while (window.pollEvent(Over))
//    {
//        if (Over.type == Event::Closed)
//            window.close();
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
//                    gOption = gMenuSize - 1;
//            }
//
//            else if (Over.key.code == Keyboard::S)
//            {
//                scrollSound.setPitch(2);
//                scrollSound.play();
//                gOption++;
//                if (gOption >= gMenuSize)
//                    gOption = 0;
//            }
//
//            else if (Over.key.code == Keyboard::Enter)
//            {
//                scrollSound.setPitch(1.9f);
//                scrollSound.play();
//                if (gOption == 0)
//                {
//                    reset(window);
//                    gameState = check;
//                }
//                else if (gOption == 1)
//                    gameState = 0;              
//                else if (gOption == 2)
//                    window.close();
//                gOption = 0;
//                menu1option = 0;
//                menu2option = 0;
//                menu3option = 0;
//            }
//        }
//    }
//
//    int gopChecker = -80;
//    Text gMenuTexts[gMenuSize];
//    for (int i = 0; i < gMenuSize; i++)
//    {
//        gMenuTexts[i].setFont(font);
//        gMenuTexts[i].setString(gOptions[i]);
//        gMenuTexts[i].setCharacterSize(50);
//        gMenuTexts[i].setLetterSpacing(1.7f);
//        setTextInMiddle(gMenuTexts[i], window);
//        gMenuTexts[i].setPosition(Vector2f(gMenuTexts[i].getPosition().x, gMenuTexts[i].getPosition().y + gopChecker));
//        gopChecker += 80;
//    }
//
//    for (int i = 0; i < gMenuSize; i++)
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
//    for (int i = 0; i < gMenuSize; i++)
//        window.draw(gMenuTexts[i]);
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
//    // Load GamePlay BG
//    if (!gBGTexture.loadFromFile("BG/gBG.png"))
//        cout << "Error: Failed to load gameplay Background Image.";
//    gBGSprite.setTexture(gBGTexture);
//
//    // Load Icon
//    if (!sI.loadFromFile("BG/icon1.png"))
//        cout << "Error: Failed to load Icon File!";
//
//    // Load Scroll Sound
//    if (!scrollBuffer.loadFromFile("Sound/soundEffect.wav"))
//        cout << "Error: Failed to load Scroll Sound!";
//    scrollSound.setBuffer(scrollBuffer);
//    scrollSound.setVolume(5);
//    scrollSound.setPitch(2);
//
//    // Load BG Music
//    if (!music.openFromFile("Sound/song.wav"))
//        cout << "Error: Failed to load Music!";
//    music.setVolume(7);
//    music.setLoop(true);
//    Listener::setPosition(snakeX[0], snakeY[0], 0);
//    music.setPosition(foodX, foodY, 0);
//    music.play();
//
//    RenderWindow window(VideoMode(width, height), "Snake Game", Style::Fullscreen);
//    window.setFramerateLimit(60);
//    window.setMouseCursorVisible(false);
//
//    window.setIcon(sI.getSize().x, sI.getSize().y, sI.getPixelsPtr());
//
//	respawnObstacles();
//	foodSpawn(window);
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
//        else if (gameState == 11)
//            menu2load(window);
//        else if (gameState == 12)
//            boxMode(window);
//        //else if (gameState == 13)
//            //nextLevel(window);
//        else if (gameState == 14)
//            controls(window);
//
//        window.display();
//    }
//    return 0;
//}