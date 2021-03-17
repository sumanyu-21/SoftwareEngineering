# include <iostream>
# include <bits/stdc++.h>
using namespace std;

class Machine
{
    public:
    int day;
    int price;
    int resale;
    int moneyPerDay;

    Machine()
    {
        this->day = 0;
        this->price = 0;
        this->resale = 0;
        this->moneyPerDay = 0;
    }
    void read()
    {
        cin>>day >> price >> resale >> moneyPerDay;
    }
};

class Sol
{
    public:
    int start;
    int moneyPerDay;
    long prevMoney;

    Sol()
    {
        start = 0;
        moneyPerDay = 0;
        prevMoney = 0;
    }

    Sol(int start, int moneyPerDay, long prevMoney)
    {
        this->start = start;
        this->moneyPerDay = moneyPerDay;
        this->prevMoney = prevMoney;
    }

    long moneyEarned(int day)
    {
        long delta = day-start; // We can't start making money on the day we buy the machine.
        return moneyPerDay*delta + prevMoney;

    }
};

int main()
{
    int N;
    cin>>N;
    if(N==0)
        return false;
    int C, D;
    cin>>C>>D;
    vector<Machine>machines(N);
    for(Machine &m: machines) // This & is important, otherwise a new object will be created and changes will not be done in this object.
        m.read();

    sort(machines.begin(), machines.end(), [&](const Machine &a, const Machine &b){
        return a.day<b.day;
    });
    

    vector<Sol>bag;
    long maxMoney = C;
    for(Machine m:machines)
    {
        // First we need to sell the previous machine.
        for(Sol s:bag)
            maxMoney = max(maxMoney, s.moneyEarned(m.day-1)); 
        
        if(m.price > maxMoney)// Machine is not worth buying even if machines are used optimally upto this day.
            continue;
        Sol partial(m.day, m.moneyPerDay, maxMoney-m.price + m.resale); // We can add the resale value right away.
        bag.push_back(partial);
    }
    
    for(Sol s:bag)
        maxMoney = max(maxMoney, s.moneyEarned(D));
    
    cout<<maxMoney<<endl;
    return 0;
}