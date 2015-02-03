//
//  main.cpp
//  StringFromPhone
//
//  Created by Vinod Gupta on 2/3/15.
//  Copyright (c) 2015 Vinod Gupta. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <sstream>
using namespace std;

class StringFromPhone
{
public:
    StringFromPhone()
    {
        _ph_map['2'] = "abc";
        _ph_map['3'] = "def";
        _ph_map['4'] = "ghi";
        _ph_map['5'] = "jkl";
        _ph_map['6'] = "mno";
        _ph_map['7'] = "pqrs";
        _ph_map['8'] = "tuv";
        _ph_map['9'] = "wxyz";
        _ph_map['0'] = "+";
    }
    virtual ~StringFromPhone()
    {
        
    }
    
    void getPossibleString2(string ph_number,vector<string> &possible_words)
    {
        for(string::iterator itr=ph_number.begin();itr != ph_number.end();++itr)
        {
            const char c=*itr;
            string &possible =_ph_map[c];
            
            bool empty_list =possible_words.empty();
            vector<string> current =possible_words;
            possible_words.erase(possible_words.begin(),possible_words.end());
            

            for(string::iterator itr2=possible.begin();itr2!=possible.end();++itr2)
            {
                const char new_char = *itr2;
                
                if(empty_list)
                {
                    stringstream ss;
                    string s;
                    ss << new_char;
                    ss >> s;
                    possible_words.push_back(s);
                    continue;
                }
                
                for(vector<string>::iterator itr3 = current.begin(); itr3 != current.end();++itr3)
                {
                    stringstream ss;
                    ss <<*itr3;
                    ss <<new_char;
                    string new_word;
                    ss>> new_word;
                    possible_words.push_back(new_word);
                }
                
            }
        }
    }
   

private:
    typedef map<int,string> PhNumberMap;
    PhNumberMap _ph_map;
    
};


int main(int argc, const char * argv[]) {
    
    StringFromPhone str_from_ph;
    vector<string> possible;
    str_from_ph.getPossibleString2("65",possible);
    
    for(vector<string>::iterator itr = possible.begin(); itr !=  possible.end(); ++itr)
    {
        cout<<*itr<<endl;
    }
    return 0;
}
