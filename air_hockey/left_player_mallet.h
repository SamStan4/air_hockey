#pragma once
#include "mallet.h"
#include "edge_collider.h"

class left_player_mallet : public mallet
{
public:

	left_player_mallet(const sf::Vector2f& new_position, const float& new_radius, const float& new_mass, const sf::Color& new_color);

	void movement_input(const edge_collider& left_edge, const edge_collider& right_edge, const edge_collider& top_edge, const edge_collider& bottom_edge) override;

	void movement_update(void) override;

	void render_projectile(sf::RenderWindow& window) override;

	sf::FloatRect get_left_global_bounds(void);

	double get_x_velocity(void);

	double get_y_velocity(void);

	double get_mass(void);

};

/*******************************************************************************************************************************************************************************
	Function Call:        left_player_mallet()
	Function description: this function is the default constructor for the left_player_mallet class
	Function input(s):    sf::Vector2f, float, float sf::Color
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

left_player_mallet::left_player_mallet(const sf::Vector2f& new_position, const float& new_radius, const float& new_mass, const sf::Color& new_color) : mallet(new_position, new_radius, new_mass, new_color)
{

}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        movement_input()
	Function description: this function is responsible for detecting keyboard input for the left player mallet
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

void left_player_mallet::movement_input(const edge_collider& left_edge, const edge_collider& right_edge, const edge_collider& top_edge, const edge_collider& bottom_edge)
{
	int multiplyer = 1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		cout << CYAN << "keyboard input detected (E)\n" << RESET << endl;
		multiplyer = 5;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
	{
		cout << CYAN << "keyboard input detected (W & S)\n" << RESET << endl;
		this->m_y_velocity = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		cout << CYAN << "keyboard input detected (W)\n" << RESET << endl;

		if (!this->get_mallet_global_bounds().intersects(top_edge.getGlobalBounds()))
		{
			this->m_y_velocity = -MALLET_MOVEMENT_SPEED * multiplyer;
		}
		else
		{
			cout << CYAN << "left player mallet touching top boundary\n" << RESET << endl;
			this->m_y_velocity = 0;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		cout << CYAN << "keyboard input detected (S)\n" << RESET << endl;

		if (!this->get_mallet_global_bounds().intersects(bottom_edge.getGlobalBounds()))
		{
			this->m_y_velocity = MALLET_MOVEMENT_SPEED * multiplyer;
		}
		else
		{
			cout << CYAN << "left player mallet touching bottom boundary\n" << RESET << endl;
			this->m_y_velocity = 0;
		}
	}
	else
	{
		this->m_y_velocity = 0;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
	{
		cout << CYAN << "keyboard input detected (A & D)\n" << RESET << endl;
		this->m_x_velocity = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		cout << CYAN << "keyboard input detected (A)\n" << RESET << endl;

		if (!this->get_mallet_global_bounds().intersects(left_edge.getGlobalBounds()))
		{
			this->m_x_velocity = -MALLET_MOVEMENT_SPEED * multiplyer;
		}
		else
		{
			cout << CYAN << "left player mallet touching left boundary\n" << RESET << endl;
			this->m_x_velocity = 0;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		cout << CYAN << "keyboard input detected (D)\n" << RESET << endl;

		if (!this->get_mallet_global_bounds().intersects(right_edge.getGlobalBounds()))
		{
			this->m_x_velocity = MALLET_MOVEMENT_SPEED * multiplyer;
		}
		else
		{
			cout << CYAN << "left player mallet touching middle boundary\n" << RESET << endl;
			this->m_x_velocity = 0;
		}
	}
	else
	{
		this->m_x_velocity = 0;
	}

	this->movement_update();
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        movement_update()
	Function description: this function moves the mallet
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

void left_player_mallet::movement_update(void)
{
	this->mallet::movement_update();
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        render_projectile()
	Function description: this function is responsible for drawing the mallet to the screen
	Function input(s):    sf::RenderWindow
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

void left_player_mallet::render_projectile(sf::RenderWindow& window)
{
	this->mallet::render_projectile(window);
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_left_global_bounds()
	Function description: this function returns the global bounds
	Function input(s):    NONE
	Function output(s):   sf::FloatRect
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

sf::FloatRect left_player_mallet::get_left_global_bounds(void)
{
	return this->get_global_bounds();
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_x_velocity()
	Function description: this function returns the x velocity data member
	Function input(s):    NONE
	Function output(s):   double
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

double left_player_mallet::get_x_velocity(void)
{
	return this->m_x_velocity;
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_y_velocity()
	Function description: this function returns the y velocity data member
	Function input(s):    NONE
	Function output(s):   double
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

double left_player_mallet::get_y_velocity(void)
{
	return this->m_y_velocity;
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_mass()
	Function description: this function returns the mass data member
	Function input(s):    NONE
	Function output(s):   double
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

double left_player_mallet::get_mass(void)
{
	return this->m_mass;
}

/*******************************************************************************************************************************************************************************/
