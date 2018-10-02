#include <QApplication>
#include <QDebug>
#include <QByteArray>

int main(int argc, char *argv[]) {

    if(argc != 2) {
        qDebug() << "Wrong number of arguments!";
    } else {
        qDebug() << qUncompress(QByteArray::fromBase64(argv[1]));
    }

    return 0;
}
