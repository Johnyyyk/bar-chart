#pragma once

// Qt includes
#include <QJsonObject>
#include <QObject>

class FrontBackProvider : public QObject
{
  Q_OBJECT

public:
  explicit FrontBackProvider(QObject *parent = nullptr) : QObject(parent) {}

signals:  // To back
  void setColumnCount(int count);

  void loadFile(QString path);
  void loadByText(QString text);

signals:  // To front
  void setFrontBarChart(QJsonObject data);
  void setFrontProgress(double progress);
};
