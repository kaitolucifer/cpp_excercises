#include <iostream>
#include "Movies.h"

using namespace std;

int main()
{
    Movies movies {};
    movies.add_movie("Star Wars", "PG", 5);
    movies.add_movie("Big", "PG-13", 2);
    movies.add_movie("Cinderella", "PG", 7);
    movies.display_all_movies();
    movies.add_movie("Star Wars", "PG", 5);
    movies.add_movie("Ice Age", "PG", 12);
    movies.watch_movie("Star Wars");
    movies.display_all_movies();
    movies.watch_movie("XXX");
    return 0;
}