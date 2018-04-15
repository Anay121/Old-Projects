ifstream opx;
ifstream gyt;

int ezh = 0;

void wildBattle(int id, int lvl){
	int ps = 0;
	instantaneousPokemon opp(id, lvl);
	int cap = 0;
	int count=0;
	srand(time(NULL));
	while (opp.hp > 0 && cap != 1 && count !=ash.partysize){
		lb:
		clrscr();
		int opt;
		cout << "Opponent: Wild " << opp.name;
		cout << "\nHP: " << opp.hp;
		cout << "\nLevel: " << opp.level;
		cout << "\n\n\n\nYour pokemon: " << ash.party[ps].name;
		cout << "\nHP: " << ash.party[ps].hp;
		cout << "\nLevel: " << ash.party[ps].level;
		cout << "\n\nYour choices: ";
		cout << "\n1. Attack";
		cout << "\n2. Use a pokeball ";
		cout << "\n3. Change pokemon" ;
		cout << "\n4. Run\n";
		cin >> opt;
		if (opt < 1 || opt > 6){
			cout << "Invalid option ";
			getch();
			goto lb;
		}
		else if(opt==2)
		{
			pokecatch(opp,cap);
			if (cap == 1){
				break;
			}
		}
		else if(opt==3)
		{
			lb2:
			clrscr();
			cout<<"Pokemon in your team:\n";
			for(int i=0;i<6;i++)
			{
				cout<<i+1<<". "<<ash.party[i].name<<"\t"<<ash.party[i].hp<<endl;
			}
			int c=ps;
			cin>>ps;
			ps--;
			if(ps < 0||ps>5)
			{
				cout<<"Invalid ";
				delay(900);
				goto lb2;
			}
			if(ash.party[ps].hp<=0)
			{
				cout<<"This pokemon cant battle anymore. Choose another";
				getch();
				goto lb2;
			}
			cout<<"Switched "<<ash.party[c].name<<" for "<<ash.party[ps].name;
		}
		else if(opt==4)
		{
			if(run((float)(ash.party[ps].hp/ash.party[ps].maxhp),(float)(opp.hp/opp.maxhp)==1)){
				cout << "Got away safely!";
				break;
			}else{
				cout << "Can't escape! ";
				}
			}
		else if(opt==6)
		{
			exit(0);
		}
		else if(opt==1)
		{
			cout << "\n1. " << m[ash.party[ps].ms[0]].name<<"\tPP: "<<ash.party[ps].am[0].pp;; 
			cout << "\n2. " << m[ash.party[ps].ms[1]].name<<"\tPP: "<<ash.party[ps].am[1].pp;;
			cout << "\n3. " << m[ash.party[ps].ms[2]].name<<"\tPP: "<<ash.party[ps].am[2].pp;;
			cout << "\n4. " << m[ash.party[ps].ms[3]].name<<"\tPP: "<<ash.party[ps].am[3].pp;;
			int x;
			lb3:
			cout<<endl;
			cin>>x;
			if(x>4||x<1||m[ash.party[ps].ms[3]].name[0]==' ')
			{
				cout<< "Invalid option. ";
				getch();
				goto lb3;
			}
			if (ash.party[ps].am[x-1].pp <1){
				cout << "No PP left for this move! Chose another one.. ";
				goto lb3;
			} else {
				int dmg= dam(ash.party[ps].level, ash.party[ps].attack, opp.defense, ash.party[ps].am[x-1].damage);
				opp.hp -= dmg;
				ash.party[ps].am[x-1].pp--;
				cout<<"You used "<<ash.party[ps].am[x-1].name<<"\nDamage done to opponent: "<<dmg;
				opp.hp -= dmg;
			}
		}
		if (opp.hp > 0){
			int ran;
			do{		
				ran=rand()%401;
				ran=ran%4;
			}
			while(m[opp.moves[ran]].name[0]==' ');
			int dmg= dam(opp.level, opp.attack, ash.party[ps].defense, m[opp.moves[ran]].damage);
			ash.party[ps].hp-=dmg;
			cout<<"\n\nOpponent used "<<m[opp.moves[ran]].name<<"\nDamage done to you: "<<dmg;
			if (ezh == 1){
				ash.party[ps].hp = ash.party[ps].maxhp;
			}
			getch();
		}
			if(ash.party[ps].hp<=0){
				ps++;
				count++;
			}
	}
	if(opp.hp<=0){
		cout<<"\n\nYou win!!";
		ash.party[ps].exp += (lvl * 10);
		cout << "\nYou got " << (lvl * 10) << "XP for winning! ";
		checklevel(ps);
		getch();
	}
	else if(count==ash.partysize)
	{
		cout<<"\nYou lose! You rush to the nearest Pokemon center to heal your pokemon .";
		ash.heal();
		getch();
	}
}
int trainerBattle(opptrainer x)
{
	int ps=0,ts=0,count=0;
	opptrainer pedro;
	pedro = x;
	cout<<"You are challenged by trainer "<< pedro.name;
	cout << "\nBegin battle.";
	getch();
	clrscr();
	while(ts<pedro.partysize && ps<ash.partysize)
	{
		while(pedro.party[ts].hp>0&&ash.party[ps].hp>0 )
		{
			lb:
			clrscr();
			int opt;
			cout << "Opponent: " << pedro.party[ts].name;
			cout << "\nHP: " << pedro.party[ts].hp;
			cout << "\nLevel: " << pedro.party[ts].level;
			cout << "\n\n\n\nYour pokemon: " << ash.party[ps].name;
			cout << "\nHP: " << ash.party[ps].hp;
			cout << "\nLevel: " << ash.party[ps].level;
			cout << "\n\nYour choices: ";
			cout << "\n1. Attack";
			cout << "\n2. Use a pokeball ";
			cout << "\n3. Change pokemon" ;
			cout << "\n4. Run\n";
			cin >> opt;
			if (opt < 1 || opt > 6){
				cout << "Invalid option ";
				getch();
				goto lb;
			}
			else if(opt==2){
				cout<< "The trainer blocked the pokeball! Don't be a thief!";
				getch();
				goto lb;
			}
			else if(opt==3)
			{
				lb2:
				clrscr();
				cout<<"Pokemon in your team:\n";
				for(int i=0;i<6;i++)
				{
					cout<<i+1<<". "<<ash.party[i].name<<"\t"<<ash.party[i].hp<<endl;
				}
				int c=ps;
				cin>>ps;
				ps--;
				if(ps < 0||ps>5)
				{
					cout<<"Invalid ";
					delay(900);
					goto lb2;
				}
				if(ash.party[ps].hp<=0)
				{
					cout<<"This pokemon cant battle anymore. Choose another";
					getch();
					goto lb2;
				}
				cout<<"Switched "<<ash.party[c].name<<" for "<<ash.party[ps].name;
			}
			else if(opt==4)
			{
				cout << "There's no running from a trainer battle! ";
				getch();
				goto lb;
			}
			else if(opt==6)
				break;
			else if(opt==1)
			{
				cout << "\n1. " << m[ash.party[ps].ms[0]].name<<"\tPP: "<<ash.party[ps].am[0].pp;; 
				cout << "\n2. " << m[ash.party[ps].ms[1]].name<<"\tPP: "<<ash.party[ps].am[1].pp;;
				cout << "\n3. " << m[ash.party[ps].ms[2]].name<<"\tPP: "<<ash.party[ps].am[2].pp;;
				cout << "\n4. " << m[ash.party[ps].ms[3]].name<<"\tPP: "<<ash.party[ps].am[3].pp;;
				int x;
				lb3:
				cout<<endl;
				cin>>x;
				if(x>4||x<1||m[ash.party[ps].ms[3]].name[0]==' ')
				{
					cout<< "Invalid option. ";
					getch();
					goto lb3;
				}
				if (ash.party[ps].am[x-1].pp <1){
					cout << "No PP left for this move! Chose another one.. ";
					goto lb3;
				} else {
					int dmg= dam(ash.party[ps].level,ash.party[ps].attack,pedro.party[ts].defense,ash.party[ps].am[x-1].damage);
					pedro.party[ts].hp -= dmg;
					ash.party[ps].am[x-1].pp--;
					cout<<"You used "<<ash.party[ps].am[x-1].name<<"\nDamage done to opponent: "<<dmg;
				}
			}
			getch();
			if(pedro.party[ts].hp<=0)
				break;
			int ran;
			do{
				ran=rand()%401;
				ran=ran%4;
			}while(m[pedro.party[ts].moves[ran]].name[0]==' ');

			int dmg= dam(ash.party[ps].level,ash.party[ps].attack,pedro.party[ts].defense,ash.party[ps].am[ran-1].damage);  //change damage formula
			ash.party[ps].hp-=dmg;
			//reduce pp
			cout<<"\n\nOpponent used "<<m[pedro.party[ts].moves[ran]].name<<"\nDamage done to you: "<<dmg;
			if (ezh == 1){
				ash.party[ps].hp = ash.party[ps].maxhp;
			}
			getch();

		}
		if(pedro.party[ts].hp<=0)
		{
			cout<<"\nYou defeated opponent's " << pedro.party[ts].name;
			ash.party[ps].exp += (pedro.party[ts].level * 10);
			cout << "\nYou got " << (pedro.party[ts].level * 10) << "XP for winning! ";
			checklevel(ps);
			getch();
			ts++;			
		}
		else if(ash.party[ps].hp<=0)
		{
			cout<<"\nYour "<< ash.party[ps].name << " was defeated ";
			ps++;
			count++;
			getch();
		}
	}
	if(ts==pedro.partysize)
	{
		cout<<"\n\nYou win!  ";
		ash.money+=pedro.prizemoney;
		return 1;
	}
	if(count==ash.partysize)
	{
		cout<<"\n\nYou lose! ";
		ash.money-=pedro.defeatloss;
		return 0;
	}

}
void gymbattle(int id){
	gyt.open("GGWP.XXX",ios::binary);
	opptrainer gym;
	clrscr();
	cout << "Welcome to " << towns[id].name << " gym!";
	if (ash.gymtrainers[id][4] == 1){
		cout << "\n\nYou've already defeated this gym, gg. ";
		getch();
	}else{
		int x = 0;
		for (x = 0; x < 5; x++){
			if (ash.gymtrainers[id][x] == 0){
				clrscr();
				cout << "You are battling trainer #" << x + 1 << "! Press any key to begin\n\n";
				getch();
				gyt.seekg(((5*id)+x) * sizeof(gym));
				gyt.read((char*)&gym,sizeof(gym));
				int result = trainerBattle(gym);
				if (result == 1){
					ash.gymtrainers[id][x] = 1;
					ash.money+=gym.prizemoney;
				}else{
					clrscr();
					cout << "After losing all your pokemon, you rush to the nearest pokecenter... ";
					ash.money-=gym.defeatloss;
					ash.heal();
					getch();
					break;
				}
			}
		}
	}
gyt.close();
}
opptrainer op;
void nexttown(){
	opx.open("kkk.xxx",ios::binary);
	if(ash.gymtrainers[ash.town][4] == 1){
		if (ash.trainers[(ash.town*10) + 9] ==  1){
			ash.town++;
		}else{
			cout << "You must first defeat all trainers till the next town! Press any key to start battling.";
			getch();
			clrscr();
			for (int i = 0; i < 10; i++){
				if (ash.trainers[(ash.town*10) + i] ==  0){
					opx.seekg(((ash.town*10)+i)* sizeof(op));
					opx.read((char *)&op,sizeof(op));
					int result = trainerBattle(op);
					if(result == 1){
						ash.trainers[(ash.town*10) + i] = 1;
					}else{
						break;
					}
				}
			}
		}
	}else{
		cout << "You must defeat this gym first! ";
		getch();
	}
	opx.close();
}