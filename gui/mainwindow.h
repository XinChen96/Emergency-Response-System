#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <string>
#include <QMainWindow>
#include <QMessageBox>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineWidgets/QWebEnginePage>
#include <QtWebEngineWidgets/QWebEngineSettings>
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QVariant"
#include "QString"
#include "../controllers/maincontroller.h"
#include "../db/user_db.h"
#include "../db/db_manager.h"
#include "../db/emergency_db.h"
#include "../users/roles.h"
#include "../users/user.h"
#include "../users/dbitem.h"
#include "../users/simulation.h"
#include "../users/civilian.h"
#include "../users/planner.h"
#include "../users/emergency.h"

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

    //index 0 login form
    void login();
    void on_enterUsername_returnPressed();
    void on_login_clicked();
    void on_reg_clicked();

    //index 1 register form
    void reg();
    void on_enterUsernameReg_returnPressed();
    void on_cancelReg_clicked();
    void on_submitReg_clicked();

    //index 2 (map view) button navigation
    void on_menu_clicked();
    void on_alerts_clicked();

    //index 3 (Emergency planner's menu) button navigation
    void on_logoutEP_clicked();
    void on_simulationsButton_clicked();
    void on_backToSim_clicked();
    void on_createBut_clicked();
    void on_nextButton_clicked();
    void on_backToSimPage2_clicked();
    void on_createSim1_clicked();
    void on_backToSimPage22_clicked();
    void on_createSim2_clicked();
    void on_viewBut_clicked();
    void on_backToSimPage_clicked();
    void on_backMapEP_clicked();
    void on_commEP_clicked();
    void on_protocolEP_clicked();
    void on_groupEP_clicked();
    void on_createEm_clicked();
    void on_backToEView_clicked();
    void on_createEm2_clicked();
    void on_backToMenu_clicked();

    void on_backComm_clicked();
    void on_pushButton_8_clicked();
    void on_backRGroup_clicked();

    //other non GUI based class methods
    void update_simulations();
    void update_groups();






    void on_breakIn_clicked();

    void on_logoutG_clicked();

    void on_add_group_clicked();

    void on_back_to_group_btn_clicked();

    void on_add_group_btn_clicked();

private:
    Ui::MainWindow *ui;

    MainController *ctrl;

    QString firstNameReg;
    QString lastNameReg;
    QString usernameReg;
    Role    roleReg;
    QString emailReg;
    Role    user;


//http://www.instructables.com/id/How-to-make-Arduino-Police-Lights/
};

#endif // MAINWINDOW_H
