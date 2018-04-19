#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineWidgets/QWebEnginePage>
#include <QtWebEngineWidgets/QWebEngineSettings>
#include "../controllers/maincontroller.h"
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

    //index 0 (login form) button navigation
    void on_login_clicked();
    void on_reg_clicked();

    //index 1 (register form) button navigation
    void on_cancelReg_clicked();
    void on_submitReg_clicked();

    //index 2 (map view) button navigation
    void on_menu_clicked();
    void on_alerts_clicked();

    //index 3 (Emergency planner's menu) button navigation
    void on_logoutEP_clicked();
    void on_backMapEP_clicked();
    void on_commEP_clicked();
    void on_protocolEP_clicked();
    void on_groupEP_clicked();

    void on_backComm_clicked();
    void on_pushButton_8_clicked();
    void on_backRGroup_clicked();



private:
    Ui::MainWindow *ui;

    MainController *ctrl;

    QString firstNameReg;
    QString lastNameReg;
    QString usernameReg;
    QString emailReg;


};

#endif // MAINWINDOW_H
