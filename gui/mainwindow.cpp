#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ctrl = new MainController();

    QWebEngineView* webview = new QWebEngineView;

    QWebEnginePage *page = webview->page();

    connect(page, &QWebEnginePage::featurePermissionRequested,
            [this, page](const QUrl &securityOrigin, QWebEnginePage::Feature feature) {
        if (feature != QWebEnginePage::Geolocation)
            return;

        page->setFeaturePermission(securityOrigin, feature, QWebEnginePage::PermissionGrantedByUser);
    });

    QUrl url = QUrl("qrc:/map.html");
    page->load(url);
    ui->mapContainer->addWidget(webview);
    ui->stackedWidget->setCurrentIndex(0);

    //Adds in all items to combo box / GUI from existing database

    std::vector<QString> sim_db = ctrl->get_Sim_DBItems(); //gets all simulation names from database

    for (int i = 0; i < sim_db.size(); i++) { //adds them to combo boxes
        ui->selectSim->addItem(sim_db[i]);
    }

    std::vector<QString> em_db = ctrl->get_Em_DBItems(); //gets all emergency names from database

    for (int i = 0; i < em_db.size(); i++) { //adds them to combo boxes
        ui->emCombo->addItem(em_db[i]);
        ui->emSelect->addItem(em_db[i]);
        ui->selEm->addItem(em_db[i]);
    }

    std::vector<Group*> gr_db = ctrl->get_groups(); //get all groups

    for (int i = 0; i < gr_db.size(); i++) { //adds them to combo box
        ui->selectGroup->addItem(gr_db[i]->name);
        //ui->selGr->addItem(gr_db[i]->name);
    }

    std::vector<int> no_db = ctrl->get_noti_sim_DBItems(); //get all notifications from database

    for (int i = 0; i < no_db.size(); i++) { //sets active simulation
        Simulation* temp_si = ctrl->select_simulation(no_db[i]);

        if (temp_si != nullptr) {
            active_sim = temp_si->name;
            sim_active = true;
        }
    }
    ui->centralWidget->setStyleSheet("QWidget[objectName='centralWidget'] { border-image:url(:/images/Login.jpg)0 0 0 0 stretch stretch}");

    //hide break in button, but hes not gone
    ui->breakIn->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
    //delete ctrl;
}

// Method to populate the groups displayed on the group page
//void MainWindow::update_groups() {
//    // Time to populate the table
//    std::vector<Group*> group_list = ctrl->get_groups();
//    std::vector<Group*>::iterator iter;

//    ui->responder_table->setRowCount(group_list.size());

//    int row = 0;
//    for(iter = group_list.begin(); iter != group_list.end(); ++iter) {
//        ui->responder_table->setItem(row, 0, new QTableWidgetItem((**iter).name));
//        ui->responder_table->setItem(row, 1, new QTableWidgetItem((**iter).date));
//        delete *iter;
//        ++row;
//    }
//}

//index 0 Login Form
//go to register form by clicking register
void MainWindow::on_reg_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_login_clicked()
{
    login();
}
void MainWindow::on_enterUsername_returnPressed()
{
    login();
}
// Successful login should take you to the appropriate screen for your user type
// Unsuccessful login should give you an alert and let you try again
void MainWindow::login(){

    if(ctrl->check_role(ui->enterUsername->text())!=3){
        userRole = Role(ctrl->check_role(ui->enterUsername->text()));
        perm_username = ui->enterUsername->text();
        ui->stackedWidget->setCurrentIndex(2);
        ui->loginAlert->setStyleSheet("");
        ui->loginAlert->setText("");
        user_ID = ctrl->get_user_id(ui->enterUsername->text());

        ui->centralWidget->setStyleSheet("QWidget[objectName='centralWidget'] { border-image:url(:/images/Background.jpg)0 0 0 0 stretch stretch}");


    }else{
        ui->enterUsername->clear();
        ui->loginAlert->setStyleSheet("background-color:rgb(245, 215, 110)");
        ui->loginAlert->setText("Username does not exist.\n Please try again.");
    }

    if(userRole == 2) { // Planner
        ui->alerts->setVisible(false);
        ctrl->start_server();
        ui->logout->setVisible(false);
        ui->menu->setVisible(true);


    } else if (userRole == civilian) {
        ui->alerts->setVisible(true);
        ui->messageG->setVisible(false);
        ui->menu->setVisible(false);
        ui->logout->setVisible(true);
        ctrl->start_client();
    } else {
        ui->alerts->setVisible(true);
        ui->messageG->setVisible(true);
        ui->menu->setVisible(true);
        ui->logout->setVisible(true);
        ctrl->start_client();

    }
}

