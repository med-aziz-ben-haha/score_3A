#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//calcul moyenne

void MainWindow::calcul_moy(){

double    ase=ui->ase->value();
double    ang=ui->ang->value();
double    fr=ui->fr->value();
double    dev=ui->dev->value();
double    gl=ui->gl->value();
double    ee=ui->ee->value();
double    mni=ui->mni->value();
double    prog=ui->prog->value();
double    pi=ui->pi->value();
double    res=ui->res->value();
double    stage=ui->stage->value();
double    tei=ui->tei->value();
double    tla=ui->tla->value();

double     moy=(ase*5+ang*3+fr*3+dev*8+gl*2+ee*3+mni*7+prog*10+pi*7+res*6+stage*2+tei*3+tla*3)/62;

//ui->moy->setValue(moy);

}


//calcul scores


void MainWindow:: arctic(){

    double    ase=ui->ase->value();
    double    ang=ui->ang->value();
    double    ee=ui->ee->value();
    double    res=ui->res->value();
    double    moy=ui->moy->value();

    double  arctic= 0.4*moy+0.1*ee+0.1*ang+ 0.2*res+0.2*ase;

    ui->arctic->setValue(arctic);


}

void MainWindow:: ds(){

    double    ang=ui->ang->value();
    double    ee=ui->ee->value();
    double    mni=ui->mni->value();
    double    pi=ui->pi->value();
    double    tei=ui->tei->value();
    double    sgbd=ui->sgbd->value();
    double    moy=ui->moy->value();

    double  ds= 0.4*moy+0.1*ee+0.1*ang+ 0.1*sgbd+0.1*pi+0.2*((mni*7+tei*3)/10);

    ui->ds->setValue(ds);


}


void MainWindow:: bi(){

    double    ang=ui->ang->value();
    double    ee=ui->ee->value();
    double    mni=ui->mni->value();
    double    tei=ui->tei->value();
    double    sgbd=ui->sgbd->value();
    double    moy=ui->moy->value();

    double  bi= 0.4*moy+0.1*ee+0.1*ang+ 0.2*sgbd+0.1*tei+0.1*mni;

    ui->bi->setValue(bi);

}


void MainWindow:: infini(){

    double    ang=ui->ang->value();
    double    ee=ui->ee->value();
    double    pi=ui->pi->value();
    double    cs=ui->cs->value();
    double    mod_mni=ui->mod_mni->value();
    double    sgbd=ui->sgbd->value();
    double    moy=ui->moy->value();

    double  infini= 0.4*moy+0.1*ee+0.1*ang+ 0.1*sgbd+0.1*pi+0.1*cs+0.1*mod_mni;

    ui->infini->setValue(infini);


}


void MainWindow:: nids(){

    double    ase=ui->ase->value();
    double    ang=ui->ang->value();
    double    ee=ui->ee->value();
    double    prog=ui->prog->value();
    double    res=ui->res->value();
    double    moy=ui->moy->value();

    double  nids= 0.4*moy+0.1*ee+0.1*ang+ 0.2*ase+0.1*prog+0.1*res;

    ui->nids->setValue(nids);


}


void MainWindow:: sleam(){

    double    ase=ui->ase->value();
    double    ang=ui->ang->value();
    double    ee=ui->ee->value();
    double    prog=ui->prog->value();
    double    moy=ui->moy->value();

    double  sleam= 0.4*moy+0.1*ee+0.1*ang+ 0.2*ase+0.2*prog;

    ui->sleam->setValue(sleam);


}


void MainWindow:: sae(){

    double    ang=ui->ang->value();
    double    gl=ui->gl->value();
    double    ee=ui->ee->value();
    double    uml=ui->uml->value();
    double    java=ui->java->value();
    double    web=ui->web->value();
    double    moy=ui->moy->value();

    double  sae= 0.4*moy+0.1*ee+0.1*ang+ 0.1*uml+0.1*java+0.1*web+0.1*gl;

    ui->sae->setValue(sae);

}


