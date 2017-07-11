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
#include "charset.h"

/* Definitions of global predefiend sets */
const CharSet CharSet::lower_alpha("lower_alpha", CharSet::LOWER_ALPHA);
const CharSet CharSet::upper_alpha("upper_alpha", CharSet::UPPER_ALPHA);
const CharSet CharSet::digits("digits", CharSet::DIGITS);
const CharSet CharSet::alpha("alpha", "lower_alpha", "upper_alpha");
const CharSet CharSet::alphanum("alphanum", "alpha", "digits");


CharSet::CharSet(QString name, QChar character) : _name(name), _type(CharSet::SINGLETON) {

}

CharSet::CharSet(QString name, QString lhs, QString rhs) : _name(name), _type(CharSet::UNION), _lhs(lhs), _rhs(rhs) {

}

CharSet::CharSet(QString n, PredefinedSets s) : _name(n), _type(CharSet::PREDEFINED), _predefined(s)  {

}

QString CharSet::predefinedSetToString(PredefinedSets s) {
    switch (s) {
    case LOWER_ALPHA:
        return "LOWER_ALPHA";
        break;
    case UPPER_ALPHA:
        return "UPPER_ALPHA";
        break;
    default:
        return "DIGITS";
        break;
    }
}

QString CharSet::setTypeToString(SetType s) {
    switch (s) {
    case UNION:
        return "UNION";
        break;
    case PREDEFINED:
        return "PREDEFINED";
        break;
    default:
        return "SINGLETON";
        break;
    }
}

QJsonObject CharSet::toJson() const {
    QJsonObject result;

    result["name"] = this->name();
    result["type"] = this->setTypeToString(type());
    switch (type()) {
    case PREDEFINED:
        result["set"] = this->predefinedSetToString(predefined());
        break;
    case UNION:
        result["lhs"] = lhs();
        result["lhs"] = lhs();
        break;
    default: //Singleton
        result["character"] = QString(value());
    }

    return result;
}
