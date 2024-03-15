#pragma once

#include "air_hockey_GENERAL_HEADER.h"
#include "networking_HEADER.h"
#include "button.h"
#include "edge_collider.h"
#include "left_player_mallet.h"
#include "right_player_mallet.h"
#include "puck.h"
#include "input_field.h"

class connect_two_computers
{
private:

	//sf::TcpSocket m_host_socket, m_guest_socket; /* just going to put this stuff in the actual functions */
	//sf::IpAddress m_ip_connection_address;
	//sf::TcpListener m_host_listener, m_guest_listener;
	//char m_connection_type, m_host_buffer[500], m_guest_buffer[500];
	//std::size_t m_recieved_bytes;

	sf::TcpSocket m_socket; /* just going to put this stuff in the actual functions */
	sf::IpAddress m_ip_connection_address;
	sf::TcpListener m_listener;
	char m_connection_type, m_buffer[500];
	std::size_t m_recieved_bytes;
	sf::Packet m_packet; /* for sending and recievint stuff */



	/* the host is going to be the left player, the client is going to be the right player*/

	int m_left_player_score, m_right_player_score;

public:

	connect_two_computers();

	int connection_engine(void);

	void get_network_connection(void);

	int host_engine(void);

	int guest_engine(void);

	bool send_code(void);

	bool get_code(void);

	string network_cipher_encryption(string input);

	string network_cipher_decryption(string input);

	bool make_guest_connection(void);

	bool make_host_connection(void);

	void reinitialize_data_members(void);

	void reset_network_configurations(void);

	void process_guest_input(int& x_input, int& y_input);
};

