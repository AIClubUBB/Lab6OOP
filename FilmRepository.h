#pragma once
#include "Film.h"
#include <vector>
#include <fstream>
using namespace std;
class FilmRepository
{
private:
	vector<Film> vectorFilme;

public:
	vector<Film> get_vectorFilme();
	void set_vectorFilme(vector<Film> & vectorFilme);
	void addFilm(Film &film);
	int findePosFilmInVector(string titel, int erscheinungsJahr);
	Film &findeFilmInVector(string titel, int erscheinungsJahr);
	void deleteFilm(string titel, int erscheinungsJahr);
	void updateFilmTitel(string titel, int erscheinungsJahr,string newTitle);
	void updateFilmGenre(string titel, int erscheinungsJahr, string newGenre);
	void updateFilmErscheinungsJahr(string titel, int erscheinungsJahr, int newErscheinungsJahr);
	void updateFilmAnzahlLikes(string titel, int erscheinungsJahr, int newAnzahlLikes);
	void updateFilmTrailer(string titel, int erscheinungsJahr, string newTrailer);
	void writeToFileFilm();
	void readFromFileFilm();
	FilmRepository();
	~FilmRepository();
};

void testRepo();
