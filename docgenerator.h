#ifndef DOCGENERATOR_H
#define DOCGENERATOR_H
#include <QVector>
#include <QFileDialog>
#include <QString>
#include "match.h"
#include "WordProcessingMerger.h"
using namespace DocxFactory;


class DocGenerator
{
public:
    static void generateSchedule(QVector<Match *> &v);
    DocGenerator();
};

#endif // DOCGENERATOR_H
