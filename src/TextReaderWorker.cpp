#include "TextReaderWorker.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

void TextReaderWorker::calcTopWordsFromText(QString text)
{
  auto paragraphs = text.toLower().split("\n");
  std::map< QString, int > columns;
  double countOfLines = paragraphs.size();
  int i = 1;
  double progress = 0.;

  for (auto& line : paragraphs)
  {
    line.remove(QRegExp("(?![a-z])\\S"));

    auto words = line.split(" ");

    for (auto& word : words)
    {
      if (word == "") continue;
      columns[word] += 1;
    }

    double newProgress = i / countOfLines;

    if (static_cast< int >(progress * 100) != static_cast< int >(newProgress * 100))
    {
      progress = newProgress;

      emit currentBarChart(getJsonByMap(getTopWords(columns, 15)));
      emit readPogress(progress);
    }
    ++i;
  }
  emit readFinish();
}

std::map<int, QString> TextReaderWorker::getTopWords(const std::map<QString, int> &words, unsigned long topCount)
{
  std::map< int, QString > topWords;

  for (auto &word : words)
  {
    if (topWords[word.second].isEmpty())
      topWords[word.second] = word.first;
    else
      topWords[word.second] = topWords[word.second] + ", " + word.first;
  }

  while (topWords.size() > topCount)
  {
    topWords.erase(topWords.begin());
  }

  return topWords;
}

QJsonObject TextReaderWorker::getJsonByMap(const std::map<int, QString> &words)
{
  QJsonObject topWordsJson;
  QJsonArray columns;
  int maxWordRepetition = 0;

  for (auto word = words.rbegin(); word != words.rend(); ++word)
  {
    QJsonObject wordData;

    wordData["count"] = word->first;
    wordData["word"] = word->second;

    if (word->first > maxWordRepetition) maxWordRepetition = word->first;

    columns.push_back(wordData);
  }

  topWordsJson["maxWordRepetition"] = maxWordRepetition;
  topWordsJson["columns"] = columns;

  return topWordsJson;
}
