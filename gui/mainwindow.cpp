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


}

MainWindow::~MainWindow()
{
    delete ui;
    //delete ctrl;
}

// Method to populate the groups displayed on the group page
void MainWindow::update_groups() {
    // Time to populate the table
    std::vector<Group*> group_list = ctrl->get_groups();
    std::vector<Group*>::iterator iter;

    ui->responder_table->setRowCount(group_list.size());

    int row = 0;
    for(iter = group_list.begin(); iter != group_list.end(); ++iter) {
        ui->responder_table->setItem(row, 0, new QTableWidgetItem((**iter).name));
        ui->responder_table->setItem(row, 1, new QTableWidgetItem((**iter).date));
        delete *iter;
        ++row;
    }
}

//index 0 (login form) button navigation
// Successful login should take you to the appropriate screen for your user type
// Unsuccessful login should give you an alert and let you try again
void MainWindow::login(){
    switch(ctrl->check_role(ui->enterUsername->text())) {
    case 0: // civilian
        user = civilian;
        ui->stackedWidget->setCurrentIndex(2);
        ui->loginAlert->setStyleSheet("");
        ui->loginAlert->setText("");
        break;
    case 1: // responder
        user = responder;
        ui->stackedWidget->setCurrentIndex(2);
        ui->loginAlert->setStyleSheet("");
        ui->loginAlert->setText("");
        break;
    case 2:// planner
        user = planner;
        ui->stackedWidget->setCurrentIndex(2);
        ui->loginAlert->setStyleSheet("");
        ui->loginAlert->setText("");
        break;
    case 3: //No such user
        ui->enterUsername->clear();
        ui->loginAlert->setStyleSheet("background-color:rgb(245, 215, 110)");
        ui->loginAlert->setText("Username does not exist.\n Please try again.");
        break;
    }
}
void MainWindow::on_enterUsername_returnPressed()
{
    login();
}
void MainWindow::on_login_clicked()
{
    login();
}
//go to register form by clicking register
void MainWindow::on_reg_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//index 1 register form
void MainWindow::reg() {

    std::cout<< "reg: Registration started--------------\n";


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
            std::cout<< "reg: user added\n";
        }else{
            std::cout<< "reg: add_user failed\n";
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

//when return is pressed in username box
void MainWindow::on_enterUsernameReg_returnPressed()
{
    reg();
}
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

//index 2 (map view) button navigation
//go to menu by clicking menu
void MainWindow::on_menu_clicked()
{
    switch(user){
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
    update_groups();
}

void MainWindow::on_logoutEP_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
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
    //get all values from box
    QString value1 = ui->lineEdit->text();
    double value2 = ui->lineEdit2->text().toDouble();
    double value3 = ui->lineEdit3->text().toDouble();
    double value4 = ui->lineEdit4->text().toDouble();
    int value5 = ui->lineEdit5->text().toInt();
    QString value6 = ui->emSelect->currentText();

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
    user = planner;
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_logoutG_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
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

    //civilian table display
    civilianTable = new QSqlTableModel(this,ctrl->get_db());
    civilianTable->setTable("users");
    civilianTable->select();

    civilianTable->setFilter("role = 'Civilian' ");
    civilianTable->sort(3,Qt::AscendingOrder); //sort by username

    civilianTable->setHeaderData(1, Qt::Horizontal, tr("First Name"));
    civilianTable->setHeaderData(2, Qt::Horizontal, tr("Last Name"));
    civilianTable->setHeaderData(3, Qt::Horizontal, tr("Username"));

    ui->civilianTableView->setModel(civilianTable);
    ui->civilianTableView->hideColumn(0); // don't show the ID

    //responder table display
    responderTable = new QSqlTableModel(this,ctrl->get_db());
    responderTable->setTable("users");
    responderTable->select();

    responderTable->setFilter("role = 'First Responder' ");
    responderTable->sort(3,Qt::AscendingOrder); //sort by username

    responderTable->setHeaderData(1, Qt::Horizontal, tr("First Name"));
    responderTable->setHeaderData(2, Qt::Horizontal, tr("Last Name"));
    responderTable->setHeaderData(3, Qt::Horizontal, tr("Username"));

    ui->responderTableView->setModel(responderTable);
    ui->responderTableView->hideColumn(0); // don't show the ID

    //planner table display
    plannerTable = new QSqlTableModel(this,ctrl->get_db());
    plannerTable->setTable("users");
    plannerTable->select();

    plannerTable->setFilter("role = 'Emergency Planner' ");
    plannerTable->sort(3,Qt::AscendingOrder); //sort by username

    plannerTable->setHeaderData(1, Qt::Horizontal, tr("First Name"));
    plannerTable->setHeaderData(2, Qt::Horizontal, tr("Last Name"));
    plannerTable->setHeaderData(3, Qt::Horizontal, tr("Username"));

    ui->plannerTableView->setModel(plannerTable);
    ui->plannerTableView->hideColumn(0); // don't show the ID



}

void MainWindow::on_backDeleteUser_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    delete civilianTable;
    delete responderTable;
}
