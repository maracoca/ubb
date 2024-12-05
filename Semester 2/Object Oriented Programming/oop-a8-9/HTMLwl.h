//
// Created by mara on 4/29/2024.
//
#pragma once
#ifndef OOP_A6_7_MARACOCA_HTMLWL_H
#define OOP_A6_7_MARACOCA_HTMLWL_H

#pragma once
#include "FileWatchList.h"

class HTMLWatchList : public FileWatchList
{
public:
    HTMLWatchList(const std::string &fileName) : FileWatchList{fileName} {}
    void writeToFile() const override;
};

#endif //OOP_A6_7_MARACOCA_HTMLWL_H
