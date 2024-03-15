#pragma once

#include "air_hockey_GENERAL_HEADER.h"
#include "button.h"
#include "edge_collider.h"
#include "left_player_mallet.h"
#include "right_player_mallet.h"
#include "puck.h"

class air_hockey_game
{
private:

	int m_left_player_score, m_right_player_score;



public:

	air_hockey_game();

	int air_hockey_game_engine(void);
};

/*******************************************************************************************************************************************************************************
	Function Call:        air_hockey_game()
	Function description: this function is the default constructor the the air_hockey_game class
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

air_hockey_game::air_hockey_game()
{
	this->m_left_player_score = 0;
	this->m_right_player_score = 0;
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        air_hockey_game_engine()
	Function description: this function will run the game and stuff
	Function input(s):    NONE
	Function output(s):   int
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

int air_hockey_game::air_hockey_game_engine(void)
{
	sf::RenderWindow game_window(sf::VideoMode(1138, 610), "Air Hockey Game");
	edge_collider
		top_edge(sf::Vector2f(1138, 15), sf::Vector2f(0, 0)),
		bottom_edge(sf::Vector2f(1138, 15), sf::Vector2f(0, 552)),
		left_edge(sf::Vector2f(15, 560), sf::Vector2f(0, 0)),
		right_edge(sf::Vector2f(15, 560), sf::Vector2f(1125, 0)),
		middle_edge(sf::Vector2f(5, 560), sf::Vector2f(567, 0)),
		left_goal(sf::Vector2f(15, 100), sf::Vector2f(0, 225)),
		right_goal(sf::Vector2f(15, 100), sf::Vector2f(1125, 225));


	sf::Mouse mouse;
	sf::CircleShape mouse_cursor(5.f);
	mouse_cursor.setFillColor(sf::Color::Magenta);
	mouse_cursor.setPosition(250, 250);

	left_player_mallet left_player(sf::Vector2f(285, 305), 35, MALLET_MASS, sf::Color::Cyan);
	right_player_mallet right_player(sf::Vector2f(853, 305), 35, MALLET_MASS, sf::Color::Cyan);

	button reset_puck_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(800, 573), sf::Vector2f(150, 30)),
		return_to_menu(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(975, 573), sf::Vector2f(150, 30));

	sf::Text return_to_menu_text, reset_puck_text, left_player_text, right_player_text, left_player_score_text, right_player_score_text;

	puck game_puck(sf::Vector2f(549, 270), 20, PUCK_MASS, sf::Color::Red);

	sf::Font button_font;

	if (!button_font.loadFromFile("fonts//AldotheApache.ttf"))
	{
		cout << "error loading button font\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "button font loaded successfully\n" << endl;

		return_to_menu_text.setFont(button_font);
		return_to_menu_text.setPosition(sf::Vector2f(978, 573));
		return_to_menu_text.scale(.75, .75);
		return_to_menu_text.setString("return to menu");

		reset_puck_text.setFont(button_font);
		reset_puck_text.setPosition(sf::Vector2f(823, 573));
		reset_puck_text.scale(.75, .75);
		reset_puck_text.setString("reset puck");

		left_player_text.setFont(button_font);
		left_player_text.setPosition(sf::Vector2f(10, 573));
		left_player_text.scale(.75, .75);
		left_player_text.setString("left player score:");

		left_player_score_text.setFont(button_font);
		left_player_score_text.setPosition(sf::Vector2f(190, 573));
		left_player_score_text.scale(.75, .75);
		left_player_score_text.setString(to_string(this->m_left_player_score));

		right_player_text.setFont(button_font);
		right_player_text.setPosition(sf::Vector2f(300, 573));
		right_player_text.scale(.75, .75);
		right_player_text.setString("right player score:");

		right_player_score_text.setFont(button_font);
		right_player_score_text.setPosition(sf::Vector2f(490, 573));
		right_player_score_text.scale(.75, .75);
		right_player_score_text.setString(to_string(this->m_right_player_score));
	}

	/* for setting up the background */
	sf::Texture arena_texture;
	arena_texture.loadFromFile("images/AirHockeyArena.png");
	sf::Sprite arena_sprite(arena_texture);
	arena_sprite.setPosition(0, 0);
	arena_sprite.setScale(1.75, 1.75);
	/********************************/

	game_window.setFramerateLimit(60);

	while (game_window.isOpen())
	{
		sf::Event event;
		while (game_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				game_window.close();
			}
		}

		mouse_cursor.setPosition(mouse.getPosition(game_window).x - mouse_cursor.getRadius(), mouse.getPosition(game_window).y - mouse_cursor.getRadius()); /* ben made this */

		left_player.movement_input(left_edge, middle_edge, top_edge, bottom_edge);
		right_player.movement_input(middle_edge, right_edge, top_edge, bottom_edge);

		game_puck.collision_detection_update(left_edge, right_edge, top_edge, bottom_edge, left_player, right_player);
		game_puck.movement_update();

		if (return_to_menu.detect_press_and_hover(mouse_cursor))
		{
			this->m_left_player_score = this->m_right_player_score = 0;
			game_window.close();
			return 0;
		}

		if (reset_puck_button.detect_press_and_hover(mouse_cursor))
		{
			game_puck.reset_puck();
		}

		if (game_puck.check_for_goal(left_goal))
		{
			cout << MAGENTA << "right player scored\n" << RESET << endl;
			this->m_right_player_score++;
			game_puck.reset_puck();
			right_player_score_text.setString(to_string(this->m_right_player_score));
		}

		if (game_puck.check_for_goal(right_goal))
		{
			cout << MAGENTA << "left player scored\n" << RESET << endl;
			this->m_left_player_score++;
			game_puck.reset_puck();
			left_player_score_text.setString(to_string(this->m_left_player_score));
		}

/*******************************************************************************************************************************************************/
		game_window.clear(sf::Color::Blue);
/*******************************************************************************************************************************************************/

		game_window.draw(arena_sprite);

		/* UNCOMMENT TO SEE EDGE COLLIDERS */
		//game_window.draw(top_edge);
		//game_window.draw(bottom_edge);
		//game_window.draw(left_edge);
		//game_window.draw(right_edge);
		//game_window.draw(middle_edge);
		//game_window.draw(left_goal);
		//game_window.draw(right_goal);
		
		left_player.render_projectile(game_window);
		right_player.render_projectile(game_window);

		game_puck.render_projectile(game_window);

		game_window.draw(return_to_menu);
		game_window.draw(return_to_menu_text);

		game_window.draw(reset_puck_button);
		game_window.draw(reset_puck_text);

		game_window.draw(left_player_text);
		game_window.draw(left_player_score_text);

		game_window.draw(right_player_text);
		game_window.draw(right_player_score_text);

		/*******************************************************************************************************************************************************/

		game_window.display();

	}
	this->m_left_player_score = this->m_right_player_score = 0;
	return 0;
}



/*******************************************************************************************************************************************************************************/



