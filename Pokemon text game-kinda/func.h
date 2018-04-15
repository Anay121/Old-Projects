void pokeInfo(pokemon x){
	cout << "\n\n";
	cout << "Name: " << x.name;
	cout << "\nLevel: " << x.level;
	cout << "\nExp: " << x.exp;
	cout << "\nHP: " << x.maxhp;
	cout << "\nAttack: " << x.attack;
	cout << "\nDefense: " << x.defense;
	cout << "\n\nMoves info:";
	for (int i = 0; i < 4; i++){
		cout << "\nMove " << i + 1 << ": " << m[x.moves[i]].name << " - " << m[x.moves[i]].damage;
	}
}	

void iPokeInfo(instantaneousPokemon x){
	cout << "\n\n";
	cout << "Name: " << x.name;
	cout << "\nLevel: " << x.level;
	cout << "\nExp: " << x.exp;
	cout << "\nHP: " << x.maxhp;
	cout << "\nAttack: " << x.attack;
	cout << "\nDefense: " << x.defense;
	cout << "\n\nMoves info:";
	for (int i = 0; i < 4; i++){
		cout << "\nMove " << i + 1 << ": " << m[x.moves[i]].name << " - " << m[x.moves[i]].damage;
	}
}
void aPokeInfo(ashPokemon x){
	cout << "\n\n";
	cout << "Name: " << x.name;
	cout << "\nLevel: " << x.level;
	cout << "\nExp: " << x.exp;
	cout << "\nHP: " << x.maxhp;
	cout << "\nAttack: " << x.attack;
	cout << "\nDefense: " << x.defense;
	cout << "\n\nMoves info:";
	for (int i = 0; i < 4; i++)
	{
		cout << "\nMove " << i + 1 << ": " << m[x.ms[i]].name << " - " << m[x.ms[i]].damage;
	}
}


void i2p(ashPokemon &dest, instantaneousPokemon src){
	strcpy(dest.name, src.name);
	dest.hp = src.hp;
	dest.maxhp = src.maxhp;
	dest.attack = src.attack;
	dest.defense = src.defense;
	dest.exp = src.exp;
	dest.level=src.level;
	for (int i = 0; i < 4; i++){
		dest.ms[i] = src.moves[i];
	}
	dest.id = src.id;
	for (i = 0; i < 4; i++){
		dest.am[i] = m[dest.ms[i]];
	}
}

int accu = 0;

void pokecatch(instantaneousPokemon opp, int &cap){
	if (ash.bag.pokeballs > 0){
		int diff = opp.maxhp - opp.hp;
		float perc = (diff * 100 )/ opp.maxhp ;
		perc*=perc; // to lower the chance 
		srand(time(NULL));
		int ran = rand()%100+1;
		if (ran <= perc || accu == 1){
			cout << "Successfully caught " << opp.name;
			cap=1;
			if (ash.partysize < 6){
				i2p(ash.party[ash.partysize], opp);
				ash.partysize++;
			} else {
				i2p(ash.pc[ash.pcsize], opp);
				ash.pcsize++;
				cout<<"\nIt has been placed in your PC\n";
			}
		} else {
			cout << opp.name << " was not caught. ";
		}
		ash.bag.pokeballs--;
	} else {
		cout << "You have no pokeballs! Try buying some at the mart. ";
	}
	getch();
}

int run(float php, float ohp)
{
	float chance = (php/ohp)*100;
	srand(time(NULL));
	int ran= rand()%100;
	if(chance>=ran)
	{
		cout<<"Successfully ran away! \n";
		return 1;
	}
	else
	{
		cout<<"Couldn't run away\n";
		return 0;
	}

}

