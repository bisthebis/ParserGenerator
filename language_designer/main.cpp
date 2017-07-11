#include <iostream>
#include <QtCore>
#include <QApplication>
#include "mainwindow.h"
#include "tokentype.h"
#include "language.h"

int main(int argc, char** argv) {
    Language lang;
    Regex regex;
    regex.pushRule({CharSet::alpha, Regex::AT_LEAST_ONCE});
    regex.pushRule({CharSet::alphanum, Regex::ANY});
    TokenType id("identifier", regex);
    lang.pushTokenType(id);

    auto idObject = lang.toJson();
    QByteArray data = QJsonDocument(idObject).toJson();

    QApplication app(argc, argv);
    QFile file("out.json");
    QTextStream ss(&file);
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Failed to open !";
        return 1;
    }
    ss << QString::fromLatin1(data);
    MainWindow window;
    window.show();

    return app.exec();
}
