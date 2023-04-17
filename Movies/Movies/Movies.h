#pragma once
#include "Movie.h"
#include<string>
#include<vector>

using namespace std;

class Movies {
	vector<Movie> movies;
public:
	void AddMovie(string name, string rating, int times);
	void DisplayAllMovies();
	void IncrementMovieCount(string MovieName);
};