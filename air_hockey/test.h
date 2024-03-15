#include "air_hockey_GENERAL_HEADER.h"
#include "networking_HEADER.h"
#include "air_hockey_game.h"
#include "main_menu.h"
#include "how_to_play.h"
#include "connect_two_computers.h"

#define NOT_TESTED_X 212
#define FAILED_X 230
#define PASSED_x 225

#define PASSED "passed"
#define FAILED "failed"

class test
{
private:

	bool
		button_test_result,
		goal_score_test_result,
		network_connection_result,
		movement_test_result,
		edge_collider_test_result,
		button_test_status,
		goal_score_test_status,
		network_connection_test_status,
		movement_test_status,
		edge_collider_test_status;

public:

	test();

	void test_reset(void);

	int test_hub(void);

	bool button_test(void);

	bool scoring_test(void);

	bool network_test(void); /* this is really a different test */

	bool movement_test(void);

	bool edge_collider_test(void);

};

/*******************************************************************************************************************************************************************************
	Function Call:        test()
	Function description: this function is the constructor for the test class, it does pretty much nothing
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/26/23
	Last edited:          4/26/23
	Programmer(s):        Samuel Stanley
																																											   */

test::test()
{
	this->button_test_result = false;
	this->goal_score_test_result = false;
	this->network_connection_result = false;
	this->movement_test_result = false;
	this->edge_collider_test_result = false;
	this->button_test_status = false;
	this->goal_score_test_status = false;
	this->network_connection_test_status = false;
	this->movement_test_status = false;
	this->edge_collider_test_status = false;

}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        test_reset()
	Function description: this function resets the private data members of the test class
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/26/23
	Last edited:          4/26/23
	Programmer(s):        Samuel Stanley
																																											   */

