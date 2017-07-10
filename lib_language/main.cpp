#include <iostream>
#include <QtCore>

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    qDebug() << "Hello world !";
    QTimer::singleShot(200,  [&](){qDebug() << "Leaving"; app.quit();});
    return app.exec();
}
