#pragma once

#include "circle_projectile.h"
#include "left_player_mallet.h"
#include "right_player_mallet.h"

class puck : public circle_projectile
{
private:

	sf::Texture puck_texture;
	sf::Sprite puck_sprite;
	int radius;

public:

	puck(const sf::Vector2f& new_position, const float& new_radius, const float& new_mass, const sf::Color& new_color);

	void movement_input(const edge_collider& left_edge, const edge_collider& right_edge, const edge_collider& top_edge, const edge_collider& bottom_edge) override;

	void movement_update(void) override;

	void render_projectile(sf::RenderWindow& window) override;

	void collision_detection_update(const edge_collider& left_edge, const edge_collider& right_edge, const edge_collider& top_edge, const edge_collider& bottom_edge, left_player_mallet& left_player, right_player_mallet& right_player);

	void collision_detection_update(const edge_collider& left_edge, const edge_collider& right_edge, const edge_collider& top_edge, const edge_collider& bottom_edge, left_player_mallet& left_player);

	void reset_puck(void);

	bool check_for_goal(const edge_collider& goal);

	float calculate_distance(const float& x_one, const float& y_one, const float& x_two, const float& y_two);

};

/*******************************************************************************************************************************************************************************
	Function Call:        puck()
	Function description: this function is the default constructor for the puck class
	Function input(s):    sf::Vector2f, float, float sf::Color
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

puck::puck(const sf::Vector2f& new_position, const float& new_radius, const float& new_mass, const sf::Color& new_color) : circle_projectile(new_position, new_radius, new_mass, new_color)
{

	//if (!puck_texture.loadFromFile("images\\redMallet.png"))
	if (!puck_texture.loadFromFile("images\\puck.png"))
	{
		cout << RED << "error loading puck texture\n" << RESET << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "puck texture loaded successfully\n" << RESET << endl;
		this->puck_sprite.setTexture(puck_texture);
		this->puck_sprite.setScale(1.3, 1.3);
	}

	this->radius = new_radius;
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        movement_input()
	Function description: this honestly wasnt needed for this class, I just needed to override it
	Function input(s):    edge_collider(s)
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

void puck::movement_input(const edge_collider& left_edge, const edge_collider& right_edge, const edge_collider& top_edge, const edge_collider& bottom_edge)
{
	/* nothing in here */
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        movement_input()
	Function description: this honestly wasnt needed for this class, I just needed to override it
	Function input(s):    edge_collider(s) two mallets
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley and help from Ben Olsen
	Equations:            new velocity (x or y) = (2 * m2 * v2 + [v1 * (m1 - m2)]) / (m1 + m2) <-- from John Schaub's physics class (highschool running start at spscc)
																																											   */

