#include <iostream>
using namespace std;

struct employee
{
    string name;
    int age;
    int salary;
    char gender;
};


int main()
{
    employee employees[100];
    int cnt_employees = 0;

    while (true)
    {
        cout << "Enter your choice:" << endl;
        cout << "1) Add new employee" << endl;
        cout << "2) Print all employees" << endl;
        cout << "3) Delete an employee by age" << endl;
        cout << "4) Update salary by name" << endl;

        char choice;
        cin >> choice;

        if (choice == '1')
        {
            cout << "Enter name: "; 
            cin >> employees[cnt_employees].name;

            cout << "Enter age: ";
            cin >> employees[cnt_employees].age;

            cout << "Enter salary: ";
            cin >> employees[cnt_employees].salary;

            cout << "Enter gender: ";
            cin >> employees[cnt_employees].gender;

            cnt_employees++;
        }

        if (choice == '2')
        {
            if (cnt_employees == 0)
            {
                cout << "There are no employees";
                break;
            }

            for (int i = 0; i < cnt_employees; i++)
            {
                cout << employees[i].name << " " << employees[i].age << " " << employees[i].gender << " " << employees[i].salary << endl;
            }
        }

        if (choice == '3')
        {
            // Start and end of an enterval, if an employee's age is included in this enterval he will be deleted. 
            int start, end;
            cout << "Enter start and end of the enterval: " << endl;
            cin >> start >> end;

            for (int x = 0; x < cnt_employees; x++)
            {
                if (start <= employees[x].age && employees[x].age <= end)
                {
                    cout << employees[x].name << " has been deleted" << endl;

                    for (int z = x; z < (cnt_employees - 1); z++)
                    {
                        employees[z] = employees[z + 1];
                    }

                    cnt_employees--;
                    x--;
                }
            }
        }

        if (choice == '4')
        {
            string name;
            cout << "Enter name: ";
            cin >> name;

            int new_salary;
            cout << "Enter new salary: ";
            cin >> new_salary;

            for (int y = 0; y < cnt_employees; y++)
            {
                if (name == employees[y].name)
                {
                    cout << employees[y].name << "'s salary has been updated to " << new_salary << endl;
                    employees[y].salary = new_salary;
                    break;
                }
            }
        }
    }

    return 0;
}
