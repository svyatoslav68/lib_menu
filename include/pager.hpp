#ifndef _PAGER_HPP
#define _PAGER_HPP

#include "menu.hpp"
class Pager {
public:
	enum TYPE_RESULT {
		TEXT,
		ACTION,
		LIST
	};
	const unsigned int number_rows = 10;
	//Pager() = 0;
	Pager(TYPE_RESULT type, Menu *menu);
	Pager(Menu *menu):m_type(TEXT),m_displayingMenu(menu),m_numberPage(0){}
	~Pager(){if (m_result_strings) delete m_result_strings;}
	std::string exec();
	std::string exec(TYPE_RESULT type);
	void display() const;
	bool next(); // возвращает False, если вызывается на последней странице
	bool prev(); // возвращает False, если вызывается на первой странице
	void setMenu(Menu *menu, int numberPage);
	std::vector<std::string> *getResultVector() {return m_result_strings;}
private:
	void clearscr() const;
	TYPE_RESULT m_type;
	Menu *m_displayingMenu; // указатель на отображаемое меню
	int m_numberPage; // номер отображаемой страницы
	std::vector<std::string> *m_result_strings = nullptr;
	//std::pair<std::vector<Item *>::const_iterator, std::vector<Item *>::const_iterator> sequence;
};

#endif //_PAGER_HPP
