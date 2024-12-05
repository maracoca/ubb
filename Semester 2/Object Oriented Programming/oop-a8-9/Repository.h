//
// Created by mara on 3/24/2024.
//
#pragma once
#ifndef OOP_A4_5_MARACOCA_REPOSITORY_H
#define OOP_A4_5_MARACOCA_REPOSITORY_H


#include <vector>
#include "Movie.h"

class Repository{
private:
    std::vector<Movie> movies;
    std::string file_name;

public:
    Repository(const std::string& file_name);
    ~Repository();
    void addRepo(const Movie& movie);
    vector<Movie> getMoviesRepo() const;
    int getLengthRepo() const;
    bool checkUnique(const Movie& movie) const;
    Movie getMovieOnPositionRepo(int position) const;
    int getPositionRepo(const Movie& movieToFind);
    bool removeRepository(Movie& movie);
    void updateMovieRepo(const int position, const Movie& movie);
    void increaseLikesOfMovieRepo(int pos);
    void read(const std::string& file_name);
    void write(const std::string& file_name);
    Movie findMovieByTrailer(const std::string& trailer);
};

#endif //OOP_A4_5_MARACOCA_REPOSITORY_H

