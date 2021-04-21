#include "TextReader.h"

#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QThread>

#include "TextReaderWorker.h"

TextReader::TextReader(QObject* parent) : QObject(parent)
{
}

void TextReader::readWordsFromFile(QString path)
{
  QFile file(path.remove("file://"));
  QString text;

  if (file.open(QIODevice::ReadOnly))
  {
    QTextStream in(&file);

    text = in.readAll();

    file.close();
  }
  readWordsFromText(text);
}

void TextReader::readWordsFromText(const QString &text)
{
  auto textReaderWorker = new TextReaderWorker();
  auto thread = new QThread();

  thread->setObjectName("ReaderThread");
  textReaderWorker->moveToThread(thread);

  connect(thread, &QThread::started, textReaderWorker,
          [text, textReaderWorker]() {
            textReaderWorker->calcTopWordsFromText(text);
          });
  connect(textReaderWorker, &TextReaderWorker::currentBarChart, this,
          &TextReader::setFrontBarChart);
  connect(textReaderWorker, &TextReaderWorker::readPogress, this,
          &TextReader::setFrontProgress);
  connect(textReaderWorker, &TextReaderWorker::readFinish, thread,
          &QThread::quit);
  connect(textReaderWorker, &TextReaderWorker::readFinish, textReaderWorker,
          &TextReaderWorker::deleteLater);
  connect(thread, &QThread::finished, thread, &QThread::deleteLater);

  thread->start();
}
