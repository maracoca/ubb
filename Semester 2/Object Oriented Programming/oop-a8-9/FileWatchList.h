//
// Created by mara on 4/27/2024.
//
#pragma once
#ifndef OOP_A6_7_MARACOCA_FILEWATCHLIST_H
#define OOP_A6_7_MARACOCA_FILEWATCHLIST_H

#include "Movie.h"
//#include "WatchList.h"
#include <vector>
#include <fstream>

class FileWatchList {
protected:
    std::vector<Movie> movies;
    std::string fileName;

public:
    FileWatchList(const std::string &fileName) : fileName(fileName) {}
    virtual ~FileWatchList() {}
    void addMovie(const Movie &);
    void removeMovieFromPlaylist(int);
    std::vector<Movie> getMovies() const { return this->movies; }
    void openInApp() const;
    virtual void writeToFile() const=0;
    Movie getMovieOnPosition(int position) const;
};


//class FileWatchList : public FileWatchList
//{
//protected:
//    std::string fileName;
//
//public:
//    FileWatchList(const std::string &fileName) : fileName{fileName} {}
//    virtual void writeToFile() const = 0;
//    void openInApp() const;
//    virtual ~FileWatchList(){};
//};



#endif //OOP_A6_7_MARACOCA_FILEWATCHLIST_H
