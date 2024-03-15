#pragma once

#include "air_hockey_GENERAL_HEADER.h"

class key_diagram : sf::RectangleShape
{
private:

	int m_current_status;
	sf::Color m_default_color, m_clicked_color;
	sf::Text m_key;

public:

	key_diagram(const sf::Vector2f& new_position, const sf::Vector2f& new_size, const sf::Color& new_regular_color, const sf::Color& new_clicked, const sf::Color& new_perimeter, const string& key, const sf::Font& new_font);

	void render_key_diagram(sf::RenderWindow& window);

	void key_press_update(sf::Keyboard::Key detect_key);
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

key_diagram::key_diagram(const sf::Vector2f & new_position, const sf::Vector2f & new_size, const sf::Color & new_regular_color, const sf::Color & new_clicked, const sf::Color& new_perimeter, const string& key, const sf::Font& new_font)
	: sf::RectangleShape(new_size)
{
	this->setPosition(new_position);
	this->m_clicked_color = new_clicked;
	this->setFillColor(new_regular_color);
	this->m_default_color = new_regular_color;
	this->m_key.setString(key);
	this->setOutlineColor(new_perimeter);
	this->m_key.setFont(new_font);
	this->m_key.setPosition(new_position);
	this->m_key.setScale(1, 1);
	//this->m_key.setColor(new_perimeter);
	this->setOutlineThickness(5);
	this->m_key.move(4, -5);
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        render_key_diagram()
	Function description: this function draws the key diagram to the window
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */
void key_diagram::render_key_diagram(sf::RenderWindow& window)
{
	window.draw(*this);
	window.draw(this->m_key);
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        key_press_detect()
	Function description: this function detects if a key is pressed and then updates some stuff
	Function input(s):    sf::Keyboard
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */
void key_diagram::key_press_update(sf::Keyboard::Key detect_key)
{
	if (sf::Keyboard::isKeyPressed(detect_key))
	{
		this->setFillColor(this->m_clicked_color);
	}
	else
	{
		this->setFillColor(this->m_default_color);
	}
}

/*******************************************************************************************************************************************************************************/

