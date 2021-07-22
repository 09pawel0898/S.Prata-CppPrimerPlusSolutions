#include "ex16_6.h"

#include <queue>

static const int MIN_PER_HR = 60;


static bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}

void ex6(void)
{
    using std::ios_base;

    // przygotowanie symulacji


    cout << "Enter the maximum lenght of the queue: ";
    int qs;
    cin >> qs;
    std::queue<Customer> line;            // w kolejce mo�e stan�� do qs klient�w

    cout << "Enter the simulated time(in hours) : ";
    int hours;                 // liczba godzin symulacji
    cin >> hours;
    // symulacja z jednominutow� rozdzielczo�ci�
    long cyclelimit = MIN_PER_HR * hours;       // liczba cykli

    cout << "Enter the average number of clients per hour: ";
    double perhour;            // �rednia liczba nowych klient�w na godzin�
    cin >> perhour;
    double min_per_cust;       // �redni odst�p czasowy pomi�dzy klientami
    min_per_cust = MIN_PER_HR / perhour;

    Customer temp;                 // dane nowego klienta
    long turnaways = 0;        // liczba klient�w odes�anych z kolejki
    long customers = 0;        // liczba klient�w przyj�tych do kolejki
    long served = 0;           // liczba klient�w obs�u�onych w symulacji
    long sum_line = 0;         // ��czna liczba oczekuj�cych
    int wait_time = 0;         // czas do zwolnienia bankomatu
    long line_wait = 0;        // ��czny czas oczekiwania

    // rozpocz�cie symulacji
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))  // mamy nowego ch�tnego
        {
            if (line.size() == qs)
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);        // czas przybycia = nr cyklu
                line.push(temp);     // do��czenie klienta do kolejki
            }
        }
        if (wait_time <= 0 && !line.empty())
        {
            temp = line.front();
            line.pop();
            wait_time = temp.ptime();   // czas obs�ugi = wait_time
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.size();
    }

    // zestawienie wynik�w
    if (customers > 0)
    {
        cout << "number of clients accepted : " << customers << endl;
        cout << "number of customers served: " << served << endl;
        cout << "number of customers returned : " << turnaways << endl;
        cout << "average queue length: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.setf(ios_base::showpoint);
        cout << (double)sum_line / cyclelimit << endl;
        cout << "average waiting time : "
            << (double)line_wait / served << " minutes\n";
    }
    else
        cout << "No clients!\n";

    cout << "Ready!\n";

    exit(0);
}
