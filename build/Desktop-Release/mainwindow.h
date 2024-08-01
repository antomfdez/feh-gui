#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidgetItem>
#include <QMainWindow>
#include <QFileDialog>
#include <QAbstractButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void List();

private slots:

    void on_buttonSet_clicked();

    void on_buttonBrowser_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_itemActivated(QListWidgetItem *item);

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void saveLastDirectory(const QStringList& path);

    void keyPressEvent(QKeyEvent *event);

    QStringList loadLastDirectory();

    void on_Next_clicked();

    void on_Prev_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
