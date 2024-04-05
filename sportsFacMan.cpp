#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Facility{

    private:
    string name;
    int capacity;
    vector<bool> slotStatus;
    vector<int> slot;

    public:
    Facility(string name,int capacity){
        this->name=name;
        this->capacity=capacity;
        slotStatus.resize(capacity);
        slot.resize(capacity); 
    }

    Facility():name(""),capacity(0){

    }

    Facility(const Facility &temp){
        this->name=temp.name;
        this->capacity=temp.capacity;
        this->slot=temp.slot;
        this->slotStatus=temp.slotStatus;
    }

    void bookSlot(int rollNo){
        int i=1;
        for (;i<=capacity;i++)
        {
            if(!slotStatus[i-1])
            {
                slotStatus[i-1]=true;
                slot[i-1]=rollNo;
                cout << "Slot " << i << " booked for " << name << " by " << rollNo << endl; 
                return;
            }
        }
        
        cout << "No slots available" << endl;
    }

    void cancelSlot(int rollNo){
        for (int j=1;j<=capacity;j++)
        {
            if(slot[j-1]==rollNo)
            {
                slotStatus[j-1]=false;
                slot[j-1]=0;
                cout << "Slot " << j << " cancelled successfully" << endl;
                return;
            }
        }
        cout << "No bookings done by this Roll Number" << endl;
    }

    void checkAvailability(){
        vector<int> availableSlot;
        for (int j=1;j<=capacity;j++)
        {
            if (!slotStatus[j-1])
            {
                availableSlot.push_back(j);
            }
        }
        if(!availableSlot.empty())
        {
            cout << "Available Slots in " << name << " are ";
            for(int k=0;k<availableSlot.size();k++)
            {
                cout << availableSlot[k] << " ";
            }
            cout << endl;
        }
        else{
            cout << "No available slots" << endl;
        }
    }

    void displaySlotStatus(){
        cout << "Slot status of " << name << " :" << endl;
        for(int j=0;j<capacity;j++)
        {
            if(slotStatus[j])
            {
                cout << "Slot " << j+1 << " is booked by " << slot[j] << endl;
            }
            else
            {
                cout << "Slot " << j+1 << " is free" << endl;
            }
        }
        cout << endl;
    }

};

class Facilities {
private:
    map<string,Facility> facilities;

public:
    void addFacility(string name, int capacity) {
        facilities.emplace(name, Facility(name, capacity));
        cout << name << " added successfully with capacity " << capacity << endl;
    }

    void BookSlot(string name, int rollNumber) {
        if (facilities.find(name) != facilities.end()) {
            facilities[name].bookSlot(rollNumber);
        } else {
            cout << "Facility " << name << " not found" << endl;
        }
    }

    void CancelSlot(string name, int rollNumber) {
        if (facilities.find(name) != facilities.end()) {
            facilities[name].cancelSlot(rollNumber);
        } else {
            cout << "Facility " << name << " not found" << endl;
        }
    }

    void CheckAvailability(string name) {
        if (facilities.find(name) != facilities.end()) {
            facilities[name].checkAvailability();
        } else {
            cout << "Facility " << name << " not found" << endl;
        }
    }

    void DisplaySlotStatus(string name) {
        if (facilities.find(name) != facilities.end()) {
            facilities[name].displaySlotStatus();
        } else {
            cout << "Facility " << name << " not found" << endl;
        }
    }
};


int main()
{
    Facilities facilities;
    int option;
    do{
        cout<<"1->Adding Facility"<<endl<<"2->Booking Slot"<<endl<<"3->Cancelling Slot"<<endl;
        cout<<"4->Check Availability"<<endl<<"5->Display Slot Status"<<endl<<"0->Exit"<<endl;
        cout<<"Enter Your Option=> ";
        cin >> option;
        switch(option){
            case 1:{
                string name;int capacity;
                cout << "Enter Facility Name=> ";
                cin >> name;
                cout << endl;
                cout << "Enter Capacity of Facility=> ";
                cin >> capacity;
                cout << endl;
                facilities.addFacility(name,capacity);
                break;
            }
            case 2:{
                string name;int rollNo;
                cout << "Enter Facility Name=> ";
                cin >> name;
                cout << endl;
                cout << "Enter Your Roll Number=> ";
                cin >> rollNo;
                cout << endl;
                facilities.BookSlot(name,rollNo);
                break;
            }
            case 3:{
                string name;int rollNo;
                cout << "Enter Facility Name=> ";
                cin >> name;
                cout << endl;
                cout << "Enter Your Roll Number=> ";
                cin >> rollNo;
                cout << endl;
                facilities.CancelSlot(name,rollNo);
                break;
            }
            case 4:{
                string name;
                cout << "Enter Facility Name=> ";
                cin >> name;
                cout << endl;
                facilities.CheckAvailability(name);
                break;
            }
            case 5:{
                string name;
                cout << "Enter Facility Name=> ";
                cin >> name;
                cout << endl;
                facilities.DisplaySlotStatus(name);
                break;
            }
            case 0:{
                cout << "Exiting Program" << endl;
                break;
            }
            default:{
                cout << "Enter Given Options Only"<< endl;
                break;
            }
        }
    }while(option!=0);
};