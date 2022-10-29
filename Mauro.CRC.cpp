#include <bits/stdc++.h>
using namespace std; 

class CRC { 
    public: 
    int fralen, genlen, frame[20], generator[20], temp[20], b; 
    char a;
    int* divide(int n, int g, int temp[10], int generator[10]) { 
        for (int i = 0; i < n; ++i) { 
            if (generator[0] == temp[i]) { 
                for (int j = 0, k = i; j < g + 1; ++j, ++k) { 
                    if (temp[k]^generator[j] == 1) {
                        temp[k] = 1; 
                    } else {
                        temp[k] = 0; 
                    }
                } 
            } 
        } 
    return temp; 
    }     
    
    void input() { 
        /* Get Frame */
        cout<<"Enter Frame Length: "; 
        cin>>fralen; 
        cout<<"Enter Frame: "; 
        for (int i = 0; i < fralen; ++i) { 
            cin>>frame[i]; 
            temp[i] = frame[i];     
        } 
        /* Get Generator */
        cout<<"Enter Generator Length: "; 
		cin>>genlen; 
        cout<<"Enter Generator: "; 
        for(int i = 0; i < genlen; ++i) { 
            cin>>generator[i]; 
        } 
        --genlen; 
        for(int i = 0; i < genlen; ++i) { 
            temp[fralen+i]=0; 
        } 
    } 
    
    void sender_side() { 
        int* sender; 
        sender = divide(fralen, genlen, temp, generator);
        cout<<endl<<"-----------SENDER'S SIDE-----------\n"<<"Cyclic Redundancy Check (CRC): "; 
        for(int i = 0; i < genlen; ++i) { 
            frame[fralen+i] = sender[fralen+i]; 
            cout<<sender[fralen+i]<<' '; 
        } 
        cout<<endl<<"Transmitted Frame: "; 
        for(int i = 0; i < fralen + genlen; ++i) 
        cout<<frame[i]<<' '; 
        cout<<endl; 
    }
	 
    int receiver_side() { 
        int* receiver; 
        cout<<"\n---------RECEIVER'S SIDE-----------\n"<<"Received Message: "; 
        for(int i = 0; i < fralen + genlen; ++i) 
        cout<<frame[i]<<' '; 
        cout<<endl; 
        cout<<"\nEnter Which Bit You Want To Change(from 0-"<<fralen+genlen<<"): ";
        cin>>b; 
        if (frame[b] == 1) {
            frame[b] = 0; 
        } else {
            frame[b] = 1; 
       	}
        receiver = divide(fralen, genlen, frame, generator); 
        cout<<"Error: "; 
        for(int i = 0; i < fralen + genlen; ++i) { 
            if(receiver[i] != 0) { 
                cout<<"Error Detected!!!"<<endl; 
                return 0; 
            } 
        } 
        cout<<"No Error Detected!"<<endl; 
    } 
}; 

int main() { 
    CRC o;
    o.input(); 
    o.sender_side(); 
    o.receiver_side(); 
    return 0; 
} 
