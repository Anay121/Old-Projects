char * enc(char * gg){
	char *k = "";
	int x = strlen(gg), y, z;
	z = gg[0];
	for (int i = 0; i < x-1; i++){
		y = gg[i] + gg[i+1];
		y = y % 26;
		y += 97;
		k[i] = y;
	}
	y = z + gg[x-1];
	y = y % 26;
	y += 97;
	k[x-1] = y;
	k[x] = '\0';
	return k;
}

void funtime(){
	cout << "Enter a number ";
	int ppos;
	int jk;
	cin >> ppos;
	if(ppos >= 1 && ppos <= 6){
		ppos--;
		cout << "Enter ID (0-35)";
		cin >> ash.party[ppos].id;
		strcpy(ash.party[ppos].name, pokedex[ash.party[ppos].id].name);
		cout << "Enter Max HP ";
		cin >> ash.party[ppos].maxhp;
		cout << "Enter attack ";
		cin >> ash.party[ppos].attack;
		cout << "Enter defense ";
		cin >> ash.party[ppos].defense;
		cout << "Enter level ";
		cin >> jk;
		ash.party[ppos].level = jk;
		ash.party[ppos].exp = (double)jk * jk * jk;
		for (jk = 0; jk < 4; jk++){
			cout << "Enter move number ";
			cin >> ash.party[ppos].ms[jk];
			ash.party[ppos].am[jk] = m[ash.party[ppos].ms[jk]];
		}
	}
}

void getrekt(){
	clrscr();
	char *hl3;
	char gg = 'a';
	int i = 0;
	while (isalpha(gg)){
		gg = getch();
		hl3[i] = gg;
		i++;
	}
	i--;
	hl3[i] = '\0';
	if (strcmp(enc(hl3), "lwvubil") == 0){
		ash.money = 100000000;
	} else if (strcmp(enc(hl3), "yexjhp") == 0){
		for (int i = 0; i < ash.partysize; i++){
			ash.party[0].level = 100;
			ash.party[0].exp = 1000000;
		}
	} else if (strcmp(hl3, "ndqdocxnhrsna") == 0){
		int x = 31;
		for (int i = 0; i < 6; i++){
			x = x + i;
			towns[0].wp[i].id = x;
		}
	} else if (strcmp(enc(hl3), "ndjfbp") == 0){
		accu = 1;
	} else if (strcmp(enc(hl3), "rzbfi") == 0){
		ash.bag.potions = 32000;
	} else if (strcmp(enc(hl3), "nxiybyl") == 0){
		ash.bag.pokeballs = 32000;
	} else if (strcmp(enc(hl3), "wlslhlhdm") == 0){
		ezh = 1;
	} else if (strcmp(enc(hl3), "bdwdzmxzmdhs") == 0){
		funtime();
	}
}