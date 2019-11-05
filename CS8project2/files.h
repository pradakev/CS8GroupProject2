#ifndef FILES
#define FILES
#include <QFile>
#include <QTextStream>
#include <QResource>
#include <QString>
#include <QDebug>
#include "membercontainer.h"
#include "transactioncontainer.h"
#include "productcontainer.h"
using namespace std;

void importMembers(QString fileName, memberContainer& members);
void importDailySales(QString fileName, productContainer& products,
                      transactionContainer& transactions, memberContainer& members);
void saveMembers(QString fileName, memberContainer& members);
void saveDailySales(QString fileName, productContainer& products,
                    transactionContainer& transactions);



void importMembers(QString fileName, memberContainer& members){
       QString temp;
       member toAdd;
       int count = 0;
       QFile inFile(fileName);
       QTextStream in(&inFile);

       if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text))
       {
           return;
       }

       while(!in.atEnd())
       {
           temp = in.readLine();
           if(count == 0)
           {
               toAdd.setName(temp.toStdString());
               count++;
           }else if(count == 1)
           {
               toAdd.setID(temp.toStdString());
               count++;
           }else if(count == 2)
           {
               toAdd.setType(temp.toStdString());
               count++;
           }else if(count == 3)
           {

               toAdd.setDate(temp.toStdString());
               members.add(toAdd);
               count = 0;
           }
       }
       inFile.close();
}
void importDailySales(QString fileName, productContainer& products,
                      transactionContainer& transactions, memberContainer& members){
    QString temp;
    int quantity;
    double price;
    int count = 0;
    product pToAdd;
    transaction tToAdd;

    QFile inFile(fileName);
    QTextStream in(&inFile);
    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    while(!in.atEnd())
    {
        temp = in.readLine();
        if(count == 0)
        {
            tToAdd.setTransDate(temp.toStdString());
            count++;
        }else if(count == 1)
        {
            tToAdd.setPurchaserID(temp.toStdString());
            count++;
        }else if(count == 2)
        {
            pToAdd.setName(temp.toStdString());
            count++;
        }else if(count == 3)
        {
            price = stod(temp.toStdString());
            quantity = stoi(temp.toStdString().substr(temp.toStdString().find_first_of('\t')));
            pToAdd.setPrice(price);
            pToAdd.setQuantity(quantity);
            tToAdd.setQuantity(quantity);
            products.add(pToAdd);
            tToAdd.setProduct(pToAdd);
            transactions.add(tToAdd);

            for (int i =0; i < members.getSize(); i++){
                if (tToAdd.getPurchaseID() == members[i].getID()){
                    members[i].setTotalPurchase(members[i].getTotalPurchases() +
                            price*quantity);
                }
            }

            count = 0;
        }
    }
    inFile.close();
}

void saveMembers(QString fileName, memberContainer& members)
{
    QFile inFile(fileName);
    QTextStream outstream(&inFile);

    inFile.open(QIODevice::WriteOnly | QIODevice::Text);

    for(int i = 0; i < members.getSize(); i++)
    {
        outstream << QString::fromStdString(members[i].getName()) << endl;
        outstream << QString::fromStdString(members[i].getID()) << endl;
        outstream << QString::fromStdString(members[i].getType()) << endl;
        outstream << QString::fromStdString(members[i].getExpDate()) << endl;
    }
    inFile.close();
    qDebug() << "Writing finished";
}
void saveDailySales(QString fileName, productContainer& products,
                    transactionContainer& transactions)
{
    QFile toFile;
    QTextStream outstream(&toFile);
    toFile.open(QIODevice::WriteOnly | QIODevice::Text);
    for(int i = 0; i < products.getSize(); i++)
    {
        outstream << QString::fromStdString(transactions[i].getPurchaseDate()) << endl;
        outstream << QString::fromStdString(transactions[i].getPurchaseID()) << endl;
        outstream << QString::fromStdString(products[i].getName()) << endl;
        outstream << products[i].getPrice() << "\t" <<
                  transactions[i].getQuantity() << endl;
    }
    toFile.close();
    qDebug() << "Writing finished";
}

#endif // FILES

