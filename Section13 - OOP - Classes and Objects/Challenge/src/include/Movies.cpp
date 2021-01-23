#include <iostream>
#include "Movies.h"

Movies::Movies() : movies {} { }

Movies::Movies(const Movies &source) : movies {source.movies} { }

Movies::~Movies() { }

void Movies::add_movie(std::string movie_name,
                       std::string movie_rating,
                       int watched) {
    bool movie_exists_flag {false};
    for (const auto &movie: movies) {
        if (movie.movie_name == movie_name) {
            movie_exists_flag = true;
            std::cout << movie_name << " already exists" << std::endl;
        }
    }
    if (!movie_exists_flag) {
        movies.push_back(Movie(movie_name, movie_rating, watched));
    }
}

void Movies::watch_movie(std::string movie_name) {
    bool movie_exists_flag {false};
    for (auto &movie: movies) {
        if (movie.movie_name == movie_name) {
            movie_exists_flag = true;
            ++movie.watched;
        }
    }
    if (!movie_exists_flag) {
        std::cout << movie_name << " doesn't exist" << std::endl;
    }
}

void Movies::display_all_movies() const {
    if (movies.size() == 0) {
        std::cout << "Sorry, no movies to display" << std::endl;
    } else {
        for (const auto &movie: movies) {
            std::cout << movie.movie_name << ", ";
            std::cout << movie.movie_rating << ", ";
            std::cout << movie.watched << std::endl;
        }
        std::cout << "--------------------------------" << std::endl;
    }
}