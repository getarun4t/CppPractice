#pragma once
#include<iostream>
#include<string>

using namespace std;

class Movie {
	string Name;
	string Rating;
	int WatchedCount;
public:
	string Get_MovieName();
	string Get_Rating();
	int Get_WatchedCount();
	void IncrementWatchedCount();
	Movie(string Name, string Rating, int WatchedCount);
};