#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "characters.h"
#include "UImenue.h"

class Game 
{
private :
	// arrays representing the terrians
	int TerrainsState[13][13]= {	{999, 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },   //x axis *64, y axis *64
									{ 0 , 0 , 0 , 0 , 0 ,999,999, 0 , 1 ,999, 1 , 0 , 0 },
									{ 0 , 0 , 0 , 0 , 0 ,999, 0 , 0 , 0 , 0 , 0 , 0 , 0 },    //0 means the block is not occupied
									{ 0 , 0 , 0 , 0 , 0 ,999, 0 , 0 , 0 , 0 , 0 , 0 , 0 },    //1 means team1 character is on the block
									{999,999, 0 ,999,999,999, 0 , 0 , 0 , 0 , 0 , 0 , 0 },    //2 means team2 character is on the block
									{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },    //9 means the block is not passable
									{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
									{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
									{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,999,999},
									{ 0 , 0 , 0 , 0 , 0 ,999,999,999,999, 0 , 0 ,999,999},
									{999,999,999,999,999, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
									{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
									{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } };  // the terrainstatearray will be an attibute of 
																							  // class Map and each map have different array

	sf::RectangleShape border;

	//general varaible
	int operating_team = 1;
	
	// assiting varaibles for UI
	bool a_character_hoveredOn = false;
	bool a_terrain_hoveredOn = false;
	Characters* character_On=nullptr;
	std::pair<int, int> coord_of_terrainOn = {999, 999};
	int TerrainNum;

	//movement varaibles
	int Block_clicking_onX;
	int Block_clicking_onY;
	bool ABlockischosen = false;
	bool ACharacterischosen = false;
	int team_characterChosen = 0;
	int characterStamina;

	//attack varaibles
	sf::Vector2f attackerPosition;
	sf::Vector2f targetPosition;
	bool aTargetIsChosen = false; // this is also used in the measuredistaice function to locate the cordinate of the source
	int damagePoint_chosenChar;

	//variabel & window
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videomode;
	//playercharacters
	Characters* swordman;
	std::vector<Characters*> swordmanpointers;
	Characters* knight;
	Characters* shieldman;
	//AIcharacters
	Characters* orc_axe;
	std::vector<Characters*> orc_axepointers;
	//map
	Map* map;
	//UImenue
	UImenue* UiMenue;
	//characters vecter
	std::vector<Characters*> playablecharacters;
	std::vector<Characters*> AIcharacters;
	std::vector<Characters*> Allcharacters;

	//input variables
	sf::Vector2i localMousePosition;
	std::string ButtonClicked="None";

	//initial initialization
	void initVariables();
	void initplayercharacters();
	void initmaps();
	void initWindow();
	void initUImenue();

	// ingame initialization
	void initnewunits();

public :
	//constructor and destructor
	Game();
	virtual ~Game();

	//accessory
	const bool running() const;

	//functions
	void pollevent();
	void GetMouseActivity();

	void checkTerrainstate();
	void checkCharactersState(); //check which character is clicked on Left or Right or hovered on. Return the character that is hovered on.

	void drawBorder(sf::RectangleShape& border);
	void MeasureDistance();
	void Construct_path(Characters* character, sf::Vector2i goal);

	void identifymovement();
	void updatePlayerCharacters();
	void updateAICharacters();
	void updatecharacters();
	void updateterrains();
	void updateUImenue();
	void rendercharacters();
	void rendermap();
	void renderUImenue();

	void update();
	void render();
};

#endif 
