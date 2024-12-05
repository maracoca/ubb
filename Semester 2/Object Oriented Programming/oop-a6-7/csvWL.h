//
// Created by mara on 4/29/2024.
//

#ifndef OOP_A6_7_MARACOCA_CSVWL_H
#define OOP_A6_7_MARACOCA_CSVWL_H

#pragma once
#include "FileWatchList.h"

class CSVWatchList : public FileWatchList{
public:
    CSVWatchList(const std::string &fileName) : FileWatchList{fileName} {}
    void writeToFile() const override;
};

#endif //OOP_A6_7_MARACOCA_CSVWL_H
