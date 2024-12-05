//
// Created by mara on 3/24/2024.
//

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>
#include "service.h"
#include "Exceptions.h"

using namespace std;

Service::Service(const std::string& file_name):  repository(file_name), file_name(file_name){
    //this->repository = Repository(file_name);
    this->adminCredentials = false;
    this->wl= nullptr;
    //this->watchlist = watchlist;
}

Service::~Service(){
    delete this->wl;
}

void Service::setAdminCredentials(bool adminCredentials)
{
    this->adminCredentials = adminCredentials;
}

bool Service::getAdminCredentials()
{
    return this->adminCredentials;
}

bool Service::addService(const Movie& movie){
//    if (this->repository.checkUnique(movie) == 0) {
//        throw RepositoryException();
//    }
//
//    this->repository.addRepo(movie);
//    return true;
    try {
        MovieExceptions::validateMovieIdentifiers(movie.getTitle(), movie.getGenre(), std::to_string(movie.getYear()), movie.getTrailer(), std::to_string(movie.getLikes()));
        if (!this->repository.checkUnique(movie)) {
            throw RepositoryException("Movie already exists in the repository!");
        }
        this->repository.addRepo(movie);
        return true;
    } catch (const RepositoryException &ex) {
        throw;
    } catch (const RepositoryException &ex) {
        throw;
    }
}

vector<Movie> Service::getMoviesService() const{
    return this->repository.getMoviesRepo();
}

int Service::getLengthService() const {
    return this->repository.getLengthRepo();
}

Movie Service::getMovieOnPositionService(int position) const{
    if (position>getMoviesService().size())
        throw PositionException();
    return this->repository.getMovieOnPositionRepo(position);
}

bool Service::removeService(Movie &movie){
    return this->repository.removeRepository(movie);
}

void Service::updateMovieService(const int position, const Movie& movie){
    this->repository.updateMovieRepo(position, movie);
}

int Service::findMoviePosition(const Movie& movie) const {
    const vector<Movie>& movies = this->getMoviesService();
    for (int i = 0; i < movies.size(); ++i) {
        if (movies[i] == movie) {
            return i; // Return the position if the movie is found
        }
    }
    return -1; // Return -1 if the movie is not found
}


bool Service::compareGenre(const string &first, const string &second) const{
    if (first != second)
        return false;
    return true;
}

vector<Movie> Service::getMoviesByGenre(const std::string &genreFromUser) const{
    vector<Movie> positionsByGenre;
    for (const auto& movie : getMoviesService()){
        //Movie movie = getMovieOnPositionService(i);
        string genre = movie.getGenre();
        if (genreFromUser == "" || compareGenre(genre, genreFromUser))
            positionsByGenre.push_back(movie);
    }
    return positionsByGenre;
}

void Service::openTrailer(int moviePos){
    Movie movie = this->getMovieOnPositionService(moviePos);
    std::string linkTrailer = movie.getTrailer();
    std::string command = "start " + linkTrailer;
    system(command.c_str());
}

void Service::addMovieToWatchList(const Movie& movie){
    //this->watchlist.push_back(movie);
    this->wl->addMovie(movie);
}

vector<Movie> Service::getMoviesTheUserLikes() const{
    //return watchlist;
    return this->wl->getMovies();
}

//int Service::getLengthWatchlist() const {
//    //return watchlist.size();
//    //return this->wl.soz
//}

Movie Service::getMovieOnPositionWatchList(int position) const{
    //return watchlist[position];
    if (position>=getMoviesTheUserLikes().size())
        throw PositionException();
    return this->wl->getMovieOnPosition(position);
}

void Service::removeWatchList(int pos){
    //watchlist.erase(watchlist.begin()+pos);
    this->wl->removeMovieFromPlaylist(pos);
}

void Service::increaseLikesOfMovie(int pos){
    Movie movie = this->getMovieOnPositionWatchList(pos);
    int new_pos = this->repository.getPositionRepo(movie);
    this->repository.increaseLikesOfMovieRepo(new_pos);
}

void Service::writeService(const std::string& file_name){
    return repository.write(file_name);
}

void Service::setTypeOfWatchList(FileWatchList *watchList)
{
    this->wl = watchList;
}

void Service::displayPlaylist(){
    this->wl->openInApp();
}

Movie Service::findMovieByTrailer(const std::string& trailer) {
    return this->repository.findMovieByTrailer(trailer);
}