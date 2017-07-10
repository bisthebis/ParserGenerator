/*
MIT License

Copyright (c) 2017 Boris Martin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef CHARSET_H
#define CHARSET_H

#include <QChar>
#include <QString>
#include <QScopedPointer>

class CharSet
{
public:
    enum PredefinedSets {LOWER_ALPHA, UPPER_ALPHA, DIGITS};
    static QString predefinedSetToString(PredefinedSets s);

    enum SetType {UNION, SINGLETON, PREDEFINED};
    static QString setTypeToString(SetType s);

    static const CharSet lower_alpha, upper_alpha, digits, alpha, alphanum;

    CharSet(QString _name, QChar character);
    CharSet(QString _name, QString _lhs, QString _rhs);
    CharSet(QString n, PredefinedSets s);

    QString name() const {return _name;}
    SetType type() const {return _type;}
    PredefinedSets predefined() const {return _predefined;}
    QChar value() const {return _value;}
    QString lhs() const {return _lhs;}
    QString rhs() const {return _rhs;}


private:
    QString _name;
    PredefinedSets _predefined; //If it's predefined, which one it is
    SetType _type;
    QChar _value; //For singleton set
    QString _lhs, _rhs; //For union. Names of the sets used.



};

#endif // CHARSET_H
