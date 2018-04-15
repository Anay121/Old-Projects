void pokemart(){
	clrscr();
	int pmc, qty;
	cout << "Welcome to the pokemart. you have $" << ash.money;
	cout << "\nWhat do you want to buy?\n1. Pokeballs ($200 each)\n2. Potions ($50 each)";
	cin >> pmc;
	cout << "Enter the quantity ";
	cin >> qty;
	if (pmc == 1){
		if ((200 * qty) <= ash.money){
			cout << "Thanks for your purchase of " << qty << "pokeballs!";
			ash.bag.pokeballs += qty;
			ash.money -= 200 * qty;
			getch();
		}else{
			cout << "You do not have $" << 200 * qty << "required for the purchase.";
			getch();
		}
	}
	if (pmc == 2){
		if ((50 * qty) <= ash.money){
			cout << "Thanks for your purchase of " << qty << "potions!";
			ash.bag.pokeballs += qty;
			ash.money -= 50 * qty;
			getch();
		}else{
			cout << "You do not have $" << 50 * qty << "required for the purchase.";
			getch();
		}
	}

}

void poketransfer(){
	int i;
	if(ash.pcsize==0)
		cout<<"There are no Pokemon stored in the PC";
	else
	{			
		cout<<ash.name<<"'s current team\n";
   	 	for(i=0;i<6;i++)
   	 	{
    	    cout<<i+1<<". "<< ash.party[i].name<<endl;
	    }
	    int psc,pcsc;
	    cout << "\nEnter which pokemon you want to swap out: ";
	    lb8:
	    cin >> psc;
	    if(psc>6||psc<1)
	    {	
	    	cout<<"Invalid";
	    	goto lb8;
		}
	    psc--;
	    clrscr();
	    cout << "\nPC Pokemon:\n\n";
	    for (i = 0; i < ash.pcsize; i++){
    		cout<<i+1<<". "<< ash.pc[i].name<<endl;	
	    }
	    cout << "\nEnter which pokemon you want to swap in: ";
	    lb9:
    	cin >> pcsc;
    	pcsc--;
    	ashPokemon buff;
    	buff = ash.party[psc];
    	ash.party[psc] = ash.pc[pcsc];
    	ash.pc[pcsc] = buff;
    	cout<<"Swapped "<<ash.pc[pcsc].name<<" for "<<ash.party[psc].name;
    }
}				

struct fp{
	int id; 
	int levels[4];
};

struct town{
	int id;
	char name[20];
	fp wp[6];
};

town towns[8] = {
	{ // bracket for towns[0]
		0,
		"Oldale",
		{
			{
				21,
				{10,11,12,13}
			},
			{
				19,
				{10,11,12,13}
			},
			{
				14,
				{10,11,12,13}
			},
			{
				27,
				{10,11,12,13}
			},
			{
				26,
				{10,11,12,13}
			},
			{
				33,
				{10,11,12,13}
			}
		}
	},
	{ // bracket for towns[1]
		1,
		"Rustboro City",
		{
			{
				24,
				{14,15,16,17}
			},
			{
				21,
				{14,15,16,17}
			},
			{
				19,
				{14,15,16,17}
			},
			{
				26,
				{14,15,16,17}
			},
			{
				7,
				{14,15,16,17}
			},
			{
				4,
				{14,15,16,17}
			}
		}
	},
	{ // bracket for towns[2]
		2,
		"Petalburg City",
		{
			{
				32,
				{19,20,21,22}
			},
			{
				4,
				{19,20,21,22}
			},
			{
				16,
				{19,20,21,22}
			},
			{
				15,
				{19,20,21,22}
			},
			{
				19,
				{19,20,21,22}
			},
			{
				25,
				{19,20,21,22}
			}
		}
	},
	{ // bracket for towns[3]
		3,
		"Mauville City",
		{
			{
				31,
				{23,24,25,26}
			},
			{
				20,
				{23,24,25,26}
			},
			{
				10,
				{23,24,25,26}
			},
			{
				2,
				{23,24,25,26}
			},
			{
				27,
				{23,24,25,26}
			},
			{
				33,
				{23,24,25,26}
			}
		}
	},
	{ // bracket for towns[4]
		4,
		"Lavaridge Town",
		{
			{
				12,
				{28,29,30,31}
			},
			{
				26,
				{28,29,30,31}
			},
			{
				19,
				{28,29,30,31}
			},
			{
				9,
				{28,29,30,31}
			},
			{
				11,
				{28,29,30,31}
			},
			{
				22,
				{28,29,30,31}
			}
		}
	},
	{ // bracket for towns[5]
		5,
		"Sootopolis City",
		{
			{
				14,
				{32,33,34,35}
			},
			{
				3,
				{32,33,34,35}
			},
			{
				1,
				{32,33,34,35}
			},
			{
				13,
				{32,33,34,35}
			},
			{
				35,
				{32,33,34,35}
			},
			{
				36,
				{32,33,34,35}
			}
		}
	},
};