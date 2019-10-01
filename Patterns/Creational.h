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
			void doStuff() override;
		};

		struct ConcreteProductB : Product
		{
			void doStuff() override;
		};

		struct Creator
		{
			virtual Product* createProduct() = 0;
			void SomeOperation();
		};

		struct ConcreteCreatorA : Creator
		{
			Product* createProduct() override;
		};
		
		struct ConcreteCreatorB : Creator
		{
			Product* createProduct() override;
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
			void render() override;
		};

		struct WebButton : Button
		{
			void render() override;
		};

		struct Dialog
		{
			virtual Button* renderButton() = 0;
			void closeDialog();
			void render();
		};

		struct WindowsDialog : Dialog
		{
			Button* renderButton() override;
		};

		struct WebDialog : Dialog
		{
			Button* renderButton() override;
		};

		void ExampleOfUse();
	}
}

namespace AbstractFactory
{
	//TODO
	//https://refactoring.guru/uk/design-patterns/abstract-factory
}