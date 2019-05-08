#include "Controller.h"
#include <iostream>
#include <assert.h>
using namespace std;
vector<Film> Controller::get_vectorFilme(){
	return filmRepo.get_vectorFilme();
}

void Controller::addFilmToRepo(string titel, string genre, int erscheinungsJahr, int anzahlLikes, string trailer) {
	/*
	adds a film to the vectorFilme in the FilmRepo if the Film was not prior added and it's form is correct
	else throws an exception if the film is already in the FilmRepo or if it is not corectly formed
	titel, genre,trailer -string
	anzahlLikes - int positive
	*/
	if (filmRepo.findePosFilmInVector(titel, erscheinungsJahr) == -1) {
		Film film{ titel,genre,erscheinungsJahr,anzahlLikes,trailer };
		filmRepo.addFilm(film);
	}
	else
	{
		cout << "A movie with the same name and release year already exist!\n";
		//exception e;
		//throw(e);
	}//throw ("A movie with the same name and release year already exist! \n");
	//throw exception();
}

void Controller::deleteFilmFromRepo(string titel, int erscheinungsJahr) {
	/*
	deletes a film from FilmRepo of the film is In the FilmRepo
	else throws Exception
	*/
	if (filmRepo.findePosFilmInVector(titel, erscheinungsJahr) != -1) {
		filmRepo.deleteFilm(titel, erscheinungsJahr);
	}
	else cout<<"There is no movie with the given titel and release year \n";
}

void Controller::updateFillmTitelFromRepo(string titel, int erscheinungsJahr, string newTitel) {
	/*
	updates a film titel if the newTitle is valid and a a film with 
	the given titel and release year is in the FilmRepo
	else throws Exeption
	titel,newtitel - string
	erscheinungsJahr - int between 1920 and 2018
	*/
	if (filmRepo.findePosFilmInVector(titel, erscheinungsJahr) != -1) {
		Film film(newTitel, "a", 2000, 1, "a");
		filmRepo.updateFilmTitel(titel, erscheinungsJahr, newTitel);
	}
	else cout << "There is no movie with the given titel and release year \n";
}

void Controller::updateFillmGenreFromRepo(string titel, int erscheinungsJahr, string newGenre){
	/*
	updates a film genre if the newGenre is valid and a a film with
	else throws exception
	titel,newGenre - string
	erscheinungsJahr - int between 1920 and 2018

	*/
	if (filmRepo.findePosFilmInVector(titel, erscheinungsJahr) != -1) {
		Film film("a", newGenre, 2000, 1, "a");
		filmRepo.updateFilmGenre(titel, erscheinungsJahr, newGenre);
	}
	else cout << "There is no movie with the given titel and release year \n";
}

void Controller::updateFillmErscheinungsJahrFromRepo(string titel, int erscheinungsJahr, int newErscheinungsJahr) {
	/*
	updates a film erscheinungsJahr if the newErscheinungsJahr is valid and a a film with
	else throws exception
	titel - string
	erscheinungsJahr,newErscheinungsJahr - int between 1920 and 2018
	*/
	if (filmRepo.findePosFilmInVector(titel, erscheinungsJahr) != -1) {
		Film film("a", "a", newErscheinungsJahr, 1, "a");
		filmRepo.updateFilmErscheinungsJahr(titel, erscheinungsJahr, newErscheinungsJahr);
	}
	else cout << "There is no movie with the given titel and release year \n";
}

void Controller::updateFillmAnzahlLikesFromRepo(string titel, int erscheinungsJahr, int newAnzahlLikes) {
	/*
	updates a film anzahlLikes if the newAnzahlLikes is valid and a a film with
	else throws exception
	titel - string
	erscheinungsJahr - int between 1920 and 2018
	newAnzahl - int pos
	*/
	if (filmRepo.findePosFilmInVector(titel, erscheinungsJahr) != -1) {
		Film film("a", "a", 2000, newAnzahlLikes, "a");
		filmRepo.updateFilmAnzahlLikes(titel, erscheinungsJahr, newAnzahlLikes);
	}
	else cout << "There is no movie with the given titel and release year \n";
}

void Controller::updateFillmTrailerFromRepo(string titel, int erscheinungsJahr, string newTrailer) {
	/*
	updates a film titel if the newTitle is valid and a a film with
	else throws exception
	titel,newTrailer - string
	erscheinungsJahr - int between 1920 and 2018

	*/
	if (filmRepo.findePosFilmInVector(titel, erscheinungsJahr) != -1) {
		Film film("a", "a", 2000, 1, newTrailer);
		filmRepo.updateFilmTrailer(titel, erscheinungsJahr, newTrailer);
	}
	else cout << "There is no movie with the given titel and release year \n";
}

void Controller::addFilmToWatchlist(Film &film) {
	/*
	adds a film to the Wachlist
	film - Film(from FilmRepo)
	*/
	benutzerRepo.addFilmToWatchList(film);
}

void Controller::deleteFilmFRomWatchList(string titel, int erscheinungsJahr) {
	/*
	deletes a Film form the WatchList
	titel - string 
	erscheinungsJahr - int between 19200 and 2018
	*/
	benutzerRepo.deleteFilmFromWatchList(titel,erscheinungsJahr);
}

void Controller::like(Film &film) {
	/*
	increses the number of likes of a Film by 1
	film - Film
	*/
	benutzerRepo.like(film);
	int pos = filmRepo.findePosFilmInVector(film.get_titel(), film.get_erscheinungsJahr());
	int like = filmRepo.get_vectorFilme()[pos].get_anzahlLikes() + 1;
	cout << like << endl;
	/* filmRepo.get_vectorFilme()[pos].set_anzahlLikes(like);
	cout << filmRepo.get_vectorFilme()[pos].get_anzahlLikes()<< endl;
	*/
	updateFillmAnzahlLikesFromRepo(film.get_titel(), film.get_erscheinungsJahr(), like);
}

vector <Film> &Controller::get_vectorFilmBenutzer() {
	/*
	return the WahtchList
	*/
	return benutzerRepo.get_WatchList();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector <Film> Controller::sortFilmGenre(string genre) {
	/*
	sorts the vector ater genre
	genre - string
	*/
	vector <Film> vectorFilmGenre;
	for (int i = 0; i < filmRepo.get_vectorFilme().size(); i++) {
		if (filmRepo.get_vectorFilme()[i].get_genre() == genre) {
			vectorFilmGenre.push_back(filmRepo.get_vectorFilme()[i]);
		}
	}
	return vectorFilmGenre;
}

int Controller::findePosFilmInRepo(string titel, int erscheinungsJahr) {
	/*
	return the position of a film in FilmRepo
	*/
	return filmRepo.findePosFilmInVector(titel, erscheinungsJahr);
}

Film & Controller::findeFilmInRepo(string titel, int erscheinungsJahr) {
	/*
	return a Film from the FilmRepo with a given titel or erscheinungsJahr
	*/
	return filmRepo.findeFilmInVector(titel,erscheinungsJahr);
}

int Controller::findePosFilmInRepoWatchlist(string titel, int erscheinungsJahr) {
	/*
	return the position of a film in Watchlist
	*/
	return benutzerRepo.findePosFilmInWatchlist(titel, erscheinungsJahr);
}
Film &Controller::findeFilmInRepoWatchlist(string titel, int erscheinungsJahr) {
	/*
	return a Film from the WatchList with a given titel or erscheinungsJahr
	*/
	for (auto &o : benutzerRepo.get_WatchList()) {
		if (o.get_titel() == titel && o.get_erscheinungsJahr() == erscheinungsJahr)
			return o;
	}
}
