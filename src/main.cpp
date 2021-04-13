#include <QApplication>
#include <QFont>

#include "Manager.h"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  Manager manager;

  manager.init();

  return a.exec();
}