void test::test_reset(void)
{
	this->button_test_result = false;
	this->goal_score_test_result = false;
	this->network_connection_result = false;
	this->movement_test_result = false;
	this->edge_collider_test_result = false;
	this->button_test_status = false;
	this->goal_score_test_status = false;
	this->network_connection_test_status = false;
	this->movement_test_status = false;
	this->edge_collider_test_status = false;
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        test_hub()
	Function description: this function displays options for testing the programs
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/26/23
	Last edited:          4/26/23
	Programmer(s):        Samuel Stanley
																																											   */

int test::test_hub(void)
{

	sf::RenderWindow testing_window(sf::VideoMode(500, 500), "Air Hockey Test Hub");

	int button_hide = 0;
	button button_test_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 100), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));
	button goal_score_test_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 180), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));
	button network_connection_test_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 260), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));
	button movement_test_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 340), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));
	button edge_collider_test_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 420), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));
	button return_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(400, 460), sf::Vector2f(MM_BUTTON_X_SIZE / 3, MM_BUTTON_Y_SIZE / 3));
	sf::Mouse mouse;
	sf::CircleShape mouse_cursor(5.f);
	mouse_cursor.setFillColor(sf::Color::Magenta);
	mouse_cursor.setPosition(250, 250);
	sf::Font button_font, title_font;
	sf::Text test_button_text, test_goal_text, test_network_text, test_movement_text, test_edge_collider_text,
		test_button_status_text, test_goal_status_text, test_network_status_text, test_movement_status_text, test_edge_collider_status_text, return_text, title_text;

	if (!title_font.loadFromFile("fonts\\1up.ttf"))
	{
		cout << "title font loading error\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "title font successfully loaded\n" << RESET << endl;
		title_text.setFont(title_font);
		title_text.setString("Choose Tests");
		title_text.setPosition(25, 10);
		title_text.scale(1.5, 1.5);
	}


	if (!button_font.loadFromFile("fonts//AldotheApache.ttf"))
	{
		cout << "error loading button font\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "button font loaded successfully\n" << endl;

		/* font */
		test_button_text.setFont(button_font);
		test_goal_text.setFont(button_font);
		test_network_text.setFont(button_font);
		test_movement_text.setFont(button_font);
		test_edge_collider_text.setFont(button_font);
		test_button_status_text.setFont(button_font);
		test_goal_status_text.setFont(button_font);
		test_network_status_text.setFont(button_font);
		test_movement_status_text.setFont(button_font);
		test_edge_collider_status_text.setFont(button_font);
		return_text.setFont(button_font);

		/* location */
		test_button_text.setPosition(190, 95);
		test_goal_text.setPosition(190, 175);
		test_network_text.setPosition(175, 255);
		test_movement_text.setPosition(170, 335);
		test_edge_collider_text.setPosition(160, 415);
		test_button_status_text.setPosition(NOT_TESTED_X, 138);
		test_goal_status_text.setPosition(NOT_TESTED_X, 218);
		test_network_status_text.setPosition(NOT_TESTED_X, 298);
		test_movement_status_text.setPosition(NOT_TESTED_X, 378);
		test_edge_collider_status_text.setPosition(NOT_TESTED_X, 458);
		return_text.setPosition(420, 460);

		/* scale */
		test_button_text.scale(1.3, 1.3);
		test_goal_text.scale(1.3, 1.3);
		test_network_text.scale(1.3, 1.3);
		test_movement_text.scale(1.3, 1.3);
		test_edge_collider_text.scale(1.3, 1.3);
		test_button_status_text.scale(.5, .5);
		test_goal_status_text.scale(.5, .5);
		test_network_status_text.scale(.5, .5);
		test_movement_status_text.scale(.5, .5);
		test_edge_collider_status_text.scale(.5, .5);
		return_text.scale(.5, .5);

		/* actual text */
		test_button_text.setString("button");
		test_goal_text.setString("scoring");
		test_network_text.setString("key input");
		test_movement_text.setString("movement");
		test_edge_collider_text.setString("boundaries");
		test_button_status_text.setString("not tested");
		test_goal_status_text.setString("not tested");
		test_network_status_text.setString("not tested");
		test_movement_status_text.setString("not tested");
		test_edge_collider_status_text.setString("not tested");
		return_text.setString("return");

		test_button_status_text.setFillColor(sf::Color::White);
		test_goal_status_text.setFillColor(sf::Color::White);
		test_network_status_text.setFillColor(sf::Color::White);
		test_movement_status_text.setFillColor(sf::Color::White);
		test_edge_collider_status_text.setFillColor(sf::Color::White);
	}

	testing_window.setFramerateLimit(60);

	while (testing_window.isOpen())
	{
		sf::Event event;
		while (testing_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				testing_window.close();
			}
		}

		mouse_cursor.setPosition(mouse.getPosition(testing_window).x - mouse_cursor.getRadius(), mouse.getPosition(testing_window).y - mouse_cursor.getRadius()); /* ben made this */

		/* button stuff */

		if (return_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				button_hide = 0;
				testing_window.close();
				return 0;
			}
		}

		if (button_test_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				button_hide = 0;
				cout << GREEN << "button test initiated\n" << RESET << endl;
				this->button_test_result = button_test();
			}
		}

		if (goal_score_test_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				button_hide = 0;
				cout << GREEN << "goal test initiated\n" << RESET << endl;
				this->goal_score_test_result = scoring_test();
			}
		}

		if (network_connection_test_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				button_hide = 0;
				cout << GREEN << "network test initiated\n" << RESET << endl;
				this->network_connection_result = network_test();
			}
		}

		if (movement_test_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				button_hide = 0;
				cout << GREEN << "movement test initiated\n" << RESET << endl;
				this->movement_test_result = movement_test();
			}
		}

		if (edge_collider_test_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				button_hide = 0;
				cout << GREEN << "edge collider test initiated\n" << RESET << endl;
				this->edge_collider_test_result = edge_collider_test();
			}
		}

		/* test status stuff */


		if (this->button_test_status) /* true = tested */
		{
			if (this->button_test_result) /* true = passed */
			{
				test_button_status_text.setString(PASSED);
				test_button_status_text.setFillColor(sf::Color::Green);
				test_button_status_text.setPosition(PASSED_x, 138);
			}
			else /* false = failed */
			{
				test_button_status_text.setString(FAILED);
				test_button_status_text.setFillColor(sf::Color::Red);
				test_button_status_text.setPosition(FAILED_X, 138);
			}

			this->button_test_status = false; /* reset to false */
		}

		if (this->goal_score_test_status) /* true = tested */
		{
			if (this->goal_score_test_result) /* true = passed */
			{
				test_goal_status_text.setString(PASSED);
				test_goal_status_text.setFillColor(sf::Color::Green);
				test_goal_status_text.setPosition(PASSED_x, 218);
			}
			else /* false = failed */
			{
				test_goal_status_text.setString(FAILED);
				test_goal_status_text.setFillColor(sf::Color::Red);
				test_goal_status_text.setPosition(FAILED_X, 218);
			}

			this->goal_score_test_status = false; /* reset to false */
		}

		if (this->network_connection_test_status) /* true = tested */
		{
			if (this->network_connection_result) /* true = passed */
			{
				test_network_status_text.setString(PASSED);
				test_network_status_text.setFillColor(sf::Color::Green);
				test_network_status_text.setPosition(PASSED_x, 298);
			}
			else /* false = failed */
			{
				test_network_status_text.setString(FAILED);
				test_network_status_text.setFillColor(sf::Color::Red);
				test_network_status_text.setPosition(FAILED_X, 298);
			}

			this->network_connection_test_status = false; /* reset to false */
		}

		if (this->movement_test_status) /* true = tested */
		{
			if (this->movement_test_result) /* true = passed */
			{
				test_movement_status_text.setString(PASSED);
				test_movement_status_text.setFillColor(sf::Color::Green);
				test_movement_status_text.setPosition(PASSED_x, 378);
			}
			else /* false = failed */
			{
				test_movement_status_text.setString(FAILED);
				test_movement_status_text.setFillColor(sf::Color::Red);
				test_movement_status_text.setPosition(FAILED_X, 378);
			}

			this->movement_test_status = false; /* reset to false */
		}

		if (this->edge_collider_test_status) /* true = tested */
		{
			if (this->edge_collider_test_result) /* true = passed */
			{
				test_edge_collider_status_text.setString(PASSED);
				test_edge_collider_status_text.setFillColor(sf::Color::Green);
				test_edge_collider_status_text.setPosition(PASSED_x, 458);
			}
			else /* false = failed */
			{
				test_edge_collider_status_text.setString(FAILED);
				test_edge_collider_status_text.setFillColor(sf::Color::Red);
				test_edge_collider_status_text.setPosition(FAILED_X, 458);
			}

			this->edge_collider_test_status = false; /* reset to false */
		}


		/*******************************************************************************************************************************************************/
		testing_window.clear(sf::Color::Blue);
		/*******************************************************************************************************************************************************/

		testing_window.draw(button_test_button);
		testing_window.draw(goal_score_test_button);
		testing_window.draw(network_connection_test_button);
		testing_window.draw(movement_test_button);
		testing_window.draw(edge_collider_test_button);
		testing_window.draw(return_button);

		testing_window.draw(test_button_text);
		testing_window.draw(test_goal_text);
		testing_window.draw(test_network_text);
		testing_window.draw(test_movement_text);
		testing_window.draw(test_edge_collider_text);
		testing_window.draw(return_text);

		testing_window.draw(test_button_status_text);
		testing_window.draw(test_goal_status_text);
		testing_window.draw(test_network_status_text);
		testing_window.draw(test_movement_status_text);
		testing_window.draw(test_edge_collider_status_text);
		testing_window.draw(title_text);

		/*******************************************************************************************************************************************************/

		testing_window.display();

		if (button_hide < DELAY_NUMBER)
		{
			button_hide++;
		}
	}

	return 0;
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        button_test()
	Function description: this function will test the button functionality
	Function input(s):    NONE
	Function output(s):   bool
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/26/23
	Last edited:          4/26/23
	Programmer(s):        Samuel Stanley
																																											   */

