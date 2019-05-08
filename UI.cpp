#include "UI.h"
#include <iostream>
using namespace std;

void UI::showListaFilme(vector<Film> vec) {
	/*
	prints the Films form a vector Film
	vec - vector <Film>
	*/
	if (vec.size() != 0) {
		cout << "Titel          Genre          erscheinungs Jahr        Anzahl Likes        Trailer\n";
		for (auto &o : vec) {
			cout << o.get_titel();
			for (int j = 0; j < 15 - o.get_titel().size(); j++)
				cout << " ";
			cout << o.get_genre();
			for (int j = 0; j < 15 - o.get_genre().size(); j++)
				cout << " ";
			cout << o.get_erscheinungsJahr();
			for (int j = 0; j < 21; j++)
				cout << " ";
			cout << o.get_anzahlLikes();
			for (int j = 0; j < 20; j++) 
				cout << " ";
			cout << o.get_trailer() << endl;
		}
	}
	else {
		cout << "The list is empty :'( \n";
	}
}

void UI::showFilm(Film &o) {
	/*
	prints a single Film
	o - Film
	*/
	cout << o.get_titel();
	for (int j = 0; j < 15 - o.get_titel().size(); j++)
		cout << " ";
	cout << o.get_genre();
	for (int j = 0; j < 15 - o.get_genre().size(); j++)
		cout << " ";
	cout << o.get_erscheinungsJahr();
	for (int j = 0; j < 21; j++)
		cout << " ";
	cout << o.get_anzahlLikes();
	for (int j = 0; j < 20; j++)
		cout << " ";
	cout << o.get_trailer() << endl;
}

void UI::addFilm() {
	/*
	takes input from the user, verifys it and build's a film if the input is correect 
	and if the Film isn't already in the FilmRepo and Handels exceeptions
	*/
		string titel;
		string genre;
		int erscheinungsJahr;
		int anzahlLikes;
		string trailer;
		cout << "Enter Titel: ";
		cin >> titel;
		cout << "Enter Genre: ";
		cin >> genre;
		cout << "Enter erscheinungs Jahr: ";
		cin >> erscheinungsJahr;
		cout << "Enter Anzahl Likes: ";
		cin >> anzahlLikes;
		cout << "Enter Trailer: ";
		cin >> trailer;
		contr.addFilmToRepo(titel, genre, erscheinungsJahr, anzahlLikes, trailer);
		cout << "FIlm successfully added! :D \n";
}

void UI::deleteFilm() {
	/*
	takes user input, deletes a Film and Handels Exceptions
	*/
		string titel;
		int erscheinungsJahr;
		cout << "Enter title: ";
		cin >> titel;
		cout << "Enter Erscheinungs Year: ";
		cin >> erscheinungsJahr;
		contr.deleteFilmFromRepo(titel, erscheinungsJahr);
		cout << "Film successfully deleted \n";

}

void UI::updateFilmTitel() {
	/*
	takes user input, updates a film and handels Excepions
	*/
		string titel;
		string newtitel;
		int erscheinungsJahr;
		cout << "Enter title: ";
		cin >> titel;
		cout << "Enter Erscheinungs Year: ";
		cin >> erscheinungsJahr;
		cout << "Enter new titel: ";
		cin >> newtitel;
		contr.updateFillmTitelFromRepo(titel, erscheinungsJahr, newtitel);
		cout << "Titel successfully updated";

}

void UI::updateFilmGenre(){
	/*
	takes user input, updates a film and handels Excepions
	*/

	string titel;
	string newGenre;
	int erscheinungsJahr;
	cout << "Enter title: ";
	cin >> titel;
	cout << "Enter Erscheinungs Year: ";
	cin >> erscheinungsJahr;
	cout << "Enter new genre: ";
	cin >> newGenre;
	contr.updateFillmGenreFromRepo(titel, erscheinungsJahr, newGenre);
	cout << "Genre successfully updated \n";

}

void UI::updateFilmErscheinungsJahr() {
	/*
	takes user input, updates a film and handels Excepions
	*/
		string titel;
		int newErscheinungsJahr;
		int erscheinungsJahr;
		cout << "Enter title: ";
		cin >> titel;
		cout << "Enter Erscheinungs Year: ";
		cin >> erscheinungsJahr;
		cout << "Enter new ErscheinungsJahr: ";
		cin >> newErscheinungsJahr;
		contr.updateFillmErscheinungsJahrFromRepo(titel, erscheinungsJahr, newErscheinungsJahr);
		cout << "Release Year successfully updated";

}

