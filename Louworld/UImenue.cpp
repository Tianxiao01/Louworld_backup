#include "UImenue.h"



//constructor and destructor
UImenue::UImenue()
{
	this->set_up_Bg();
	this->initCharacterUI();
	this->initTerrainsUI();
	this->init_shared_elements();
}

UImenue::~UImenue()
{
}

void UImenue::set_up_Bg()
{
	this->menue_background_Rect.setFillColor(sf::Color(165, 113, 80));
	this->menue_background_Rect.setSize(sf::Vector2f(this->width, this->length));
	this->menue_background_Rect.setPosition(839, 0);
	this->menue_background_Rect.setOutlineColor(sf::Color(199, 199, 199));
	this->menue_background_Rect.setOutlineThickness(8.f);
	this->font1.loadFromFile("textures/font/pixel.ttf");
}

void UImenue::initCharacterUI()
{
	this->set_up_characters_information();
}

void UImenue::initTerrainsUI()
{
	this->set_up_terrains_informaiton();
}

void UImenue::set_up_imageRect()
{
	
	//this->test_img.loadFromFile("textures/characters/swordman01/swordman01_idle.png");
	this->imageRect.setPosition(894, 80);
	//this->imageRect.setTexture(this->test_img);
	this->imageRect.setScale(2, 2);
	//this->imageRect.setTextureRect(sf::IntRect(0,64*2,64,64));
}

void UImenue::set_up_characters_information()
{
	this->HP_frame_rect.setPosition(894, 310);
	this->HP_frame_rect.setSize(sf::Vector2f(100, 16));
	this->HP_frame_rect.setFillColor(sf::Color(169, 169, 169));

	this->HP_rect.setPosition(896, 312);
	this->HP_rect.setSize(sf::Vector2f(96, 12));
	this->HP_rect.setFillColor(sf::Color(255,0,0));

	this->HP_text.setFont(this->font1);
	this->HP_text.setString("HP:");
	this->HP_text.setFillColor(sf::Color::Black);
	this->HP_text.setPosition(847, 310);
	this->HP_text.setCharacterSize(18);
	this->HP_text.setStyle(sf::Text::Bold);

	this->HP_number.setFont(this->font1);
	this->HP_number.setString("***/***");
	this->HP_number.setFillColor(sf::Color::Black);
	this->HP_number.setPosition(995, 312);
	this->HP_number.setCharacterSize(12);
}

void UImenue::set_up_terrains_informaiton()
{

}

void UImenue::init_shared_elements()
{
	this->set_up_imageRect();

	this->description.setFont(this->font1);
	this->description.setString("//////////////////"); // 18 charaacters for each line
	this->description.setFillColor(sf::Color::Black);
	this->description.setPosition(850, 380);
	this->description.setCharacterSize(13);
}