bool test::button_test(void)
{
	/* if you were able to press the button to get here, the button worked lol*/
	this->button_test_status = true;
	return true;
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        scoring_test()
	Function description: this function will test the scoring functionality
	Function input(s):    NONE
	Function output(s):   bool
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/26/23
	Last edited:          4/26/23
	Programmer(s):        Samuel Stanley
																																											   */
bool test::scoring_test(void)
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

	button reset_puck_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(800, 573), sf::Vector2f(150, 30)),
		return_to_menu(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(975, 573), sf::Vector2f(150, 30));

	sf::Text return_to_menu_text, reset_puck_text, score_text;

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
		return_to_menu_text.setPosition(sf::Vector2f(998, 573));
		return_to_menu_text.scale(.75, .75);
		return_to_menu_text.setString("cancle test");

		reset_puck_text.setFont(button_font);
		reset_puck_text.setPosition(sf::Vector2f(823, 573));
		reset_puck_text.scale(.75, .75);
		reset_puck_text.setString("reset puck");

		score_text.setFont(button_font);
		score_text.setPosition(10, 573);
		score_text.scale(.75, .75);
		score_text.setString("score a goal!");
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

		left_player.movement_input(left_edge, right_edge, top_edge, bottom_edge);

		game_puck.collision_detection_update(left_edge, right_edge, top_edge, bottom_edge, left_player);

		game_puck.movement_update();

		if (return_to_menu.detect_press_and_hover(mouse_cursor))
		{
			this->goal_score_test_status = false;
			game_window.close();
			return false;
		}

		if (reset_puck_button.detect_press_and_hover(mouse_cursor))
		{
			game_puck.reset_puck();
		}

		if ((game_puck.check_for_goal(left_goal)) || (game_puck.check_for_goal(right_goal)))
		{
			this->goal_score_test_status = true;
			game_window.close();
			return true;
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

		game_puck.render_projectile(game_window);

		game_window.draw(return_to_menu);
		game_window.draw(return_to_menu_text);

		game_window.draw(reset_puck_button);
		game_window.draw(reset_puck_text);
		game_window.draw(score_text);

		/*******************************************************************************************************************************************************/

		game_window.display();

	}


	return false;
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        network_test()
	Function description: this function will test the network connection functionality
	Function input(s):    NONE
	Function output(s):   bool
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/26/23
	Last edited:          4/26/23
	Programmer(s):        Samuel Stanley
																																											   */
