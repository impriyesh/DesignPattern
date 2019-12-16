#include <iostream>

// Product

class Product {
public:
    virtual ~Product() { }
    virtual void say() = 0;
};

class ConcreteProduct :public Product {
public:
    ConcreteProduct() {
        std::cout << "ConcreteProduct..." << std::endl;
    }
    void say() {
        std::cout << "ConcreteProduct Say... now see this derived \\
			concrete product class \n\n object is getting called from base class object" << std::endl;
    }
    ~ConcreteProduct() { }
};

// Factory

class Factory {
public:
    virtual Product* CreateProduct() = 0;
    virtual ~Factory() { }
protected:
    Factory() { }
};

class ConcreteFactory :public Factory {
public:
	// constructor
    ConcreteFactory() {
        std::cout << "ConcreteFactory..." << std::endl;
    }
	//destructor
    ~ConcreteFactory() {

    }
	// method to create the class object. In this case concrete objects.
    Product* CreateProduct() {
        return new ConcreteProduct();
    }

};

// Test best way to learn dsign pattern - checking git 12/16
// with the help of base class object we are geting the concrete class object.
// now with the base object we are calling te CreateProduct() method, which is defined 
// inside the derived class ConcreteProduct.

int main() {

	//IN Factory Patterm you first create a ConcreteFactory object and store it in base class factory
	// Now call the CreateFactory method in ConcreteFactory class with factory object
	// 
	// from the factory class you call the CreateProduct() method
    Factory *factory = new ConcreteFactory();
    Product *product = factory->CreateProduct();
    product->say();

    delete factory;
    delete product;

    return 0;
}
