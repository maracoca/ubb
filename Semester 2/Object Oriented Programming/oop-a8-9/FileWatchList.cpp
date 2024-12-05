//
// Created by mara on 4/27/2024.
//

#include "FileWatchList.h"
#include <fstream>
#include <cstdlib>

void FileWatchList::addMovie(const Movie &movie) {
    this->movies.push_back(movie);
}

void FileWatchList::removeMovieFromPlaylist(int positionOfMovie) {
    if (positionOfMovie >= 0 && positionOfMovie < this->movies.size())
        this->movies.erase(this->movies.begin() + positionOfMovie);
}

Movie FileWatchList::getMovieOnPosition(int position) const{
    return this->movies[position];
}

void FileWatchList::openInApp() const {
    this->writeToFile();
    std::string commandToOpenFile = "start " + this->fileName;
    system(commandToOpenFile.c_str());
}


