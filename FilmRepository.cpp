#include "FilmRepository.h"
#include <assert.h>
#include <iostream>

using namespace std;

FilmRepository::FilmRepository()
{
	readFromFileFilm();
}

vector<Film> FilmRepository::get_vectorFilme() {
	/*
	returns the vectorFilme
	*/
	return vectorFilme;
}


void FilmRepository::set_vectorFilme(vector<Film> &vectorFilme) {
	/*
	sets the vectorFilme
	*/
	this->vectorFilme = vectorFilme;
}

void FilmRepository::addFilm(Film &film) {
	/*
	adds a film object to vector Filme
	film - Film Obj
	*/
	vectorFilme.push_back(film);
	this->writeToFileFilm();
}

int FilmRepository::findePosFilmInVector(string titel, int erscheinungsJahr) {
	/*
	return the position of a film with a given titel and release Year, or -1 if there is no film with the givern attributes
	titel - string
	erscheinungsJahr - int between 1920 and 2018
	*/
	int finde = -1;
	for (int i = 0; i < vectorFilme.size();i++) {
		if (vectorFilme[i].get_titel() == titel && vectorFilme[i].get_erscheinungsJahr() == erscheinungsJahr)
			finde = i;
	}
	return finde;
}

void FilmRepository::deleteFilm(string titel, int erscheinungsJahr) {
	/*
	deletes a film from the vectorFilme with a given titel and releaseYear
	titel - string
	erscheinungsJahr - int between 1920 and 2018
	*/
	int pos = findePosFilmInVector(titel, erscheinungsJahr);
	vectorFilme.erase(vectorFilme.begin()+pos);
	writeToFileFilm();
}

Film &FilmRepository::findeFilmInVector(string titel, int erscheinungsJahr) {
	/*
	reutrns a film from vectorFilme with a given titel and erscheinungsJahr
	titel - string
	erscheinungsJahr - int between 1920 and 2018
	*/
	for (auto &film : vectorFilme) {
		if (film.get_titel() == titel && film.get_erscheinungsJahr() == erscheinungsJahr)
			return film;
	}
}

void FilmRepository::updateFilmTitel(string titel, int erscheinungsJahr, string newTitle) {
	/*
	updates the titel of a film obecte
	titel - string
	erscheinungsJahr - int between 1920 and 2018
	newtitel - string
	*/
	findeFilmInVector(titel, erscheinungsJahr).set_titel(newTitle);
	writeToFileFilm();
}

void FilmRepository::updateFilmGenre(string titel, int erscheinungsJahr, string newGenre) {
	/*
	updates the genre of a film obecte
	titel - string
	erscheinungsJahr - int between 1920 and 2018
	newgenre - string
	*/
	findeFilmInVector(titel, erscheinungsJahr).set_genre(newGenre);
	writeToFileFilm();
}

void FilmRepository::updateFilmErscheinungsJahr(string titel, int erscheinungsJahr, int newErscheinungsJahr) {
	/*
	updates the release Year of a film obecte
	titel - string
	erscheinungsJahr - int between 1920 and 2018
	newErscheinungsJahr - int bewteen 1920 and 2018
	*/
	findeFilmInVector(titel, erscheinungsJahr).set_erscheinungsJahr(newErscheinungsJahr);
	writeToFileFilm();
}

void FilmRepository::updateFilmAnzahlLikes(string titel, int erscheinungsJahr, int newAnzahlLikes) {
	/*
	updates the positive of a film obecte
	titel - string
	erscheinungsJahr - int between 1920 and 2018
	newAnzahlLikes - int positive
	*/
	findeFilmInVector(titel, erscheinungsJahr).set_anzahlLikes(newAnzahlLikes);
	writeToFileFilm();
}

void FilmRepository::updateFilmTrailer(string titel, int erscheinungsJahr, string newTrailer) {
	/*
	updates the trailer of a film obecte
	titel - string
	erscheinungsJahr - int between 1920 and 2018
	newtrailer - string
	*/
	findeFilmInVector(titel, erscheinungsJahr).set_trailer(newTrailer);
	writeToFileFilm();
}

void FilmRepository::writeToFileFilm()
{
	ofstream fout("Films.txt");
	for (int i = 0; i < vectorFilme.size(); i++)
	{
		fout << vectorFilme[i].get_titel() << " ";
		fout << vectorFilme[i].get_genre() << " ";
		fout << vectorFilme[i].get_erscheinungsJahr() << " ";
		fout << vectorFilme[i].get_anzahlLikes() << " ";
		fout << vectorFilme[i].get_trailer() << "\n";
	}
	fout.close();
}

void FilmRepository::readFromFileFilm()
{
	ifstream fin("Films.txt");
	string title = "";
	string genre = "";
	string trailer = "";
	int year,likes;
	vectorFilme.clear();
	while (fin>>title)
	{
		fin >> genre >> year >> likes >> trailer;
		vectorFilme.push_back(Film(title,genre,year,likes,trailer));
	}
	fin.close();
}

FilmRepository::~FilmRepository()
{
}

void testaddeleteFilm() {
	FilmRepository Repo;
	Film film1("film1", "gen1", 2001, 21, "trailer1");
	Film film2("film2", "gen2", 2002, 22, "trailer2");
	Film film3("film3", "gen3", 2003, 23, "trailer3");
	Film film4("film4", "gen4", 2004, 24, "trailer4");
	Repo.addFilm(film1);
	assert(Repo.get_vectorFilme().size() == 1);
	Repo.addFilm(film2);
	assert(Repo.get_vectorFilme().size() == 2);
	assert(Repo.get_vectorFilme()[0] == film1);
	assert(Repo.get_vectorFilme()[1] == film2);
	Repo.deleteFilm(film1.get_titel(), film1.get_erscheinungsJahr());
	assert(Repo.get_vectorFilme().size() == 1);
}

void testupdates() {
	FilmRepository Repo;
	Film film1("film1", "gen1", 2001, 21, "trailer1");
	Film film2("film2", "gen2", 2002, 22, "trailer2");
	Film film3("film3", "gen3", 2003, 23, "trailer3");
	Film film4("film4", "gen4", 2004, 24, "trailer4");
	Repo.addFilm(film1);
	Repo.addFilm(film2);
	Repo.updateFilmTitel("film1", 2001, "f1");
	assert(Repo.get_vectorFilme()[0].get_titel() == "f1");
	Repo.updateFilmGenre("f1", 2001, "g1");
	assert(Repo.get_vectorFilme()[0].get_genre() == "g1");
	Repo.updateFilmErscheinungsJahr("f1", 2001, 2011);
	assert(Repo.get_vectorFilme()[0].get_erscheinungsJahr() == 2011);
	Repo.updateFilmAnzahlLikes("f1", 2011, 1);
	assert(Repo.get_vectorFilme()[0].get_anzahlLikes() == 1);
	Repo.updateFilmTrailer("f1", 2011, "t1");
	assert(Repo.get_vectorFilme()[0].get_trailer() == "t1");
}

void testRepo() {
	testFilm();
	testaddeleteFilm();
	testupdates();
}