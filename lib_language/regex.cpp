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
#include "regex.h"
#include <QJsonObject>
#include <QJsonValue>

Regex::Regex()
{

}

QString Regex::repeatModeToString(RepeatMode s) {
    switch (s) {
    case EXACTLY_ONCE:
        return "EXACTLY_ONCE";
        break;
    case AT_LEAST_ONCE:
        return "AT_LEAST_ONCE";
        break;
    default:
        return "ANY";
        break;
    }
}

QJsonArray Regex::toJson() {
    /* Utility for converting a member to an object */
    const static auto ruleToJson = [](const Regex::RegexMember& rule) -> QJsonValue {
        QJsonObject item;
        item["set"] = rule.first.name();
        item["mode"] = repeatModeToString(rule.second);
        return QJsonValue(item);
    };

    QJsonArray result;
    for (const auto& e : rules)
        result.append(ruleToJson(e));

    return result;
}
