#include "air_hockey_GENERAL_HEADER.h"
#define INPUT_FIELD_BOX_WIDTH 30
#define INPUT_FIELD_BOX_LENGTH 20
#define EXPANSION_SIZE 15
#define TEXT_SLEEP 350000000

class input_field : public sf::RectangleShape
{
private:

	string m_input;
	sf::Font input_font;
	sf::Text m_player_text;
	int m_origional_x_location, m_origional_y_location, m_text_origional_x_location, m_text_origional_y_location;

public:

	input_field(const sf::Vector2f location);

	void input_field_update(void);

	void render_input_field(sf::RenderWindow& window);

	string get_string_contents(void);
};

/*******************************************************************************************************************************************************************************
	Function Call:        input_field()
	Function description: this function is the constructor for this thing
	Function input(s):    none
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */
input_field::input_field(const sf::Vector2f location)
{	
	if (!input_font.loadFromFile("fonts\\AldotheApache.ttf"))
	{
		cout << RED << "error loading input font\n" << RESET << endl;
		system("pause");
	}
	else
	{
		this->m_player_text.setFont(input_font);
		m_player_text.scale(sf::Vector2f(1, 1));
		m_player_text.setPosition(sf::Vector2f(location.x + 5, location.y - 5));
		this->m_player_text.setString(" ");
	}

	this->m_input = " ";

	this->setSize(sf::Vector2f(INPUT_FIELD_BOX_WIDTH, INPUT_FIELD_BOX_LENGTH));
	this->setPosition(location);
	this->setFillColor(sf::Color::Cyan);
	this->setOutlineThickness(5);
	this->setOutlineColor(sf::Color::Green);

	this->m_origional_x_location = location.x;
	this->m_origional_y_location = location.y;
	this->m_text_origional_x_location = location.x + 5;
	this->m_text_origional_y_location = location.y - 5;

	//cout << "X: " << this->m_player_text.getPosition().x << endl << "Y: " << this->m_player_text.getPosition().y << endl << endl;

	//system("pause");
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        input_field_update()
	Function description: this function detects if a key is pressed and then updates some stuff
	Function input(s):    sf::Keyboard
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */
void input_field::input_field_update(void)
{
	if (this->m_input.size() < 21)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			this->m_input += 'A';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		{
			this->m_input += 'B';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			this->m_input += 'C';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			this->m_input += 'D';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			this->m_input += 'E';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			this->m_input += 'F';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			this->m_input += 'G';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
		{
			this->m_input += 'H';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		{
			this->m_input += 'I';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		{
			this->m_input += 'J';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		{
			this->m_input += 'K';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		{
			this->m_input += 'L';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		{
			this->m_input += 'M';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		{
			this->m_input += 'N';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
		{
			this->m_input += 'O';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			this->m_input += 'P';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			this->m_input += 'Q';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			this->m_input += 'R';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			this->m_input += 'S';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			this->m_input += 'T';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		{
			this->m_input += 'U';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
		{
			this->m_input += 'V';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			this->m_input += 'W';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			this->m_input += 'X';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			this->m_input += 'Y';
			sleep(TEXT_SLEEP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			this->m_input += 'Z';
			sleep(TEXT_SLEEP);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		if (this->m_input.size() > 0) /* make sure there is a character to delete */
		{
			this->m_input.erase(this->m_input.size() - 1);
			//sleep(TEXT_SLEEP);
		}
		sleep(TEXT_SLEEP);
	}

	//cout << "X: " << this->m_player_text.getPosition().x << endl << "Y: " << this->m_player_text.getPosition().y << endl << endl;

	//system("pause");

	if (this->m_input.size() != 0)
	{
		this->setSize(sf::Vector2f(INPUT_FIELD_BOX_LENGTH + ((this->m_input.size() - 1) * EXPANSION_SIZE), INPUT_FIELD_BOX_WIDTH));
		this->setPosition(sf::Vector2f(this->m_origional_x_location - (EXPANSION_SIZE * 0.5 * this->m_input.size()), this->m_origional_y_location));
		this->m_player_text.setPosition(sf::Vector2f(this->m_text_origional_x_location - (EXPANSION_SIZE * 0.5 * this->m_input.size()), this->m_text_origional_y_location));
	}
	else
	{
		this->setSize(sf::Vector2f(INPUT_FIELD_BOX_LENGTH, INPUT_FIELD_BOX_WIDTH));
	}

	//cout << "SIZE: " << this->m_input.size() << endl;

	this->m_player_text.setString(this->m_input);

	//cout << GREEN << this->m_input << endl << endl;

	//cout << "X: " << this->m_player_text.getPosition().x << endl << "Y: " << this->m_player_text.getPosition().y << endl << endl;

}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        input_field()
	Function description: this function is the constructor for this thing
	Function input(s):    none
	Function output(s):   NONE
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */
void input_field::render_input_field(sf::RenderWindow& window)
{
	window.draw(*this);
	window.draw(this->m_player_text);
}

/*******************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************
	Function Call:        get_string_contents()
	Function description: this function returns the string that was inputed
	Function input(s):    none
	Function output(s):   std::string
	Preconditions:        NONE
	Postconditions:       NONE
	Creation date:        4/22/23
	Last edited:          4/22/23
	Programmer(s):        Samuel Stanley
																																											   */
string input_field::get_string_contents(void)
{
	return this->m_input;
}

/*******************************************************************************************************************************************************************************/
