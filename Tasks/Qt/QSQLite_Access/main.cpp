#include <QApplication>
#include <QFile>
#include <QtSql>
#include <QtDebug>

int main(int argc, char *argv[]) {

      if(argc != 3) {
         qDebug() << "Wrong number of arguments";
         return 1;
      }
      QString db_PATH = argv[1];
      QString db_name = argv[2];


      if(!db_name.endsWith(".db"))
                    db_name.append(".db");


      if(QFile::exists(db_PATH + "/" + db_name)) {

                    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
                    mydb.setDatabaseName(db_PATH + "/" + db_name);

                    if(!mydb.open()) {
                        qDebug("Database Open Failed!");
                    } else {
                        QSqlQuery query("SELECT * FROM mytable");

                        if(query.exec()) {
                            while(query.next()) {
                                qDebug().noquote() << "| ID "         <<"|" << query.value(0).toInt();
                                qDebug().noquote() << "| NAME "       <<"|" << query.value(1).toString();
                                qDebug().noquote() << "| TOOLCHAINS " <<"|" << query.value(2).toString();
                                qDebug().noquote() << "| FAMILIES "   <<"|" << query.value(3).toString() << "\n";
                            }
                        } else {
                            qDebug() << query.lastError().text();
                        }
                    }
       } else {
            qDebug() << "Invalid Path/Database name";
       }



    return 0;
}
