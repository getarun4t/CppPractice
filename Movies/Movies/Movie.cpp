#include "Movie.h"

string Movie::Get_MovieName() { return this->Name; }
string Movie::Get_Rating() { return this->Rating; }
int Movie::Get_WatchedCount() { return this->WatchedCount; }

void Movie::IncrementWatchedCount()
{
	this->WatchedCount++;
}

Movie::Movie(string Name, string Rating, int WatchedCount) : Name{ Name }, Rating{ Rating }, WatchedCount{ WatchedCount } {}