bool test::network_test(void)
{
	int button_hide = 0;
	sf::RenderWindow test_window(sf::VideoMode(500, 500), "Air Hockey Scoring Test");
	sf::Mouse mouse;
	sf::CircleShape mouse_cursor(5.f);
	sf::Font title_font, button_font;
	sf::Text press_text, return_text;
	mouse_cursor.setFillColor(sf::Color::Transparent);
	mouse_cursor.setPosition(250, 250);
	button return_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 300), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));


	if (!button_font.loadFromFile("fonts\\AldotheApache.ttf"))
	{
		cout << "main menu font loading error\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "button font successfully loaded\n" << RESET << endl;
		return_text.setFont(button_font);
		return_text.setPosition(140, 300);
		return_text.setString("cancle test");
		return_text.scale(1.5, 1.5);
	}

	if (!title_font.loadFromFile("fonts\\1up.ttf"))
	{
		cout << "title font loading error\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "title font successfully loaded\n" << RESET << endl;
		press_text.setFont(title_font);
		press_text.setPosition(80, 100);
		press_text.setString("press W");
		press_text.scale(2, 2);
	}

	test_window.setFramerateLimit(60);

	while (test_window.isOpen())
	{
		sf::Event event;
		while (test_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				test_window.close();
			}
		}

		/*******************************************************************************************************************************************************/

		mouse_cursor.setPosition(mouse.getPosition(test_window).x - mouse_cursor.getRadius(), mouse.getPosition(test_window).y - mouse_cursor.getRadius()); /* ben made this */

		if (return_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				test_window.close();
				return false;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			this->network_connection_test_status = true;
			test_window.close();
			return true;
		}

		/*******************************************************************************************************************************************************/
		test_window.clear(sf::Color::Blue); /* the argument to the clear call allows for color in the program */
		/*******************************************************************************************************************************************************/

		test_window.draw(return_button);
		test_window.draw(press_text);
		test_window.draw(return_text);

		/*******************************************************************************************************************************************************/
		test_window.display();

		if (button_hide < DELAY_NUMBER)
		{
			button_hide++;
		}
	}
	return false;
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        network_test()
	Function description: this function will test the game's movement functionality (using WASD)
	Function input(s):    NONE
	Function output(s):   bool
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/26/23
	Last edited:          4/26/23
	Programmer(s):        Samuel Stanley
																																											   */
