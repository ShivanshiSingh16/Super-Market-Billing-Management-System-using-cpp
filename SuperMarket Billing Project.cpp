a        data.close();
        data1.close();

        remove("C:\\Users\\Shantanu Sengar\\Documents\\DATABASEOFPRODUCTS.txt");
        rename("C:\\Users\\Shantanu Sengar\\Documents\\DATABASEOFPRODUCTS1.txt", "C:\\Users\\Shantanu Sengar\\Documents\\DATABASEOFPRODUCTS.txt");

        if (token == 0)
        {
            cout << "\n\nRecord not found";
        }
    }
}

void shopping::delpro()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\t\t\t Delete the record :";
    cout << "\n\t\t\t Product Code :";
    cin >> pkey;

    data.open("C:\\Users\\Shantanu Sengar\\Documents\\DATABASEOFPRODUCTS.txt", ios::in); //check if file exists or not
    if (!data)
    {
        cout << "\nFile does not exist";
    }
    else
    {
        data1.open("C:\\Users\\Shantanu Sengar\\Documents\\DATABASEOFPRODUCTS1.txt", ios::app | ios::out); //open new file
        data >> pcode >> pname >> price >> discount;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\t\t Product Deleted Successfully ! ";
                // in first iteration if pkey matches if block will execute
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
            }
            data >> pcode >> pname >> price >> discount;
        }
        data.close();
        data1.close();
        remove("C:\\Users\\Shantanu Sengar\\Documents\\DATABASEOFPRODUCTS.txt");
        rename("C:\\Users\\Shantanu Sengar\\Documents\\DATABASEOFPRODUCTS1.txt", "C:\\Users\\Shantanu Sengar\\Documents\\DATABASEOFPRODUCTS.txt");
        if (token == 0)
        {
            cout << "\n\nRecord not found";
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("DATABASEOFPRODUCTS.txt", ios::in);
    cout << "\n\n_______________________________________________\n";
    cout << "Product No \t\t Name \t\t Price \n";
    cout << "\n\n_______________________________________________\n";
    data >> pcode >> pname >> price >> discount;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> discount;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;
    int procode[100];
    int qty[100];
    char ch;
    int count = 0;
    float amount = 0, dis = 0, total = 0;
    cout << "\n\t\t\t\t RECEIPT";
    data.open("C:\\Users\\Shantanu Sengar\\Documents\\DATABASEOFPRODUCTS.txt", ios::in);
    if (!data)
    {
        cout << "\n\n FILE DOES NOT EXISTS ";
    }
    else
    {
        data.close();
        list();

        cout << "\n\n________________________________________________\n";
        cout << "\n\n                                                \n";
        cout << "\n\n             PLEASE PLACE YOUR ORDER            \n";
        cout << "\n\n                                                \n";
        cout << "\n\n________________________________________________\n";

        do
        {
            m:
            cout << "\n Enter the product code :";
            cin >> procode[count];
            cout << "\n Enter the product Quantity: ";
            cin >> qty[count];

            for (int i = 0; i < count; i++)
            {
                if (procode[count] == procode[i])
                {
                    cout << "Duplicate Product Code , Please try again !\n";
                    goto m;
                }
            }
            count++;
            cout << "\n\n Do you want to buy more products ? If Yes , press y else n";
            cin >> ch;
        } while (ch == 'y');
        cout << "\n\t\t\t_______________________RECEIPT________________________\n";
        cout << "\nProduct no \t\t Product Quantity \t\t Price \t\t Amount \t\t Amount With Discount \n";

        for (int i = 0; i < count; i++)
        {
            data.open("C:\\Users\\Shantanu Sengar\\Documents\\DATABASEOFPRODUCTS.txt", ios::in);
            data >> pcode >> pname >> price >> discount;

            while (!data.eof())
            {
                if (pcode == procode[i])
                {
                    amount = price * qty[i];
                    dis = amount - (amount * discount / 100);
                    total = total + dis;

                    cout << "\n" << pcode << "\t\t\t" << qty[i] << "\t\t\t" << pname << "\t\t\t" << price << "\t\t\t" << amount << "\t\t\t" << dis;
                }
                data >> pcode >> pname >> price >> discount;
            }
            data.close();
        }
    }
    cout << "\n\n__________________________________________________________________";
    cout << "\n Total Amount :" << total;
}

int main()
{
    shopping s;
    s.menu();
}
