#pragma once
#include <iostream>
#include <string>
#include "Film.h"
#include <assert.h>
using namespace std;
Film::Film(string titel, string genre, int erscheinungsJahr, int anzahlLikes, string trailer)
/*
constructor for a film object
*/
{
	this->titel = titel;
	this->genre = genre;
	this->erscheinungsJahr = erscheinungsJahr;
	this->anzahlLikes = anzahlLikes;
	this->trailer = trailer;
}


string Film::get_titel() {
	/*////////////////////////////////////////
	return the titel of a film obj
	*/
	return titel;
}

string Film::get_genre() {
	/*
	return the genre of a film object
	*/
	return genre;
}

int Film::get_erscheinungsJahr() {
	/*
	return the releas year of a film object
	*/
	return erscheinungsJahr;
}

int Film::get_anzahlLikes() {
	/*
	return the number of like of a film object
	*/
	return anzahlLikes;
}

string Film::get_trailer(){
	/*
	return the trailer of a film object
	*/
	return trailer;
}


void Film::set_titel(string titel) {
	/*
	sets the titel of a film object
	titel - string
	*/
	this->titel = titel;
}

void Film::set_genre(string genre) {
	/*
	sets the Genre of a Film object
	genre - string
	*/
	this->genre = genre;
}

void Film::set_erscheinungsJahr(int erscheinungsJahr) {
	/*
	sets the releas year of a film object
	erscheinungsJahr - int between 1920 and 2018
	*/
	this->erscheinungsJahr = erscheinungsJahr;
}

void Film::set_anzahlLikes(int anzahlLikes) {
	/*
	sets the number of likes of a Film Object
	anzahlLikes - int, positive
	*/
	this->anzahlLikes = anzahlLikes;
}

void Film::set_trailer(string tailer) {
	this->trailer = tailer;
}

bool Film::operator==(Film film) {
	/*
	overloads the operator == for film Objects
	returns true if two movies have the same titel and releas Year
	film - Film
	*/
	if (this->titel == film.get_titel() && (this->erscheinungsJahr == film.get_erscheinungsJahr()))
		return true;
	else
	return false;
}

void testGetters() {
	Film film1("film1", "gen1", 2001, 21, "trailer1");
	Film film2("film2", "gen2", 2002, 22, "trailer2");
	Film film3("film3", "gen3", 2003, 23, "trailer3");
	Film film4("film4", "gen4", 2004, 24, "trailer4");
	assert(film1.get_titel() == "film1");
	assert(film2.get_genre() == "gen2");
	assert(film3.get_erscheinungsJahr() == 2003);
	assert(film4.get_anzahlLikes() == 24);
	assert(film1.get_trailer() == "trailer1");
}

void testSetters() {
	Film film1("film1", "gen1", 2001, 21, "trailer1");
	Film film2("film2", "gen2", 2002, 22, "trailer2");
	Film film3("film3", "gen3", 2003, 23, "trailer3");
	Film film4("film4", "gen4", 2004, 24, "trailer4");
	film1.set_titel("f1");
	film2.set_genre("g2");
	film3.set_erscheinungsJahr(2013);
	film4.set_anzahlLikes(1);
	film1.set_trailer("t");
	assert(film1.get_titel() == "f1");
	assert(film2.get_genre() == "g2");
	assert(film3.get_erscheinungsJahr() == 2013);
	assert(film4.get_anzahlLikes() == 1);
	assert(film1.get_trailer() == "t");
}

void testFilm() {
	testGetters();
	testSetters();
}

Film::~Film()
{
}
