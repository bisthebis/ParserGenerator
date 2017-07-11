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
#include "language.h"
#include <QJsonArray>
#include <QJsonObject>

Language::Language()
{
    pushCharSet(CharSet::upper_alpha);
    pushCharSet(CharSet::lower_alpha);
    pushCharSet(CharSet::digits);
    pushCharSet(CharSet::alpha);
    pushCharSet(CharSet::alphanum);
}

void Language::pushTokenType(const TokenType &t) {
    //Since TokenTypes are not default constructible, operator [] can't be used.
    tokens.insert(t.name(), t);
}

void Language::pushCharSet(const CharSet &s) {
    //Since CharSets are not default constructible, operator [] can't be used.
    charSets.insert(s.name(), s);
}

QJsonObject Language::toJson() {
    //The document is a single object containing charsets and tokentypes arrays
    QJsonObject result;

    QJsonArray JsonCharSets;
    for (const auto& set : charSets) {
        JsonCharSets.append(set.toJson());
    }
    result["sets"] = JsonCharSets;

    QJsonArray JsonTokenTypes;
    for (const auto& type : tokens) {
        JsonTokenTypes.append(type.toJson());
    }

    result["sets"] = JsonCharSets;
    result["types"] = JsonTokenTypes;

    return result;
}
