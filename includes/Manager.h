#pragma once

// Qt includes
#include <QQmlApplicationEngine>

class FrontBackProvider;
class TextReader;

class Manager : public QObject
{
public:
  explicit Manager() {}

  void init();

private:
  void initConnections();

  FrontBackProvider* fbProvider;
  TextReader* textReader;

  QQmlApplicationEngine engine;
};
