#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <string>
#include <vector>
#include <QTableView>
#include <QMainWindow>
#include <QMessageBox>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineWidgets/QWebEnginePage>
#include <QtWebEngineWidgets/QWebEngineSettings>
#include <QSqlTableModel>
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
    //Push buttons clicked
    void on_login_clicked();
    void on_reg_clicked();
    //Return pressed in Username box
    void on_enterUsername_returnPressed();
    //Helper method
    void login();

    //index 1 Registration Form
    //Push button clicked
    void on_cancelReg_clicked();
    void on_submitReg_clicked();
    //Return pressed in Username box
    void on_enterUsernameReg_returnPressed();
    //Helper method
    void reg();

    //index 2 Map view
    //Push buttons clicked
    void on_menu_clicked();
    void on_alerts_clicked();

    //index 3 Main Menu for Emergency Planner
    void on_backMapEP_clicked();
    void on_commEP_clicked();
    void on_groupEP_clicked();
    void on_protocolEP_clicked();
    void on_deleteEP_clicked();
    void on_logoutEP_clicked();

    //index 4 Communication for Emergency Planner
    void on_backComm_clicked();

    void on_simulationsButton_clicked();
    void on_backToSim_clicked();
    void on_createBut_clicked();
    void on_nextButton_clicked();

    void on_backToSimPage2_clicked();
    void on_createSim1_clicked();
    void on_backToSimPage22_clicked();
    void on_backToSimPage23_clicked();
    void on_createSim2_clicked();
    void on_viewBut_clicked();
    void on_backToSimPage_clicked();


    void on_createEm_clicked();
    void on_backToEView_clicked();
    void on_createEm2_clicked();
    void on_backToMenu_clicked();


    void on_pushButton_8_clicked();
    void on_backRGroup_clicked();

    void on_setGroupRole_clicked();
    void on_backToCreateEm_clicked();
    void on_selectTheGroup_clicked();
    void on_setRole_clicked();
    void on_backToCreateEm2_clicked();

    //index 16 View/Delete Users page
    //Push button clicked
    void on_backDeleteUser_clicked();
    void on_reloadDeleteUser_clicked();
    void on_deleteUser_clicked();
    //Table view clicked
    void on_civilianTableView_clicked(const QModelIndex &index);
    void on_responderTableView_clicked(const QModelIndex &index);
    void on_plannerTableView_clicked(const QModelIndex &index);
    void on_allUserTableView_clicked(const QModelIndex &index);
    //Tab clicked
    void on_userTableTab_tabBarClicked(int index);
    //Helper methods
    void display_tableview(QString, QSqlTableModel*, QTableView*);
    QString readSelectedCell(int,QTableView*);


    //other non GUI based class methods
    void update_simulations();
    void update_groups();





    void on_breakIn_clicked();

    void on_logoutG_clicked();


private:
    Ui::MainWindow *ui;

    MainController *ctrl;

    QSqlTableModel *civilianTable;
    QSqlTableModel *responderTable;
    QSqlTableModel *plannerTable;
    QSqlTableModel *allUserTable;

    QString firstNameReg;
    QString lastNameReg;
    QString usernameReg;
    Role    roleReg;
    QString emailReg;
    Role    user;
    QString emergencyName;
    int group_ID;


//http://www.instructables.com/id/How-to-make-Arduino-Police-Lights/
};

#endif // MAINWINDOW_H
