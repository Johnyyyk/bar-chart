#include "Manager.h"

// Qt includes
#include <QObject>
#include <QQmlContext>

#include "FrontBackProvider.h"

void Manager::init()
{
  fbProvider = new FrontBackProvider(this);
  initConnections();
  engine.rootContext()->setContextProperty("frontBackProvider",
                                           fbProvider);
  engine.load(QUrl(QStringLiteral("qrc:/main.qml"), QUrl::TolerantMode));
}

void Manager::initConnections()
{

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