void UI::updateFilmeAnzahlLikes() {
	/*
	takes user input, updates a film and handels Excepions
	*/

		string titel;
		int newAnzahlLikes;
		int erscheinungsJahr;
		cout << "Enter title: ";
		cin >> titel;
		cout << "Enter Erscheinungs Year: ";
		cin >> erscheinungsJahr;
		cout << "Enter new Anzahl Likes: ";
		cin >> newAnzahlLikes;
		contr.updateFillmAnzahlLikesFromRepo(titel, erscheinungsJahr, newAnzahlLikes);
		cout << "Anzahl Likes successfully updated \n";

}

void UI::updateFilmeTrailer() {
	/*
	takes user input, updates a film and handels Excepions
	*/
		string titel;
		string newtariler;
		int erscheinungsJahr;
		cout << "Enter title: ";
		cin >> titel;
		cout << "Enter Erscheinungs Year: ";
		cin >> erscheinungsJahr;
		cout << "Enter new genre: ";
		cin >> newtariler;
		contr.updateFillmTrailerFromRepo(titel, erscheinungsJahr, newtariler);
		cout << "Trailer successfully updated \n";

}

void UI::addFilmToWatchlist() {
	/*
	takes input from the user, verifys it and build's a film if the input is correect
	and if the Film isn't already in the Watchlist and Handels exceeptions
	*/
	string titel;
	cout << "Enter a titel: ";
	cin >> titel;
	int erscheinungsJahr;
	cout << "Enter erscheinungsJahr: ";
	cin >> erscheinungsJahr;
	if (contr.findePosFilmInRepo(titel, erscheinungsJahr) != -1) {
		contr.addFilmToWatchlist(contr.findeFilmInRepo(titel, erscheinungsJahr));
		cout << "Film successfully added to the WatchList!" << endl;
	}
	else {
		cout << "No such Film with the given Titel and release Year \n" << endl;
	}
}

void UI::deleteFilmFromWatchlist() {
	/*
	takes user input, deletes a Film and Handels Exceptions
	*/
	string titel;
	cout << "Enter a titel: ";
	cin >> titel;
	int erscheinungsJahr;
	cout << "Enter erscheinungsJahr: ";
	cin >> erscheinungsJahr;
	if (contr.findePosFilmInRepoWatchlist(titel, erscheinungsJahr) != -1) {
		contr.deleteFilmFRomWatchList(titel, erscheinungsJahr);
		cout << "Film successfully deleted from Watchlist \n";
	}
	else {
		cout << "No such Film with the given Titel and release Year \n";
	}
}

void UI::like(int i) {
	/*
	increase the number of Likes of a Film by one
	*/
	contr.like(contr.get_vectorFilmBenutzer()[i]);
}

void UI::sortFilmGenre() {
	/*
	takes input from the user and sorts the film after the given genre
	*/
	string genre;
	cout << "Enter Genre: ";
	cin >> genre;
	vector <Film> vec =contr.sortFilmGenre(genre);
	if (vec.size() == 0)
		cout << "There is no Film with the given genre \n";
	else {
		cout << "List Films sorted after genre: \n";
		showListaFilme(vec);
	}
}

void UI::runTrailer(int i) {
	/*
	runs the trailer of the current Film
	*/
	string url = contr.get_vectorFilmBenutzer()[i].get_trailer();
	//wstring ws(url.begin(), url.end());
	//LPCWSTR ls = ws.c_str(); 

//	int n = url.length();

	//char char_array[n + 1];

	//strcpy(char_array, url.c_str());

	//ShellExecute(NULL, "open" , url.c_str(), NULL, NULL, SW_SHOWNORMAL);
	system(std::string("start " + url).c_str());
}

