//
// Created by mara on 3/24/2024.
//

#ifndef OOP_A4_5_MARACOCA_SERVICE_H
#define OOP_A4_5_MARACOCA_SERVICE_H

#pragma once
#include "service.h"
#include "Repository.h"
#include "FileWatchList.h"

class Service {
private:
    Repository repository;
    bool adminCredentials;
   // vector<Movie> watchlist;
    string file_name;
    FileWatchList *wl;

public:
    Service(const std::string& file_name);
    ~Service();
    void setAdminCredentials(bool adminCredentials);
    bool getAdminCredentials();
    bool addService(const Movie& movie);
    vector<Movie> getMoviesService() const;
    int getLengthService() const;
    void generate10RandomMovies();
    Movie getMovieOnPositionService(int position) const;
    bool removeService(Movie &movie);
    void updateMovieService(const int position, const Movie& movie);
    bool compareGenre(const string &first, const string &second) const;
    vector<Movie> getMoviesByGenre(const std::string &genreFromUser) const;
    void openTrailer(int moviePos);
    void addMovieToWatchList(const Movie& movie);
    vector<Movie> getMoviesTheUserLikes() const;
    //int getLengthWatchlist() const;
    Movie getMovieOnPositionWatchList(int position) const;
    void removeWatchList(int pos);
    void increaseLikesOfMovie(int pos);
    void writeService(const std::string& file_name);
    void setTypeOfWatchList(FileWatchList *watchList);
    void displayPlaylist();
    int findMoviePosition(const Movie& movie) const;
    Movie findMovieByTrailer(const std::string& trailer);
};

#endif //OOP_A4_5_MARACOCA_SERVICE_H
