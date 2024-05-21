#pragma once
#include "map.h"

class UImenue
{
private:
	sf::Font font;
	const int width=235;
	const int length=821;
public:
	 //constructor and destroctor
	UImenue();
	virtual ~UImenue();

	//All menue elements
	//all these elements will be changed from time to time, so they are put in public specificer
	sf::RectangleShape menue_background_Rect;
	sf::Text Name;
	sf::Sprite imageRect;
	sf::RectangleShape HP_frame_rect;
	sf::RectangleShape HP_rect;
	sf::Text HP_text;
	sf::Text HP_number;
	sf::Text description; 

	//general varaibles
	sf::Font font1;


	//test
	//sf::Texture test_img;

	//functions
	void set_up_Bg();
	void initCharacterUI();
	void initTerrainsUI();

	void set_up_imageRect();
	void set_up_characters_information();
	void set_up_terrains_informaiton();
	void init_shared_elements();

};