bool test::movement_test(void)
{
	int button_hide = 0;
	sf::RenderWindow test_window(sf::VideoMode(500, 500), "Air Hockey Movement Test");
	sf::Mouse mouse;
	sf::CircleShape mouse_cursor(5.f);
	sf::Font title_font, button_font;
	sf::Text press_text, return_text, use_text;
	mouse_cursor.setFillColor(sf::Color::Transparent);
	mouse_cursor.setPosition(250, 250);
	button return_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(125, 400), sf::Vector2f(MM_BUTTON_X_SIZE, MM_BUTTON_Y_SIZE));
	sf::RectangleShape rectangle;
	left_player_mallet mallet(sf::Vector2f(215, 215), 35, MALLET_MASS, sf::Color::Transparent);
	edge_collider edge(sf::Vector2f(1, 1), sf::Vector2f(1000, 1000));

	rectangle.setSize(sf::Vector2f(200, 200));
	rectangle.setPosition(sf::Vector2f(150, 150));
	rectangle.setFillColor(sf::Color::Cyan);
	rectangle.setOutlineThickness(5);
	rectangle.setOutlineColor(sf::Color::Green);

	if (!button_font.loadFromFile("fonts\\AldotheApache.ttf"))
	{
		cout << "main menu font loading error\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "button font successfully loaded\n" << RESET << endl;
		use_text.setFont(button_font);
		use_text.setPosition(190, 125);
		use_text.setString("(use wasd to move)");
		use_text.scale(.5, .5);

		return_text.setFont(button_font);
		return_text.setPosition(140, 400);
		return_text.setString("cancle test");
		return_text.scale(1.5, 1.5);
	}

	if (!title_font.loadFromFile("fonts\\1up.ttf"))
	{
		cout << "title font loading error\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "title font successfully loaded\n" << RESET << endl;
		press_text.setFont(title_font);
		press_text.setPosition(30, 10);
		press_text.setString("   try to move\noutside the box");
		press_text.scale(1.25, 1.25);
	}

	test_window.setFramerateLimit(60);

	while (test_window.isOpen())
	{
		sf::Event event;
		while (test_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				test_window.close();
			}
		}

		/*******************************************************************************************************************************************************/

		mouse_cursor.setPosition(mouse.getPosition(test_window).x - mouse_cursor.getRadius(), mouse.getPosition(test_window).y - mouse_cursor.getRadius()); /* ben made this */

		if (return_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				test_window.close();
				this->movement_test_status = false;
				return false;
			}
		}

		if (!(mallet.get_mallet_global_bounds().intersects(rectangle.getGlobalBounds())))
		{
			test_window.close();
			this->movement_test_status = true;
			return true;
		}


		mallet.movement_input(edge, edge, edge, edge);

		/*******************************************************************************************************************************************************/
		test_window.clear(sf::Color::Blue); /* the argument to the clear call allows for color in the program */
		/*******************************************************************************************************************************************************/

		test_window.draw(return_button);
		test_window.draw(press_text);
		test_window.draw(return_text);
		test_window.draw(rectangle);
		mallet.render_projectile(test_window);
		test_window.draw(use_text);


		/*******************************************************************************************************************************************************/
		test_window.display();

		if (button_hide < DELAY_NUMBER)
		{
			button_hide++;
		}
	}
	return false;
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        edge_collider_test()
	Function description: this function will test the game's edge collider / bounds system
	Function input(s):    NONE
	Function output(s):   bool
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/26/23
	Last edited:          4/26/23
	Programmer(s):        Samuel Stanley
																																											   */
