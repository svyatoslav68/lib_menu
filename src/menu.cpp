#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <functional>
#define SOCI_USE_BOOST
#include <soci/soci.h>
#include "connection.hpp"
#include "item.hpp"
#include "pager.hpp"

// Определение статической переменной-члена класса
std::stack<Menu *> Menu::menuStack;

void Menu::enterMenu(Menu *menu){
	menuStack.push(menu);
}

Menu *Menu::exitMenu(){
	if (!menuStack.empty()) {
		menuStack.pop();
		return menuStack.top();
		//return el;
	}
	else 
		return nullptr;
}

bool Menu::isActiveMenu(){
	return ! menuStack.empty();
}

//Menu::

Menu::Menu(std::string name):m_string_name(name),m_size(0),m_parent(nullptr){
	m_items = new std::vector<Item>();
}

Menu::Menu(std::string name, std::vector<std::string> &content):Menu(name)
{
	for (std::string item: content) {
		m_items->push_back(item);
	}
	m_size = m_size+content.size();
}

Menu::Menu(std::string name, socibd::Connection &con, std::string SQL):Menu(name)
{
	std::vector<std::string> values_from_bd;
	values_from_bd = con.getColumn<std::string>(SQL);
	for (std::string item: values_from_bd) {
		m_items->push_back(item);
	}
	m_size = m_size+values_from_bd.size();
}

void Menu::addItem(const Item& newitem, const int after = -1){
	m_items->push_back(newitem);
	++m_size;
}

void Menu::addSubMenu(const Menu& submenu, const int after){

}

Menu::~Menu(){
	delete m_items;
}
