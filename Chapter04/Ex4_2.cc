#include <map>
#include <string>
#include <iostream>
#include <algorithm>

int main(int argc, char* argv[])
{
    using namespace std;

    map<string, unsigned long> telephone_numbers ={
        {"john", 7123812},
        {"tom", 929821111},
        {"jerry", 82111111},
        {"beker", 2338834665},
    };

    for (auto it = telephone_numbers.begin(); it != telephone_numbers.end(); ++it)
        cout << it->first << " : " << it->second << endl;

    string key{""};
    cout << "Enter the name: ";
    cin >> key;
    auto iter = telephone_numbers.find(key);
    if (iter == telephone_numbers.end())
        cout << key << " is a non-existing name." << endl;
    else
        cout << key << "'s telephone number is " << iter->second << endl;

    return 0;
}
