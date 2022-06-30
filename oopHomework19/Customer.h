#pragma once
namespace myCustomer
{
	class Customer {
		int id;
		string name;
		string surname;
		string dateOfBirth;
	public:

		Customer(int id, string name, string surname, string dateOfBirth)
			:id(id), name(name), surname(surname), dateOfBirth(dateOfBirth) {}

		int getId()const { return id; }
		string getName()const { return name; }
		string getSurname()const { return surname; }
		string getDateOfBirth()const { return dateOfBirth; }


	};

}