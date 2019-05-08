#pragma once
#include <iostream>
#include <string>

using namespace std;
class Film
{
private:
	string titel;
	string genre;
	int erscheinungsJahr;
	int anzahlLikes;
	string trailer;

public:
	Film(string titel, string genre, int erscheinungsJahr, int anzahlLikes, string trailer);
	string get_titel();
	string get_genre();
	int get_erscheinungsJahr();
	int get_anzahlLikes();
	string get_trailer();
	void set_titel(string titel);
	void set_genre(string genre);
	void set_erscheinungsJahr(int erscheinungsJahr);
	void set_anzahlLikes(int anzahlLinks);
	void set_trailer(string trailer);
	bool operator==(Film film);
	~Film();
};

void testGetters();
void testSetters();
void testFilm();

