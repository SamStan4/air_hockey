#pragma once

#include "air_hockey_GENERAL_HEADER.h"

class button : public sf::RectangleShape
{
private:

	sf::Color
		m_regular_color,
		m_hover_color;

public:

	button(const sf::Vector2f& new_position, const sf::Vector2f& new_size, const sf::Color& new_regular_color, const sf::Color& new_hover_color);

	button(const sf::Color& new_regular_color, const sf::Color& new_hover_color, const sf::Color& new_perimeter_color, const sf::Vector2f& new_position, const sf::Vector2f& new_size)
	{
		this->m_regular_color = new_regular_color;
		this->m_hover_color = new_hover_color;
		this->setOutlineColor(new_perimeter_color);
		this->setOutlineThickness(5);
		this->setPosition(new_position);
		this->setSize(new_size);
	}

	bool detect_press_and_hover(sf::CircleShape& mouse_cursor);

	void set_position(sf::Vector2f new_position);
};

/*******************************************************************************************************************************************************************************
	Function Call:        game_wrapper()
	Function description: this function is responsible for detecting button clicks
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */

bool button::detect_press_and_hover(sf::CircleShape& mouse_cursor)
{
	if (this->getGlobalBounds().intersects(mouse_cursor.getGlobalBounds()))
	{
		this->setFillColor(this->m_hover_color);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		this->setFillColor(this->m_regular_color);
		return false;
	}

}

/*******************************************************************************************************************************************************************************/

