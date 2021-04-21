#include "TextReader.h"

#include <QFile>
#include <QTextStream>
#include <QThread>
#include <QUrl>

#include "TextReaderWorker.h"

TextReader::TextReader(QObject* parent) : QObject(parent), columnCount(15)
{
}

void TextReader::setColumnCount(int count)
{
  columnCount = count;
}

void TextReader::readWordsFromFile(QString path)
{
  QFile file(QUrl(path).toLocalFile());

  QString text;

  if (file.open(QIODevice::ReadOnly))
  {
    QTextStream in(&file);

    text = in.readAll();

    file.close();
  }
  readWordsFromText(text);
}

void TextReader::readWordsFromText(const QString& text)
{
  auto textReaderWorker = new TextReaderWorker();
  auto thread = new QThread();

  thread->setObjectName("ReaderThread");
  textReaderWorker->moveToThread(thread);

  connect(thread, &QThread::started, textReaderWorker,
          [=]() { textReaderWorker->calcTopWordsFromText(text, columnCount); });
  connect(textReaderWorker, &TextReaderWorker::currentBarChart, this,
          &TextReader::setFrontBarChart);
  connect(textReaderWorker, &TextReaderWorker::readProgress, this,
          &TextReader::setFrontProgress);
  connect(textReaderWorker, &TextReaderWorker::readFinish, thread,
          &QThread::quit);
  connect(textReaderWorker, &TextReaderWorker::readFinish, textReaderWorker,
          &TextReaderWorker::deleteLater);
  connect(thread, &QThread::finished, thread, &QThread::deleteLater);

  thread->start();
}
