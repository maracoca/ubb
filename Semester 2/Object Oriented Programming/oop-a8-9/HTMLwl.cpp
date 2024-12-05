//
// Created by mara on 4/29/2024.
//

#include "HTMLwl.h"
//#include "Exceptions.h"
#include <fstream>

void HTMLWatchList::writeToFile() const
{
    std::ofstream HTMLOutputFile(this->fileName.c_str());

    HTMLOutputFile << "<!DOCTYPE html> <html> <head> <title> Movie FileWatchList</title> </head > <body> <table border=\"1\">";
    HTMLOutputFile << "<tr> <td> Index </td> <td> Title </td> <td> Genre </td> <td> Year Of Release </td> <td> Likes Count </td> <td> Trailer </td> </tr>";
    int index = 0;
    for (auto movie : this->movies)
        HTMLOutputFile << "<tr> <td>" << index++ << "</td> <td>" << movie.getTitle() << "</td> <td>" << movie.getGenre() << "</td> <td>" << movie.getYear() << "</td> <td>" << movie.getLikes() << "</td> <td><a href=\"" << movie.getTrailer() << "\"> Link</a></ td> </tr>";

    HTMLOutputFile << "</table> </body> </html>";
    HTMLOutputFile.close();
}