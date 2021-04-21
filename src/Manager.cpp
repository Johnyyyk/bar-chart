#include "Manager.h"

// Qt includes
#include <QObject>
#include <QQmlContext>
#include <QThread>

#include "FrontBackProvider.h"
#include "TextReader.h"

void Manager::init()
{
  fbProvider = new FrontBackProvider(this);
  textReader = new TextReader();
  initConnections();

  engine.rootContext()->setContextProperty("frontBackProvider",
                                           fbProvider);
  engine.load(QUrl(QStringLiteral("qrc:/main.qml"), QUrl::TolerantMode));
}

void Manager::initConnections()
{
  connect(textReader, &TextReader::setFrontBarChart, fbProvider,
          &FrontBackProvider::setFrontBarChart);
  connect(textReader, &TextReader::setFrontProgress, fbProvider,
          &FrontBackProvider::setFrontProgress);

  connect(fbProvider, &FrontBackProvider::loadFile, textReader,
          &TextReader::readWordsFromFile);
  connect(fbProvider, &FrontBackProvider::loadByText, textReader,
          &TextReader::readWordsFromText);
}
