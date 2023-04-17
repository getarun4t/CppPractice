#include"Movies.h"

int main() {
	Movies movie_list;	
	movie_list.DisplayAllMovies();
	movie_list.AddMovie("Manichithrathazhu", "U/A", 22);
	movie_list.AddMovie("Drishyam", "A", 2);
	movie_list.DisplayAllMovies();

	movie_list.AddMovie("Manichithrathazhu", "U/A", 22);
	movie_list.DisplayAllMovies();
	movie_list.IncrementMovieCount("Manichithrathazhu");
	movie_list.IncrementMovieCount("North 24 Katham");
	movie_list.DisplayAllMovies();
}