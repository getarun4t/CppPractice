#include <iostream>
#include"Movies.h"
#include<algorithm>

using namespace std;

void Movies::AddMovie(string name, string rating, int times)
{   
    int flag{ 0 };
    for (auto i = movies.begin(); i != movies.end(); ++i) {
        if (i->Get_MovieName() == name) {
            cout << "Error: " << name << " already added to the list." << endl;
            flag = 1;
        }
    }
    if (!flag)
        movies.push_back({name, rating, times});
}

void Movies::DisplayAllMovies()
{
    for (auto i = movies.begin(); i != movies.end(); ++i)
        cout << i->Get_MovieName() << endl;
}

void Movies::IncrementMovieCount(string MovieName)
{
    int flag{ 0 };
    for (auto i = movies.begin(); i != movies.end(); ++i) {
        if (i->Get_MovieName() == MovieName) {
            i->IncrementWatchedCount();
            flag= 1;
        }
    }
    if (!flag)
        cout << "Error: " << MovieName << " is not present in the list"<< endl;
}
