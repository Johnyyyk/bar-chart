#include "TextReader.h"

#include <QDebug>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>

TextReader::TextReader(QObject* parent) : QObject(parent)
{
}

void TextReader::readWordsFromFile(QString path)
{
  QFile file(path.remove("file://"));

  if (file.open(QIODevice::ReadOnly))
  {
    QTextStream in(&file);

    readWordsFromText(in.readAll());

//    while (!in.atEnd())
//    {
//      auto line = in.readLine().toLower();

//      if (line == "") continue;

//      line.remove(QRegExp("(?![a-z])\\S+"));

//      auto words = line.split(" ");

//      for (auto& word : words)
//      {
//        if (word == "") continue;
//        columns[word] += 1;
//      }
//      //      qDebug() <<words;
//    }
    file.close();
  }
}

void TextReader::readWordsFromText(QString text)
{
  auto paragraphs = text.toLower().split("\n");
  std::map< QString, int > columns;
  double countOfLines = paragraphs.size();
  int i = 1;

  for (auto& line : paragraphs)
  {
    line.remove(QRegExp("(?![a-z])\\S"));

    auto words = line.split(" ");

    for (auto& word : words)
    {
      if (word == "") continue;
      columns[word] += 1;
    }

    emit setFrontBarChart(getJsonByMap(getTopWords(columns, 15)));
    emit setFrontProgress(i / countOfLines);
    ++i;
  }
}

std::map<int, QString> TextReader::getTopWords(
    const std::map< QString, int >& words, int topCount)
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

QJsonObject TextReader::getJsonByMap(const std::map< int, QString > &words)
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
