#include <QCoreApplication>
#include "eigen/Dense"
#include <QFile>
#include "QTextStream"
#include <QDebug>
#include<iostream>
using namespace Eigen;
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int rows=0;
    int clows=0;
    int count =0;
    //首先确定读取的行列数
    QFile file("C:/Users/qixianyu/Documents/untitled13/data.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"read failed!";
         return -1;
    }
    QTextStream in(&file);
       while (!in.atEnd())
       {
           QString line = in.readLine();

           QStringList strlist = line.split(" ", QString::SkipEmptyParts);
           rows++;
           if(count ==0)
           {
               clows =strlist.size();
               count++;

           }
           else
           {
               if(clows!=strlist.size())
               {
                    qDebug()<<"failed!";

                }

          }
      }
      qDebug()<<"rows="<<rows;
      qDebug()<<"clows="<<clows;
    file.close();


    //定义矩阵，给矩阵赋值

    Eigen::MatrixXd m(rows,clows);
    rows=0;
    QFile file1("C:/Users/qixianyu/Documents/untitled13/data.txt");
    if (!file1.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"read failed!";
         return -1;
    }
    QTextStream in1(&file1);
       while (!in1.atEnd())
       {
           QString line = in1.readLine();

           QStringList strlist = line.split(" ", QString::SkipEmptyParts);

           for(int i=0;i<strlist.size()-1;i++)
           {
              QString  str=strlist.at(i);
              m(rows,i)=str.toDouble();
           }
           rows++;
       }
       qDebug()<<m.rows()<<m.cols();

    file.close();

    EigenSolver<MatrixXd> es(m);
    cout << "The eigenvalues of A are:" << endl << es.eigenvalues() << endl;
//    cout << "The matrix of eigenvectors, V, is:" << endl << es.eigenvectors() << endl << endl;
//    complex<double> lambda = es.eigenvalues()[0];
//    cout << "Consider the first eigenvalue, lambda = " << lambda << endl;
//    VectorXcd v = es.eigenvectors().col(0);
//    cout << "If v is the corresponding eigenvector, then lambda * v = " << endl << lambda * v << endl;
//    cout << "... and A * v = " << endl << m.cast<complex<double> >() * v << endl << endl;
//    MatrixXcd D = es.eigenvalues().asDiagonal();
//    MatrixXcd V = es.eigenvectors();
//    cout << "Finally, V * D * V^(-1) = " << endl << V * D * V.inverse() << endl;
    return a.exec();
}

