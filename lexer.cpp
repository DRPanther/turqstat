// Copyright (c) 2002-2008 Peter Krefting
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

#include <stdlib.h>

#include "utility.h"
#include "lexer.h"
#include "output.h"

Token *Token::Parse(const string &line, const Section *current, bool &error)
{
	bool in_settings =
		current &&
		(current->GetSection() == Section::Settings ||
		 current->GetSection() == Section::Localization);

    // Parse a single line.
    if (';' == line[0])
    {
        if (';' == line[1] && !in_settings)
        {
            // Double semi-colon means that line starts with a semi-colon
            return Parse2(line.substr(1), error);
        }
        else
        {
            // Line is a comment
            return NULL;
        }
    }
    else if ('[' == line[0])
    {
        // Line is a section name
        string::size_type endbracket = line.find(']');
        if (string::npos == endbracket)
        {
            error = true;
            return NULL;
        }
        else
        {
            return new Section(line.substr(1, endbracket - 1), error);
        }
    }
	else if (in_settings)
	{
		if (line != "")
		{
			return new Setting(line, current, error);
		}
	}

    // Call real parser
    return Parse2(line, error);
}

Token *Token::Parse2(string line, bool &error)
{
    // Parse a regular line
    string::size_type pos = 0;
    Token *head = NULL;

    if ('@' == line[0])
    {
        // Find end of variable and parse it
        pos = line.find('@', 1);
        if (1 == pos)
        {
            // Literal @ sign.
            pos = line.find('@', 2);
            if (string::npos == pos)
            {
                head = new Literal(line.substr(1), true);
            }
            else
            {
                head = new Literal(line.substr(1, pos - 1));
            }
        }
        else if (string::npos == pos)
        {
            // Incorrect syntax
            error = true;
            return NULL;
        }
        else
        {
            // Real variable
            head = new Variable(line.substr(1, pos - 1), error);
            pos ++;
        }
    }
    else
    {
        // String literal up to next variable or end-of-line
        pos = line.find('@');
        if (string::npos == pos)
        {
            head = new Literal(line, true);
        }
        else
        {
            head = new Literal(line.substr(0, pos));
        }
    }

    if (pos != string::npos && pos < line.length())
    {
        head->m_next_p = Parse2(line.substr(pos), error);
    }
	else
	{
		if (head->IsVariable())
		{
			// If the last token on a line is a variable, add a final
			// linebreak token
			head->m_next_p = new Literal("", true);
		}
	}

    return head;
}

Literal::Literal(string s, bool lineend)
    : Token(),
      m_literal(s),
      m_linebreak(lineend)
{
    // If the line ends with a single backslash, remove the linebreak.
    // If the line ends with double backslashes, change them into one.
    if (lineend)
    {
        string::size_type len = s.length();
        if (len && m_literal[len - 1] == '\\')
        {
            // No matter what we erase the last character if it was a
            // backslash.
            m_literal.erase(len - 1);
            m_linebreak = m_literal[len - 2] == '\\';
        }
    }
}

Section::Section(string s, bool &error)
    : Token()
{
    // Translate token string into enumeration value.
    if (0 == fcompare(s, "Common"))          m_section = Common;
    else if (0 == fcompare(s, "IfEmpty"))    m_section = IfEmpty;
    else if (0 == fcompare(s, "IfNotNews"))  m_section = IfNotNews;
    else if (0 == fcompare(s, "IfNews"))     m_section = IfNews;
    else if (0 == fcompare(s, "Original"))   m_section = Original;
    else if (0 == fcompare(s, "Quoters"))    m_section = Quoters;
    else if (0 == fcompare(s, "Writers"))    m_section = Writers;
    else if (0 == fcompare(s, "TopNets"))    m_section = TopNets;
    else if (0 == fcompare(s, "TopDomains")) m_section = TopDomains;
    else if (0 == fcompare(s, "Received"))   m_section = Received;
    else if (0 == fcompare(s, "Subjects"))   m_section = Subjects;
    else if (0 == fcompare(s, "Programs"))   m_section = Programs;
    else if (0 == fcompare(s, "Week"))       m_section = Week;
    else if (0 == fcompare(s, "Day"))        m_section = Day;
	else if (0 == fcompare(s, "Settings"))   m_section = Settings;
	else if (0 == fcompare(s, "Localization")) m_section = Localization;
    else error = true;
}

