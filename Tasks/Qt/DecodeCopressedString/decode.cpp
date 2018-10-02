#include <QApplication>
#include <QDebug>
#include <QByteArray>

int main(int argc, char *argv[]) {

    if(argc == 1) {
        qDebug() << "Missing for compressed string!";
    } else {
        qDebug() << qUncompress(QByteArray::fromBase64(argv[1]));
    }

    return 0;
}
