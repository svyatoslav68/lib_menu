#pragma once

class Menu;
class Item{
public:
	Item();
	Item(std::string text);
	Item(std::string text, Menu *subMenu);
	std::string getText() const {return m_text_item;}
	//void action() const;
	void setAction(std::function<void(std::string)> action);
	std::function<void(const std::string)> action;
	Menu *getMenu() const {return m_subMenu;}
	bool isMenu() const {return this->m_subMenu!=nullptr;}
	~Item();
private:
	std::string m_text_item;
	std::function<void(std::string)> m_action;
	Menu *m_subMenu = nullptr;
	//void *(
};

