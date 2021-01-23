#include <iostream>
#include "Movie.h"

int Movie::num_movies {0};

Movie::Movie(std::string movie_name, std::string movie_rating, int watched)
    : movie_name {movie_name}, movie_rating {movie_rating}, watched {watched} {
        ++num_movies;
    }

Movie::Movie(const Movie &source)
    : Movie {source.movie_name, source.movie_rating, source.watched} { }

Movie::Movie(Movie &&source)
    : Movie {source.movie_name, source.movie_rating, source.watched} { }

Movie::~Movie() {
    --num_movies;
}

int Movie::get_num_movies() {
    return num_movies;
}