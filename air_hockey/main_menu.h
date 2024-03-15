#pragma once

#include "air_hockey_GENERAL_HEADER.h"
#include "button.h"

class main_menu
{
private:


public:

	main_menu();

	int main_menu_engine(void);
};

/*******************************************************************************************************************************************************************************
	Function Call:        main_menu()
	Function description: this function is the default constructor for the main_menu class
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */

main_menu::main_menu() {}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        main_menu_engine()
	Function description: this function will get user input
	Function input(s):    NONE
	Function output(s):   int, returned to game wrapper
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */

int main_menu::main_menu_engine(void)
{
	sf::RenderWindow menu_window(sf::VideoMode(500, 500), "Air Hockey Main Menu");
	sf::Mouse mouse;
	sf::CircleShape mouse_cursor(5.f);
	sf::Font title_font, button_font;
	sf::Text game_title, play_game_text, exit_system_text, how_to_play_text, connect_system_text, test_game_text;
	button play_game_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 100), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));
	button exit_system_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 400), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));
	button how_to_play_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 300), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));
	button connect_computer_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 200), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));
	button test_game_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(400, 440), sf::Vector2f(MM_BUTTON_X_SIZE / 3, MM_BUTTON_Y_SIZE / 3));
	int button_hide = 0;

	mouse_cursor.setFillColor(sf::Color::Transparent);
	mouse_cursor.setPosition(250, 250);

	if (!button_font.loadFromFile("fonts\\AldotheApache.ttf"))
	{
		cout << "main menu font loading error\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "button font successfully loaded\n" << RESET << endl;
		play_game_text.setFont(button_font);
		exit_system_text.setFont(button_font);
		how_to_play_text.setFont(button_font);
		connect_system_text.setFont(button_font);
		test_game_text.setFont(button_font);

		play_game_text.setString("play game");
		exit_system_text.setString("exit");
		how_to_play_text.setString("how to play");
		connect_system_text.setString("connect");
		test_game_text.setString("test");

		play_game_text.setPosition(160, 100);
		exit_system_text.setPosition(215, 400);
		how_to_play_text.setPosition(135, 300);
		connect_system_text.setPosition(175, 200);
		test_game_text.setPosition(425, 440);

		play_game_text.scale(1.5, 1.5);
		exit_system_text.scale(1.5, 1.5);
		how_to_play_text.scale(1.5, 1.5);
		connect_system_text.scale(1.5, 1.5);
		test_game_text.scale(.5, .5);
	}

	if (!title_font.loadFromFile("fonts\\1up.ttf"))
	{
		cout << "title font loading error\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "title font successfully loaded\n" << RESET << endl;
		game_title.setFont(title_font);
		game_title.setString("Air Hockey");
		game_title.setPosition(20, 10);
		game_title.scale(2, 2);
	}

	menu_window.setFramerateLimit(60);

	while (menu_window.isOpen())
	{
		sf::Event event;
		while (menu_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				menu_window.close();
			}
		}

/*******************************************************************************************************************************************************/

		mouse_cursor.setPosition(mouse.getPosition(menu_window).x - mouse_cursor.getRadius(), mouse.getPosition(menu_window).y - mouse_cursor.getRadius()); /* ben made this */
		
		if (test_game_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				cout << RED << "mouse input for test game detected\n" << RESET << endl;
				menu_window.close();
				return -2;
			}
		}

		if (connect_computer_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				cout << RED << "mouse input for connect two computers detected\n" << RESET << endl;
				menu_window.close();
				return -1;
			}
		}

		if (play_game_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				cout << RED << "mouse input for play game detected\n" << RESET << endl;
				menu_window.close();
				return 1;
			}
		}
		else if (how_to_play_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				cout << RED << "mouse input for view records detected\n" << RESET << endl;
				menu_window.close();
				return 2;
			}
		}
		else if (exit_system_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				cout << RED << "mouse input for exit system detected\n" << RESET << endl;
				menu_window.close();
				return 3;
			}
		}

/*******************************************************************************************************************************************************/
		menu_window.clear(sf::Color::Blue); /* the argument to the clear call allows for color in the program */
/*******************************************************************************************************************************************************/

		menu_window.draw(game_title);
		menu_window.draw(mouse_cursor);
		menu_window.draw(play_game_button);
		menu_window.draw(exit_system_button);
		menu_window.draw(how_to_play_button);
		menu_window.draw(connect_computer_button);
		menu_window.draw(test_game_button);
		menu_window.draw(play_game_text);
		menu_window.draw(how_to_play_text);
		menu_window.draw(exit_system_text);
		menu_window.draw(connect_system_text);
		menu_window.draw(test_game_text);

/*******************************************************************************************************************************************************/
		menu_window.display();

		if (button_hide < DELAY_NUMBER)
		{
			button_hide++;
		}
	}

	return 3; /* if user closes the window, close the program */
}

/*******************************************************************************************************************************************************************************/

