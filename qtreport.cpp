// Copyright (c) 2000 Peter Karlsson
//
// $Id$
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#include <qlayout.h>
#include <qfiledialog.h>
#include <qcheckbox.h>
#include <qspinbox.h>
#include <qpushbutton.h>
#include <limits.h>

#include "qtreport.h"
#include "statview.h"

bool ReportSelectWindow::doquoters = true;
bool ReportSelectWindow::dotopwritten = true;
bool ReportSelectWindow::dotoporiginal = true;
bool ReportSelectWindow::dotopnets = true;
bool ReportSelectWindow::dotopdomains = true;
bool ReportSelectWindow::dotopreceived = true;
bool ReportSelectWindow::dotopsubjects = true;
bool ReportSelectWindow::dotopprograms = true;
bool ReportSelectWindow::doweekstats = true;
bool ReportSelectWindow::dodaystats = true;
#ifdef HAVE_LOCALE_H
bool ReportSelectWindow::douselocale = true;
#endif

int ReportSelectWindow::defaultmaxnum = 15;

ReportSelectWindow::ReportSelectWindow(QWidget *parent, const char *name,
                                       StatEngine *engine_p)
    : QDialog(parent, name, true), engine(engine_p)
{
    // Create layout
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Add checkboxes
    quoters =
        new QCheckBox(tr("Enable &blacklist of quoters"), this);
    topwritten =
        new QCheckBox(tr("Enable toplist of &writers"), this);
    toporiginal =
        new QCheckBox(tr("Enable toplist of &original content"), this);
    topnets =
        new QCheckBox(tr("Enable toplist of Fidonet &nets"), this);
    topdomains =
        new QCheckBox(tr("Enable toplist of Internet &domains"), this);
    topreceived =
        new QCheckBox(tr("Enable toplist of &receivers"), this);
    topsubjects =
        new QCheckBox(tr("Enable toplist of &subjects"), this);
    topprograms =
        new QCheckBox(tr("Enable toplist of &programs"), this);
    weekstats =
        new QCheckBox(tr("&Enable posting by weekday statistics"), this);
    daystats =
        new QCheckBox(tr("Enable posting by &hour statiscs"), this);
#ifdef HAVE_LOCALE_H
    uselocale =
        new QCheckBox(tr("&Use locale date format"), this);
#endif

    // Check all checkboxes
    quoters->setChecked(doquoters);
    topwritten->setChecked(dotopwritten);
    toporiginal->setChecked(dotoporiginal);
    topnets->setChecked(dotopnets);
    topdomains->setChecked(dotopdomains);
    topreceived->setChecked(dotopreceived);
    topsubjects->setChecked(dotopsubjects);
    topprograms->setChecked(dotopprograms);
    weekstats->setChecked(doweekstats);
    daystats->setChecked(dodaystats);
#ifdef HAVE_LOCALE_H
    uselocale->setChecked(douselocale);
#endif

    // Place in dialog
    layout->addWidget(quoters);
    layout->addWidget(topwritten);
    layout->addWidget(toporiginal);
    layout->addWidget(topnets);
    layout->addWidget(topdomains);
    layout->addWidget(topreceived);
    layout->addWidget(topsubjects);
    layout->addWidget(topprograms);
    layout->addWidget(weekstats);
    layout->addWidget(daystats);
#ifdef HAVE_LOCALE_H
    layout->addWidget(uselocale);
#endif

    // Input boxes
    maxnum = new QSpinBox(1, INT_MAX, 1, this);
    maxnum->setValue(defaultmaxnum);
    maxnum->setSuffix(tr(" entries"));
    layout->addWidget(maxnum);

    // Add buttons
    QHBoxLayout *buttonlayout = new QHBoxLayout(layout);
    
    QPushButton *save = new QPushButton(tr("&Save"), this);
    buttonlayout->addWidget(save);
    connect(save, SIGNAL(clicked()), SLOT(saveToFile()));

    QPushButton *ok = new QPushButton(tr("Cancel"), this);
    buttonlayout->addWidget(ok);
    connect(ok, SIGNAL(clicked()), SLOT(accept()));
}

ReportSelectWindow::~ReportSelectWindow()
{
}

void ReportSelectWindow::saveToFile()
{
    // Browse for filename
    QString filename =
        QFileDialog::getSaveFileName(tr("report.txt"),
                                     tr("Report files (*.txt)"),
                                     this, "savereport", tr("Save report"));
    if (filename.isEmpty()) return; // Cancel

    // Create view object
    StatView view;

    // Save data
    doquoters = quoters->isChecked();
    dotopwritten = topwritten->isChecked();
    dotoporiginal = toporiginal->isChecked();
    dotopnets = topnets->isChecked();
    dotopdomains = topdomains->isChecked();
    dotopreceived = topreceived->isChecked();
    dotopsubjects = topsubjects->isChecked();
    dotopprograms = topprograms->isChecked();
    doweekstats = weekstats->isChecked();
    dodaystats = daystats->isChecked();
#ifdef HAVE_LOCALE_H
    douselocale = uselocale->isChecked();
#endif
    defaultmaxnum = maxnum->value();

    // Enable toplists we want
    view.EnableQuoters(doquoters);
    view.EnableTopWritten(dotopwritten);
    view.EnableTopOriginal(dotoporiginal);
    view.EnableTopNets(dotopnets);
    view.EnableTopDomains(dotopdomains);
    view.EnableTopReceived(dotopreceived);
    view.EnableTopSubjects(dotopsubjects);
    view.EnableTopPrograms(dotopprograms);
    view.EnableWeekStats(doweekstats);
    view.EnableDayStats(dodaystats);
#ifdef HAVE_LOCALE_H
    view.UseLocale(douselocale);
#endif

    // Set toplist parameters
    view.ShowVersions(true);
    view.ShowAllNums(false);
    view.SetMaxEntries(defaultmaxnum);

    // Write output
    view.CreateReport(engine, string(filename.local8Bit()));

    // Close
    accept();
}