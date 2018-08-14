#include "mainwindow.h"
#include "ui_mainwindow.h"

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
                //crash here
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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTeam()
{
    int rows = teamList.rowCount();
    teams.push_back(new Team(teams.size() + 1, s->getName()));
    QStandardItem *lp = new QStandardItem(QString::number(teams.size()));
    teamList.setItem(rows, 0, lp);
    QStandardItem *team = new QStandardItem(teams[teams.size() - 1]->getTeamName());
    teamList.setItem(rows, 1, team);
    QStandardItem *points = new QStandardItem(QString::number(0));
    teamList.setItem(rows, 2, points);
}

void MainWindow::on_pushButton_clicked()
{
    s = new TeamAddingScreen;
    connect(s, SIGNAL(newTeam()), this, SLOT(addTeam()));
    s->setModal(true);
    s->exec();
    connect(s, &TeamAddingScreen::deleteScreen, [=](){delete s;});
}

void MainWindow::on_pushButton_2_clicked()
{
    randomizeTeams();
    updateTeamList();
    matchTeams();
}

void MainWindow::on_help_triggered()
{

}
