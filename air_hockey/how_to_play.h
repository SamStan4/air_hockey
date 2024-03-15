#pragma once

#include "air_hockey_GENERAL_HEADER.h"
#include "key_diagram.h"
#include "button.h"

class how_to_play
{
public:

	how_to_play();

	int how_to_play_engine(void);
};

/*******************************************************************************************************************************************************************************
	Function Call:        how_to_play()
	Function description: this function is the default constructor for the how to play class
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

how_to_play::how_to_play()
{}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        how_to_play()
	Function description: this function is the default constructor for the how to play class
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

int how_to_play::how_to_play_engine(void)
{
	sf::RenderWindow tutorial_window(sf::VideoMode(500, 500), "Air Hockey, How to Play");
	sf::Mouse mouse;
	sf::CircleShape mouse_cursor(5.f);
	sf::Font title_font, button_font;
	sf::Text game_title, return_to_main, right_instructions, right_instructions_w, right_instructions_a, right_instructions_s, right_instructions_d, right_instructions_e,
		left_instructions, left_instructions_i, left_instructions_j, left_instructions_k, left_instructions_l, left_instructions_u;

	mouse_cursor.setFillColor(sf::Color::Magenta);
	mouse_cursor.setPosition(250, 250);

	button return_to_main_menu_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(320, 450), sf::Vector2f(MM_BUTTON_X_SIZE / 1.5, MM_BUTTON_Y_SIZE / 2));

	if (!button_font.loadFromFile("fonts\\AldotheApache.ttf"))
	{
		cout << "main menu font loading error\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "button font successfully loaded\n" << RESET << endl;
		return_to_main.setFont(button_font);
		return_to_main.setString("return to menu");
		return_to_main.setPosition(330, 450);
		return_to_main.scale(.75, .75);

		right_instructions.setFont(button_font);
		right_instructions_w.setFont(button_font);
		right_instructions_a.setFont(button_font);
		right_instructions_s.setFont(button_font);
		right_instructions_d.setFont(button_font);
		right_instructions_e.setFont(button_font);

		left_instructions.setFont(button_font);
		left_instructions_i.setFont(button_font);
		left_instructions_j.setFont(button_font);
		left_instructions_k.setFont(button_font);
		left_instructions_l.setFont(button_font);
		left_instructions_u.setFont(button_font);

		right_instructions.setString("Left player: ");
		right_instructions_w.setString("W --> move up");
		right_instructions_a.setString("A --> move left");
		right_instructions_s.setString("S --> move down");
		right_instructions_d.setString("D --> move right");
		right_instructions_e.setString("E --> speed boost");

		left_instructions.setString("Right player: ");
		left_instructions_i.setString("I --> move up");
		left_instructions_j.setString("J --> move left");
		left_instructions_k.setString("K --> move down");
		left_instructions_l.setString("L --> move right");
		left_instructions_u.setString("U --> speed boost");

		right_instructions.setPosition(sf::Vector2f(50, 250));
		right_instructions_w.setPosition(sf::Vector2f(50, 275));
		right_instructions_a.setPosition(sf::Vector2f(50, 300));
		right_instructions_s.setPosition(sf::Vector2f(50, 325));
		right_instructions_d.setPosition(sf::Vector2f(50, 350));
		right_instructions_e.setPosition(sf::Vector2f(50, 375));

		left_instructions.setPosition(sf::Vector2f(300, 250));
		left_instructions_i.setPosition(sf::Vector2f(300, 275));
		left_instructions_j.setPosition(sf::Vector2f(300, 300));
		left_instructions_k.setPosition(sf::Vector2f(300, 325));
		left_instructions_l.setPosition(sf::Vector2f(300, 350));
		left_instructions_u.setPosition(sf::Vector2f(300, 375));

		right_instructions.scale(sf::Vector2f(.75, .75));
		right_instructions_w.scale(sf::Vector2f(.75, .75));
		right_instructions_a.scale(sf::Vector2f(.75, .75));
		right_instructions_s.scale(sf::Vector2f(.75, .75));
		right_instructions_d.scale(sf::Vector2f(.75, .75));
		right_instructions_e.scale(sf::Vector2f(.75, .75));

		left_instructions.scale(sf::Vector2f(.75, .75));
		left_instructions_i.scale(sf::Vector2f(.75, .75));
		left_instructions_j.scale(sf::Vector2f(.75, .75));
		left_instructions_k.scale(sf::Vector2f(.75, .75));
		left_instructions_l.scale(sf::Vector2f(.75, .75));
		left_instructions_u.scale(sf::Vector2f(.75, .75));
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

	key_diagram
		w_key(sf::Vector2f(70, 120), sf::Vector2f(KEY_PARAMETER, KEY_PARAMETER), sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, "W", button_font),
		a_key(sf::Vector2f(40, 170), sf::Vector2f(KEY_PARAMETER, KEY_PARAMETER), sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, "A", button_font),
		s_key(sf::Vector2f(90, 170), sf::Vector2f(KEY_PARAMETER, KEY_PARAMETER), sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, "S", button_font),
		d_key(sf::Vector2f(140, 170), sf::Vector2f(KEY_PARAMETER, KEY_PARAMETER), sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, "D", button_font),
		e_key(sf::Vector2f(120, 120), sf::Vector2f(KEY_PARAMETER, KEY_PARAMETER), sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, "E", button_font),

		i_key(sf::Vector2f(370, 120), sf::Vector2f(KEY_PARAMETER, KEY_PARAMETER), sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, "I", button_font),
		j_key(sf::Vector2f(340, 170), sf::Vector2f(KEY_PARAMETER, KEY_PARAMETER), sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, "J", button_font),
		k_key(sf::Vector2f(390, 170), sf::Vector2f(KEY_PARAMETER, KEY_PARAMETER), sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, "K", button_font),
		l_key(sf::Vector2f(440, 170), sf::Vector2f(KEY_PARAMETER, KEY_PARAMETER), sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, "L", button_font),
		u_key(sf::Vector2f(320, 120), sf::Vector2f(KEY_PARAMETER, KEY_PARAMETER), sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, "U", button_font);

	tutorial_window.setFramerateLimit(60);

	while (tutorial_window.isOpen())
	{
		sf::Event event;
		while (tutorial_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				tutorial_window.close();
			}
		}

		/*******************************************************************************************************************************************************/

		mouse_cursor.setPosition(mouse.getPosition(tutorial_window).x - mouse_cursor.getRadius(), mouse.getPosition(tutorial_window).y - mouse_cursor.getRadius()); /* ben made this */

		w_key.key_press_update(sf::Keyboard::W);
		a_key.key_press_update(sf::Keyboard::A);
		s_key.key_press_update(sf::Keyboard::S);
		d_key.key_press_update(sf::Keyboard::D);
		e_key.key_press_update(sf::Keyboard::E);

		i_key.key_press_update(sf::Keyboard::I);
		j_key.key_press_update(sf::Keyboard::J);
		k_key.key_press_update(sf::Keyboard::K);
		l_key.key_press_update(sf::Keyboard::L);
		u_key.key_press_update(sf::Keyboard::U);

		if (return_to_main_menu_button.detect_press_and_hover(mouse_cursor))
		{
			tutorial_window.close();
			return 0;
		}

		/*******************************************************************************************************************************************************/
		tutorial_window.clear(sf::Color::Blue); /* the argument to the clear call allows for color in the program */
		/*******************************************************************************************************************************************************/

		tutorial_window.draw(game_title);

		w_key.render_key_diagram(tutorial_window);
		a_key.render_key_diagram(tutorial_window);
		s_key.render_key_diagram(tutorial_window);
		d_key.render_key_diagram(tutorial_window);
		e_key.render_key_diagram(tutorial_window);

		i_key.render_key_diagram(tutorial_window);
		j_key.render_key_diagram(tutorial_window);
		k_key.render_key_diagram(tutorial_window);
		l_key.render_key_diagram(tutorial_window);
		u_key.render_key_diagram(tutorial_window);

		tutorial_window.draw(return_to_main_menu_button);
		tutorial_window.draw(return_to_main);

		tutorial_window.draw(right_instructions);
		tutorial_window.draw(right_instructions_w);
		tutorial_window.draw(right_instructions_a);
		tutorial_window.draw(right_instructions_s);
		tutorial_window.draw(right_instructions_d);
		tutorial_window.draw(right_instructions_e);

		tutorial_window.draw(left_instructions);
		tutorial_window.draw(left_instructions_i);
		tutorial_window.draw(left_instructions_j);
		tutorial_window.draw(left_instructions_k);
		tutorial_window.draw(left_instructions_l);
		tutorial_window.draw(left_instructions_u);

		/*******************************************************************************************************************************************************/
		tutorial_window.display();

	}

	return 0;

}

/*******************************************************************************************************************************************************************************/