#include <iostream>
#include "BenutzerRepository.h"
using namespace std;

BenutzerRepository::BenutzerRepository()
{
	readFromFileBen();
}


vector<Film> & BenutzerRepository::get_WatchList() {
	/*
	return  vector Watchlist
	*/
	return WatchList;
}

void BenutzerRepository::set_watchList(vector<Film> &watchlist) {
	/*
	sets the vector Watchlist
	*/
	this->WatchList = watchlist;
}

void BenutzerRepository::addFilmToWatchList(Film &film) {
	/*
	adds a film to the WatchList
	film - Film
	*/
	WatchList.push_back(film);
	writeToFileBen();
}

int BenutzerRepository::findePosFilmInWatchlist(string titel, int erscheinungsJahr) {
	/*
	return the position of a film in the Watch with the given titel and ersceinungsJahr or -1 if there is no such film in Watchlist
	titel - string
	erscheinungsJahr - int positive
	*/
	int finde = -1;
	for (int i = 0; i < WatchList.size(); i++) {
	//for (auto &i : WatchList) {
		if (WatchList[i].get_titel() == titel && WatchList[i].get_erscheinungsJahr() == erscheinungsJahr)
			return i;
	}
}

void BenutzerRepository::deleteFilmFromWatchList(string titel, int erscheinungsJahr) {
	/*
	deletes a film from the Wathclist
	titel -string
	erscheinungsJahr - int positive
	*/
	int pos = findePosFilmInWatchlist(titel, erscheinungsJahr);
	WatchList.erase(WatchList.begin() + pos);
	writeToFileBen();
}

Film & BenutzerRepository::findeFilmInWatchlist(string titel, int erscheinungsJahr) {
	/*
	returns the film with the given titel and releaaseYear from the Watchlist
	*/
	for (auto &i : WatchList) {
		if (i.get_titel() == titel && (i.get_erscheinungsJahr() == erscheinungsJahr))
			return i;
	}
}

void BenutzerRepository::like(Film &film) {
	film.set_anzahlLikes(film.get_anzahlLikes() + 1);
	writeToFileBen();
}

BenutzerRepository::~BenutzerRepository()
{
}

void BenutzerRepository::writeToFileBen()
{
	ofstream f("Watchlist.txt");
	for (int i = 0; i < WatchList.size(); i++)
	{
		f << WatchList[i].get_titel() << " ";
		f << WatchList[i].get_genre() << " ";
		f << WatchList[i].get_erscheinungsJahr() << " ";
		f << WatchList[i].get_anzahlLikes() << " ";
		f << WatchList[i].get_trailer() << "\n";
	}
	f.close();
}

void BenutzerRepository::readFromFileBen()
{
	ifstream g("Watchlist.txt");
	string title = "";
	string genre = "";
	string trailer = "";
	int year, likes;
	WatchList.clear();
	while (g >> title)
	{
		g >> genre >> year >> likes >> trailer;
		WatchList.push_back(Film(title, genre, year, likes, trailer));
	}
	g.close();
}
