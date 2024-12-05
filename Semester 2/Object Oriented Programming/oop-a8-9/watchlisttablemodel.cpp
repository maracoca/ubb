//
// Created by mara on 6/3/2024.
//

#include "watchlisttablemodel.h"

WatchlistTableModel::WatchlistTableModel(const std::vector<Movie>& watchlistData, QObject* parent)
        : QAbstractTableModel(parent), watchlist(watchlistData) {}

int WatchlistTableModel::rowCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return watchlist.size();
}

int WatchlistTableModel::columnCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return 5; // Assuming 5 columns for Title, Genre, Trailer, Year Release, and Nr likes
}

QVariant WatchlistTableModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (index.row() >= watchlist.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        const Movie& movie = watchlist[index.row()];
        switch (index.column()) {
            case 0: return QString::fromStdString(movie.getTitle());
            case 1: return QString::fromStdString(movie.getGenre());
            case 2: return QString::fromStdString(movie.getTrailer());
            case 3: return QVariant(movie.getYear());
            case 4: return QVariant(movie.getLikes());
            default: return QVariant();
        }
    }
    return QVariant();
}

QVariant WatchlistTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0: return tr("Title");
            case 1: return tr("Genre");
            case 2: return tr("Trailer");
            case 3: return tr("Year Release");
            case 4: return tr("Nr likes");
            default: return QVariant();
        }
    }
    return QVariant();
}
