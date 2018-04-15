#define dam(lv,a,d,b) (float)(2*lv+10)*a/(250*d) * b + 2

class pokebase{
public:
	int id;
	char name[20];
	float basehp;
	float baseatt;
	float basedef;
	int m[4];
};

pokebase pokedex[100] = {
	{1, "Bulbasaur", 45, 49, 49,{97,39,99,95}},
	{2, "Charmander", 39, 52, 43 ,{20,9,35,37}},
	{3, "Squirtle",44,48,65,{25,1,30,23}},
	{4, "Pidgey", 40, 45, 40,{80,90,70,12}},
	{5, "Bellsprout", 50, 75, 35,{94,72,35,91}},
	{6, "Wurmple", 45, 45, 35,{90,9,18,82}},
	{7, "Silcoon", 50, 35, 55,{81,16,101,27}},
	{8, "Zigzagoon", 38, 30, 41,{11,61,57,61}},
	{9, "Rattata", 30, 56, 35,{66,53,93,2}},
	{10, "Ekans",35,60,44,{69,82,52,5}},
	{11, "Pikachu",35,55,40,{28,81,7,36}},
	{12, "Zubat",40,45,35,{19,28,8,89}},
	{13, "Diglett",10,55,25,{84,64,65,96}},
	{14, "Psyduck",50,52,48,{61,32,13,55}},
	{15, "Abra",25,20,15,{38,61,71,44}},
	{16, "Magnemite", 25, 35, 70,{90,5,83,69}},
	{17, "Seel",	65,45,55,{56,2,39,52}},
	{18, "Shellder",30,65,100,{30,85,5,80}},
	{19, "Gastly",30,35,30,{97,11,42,19}},
	{20, "Exeggcute",60,40,80,{26,23,58,16}},
	{21, "Koffing",40,65,9,{91,41,93,66}},
	{22, "Rhyhorn",80,85,95,{73,5,61,66}},
	{23, "Kangaskhan",105,95,80,{68,84,5,5}},
	{24, "Mr. Mime",40,45,65,{52,77,18,31}},
	{25, "Scyther",70,110,80,{10,17,39,85}},
	{26, "Electabuzz",65,83,57,{32,82,33,4}},
	{27, "Magmar",65,95,57,{58,81,12,56}},
	{28, "Lapras",130,85,80,{59,12,29,23}},
	{29, "Aerodactyl",80,105,65,{64,98,60,71}},
	{30, "Snorlax",160,110,65,{50,3,25,1}},
	{31, "Articuno",180,180,180,{44,90,21,48}},
	{32, "Zapdos",180,180,180,{75,60,94,86}},
	{33, "Moltres",180,180,180,{10,60,79,18}},
	{34, "Dratini",180,180,180,{64,4,84,99}},
	{35, "Mewtwo",180,180,180,{100,93,62,26}},
	{36, "Mew",180,180,180,{69,31,43,52}},
};

class pokemon{
	public:
		int id;
		char name[20];
		int hp;
		int maxhp;
		int attack;
		int defense;
		double exp;
		int level;
		int moves[4];
};

class instantaneousPokemon{ 
	public:
		int id;
		char name[20];
		int hp;
		int maxhp;
		int attack;
		int defense;
		double exp;
		int level;
		int moves[4];
		instantaneousPokemon(int no, float lvl){
			id = no;
			level = lvl;
			exp = lvl*lvl*lvl;
			attack = ((2 * pokedex[no].baseatt + 36) * (lvl/100)) + 5;
			defense = ((2 * pokedex[no].basedef + 36) * (lvl/100)) + 5;
			maxhp = ((2 * pokedex[no].basehp + 36) * (lvl/100)) + level + 10;
			hp = maxhp;
			strcpy(name, pokedex[no].name);
			for (int i = 0; i < 4; i++){
				moves[i] = pokedex[no].m[i];
			}
		}
};

class ashPokemon{
	public:
		int id;
		char name[20];
		int hp;
		int maxhp;
		int attack;
		int defense;
		double exp;
		int level;
		int ms[4];
		char gender;
		moves am[4];

		void setexp(){
			exp = level * level * level;
		}
};

struct b{ //bag
	int pokeballs;
	int potions;
};

struct Ash{
	char name[20];
	ashPokemon party[6];
	ashPokemon pc[100];
	int partysize;
	int pcsize;
	int town;
	int gyms[8];
	int trainers[80];
	int gymtrainers[8][5];
	double money;
	char gender;
	b bag;

	void heal(){
		for (int i = 0; i < 6; i++){
			party[i].hp = party[i].maxhp;
			for(int k=0;k<4;k++)
				party[i].am[k].pp=party[i].am[k].maxpp;
		}
	}

};

Ash ash;

struct opptrainer{
	int id;
	char name[20];
	int partysize;
	pokemon party[6];
	int prizemoney;
	int defeatloss;
};