Variable::Variable(string s, bool &error)
    : Token(),
      m_width(0)
{
    // Find parameters
    string::size_type bracket1 = s.find('[');
    string::size_type bracket2 = s.find(']', bracket1 + 1);
    string::size_type namelen = bracket1;

    while (bracket1 != string::npos && bracket2 != string::npos &&
           bracket2 > bracket1 + 1)
    {
        // Valid indexing
        if (isdigit(s[bracket1 + 1]))
        {
            SetWidth(s.substr(bracket1 + 1, bracket2 - bracket1 - 1));
        }
        else
        {
            error = true;
        }

        // Find next bracket, if any
        bracket1 = s.find('[', bracket2 + 1);
        bracket2 = s.find(']', bracket1 + 1);
    }

    if (namelen != string::npos)
    {
        SetVariable(s.substr(0, namelen), error);
    }
    else
    {
        SetVariable(s, error);
    }
}

void Variable::SetWidth(string s)
{
    m_width = atoi(s.c_str());
}

void Variable::SetVariable(string s, bool &error)
{
    // Translate token string into enumeration value.
    if (0 == fcompare(s, "Version"))                 m_type = Version;
    else if (0 == fcompare(s, "Copyright"))          m_type = Copyright;
    else if (0 == fcompare(s, "IfReceived"))         m_type = IfReceived;
    else if (0 == fcompare(s, "IfAreas"))            m_type = IfAreas;
    else if (0 == fcompare(s, "Place"))              m_type = Place;
    else if (0 == fcompare(s, "Name"))               m_type = Name;
    else if (0 == fcompare(s, "Written"))            m_type = Written;
    else if (0 == fcompare(s, "BytesWritten"))       m_type = BytesWritten;
    else if (0 == fcompare(s, "Ratio"))              m_type = Ratio;
    else if (0 == fcompare(s, "BytesTotal"))         m_type = BytesTotal;
    else if (0 == fcompare(s, "BytesQuoted"))        m_type = BytesQuoted;
    else if (0 == fcompare(s, "TotalAreas"))         m_type = TotalAreas;
    else if (0 == fcompare(s, "TotalPeople"))        m_type = TotalPeople;
    else if (0 == fcompare(s, "TotalNets"))          m_type = TotalNets;
    else if (0 == fcompare(s, "TotalDomains"))       m_type = TotalDomains;
    else if (0 == fcompare(s, "TotalSubjects"))      m_type = TotalSubjects;
    else if (0 == fcompare(s, "TotalPrograms"))      m_type = TotalPrograms;
    else if (0 == fcompare(s, "EarliestReceived"))   m_type = EarliestReceived;
    else if (0 == fcompare(s, "LastReceived"))       m_type = LastReceived;
    else if (0 == fcompare(s, "EarliestWritten"))    m_type = EarliestWritten;
    else if (0 == fcompare(s, "LastWritten"))        m_type = LastWritten;
    else if (0 == fcompare(s, "BytesOriginal"))      m_type = BytesOriginal;
    else if (0 == fcompare(s, "PerMessage"))         m_type = PerMessage;
    else if (0 == fcompare(s, "Fidonet"))            m_type = Fidonet;
    else if (0 == fcompare(s, "TopDomain"))          m_type = TopDomain;
    else if (0 == fcompare(s, "Received"))           m_type = Received;
    else if (0 == fcompare(s, "ReceiveRatio"))       m_type = ReceiveRatio;
    else if (0 == fcompare(s, "Subject"))            m_type = Subject;
    else if (0 == fcompare(s, "Program"))            m_type = Program;
    else if (0 == fcompare(s, "Bar"))                m_type = Bar;
    else error = true;
}

Setting::Setting(string s, const Section *current, bool &error)
{
	// Find divider
	string::size_type equals = s.find('=');
	if (equals == string::npos)
	{
		error = true;
	}
	else
	{
		SetType(s.substr(0, equals), current, error);
		SetValue(s.substr(equals + 1));
	}	
}

void Setting::SetType(string s, const Section *current, bool &error)
{
	// Translate setting string into enumeration value
	switch (current->GetSection())
	{
	case Section::Settings:
		if (0 == fcompare(s, "HTML"))			m_type = HTML;
		else error = true;
		break;

	case Section::Localization:
		if (0 == fcompare(s, "Mon"))		m_type = Monday;
		else if (0 == fcompare(s, "Tue"))		m_type = Tuesday;
		else if (0 == fcompare(s, "Wed"))		m_type = Wednesday;
		else if (0 == fcompare(s, "Thu"))		m_type = Thursday;
		else if (0 == fcompare(s, "Fri"))		m_type = Friday;
		else if (0 == fcompare(s, "Sat"))		m_type = Saturday;
		else if (0 == fcompare(s, "Sun"))		m_type = Sunday;
		else error = true;
		break;

	default:
		TDisplay::GetOutputObject()->
			InternalErrorQuit(TDisplay::template_parse_error, 1);
		break;
	}
}
