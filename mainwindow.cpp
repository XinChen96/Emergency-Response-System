#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWebEngineView* webview = new QWebEngineView;

    QWebEnginePage *page = webview->page();

    connect(page, &QWebEnginePage::featurePermissionRequested,
            [this, page](const QUrl &securityOrigin, QWebEnginePage::Feature feature) {
        if (feature != QWebEnginePage::Geolocation)
            return;

        QMessageBox msgBox(this);
        msgBox.setText(tr("%1 wants to know your location").arg(securityOrigin.host()));
        msgBox.setInformativeText(tr("Do you want to send your current location to this website?"));
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);

        if (msgBox.exec() == QMessageBox::Yes) {
            page->setFeaturePermission(
                securityOrigin, feature, QWebEnginePage::PermissionGrantedByUser);
        } else {
            page->setFeaturePermission(
                securityOrigin, feature, QWebEnginePage::PermissionDeniedByUser);
        }
    });

    QUrl url = QUrl("qrc:/map.html");
    page->load(url);
    ui->mapContainer->addWidget(webview);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//index 0 (login form) button navigation
//go to map view by clicking login
void MainWindow::on_login_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
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
//go to loginForm by clicking submit
void MainWindow::on_submitReg_clicked()
{
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


void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_backRGroup_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}