bool test::edge_collider_test(void)
{
	int button_hide = 0;
	sf::RenderWindow test_window(sf::VideoMode(500, 500), "Air Hockey Boundary Test");
	sf::Mouse mouse;
	sf::CircleShape mouse_cursor(5.f);
	sf::Font title_font, button_font;
	sf::Text press_text, return_text, use_text, done_text, try_it_message;
	mouse_cursor.setFillColor(sf::Color::Transparent);
	mouse_cursor.setPosition(250, 250);
	button return_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(270, 400), sf::Vector2f(MM_BUTTON_X_SIZE / 1.5, MM_BUTTON_Y_SIZE));
	button done_button(sf::Color::Cyan, sf::Color::Magenta, sf::Color::Green, sf::Vector2f(63, 400), sf::Vector2f(MM_BUTTON_X_SIZE / 1.5, MM_BUTTON_Y_SIZE));
	sf::RectangleShape rectangle;
	left_player_mallet mallet(sf::Vector2f(215, 215), 35, MALLET_MASS, sf::Color::Transparent);
	edge_collider left_wall(sf::Vector2f(10, 220), sf::Vector2f(140, 140)), right_wall(sf::Vector2f(10, 220), sf::Vector2f(350, 140)), top_wall(sf::Vector2f(220, 10), sf::Vector2f(140, 140)), bottom_wall(sf::Vector2f(220, 10), sf::Vector2f(140, 350));
	bool has_touched = false, message_sent = false;

	rectangle.setSize(sf::Vector2f(200, 200));
	rectangle.setPosition(sf::Vector2f(150, 150));
	rectangle.setFillColor(sf::Color::Cyan);
	rectangle.setOutlineThickness(5);
	rectangle.setOutlineColor(sf::Color::Green);


	if (!button_font.loadFromFile("fonts\\AldotheApache.ttf"))
	{
		cout << "main menu font loading error\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "button font successfully loaded\n" << RESET << endl;
		return_text.setFont(button_font);
		return_text.setPosition(273, 408);
		return_text.setString("cancle test");
		return_text.scale(1.10, 1.10);

		use_text.setFont(button_font);
		use_text.setPosition(190, 125);
		use_text.setString("(use wasd to move)");
		use_text.scale(.5, .5);

		done_text.setFont(button_font);
		done_text.setPosition(105, 400);
		done_text.setString("done");
		done_text.scale(1.5, 1.5);

		try_it_message.setFont(button_font);
		try_it_message.setPosition(90, 440);
		try_it_message.setString("TRY MOVING FIRST!");
		try_it_message.scale(.5, .5);
		try_it_message.setFillColor(sf::Color::Red);
	}

	if (!title_font.loadFromFile("fonts\\1up.ttf"))
	{
		cout << "title font loading error\n" << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "title font successfully loaded\n" << RESET << endl;
		press_text.setFont(title_font);
		press_text.setPosition(30, 10);
		press_text.setString("   try to move\noutside the box");
		press_text.scale(1.25, 1.25);
	}

	test_window.setFramerateLimit(60);

	while (test_window.isOpen())
	{
		sf::Event event;
		while (test_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				test_window.close();
			}
		}

		/*******************************************************************************************************************************************************/

		mouse_cursor.setPosition(mouse.getPosition(test_window).x - mouse_cursor.getRadius(), mouse.getPosition(test_window).y - mouse_cursor.getRadius()); /* ben made this */

		if (!has_touched) /* if there has been no edge collision */
		{
			if ((mallet.get_global_bounds().intersects(left_wall.getGlobalBounds())) || (mallet.get_global_bounds().intersects(right_wall.getGlobalBounds())) || (mallet.get_global_bounds().intersects(top_wall.getGlobalBounds())) || (mallet.get_global_bounds().intersects(bottom_wall.getGlobalBounds())))
			{
				has_touched = true;
			}
		}

		if (return_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				test_window.close();
				this->edge_collider_test_status = false;
				return false;
			}
		}

		if (done_button.detect_press_and_hover(mouse_cursor))
		{
			if (button_hide >= DELAY_NUMBER)
			{
				if (has_touched)
				{
					test_window.close();
					this->edge_collider_test_status = true;
					return true;
				}
				else
				{
					if (!message_sent)
					{
						message_sent = true;
						done_text.setPosition(sf::Vector2f(105, 390));
					}
				}
			}
		}

		if (!mallet.get_global_bounds().intersects(rectangle.getGlobalBounds()))
		{
			test_window.close();
			this->edge_collider_test_status = true;
			return false;
		}

		mallet.movement_input(left_wall, right_wall, top_wall, bottom_wall);

		/*******************************************************************************************************************************************************/
		test_window.clear(sf::Color::Blue); /* the argument to the clear call allows for color in the program */
		/*******************************************************************************************************************************************************/
		test_window.draw(rectangle);
		test_window.draw(return_button);
		test_window.draw(done_button);
		test_window.draw(press_text);
		test_window.draw(return_text);
		test_window.draw(use_text);
		mallet.render_projectile(test_window);
		test_window.draw(done_text);
		if (message_sent)
		{
			test_window.draw(try_it_message);
		}

		//test_window.draw(left_wall);
		//test_window.draw(right_wall);
		//test_window.draw(top_wall);
		//test_window.draw(bottom_wall);

		/*******************************************************************************************************************************************************/
		test_window.display();

		if (button_hide < DELAY_NUMBER)
		{
			button_hide++;
		}
	}
	return false;
}

/*******************************************************************************************************************************************************************************/



