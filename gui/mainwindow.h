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
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QVariant"
#include "QString"
#include "../controllers/db_table.h"
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
#include "../controllers/client.h"
#include "../controllers/server.h"

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
    //void on_commEP_clicked();
    void on_groupEP_clicked();
    void on_protocolEP_clicked();
    void on_deleteEP_clicked();
    void on_logoutEP_clicked();

    //index 4 Communication for Emergency Planner
    void on_backComm_clicked();

    //index 5 Manage Responder Group Member
    void on_backRGroupMember_clicked();
    void on_addMember_clicked();
    void on_removeMember_clicked();
    void on_responderCol_clicked(const QModelIndex &index);
    void on_reloadMember_clicked();
    void on_rGroupMemberCol_clicked(const QModelIndex &index);

    //index 6 Manage Responder Group
    void on_addRGroup_clicked();
    void on_rGroupTableView_clicked(const QModelIndex &index);
    void on_refreshRGroup_clicked();
    void on_deleteRGroup_clicked();
    void on_manageRGroupMember_clicked();



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

    void on_viewProt_clicked();
    void on_backToMe_clicked();
    void on_viewProto_clicked();
    void on_backToSelEm_clicked();
    void on_availGroups_clicked();

    void on_backToMenA_clicked();
    void on_backToMapA_clicked();
    void on_checkNot_clicked();
    void on_backMapG_clicked();

    void on_startSim_clicked();
    void on_stopSim_clicked();

    void on_notifMenu_clicked();

    void on_messagesEP_clicked();

    //index 16 View/Delete Users page
    //Push button clicked
    void on_backDeleteUser_clicked();
    void on_reloadDeleteUser_clicked();
    void on_deleteUser_clicked();
    //Table view clicked
    void on_allUserTableView_clicked(const QModelIndex &index);
    //Combo box index changed
    void on_identityDeleteUser_currentIndexChanged(int index);
    //Helper methods
    void display_tableview(db_table,QString, QSqlRelationalTableModel*, QTableView*);
    void display_messages(QSqlRelationalTableModel*, QTableView*, int);
    QString readSelectedCell(int,QTableView*);


    //other non GUI based class methods
    void update_simulations();
    //void update_groups();

    void on_breakIn_clicked();

    void on_logoutG_clicked();





    int get_user_id(QString);

    QString find_group(QString);


    void on_messageG_clicked();

    void on_selectGroup_2_activated(const QString &arg1);

    void on_update_instructions_btn_clicked();

    void on_pushButton_4_clicked();

    void on_backToSelEm_5_clicked();

private:
    Ui::MainWindow *ui;

    MainController *ctrl;

    QSqlRelationalTableModel *allUserTable;
    QSqlRelationalTableModel *rGroupTable;
    QSqlRelationalTableModel *instructionGroupTable;
    QSqlRelationalTableModel *uGroupTable;

    QString firstNameReg;
    QString lastNameReg;
    QString usernameReg;
    QString perm_username;
    Role    roleReg;
    QString emailReg;
    Role    userRole;
    QString emergencyName;
    int group_ID;
    int user_ID;
    bool sim_active = false;
    QString sim_name = "";
    QString active_sim = "";
    bool is_updating = false;
    int id_value = -1;

//http://www.instructables.com/id/How-to-make-Arduino-Police-Lights/
};

#endif // MAINWINDOW_H
