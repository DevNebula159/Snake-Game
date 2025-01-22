//void mainMenuText(RenderWindow& window, int& mainMenuOption)
//{
//    window.clear();
//
//    // Snake Game Title
//    string snakeGame = "SNAKE GAME";
//
//    // Menu options
//    vector<string> options = { "New Game", "Saved Game", "Mode", "Exit" };
//
//    // Background color
//    RectangleShape background(Vector2f(window.getSize().x, window.getSize().y));
//    background.setFillColor(Color(30, 50, 30)); // Dark green for a snake theme
//    window.draw(background);
//
//    // Event Handling
//    Event menu;
//    while (window.pollEvent(menu))
//    {
//        if (menu.type == Event::Closed)
//        {
//            window.close();
//        }
//        else if (menu.type == Event::KeyPressed)
//        {
//            if (menu.key.code == Keyboard::Escape)
//            {
//                window.close();
//            }
//            else if (menu.key.code == Keyboard::W) // Move up
//            {
//                mainMenuOption--;
//                if (mainMenuOption < 0)
//                    mainMenuOption = options.size() - 1; // Wrap to last option
//            }
//            else if (menu.key.code == Keyboard::S) // Move down
//            {
//                mainMenuOption++;
//                if (mainMenuOption >= options.size())
//                    mainMenuOption = 0; // Wrap to first option
//            }
//            else if (menu.key.code == Keyboard::Enter) // Select
//            {
//                if (mainMenuOption == 0)
//                {
//
//                    gameState = 3;// Call the main game logic
//                }
//                else if (mainMenuOption == 1)
//                {
//                    cout << "Save game placeholder." << endl;
//                }
//                else if (mainMenuOption == 2)
//                {
//                    gameState = 1; // Switch to mode/difficulty selection
//                }
//                else if (mainMenuOption == 3)
//                {
//                    window.close(); // Exit the game
//                }
//            }
//        }
//    }
//
//    // SNake GAme title
//    Text snakegame;
//    snakegame.setFont(font);
//    snakegame.setCharacterSize(100);
//    snakegame.setFillColor(Color::Green);
//    snakegame.setString(snakeGame);
//    snakegame.setPosition(
//        window.getSize().x / 2 - snakegame.getLocalBounds().width / 2,
//        50
//    );
//    window.draw(snakegame);
//
//    // Drawing Menu Options
//    for (int i = 0; i < options.size(); i++)
//    {
//        Text menuText;
//        menuText.setFont(font);
//        menuText.setString(options[i]);
//        menuText.setCharacterSize(50);
//        menuText.setFillColor(i == mainMenuOption ? Color::Yellow : Color::White);
//        menuText.setStyle(i == mainMenuOption ? Text::Bold : Text::Regular);
//
//        // Position each menu option
//        menuText.setPosition(
//            window.getSize().x / 2 - menuText.getLocalBounds().width / 2,
//            200 + i * 80 // Spaced below the title
//        );
//        window.draw(menuText);
//
//        // Add a snake icon beside the selected option
//        if (i == mainMenuOption)
//        {
//            CircleShape snakeIcon(10);
//            snakeIcon.setFillColor(Color::Green);
//            snakeIcon.setPosition(
//                window.getSize().x / 2 - menuText.getLocalBounds().width / 2 - 30,
//                200 + i * 80 + 15 // Align with text
//            );
//            window.draw(snakeIcon);
//        }
//    }
//
//    // Display the updated content
//    window.display();
//}
//
//void menu2(RenderWindow& window)
//{
//    window.clear();
//    string instruct = "SELECT THE MODE";
//    vector<string> options = { "Endless Mode", "Custom Mode", "Level Mode","Back" };
//    int optionSelect1 = 0;  // Initial selected option is the first one.
//
//    // Event Handling
//    Event modemenu;
//
//    while (window.isOpen()) {
//        while (window.pollEvent(modemenu)) {
//            if (modemenu.type == Event::Closed) {
//                window.close();
//            }
//            else if (modemenu.type == Event::KeyPressed) {
//                if (modemenu.key.code == Keyboard::Escape) {
//                    window.close();
//                }
//                else if (modemenu.key.code == Keyboard::W) // Move up
//                {
//                    optionSelect1--;
//                    if (optionSelect1 < 0)
//                        optionSelect1 = options.size() - 1; // Wrap to last option
//                }
//                else if (modemenu.key.code == Keyboard::S) // Move down
//                {
//                    optionSelect1++;
//                    if (optionSelect1 >= options.size())
//                        optionSelect1 = 0; // Wrap to first option
//                }
//                else if (modemenu.key.code == Keyboard::Enter) // Select
//                {
//                    gameState = 2;
//                    return;
//                }
//            }
//        }
//        window.clear();
//
//        // Background color
//        RectangleShape background(Vector2f(window.getSize().x, window.getSize().y));
//        background.setFillColor(Color(30, 50, 30));  // Dark green for a snake theme
//        window.draw(background);
//
//        // Drawing the options
//        for (int i = 0; i < options.size(); i++) {
//            Text modemenuOptions;
//            modemenuOptions.setFont(font);  // Set font once
//            modemenuOptions.setString(options[i]);
//            modemenuOptions.setCharacterSize(50);
//            modemenuOptions.setPosition(
//                window.getSize().x / 2 - modemenuOptions.getLocalBounds().width / 2,
//                200 + i * 80  // Spaced below the title
//            );
//
//            // Highlight the selected option
//            if (i == optionSelect1) {
//                modemenuOptions.setFillColor(Color::Yellow);  // Highlight the selected option in yellow
//                modemenuOptions.setStyle(Text::Bold);  // Bold style for selected option
//            }
//            else {
//                modemenuOptions.setFillColor(Color::White);  // White for non-selected options
//                modemenuOptions.setStyle(Text::Regular);  // Regular style for non-selected options
//            }
//
//            window.draw(modemenuOptions);
//        }
//
//        // Drawing instruction text
//        Text instruction;
//        instruction.setString(instruct);
//        instruction.setFont(font);
//        instruction.setCharacterSize(100);
//        instruction.setFillColor(Color::Green);
//        instruction.setStyle(Text::Bold);
//        instruction.setPosition(
//            window.getSize().x / 2 - instruction.getLocalBounds().width / 2,
//            50  // Position it at the top
//        );
//        window.draw(instruction);
//
//        // Display the updated content
//        window.display();
//    }
//}
//
//void colorSelection(RenderWindow& window)
//{
//	window.clear();
//
//	string instruct = "Select the Snake Skin Color";
//	vector<string> options = { "Red", "Blue", "White", "Green","Back" };
//	int selectedColor = 0;  // Initial selected option
//
//	Event skinmenu;
//	while (window.pollEvent(skinmenu))
//	{
//		if (skinmenu.type == Event::Closed)
//		{
//			window.close();
//		}
//		else if (skinmenu.type == Event::KeyPressed)
//		{
//			if (skinmenu.key.code == Keyboard::Escape)
//			{
//				window.close();
//			}
//			else if (skinmenu.key.code == Keyboard::W)
//			{  // Move up
//				selectedColor--;
//				if (selectedColor < 0)
//					selectedColor = options.size() - 1;  // Wrap to last option
//			}
//			else if (skinmenu.key.code == Keyboard::S)
//			{  // Move down
//				selectedColor++;
//				if (selectedColor >= options.size())
//					selectedColor = 0;
//			}
//			else if (skinmenu.key.code == Keyboard::Enter)
//			{
//				if (selectedColor == 0)
//				{
//
//				}
//				else if (selectedColor == 1)
//				{
//
//				}
//				else if (selectedColor == 2)
//				{
//
//				}
//				else if (selectedColor == 3)
//				{
//
//				}
//				else if (selectedColor == 4)
//				{
//					gameState = 0;
//				}
//			}
//		}
//	}
//
//	window.clear();
//
//	// Background color
//	RectangleShape background(Vector2f(window.getSize().x, window.getSize().y));
//	background.setFillColor(Color(30, 50, 30));
//	window.draw(background);
//
//	// Drawing the options
//	for (int i = 0; i < options.size(); i++)
//	{
//
//		RectangleShape snake(Vector2f(300, 50));
//		snake.setPosition(window.getSize().x / 2 - 150, 200 + i * 100);
//
//		// Set color for each rectangle
//		if (i == 0)
//		{
//			snake.setFillColor(Color::Red);
//		}
//		else if (i == 1)
//		{
//			snake.setFillColor(Color::Blue);
//		}
//		else if (i == 2)
//		{
//			snake.setFillColor(Color::White);
//		}
//		else if (i == 3)
//		{
//			snake.setFillColor(Color::Green);
//		}
//		else if (i == 4)
//		{
//			snake.setFillColor(Color::Yellow);
//		}
//
//		// Highlight selected option
//		if (i == selectedColor)
//		{
//			snake.setOutlineThickness(5);
//			snake.setOutlineColor(Color::Yellow);
//		}
//		else
//		{
//			snake.setOutlineThickness(0);
//		}
//
//		window.draw(snake);
//
//		// Draw color names
//		Text colorName;
//		colorName.setFont(font);
//		colorName.setString(options[i]);
//		colorName.setCharacterSize(40);
//		colorName.setFillColor(i == selectedColor ? Color::Black : Color::White);
//		colorName.setPosition(window.getSize().x / 2 - colorName.getLocalBounds().width / 2, 200 + i * 100 + 10);
//		window.draw(colorName);
//	}
//
//	// Drawing instruction text
//	Text instruction;
//	instruction.setString(instruct);
//	instruction.setFont(font);
//	instruction.setCharacterSize(50);
//	instruction.setFillColor(Color::Green);
//	instruction.setStyle(Text::Bold);
//	instruction.setPosition(window.getSize().x / 2 - instruction.getLocalBounds().width / 2, 50);
//	window.draw(instruction);
//}
