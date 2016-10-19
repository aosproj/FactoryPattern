#include<iostream>

class Pizza {
public:
	virtual void prepare() = 0;
	virtual void bake();
	virtual void cut();
	virtual void box();
};

void Pizza::bake()
{
	std::cout << "Baking the pizza" << std::endl;
}

void Pizza::cut()
{
	std::cout << "Cutting the pizza into slices" << std::endl;
}

void Pizza::box()
{
	std::cout << "Boxing the pizza" << std::endl;
}

class CheesePizza :public Pizza
{
	void prepare()
	{
		std::cout << "Creating a cheese pizza" << std::endl;
	}
};

class VeggiePizza :public Pizza
{
	void prepare()
	{
		std::cout << "Creating a veggie pizza" << std::endl;
	}
};

class ClamPizza :public Pizza
{
	void prepare()
	{
		std::cout << "Creating a clam pizza" << std::endl;
	}
};

class SimplePizzaFactory
{
public:

	Pizza *createPizza(char *type)
	{
		if (strcmp(type, "CheesePizza"))
		{
			return new CheesePizza;
		}
		else if (strcmp(type, "VeggiePizza"))
		{
			return new VeggiePizza;
		}
		else if (strcmp(type, "ClamPizza"))
		{
			return new ClamPizza;
		}
	}
};

class PizzaStore
{
	SimplePizzaFactory *factory;
	Pizza *pizza;

public:
	PizzaStore(SimplePizzaFactory *factory)
	{
		this->factory = factory;
	}

	void createPizza(char *type)
	{
		pizza = factory->createPizza(type);
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
	}

};

int main()
{
	SimplePizzaFactory *factory = new SimplePizzaFactory();
	PizzaStore *pstore = new PizzaStore(factory);
	pstore->createPizza("CheesePizza");
}