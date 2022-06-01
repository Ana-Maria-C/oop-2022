#include"Contact.h"
#include"Agenda.h"
#include "Prieten.h"
#include "Coleg.h"
#include "Cunoscut.h"
#include<iostream>
using namespace std;

int main()
{
	Prieten friend1 = Prieten("Ioana", "20/05/2003", "0769560734", "Iasi");
	Prieten friend2 = Prieten("Alin", "12/08/2010", "0763790570", "Botosani");
	Prieten friend3 = Prieten("Rusu", "02/02/2002", "0743760500", "Galati");
	Agenda Agenda;
	Agenda.Add_contact(&friend1);
	Agenda.Add_contact(&friend2);
	Agenda.Add_contact(&friend3);
	Coleg coleg = Coleg("Andreea", "0735273910", "BitDefender", "Iasi");
	Cunoscut cunoscut = Cunoscut("Ioan", "0725633121");
	Agenda.Add_contact(&coleg);
	Agenda.Add_contact(&cunoscut);
	Agenda.Friends_contact();
	Agenda.Delete_contact("Ioana");
	Agenda.Friends_contact();
	Agenda.Search_by_name("Rusu");
	Agenda.Search_by_name("Maria");
	return 0;
}