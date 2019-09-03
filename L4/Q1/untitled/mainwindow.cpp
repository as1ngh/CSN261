#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    fstream afile;
    afile.open("/home/as1ngh/CSN261/L4/Q1/L4_P1_input.csv",ios::in | ios::out );
    while(!afile.eof()){
        string line;
         getline(afile,line);
         string word="";
         string meaning="";
         int i=0;
         for(i=0;i<line.size();i++){
            if(line.at(i)==',')
                 break;
            word.push_back(line.at(i));
         }
         for(i=i+1;i<line.size();i++){
            meaning.push_back(line.at(i));
         }
         root->insert(root,word,meaning);
    }
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(listener()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::listener()
{
    string word = this->ui->lineEdit->text().toUtf8().constData();
    QString meaning = QString::fromUtf8(root->getMeaning(root, word).c_str());
    this->ui->textEdit->setHtml(meaning);

}
