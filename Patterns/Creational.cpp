#include "Creational.h"

#include <iostream>

using namespace std;

/*!
	Example from refactoring guru

	full documentation see here: https://refactoring.guru/uk/design-patterns/factory-method
*/

namespace FabricMethod
{
	namespace ProductCreator 
	{

		
		void ConcreteProductA::doStuff()
		{
			cout << "Doing stuff of Product A." << endl;
		}

		void ConcreteProductB::doStuff()
		{
			cout << "Doing stuff of Product B." << endl;
		}


		void Creator::SomeOperation()
		{
			auto concreteProduct = createProduct();
			concreteProduct->doStuff();
			delete concreteProduct;
		}

		Product* ConcreteCreatorA::createProduct()
		{
			return (Product*)new ConcreteProductA();
		}

		Product* ConcreteCreatorB::createProduct()
		{
			return (Product*)new ConcreteProductB();
		}
		

		void ExampleOfUse()
		{
			Creator* creator = (Creator*)new ConcreteCreatorA;
			creator->SomeOperation();
			//TODO what if exceptions was thrown?
			delete creator;

			creator = (Creator*)new ConcreteCreatorB;
			creator->SomeOperation();
			//TODO what if exceptions was thrown?
			delete creator;
		}
	}


	namespace ButtonDialog 
	{

		void Button::OnClick(Dialog * dlg)
		{
			cout << "Button clicked." << endl;

			//TODO
			//How to pass member as function pointer??
			dlg->closeDialog();
		}

		void Button::render()
		{
			cout << "Windows button render." << endl;
		}

		void WebButton::render()
		{
			cout << "Web button render." << endl;
		}

		void WindwosButton::render()
		{
			cout << "Web button render." << endl;
		}


		void Dialog::closeDialog()
		{
			cout << "Dialog closed." << endl;
		}

		void Dialog::render()
		{
			cout << "Dialog render." << endl;
			auto button = renderButton();
			button->OnClick(this);
			button->render();
			delete button;
		}

		Button* WindowsDialog::renderButton()
		{
			return (Button*)new WindwosButton;
		}

		Button* WebDialog::renderButton()
		{
			return (Button*)new WebButton;
		}
	
		void ExampleOfUse()
		{

			Dialog* dialog;

			if (true)
				dialog = (Dialog*)new WindowsDialog;
			else if (false)
				dialog = (Dialog*)new WebDialog;
			else
				throw;
			
			dialog->render();

			//TODO what if exceptions was thrown by render() function?
			delete dialog;
		};
	}
}