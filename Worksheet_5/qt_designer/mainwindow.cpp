// qt_designer/mainwindow.cpp ------------------------------------------
#include "mainwindow.h" 
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QMessageBox>
#include "stockitem.h"
#include "edititemdialog.h"
#include "stockitemlistmodel.h"

MainWindow::MainWindow(QWidget *parent) : 
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   ui->listView->setModel( &stockList );
   ui->listView->setSelectionBehavior( QAbstractItemView::SelectItems);


  connect(ui->addbutton, &QPushButton::released, this, &MainWindow::handleAddButton);
  connect(ui->editbutton, &QPushButton::released, this, &MainWindow::handleEditButton);
  connect(ui->removebutton, &QPushButton::released, this, &MainWindow::handleRemoveButton);

  connect(this, &MainWindow::statusUpdateMessage, ui->statusBar, &QStatusBar::showMessage);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::handleAddButton() {
StockItem item;
stockList.addItem(item);
emit statusUpdateMessage(QString("Add button was clicked"), 0);

}

void MainWindow::handleEditButton() {
EditItemDialog dialog( this );
QModelIndexList selectedList;

selectedList = ui->listView->selectionModel()->selectedIndexes();
if(selectedList.length() == 1) {
    StockItem item = stockList.getItem( selectedList[0]);
    if(dialog.runDialog(item)) {
        stockList.setItem(item, selectedList[0]);
        }
} else{

emit statusUpdateMessage( QString("No item selected to edit!"), 0 );
}
}

void MainWindow::handleRemoveButton() {
    emit statusUpdateMessage( QString("Remove button was clicked"), 0 );

}