/*******************************************************************************************************************************************************************************
	Function Call:        connect_two_computers()
	Function description: this function will establish weather or not the person is going to be hosting or not
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

connect_two_computers::connect_two_computers()
{
	//this->m_ip_address = sf::IpAddress::getLocalAddress(); /* im not going to grab this right away */
	this->m_left_player_score = 0;
	this->m_right_player_score = 0;
	this->m_recieved_bytes = 0;
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        connection_engine()
	Function description: this function will function will be responsible for managing the game over a TCP socket connection
	Function input(s):    NONE
	Function output(s):   int
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */
int connect_two_computers::connection_engine(void)
{

	get_network_connection();

	if (this->m_connection_type != 'r')
	{
		if (this->m_connection_type == 'h') /* this person is the host */
		{
			cout << YELLOW << "host connection initiated\n" << RESET << endl;
			if (send_code()) /* creates an IP cipher */
			{
				host_engine();
			}
		}
		else if (this->m_connection_type == 'g') /* this person is the guest */
		{
			cout << YELLOW << "guest connection initiated" << RESET << endl;
			if (get_code()) /* enter an IP cipher */
			{
				if (make_guest_connection())
				{
					guest_engine();
				}
			}
		}
	}

	this->reset_network_configurations(); /* destroy all data */

	return 0; /* go back to main menu */
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        connection_engine()
	Function description: this function will function will be responsible for managing the game over a TCP socket connection
	Function input(s):    NONE
	Function output(s):   int
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */
void connect_two_computers::get_network_connection(void)
{
	//sleep(1000000000); /* so that the button is not accidentally pressed */

	sf::RenderWindow get_connection_window(sf::VideoMode(500, 500), "Air Hockey Status Menu");
	sf::Mouse mouse;
	sf::CircleShape mouse_cursor(5.f);
	sf::Font title_font, button_font;
	sf::Text title_text, host_text, guest_text, exit_text;
	button host_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 150), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));
	button guest_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 250), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));
	button exit_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 350), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));
	int button_hide = 0;


	mouse_cursor.setFillColor(sf::Color::Magenta);
	mouse_cursor.setPosition(250, 250);

	if (!button_font.loadFromFile("fonts\\AldotheApache.ttf"))
	{
		cout << "main menu font loading error\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "button font successfully loaded\n" << RESET << endl;
		
		host_text.setFont(button_font);
		guest_text.setFont(button_font);
		exit_text.setFont(button_font);

		host_text.setString("host");
		guest_text.setString("guest");
		exit_text.setString("exit");

		host_text.scale(sf::Vector2f(1.5, 1.5));
		guest_text.scale(sf::Vector2f(1.5, 1.5));
		exit_text.scale(sf::Vector2f(1.5, 1.5));

		host_text.setPosition(sf::Vector2f(210, 150));
		guest_text.setPosition(sf::Vector2f(200, 250));
		exit_text.setPosition(sf::Vector2f(215, 350));
	}

	if (!title_font.loadFromFile("fonts\\1up.ttf"))
	{
		cout << "title font loading error\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "title font successfully loaded\n" << RESET << endl;

		title_text.setFont(title_font);
		title_text.setString("Choose Status");
		title_text.scale(sf::Vector2f(1.5, 1.5));
		title_text.setPosition(sf::Vector2f(5, 30));

	}

	get_connection_window.setFramerateLimit(60);

	while (get_connection_window.isOpen())
	{
		sf::Event event;
		while (get_connection_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				get_connection_window.close();
			}
		}

		/*******************************************************************************************************************************************************/

		mouse_cursor.setPosition(mouse.getPosition(get_connection_window).x - mouse_cursor.getRadius(), mouse.getPosition(get_connection_window).y - mouse_cursor.getRadius()); /* ben made this */

		if (host_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				this->m_connection_type = 'h';
				get_connection_window.close();
				return;
			}
		}
		if (guest_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				this->m_connection_type = 'g';
				get_connection_window.close();
				return;
			}
		}
		if (exit_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				this->m_connection_type = 'r';
				get_connection_window.close();
				return;
			}
		}


		/*******************************************************************************************************************************************************/
		get_connection_window.clear(sf::Color::Blue);
		/*******************************************************************************************************************************************************/

		get_connection_window.draw(title_text);

		get_connection_window.draw(host_button);
		get_connection_window.draw(guest_button);
		get_connection_window.draw(exit_button);

		get_connection_window.draw(host_text);
		get_connection_window.draw(guest_text);
		get_connection_window.draw(exit_text);

		//get_connection_window.draw(mouse_cursor);

		/*******************************************************************************************************************************************************/
		get_connection_window.display();

		if (button_hide < DELAY_NUMBER)
		{
			button_hide++;
		}
	}

}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        host_engine()
	Function description: this function will function will drive the program if the user chooses to be the host (server side, does all of the calculations)
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        host connection is already established
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */
int connect_two_computers::host_engine(void)
{
	this->reinitialize_data_members();

	sf::RenderWindow game_window(sf::VideoMode(1138, 610), "Air Hockey Game");


	edge_collider
		top_edge(sf::Vector2f(1138, 15), sf::Vector2f(0, 0)),
		bottom_edge(sf::Vector2f(1138, 15), sf::Vector2f(0, 552)),
		left_edge(sf::Vector2f(15, 560), sf::Vector2f(0, 0)),
		right_edge(sf::Vector2f(15, 560), sf::Vector2f(1125, 0)),
		middle_edge(sf::Vector2f(5, 560), sf::Vector2f(567, 0)),
		left_goal(sf::Vector2f(15, 100), sf::Vector2f(0, 225)),
		right_goal(sf::Vector2f(15, 100), sf::Vector2f(1125, 225));

	int guest_player_x = 0, guest_player_y = 0;
	bool guest_reset_puck = false;

	sf::CircleShape mouse_cursor(5.f);
	mouse_cursor.setFillColor(sf::Color::Magenta);
	mouse_cursor.setPosition(250, 250);
	sf::Mouse mouse;

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

		/* PERFORME CALCULATOINS */
		mouse_cursor.setPosition(mouse.getPosition(game_window).x - mouse_cursor.getRadius(), mouse.getPosition(game_window).y - mouse_cursor.getRadius()); /* ben made this */


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

		/* SEND LOCATIONS OF THINGS TO GUEST */

		this->m_packet << left_player.get_position().x << left_player.get_position().y << right_player.get_position().x << right_player.get_position().y << game_puck.get_position().x << game_puck.get_position().y << this->m_left_player_score << this->m_right_player_score;

		this->m_socket.send(this->m_packet);

		this->m_packet.clear();

		this->m_socket.receive(m_packet);

		if (m_packet >> guest_player_x >> guest_player_y >> guest_reset_puck)
		{
			right_player.movement_input_network(middle_edge, right_edge, top_edge, bottom_edge, guest_player_x, guest_player_y);

			if (guest_reset_puck)
			{
				game_puck.reset_puck();
			}
		}

		left_player.movement_input(left_edge, middle_edge, top_edge, bottom_edge);

		this->m_packet.clear();

		/*******************************************************************************************************************************************************/
		game_window.clear(sf::Color::Blue);
		/*******************************************************************************************************************************************************/

		/* DRAW THINGS */
		game_window.draw(arena_sprite);

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

		/* RECIEVE INPUT FROM GUEST */

	}

	return 0;
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        guest_engine()
	Function description: this function will function will drive the program if the user chooses to be the guest (client side)
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        guest connection is already established
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */
int connect_two_computers::guest_engine(void)
{
	this->reinitialize_data_members();

	sf::RenderWindow game_window(sf::VideoMode(1138, 610), "Air Hockey Game");


	sf::CircleShape mouse_cursor(5.f);
	mouse_cursor.setFillColor(sf::Color::Magenta);
	mouse_cursor.setPosition(250, 250);
	sf::Mouse mouse;
	float left_player_x = 285, left_player_y = 305, right_player_x = 853, right_player_y = 305, game_puck_x = 459, game_puck_y = 270;
	int x_return_velocity = 0, y_return_velocity = 0;
	bool reset_return = false;

	sf::Texture puck_texture, mallet_texture;
	sf::Sprite left_player_sprite, right_player_sprite, game_puck_sprite;

	if (!puck_texture.loadFromFile("images\\puck.png"))
	{
		cout << RED << "error loading puck texture\n" << RESET << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "puck texture loaded successfully\n" << RESET << endl;
		game_puck_sprite.setTexture(puck_texture);
		game_puck_sprite.setScale(1.3, 1.3);
		game_puck_sprite.setPosition(sf::Vector2f(game_puck_x, game_puck_y));
	}

	if (!mallet_texture.loadFromFile("images/redMallet.png"))
		//if (!mallet_texture.loadFromFile("images/puck.png"))
	{
		cout << RED << "error loading mallet texture\n" << RESET << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "mallet texture loaded successfully\n" << RESET << endl;
		right_player_sprite.setTexture(mallet_texture);
		right_player_sprite.setScale(2.2, 2.2);
		right_player_sprite.setPosition(sf::Vector2f(right_player_x, right_player_y));
		left_player_sprite.setTexture(mallet_texture);
		left_player_sprite.setScale(2.2, 2.2);
		left_player_sprite.setPosition(sf::Vector2f(left_player_x, left_player_x));
	}

	button reset_puck_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(800, 573), sf::Vector2f(150, 30)),
		return_to_menu(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(975, 573), sf::Vector2f(150, 30));

	sf::Text return_to_menu_text, reset_puck_text, left_player_text, right_player_text, left_player_score_text, right_player_score_text;

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

		if (return_to_menu.detect_press_and_hover(mouse_cursor))
		{
			this->m_left_player_score = this->m_right_player_score = 0;
			game_window.close();
			return 0;
		}

		if (reset_puck_button.detect_press_and_hover(mouse_cursor))
		{
			reset_return = true;
		}
		else
		{
			reset_return = false;
		}

		this->m_socket.receive(this->m_packet);

		if (this->m_packet >> left_player_x >> left_player_y >> right_player_x >> right_player_y >> game_puck_x >> game_puck_y >> this->m_left_player_score >> this->m_right_player_score)
		{
			left_player_sprite.setPosition(sf::Vector2f(left_player_x, left_player_y));
			right_player_sprite.setPosition(sf::Vector2f(right_player_x, right_player_y));
			game_puck_sprite.setPosition(sf::Vector2f(game_puck_x, game_puck_y));
		}
		
		this->m_packet.clear();

		process_guest_input(x_return_velocity, y_return_velocity);

		this->m_packet << x_return_velocity << y_return_velocity << reset_return;

		this->m_socket.send(this->m_packet);

		this->m_packet.clear();

		left_player_score_text.setString(to_string(this->m_left_player_score));
		right_player_score_text.setString(to_string(this->m_right_player_score));

		/*******************************************************************************************************************************************************/
		game_window.clear(sf::Color::Blue);
		/*******************************************************************************************************************************************************/

		/* DRAW THINGS */
		game_window.draw(arena_sprite);

		game_window.draw(return_to_menu);
		game_window.draw(return_to_menu_text);

		game_window.draw(reset_puck_button);
		game_window.draw(reset_puck_text);

		game_window.draw(left_player_text);
		game_window.draw(left_player_score_text);

		game_window.draw(right_player_text);
		game_window.draw(right_player_score_text);

		game_window.draw(left_player_sprite);
		game_window.draw(right_player_sprite);
		game_window.draw(game_puck_sprite);


		/*******************************************************************************************************************************************************/

		game_window.display();


	}
	this->m_left_player_score = this->m_right_player_score = 0;

	return 0;
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        send_code()
	Function description: this function will prompt the user to send a connection code to the other player
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */
bool connect_two_computers::send_code(void)
{
	sf::RenderWindow send_code_window(sf::VideoMode(500, 500), "Air Hockey Send code");
	sf::Mouse mouse;
	sf::CircleShape mouse_cursor(5.f);
	string IP_string;
	sf::IpAddress f_ip_address = sf::IpAddress::getLocalAddress();
	sf::Font title_font, button_font;
	sf::Text title_text, code_text, waiting_text, make_connection_text, exit_text;
	button make_connection_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 250), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));
	button exit_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 350), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));


	IP_string = f_ip_address.toString();
	IP_string = network_cipher_encryption(IP_string);

	if (!title_font.loadFromFile("fonts\\1up.ttf"))
	{
		cout << "title font loading error\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "title font successfully loaded\n" << RESET << endl;
		title_text.setFont(title_font);
		title_text.setPosition(sf::Vector2f(90, 10));
		title_text.setString("send code");
		title_text.scale(sf::Vector2f(1.5, 1.5));
	}

	if (!button_font.loadFromFile("fonts\\AldotheApache.ttf"))
	{
		cout << "main menu font loading error\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "button font successfully loaded\n" << RESET << endl;
		code_text.setFont(button_font);
		code_text.setPosition(sf::Vector2f(120, 100));
		code_text.setString("code: " + IP_string);
		code_text.scale(sf::Vector2f(1, 1));

		waiting_text.setFont(button_font);
		waiting_text.setPosition(sf::Vector2f(150, 200));
		waiting_text.setString("(click make connection when guest\nis finished entering the code)");
		waiting_text.scale(sf::Vector2f(.5, .5));

		make_connection_text.setFont(button_font);
		make_connection_text.setPosition(sf::Vector2f(150, 260));
		make_connection_text.setString("make connection");
		make_connection_text.scale(sf::Vector2f(1, 1));

		exit_text.setFont(button_font);
		exit_text.setPosition(sf::Vector2f(215, 350));
		exit_text.setString("exit");
		exit_text.scale(sf::Vector2f(1.5, 1.5));
	}



	mouse_cursor.setFillColor(sf::Color::Magenta);
	mouse_cursor.setPosition(250, 250);

	send_code_window.setFramerateLimit(60);

	while (send_code_window.isOpen())
	{
		sf::Event event;
		while (send_code_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				send_code_window.close();
			}
		}

		/*******************************************************************************************************************************************************/

		mouse_cursor.setPosition(mouse.getPosition(send_code_window).x - mouse_cursor.getRadius(), mouse.getPosition(send_code_window).y - mouse_cursor.getRadius()); /* ben made this */

		if (make_connection_button.detect_press_and_hover(mouse_cursor)) /* make the connection */
		{
			send_code_window.close();
			return make_host_connection();
		}
		
		if (exit_button.detect_press_and_hover(mouse_cursor))
		{
			return false;
		}

		/*******************************************************************************************************************************************************/
		send_code_window.clear(sf::Color::Blue);
		/*******************************************************************************************************************************************************/

		send_code_window.draw(title_text);
		send_code_window.draw(code_text);
		send_code_window.draw(waiting_text);

		send_code_window.draw(make_connection_button);
		send_code_window.draw(exit_button);

		send_code_window.draw(make_connection_text);
		send_code_window.draw(exit_text);

		/*******************************************************************************************************************************************************/

		send_code_window.display();
	}

	return false;
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_code()
	Function description: this function will prompt the user to ender a code given to them from the other player
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */
bool connect_two_computers::get_code(void)
{
	sf::RenderWindow get_code_window(sf::VideoMode(500, 500), "Air Hockey Get code");
	sf::Mouse mouse;
	sf::CircleShape mouse_cursor(5.f);
	input_field f_input_field(sf::Vector2f(240, 200));
	sf::Text title_text, type_text, enter_text, exit_text;
	sf::Font title_font, button_font;
	button enter_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 300), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));
	button exit_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 400), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));
	int button_hide = 0;
	string IP_string;

	this->m_socket.setBlocking(true);

	if (!title_font.loadFromFile("fonts\\1up.ttf"))
	{
		cout << "title font loading error\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "title font successfully loaded\n" << RESET << endl;

		title_text.setFont(title_font);
		title_text.setString("Enter Code \nFrom Host");
		title_text.scale(sf::Vector2f(1.5, 1.5));
		title_text.setPosition(sf::Vector2f(70, 10));

	}

	if (!button_font.loadFromFile("fonts\\AldotheApache.ttf"))
	{
		cout << "main menu font loading error\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "button font successfully loaded\n" << RESET << endl;
		type_text.setFont(button_font);
		type_text.setString("(start typing)");
		type_text.scale(sf::Vector2f(.5, .5));
		type_text.setPosition(sf::Vector2f(195, 150));

		enter_text.setFont(button_font);
		enter_text.setString("enter");
		enter_text.scale(sf::Vector2f(1.5, 1.5));
		enter_text.setPosition(sf::Vector2f(200, 300));

		exit_text.setFont(button_font);
		exit_text.setString("exit");
		exit_text.scale(sf::Vector2f(1.5, 1.5));
		exit_text.setPosition(sf::Vector2f(220, 400));
	}


	mouse_cursor.setFillColor(sf::Color::Magenta);
	mouse_cursor.setPosition(250, 250);

	get_code_window.setFramerateLimit(60);

	while (get_code_window.isOpen())
	{
		sf::Event event;
		while (get_code_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				get_code_window.close();
				return false;
			}
		}

		/*******************************************************************************************************************************************************/

		mouse_cursor.setPosition(mouse.getPosition(get_code_window).x - mouse_cursor.getRadius(), mouse.getPosition(get_code_window).y - mouse_cursor.getRadius()); /* ben made this */

		f_input_field.input_field_update();

		if (enter_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				IP_string = network_cipher_decryption(f_input_field.get_string_contents());

				IP_string = IP_string.substr(1, IP_string.size() - 1);

				this->m_ip_connection_address = IP_string;

				get_code_window.close();
				return true;
			}
		}

		if (exit_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				get_code_window.close();
				return false;
			}
		}

		/*******************************************************************************************************************************************************/
		get_code_window.clear(sf::Color::Blue);
		/*******************************************************************************************************************************************************/

		f_input_field.render_input_field(get_code_window);

		get_code_window.draw(enter_button);
		get_code_window.draw(exit_button);

		get_code_window.draw(title_text);
		get_code_window.draw(type_text);
		get_code_window.draw(enter_text);
		get_code_window.draw(exit_text);

		/*******************************************************************************************************************************************************/

		get_code_window.display();

		if (button_hide < DELAY_NUMBER)
		{
			button_hide++;
		}
	}

}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        network_cipher_encryption()
	Function description: this function will use a simple cipher to encode the IP address
	Function input(s):    std::string
	Function output(s):   std::string
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */
string connect_two_computers::network_cipher_encryption(string input)
{
	string encode_string;

	for (int i = 0; input[i] != '\0'; ++i)
	{
		if (input[i] != '.')
		{
			encode_string += (input[i] + 17); /* converts numbers to uppercase letters */
		}
		else
		{
			encode_string += 'Z';
		}
	}

	return encode_string;
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        network_cipher_decryption()
	Function description: this function will use a simple cipher to decode the IP address
	Function input(s):    std::string
	Function output(s):   std::string
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */
string connect_two_computers::network_cipher_decryption(string input)
{
	string decode_string;

	for (int i = 0; input[i] != '\0'; ++i)
	{
		if (input[i] != 'Z')
		{
			decode_string += (input[i] - 17); /* converts numbers to uppercase letters */
		}
		else
		{
			decode_string += '.';
		}
	}

	return decode_string;
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        make_guest_connection()
	Function description: this function will connect the guest to the system
	Function input(s):    NONE
	Function output(s):   bool
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */
bool connect_two_computers::make_guest_connection(void)
{
	string test_string, compare_string = SUCCESS;
	//sf::Packet 

	this->m_socket.connect(this->m_ip_connection_address, SOCKET_PORT);

	//while (this->m_socket.isBlocking()); /* wait here while this socket is blocked */

	this->m_packet << compare_string;

	this->m_socket.send(this->m_packet);

	this->m_socket.receive(this->m_packet);

	this->m_packet >> test_string;

	cout << "CONNECTION TEST RESULT: " << test_string << endl;

	if (test_string == compare_string)
	{
		cout << MAGENTA << "GUEST CONNECTION ESTABLISHED\n" << endl;
		/****** remove later *******/
		//system("pause");
		/*************/
		return true;
	}
	else
	{
		cout << RED << "GUEST CONNECTION FAILED\n" << RESET << endl;
		system("pause");
		return false;
	}
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        make_host_connection()
	Function description: this function will connect the host to the guest
	Function input(s):    NONE
	Function output(s):	  bool
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */
bool connect_two_computers::make_host_connection(void)
{
	string test_string, compare_string = SUCCESS;

	this->m_listener.listen(SOCKET_PORT);
	this->m_listener.accept(this->m_socket);

	this->m_socket.setBlocking(false); /* unblock this port */

	this->m_ip_connection_address = this->m_socket.getRemoteAddress();

	this->m_socket.receive(this->m_packet);

	if (this->m_packet >> test_string)
	{
		cout << "SOMETHING IS IN THE PACKET" << endl;
	}
	else
	{
		cout << "NOTHING IS HERE" << endl;
	}

	//this->m_recieving_packet >> test_string;

	cout << MAGENTA << "TEST STRING: " << test_string << endl << endl;

	this->m_packet << test_string;

	this->m_socket.send(this->m_packet);

	cout << "CONNECTION TEST RESULT: " << test_string << endl;

	if (test_string == compare_string)
	{
		cout << MAGENTA << "HOST CONNECTION ESTABLISHED\n" << endl;
		/****** remove later *******/
		//system("pause");
		/*************/
		return true;
	}
	else
	{
		cout << RED << "HOST CONNECTION FAILED\n" << RESET << endl;
		system("pause");
		return false;
	}
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        reinitialize_data_members()
	Function description: this function will reinitialize the class data members that are changed very often
	Function input(s):    NONE
	Function output(s):	  NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */
void connect_two_computers::reinitialize_data_members(void)
{
	for (int i = 0; (i < BUFFER_SIZE) && (this->m_buffer[i] != '\0'); ++i)
	{
		this->m_buffer[i] = '\0'; /* reset the c string to null string */
	}

	this->m_recieved_bytes = 0;
	this->m_packet.clear();
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        reset_network_configurations()
	Function description: this function will reset all data members of this class
	Function input(s):    NONE
	Function output(s):	  NONE
	Preconditions:        IP and other atributes no longer needed
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */
void connect_two_computers::reset_network_configurations(void)
{

	this->m_socket.disconnect();
	this->m_ip_connection_address = sf::IpAddress::None;
	this->m_listener.close();
	this->m_connection_type = '\0';
	
	reinitialize_data_members();
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        process_guest_input()
	Function description: this function will figure out what input to return to the host computer
	Function input(s):    int&, int&, bool&;
	Function output(s):	  NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */
void connect_two_computers::process_guest_input(int& x_input, int& y_input)
{
	int multiplyer = 1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
	{
		multiplyer = 5;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && (sf::Keyboard::isKeyPressed(sf::Keyboard::L)))
	{
		x_input = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		x_input = -MALLET_MOVEMENT_SPEED * multiplyer;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		x_input = MALLET_MOVEMENT_SPEED * multiplyer;
	}
	else
	{
		x_input = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && (sf::Keyboard::isKeyPressed(sf::Keyboard::K)))
	{
		y_input = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		y_input = -MALLET_MOVEMENT_SPEED * multiplyer;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		y_input = MALLET_MOVEMENT_SPEED * multiplyer;
	}
	else
	{
		y_input = 0;
	}
}

/*******************************************************************************************************************************************************************************/






