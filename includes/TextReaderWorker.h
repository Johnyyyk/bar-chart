#pragma once

// Qt includes
#include <QObject>

class TextReaderWorker : public QObject
{
  Q_OBJECT

public:
  TextReaderWorker(QObject *parent = nullptr) : QObject(parent) {}

public slots:
  void calcTopWordsFromText(QString text, int topCount);

private:
  std::map< int, QString > getTopWords(const std::map< QString, int > &words,
                                       unsigned long topCount);
  QJsonObject getJsonByMap(const std::map< int, QString > &words);

signals:
  void currentBarChart(QJsonObject data);
  void readProgress(double progress);
  void readFinish();
};
