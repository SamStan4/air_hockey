#pragma once

#include "circle_projectile.h"

class mallet : public circle_projectile
{
private:
	bool puck_collision;
protected:

	sf::Texture mallet_texture;
	sf::Sprite mallet_sprite; /* will be drawn on top of the mallet */
	int radius;

public:

	mallet(const sf::Vector2f& new_position, const float& new_radius, const float& new_mass, const sf::Color& new_color);

	void movement_input(const edge_collider& left_edge, const edge_collider& right_edge, const edge_collider& top_edge, const edge_collider& bottom_edge) override;

	virtual void movement_update(void) = 0;

	void render_projectile(sf::RenderWindow& window) override;

	sf::FloatRect get_mallet_global_bounds(void);

	virtual int get_radius(void);

	bool get_puck_collision_bool();

	void set_puck_collision_bool(bool newStatus);
};

/*******************************************************************************************************************************************************************************
	Function Call:        mallet()
	Function description: this function is the default constructor for the mallet class which is derived from circular projectile
	Function input(s):    sf::Vector2f, floar, float, sf::Color
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */

mallet::mallet(const sf::Vector2f& new_position, const float& new_radius, const float& new_mass, const sf::Color& new_color) : circle_projectile(new_position, new_radius, new_mass, new_color)
{

	if (!mallet_texture.loadFromFile("images/redMallet.png"))
	//if (!mallet_texture.loadFromFile("images/puck.png"))
	{
		cout << RED << "error loading mallet texture\n" << RESET << endl;
		system("pause");
	}
	else
	{
		cout << GREEN << "mallet texture loaded successfully\n" << RESET << endl;
		this->mallet_sprite.setTexture(mallet_texture);
		this->mallet_sprite.setScale(2.2, 2.2);
	}

	this->radius = new_radius;
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        movement_input()
	Function description: this function is responsible for accepting keyboard input and updating velocity for the object
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */

void mallet::movement_input(const edge_collider& left_edge, const edge_collider& right_edge, const edge_collider& top_edge, const edge_collider& bottom_edge)
{
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        movement_update()
	Function description: this function is responsible for updating the position of the mallet
	Function input(s):    NONE
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */

void mallet::movement_update(void)
{
	this->circle_projectile::movement_update();
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        render_projectile()
	Function description: this function is responsible for rendering the mallet
	Function input(s):    sf::RenderWindow
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

void mallet::render_projectile(sf::RenderWindow& window)
{
	this->mallet_sprite.setPosition(this->get_position());
	//circle_projectile::render_projectile(window);
	window.draw(this->mallet_sprite); /* <-- there is something wrong with the sprite */
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_mallet_global_bounds()
	Function description: this function returns the global bounds of the mallet
	Function input(s):    NONE
	Function output(s):   sf::FloatRect
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

sf::FloatRect mallet::get_mallet_global_bounds(void)
{
	return this->get_global_bounds();
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_radius()
	Function description: this function returns the radius of the mallet
	Function input(s):    NONE
	Function output(s):   int
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */

int mallet::get_radius(void)
{
	return this->radius;
}

/*******************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************
	Function Call:        get_puck_collision_bool()
	Function description: this function returns the collision state of the puck and this mallet (true = collision) (false = no collision)
	Function input(s):    NONE
	Function output(s):   bool
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */
bool mallet::get_puck_collision_bool() {
	return this->puck_collision;
}
/*******************************************************************************************************************************************************************************/


/*******************************************************************************************************************************************************************************
	Function Call:        set_puck_collision_bool()
	Function description: this function sets the collision state of the puck and this mallet (true = collision) (false = no collision)
	Function input(s):    bool
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/24/23
	Last edited:          4/24/23
	Programmer(s):        Samuel Stanley
																																											   */
void mallet::set_puck_collision_bool(bool newStatus)
{
	this->puck_collision = newStatus;
}
/*******************************************************************************************************************************************************************************/


