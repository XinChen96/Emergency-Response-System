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

    //***
    //TO ADD: add in all items to combo box from existing database
    //***


    std::vector<QString> sim_db = ctrl->get_Sim_DBItems(); //gets all simulation names from database

    for (int i = 0; i < sim_db.size(); i++) { //adds them to combo boxes
        ui->selectSim->addItem(sim_db[i]);
    }

    std::vector<QString> em_db = ctrl->get_Em_DBItems(); //gets all emergency names from database

    for (int i = 0; i < em_db.size(); i++) { //adds them to combo boxes
        ui->emCombo->addItem(em_db[i]);
        ui->emSelect->addItem(em_db[i]);
    }

    std::vector<Group*> gr_db = ctrl->get_groups(); //get all groups

    for (int i = 0; i < gr_db.size(); i++) { //adds them to combo box
        ui->selectGroup->addItem(gr_db[i]->name);
    }

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
        ui->stackedWidget->setCurrentIndex(2);
        ui->loginAlert->setStyleSheet("");
        ui->loginAlert->setText("");

    }else{
        ui->enterUsername->clear();
        ui->loginAlert->setStyleSheet("background-color:rgb(245, 215, 110)");
        ui->loginAlert->setText("Username does not exist.\n Please try again.");
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
        ui->responderChannelG->setEnabled(false);
        break;
    }
}
//go to communication by clicking alert
void MainWindow::on_alerts_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
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


void MainWindow::on_commEP_clicked()
{
    //go to comm
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_protocolEP_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::on_groupEP_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    display_tableview(group,"all users",rGroupTable,ui->rGroupTableView);
    //update_groups();
}

void MainWindow::on_logoutEP_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->enterUsername->clear();
}

void MainWindow::on_simulationsButton_clicked() {
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_backToSim_clicked() {
    ui->stackedWidget->setCurrentIndex(3);
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
        QString value1 = "Latitude of Emergency: " + temp1;
        QString value2 = "Longitude of Emergency: " + temp2;
        QString value3 = "Radius of Emergency: " + temp3;
        QString value4 = "Number of Civilians Involved: " + temp4;
        QString value5 = "Type of Emergency: " + temp5;

        //reset the values
        ui->label0->setText(value0);
        ui->labe1->setText(value1);
        ui->label_15->setText(value2);
        ui->label3->setText(value3);
        ui->label4->setText(value4);
        ui->label5->setText(value5);

        ui->stackedWidget->setCurrentIndex(11); //set page

        delete sim;
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

    ui->stackedWidget->setCurrentIndex(14);

    //clear values
    ui->enter1->clear();
    ui->enter2->clear();
}

void MainWindow::on_deleteEP_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);

    //all users table display
    display_tableview(user,"all users",allUserTable,ui->allUserTableView);

    ui->identityDeleteUser->setCurrentIndex(0);
}


void MainWindow::on_identityDeleteUser_currentIndexChanged(int index)
{
    switch(index){
    case 0://all users
        //all users table display
        display_tableview(user,"all users",allUserTable,ui->allUserTableView);
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

    alert = readSelectedCell(4,ui->allUserTableView) + " " + selectedUsername +
            " (" + readSelectedCell(1,ui->allUserTableView) + " " +
            readSelectedCell(2,ui->allUserTableView) + ")" + " is deleted ";



    ctrl->delete_user(selectedUsername);
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
//only user table for now
void MainWindow::display_tableview(db_table table,QString filter,QSqlTableModel* tableModel,QTableView* tableView){

    QString filterCmd;

    switch(table){
    case user:
        tableModel = new QSqlTableModel(this,ctrl->get_DB(user));
        tableModel->setTable("users");
        tableModel->select();
        if(filter != "all users"){
            filterCmd = "role = '" + filter + "'";
            tableModel->setFilter(filterCmd);
        }else{
            filterCmd = "";
        }
        tableModel->sort(3,Qt::AscendingOrder); //sort by username
        tableModel->setHeaderData(1, Qt::Horizontal, tr("First Name"));
        tableModel->setHeaderData(2, Qt::Horizontal, tr("Last Name"));
        tableModel->setHeaderData(3, Qt::Horizontal, tr("Username"));
        break;
    case group:
        tableModel = new QSqlTableModel(this,ctrl->get_DB(user));
        tableModel->setTable("groups");
        tableModel->select();
        tableModel->sort(1,Qt::AscendingOrder); //sort by group name
        break;
    }



    tableView->setModel(tableModel);
    tableView->hideColumn(0); // don't show the ID
    tableView->setSelectionBehavior( QAbstractItemView::SelectRows );
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->plannerTableView->setSelectionMode( QAbstractItemView::SingleSelection );
}



void MainWindow::on_setGroupRole_clicked() {
    //keep track of emergency name
    emergencyName = ui->emCombo->currentText();

    QString temp = "Select Group for \"" + emergencyName + "\" Emergency:";

    //update text for next page
    ui->selLabel->setText(temp);

    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_backToCreateEm_clicked() {
    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::on_selectTheGroup_clicked() {
    QString temp = ui->selectGroup->currentText(); //get value from combo box

    Group* gr_temp = ctrl->select_group(temp);
    group_ID = gr_temp->id;

    QString temp2 = "Group \"" + gr_temp->name + "\" Roles for \"" + emergencyName + "\" Emergency:"; //set text in new window

    ui->selLabel2->setText(temp2);

    ui->stackedWidget->setCurrentIndex(18);

    delete gr_temp;
}

void MainWindow::on_setRole_clicked() {
    QString value = ui->enterRole->toPlainText(); //get role

    Emergency* temp_em = ctrl->select_emergency(emergencyName);

    int em_id = temp_em->id; //get id of emergency

    Response* temp_resp = new Response(group_ID, em_id, value); //construct response item

    ctrl->add_response(temp_resp); //add to database

    ui->enterRole->clear(); //clear box

    ui->stackedWidget->setCurrentIndex(14);

    delete temp_em;
    delete temp_resp;
}

void MainWindow::on_backToCreateEm2_clicked() {
    ui->stackedWidget->setCurrentIndex(17);;

}


void MainWindow::on_addRGroup_clicked()
{
    ctrl->add_group(ui->enterRGroupName->text());
    display_tableview(group,"all users",rGroupTable,ui->rGroupTableView);
    ui->enterRGroupName->clear();
}

void MainWindow::on_adduserRGroup_clicked()
{
    //rGroupTable = new QSqlTableModel(this,ctrl->get_DB(group));
   //rGroupTable->setTable("groups");
    //rGroupTable->(1,QSqlRelation("user","id","username"));
}
