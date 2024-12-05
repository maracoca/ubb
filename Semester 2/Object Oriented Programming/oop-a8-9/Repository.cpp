//
// Created by mara on 3/24/2024.
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include "Repository.h"
using namespace std;

Repository::Repository(const std::string& file_name): file_name(file_name){
    this->movies = vector<Movie>();
    read(file_name);
}

Repository::~Repository(){}

void Repository::addRepo(const Movie& movie){
    movies.push_back(movie);
    write(this->file_name);
}

vector<Movie> Repository::getMoviesRepo() const{
    return this->movies;
}

int Repository::getLengthRepo() const{
    return movies.size();
}


bool Repository::checkUnique(const Movie& movieToCheck) const{
    for (const auto& movie : movies) {
        //Movie movie = getMovieOnPositionRepo(i);
        if (movieToCheck.getTitle() == movie.getTitle() && movieToCheck.getGenre() == movie.getGenre())
            return 0;
        else if (movieToCheck.getTrailer() == movie.getTrailer())
            return 0;
    }
    return 1;
}

Movie Repository::getMovieOnPositionRepo(int position) const{
    return movies[position];
}

int Repository::getPositionRepo(const Movie& movieToFind) {
    int i = 0;
    for (const auto& movie : movies) {
//        Movie movie = getMovieOnPositionRepo(i);
        if (movieToFind.getTitle() == movie.getTitle() && movieToFind.getGenre() == movie.getGenre())
            return i;
        i++;
    }
    return -1;
}

bool Repository::removeRepository(Movie& movie){
    vector<Movie>::iterator it;
    it = find(movies.begin(), movies.end(), movie);
    if (it != movies.end()) {
        movies.erase(it);
        write(this->file_name);
        return true;
    } else {
        return false;
    }

}

void Repository::updateMovieRepo(const int position, const Movie& movie){
    //if (position )
    movies[position] = movie;
    write(this->file_name);
}

void Repository::increaseLikesOfMovieRepo(int pos){
    Movie movieToBeUpdated = getMovieOnPositionRepo(pos);
    movieToBeUpdated.setLikes(movieToBeUpdated.getLikes() + 1);
    updateMovieRepo(pos, movieToBeUpdated);
}

void Repository::read(const std::string& file_name){
    ifstream fi(file_name);
    if (!fi.is_open())
        return;

    movies.clear();
    Movie movie{};
    while (fi >> movie){
       movies.push_back(movie);
    }
    fi.close();
}

void Repository::write(const std::string& file_name){
    ofstream fo(file_name);
    if (!fo.is_open())
        return;

    vector<Movie> allMovies = getMoviesRepo();
    for (const auto& s : allMovies){
        fo << s;
    }
    fo.close();
}

Movie Repository::findMovieByTrailer(const std::string& trailer) {
    for (const auto &movie: this->movies) {
        if (movie.getTrailer() == trailer) {
            return movie;
        }
    }
}