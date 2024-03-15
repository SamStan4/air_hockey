#pragma once

#include "air_hockey_GENERAL_HEADER.h"
#include "edge_collider.h"

class circle_projectile : sf::CircleShape
{
protected:

	double
		m_x_velocity,
		m_y_velocity,
		m_mass;

public:

	circle_projectile(const sf::Vector2f& new_position, const float& new_radius, const float& new_mass, const sf::Color& new_color);

	virtual double get_x_velocity(void);

	virtual double get_y_velocity(void);

	virtual double get_mass(void);

	virtual void movement_input(const edge_collider& left_edge, const edge_collider& right_edge, const edge_collider& top_edge, const edge_collider& bottom_edge) = 0;

	virtual void movement_update(void) = 0;

	double get_velocity_magnitude(void);

	double get_momentum_magnitude(void);

	sf::Vector2f get_position(void);

	sf::Vector2f get_middle_position(void);

	virtual void render_projectile(sf::RenderWindow& window) = 0;

	sf::FloatRect get_global_bounds(void);

	void go_to(sf::Vector2f location);
	
	virtual void get_center_coordinate(float& x_coor, float& y_coor);

	void manual_move(sf::Vector2f movement_input);

	float get_Radius(void);

	float get_distance(sf::Vector2f otherPos);
};

/*******************************************************************************************************************************************************************************
	Function Call:        circle_projectile()
	Function description: this function is the default constructor for the circle_projectile class
	Function input(s):    sf::Vector2f, float, sf::Color
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */

circle_projectile::circle_projectile(const sf::Vector2f& new_position, const float& new_radius, const float& new_mass, const sf::Color& new_color)
{
	this->setPosition(new_position);
	this->setRadius(new_radius);
	this->setFillColor(new_color);
	this->m_mass = new_mass;

	this->m_x_velocity = 0;
	this->m_y_velocity = 0;
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_x_velocity()
	Function description: this function is the getter for the circle projectile x velocity data member
	Function input(s):    NONE
	Function output(s):   double
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

double circle_projectile::get_x_velocity(void)
{
	return this->m_x_velocity;
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_y_velocity()
	Function description: this function is the getter for the circle projectile y velocity data member
	Function input(s):    NONE
	Function output(s):   double
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

double circle_projectile::get_y_velocity(void)
{
	return this->m_y_velocity;
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_mass()
	Function description: this function is the getter for the circle projectile mass data member
	Function input(s):    NONE
	Function output(s):   double
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

double circle_projectile::get_mass(void)
{
	return this->m_mass;
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        movement_input()
	Function description: this function will determine the x and y velocity for all circular projectiles
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

void circle_projectile::movement_input(const edge_collider& left_edge, const edge_collider& right_edge, const edge_collider& top_edge, const edge_collider& bottom_edge)
{
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        movement_update()
	Function description: this function moves the circular projectile in the direction of the velocity, note I will need to override this for the puck as to limit the movement speed
	Function input(s):    NONE
	Function output(s):   double
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

void circle_projectile::movement_update(void)
{
		this->move(m_x_velocity, m_y_velocity);
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_velocity_magnitude()
	Function description: this function calculates and returns the magnitude of the circular projectile's velocity
	Function input(s):    NONE
	Function output(s):   double
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
	Formulas used:        | V(t) | = sqrt((x velocity)^2 + (y velocity)^2) <-- from Eric Remaley's calculus 3 class
																																											   */

double circle_projectile::get_velocity_magnitude(void)
{
	return sqrt(pow(this->m_x_velocity, 2) + pow(this->m_y_velocity, 2));
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_momentum_magnitude()
	Function description: this function calculates and returns the magnitude of the circular projectile's momentum
	Function input(s):    NONE
	Function output(s):   double
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
	Formulas used:        | m(t) | = | v(t) | * mass    <-- from John Schaub's engineering physics 1 class (highschool running start class at spscc)
																																											   */

double circle_projectile::get_momentum_magnitude(void)
{
	return sqrt(pow(this->m_x_velocity, 2) + pow(this->m_y_velocity, 2)) * this->m_mass;
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_position()
	Function description: this function returns the exact position of the mallet
	Function input(s):    NONE
	Function output(s):   sf::Vector2f
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley                                                                                                                               */

sf::Vector2f circle_projectile::get_position(void)
{
	int x_pos, y_pos;

	x_pos = this->getPosition().x; /* accounts for radius so exact center is returned */
	y_pos = this->getPosition().y;

	return sf::Vector2f(x_pos, y_pos);
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_middle_position()
	Function description: this function returns the exact position of the mallet
	Function input(s):    NONE
	Function output(s):   sf::Vector2f
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley                                                                                                                           */

sf::Vector2f circle_projectile::get_middle_position(void)
{
	int x_pos, y_pos;

	x_pos = this->getPosition().x + this->getRadius(); /* accounts for radius so exact center is returned */
	y_pos = this->getPosition().y + this->getRadius();

	return sf::Vector2f(x_pos, y_pos);
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_position()
	Function description: this function returns the exact position of the mallet
	Function input(s):    NONE
	Function output(s):   sf::Vector2f
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley                                                                                                                           */

void circle_projectile::render_projectile(sf::RenderWindow& window)
{
	window.draw(*this);
}


/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_global_bounds()
	Function description: this function returns the global bounds of the circle
	Function input(s):    NONE
	Function output(s):   sf::FloatRect
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley                                                                                                                           */

sf::FloatRect circle_projectile::get_global_bounds(void)
{
	return this->getGlobalBounds();
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        go_to()
	Function description: this function sets the position of the circular projectile
	Function input(s):    NONE
	Function output(s):   sf::Vector2f
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley                                                                                                                           */

void circle_projectile::go_to(sf::Vector2f location)
{
	this->setPosition(location);
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_center_coordinate()
	Function description: this function will find the center coordinate of the circle projectile
	Function input(s):    float& * 2
	Function output(s):   indirect
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/26/23
	Last edited:          4/26/23
	Programmer(s):        Samuel Stanley                                                                                                                           */

void circle_projectile::get_center_coordinate(float& x_coor, float& y_coor)
{
	x_coor = this->getPosition().x + this->getRadius();
	y_coor = this->getPosition().y + this->getRadius();
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        manual_move()
	Function description: this function will find manually move the object
	Function input(s):    sf::Vector2f
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/26/23
	Last edited:          4/26/23
	Programmer(s):        Samuel Stanley                                                                                                                           */

void circle_projectile::manual_move(sf::Vector2f movement_input)
{
	this->move(movement_input);
}

/*******************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************
	Function Call:        get_Radius()
	Function description: this function gets the radius of the projectile
	Function input(s):    NONE
	Function output(s):   float
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley                                                                                                                           */
float circle_projectile::get_Radius(void) {
	return this->getRadius();
}

/*******************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************
	Function Call:        get_distance()
	Function description: this function gets the distance between itself and a position
	Function input(s):    sf::Vector2f
	Function output(s):   float
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley                                                                                                                           */

float circle_projectile::get_distance(sf::Vector2f otherPos)
{
	float x_dist = this->get_middle_position().x - otherPos.x;
	float y_dist = this->get_middle_position().y - otherPos.y;

	return sqrt(pow(x_dist, 2) + pow(y_dist, 2));
}

/*******************************************************************************************************************************************************************************/




