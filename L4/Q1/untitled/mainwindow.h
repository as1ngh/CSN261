#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <dict.h>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    node*root =NULL;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void listener();
};

#endif // MAINWINDOW_H
