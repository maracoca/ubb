//
// Created by mara on 4/30/2024.
//

#include "Exceptions.h"

RepositoryException::RepositoryException() : std::exception(){
    this->message = "";
}

RepositoryException::RepositoryException(const std::string &message){
    this->message = message;
}

const char *RepositoryException::what(){
    return "Movie already in repo";
}

const char *PositionException::what(){
    return "The position of the movie is invalid!";
}