void puck::collision_detection_update(const edge_collider& left_edge, const edge_collider& right_edge, const edge_collider& top_edge, const edge_collider& bottom_edge, left_player_mallet& left_player, right_player_mallet& right_player)
{
	/* deal with mallets first */

	float left_player_x = 0, left_player_y = 0, right_player_x = 0, right_player_y = 0, puck_x = 0, puck_y = 0, left_player_puck_distance = 0, right_player_puck_distance = 0, minimum_left_distance = 0, minimum_right_distance = 0;
	bool m_value_left = false, m_value_right = false;

	left_player.get_center_coordinate(left_player_x, left_player_y);
	right_player.get_center_coordinate(right_player_x, right_player_y);
	this->get_center_coordinate(puck_x, puck_y);

	left_player_puck_distance = calculate_distance(puck_x, puck_y, left_player_x, left_player_y);
	right_player_puck_distance = calculate_distance(puck_x, puck_y, right_player_x, right_player_y);

	minimum_left_distance = this->radius + left_player.get_radius();
	minimum_right_distance = this->radius + right_player.get_radius();

	//if (this->get_global_bounds().intersects(left_player.get_global_bounds()))
	if (left_player_puck_distance <= minimum_left_distance)
	{
		/*cout << RED << "left player and puck collision detected\n" << RESET << endl;
		this->m_x_velocity = ((2 * left_player.get_mass() * left_player.get_x_velocity()) + (this->m_x_velocity * (this->m_mass - left_player.get_mass()))) / (this->m_mass + left_player.get_mass());
		this->m_y_velocity = ((2 * left_player.get_mass() * left_player.get_y_velocity()) + (this->m_y_velocity * (this->m_mass - left_player.get_mass()))) / (this->m_mass + left_player.get_mass());
		m_value_left = true;*/
		
		if (this->get_Radius() + left_player.get_Radius() >= this->get_distance(left_player.get_middle_position())) 
		{
			if (left_player.get_puck_collision_bool() == false) 
			{
				cout << RED << "left player and puck collision detected\n" << RESET << endl;

				float contactLine;
				float velLine;
				sf::Vector2f tanLine(left_player.get_middle_position().x - this->get_middle_position().x, left_player.get_middle_position().y - this->get_middle_position().y);

				float x_dir = -tanLine.x / abs(tanLine.x);
				float y_dir = -tanLine.y / abs(tanLine.y);
				float temp_x = ((2 * left_player.get_mass() * left_player.get_x_velocity()) + (this->m_x_velocity * (this->m_mass - left_player.get_mass()))) / (this->m_mass + left_player.get_mass()) * pow((left_player.get_middle_position().x - this->get_middle_position().x) / 55, 2);
				float temp_y = ((2 * left_player.get_mass() * left_player.get_y_velocity()) + (this->m_y_velocity * (this->m_mass - left_player.get_mass()))) / (this->m_mass + left_player.get_mass()) * pow((left_player.get_middle_position().y - this->get_middle_position().y) / 55, 2);
				if (abs(x_dir) != 1) 
				{
					this->m_x_velocity = sqrt(pow(temp_x, 2) + pow(temp_y, 2)) * abs(tanLine.x) / 55;
				}
				else 
				{
					this->m_x_velocity = sqrt(pow(temp_x, 2) + pow(temp_y, 2)) * abs(tanLine.x) / 55 * x_dir;
				}
				if (abs(y_dir) != 1) 
				{
					this->m_y_velocity = sqrt(pow(temp_x, 2) + pow(temp_y, 2)) * abs(tanLine.y) / 55;
				}
				else 
				{
					this->m_y_velocity = sqrt(pow(temp_x, 2) + pow(temp_y, 2)) * abs(tanLine.y) / 55 * y_dir;
				}


				left_player.set_puck_collision_bool(true);
			}
		}
		else 
		{
			left_player.set_puck_collision_bool(false);
		}
	}
	else 
	{
		left_player.set_puck_collision_bool(false);
	}

	//if (this->get_global_bounds().intersects(right_player.get_global_bounds()))
	if (right_player_puck_distance <= minimum_right_distance)
	{
		/*cout << RED << "right player and puck collision detected\n" << RESET << endl;
		this->m_x_velocity = ((2 * right_player.get_mass() * right_player.get_x_velocity()) + (this->m_x_velocity * (this->m_mass - right_player.get_mass()))) / (this->m_mass + right_player.get_mass());
		this->m_y_velocity = ((2 * right_player.get_mass() * right_player.get_y_velocity()) + (this->m_y_velocity * (this->m_mass - right_player.get_mass()))) / (this->m_mass + right_player.get_mass());
		m_value_right = true;*/
		
		if (this->get_Radius() + right_player.get_Radius() >= this->get_distance(right_player.get_middle_position())) 
		{
			if (right_player.get_puck_collision_bool() == false)
			{
				cout << RED << "left player and puck collision detected\n" << RESET << endl;
				float contactLine;
				float velLine;
				sf::Vector2f tanLine(right_player.get_middle_position().x - this->get_middle_position().x, right_player.get_middle_position().y - this->get_middle_position().y);
				float x_dir = -tanLine.x / abs(tanLine.x);
				float y_dir = -tanLine.y / abs(tanLine.y);
				float temp_x = ((2 * right_player.get_mass() * right_player.get_x_velocity()) + (this->m_x_velocity * (this->m_mass - right_player.get_mass()))) / (this->m_mass + right_player.get_mass()) * pow((right_player.get_middle_position().x - this->get_middle_position().x) / 55, 2);
				float temp_y = ((2 * right_player.get_mass() * right_player.get_y_velocity()) + (this->m_y_velocity * (this->m_mass - right_player.get_mass()))) / (this->m_mass + right_player.get_mass()) * pow((right_player.get_middle_position().y - this->get_middle_position().y) / 55, 2);
			if (abs(x_dir) != 1) 
			{
				this->m_x_velocity = sqrt(pow(temp_x, 2) + pow(temp_y, 2)) * abs(tanLine.x) / 55;
			}
			else 
			{
				this->m_x_velocity = sqrt(pow(temp_x, 2) + pow(temp_y, 2)) * abs(tanLine.x) / 55 * x_dir;
			}
			if (abs(y_dir) != 1) 
			{
				this->m_y_velocity = sqrt(pow(temp_x, 2) + pow(temp_y, 2)) * abs(tanLine.y) / 55;
			}
			else 
			{
				this->m_y_velocity = sqrt(pow(temp_x, 2) + pow(temp_y, 2)) * abs(tanLine.y) / 55 * y_dir;
			}
				right_player.set_puck_collision_bool(true);
			}
		}
		else 
		{
				right_player.set_puck_collision_bool(false);
		}
		
	}
	else
	{
		right_player.set_puck_collision_bool(false);
	}


	/* deal with walls */

	if (this->get_global_bounds().intersects(left_edge.getGlobalBounds()))
	{
		cout << RED << "left wall collision detected\n" << RESET << endl;

		if (this->m_x_velocity < 0)
		{
			this->m_x_velocity *= -1;
		}
	}
	else if (m_value_left)
	{
		this->manual_move(sf::Vector2f(((puck_x - left_player_x) / left_player_puck_distance), (puck_y - left_player_y) / left_player_puck_distance));
	}
	else if (m_value_right)
	{
		this->manual_move(sf::Vector2f(((puck_x - right_player_x) / right_player_puck_distance), (puck_y - right_player_y) / right_player_puck_distance));
	}

	if (this->get_global_bounds().intersects(right_edge.getGlobalBounds()))
	{
		cout << RED << "right wall collision detected\n" << RESET << endl;

		if (this->m_x_velocity > 0)
		{
			this->m_x_velocity *= -1;
		}
	}
	else if (m_value_left)
	{
		this->manual_move(sf::Vector2f(((puck_x - left_player_x) / left_player_puck_distance), (puck_y - left_player_y) / left_player_puck_distance));
	}
	else if (m_value_right)
	{
		this->manual_move(sf::Vector2f(((puck_x - right_player_x) / right_player_puck_distance), (puck_y - right_player_y) / right_player_puck_distance));
	}


	if (this->get_global_bounds().intersects(top_edge.getGlobalBounds()))
	{
		cout << RED << "top wall collision detected\n" << RESET << endl;

		if (this->m_y_velocity < 0)
		{
			this->m_y_velocity *= -1;
		}
	}
	else if (m_value_left)
	{
		this->manual_move(sf::Vector2f(((puck_x - left_player_x) / left_player_puck_distance), (puck_y - left_player_y) / left_player_puck_distance));
	}
	else if (m_value_right)
	{
		this->manual_move(sf::Vector2f(((puck_x - right_player_x) / right_player_puck_distance), (puck_y - right_player_y) / right_player_puck_distance));
	}


	if (this->get_global_bounds().intersects(bottom_edge.getGlobalBounds()))
	{
		cout << RED << "bottom wall collision detected\n" << RESET << endl;

		if (this->m_y_velocity > 0)
		{
			this->m_y_velocity *= -1;
		}
	}
	else if (m_value_left)
	{
		this->manual_move(sf::Vector2f(((puck_x - left_player_x) / left_player_puck_distance), (puck_y - left_player_y) / left_player_puck_distance));
	}
	else if (m_value_right)
	{
		this->manual_move(sf::Vector2f(((puck_x - right_player_x) / right_player_puck_distance), (puck_y - right_player_y) / right_player_puck_distance));
	}


}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        movement_input()
	Function description: this honestly wasnt needed for this class, I just needed to override it
	Function input(s):    edge_collider(s) one mallet
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
	Equations:            new velocity (x or y) = (2 * m2 * v2 + [v1 * (m1 - m2)]) / (m1 + m2) <-- from John Schaub's physics class (highschool running start at spscc)
																																											   */

