// Lab5.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include<string>
#include "UI.h"

using namespace std;

int main()
{
	BenutzerRepository repoBen;
	FilmRepository repoFilm;

	Controller contr(repoFilm, repoBen);
	UI ui(contr);
	ui.initalInterface();
	return 0;
}

