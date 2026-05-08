#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string name;

    cout << "Enter your name: ";
    getline(cin,name);  

    if (name.empty()) {
    cout << "Error: Name cannot be empty!" << endl;
    return 0;
    }

    else{
    srand(time(0)); 
    vector<string> roasts = {
       "Your code doesn’t have bugs… it has full ecosystems."
      "Even your compiler gives up on you."
       "{name} debug like he's playing hide and seek with logic… and losing."
       "Your code runs… away from responsibility."
        "You put the ‘why’ in runtime error."
         "Even Stack Overflow can't save you now.

    };


    int index = rand() % roasts.size();
    string roast = roasts[index];


    size_t pos = roast.find("{name}");

    while (pos != string::npos) {
        roast.replace(pos, 6, name);
        pos = roast.find("{name}");
    }

    cout << "\n Roast:\n" << roast << endl;

    return 0;
}
    }
