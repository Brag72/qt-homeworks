#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtNetwork/QAuthenticator>//>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db;
    QAuthenticator nw;

    return a.exec();
}
