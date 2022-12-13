#include<iostream>
#include<queue>
using namespace std;

class Counter{
    public:
    string c_Num, c_Type;
    string date, t_num;

    Counter(){};
    Counter(string x, string y, string z, string zx){
        c_Num = x;
        c_Type = y;
        date = z;
        t_num = zx;
    }
    void p_C_details(){
       cout<<"Car number: "<<c_Num<<endl;
       cout<<"Car type: "<<c_Type<<endl;
       cout<<"Date: "<<date<<endl;
       cout<<"Ticket number: "<<t_num<<endl;
    }

}; 


class Vehicle{
    public:
    string c_Num, c_Type;

    Vehicle(){};
    Vehicle(string a, string b){
        c_Num = a; 
        c_Type = b;
    }

    string getC_num(){
        return c_Num;
    }
    string getC_type(){
        return c_Type;
    }

    void p_v_Details() {
      cout<<"Car number: "<<c_Num<<endl;
      cout<<"Car type: "<<c_Type<<endl<<endl;
    }
};

int main(){
    int n;
    int h_count = 0, m_count=0, l_count=0;
    cout<<"Enter number of vehicles: ";
    cin>>n;
    Vehicle v[n];
    Counter c1[n], c2[n], c3[n];    

    string c_n, c_t, date, ticket_num;
    string number;

    for(int i=0; i<n; i++){
        cout<<"Enter car Number of car "<<i+1<<": ";
        cin>>c_n;
        cout<<"Enter car type of car "<<i+1<<": ";
        cin>>c_t;
        cout<<"\n\n";
        v[i] = Vehicle(c_n, c_t);
    }

    cout<<endl;

    for(int i=0; i<n; i++){
        cout<<"Enter date of toll for car "<<i+1<<": ";
        cin>>date;
        cout<<"Enter ticket num for car "<<i+1<<": ";
        cin>>ticket_num;
        if(v[i].getC_type() == "Heavy-Duty"){
            c1[i] = Counter(v[i].getC_num(), v[i].getC_type(), date, ticket_num);
            h_count++;
        }
        else if(v[i].getC_type() == "Medium-Duty"){
            c2[i] = Counter(v[i].getC_num(), v[i].getC_type(), date, ticket_num);
            m_count++;
        }
        else if(v[i].getC_type() == "Light-Duty"){
            c3[i] = Counter(v[i].getC_num(), v[i].getC_type(), date, ticket_num);
            l_count++;
        }
    }

    queue<Counter> myQueue;

    for(int i=0; i<n; i++){
        if(v[i].getC_type() == "Heavy-Duty"){
            myQueue.push(c1[i]);
        }
        else if(v[i].getC_type() == "Medium-Duty"){
            myQueue.push(c2[i]);
        }
        else if(v[i].getC_type() == "Light-Duty"){
            myQueue.push(c3[i]);
        }

    }

    int ex, count = 0;
    float total_c1, total_c2, total_c3, total;
    do{
        cout<<"Menu\n1. Show all toll information\n2. Show information for a specific car\n3. Total earning in heavy-duty counter\n4. Total earning in medium-duty counter\n5. Total earning in light-duty counter\n6. Total earning of all counters\n7. Exit"<<endl;
    cout<<"Choose an option: ";
    cin>>ex;

    switch (ex)
    {
    case 1: 
        while(!myQueue.empty()){
        myQueue.front().p_C_details();
        myQueue.pop();
        }
    break;


    case 2:
        cout << "Enter car number to search: ";
        cin >> number;
      

        for(int i=0; i<n; i++){
            if(c1[i].c_Num == number){
               cout<<"Toll date: "<<c1[i].date<<endl;
               cout<<"Ticket Number: "<<c1[i].t_num<<endl<<endl;  
               count++;
               break;
            }
            else if(c2[i].c_Num == number){
                cout<<"Toll date: "<<c2[i].date<<endl;
                cout<<"Ticket Number: "<<c2[i].t_num<<endl<<endl;  
                count++;
                break;
            }
            else if(c3[i].c_Num == number){
                cout<<"Toll date: "<<c3[i].date<<endl;
                cout<<"Ticket Number: "<<c3[i].t_num<<endl<<endl;  
                count++;
                break;
            }
        }
      
        if(count==0){
            cout  << "Car info not found\n";}

    break; 

        
    case 3:
        total_c1 = h_count*800;
        cout<<"Total earnings of heavy-duty counter is: "<<total_c1<<endl;
    break;


    case 4:
        total_c2 = m_count*500;
        cout<<"Total earnings of medium-duty counter is: "<<total_c2<<endl;
    break;


    case 5:
        total_c3 = l_count*300;
        cout<<"Total earnings of light-duty counter is: "<<total_c3<<endl;
    break;


    case 6:
        total = h_count*800 + m_count*500 + l_count*300;
        cout<<"Total earnings of all counters is: "<<total<<endl;
    break;

    }}while(ex!=7);
    
    

    return 0;
}
