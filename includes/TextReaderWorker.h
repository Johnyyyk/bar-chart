#pragma once

// Qt includes
#include <QObject>

class TextReaderWorker : public QObject
{
  Q_OBJECT

public:
  TextReaderWorker() {}

public slots:
  void calcTopWordsFromText(QString text);

private:
  std::map< int, QString > getTopWords(const std::map< QString, int > &words,
                                       unsigned long topCount);
  QJsonObject getJsonByMap(const std::map< int, QString > &words);

signals:
  void currentBarChart(QJsonObject data);
  void readPogress(double progress);
  void readFinish();
};
