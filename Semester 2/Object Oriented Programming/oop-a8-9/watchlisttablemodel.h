//
// Created by mara on 6/3/2024.
//

#ifndef OOP_A8_9_MARACOCA_WATCHLISTTABLEMODEL_H
#define OOP_A8_9_MARACOCA_WATCHLISTTABLEMODEL_H


#include <QAbstractTableModel>
#include <vector>
#include "movie.h" // Assuming Movie class is defined in this header file

class WatchlistTableModel : public QAbstractTableModel {
Q_OBJECT
public:
    WatchlistTableModel(const std::vector<Movie>& watchlistData, QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

private:
    std::vector<Movie> watchlist;
};


#endif //OOP_A8_9_MARACOCA_WATCHLISTTABLEMODEL_H
