#pragma once

#include "air_hockey_GENERAL_HEADER.h"
#include "air_hockey_game.h"
#include "main_menu.h"
#include "how_to_play.h"
#include "connect_two_computers.h"
#include "test.h"

class game_wrapper
{
private:

	/*
		current_program_status:

				   -2 --> testing the program (yes this is -2)
				   -1 --> connect two computers (yes this is -1)
					0 --> inside main menu
					1 --> inside game (playing the game)
					2 --> how to play

		anything else --> exit the game (will probably denote this option value as 3)
	*/

	int current_program_status;

	main_menu m_main_menu; /* for loading the main menu of the APP */
	air_hockey_game m_game; /* for playing the actual game */
	how_to_play m_tutorial;
	connect_two_computers m_connection;
	test m_test;

public:

	game_wrapper();

	void general_engine(void);

};

/*******************************************************************************************************************************************************************************
	Function Call:        game_wrapper()
	Function description: this function is the default constructor for the app_wrapper class
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */

game_wrapper::game_wrapper()
{
	this->current_program_status = 0; /* set the default to main menu */
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        general_engine()
	Function description: this function is going to be the only function that is called in main()
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */

void game_wrapper::general_engine(void)
{
	while ((this->current_program_status == -1) || (this->current_program_status == 0) || (this->current_program_status == 1) || (this->current_program_status == 2) || (this->current_program_status == -2))
	{
		switch (this->current_program_status)
		{
		case -2:
			cout << GREEN << "inside testing hub\n" << RESET << endl;
			this->current_program_status = this->m_test.test_hub();
			break;
		case -1:
			cout << GREEN << "inside computer networking thing\n" << RESET << endl;
			this->current_program_status = this->m_connection.connection_engine();
			break;
		case 0: /* inside of main menu */
			cout << GREEN << "inside main menu\n" << RESET << endl;
			this->current_program_status = this->m_main_menu.main_menu_engine();
			break;
		case 1: /* inside of game (playing the game) */
			cout << GREEN << "inside game play\n" << RESET << endl;
			this->current_program_status = this->m_game.air_hockey_game_engine();
			break;
		case 2: /* inside of post game menu */
			cout << GREEN << "inside how to play\n" << RESET << endl;
			this->current_program_status = this->m_tutorial.how_to_play_engine();
			break;
		}
	}

	cout << RED << "program over" << RESET << endl;
}

/*******************************************************************************************************************************************************************************/





















	//sf::Mouse mouse;
	//	sf::RenderWindow game_window(sf::VideoMode(1500, 750), "~Air Hockey~");
	//	sf::Clock c;
	//
	//	/*** for loading arena image ***/
	//
	//	sf::Texture arena_texture;
	//	arena_texture.loadFromFile("images/AirHockeyArena.png");
	//	sf::Sprite arena_sprite(arena_texture);
	//	arena_sprite.setPosition(0, 0);
	//	arena_sprite.setScale(2.3, 2.3);
	//
	//	/*******************************/
	//
	//
	//	game_window.setFramerateLimit(60);
	//
	//	while (game_window.isOpen())
	//	{
	//		sf::Event event;
	//		while (game_window.pollEvent(event))
	//		{
	//			if (event.type == sf::Event::Closed)
	//			{
	//				game_window.close();
	//			}
	//		}
	//		game_window.clear();
	//
	//		game_window.draw(arena_sprite);
	//
	//		game_window.display();
	//
	//	}
	//
	//}
