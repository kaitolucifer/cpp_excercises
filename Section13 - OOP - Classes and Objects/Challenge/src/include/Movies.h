#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <string>
#include <vector>
#include "Movie.h"

class Movies {
    private:
        std::vector<Movie> movies;

    public:
        void add_movie(std::string movie_name, std::string movie_rating, int watched);
        void watch_movie(std::string movie_Name);
        void display_all_movies() const;
        Movies();
        Movies(const Movies&source);
        ~Movies();
};

#endif // _MOVIE_H_