#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(1270, 720);

    QStringList horizontalHeader;
    horizontalHeader.append("Lp.");
    horizontalHeader.append("Nazwa drużyny");
    horizontalHeader.append("Pkt.");
    teamList.setHorizontalHeaderLabels(horizontalHeader);

    ui->teamView->setModel(&teamList);
    ui->teamView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->teamView->setColumnWidth(0, 40);
    ui->teamView->setColumnWidth(1, 430);
    ui->teamView->setColumnWidth(2, 40);
    ui->teamView->setStyleSheet("QHeaderView::section { background-color: #F6F6F6 }");
    ui->teamView->verticalHeader()->setVisible(false);
    ui->teamView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    QStringList header2;
    header2.append("Lp.");
    header2.append("Mecz");
    header2.append("Wynik");
    matchList.setHorizontalHeaderLabels(header2);

    ui->matchView->setModel(&matchList);
    ui->matchView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->matchView->setColumnWidth(0, 40);
    ui->matchView->setColumnWidth(1, 640);
    ui->matchView->setColumnWidth(2, 76);
    ui->matchView->setStyleSheet("QHeaderView::section { background-color: #F6F6F6 }");
    ui->matchView->verticalHeader()->setVisible(false);
    ui->matchView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
}

void MainWindow::updateTeamList()
{
    teamList.clear();
    QStringList horizontalHeader;
    horizontalHeader.append("Lp.");
    horizontalHeader.append("Nazwa drużyny");
    horizontalHeader.append("Pkt.");
    teamList.setHorizontalHeaderLabels(horizontalHeader);
    ui->teamView->setColumnWidth(0, 40);
    ui->teamView->setColumnWidth(1, 430);
    ui->teamView->setColumnWidth(2, 40);
    ui->teamView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    for(int x = 0; x < teams.size(); x++)
    {
        QStandardItem *lp = new QStandardItem(QString::number(x + 1));
        teamList.setItem(x, 0, lp);
        QStandardItem *team = new QStandardItem(teams[x]->getTeamName());
        teamList.setItem(x, 1, team);
        QStandardItem *points = new QStandardItem(QString::number(teams[x]->getScore()));
        teamList.setItem(x, 2, points);
    }
    ui->teamView->setModel(&teamList);
}

void MainWindow::updateMatchList()
{
    matchList.clear();
    QStringList header2;
    header2.append("Lp.");
    header2.append("Mecz");
    header2.append("Wynik");
    matchList.setHorizontalHeaderLabels(header2);

    ui->matchView->setModel(&matchList);
    ui->matchView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->matchView->setColumnWidth(0, 40);
    ui->matchView->setColumnWidth(1, 640);
    ui->matchView->setColumnWidth(2, 76);
    ui->matchView->setStyleSheet("QHeaderView::section { background-color: #F6F6F6 }");
    ui->matchView->verticalHeader()->setVisible(false);
    ui->matchView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    for(int c = 0; c < matches.size(); c++)
    {
        int rows = matchList.rowCount();
        QStandardItem *lp = new QStandardItem(QString::number(c + 1));
        matchList.setItem(rows, 0, lp);
        QStandardItem *vs = new QStandardItem(matches[c]->getTeam1Name() + " vs " + matches[c]->getTeam2Name());
        matchList.setItem(rows, 1, vs);
		if (matches[c]->getTeam1Score() != -1 && matches[c]->getTeam1Score() != -1)
		{
			QStandardItem *score = new QStandardItem(QString::number(matches[c]->getTeam1Score()) + " : " + QString::number(matches[c]->getTeam2Score()));
			matchList.setItem(rows, 2, score);
		}
	}       
}

int MainWindow::findTeamIndex(int ID)
{
	for (int x = 0; x < teams.size(); x++)
	{
		if (teams[x]->getId() == ID)
		{
			return x;
		}
	}
}

MainWindow::~MainWindow()
{
    delete ui;
    delete a;
	for (int x = 0; x < teams.size(); x++)
	{
		delete teams[x];
	}
	for (int x = 0; x < matches.size(); x++)
	{
		delete matches[x];
	}
}

void MainWindow::newTeam()
{
    int rows = teamList.rowCount();
    teams.push_back(new Team(teams.size() + 1, a->getName()));
    QStandardItem *lp = new QStandardItem(QString::number(teams.size()));
    teamList.setItem(rows, 0, lp);
    QStandardItem *team = new QStandardItem(teams[teams.size() - 1]->getTeamName());
    teamList.setItem(rows, 1, team);
    QStandardItem *points = new QStandardItem(QString::number(0));
    teamList.setItem(rows, 2, points);
	if (teams.size() == 3)
	{
		ui->startTournament->setEnabled(true);
	}
}

