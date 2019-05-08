#pragma once
#include "FilmRepository.h"
#include "BenutzerRepository.h"
using namespace std;

class Controller
{
private:
	FilmRepository filmRepo;
	BenutzerRepository benutzerRepo;
public:
	vector <Film> get_vectorFilme();
	void addFilmToRepo(string titel,string genre,int erscheinungsJahr,int anzahlLikes,string trailer);
	void deleteFilmFromRepo(string titel, int erscheinungsJahr);
	void updateFillmTitelFromRepo(string titel, int erscheinungsJahr, string newTitel);
	void updateFillmGenreFromRepo(string titel, int erscheinungsJahr, string newGenre);
	void updateFillmErscheinungsJahrFromRepo(string titel, int erscheinungsJahr, int newErscheinungsJahr);
	void updateFillmAnzahlLikesFromRepo(string titel, int erscheinungsJahr, int newAnzahlLikes);
	void updateFillmTrailerFromRepo(string titel, int erscheinungsJahr, string newTrailer);
	int findePosFilmInRepo(std::string titel, int erscheinungsJahr);
	Film &findeFilmInRepo(std::string titel, int erscheinungsJahr);



	vector <Film>& get_vectorFilmBenutzer();
	void like(Film &film);
	void addFilmToWatchlist(Film &film);
	void deleteFilmFRomWatchList(string titel, int erscheinungsJahr);
	vector <Film> sortFilmGenre(string genre);
	int findePosFilmInRepoWatchlist(string titel, int erscheinungsJahr);
	Film &findeFilmInRepoWatchlist(string titel, int erscheinungsJahr);


	Controller(FilmRepository &filmRepos, BenutzerRepository &benutzerRepo) :filmRepo( filmRepos )\
		, benutzerRepo(benutzerRepo){};
	~Controller() {};

};

//void testController();