void checklevel(int x){
	int &t = ash.party[x].level;
	double l = t;
	l++;
	while ((l)*(l)*(l) < ash.party[x].exp){
		t++;
		l++;
		ash.party[x].exp-((t+1)*(t+1)*(t+1));
		cout << "\nCongratulations! Your " << ash.party[x].name << " has leveled up! \n";
		ash.party[x].attack+=(0.026)*pokedex[ash.party[x].id].baseatt;
		ash.party[x].defense+=(0.026)*pokedex[ash.party[x].id].basedef;
		ash.party[x].hp+=(0.03)*pokedex[ash.party[x].id].basehp;
	}
}
void start() //start intro
{ 
	clrscr();
	char ch;
	int p;
	cout<<"\n\nHello, trainer! Sorry to keep you waiting.";
	getch();
	cout<<"\n\n\nWelcome to the world of Pokemon. My name is Professor Oak \nI'll be telling  you about the basics of this game.";
	getch();
	cout<<"\n\nOur world is widely inhabited by beings called 'Pokemons'. We humans live \talongside pokemons, as friends and partners.\n";
	getch();
	cout<<"\nSome of us battle other trainers to deepen the bonds between their pokemon.";
	getch();
	clrscr();
	cout<<"\n\nNow, tell me about yourself.\n";
	lb1:
	cout<<"Are you a Boy(b)? or a Girl(g)?   ";
	if(!kbhit())
	{
		lb:
		switch(getch())
		{
			case 'b':
			case 'B':
			ash.gender='b';
			break;
			case 'g':
			case 'G':
			ash.gender='g';
			break;
			default:
			goto lb;
		}
	}
	cout<<ash.gender;
	cout<<"\nAh, I see. \nAnd what is your name?\n";
	gets(ash.name);
	cout<<"Confirm?(y/n)";
	cin>>ch;
	if(ch=='n'||ch=='N')
		goto lb1;
	cout<<"\nWelcome to the world of Pokemon, "<<ash.name<<". Your journey begins in Pallet town, your hometown. \nCome to my lab later on, and ill help you choose your first pokemon.";
	getch();

	clrscr();
	cout<<"\n\n\tRing!";delay(800);
	cout<<"Ring!";delay(800);
	cout<<"Ring!";delay(800);
	cout<<"\nMom: "<<ash.name<<"! Wake up! It's already 10 am and youll be late for your appointment  with Professor Oak!  \n";
	cout<<"\nMom:  Ah, there you are. Now hurry up, you have to go to the Lab. You know where it is. Gary must b e waiting for you. ";
	getch();
	clrscr();
	cout<<"\n\nGary: You're late,"<<ash.name<<"! It's not good for me if my rival is tardy. Anyways, lets \thurry up now.\n";
	delay(2000);
	cout<<"\nOak: Ah, you are finally here. Excited to choose your partner?\n";
	cout<<"\nGary: You betcha! "<<ash.name<<", you take the first pick.\n";
	lb2:
	cout<<"\nOak: You have three choices: \n1."<<pokedex[0].name<<"\n2."<<pokedex[1].name<<"\n3."<<pokedex[2].name<<'\n';
	cin>>p;
	if(p>3||p<1)
	{	
		cout<<"Thats not a choice!\n";
		goto lb2;
	}
	instantaneousPokemon x(p-1,10);
	i2p(ash.party[0],x);
	ash.partysize++;
	cout<<"\nYou have chosen: "<<ash.party[0].name;
	cout<<"\nGary: Then ill choose this one! ";
	if(p==3)
		p=0;
	cout<<"\n Rival Gary chose "<<pokedex[p].name<<endl; 
	cout<<"\nOak: Good choice! I'm sure the pokemon will be really happy with you!";
	getch();
	clrscr();
	cout<<"\nOak: Now, I have a task for both of you. \nI want you to go out into the world and collect data on all the types of pokemon we know of! \nYou could start by defeating the gym in this town right here.";
	cout<<"\n\nOak: I'm sure you know how to battle, right?";
	getch();
	cout<<"\n\nGary: Yes! We select Attack and choose which move to use. The PP tells us how many times we can use the move. To capture a wild pokemon, we can use a pokeball.";
	getch();
	cout<<"\n\nOak: Good! Now, Off you go!";  
	clrscr();
}