void MainWindow::newScore()
{
	int t1 = matches[b->getMatchID()]->getTeam1ID();
	int t2 = matches[b->getMatchID()]->getTeam2ID();
    int t1Score = b->getTeam1Score();
    int t2Score = b->getTeam2Score();
    matches[b->getMatchID()]->setTeam1Score(t1Score);
    matches[b->getMatchID()]->setTeam2Score(t2Score);
    if(t1Score > t2Score)
    {
        teams[findTeamIndex(t1)]->addWin();
        teams[findTeamIndex(t2)]->addLoss();
        teams[findTeamIndex(t1)]->setScore(3);
        teams[findTeamIndex(t1)]->setSmallPoints(t1Score);
        teams[findTeamIndex(t2)]->setSmallPoints(t2Score);
    }
    else if (t1Score < t2Score)
    {
        teams[findTeamIndex(t1)]->addLoss();
        teams[findTeamIndex(t2)]->addWin();
        teams[findTeamIndex(t2)]->setScore(3);
        teams[findTeamIndex(t1)]->setSmallPoints(t1Score);
        teams[findTeamIndex(t2)]->setSmallPoints(t2Score);
    }
    else if (t1Score == t2Score)
    {
        teams[findTeamIndex(t1)]->addTie();
        teams[findTeamIndex(t2)]->addTie();
        teams[findTeamIndex(t1)]->setScore(1);
        teams[findTeamIndex(t2)]->setScore(1);
        teams[findTeamIndex(t1)]->setSmallPoints(t1Score);
        teams[findTeamIndex(t2)]->setSmallPoints(t2Score);
    }
	qSort(teams.begin(), teams.end(), [](const Team *a, const Team *b) {return a->getScore() > b->getScore(); });
    updateMatchList();
	updateTeamList();
}


void MainWindow::on_addTeam_triggered()
{
    a = new AddTeam();
    connect(a, SIGNAL(newTeam()), this, SLOT(newTeam()));
    a->setModal(true);
    a->exec();
    connect(a, &AddTeam::deleteScreen, [=](){delete a;});
}

void MainWindow::randomizeTeams()
{
    QVector<Team *> tmp;
    QVector<int> random;
    int x = teams.size();
    int j;
    while (x != 0)
    {
        bool r = false;
        j = qrand() % (teams.size()) + 1;
        for (int z = 0; z < random.size(); z++)
        {
            if (random[z] == j)
            {
                r = true;
                break;
            }
        }
        if (r == false)
        {
            random.push_back(j);
            x--;
        }
    }
    for(int w = 0; w<teams.size(); w++)
    {
        tmp.push_back(teams[random[w] - 1]);
    }
    for(int w = 0; w<teams.size(); w++)
    {
        teams[w] = tmp[w];
    }
    for(int g = 0; g<teams.size(); g++)
    {
        teams[g]->setId(g);
    }
}

void MainWindow::matchTeams()
{
    QVector<QVector<int>> berger;
    int permutations = 0;
    int x = teams.size();
    int z = 0;
    int helper;
    if(x % 2 == 0)
    {
        permutations = x - 1;
        x /= 2;
    }
    else
    {
        permutations = x;
        x = x/2 + 1;
    }
    berger.resize(x);
    for(; z<x; z++)
    {
        berger[z].push_back(z + 1);
    }
    z++;
    for(int j = z - 2; j >= 0; j--)
    {
        berger[j].push_back(z);
        z++;
    }

    for(int g = 0; g < permutations; g++)
    {
        if(teams.size() % 2 == 0)
        {
            for(int w = 0; w < x; w++)
            {
                matches.push_back(new Match(matches.size() + 1, berger[w][0] - 1, berger[w][1] - 1, teams[berger[w][0] - 1]->getTeamName(), teams[berger[w][1] - 1]->getTeamName()));
            }
        }
        if(teams.size() % 2 != 0)
        {
            for(int w = 1; w < x; w++)
            {
                matches.push_back(new Match(matches.size() + 1, berger[w][0] - 1, berger[w][1] - 1, teams[berger[w][0] - 1]->getTeamName(), teams[berger[w][1] - 1]->getTeamName()));
            }
        }

        helper = berger[1][1];
        for(int h = 1; h<x-1; h++)
        {
            berger[h][1] = berger[h + 1][1];
        }
        berger[x - 1][1] = berger[x - 1][0];
        for(int m = x - 1; m > 0; m--)
        {
            berger[m][0] = berger[m - 1][0];
        }
        berger[0][0] = helper;
    }

    for(int c = 0; c < matches.size(); c++)
    {
        int rows = matchList.rowCount();
        QStandardItem *lp = new QStandardItem(QString::number(c + 1));
        matchList.setItem(rows, 0, lp);
        QStandardItem *vs = new QStandardItem(matches[c]->getTeam1Name() + " vs " + matches[c]->getTeam2Name());
        matchList.setItem(rows, 1, vs);
    }
}

void MainWindow::on_startTournament_triggered()
{
    randomizeTeams();
    matchTeams();
    updateTeamList();	
	ui->addTeam->setDisabled(true);
	ui->generateSchedule->setEnabled(true);
	ui->startTournament->setDisabled(true);
}

void MainWindow::on_matchView_doubleClicked(const QModelIndex &index)
{
	if (matches[index.row()]->getTeam1Score() == -1 && matches[index.row()]->getTeam2Score() == -1)
	{
		b = new AddScore(index.row(), matches[index.row()]->getTeam1Name(), matches[index.row()]->getTeam2Name());
		connect(b, SIGNAL(newScore()), this, SLOT(newScore()));
		b->setModal(true);
		b->exec();
        connect(b, &AddScore::deleteScreen, [=]() {delete b; });
	}    
}

void MainWindow::on_generateSchedule_triggered()
{
   DocGenerator::generateSchedule(matches);
}

void MainWindow::on_teamView_doubleClicked(const QModelIndex &index)
{
    c = new TeamInfo(teams[index.row()]->getTeamName(), QString::number(teams[index.row()]->getWins()), QString::number(teams[index.row()]->getTies()), QString::number(teams[index.row()]->getLosses()), QString::number(teams[index.row()]->getSmallPoints()));
    c->setModal(true);
    c->exec();
    connect(c, &TeamInfo::deleteScreen, [=]() {delete c; });
}
