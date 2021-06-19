#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <algorithm>
#include <QList>
#include "smtp.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void calcul_moy();

    void arctic();
    void ds();
    void bi();
    void infini();
    void nids();
    void sleam();
    void sae();
    void se();
    void sim();
    void twin();

    void calcul_scores();

    void sort_scores();




private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
