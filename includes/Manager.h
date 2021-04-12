#pragma once

// STD includes
#include <memory>

// Qt includes
#include <QQmlApplicationEngine>

class FrontBackProvider;

class Manager : public QObject
{
public:
  explicit Manager() {}

  void init();

private:
  void initConnections();

  FrontBackProvider* fbProvider;

  QQmlApplicationEngine engine;
};