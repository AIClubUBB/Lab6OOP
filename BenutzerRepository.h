#pragma once
#include <vector>
#include "Film.h"
#include <fstream>
using namespace std;
class BenutzerRepository
{
private:
	vector<Film> WatchList;
public:
	vector<Film> & get_WatchList();
	void set_watchList(vector<Film> &watchlist);
	void addFilmToWatchList(Film &film);
	int findePosFilmInWatchlist(string titel, int erscheinungsJahr);
	Film &findeFilmInWatchlist(string titel, int erscheinungsJahr);
	void deleteFilmFromWatchList(string titel, int erscheinungsJahr);
	void writeToFileBen();
	void readFromFileBen();
	void like(Film &film);
	BenutzerRepository();
	~BenutzerRepository();
};