//index 1 register form
//when cancel button is clicked
void MainWindow::on_cancelReg_clicked()
{
    //clear contents if register is cancelled
    ui->enterFirstnameReg->clear();
    ui->enterLastnameReg->clear();
    ui->enterUsernameReg->clear();
    ui->regAlert->setStyleSheet("");
    ui->regAlert->setText("");

    //go to login form
    ui->stackedWidget->setCurrentIndex(0);
}
//when submit button is clicked
void MainWindow::on_submitReg_clicked()
{

    reg();
}
//when return is pressed in username box
void MainWindow::on_enterUsernameReg_returnPressed()
{
    reg();
}
void MainWindow::reg() {

    std::cout<< "reg: Registration started--------------\n";
    //ctrl = new MainController();

    bool incomplete;
    bool existed;

    //get user identityt
    if(ui->identity->currentText() == "Civilian"){
        roleReg = civilian;
    }else if (ui->identity->currentText() == "Emergency Planner"){
        roleReg = planner;
    }else if (ui->identity->currentText() == "First Responder"){
        roleReg = responder;
    }

    //get user information
    firstNameReg = ui->enterFirstnameReg->text();
    lastNameReg  = ui->enterLastnameReg->text();
    usernameReg  = ui->enterUsernameReg->text();

    if(ui->enterFirstnameReg->text().isEmpty()||
            ui->enterLastnameReg->text().isEmpty()||
            ui->enterUsernameReg->text().isEmpty()){
        incomplete = true;
    }else{
        incomplete= false;
    }

    if(ctrl->check_role(usernameReg) != 3){
        existed = true;
    }else{
        existed = false;
    }

    if(incomplete){
        ui->regAlert->setStyleSheet("background-color:rgb(245, 215, 110)");
        ui->regAlert->setText("User information is not completed.");
    }else if (existed){
        ui->regAlert->setStyleSheet("background-color:rgb(245, 215, 110)");
        ui->regAlert->setText("Username already exists.");
    }else{
        ui->regAlert->setStyleSheet("");
        ui->regAlert->setText("");

        //add user information into user database
        if(ctrl->add_user(firstNameReg,lastNameReg,usernameReg,roleReg)){
            std::cout<< "GUI: reg() user added\n";
        }else{
            std::cout<< "GUI: reg() add_user failed\n";
        }

        //clear contents if register is submitted
        ui->enterFirstnameReg->clear();
        ui->enterLastnameReg->clear();
        ui->enterUsernameReg->clear();
        std::cout<< "reg: Registration ended----------\n";

        //go to loginForm
        ui->stackedWidget->setCurrentIndex(0);
    }
}



//index 2 (map view) button navigation
//go to menu by clicking menu
void MainWindow::on_menu_clicked()
{
    switch(userRole){
    case planner:
        ui->stackedWidget->setCurrentIndex(3);
        break;
    case responder:
        ui->stackedWidget->setCurrentIndex(13);
        break;
    case civilian:
        ui->stackedWidget->setCurrentIndex(13);
        break;
    }
}
//go to communication by clicking alert
void MainWindow::on_alerts_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);
}

//index 3 (Emergency planner's menu) button navigation
//go to map view by clicking back
void MainWindow::on_backMapEP_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_backComm_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}


/*void MainWindow::on_commEP_clicked()
{
    //go to comm
     ui->stackedWidget->setCurrentIndex(21);
} */

void MainWindow::on_protocolEP_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::on_groupEP_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    on_refreshRGroup_clicked();


}

void MainWindow::on_logoutEP_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->enterUsername->clear();
    ui->notArea->clear();
    ui->centralWidget->setStyleSheet("QWidget[objectName='centralWidget'] { border-image:url(:/images/Login.jpg)0 0 0 0 stretch stretch}");
}

