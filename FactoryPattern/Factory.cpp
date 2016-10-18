#include <iostream>

/*Abstract Product */
class Button
{
public:
	virtual void createButton() = 0;
};

/*Concrete Product */
class AndroidOS :public Button
{
public:
	void createButton()
	{
		std::cout << "Created Windows specific Button" << std::endl;
	}
};

/*Concrete Product */
class iOS :public Button
{
public:
	void createButton()
	{
		std::cout << "Created ios specific Button" << std::endl;
	}
};

/*Concrete Product */
class Win :public Button
{
public:
	void createButton()
	{
		std::cout << "Created windows specific Button" << std::endl;
	}
};

/* Factory */
class Factory
{
public:
	virtual Button* chooseOSButton()
	{
		return new AndroidOS;
	}
};

/* Derived Factory*/
template<typename OS>
class ButtonCreator :public Factory
{
private:
	bool typecheck;
public:
	ButtonCreator() :typecheck(false) {}
	Button* chooseOSButton()
	{
		typecheck = (std::is_same<OS, Win>::value || std::is_same<OS, iOS>::value || std::is_same<OS, AndroidOS>::value);
		if (typecheck)
		{
			return new OS;
		}
	}
};

int main()
{
	Button *buttonobj;
	Factory *obj = new ButtonCreator<Win>;
	buttonobj = obj->chooseOSButton();
	buttonobj->createButton();

	obj = new ButtonCreator<iOS>;
	buttonobj = obj->chooseOSButton();
	buttonobj->createButton();

	obj = new ButtonCreator<AndroidOS>;
	buttonobj = obj->chooseOSButton();
	buttonobj->createButton();

	return 0;
}