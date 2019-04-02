#include "docgenerator.h"

void DocGenerator::generateSchedule(QVector<Match *> &v)
{
	WordProcessingMerger& l_merger = WordProcessingMerger::getInstance();
	l_merger.load("scheduleTemplate.dfw");
    l_merger.paste("schedule");
    for (int i = 0; i < v.size(); i++)
    {
		l_merger.setClipboardValue("linia", "lp", string(std::to_string(i + 1) + "."));
        l_merger.setClipboardValue("linia", "team1", string(v[i]->getTeam1Name().toStdString()));
        l_merger.setClipboardValue("linia", "team2", string(v[i]->getTeam2Name().toStdString()));
		l_merger.paste("linia");
	}
	QString fileName = QFileDialog::getSaveFileName(nullptr,"Zapisz:", "", "Word Document (*.docx)");
    l_merger.save(fileName.toStdString());
}

DocGenerator::DocGenerator()
{

}