void UI::add10Films() {
	/*
	adds 10 Films to the FilmRepo
	*/
		contr.addFilmToRepo("film1", "gen1", 2001, 21, "https://www.youtube.com/watch?v=20bpjtCbCz0");
		contr.addFilmToRepo("film2", "gen2", 2002, 22, "https://www.youtube.com/watch?v=ewlwcEBTvcg");
		contr.addFilmToRepo("film3", "gen3", 2003, 23, "https://www.youtube.com/watch?v=ijXruSzfGEc");
		contr.addFilmToRepo("film4", "gen1", 2004, 24, "https://www.youtube.com/watch?v=zSWdZVtXT7E");
		contr.addFilmToRepo("film1", "gen5", 2005, 25, "https://www.youtube.com/watch?v=YoHD9XEInc0");
		contr.addFilmToRepo("film6", "gen6", 2006, 26, "https://www.youtube.com/watch?v=SUXWAEX2jlg");
		contr.addFilmToRepo("film7", "gen7", 2007, 27, "https://www.youtube.com/watch?v=1Fg5iWmQjwk");
		contr.addFilmToRepo("film8", "gen8", 2008, 28, "https://www.youtube.com/watch?v=8ndhidEmUbI");
		contr.addFilmToRepo("film9", "gen9", 2009, 29, "https://www.youtube.com/watch?v=2QKg5SZ_35I");
		contr.addFilmToRepo("film10", "gen10", 2010, 30, "https://www.youtube.com/watch?v=Xr3sEnOmsFc");

		cout << "10 films added \n";
 
	
}


void UI::menuAdmin() {
	/*
	prints the Admin menu
	*/
	cout << "1 - Show Lista Filme \n2 - Add Film \n3 - Delete Film \n4 - Update Film \n5 - Exit \n6 - add10Films\n" ;
	cout<<"Enter Option :";
}

void UI::menuUpdateFilm() {
	/*
	prints the update menu
	*/
	cout << "1 - Update Titel \n2 - Update Genre \n3 - Update erscheinungsJahr \n";
	cout << "4 - Update AnzahlLikes \n5 - Update Trailer \n6 - Exit \nEnter Option: ";
}

void UI::updateInterface() {
	/*
	update interface
	*/
	int optu;
	bool run = true;
	while (run) {
		menuUpdateFilm();
		cin >> optu;
		switch (optu) {
		case 1:
			updateFilmTitel();
			break;
		case 2:
			updateFilmGenre();
			break;
		case 3:
			updateFilmErscheinungsJahr();
			break;
		case 4:
			updateFilmeAnzahlLikes();
			break;
		case 5:
			updateFilmeTrailer();
			break;
		default:
			run = false;
			break;
		}
	}


}

void UI::adminInterface() {
	/*
	admin interface
	*/
	int opt;
	bool run = true;
	while (run) {
		menuAdmin();
		cin >> opt;
		switch (opt) {
		case 1:
			showListaFilme(contr.get_vectorFilme());
			break;
		case 2:
			addFilm();
			break;
		case 3:
			deleteFilm();
			break;
		case 4:
			updateInterface();
			break;
		case 5:
			run = false;
			break;
		case 6:
			add10Films();
			break;
		default:
			cout << "Invalid option! \n";
		}
	}
}

void UI::menuUser() {
	/*
	prints user menu
	*/
	cout << "1 - Show WatchList \n2 - Add Film to Watchlist \n3 - Delete Film form Watchlist \n";
	cout << "4 - Like \n5 - Sort after Genre \n6 - Watch Trailer \n7 - next Film \n8 - prev Film \n9 - Exit \nEnter Option: ";
}

void UI::userInterface() {
	/*
	user interface
	*/
	int opt,i =0;
	bool run = true;
	while (run) {
		if (contr.get_vectorFilmBenutzer().size() != 0) {
			cout << "Current Film: \n";
			showFilm(contr.get_vectorFilmBenutzer()[i]);
		}
		menuUser();
		cin >> opt;
		switch (opt) {
		case 1:
			showListaFilme(contr.get_vectorFilmBenutzer());
			break;
		case 2:
			addFilmToWatchlist();
			break;
		case 3:
			deleteFilmFromWatchlist();
			break;
		case 4:
			like(i);
			break;
		case 5:
			sortFilmGenre();
			break;
		case 6:
			runTrailer(i);
			break;
		case 7:
			if (i < contr.get_vectorFilmBenutzer().size()-1)
				i += 1;
			else
				cout << "No more next Films \n";
			break;
		case 8:
			if (i >= 1)
				i -= 1;
			else
				cout << "No more prev Films \n";
			break;
		case 9:
			run = false;
			break;
		}
	}
}

void UI::initalInterface() {
	/*
	initial Interface
	*/
	int opt;
	bool run = true;
	while (run) {
		cout << "1 - Admin\n2 - User \n3 - Exit \n4 - Tests \nChose Mode: ";
		cin >> opt;
		if (opt == 1)
			adminInterface();
		else if (opt == 2)
			userInterface();
		else if (opt == 4) {
			//testController();
			cout << "All test completed! :D\n";
		}
		else
			run = false;
	}
}
