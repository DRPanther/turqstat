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

#ifndef __QTLIST_H
#define __QTLIST_H

#include <qdialog.h>
#include <string>

class QListView;
class StatEngine;

class TopListWindow : public QDialog
{
    Q_OBJECT

public:
    enum toplist_e
    {
        Quoters, Senders, OrigContent, FidoNets, Domains, Receivers,
        Subjects, Software
    };


    TopListWindow(QWidget *parent, const char *name, toplist_e list);
    ~TopListWindow();

    void fillOut(StatEngine *engine);

protected:
    void setupHeaders();
    void addQuoters(StatEngine *);
    void addSenders(StatEngine *);
    void addOriginalContent(StatEngine *);
    void addFidoNets(StatEngine *);
    void addDomains(StatEngine *);
    void addReceivers(StatEngine *);
    void addSubjects(StatEngine *);
    void addSoftware(StatEngine *);

    char *charConvertCopy(string &);
    QString percentString(int, int);

    QListView   *listview;

    enum toplist_e toplist;

protected slots:
    void saveToFile();
};

#endif