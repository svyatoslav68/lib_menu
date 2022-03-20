#include <iostream>
#include <string>
#include <functional>
#define SOCI_USE_BOOST
#include <soci/soci.h>
#include "connection.hpp"
#include "menu.hpp"
#include "item.hpp"

Item::Item():m_subMenu(nullptr)
{

}

Item::Item(std::string text):m_text_item(text),m_subMenu(nullptr)
{

}

Item::Item(std::string text, Menu *subMenu):m_text_item(text),
															m_subMenu(subMenu)
{

}

Item::~Item()
{

}

void Item::setAction(std::function<void(std::string)> _action)
{
	//action = _action;//
	action = std::bind(_action, std::placeholders::_1);
//	m_action("wiwiwiw");
}

