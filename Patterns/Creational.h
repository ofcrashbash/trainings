#pragma once
namespace FabricMethod
{
	namespace ProductCreator 
	{
		struct Product
		{
			//pure virtual function
			virtual void doStuff() = 0;
		};

		struct ConcreteProductA : Product
		{
			void doStuff();
		};

		struct ConcreteProductB : Product
		{
			void doStuff();
		};

		struct Creator
		{
			virtual Product* createProduct() = 0;
			void SomeOperation();
		};

		struct ConcreteCreatorA : Creator
		{
			Product* createProduct();
		};
		
		struct ConcreteCreatorB : Creator
		{
			Product* createProduct();
		};

		void ExampleOfUse();
	}

	namespace ButtonDialog 
	{
		struct Dialog;

		struct Button
		{
			void OnClick(Dialog* dlg);
			virtual void render() = 0;
		};

		struct WindwosButton : Button
		{
			void render();
		};

		struct WebButton : Button
		{
			void render();
		};

		struct Dialog
		{
			virtual Button* renderButton() = 0;
			void closeDialog();
			void render();
		};

		struct WindowsDialog : Dialog
		{
			Button* renderButton();
		};

		struct WebDialog : Dialog
		{
			Button* renderButton();
		};

		void ExampleOfUse();
	}
}

namespace AbstractFactory
{
	//TODO
	//https://refactoring.guru/uk/design-patterns/abstract-factory
}