void MainWindow::on_simulationsButton_clicked() {
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_backToSim_clicked() {
    ui->stackedWidget->setCurrentIndex(3);
    //set error text
    ui->errorText2->clear();
    ui->errorText2->setStyleSheet("");
}

void MainWindow::on_createBut_clicked() {
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_nextButton_clicked() {
    QString simType = ui->simComboBox->currentText();

    if (simType == "First Responder Simulation") {
        ui->stackedWidget->setCurrentIndex(9);
    } else if (simType == "Civilian Simulation") {
        ui->stackedWidget->setCurrentIndex(10);
    }
}

void MainWindow::on_backToSimPage2_clicked() {
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_createSim1_clicked() {
    QString value6 = ui->emSelect->currentText();

    if (value6 != nullptr) {

        //get all values from box
        QString value1 = ui->lineEdit->text();
        double value2 = ui->lineEdit2->text().toDouble();
        double value3 = ui->lineEdit3->text().toDouble();
        double value4 = ui->lineEdit4->text().toDouble();
        int value5 = ui->lineEdit5->text().toInt();

        Emergency* temp_em = ctrl->select_emergency(value6);

        Simulation* temp = new Simulation(value1, value2, value3, value4, value5, temp_em->id);

        ctrl->add_simulation(temp);
        ui->selectSim->addItem(value1);

        ui->stackedWidget->setCurrentIndex(7);

        //clear all box values
        ui->lineEdit->clear();
        ui->lineEdit2->clear();
        ui->lineEdit3->clear();
        ui->lineEdit4->clear();
        ui->lineEdit5->clear();

        delete temp_em;
        delete temp;
    }
}

void MainWindow::on_backToSimPage22_clicked() {
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_createSim2_clicked() {
    //get all values from box
    QString value1 = ui->lineEdit->text();
    double value2 = ui->lineEdit2->text().toDouble();
    double value3 = ui->lineEdit3->text().toDouble();
    double value4 = ui->lineEdit4->text().toDouble();
    int value5 = ui->lineEdit5->text().toInt();

    ui->stackedWidget->setCurrentIndex(7);

    //clear all box values
    ui->lineEdit->clear();
    ui->lineEdit2->clear();
    ui->lineEdit3->clear();
    ui->lineEdit4->clear();
    ui->lineEdit5->clear();
}

void MainWindow::on_viewBut_clicked() {
    QString simName = ui->selectSim->currentText();

    if (simName != nullptr) { //make sure an actual item is selected

        Simulation* sim = ctrl->select_simulation(simName); //get the database entry
        sim_name = simName;

        if (sim != nullptr) {
            //set error text
            ui->errorText2->clear();
            ui->errorText2->setStyleSheet("");

            //get value from db
            QString temp0 = sim->name;
            QString temp1 = QString::number(sim->lat);
            QString temp2 = QString::number(sim->lng);
            QString temp3 = QString::number(sim->radius);
            QString temp4 = QString::number(sim->num_civilians);
            int temp_id = sim->emergency_id;

            Emergency* temp_em = ctrl->select_emergency(temp_id);
            QString temp5 = temp_em->name;

            //Get value from current box and add to it
            QString value0 = temp0 + ":";
            QString value1 = temp1;
            QString value2 = temp2;
            QString value3 = temp3;
            QString value4 = temp4;
            QString value5 = temp5;

            //reset the values
            ui->label0->setText(value0);
            ui->labe1->setText(value1);
            ui->label_15->setText(value2);
            ui->label3->setText(value3);
            ui->label4->setText(value4);
            ui->label5->setText(value5);

            if (active_sim != simName) {
                //default text appearance
                ui->label6->setStyleSheet("color:rgb(242, 21, 21)");
                ui->label6->setText("Simulation Not Active.");
            } else if (active_sim == simName) {
                ui->label6->setStyleSheet("color:rgb(1, 155, 52)");
                ui->label6->setText("Simulation Active.");
            }

            ui->stackedWidget->setCurrentIndex(11); //set page

            delete sim;
        } else {
            //set error text
            ui->errorText2->setAlignment(Qt::AlignCenter);
            ui->errorText2->setText("Please select a Simulation before viewing.");
            ui->errorText2->setStyleSheet("background-color:rgb(245, 215, 110)");
        }
    } else {
        //set error text
        ui->errorText2->setAlignment(Qt::AlignCenter);
        ui->errorText2->setText("Please select a Simulation before viewing.");
        ui->errorText2->setStyleSheet("background-color:rgb(245, 215, 110)");
    }
}

void MainWindow::on_backToSimPage_clicked() {
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow:: on_backToSimPage23_clicked() {
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_backRGroup_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::update_simulations() {

}


void MainWindow::on_breakIn_clicked()
{
    userRole = planner;
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_logoutG_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->enterUsername->clear();
    ui->notArea->clear();
    ui->centralWidget->setStyleSheet("QWidget[objectName='centralWidget'] { border-image:url(:/images/Login.jpg)0 0 0 0 stretch stretch}");
}

void MainWindow::on_createEm_clicked() {
    ui->stackedWidget->setCurrentIndex(15);
}

//void MainWindow::on_back_to_group_btn_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(6);
//    update_groups();
//}

void MainWindow::on_backToMenu_clicked() {
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_backToEView_clicked() {
    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::on_createEm2_clicked() {
    //Get value from value boxes
    QString value0 = ui->enter1->text();
    QString value1 = ui->enter2->toPlainText();

    Emergency* em = new Emergency(value0, value1);

    ctrl->add_emergency(em);

    //add to database and box
    ui->emCombo->addItem(value0);
    ui->emSelect->addItem(value0);
    ui->selEm->addItem(value0);

    ui->stackedWidget->setCurrentIndex(14);

    //clear values
    ui->enter1->clear();
    ui->enter2->clear();
}

void MainWindow::on_deleteEP_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);

    //all users table display
    display_tableview(user,"all",allUserTable,ui->allUserTableView);

    ui->identityDeleteUser->setCurrentIndex(0);
}


void MainWindow::on_identityDeleteUser_currentIndexChanged(int index)
{
    switch(index){
    case 0://all users
        //all users table display
        display_tableview(user,"all",allUserTable,ui->allUserTableView);
        break;
    case 1://civilian
        //civlian table display
        display_tableview(user,"Civilian",allUserTable,ui->allUserTableView);
        break;
    case 2://first responder
        //responder table display
        display_tableview(user,"First Responder",allUserTable,ui->allUserTableView);
        break;
    case 3://emergency planner
        //planner table display
        display_tableview(user,"Emergency Planner",allUserTable,ui->allUserTableView);
        break;
    }
}


//index 16
void MainWindow::on_backDeleteUser_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    //cannot delete here, error for too many deletes
    //delete allUserTableView;
}
void MainWindow::on_deleteUser_clicked()
{
    QString selectedUsername;
    QString alert;

    selectedUsername = readSelectedCell(3,ui->allUserTableView);

    alert = readSelectedCell(4,ui->allUserTableView)
          + " " + selectedUsername + " ["
          + readSelectedCell(1,ui->allUserTableView) + " "
          + readSelectedCell(2,ui->allUserTableView) + "] is deleted ";

    ctrl->delete_row(user,selectedUsername);
    on_reloadDeleteUser_clicked();
    ui->deleteAlert->setText(alert);

}
void MainWindow::on_reloadDeleteUser_clicked()
{

    on_identityDeleteUser_currentIndexChanged(ui->identityDeleteUser->currentIndex());
    //clear alert after reload
    ui->deleteAlert->setText("");
}
void MainWindow::on_allUserTableView_clicked(const QModelIndex &index)
{
    QString alert = "Delete " + readSelectedCell(4,ui->allUserTableView)
                  + " "  + readSelectedCell(3,ui->allUserTableView)
                  + " (" + readSelectedCell(1,ui->allUserTableView)
                  + " "  +readSelectedCell(2,ui->allUserTableView)
                  + ")?";
    ui->deleteAlert->setText(alert);
}
QString MainWindow::readSelectedCell(int selectedCol,QTableView* selectedTable)
{
    //get selected row number
    int selectedRow =selectedTable->selectionModel()->currentIndex().row();

    //return the data in selected cell as QString
    return selectedTable->model()->data(
           selectedTable->model()->index(selectedRow,selectedCol)).
            toString();
}

// Display all of the messages from the database
void MainWindow::display_messages(QSqlRelationalTableModel* table_model, QTableView* table_view, int group) {
    table_model = new QSqlRelationalTableModel(this, ctrl->get_DB(user));
    table_model->setTable("instructions");
    std::cout << "This is the group that it is filtering by: " << group << std::endl;
    QString filter = QString("group_id=%1").arg(group);
    table_model->setFilter(filter);
    table_model->select();
    table_model->sort(0, Qt::DescendingOrder); // Sort with most recent message first

    table_model->setHeaderData(1, Qt::Horizontal, tr("Instruction"));
    table_model->setHeaderData(2, Qt::Horizontal, tr("Date"));
    table_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table_view->setModel(table_model);
    table_view->setColumnWidth(2, table_view->columnWidth(2) / 4);
    table_view->hideColumn(0);
    table_view->hideColumn(2);
}

//only user table for now
void MainWindow::display_tableview(db_table table,QString filter,QSqlRelationalTableModel* tableModel,QTableView* tableView){

    QString filterCmd;

    switch(table){
    case user:
        tableModel = new QSqlRelationalTableModel(this,ctrl->get_DB(user));
        tableModel->setTable("users");
        tableModel->select();
        if(filter != "all"){
            filterCmd = "role = '" + filter + "'";
            tableModel->setFilter(filterCmd);
        }else{
            filterCmd = "";
        }
        tableModel->sort(3,Qt::AscendingOrder); //sort by username

        tableModel->setHeaderData(1, Qt::Horizontal, tr("First Name"));
        tableModel->setHeaderData(2, Qt::Horizontal, tr("Last Name"));
        tableModel->setHeaderData(3, Qt::Horizontal, tr("Username"));
        tableView->setModel(tableModel);

        if(ui->stackedWidget->currentIndex()==5){
            tableView->hideColumn(0);
            tableView->hideColumn(4);
            tableModel->setHeaderData(3, Qt::Horizontal, tr("Username"));
        }else{
            tableView->hideColumn(0); // don't show the ID
        }

        break;
    case group:
        tableModel = new QSqlRelationalTableModel(this,ctrl->get_DB(user));
        tableModel->setTable("groups");
        tableModel->select();
        tableModel->sort(1,Qt::AscendingOrder); //sort by group name
        tableModel->setHeaderData(1, Qt::Horizontal, tr("Group Name"));
        tableModel->setHeaderData(2, Qt::Horizontal, tr("Date Created"));
        tableView->setModel(tableModel);
        tableView->hideColumn(0); // don't show the ID
        tableView->setSelectionBehavior( QAbstractItemView::SelectRows );
        tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        tableView->setItemDelegate(new QSqlRelationalDelegate(tableView));
        break;
     case userGroup:
        tableModel = new QSqlRelationalTableModel(this,ctrl->get_DB(user));
        tableModel->setTable("userGroups");
        tableModel->setRelation(2,QSqlRelation("users","id","username"));
        tableModel->select();

        filterCmd = "group_id = '" + filter + "'";
        tableModel->setFilter(filterCmd);

        tableModel->sort(1,Qt::AscendingOrder); //sort by group name
        tableModel->setHeaderData(2, Qt::Horizontal, tr("Responder Username"));

        tableModel->setRelation(2,QSqlRelation("users","id","username"));
        tableView->setModel(tableModel);
        tableView->hideColumn(0); // don't show the ID
        tableView->hideColumn(1); // don't show the Group ID
        tableView->setItemDelegate(new QSqlRelationalDelegate(tableView));
        break;
    }

    tableView->setSelectionBehavior( QAbstractItemView::SelectRows );
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


//    tableView->setModel(tableModel);
//    tableView->hideColumn(0); // don't show the ID
//    tableView->setSelectionBehavior( QAbstractItemView::SelectRows );
//    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    //ui->plannerTableView->setSelectionMode( QAbstractItemView::SingleSelection );
}



void MainWindow::on_setGroupRole_clicked() {
    //keep track of emergency name
    emergencyName = ui->emCombo->currentText();

    if (emergencyName != nullptr) {

        QString temp = "Select Group for \"" + emergencyName + "\" Emergency:";

        //update text for next page
        ui->selLabel->setText(temp);

        ui->stackedWidget->setCurrentIndex(17);
    }
}

void MainWindow::on_backToCreateEm_clicked() {
    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::on_selectTheGroup_clicked() {
    QString temp = ui->selectGroup->currentText(); //get value from combo box

    if (temp != nullptr) {

        Group* gr_temp = ctrl->select_group(temp);
        group_ID = gr_temp->id;

        QString temp2 = "Set Group \"" + gr_temp->name + "\" Role for \"" + emergencyName + "\" Emergency:"; //set text in new window

        ui->selLabel2->setText(temp2);

        Emergency* temp_em = ctrl->select_emergency(emergencyName);
        Response* temp_resp = ctrl->select_response(temp_em, gr_temp);

        if (temp_resp != nullptr) {
            ui->enterRole->setText(temp_resp->emergency_response);
            id_value = temp_resp->id;
            is_updating = true;
        }

        ui->stackedWidget->setCurrentIndex(18);

        delete gr_temp;
    }
}

void MainWindow::on_setRole_clicked() {
    QString value = ui->enterRole->toPlainText(); //get role

    Emergency* temp_em = ctrl->select_emergency(emergencyName);

    int em_id = temp_em->id; //get id of emergency

    // TODO: change back to group_ID
    Response* temp_resp = new Response(group_ID, em_id, value); //construct response item

    if (is_updating) {
        temp_resp->id = id_value;

        std::cout << temp_resp->id << " value\n";
        ctrl->update_response(temp_resp); //update in database
        is_updating = false;
    } else {
        ctrl->add_response(temp_resp); //add to databas
    }

    ui->enterRole->clear(); //clear box

    ui->stackedWidget->setCurrentIndex(14);

    delete temp_em;
    delete temp_resp;
}

void MainWindow::on_backToCreateEm2_clicked() {
    ui->stackedWidget->setCurrentIndex(17);
    ui->enterRole->clear();
}


void MainWindow::on_addRGroup_clicked()
{
    QString alert;
    on_refreshRGroup_clicked();
    if(ui->enterRGroupName->text().isEmpty()){
    alert= "Please enter a new group name";
    ui->selectAlertRGroup->setText(alert);
    ui->selectAlertRGroup->setStyleSheet("background-color:rgb(245, 215, 110)");
    }else if(ctrl->select_group(ui->enterRGroupName->text())!=nullptr){
        alert= "Group already exists. Please enter a different name";
        ui->selectAlertRGroup->setText(alert);
        ui->selectAlertRGroup->setStyleSheet("background-color:rgb(245, 215, 110)");
    }else{
    alert= "Group ["+ui->enterRGroupName->text()+"] added";
    ctrl->add_group(ui->enterRGroupName->text());
    ui->selectGroup->addItem(ui->enterRGroupName->text());


    ui->selectAlertRGroup->setText(alert);
    display_tableview(group,"all",rGroupTable,ui->rGroupTableView);

    ui->enterRGroupName->clear();
    }
}

void MainWindow::on_rGroupTableView_clicked(const QModelIndex &index)
{

    int memberCnt = ctrl->cnt_group_member(readSelectedCell(0,ui->rGroupTableView).toInt());
    QString alert = "Group "+readSelectedCell(1,ui->rGroupTableView)+" ("+ QString::number(memberCnt) +" members) selected";
    ui->selectAlertRGroup->setText(alert);
    ui->selectAlertRGroup->setStyleSheet("color: white;");
    ui->manageRGroupMember->setEnabled(true);
    ui->deleteRGroup->setEnabled(true);

}

void MainWindow::on_refreshRGroup_clicked()
{
    display_tableview(group,"all",rGroupTable,ui->rGroupTableView);
    ui->selectAlertRGroup->setText("");
    ui->selectAlertRGroup->setStyleSheet("color: white;");
    ui->manageRGroupMember->setEnabled(false);
    ui->deleteRGroup->setEnabled(false);
}

void MainWindow::on_deleteRGroup_clicked()
{
    QString selectedId = readSelectedCell(0,ui->rGroupTableView);
    QString selectedName = readSelectedCell(1,ui->rGroupTableView);
    QString alert;

    //remove group from combo box
    Group* temp_gr = ctrl->select_group(selectedName);

        if(ctrl->delete_row(group,selectedId)){
            on_refreshRGroup_clicked();
            alert = "Group ["+ selectedName +"] is deleted";
            ui->selectAlertRGroup->setText(alert);

            //remove group from combo box
            int spot = temp_gr->id - 1;
            ui->selectGroup->removeItem(spot);
        }else{
            on_refreshRGroup_clicked();
            alert = "Group ["+ selectedName +"] delete failed";
            ui->selectAlertRGroup->setText(alert);

        }

}

void MainWindow::on_manageRGroupMember_clicked()
{
    QString pageTitle = readSelectedCell(1,ui->rGroupTableView)+" Group";
    QString tableTitle = "Existing Group Members in " + readSelectedCell(1,ui->rGroupTableView);
    ui->rGroupMemberTitle->setText(pageTitle);
    ui->userGroupTitle->setText(tableTitle);
    ui->stackedWidget->setCurrentIndex(5);

    on_reloadMember_clicked();


}

void MainWindow::on_backRGroupMember_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_addMember_clicked()
{
   QString groupID = readSelectedCell(0,ui->rGroupTableView);

   QString groupName = readSelectedCell(1,ui->rGroupTableView);
   QString userName  = readSelectedCell(3,ui->responderCol);

   ctrl->add_to_group(groupName,userName);
    on_reloadMember_clicked();

}

void MainWindow::on_viewProt_clicked() {
    ui->stackedWidget->setCurrentIndex(19);
    ui->selGr->clear(); //clear for next viewing
}

void MainWindow::on_backToMe_clicked() {
    ui->stackedWidget->setCurrentIndex(3);
    ui->errorText->clear();
    ui->errorText->setStyleSheet("");
}

void MainWindow::on_availGroups_clicked() {
    QString temp0 = ui->selEm->currentText();
    ui->selGr->clear(); //clear box so it doesn't add more

    if (temp0 != nullptr) {

        ui->errorText->clear();
        ui->errorText->setStyleSheet("");

        Emergency* em_db = ctrl->select_emergency(temp0); //get emergency

        std::vector<int> em_resp = ctrl->get_resp_em_DBItems(em_db->id); //get all groups

        for (int i = 0; i < em_resp.size(); i++) { //adds them to combo box
            Group* temp_gr = ctrl->select_group(em_resp[i]); //get group that uses said emergency
            if  (temp_gr != nullptr) {
                ui->selGr->addItem(temp_gr->name);
            }
        }

        delete em_db;
    }
}

void MainWindow::on_viewProto_clicked() {
    QString temp0 = ui->selEm->currentText();
    QString temp1 = ui->selGr->currentText();

    if (temp0 != nullptr && temp1 != nullptr) { //make sure not null

        Emergency* em_db = ctrl->select_emergency(temp0); //get emergency
        Group* gr_db = ctrl->select_group(temp1);
        Response* resp_db = ctrl->select_response(em_db, gr_db); //get response

        if (resp_db) {

            ui->errorText->clear();
            ui->errorText->setStyleSheet("");

            //display the information
            ui->pubRes->setText(em_db->public_response);
            ui->grRole->setText(resp_db->emergency_response);

            ui->protEmLab->setText("Protocol for Group \"" + temp1 + "\" - \"" + temp0 + "\" Emergency:"); //set text

            ui->stackedWidget->setCurrentIndex(20);

            delete em_db;
            delete gr_db;
            delete resp_db;
        } else {
            ui->errorText->setAlignment(Qt::AlignCenter);
            ui->errorText->setText("Please click Available Groups before viewing.");
            ui->errorText->setStyleSheet("background-color:rgb(245, 215, 110)");
        }
    } else {
        ui->errorText->setAlignment(Qt::AlignCenter);
        ui->errorText->setText("Please click Available Groups before viewing.");
        ui->errorText->setStyleSheet("background-color:rgb(245, 215, 110)");
    }
}

void MainWindow::on_backToSelEm_clicked() {
    ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_backToMenA_clicked() {
    if(userRole == planner){
    ui->stackedWidget->setCurrentIndex(3);
    }else{
        ui->stackedWidget->setCurrentIndex(13);
    }
    ui->latBox->clear();
    ui->longBox->clear();
}

void MainWindow::on_checkNot_clicked() {
    QString lat_str = ui->latBox->text();
    QString lng_str = ui->longBox->text();

    if (lat_str != nullptr && lng_str != nullptr) {

        double lat = lat_str.toDouble();
        double lng = lng_str.toDouble();

        std::vector<int> no_db = ctrl->get_noti_sim_DBItems(); //get all notifications from database

        for (int i = 0; i < no_db.size(); i++) { //sets active simulation
            Simulation* temp_si = ctrl->select_simulation(no_db[i]);

            if (temp_si != nullptr) {
                //get proper location values
                double lat_high = temp_si->lat + temp_si->radius;
                double lat_low = temp_si->lat - temp_si->radius;
                double lng_high = temp_si->lng + temp_si->radius;
                double lng_low = temp_si->lng - temp_si->radius;

                std::cout << lat << " lat " << lng << " lng \n";
                std::cout << lat_high << " lat high " << lng_high << " lng high \n";
                std::cout << lat_low << " lat low " << lng_low << " lng low \n";

                if (((lat <= lat_high && lat >= lat_low) || (lat >= lat_high && lat <= lat_low)) && ((lng >= lng_high && lng <= lng_low) || (lng <= lng_high && lng >= lng_low))) {
                    //get the Emergency
                    Emergency* em_val = ctrl->select_emergency(temp_si->emergency_id);

                    QString new_text, old_text;

                    switch(userRole) {
                        case planner: {

                            //nothing yet
                            break;
                        }
                        case responder:
                        {
                            //get group info
                            QString group_name = find_group(perm_username);
                            Group* gr_val = ctrl->select_group(group_name);

                            //get response
                            Response* res_val = ctrl->select_response(em_val, gr_val);

                            if (res_val != nullptr) {

                                new_text = QString::fromUtf8("ATTENTION:\nThere is a \"") + em_val->name
                                    + QString::fromUtf8("\" Emergency at Latitude: ") + QString::number(temp_si->lat)
                                    + " and Longitude: " + QString::number(temp_si->lng) + "\n"
                                    + "There are " + QString::number(temp_si->num_civilians) + " civilians in the area of the \""
                                    + em_val->name + "\".\nAs a member of the \"" + gr_val->name + "\" Group, "
                                    + "you have been directed to do as follows:\n"
                                    + res_val->emergency_response + QString::fromUtf8("\nThank You and Stay Safe!\n");
                                old_text = ui->notArea->toPlainText();

                                //ui->notArea->setText(old_text + "\n" + new_text);
                                ui->notArea->setText(new_text);
                            } else {
                                ui->notArea->setText("No active emergencies to worry about.");
                            }
                            break;
                        }
                        case civilian: {
                            new_text = QString::fromUtf8("ATTENTION:\nThere is a \"") + em_val->name
                                    + QString::fromUtf8("\" Emergency at Latitude: ") + QString::number(temp_si->lat)
                                    + " and Longitude: " + QString::number(temp_si->lng) + "\n"
                                    + "You have been directed to do as follows:\n"
                                    + em_val->public_response + QString::fromUtf8("\nThank You and Stay Safe!\n");
                            old_text = ui->notArea->toPlainText();

                            //ui->notArea->setText(old_text + "\n" + new_text);
                            ui->notArea->setText(new_text);

                            std::cout << new_text.toStdString();
                            break;
                        }
                    }
                } else {
                    switch(userRole) {
                        case planner:
                            ui->notArea->setText("No active emergencies to worry about.");
                            break;
                        case responder:
                            ui->notArea->setText("No active emergencies to worry about.");
                            break;
                        case civilian:
                            ui->notArea->setText("No active emergencies to worry about.");
                            break;
                    }
                }
            }
        }
    }
}

void MainWindow::on_removeMember_clicked()
{
    QString groupID = readSelectedCell(0,ui->rGroupTableView);
    //int userID  = readSelectedCell(0,ui->responderCol).toInt();
    QString id = readSelectedCell(0,ui->rGroupMemberCol);

    ctrl->delete_row(userGroup,id);
    on_reloadMember_clicked();
}

void MainWindow::on_startSim_clicked() {
    if (!sim_active) { //only allow for one sim running at a time
        sim_active = true;
        active_sim = sim_name;

        //set text
        ui->label6->setStyleSheet("color:rgb(1, 155, 52)");
        ui->label6->setText("Simulation Active.");

        Simulation* temp_sim = ctrl->select_simulation(sim_name);
        Notification* temp_not = new Notification(temp_sim->id);

        ctrl->add_notification(temp_not); //add in notification to database

        delete temp_sim;
        delete temp_not;
    }
}

void MainWindow::on_stopSim_clicked() {
    if (sim_active && sim_name == active_sim) { //only allow for one sim running at a time
        sim_active = false;
        active_sim = "";
        ui->notArea->clear();


        //set text
        ui->label6->setStyleSheet("color:rgb(242, 21, 21)");
        ui->label6->setText("Simulation Not Active.");

        Simulation* temp_sim = ctrl->select_simulation(sim_name);
        Notification* temp_no = ctrl->select_notification_id(temp_sim->id);

        ctrl->remove_notification(temp_no->id); //remove notification from database

        delete temp_sim;
        delete temp_no;
    }
}

QString MainWindow::find_group(QString username){
    QString groupName;
    int userId = get_user_id(username);
    std::cout << "GUi:get user id"<<userId << std::endl;
    int groupId = ctrl->find_group(userId);
    std::cout << "GUi:group id"<<groupId << std::endl;
    if(groupId == -1){
    groupName = "";
    }else{groupName = ctrl->select_group(groupId)->name;
    }
    std::cout << "GUi:find group"<<groupName.toStdString() << std::endl;


    return groupName;

}

int MainWindow::get_user_id(QString username){
    return ctrl->select_user(username)->id;
}

void MainWindow::on_responderCol_clicked(const QModelIndex &index)
{

QString firstName = readSelectedCell(1,ui->responderCol);
QString lastName =  readSelectedCell(2,ui->responderCol);
QString userName =  readSelectedCell(3,ui->responderCol);
QString groupName = find_group(userName);
QString alert = "Responder: "+firstName+ " " + lastName + " ["+userName+"] "+ ", Current Group:"+ find_group(userName);

if(groupName == ""){

alert = "Available Responder: "+firstName+ " " + lastName + " ["+userName+"] ";
ui->addMember->setEnabled(true);
ui->alertMember->setStyleSheet("background-color:rgb(38, 194, 129);color:white;");
}else{
alert = "Responder: "+firstName+ " " + lastName + " ["+userName+"] "+ "is already assigned to Group: "+ find_group(userName);
ui->addMember->setEnabled(false);
ui->alertMember->setStyleSheet("background-color:rgb(245, 215, 110)");
}
ui->removeMember->setEnabled(false);
ui->alertMember->setText(alert);

}

void MainWindow::on_reloadMember_clicked()
{
    display_tableview(userGroup,readSelectedCell(0,ui->rGroupTableView),uGroupTable,ui->rGroupMemberCol);
    display_tableview(user,"First Responder",allUserTable,ui->responderCol);
    ui->addMember->setEnabled(false);
    ui->removeMember->setEnabled(false);
    ui->alertMember->setText("");
    ui->alertMember->setStyleSheet("color:white");
}

void MainWindow::on_rGroupMemberCol_clicked(const QModelIndex &index)
{

    QString userName =  readSelectedCell(2,ui->rGroupMemberCol);
    QString firstName = ctrl->select_user(userName)->first_name;
    QString lastName =  ctrl->select_user(userName)->last_name;


    QString alert = "Responder: "+firstName+ " " + lastName + " ["+userName+"] "+ ", Existing Member in this group "+ find_group(userName);
    ui->addMember->setEnabled(false);
    ui->removeMember->setEnabled(true);
    ui->alertMember->setText(alert);
    ui->alertMember->setStyleSheet("color:white");

}

void MainWindow::on_messageG_clicked() {
    // Populate group box
    ui->selectGroup_2->clear();
    std::vector<Group*> group_list = ctrl->get_user_groups(user_ID);
    group_ID = group_list[0]->id;
    for(int i = 0; i < group_list.size(); i++) {
        ui->selectGroup_2->addItem(group_list[i]->name);
    }
    ctrl->update_instructions(group_ID);
    display_messages(instructionGroupTable, ui->instructions_table_view, group_ID);
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_selectGroup_2_activated(const QString &arg1) {
    //TODO: set the correct id here
    display_messages(instructionGroupTable, ui->instructions_table_view, group_ID);
}

void MainWindow::on_update_instructions_btn_clicked() {
    ctrl->update_instructions(group_ID);
    display_messages(instructionGroupTable, ui->instructions_table_view, group_ID);
}

void MainWindow::on_backToMapA_clicked() {
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_backMapG_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_notifMenu_clicked() {
    ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_messagesEP_clicked() {
    ui->select_group_box_4->clear();
    std::vector<Group*> group_list = ctrl->get_groups();

    for(int i = 0; i < group_list.size(); i++) {
        ui->select_group_box_4->addItem(group_list[i]->name);
        delete group_list[i];
    }
    ui->stackedWidget->setCurrentIndex(23);
}

void MainWindow::on_pushButton_4_clicked()
{
    QString group = ui->select_group_box_4->currentText(); // Get current group
    QString instruction = ui->instruction_box_4->toPlainText(); // Get instructions
    int group_id = ctrl->get_group_id(group);
    ctrl->add_instruction(instruction, group_id);
    ui->instruction_box_4->clear();
}

void MainWindow::on_backToSelEm_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_backToMenG_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_logout_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->enterUsername->clear();
    ui->notArea->clear();
    ui->centralWidget->setStyleSheet("QWidget[objectName='centralWidget'] { border-image:url(:/images/Login.jpg)0 0 0 0 stretch stretch}");
}
