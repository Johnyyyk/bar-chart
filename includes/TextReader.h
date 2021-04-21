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
  void readWordsFromText(const QString &text);

signals:
  void setFrontBarChart(QJsonObject data);
  void setFrontProgress(double progress);
};