void puck::collision_detection_update(const edge_collider& left_edge, const edge_collider& right_edge, const edge_collider& top_edge, const edge_collider& bottom_edge, left_player_mallet& left_player)
{
	/* deal with mallets first */

	float left_player_x = 0, left_player_y = 0, puck_x = 0, puck_y = 0, left_player_puck_distance = 0, minimum_left_distance = 0;
	bool m_value_left = false, m_value_right = false;

	left_player.get_center_coordinate(left_player_x, left_player_y);
	this->get_center_coordinate(puck_x, puck_y);

	left_player_puck_distance = calculate_distance(puck_x, puck_y, left_player_x, left_player_y);

	minimum_left_distance = this->radius + left_player.get_radius();

	//if (this->get_global_bounds().intersects(left_player.get_global_bounds()))
	if (left_player_puck_distance <= minimum_left_distance)
	{
		cout << RED << "left player and puck collision detected\n" << RESET << endl;
		this->m_x_velocity = ((2 * left_player.get_mass() * left_player.get_x_velocity()) + (this->m_x_velocity * (this->m_mass - left_player.get_mass()))) / (this->m_mass + left_player.get_mass());
		this->m_y_velocity = ((2 * left_player.get_mass() * left_player.get_y_velocity()) + (this->m_y_velocity * (this->m_mass - left_player.get_mass()))) / (this->m_mass + left_player.get_mass());
		m_value_left = true;
	}

	/* deal with walls */

	if (this->get_global_bounds().intersects(left_edge.getGlobalBounds()))
	{
		cout << RED << "left wall collision detected\n" << RESET << endl;

		if (this->m_x_velocity < 0)
		{
			this->m_x_velocity *= -1;
		}
	}
	else if (m_value_left)
	{
		this->manual_move(sf::Vector2f(((puck_x - left_player_x) / left_player_puck_distance), (puck_y - left_player_y) / left_player_puck_distance));
	}

	if (this->get_global_bounds().intersects(right_edge.getGlobalBounds()))
	{
		cout << RED << "right wall collision detected\n" << RESET << endl;

		if (this->m_x_velocity > 0)
		{
			this->m_x_velocity *= -1;
		}
	}
	else if (m_value_left)
	{
		this->manual_move(sf::Vector2f(((puck_x - left_player_x) / left_player_puck_distance), (puck_y - left_player_y) / left_player_puck_distance));
	}


	if (this->get_global_bounds().intersects(top_edge.getGlobalBounds()))
	{
		cout << RED << "top wall collision detected\n" << RESET << endl;

		if (this->m_y_velocity < 0)
		{
			this->m_y_velocity *= -1;
		}
	}
	else if (m_value_left)
	{
		this->manual_move(sf::Vector2f(((puck_x - left_player_x) / left_player_puck_distance), (puck_y - left_player_y) / left_player_puck_distance));
	}


	if (this->get_global_bounds().intersects(bottom_edge.getGlobalBounds()))
	{
		cout << RED << "bottom wall collision detected\n" << RESET << endl;

		if (this->m_y_velocity > 0)
		{
			this->m_y_velocity *= -1;
		}
	}
	else if (m_value_left)
	{
		this->manual_move(sf::Vector2f(((puck_x - left_player_x) / left_player_puck_distance), (puck_y - left_player_y) / left_player_puck_distance));
	}
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        movement_update()
	Function description: this just moves the puck
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

void puck::movement_update(void)
{
	this->circle_projectile::movement_update();
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        render_projectile()
	Function description: draws the puck to the screen
	Function input(s):    sf::RenderWindow
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

void puck::render_projectile(sf::RenderWindow& window)
{
	this->puck_sprite.setPosition(this->get_position());
	//circle_projectile::render_projectile(window);
	window.draw(this->puck_sprite); /* <-- there is something wrong with the sprite */

}
/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        reset_puck()
	Function description: puts the puck back to the center and resets velocity
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

void puck::reset_puck(void)
{
	this->m_x_velocity = 0;
	this->m_y_velocity = 0;
	this->go_to(sf::Vector2f(549, 265));
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        check_for_goal()
	Function description: checks if the puck is intersecting the goal
	Function input(s):    edge_collider&
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

bool puck::check_for_goal(const edge_collider& goal)
{
	if (this->get_global_bounds().intersects(goal.getGlobalBounds()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        calculate_distance()
	Function description: returns the distance between two points
	Function input(s):    float& X 4
	Function output(s):   float
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

float puck::calculate_distance(const float& x_one, const float& y_one, const float& x_two, const float& y_two)
{
	return sqrt(pow((x_two - x_one), 2) + pow((y_two - y_one), 2));
}

/*******************************************************************************************************************************************************************************/


