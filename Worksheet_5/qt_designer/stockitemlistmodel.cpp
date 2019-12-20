//stockitemlistmodel.cpp

#include "stockitemlistmodel.h"
#include <QListView>
#include <QAbstractListModel>
#include <QModelIndex>

int StockItemListModel::rowCount( const QModelIndex & parent ) const {
    return stockItems.size();
}

QVariant StockItemListModel::data( const QModelIndex & index, int role ) const {
    if ( !index.isValid() ) return QVariant();
    if ( index.row() >= stockItems.size() || index.row() < 0 ) return QVariant();

    if(role == Qt::DisplayRole ) {
        return QVariant( stockItems[index.row()].getName() );
    } else {
        return QVariant();

    }
}

void StockItemListModel::addItem( const StockItem & s ) {
    emit beginInsertRows( QModelIndex(), stockItems.size()-1, stockItems.size()-1 );
    stockItems.push_back( s );
    emit endInsertRows();

}

void StockItemListModel::insertItem( const StockItem &s, const QModelIndex & index) {
    emit beginInsertRows( QModelIndex(), stockItems.size ()-1, stockItems.size()-1);
    stockItems.push_back( s );
    emit endInsertRows();
}

void StockItemListModel::setItem( const StockItem &s, const QModelIndex & index) {
    if(index.isValid() && index.row() >= 0 && index.row() < stockItems.size() ) {
        stockItems[index.row( )] = s;
        emit dataChanged( index, index);
    }
}

void StockItemListModel::removeItem( const StockItem &s ,const QModelIndex & index ) {
    emit beginInsertRows( QModelIndex(), stockItems.size()-1, stockItems.size()-1 );
    stockItems.push_back(s);
    emit endInsertRows();
}

StockItem StockItemListModel::getItem( const QModelIndex & index) const {
    if( index.isValid() && index.row() >= 0 && index.row() < stockItems.size() )
        return stockItems[index.row()];

    return StockItem();
}
