#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>

class Movies;

class Movie {
    friend class Movies;
    private:
        static int num_movies;
        std::string movie_name;
        std::string movie_rating;
        int watched;

    public:
        std::string get_movie_name() {return movie_name;}
        std::string get_movie_rating() {return movie_rating;}
        Movie(std::string movie_name, std::string movie_rating, int watched = 0);
        Movie(const Movie &source);
        Movie (Movie &&source);
        ~Movie();

        static int get_num_movies();
};

#endif // _MOVIE_H_