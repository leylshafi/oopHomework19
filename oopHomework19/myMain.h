#pragma once
class myMain
{
public:
	static void Start()
	{
		Database database;
		database.admins.push_back(Admin(1, "leylshafi", "leyla123"));
		database.admins.push_back(Admin(2, "nigarshafi", "nigar123"));

		int a;
		Product p = Product("Cola", 3.5, "red");
		Product p2 = Product("Fanta", 3.5, "yellow");
		database.productItem.push_back(ProductItem(15, &p));
		database.productItem.push_back(ProductItem(30, &p2));
		cout << "Welcome to E-Commerce Shop!!!" << endl;
		while (true)
		{
			cout << "Enter 1 for Customer, 2 for Admin" << endl;
			cin >> a;
			if (a == 1)
			{
				string name, surname, dateOfBirth;
				int id;
				cout << "Enter your id, name, surname, date of birth: " << endl;
				cin >> id >> name >> surname >> dateOfBirth;
				Customer customer(id, name, surname, dateOfBirth);
				database.customers.push_back(customer);
				cout << endl;

				for (size_t i = 0; i < database.productItem.size(); i++)
				{
					cout << "Id: " << database.productItem[i].getId() << endl;
					cout << "Name: " << database.productItem[i].getProduct().getName() << endl;
				}
				cout << "Do you want to see details: y/n" << endl;
				char chs;
				cin >> chs;
				if (chs == 'y')
				{
					for (size_t i = 0; i < database.productItem.size(); i++)
					{
						cout << database.productItem[i] << endl;
					}
				}
				else cout << "okay" << endl;

				cout << "Do you want to buy? " << endl;
				cin >> chs;
				if (chs == 'y')
				{
					cout << "Enter the id of what you wanna buy: " << endl;
					int buyId;
					cin >> buyId;
					cout << "How much you want it?: " << endl;
					int amount;
					cin >> amount;

					for (size_t i = 0; i < database.productItem.size(); i++)
					{
						if (buyId == database.productItem[i].getId()) {
							database.productItem[i].quantity -= amount;
							cout << "You bought!!" << endl;
						}
					}
				}
				else cout << "okay" << endl;


			}
			else if (a == 2)
			{


				int choose;
				string username;
				cout << "Enter username: " << endl;
				cin >> username;
				string Password;
				cout << "Enter password: ";
				cin >> Password;


				for (size_t i = 0; i < database.admins.size(); i++)
				{
					if (database.admins[i].getUsername() == username && database.admins[i].getPassword() == Password) {
						cout << "\nEnter 1 for show all products, 2 for add product, 3 for update" << endl;

						cin >> choose;
						switch (choose)
						{
						case 1:
							database.Read();
							break;
						case 2:
							database.Create();
							break;
						case 3:
							database.Update();
							break;
						default:
							break;
						}
					}
				}

			}
		}
	}
};