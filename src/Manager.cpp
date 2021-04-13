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

  QThread *textReaderThread = new QThread(this);
  textReader->moveToThread(textReaderThread);
  textReaderThread->start();

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

//void Manager::initIFaceConnections(Back::IFace* backIFace)
//{
//  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, backIFace,
//                   &Back::IFace::frontReady);

//#define connectFrontWithBack(signalSlot)                             \
//  QObject::connect(fbProvider.get(), &FrontBackProvider::signalSlot, \
//                   backIFace, &Back::IFace::signalSlot)

//  connectFrontWithBack(press);

//#define connectBackWithFrontImpl(fullSignal, fullSlot) \
//  QObject::connect(backIFace, fullSignal, fbProvider.get(), fullSlot)
//#define connectBackWithFront(signalSlot)             \
//  connectBackWithFrontImpl(&Back::IFace::signalSlot, \
//                           &FrontBackProvider::signalSlot)

//  connectBackWithFront(enableFrontLandmarkSwitchControl);

//#undef connectFrontWithBack
//#undef connectBackWithFrontImpl
//#undef connectBackWithFront
//}
