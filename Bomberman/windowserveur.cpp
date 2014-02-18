#include "windowserveur.h"
#include "ui_windowserveur.h"
#include <QMessageBox>

windowserveur::windowserveur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowserveur)
{

    ui->setupUi(this);

    connect(ui->pushButtonLancerServeur,SIGNAL(clicked()),this, SLOT(DemarrerServeur()));
    connect(ui->pushButtonArreterServeur,SIGNAL(clicked()),this, SLOT(ArreterServeur()));
    connect(ui->pushButtonFermer,SIGNAL(clicked()),this,SLOT(close()));
}

windowserveur::~windowserveur()
{
    delete ui;
}

void windowserveur::DemarrerServeur()
{
        serveur = new NetworkServer(this);

        etatServeur = new QLabel;
        // changer text label
        ui->labelStatutServeur->setText("Le serveur est démarré.");

       if(serveur->start())
       {
           // changer text label
           ui->labelStatutServeur->setText("Le serveur a été demarré sur le port :<strong>" + QString::number(serveur->serverPort()));

       }else{
           // Si le serveur n'a pas ete demarre correctement
           ui->labelStatutServeurErreur->setText("Le serveur est déja demarré. Raison :" + serveur->errorString());
       }
}


void windowserveur::ArreterServeur()
{
    // changer text label
    ui->labelStatutServeur->setText("Le serveur est arreté.");
    serveur->deleteLater();
}
