#pragma once

// Qt includes
#include <QObject>

class TextReader : public QObject
{
  Q_OBJECT

public:
  explicit TextReader(QObject *parent = nullptr);

public slots:
  void readWordsFromFile(QString path);
  void readWordsFromText(QString text);

private:
  std::map< int, QString > getTopWords(const std::map< QString, int > &words,
                                       int topCount);
  QJsonObject getJsonByMap(const std::map< int, QString > &words);

signals:
  void setFrontBarChart(QJsonObject data);
  void setFrontProgress(double progress);
};

