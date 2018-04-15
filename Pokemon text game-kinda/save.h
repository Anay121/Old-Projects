ifstream ggg;
ofstream wp;

void load(){
	ggg.open("POKE.SAV", ios::binary);
	ggg.read((char *)&ash, sizeof(ash));
	cout << "\nSuccessfully loaded " << ash.name	<<"'s profile.";
	ggg.close();
}

void save(){
	wp.open("POKE.SAV", ios::binary);
	wp.write((char *)&ash, sizeof(ash));
	cout << "\nSucessfully saved " << ash.name << "'s profile.";
	wp.close();
}

void newProfile(){
	cout << "What is your name? ";
	gets(ash.name);
	ash.partysize = 0;
	ash.pcsize = 0;
	ash.town = 0;
	ash.money=3000;
	int i;
	for (i = 0; i < 8; i++){
		ash.gyms[i] = 0;
	}
	for (i = 0; i < 80; i++){
		ash.trainers[i] = 0;
	}
	for (i = 0; i < 8; i++){
		for (int j = 0; j < 5; j++){
			ash.gymtrainers[i][j] = 0;
		}
	}
	cout << "Press any key to save ";
	save();
	start();
}