void MainWindow:: se(){

    double    ang=ui->ang->value();
    double    ee=ui->ee->value();
    double    uml=ui->uml->value();
    double    java=ui->java->value();
    double    web=ui->web->value();
    double    sgbd=ui->sgbd->value();
    double    moy=ui->moy->value();

    double  se= 0.4*moy+0.1*ee+0.1*ang+ 0.1*uml+0.1*java+0.1*web+0.1*sgbd;

    ui->se->setValue(se);


}


void MainWindow:: sim(){

    double    ang=ui->ang->value();
    double    ee=ui->ee->value();
    double    pi=ui->pi->value();
    double    java=ui->java->value();
    double    mobile=ui->mobile->value();
    double    moy=ui->moy->value();

    double  sim= 0.4*moy+0.1*ee+0.1*ang+ 0.15*pi+0.1*java+0.15*mobile;

    ui->sim->setValue(sim);


}


void MainWindow:: twin(){

    double    ang=ui->ang->value();
    double    ee=ui->ee->value();
    double    pi=ui->pi->value();
    double    uml=ui->uml->value();
    double    java=ui->java->value();
    double    web=ui->web->value();
    double    moy=ui->moy->value();

    double  twin= 0.4*moy+0.1*ee+0.1*ang+ 0.1*uml+0.1*java+0.1*web+0.1*pi;

    ui->twin->setValue(twin);
  }

void MainWindow:: calcul_scores(){

 arctic();
 ds();
 bi();
 infini();
 nids();
 sleam();
 sae();
 se();
 sim();
 twin();

}

//sorting


bool variantLessThan(const QVariant &v1, const QVariant &v2)
{
    return v1.toString() < v2.toString();
}

void MainWindow::sort_scores(){

    //make list
    QList<QString> fieldsList;
    fieldsList.append(QString::number(ui->arctic->value())+" : ARCTIC"   );
    fieldsList.append(QString::number(ui->ds->value())+" : DS"   );
    fieldsList.append(QString::number(ui->bi->value())+" : ERP-BI"   );
    fieldsList.append(QString::number(ui->infini->value())+" : INFINI"   );
    fieldsList.append(QString::number(ui->nids->value())+" : NIDS"   );
    fieldsList.append( QString::number(ui->sleam->value())+" : SLEAM"   );
    fieldsList.append( QString::number(ui->sae->value())+" : SAE"   );
    fieldsList.append( QString::number(ui->se->value())+" : SE"  );
    fieldsList.append(QString::number(ui->sim->value())+" : SIM"   );
    fieldsList.append( QString::number(ui->twin->value())+" : TWIN"   );

    //sort list
    std::sort(fieldsList.begin(), fieldsList.end());
    std::reverse(fieldsList.begin(), fieldsList.end());

    //print
    QString string;
    for(int i=0; i<fieldsList.size(); i++)
    {
    string += fieldsList[i];
    if(i<fieldsList.size()-1)
    string +="     //     " ;
    }

    ui->ordre->setText(string);

    QString mail="";

    if(ui->infini->value()> 14.05) mail+="  INFINI : "+QString::number(ui->infini->value())+" // ";
    if(ui->arctic->value()> 13.71) mail+="  ARCTIC : "+QString::number(ui->arctic->value())+" // ";
    if(ui->nids->value()>13.81 ) mail+="  NIDS : "+QString::number(ui->nids->value())+" // ";
    if(ui->ds->value()> 13.65) mail+="  DS : "+QString::number(ui->ds->value())+" // ";
    if(ui->bi->value()>13.3 ) mail+="  ERP-BI : "+QString::number(ui->bi->value())+" // ";


    Smtp* smtp = new Smtp("orientation3a@gmail.com","orientationmdp2021", "smtp.gmail.com");
    if(mail!="")      smtp->sendMail("orientation3a@gmail.com", "orientation3a@gmail.com" , fieldsList[0] ,mail);

}


//donner resultat
void MainWindow::on_pushButton_clicked()
{
calcul_moy();
calcul_scores();
sort_scores();

}
