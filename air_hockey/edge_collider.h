#pragma once

#include "air_hockey_GENERAL_HEADER.h"

class edge_collider : public sf::RectangleShape
{
private:


public:

	edge_collider(const sf::Vector2f& new_size, const sf::Vector2f& new_position);

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

edge_collider::edge_collider(const sf::Vector2f& new_size, const sf::Vector2f& new_position)
{
	this->setSize(new_size);
	this->setPosition(new_position);
	//this->setFillColor(sf::Color::Transparent);
	this->setFillColor(sf::Color::Magenta);
}

/*******************************************************************************************************************************************************************************/

