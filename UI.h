#pragma once
#include "Controller.h"
#include <iostream>
#include <windows.h>

class UI
{
private:
	Controller contr;
	void showListaFilme(vector <Film> vec);
	void showFilm(Film &o);
	void addFilm();
	void deleteFilm();
	void updateFilmTitel();
	void updateFilmGenre();
	void updateFilmErscheinungsJahr();
	void updateFilmeAnzahlLikes();
	void updateFilmeTrailer();

	void addFilmToWatchlist();
	void deleteFilmFromWatchlist();
	void like(int i);
	void sortFilmGenre();
	void runTrailer(int i);
	void add10Films();
public:
	void menuAdmin();
	void menuUpdateFilm();
	void updateInterface();
	void menuUser();
	void adminInterface();
	void userInterface();
	void initalInterface();
	UI(Controller &contr) :contr(contr) {};
};

