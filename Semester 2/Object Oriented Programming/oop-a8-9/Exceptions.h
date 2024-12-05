//
// Created by mara on 4/30/2024.
//
#pragma once
#ifndef OOP_A6_7_MARACOCA_EXCEPTIONS_H
#define OOP_A6_7_MARACOCA_EXCEPTIONS_H

#include <exception>
#include <string>

using namespace std;

class RepositoryException : public exception {
protected:
    string message;
public:
    RepositoryException();
    RepositoryException(const std::string &message);
    virtual ~RepositoryException(){};
    virtual const char *what();
};

class PositionException : public RepositoryException{
public:
    const char *what();
};

#endif //OOP_A6_7_MARACOCA_EXCEPTIONS_H
