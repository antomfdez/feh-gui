#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTreeView>
#include <QListWidgetItem>
#include <QSettings>
#include <QShortcut>
#include <QAbstractButton>
#include <QKeySequence>
#include <QKeyEvent>

using namespace std;

QVector<QString> filePath;
QStringList fullPaths;
QStringList lastDir;
int currentRow,lastRow;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+O"), this);
    connect(shortcut, &QShortcut::activated, this, &MainWindow::on_buttonBrowser_clicked);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Down)
    {
        if (currentRow == lastRow)
        {
            ui->listWidget->setCurrentRow(0);
            return;
        }
    }
    if (event->key() == Qt::Key_Up)
    {
        if (currentRow == 0)
        {
            ui->listWidget->setCurrentRow(lastRow);
            return;
        }
    }
    QMainWindow::keyPressEvent(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveLastDirectory(const QStringList& path)
{
    QSettings settings("test", "bg");
    settings.setValue("lastDirectory", path);
}

QStringList MainWindow::loadLastDirectory()
{
    QSettings settings("test", "bg");
    return settings.value("lastDirectory", QStringList()).toStringList();
}

void MainWindow::List()
{
    QStringList lastDir = loadLastDirectory();
    if (lastDir.isEmpty())
        return;
    QStringList _fnames = lastDir;

    saveLastDirectory(_fnames);

    for (const QString& directorio : _fnames) {
        QDir dir(directorio);
        QStringList nameFilters;
        nameFilters << "*.png" << "*.jpg" << "*.jpeg" << "*.gif";
        dir.setNameFilters(nameFilters);
        QStringList dirContents = dir.entryList(QDir::NoDotAndDotDot | QDir::AllEntries);
        for (const QString& entry : dirContents) {
            fullPaths.append(dir.filePath(entry));
        }
        ui->listWidget->clear();
        ui->listWidget->addItems(fullPaths);
    }
    lastRow = ui->listWidget->count() - 1;
    ui->listWidget->setCurrentRow(0);
    ui->listWidget->setFocus();
}

void MainWindow::on_buttonSet_clicked()
{
    std::string bg = "feh --bg-fill " + filePath[0].toStdString();
    std::system(bg.c_str());

    ui->listWidget->setFocus();
}

void MainWindow::on_buttonBrowser_clicked()
{
    QFileDialog* _f_dlg = new QFileDialog(this);
    _f_dlg->setFileMode(QFileDialog::Directory);
    _f_dlg->setOption(QFileDialog::DontUseNativeDialog, true);

    lastDir = loadLastDirectory(); // New function to load last directory
    if (!lastDir.isEmpty()) {
        _f_dlg->setDirectory(lastDir.first());
    }

    // Try to select multiple files and directories at the same time in QFileDialog
    QListView *l = _f_dlg->findChild<QListView*>("listView");
    if (l) {
        l->setSelectionMode(QAbstractItemView::MultiSelection);
    }
    QTreeView *t = _f_dlg->findChild<QTreeView*>();
    if (t) {
        t->setSelectionMode(QAbstractItemView::MultiSelection);
    }

    int nMode = _f_dlg->exec();
    if (nMode == QDialog::Accepted)
    {
        QStringList _fnames = _f_dlg->selectedFiles();

        saveLastDirectory(_fnames);

        fullPaths.clear();

        ui->listWidget->blockSignals(true);
        ui->listWidget->clear();
        ui->listWidget->blockSignals(false);

        for (const QString& directorio : _fnames) {
            QDir dir(directorio);
            QStringList nameFilters;
            nameFilters << "*.png" << "*.jpg" << "*.jpeg" << "*.gif";
            dir.setNameFilters(nameFilters);
            QStringList dirContents = dir.entryList(QDir::NoDotAndDotDot | QDir::AllEntries);
            for (const QString& entry : dirContents) {
                fullPaths.append(dir.filePath(entry));
            }
            ui->listWidget->addItems(fullPaths);
        }

        ui->listWidget->setCurrentRow(0);
        ui->listWidget->setFocus();
    }
    lastRow = ui->listWidget->count() - 1;
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    filePath[0] = item->text();
    QPixmap pixmap(filePath[0]);
    ui->imagen->setPixmap(pixmap.scaled(ui->imagen->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}


void MainWindow::on_listWidget_itemActivated(QListWidgetItem *item) // Set wallpaper with enter key
{
    on_buttonSet_clicked();
}

void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous) // Change preview when item changed
{
    currentRow = ui->listWidget->row(current);
    if (lastRow == 0)
        filePath = {fullPaths[currentRow]};
    else if (currentRow == 0)
        filePath = {fullPaths[currentRow],fullPaths[lastRow],fullPaths[currentRow+1]};
    else if (currentRow == lastRow)
        filePath = {fullPaths[currentRow],fullPaths[currentRow-1],fullPaths[0]};
    else
        filePath = {fullPaths[currentRow],fullPaths[currentRow-1],fullPaths[currentRow+1]};
    QVector<QString> widgets = {"imagen","imagen0","imagen2"};
    for(int x = 0;x<filePath.size();x++)
    {
        QPixmap pixmap(filePath[x]);
        QLabel *label = findChild<QLabel*>(widgets[x]);
        if (label)
            label->setPixmap(pixmap.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}


void MainWindow::on_Next_clicked()
{
    currentRow = currentRow+1;
    if (currentRow > lastRow)
        ui->listWidget->setCurrentRow(0);
    else
        ui->listWidget->setCurrentRow(currentRow);
}


void MainWindow::on_Prev_clicked()
{
    currentRow = currentRow-1;
    if (currentRow < 0)
        ui->listWidget->setCurrentRow(lastRow);
    else
        ui->listWidget->setCurrentRow(currentRow);
}

