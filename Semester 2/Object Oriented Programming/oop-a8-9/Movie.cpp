//
// Created by mara on 3/24/2024.
//

#include "Movie.h"
#include <iostream>
#include <regex>

using namespace std;

Movie::Movie(const std::string &title, const std::string &genre, int year, int nr_likes, const std::string &trailer) : title{title}, genre{genre}, year{year}, nr_likes{nr_likes}, trailer{trailer}{}
Movie::Movie(const Movie &movie)
{
    this->title = movie.title;
    this->genre = movie.genre;
    this->year = movie.year;
    this->nr_likes = movie.nr_likes;
    this->trailer = movie.trailer;
}

Movie::~Movie(){}

std::string Movie::getTitle() const{
    return this->title;
}

std::string Movie::getGenre() const{
    return this->genre;
}

std::string Movie::getTrailer() const{
    return this->trailer;
}

int Movie::getYear() const{
    return this->year;
}
int Movie::getLikes() const{
    return this->nr_likes;
}

void Movie::setTitle(const std::string &title){
    this->title = title;
}

void Movie::setGenre(const std::string &genre){
    this->genre = genre;
}

void Movie::setTrailer(const std::string &trailer){
    this->trailer = trailer;
}

void Movie::setLikes(int like) {
//    this->checkLikes(like);
    this->nr_likes=like;
}

void Movie::setYearRelease(int year_release) {
//    this->checkYear(year_release);
    this->year=year_release;
}

MovieExceptions::MovieExceptions(std::vector<std::invalid_argument> errors)
{
    this->errors = errors;
}

vector<invalid_argument> MovieExceptions::returnErrors(){
    return this->errors;
}


MovieExceptions::MovieExceptions(std::string error)
{
    this->errors.push_back(std::invalid_argument(error));
}

void MovieExceptions::checkTitle(const string& title) {
    if (title.empty())
        throw std::invalid_argument("Title cannot be empty.");
}

void MovieExceptions::checkGenre(const string& genre) {
    if (genre.empty())
        throw std::invalid_argument("Genre cannot be empty.");
}

void MovieExceptions::checkYear(const string &year) {
    int yearInt;
    try{
        yearInt = stoi(year);
    }
    catch (const std::exception &e)
    {
        throw std::invalid_argument("The year of release of the movie must be an integer!");
    }

    if (yearInt < 0)
        throw std::invalid_argument("Year must be a positive integer.");
}

void MovieExceptions::checkLikes(const string &likes) {
    int likesInt;
    try{
        likesInt = stoi(likes);
    }
    catch (const std::exception &e)
    {
        throw std::invalid_argument("The year of release of the movie must be an integer!");
    }
    if (likesInt < 0)
        throw std::invalid_argument("Likes must be a positive integer.");
}

void MovieExceptions::checkTrailer(const string& trailer) {
    if (trailer.empty())
        throw std::invalid_argument("Trailer cannot be empty.");
    std::regex trailer_regex("https?:\\/\\/(www\\.)?youtube\\.com\\/.*");
    if (!std::regex_match(trailer, trailer_regex))
        throw std::invalid_argument("Invalid trailer link");
}

void MovieExceptions::validateMovieIdentifiers(const string &title, const string &genre, const string &year, const string &trailer, const string &likes)
{
    vector<invalid_argument> errors;
    try{
        checkTitle(title);
    }
    catch (const invalid_argument &error){
        errors.push_back(error);
    }
    try{
        checkGenre(genre);
    }
    catch (const invalid_argument &error){
        errors.push_back(error);
    }
    try{
        checkYear(year);
    }
    catch (const std::invalid_argument &error){
        errors.push_back(error);
    }
    try{
        checkLikes(likes);
    }
    catch (const std::invalid_argument &error)
    {
        errors.push_back(error);
    }
    try{
        checkTrailer(trailer);
    }
    catch (const std::invalid_argument &error)
    {
        errors.push_back(error);
    }

    if (errors.size() > 0)
        throw MovieExceptions(errors);
}


bool Movie::operator==(const Movie &movie) const{
    return this->title == movie.title && this->genre == movie.genre && this->year == movie.year;
}

vector<string> tokenize(string str, char delimiter){
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

std::istream & operator>>(std::istream& is, Movie& movie){
    string line;
    getline(is, line);

    vector<string> tokens = tokenize(line, ',');
    if (tokens.size() != 5)
        return is;
    movie.setTitle(tokens[0]);
    movie.setGenre(tokens[1]);
    movie.setYearRelease(stoi(tokens[2]));
    movie.setLikes(stoi(tokens[3]));
    movie.setTrailer(tokens[4]);

    return is;
}

std::ostream & operator<<(std::ostream & os, const Movie& movie){
    os << movie.getTitle() << "," << movie.getGenre() << "," << movie.getYear() << "," << movie.getLikes() << "," << movie.getTrailer() << "\n";
    return os;
}

string Movie::toString() const{
    stringstream buffer;
    buffer<<title<<genre<<year<<nr_likes<<trailer<<"\n";
    return buffer.str();
}