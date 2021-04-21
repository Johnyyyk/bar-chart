#pragma once

// Qt includes
#include <QObject>

class TextReader : public QObject
{
  Q_OBJECT

public:
  explicit TextReader(QObject *parent = nullptr);

public slots:
  void setColumnCount(int count);

  void readWordsFromFile(QString path);
  void readWordsFromText(const QString &text);

private:
  int columnCount;

signals:
  void setFrontBarChart(QJsonObject data);
  void setFrontProgress(double progress);

};

