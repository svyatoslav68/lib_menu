#ifndef _MENU_HPP
#define _MENU_HPP
/*****************************************************************************
 *****************  файл menu.hpp ********************************************
 ****************************************************************************/
#include <stack>
#include <vector>

class Pager;
class Item;

class Menu {
public:
	//Menu();
	Menu(std::string name);
	Menu(std::string name, std::vector<std::string> &content);
	Menu(std::string name, socibd::Connection &con, std::string SQL);
	static std::stack<Menu *> menuStack;
	void addItem(const Item& newitem, const int after);
	void addSubMenu(const Menu& submenu, const int after);
	~Menu();
	std::string getName() {return m_string_name;}
	friend class Pager;
	//Item *getBeginItem() {return &(m_items->at(0));}
	static void enterMenu(Menu *); // вход в меню, меню помещается на стек
	static Menu* exitMenu(); // выход из меню, меню снимается со стека
	bool isActiveMenu(); // true, если на вершине menuStack есть меню
private:
	std::string m_string_name;
	unsigned int m_size;
	Menu *m_parent;
	std::vector<Item> *m_items;
};
#endif //_MENU_HPP
