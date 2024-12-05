//
// Created by mara on 3/24/2024.
//
#pragma once
#ifndef OOP_A4_5_MARACOCA_MOVIE_H
#define OOP_A4_5_MARACOCA_MOVIE_H

#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Movie{
private: //only available in this class
    string title; //attributes, properties
    string genre;
    int year;
    int nr_likes;
    string trailer;


public:
    Movie(const string& title="", const string& genre="", int year = 0, int likes = 0, const string& trailer="");

    Movie(const Movie &movie);

    ~Movie();
    std::string getTitle() const;
    std::string getGenre() const;
    std::string getTrailer() const;
    int getYear() const;
    int getLikes() const;
    //void checkTitle(const string& title) const;
//    void checkGenre(const string& genre) const;
//    void checkYear(const int year) const;
//    void checkLikes(const int likes) const;
//    void checkTrailer(const string& trailer) const;
    void setTitle(const std::string &title);
    void setGenre(const std::string &genre);
    void setTrailer(const std::string &trailer);
    void setLikes(int nr_likes);
    void setYearRelease(int year_release);
    bool operator==(const Movie &movie) const;
    friend std::istream& operator>>(std::istream& is, Movie& movie);
    friend std::ostream& operator<<(std::ostream & os, const Movie& movie);
    string toString() const;
};

class MovieExceptions{
private:
    vector<invalid_argument> errors;
public:
    MovieExceptions(vector<invalid_argument> errors);
    MovieExceptions(string error);
    vector<invalid_argument> returnErrors();
    static void checkTitle(const string& genre) ;
    static void checkGenre(const string& genre) ;
    static void checkYear(const string &year) ;
    static void checkLikes(const string &likes)  ;
    static void checkTrailer(const string& trailer) ;
    static void validateMovieIdentifiers(const std::string &, const std::string &, const std::string &, const std::string &, const std::string &);
};

#endif //OOP_A4_5_MARACOCA_MOVIE_H
