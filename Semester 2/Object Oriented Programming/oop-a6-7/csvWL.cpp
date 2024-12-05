//
// Created by mara on 4/29/2024.
//

#include "csvWL.h"
//#include "Exceptions.h"
#include <fstream>

void CSVWatchList::writeToFile() const
{
    std::ofstream CSVOutputFile(this->fileName.c_str());

    CSVOutputFile << "Index, Name, Genre, Year Of Release, Trailer, Likes Count\n";
    int index = 0;
    for (auto movie : this->movies)
        CSVOutputFile << index++ << ", " << movie.getTitle() << "," << movie.getGenre() << "," << movie.getYear() << "," << movie.getTrailer() << "," << movie.getLikes() << "\n";

    CSVOutputFile.close();
}