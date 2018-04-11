#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineWidgets/QWebEnginePage>
#include <QtWebEngineWidgets/QWebEngineSettings>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:

    void on_login_clicked();

    void on_menu_clicked();

    void on_logoutEP_clicked();

    void on_backMapEP_clicked();

    void on_cancelReg_clicked();

    void on_submitReg_clicked();

    void on_reg_clicked();

    void on_commEP_clicked();

    void on_backComm_clicked();

    void on_alerts_clicked();

    void on_pushButton_8_clicked();

    void on_backRGroup_clicked();

    void on_protocolEP_clicked();

    void on_groupEP_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
