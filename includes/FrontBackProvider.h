#pragma once

// Qt includes
#include <QObject>

class FrontBackProvider : public QObject
{
  Q_OBJECT

public:
  explicit FrontBackProvider(QObject *parent = nullptr) : QObject(parent) {}

signals: // To back
//  void press(double x, double y);

signals: // To front
//  void setFrontMainScaleSliderPosition(double position);

};
