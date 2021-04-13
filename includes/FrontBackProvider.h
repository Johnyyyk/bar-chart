#pragma once

// Qt includes
#include <QObject>
#include <QJsonObject>

class FrontBackProvider : public QObject
{
  Q_OBJECT

public:
  explicit FrontBackProvider(QObject *parent = nullptr) : QObject(parent) {}

signals: // To back
  void loadFile(QString path);
  void loadByText(QString text);

signals: // To front
  void setFrontBarChart(QJsonObject data);
  void setFrontProgress(double progress);
};
