#include "TextReaderWorker.h"

#include <QJsonArray>
#include <QJsonObject>

void TextReaderWorker::calcTopWordsFromText(QString text, int topCount)
{
  auto paragraphs = text.toLower().split("\n");
  std::map< QString, int > words;
  double countOfLines = paragraphs.size();
  int i = 1;
  double progress = 0.;

  for (auto &line : paragraphs)
  {
    line.remove(QRegExp("(?![a-z])\\S"));

    auto lineWords = line.split(" ");

    for (auto &word : lineWords)
    {
      if (word == "") continue;
      words[word] += 1;
    }

    double newProgress = i / countOfLines;

    if (static_cast< int >(progress * 100) !=
        static_cast< int >(newProgress * 100))
    {
      progress = newProgress;

      emit currentBarChart(getJsonByMap(getTopWords(words, topCount)));
      emit readProgress(progress);
    }
    ++i;
  }
  emit readFinish();
}

std::map< QString, int > TextReaderWorker::getTopWords(
    const std::map< QString, int > &words, unsigned long topCount)
{
  std::map< int, QString > topWords;

  for (auto &word : words)
  {
    topWords[word.second] = word.first;
  }

  while (topWords.size() > topCount)
  {
    topWords.erase(topWords.begin());
  }

  std::map< QString, int > sortedTopWords;

  for (auto &word : topWords)
  {
    sortedTopWords[word.second] = word.first;
  }

  return sortedTopWords;
}

QJsonObject TextReaderWorker::getJsonByMap(const std::map<QString, int> &words)
{
  QJsonObject topWordsJson;
  QJsonArray columns;
  int maxWordRepetition = 0;

  for (auto &word : words)
  {
    QJsonObject wordData;

    wordData["count"] = word.second;
    wordData["word"] = word.first;

    if (word.second > maxWordRepetition) maxWordRepetition = word.second;

    columns.push_back(wordData);
  }

  topWordsJson["maxWordRepetition"] = maxWordRepetition;
  topWordsJson["columns"] = columns;

  return topWordsJson;
}
