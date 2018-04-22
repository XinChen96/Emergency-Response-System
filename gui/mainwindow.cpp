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


    //shut off editing of table
    ui->triggerTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

MainWindow::~MainWindow()
{
    delete ui;
    //delete ctrl;
}

//index 0 (login form) button navigation
// Successful login should take you to the appropriate screen for your user type
// Unsuccessful login should give you an alert and let you try again
void MainWindow::on_login_clicked()
{
    switch(ctrl->check_login(ui->enterUsername->text())) {
    case 0: break; // civilian
    case 1: break; // responder
    case 2:// planner
        ui->stackedWidget->setCurrentIndex(2);
        break;
    case 3: break; //NA
            // No such user
    }

}
//go to register form by clicking register
void MainWindow::on_reg_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//index 1 (register form) button navigation
//go to login form by clicking cancel
void MainWindow::on_cancelReg_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
//when submit button is clicked
void MainWindow::on_submitReg_clicked()
{
    if(ui->identity->currentText() == "Civilian"){
        roleReg = civilian;
    }else if (ui->identity->currentText() == "Emergency Planner"){
        roleReg = planner;
    }else{
        roleReg = NA;
    }
    firstNameReg = ui->enterFirstnameReg->text();
    lastNameReg  = ui->enterLastnameReg->text();
    usernameReg  = ui->enterUsernameReg->text();
    //emailReg     = ui->enterEmailReg->text();

    ctrl->add_user(firstNameReg,lastNameReg,usernameReg,roleReg);
    ui->enterFirstnameReg->clear();
    ui->enterLastnameReg->clear();
    ui->enterUsernameReg->clear();
    //go to loginForm
    ui->stackedWidget->setCurrentIndex(0);





}

//index 2 (map view) button navigation
//go to menu by clicking menu
void MainWindow::on_menu_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
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
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_groupEP_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
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
    ui->stackedWidget->setCurrentIndex(8);
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
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_createSim1_clicked() {
    //get all values from box
    QString value1 = ui->lineEdit->text();
    double value2 = ui->lineEdit2->text().toDouble();
    double value3 = ui->lineEdit3->text().toDouble();
    double value4 = ui->lineEdit4->text().toDouble();
    int value5 = ui->lineEdit5->text().toInt();

    Simulation* temp = new Simulation(value1, 0, value2, value3, value4, value5, -1);

    ctrl->add_simulation(temp);
    ui->selectSim->addItem(value1);

    ui->stackedWidget->setCurrentIndex(7);

    //clear all box values
    ui->lineEdit->clear();
    ui->lineEdit2->clear();
    ui->lineEdit3->clear();
    ui->lineEdit4->clear();
    ui->lineEdit5->clear();
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
    simName = ui->selectSim->currentText();
}

void MainWindow::on_backToSimPage_clicked() {
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









