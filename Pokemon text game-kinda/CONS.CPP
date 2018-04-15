#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <fstream.h>
#include <ctype.h>
#include <limits.h>

//user defined

#include <moves.h>
#include <defn.h>
#include <func.h>
#include <save.h>
#include <city.h>
#include <battle.h>
#include <hax.h>

int hax = 0;

void main(){
	clrscr();
	int kkk;
	cout << "Press 1 to load or 2 to create a new profile. ";
	cin >> kkk;
	if (kkk == 1){
		load();
	}else{
		newProfile();
	
		ash.town = 0;	
	}
	getch();
	aPokeInfo(ash.party[0]);
	save();

	int ch = 1;
	while (ch != 9){
		clrscr();
		cout << "You are in " << towns[ash.town].name << ".\n\n";
		cout << "\nWhat do you want to do?\n\n";
		cout << "\n1. Battle Wild Pokemon\n2. Heal Pokemon\n3. Pokemart\n4. Battle Gym";
		cout << "\n5. Advance to next city\n6. Return to previous one.\n7. Show trainer info\n8. Show pokemon\n9. Save and Exit\n10. Exit without saving\n";
		cin >> ch;
		while (cin.fail()){
	        cin.clear();
	        cin.ignore(INT_MAX, '\n');
	        cout << "You can only enter numbers.\n";
	        cout << "Enter a number.\n";
	        cin >> ch;
	    }
		switch(ch){
			case 1:
				clrscr();
				int y = rand() % 6;
				int z = rand() % 4;
				int d = towns[ash.town].wp[y].id;
				int lvl = towns[ash.town].wp[y].levels[z];
				wildBattle(d, lvl);
				break;
			case 2:
				clrscr();
				cout<<"What do you want to do?\n1. Heal your Pokemon\n2. Swap Pokemon from PC\n";
				int x=0;
				cin>>x;
				if(x==1)
				{
					cout << "Welcome to the Pokemon Center. We have healed your pokemon. Please come again! ";
					ash.heal();
					getch();
				}
				else if(x==2)
				{
					poketransfer();
				}
				else
					cout<<"Invalid choice";
				getch();
				break;
			case 3:
				pokemart();
				break;
			case 4:
				gymbattle(ash.town);
				break;
			case 5:
				nexttown(); //in battle.h
				break;
			case 6:
				if(ash.town != 0){
					ash.town--;
				}else{
					cout << "There is no town before Oldale!";
					getch();
				}
				break;
			case 7:
				clrscr(); 
				cout<<"Player name: "<<ash.name<<"\nNo. of Gym badges :";
				for(int i=0;i<8;i++){
					if(ash.gyms[i]==0){
						break;
					}
				}
				cout<<i<<"\nMoney: "<<ash.money;
				cout << "\nPokeballs: " << ash.bag.pokeballs << "\nPotions: " << ash.bag.potions;
				getch();
				break;
			case 8:
				clrscr();
				int choice=0;
				char ch=' ';
				cout<<ash.name<<"'s current team:\n";
				for(i=0;i<6;i++){
					cout<<i+1<<". "<< ash.party[i].name<<endl;
				}
				cout<<"\nSelect what to do:\n1. Display details\n2.Switch Pokemon\n3.Exit\n";
				cin>>choice;
				switch(choice){
					case 1: cout<<"Select pokemon to display info. ";
						int p=0;
						cin>>p;
						lb:
						clrscr();
						aPokeInfo(ash.party[p-1]);
						cout<<"\nPress A for previous pokemon and D for next pokemon or E to exit";  //Easy navigation
						ch=getche();
						if((ch=='a'||ch=='A') && (p>=1&&p<=6)) {
							p--;
							goto lb;
						}else if((ch=='d'||ch=='D') && (p>=0&&p<=5)) {
							p++;
							goto lb;
						}else if(ch=='e'||ch=='E'){
							break;
						}
						break;
					case 2: clrscr();
						int o,n;
						cout<<"Which pokemon to swap? ";
						cin>>o;
						o--;
						cout<<"Which pokemon to swap with?";
						cin>>n;
						n--;
						if(isalpha(ash.party[o].name[0])&&isalpha(ash.party[n].name[0])) //check the condition
						{
							ashPokemon temp;
							temp=ash.party[o];
							ash.party[o]=ash.party[n];
							ash.party[n]=temp;
						}
							
						break;
					case 3: break;
				}
				break;
			case 10:
				exit(0);
				break;
			case 69:
				hax = 1;
				break;
			case 420:
				if (hax == 1){
					getrekt();
				}
				break;
			default:
				break;
		}
	}
	save();
}