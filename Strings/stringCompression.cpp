#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int index = 0;  //index will assign both: character and count!!
        int i = 0;

        while(i < n){
            char curr_char = chars[i];
            int count = 0;

            //finding the count for current character
            while(i < n && chars[i] == curr_char){
                count++;
                i++;
            }

            // Assigning current character in input string
            chars[index] = curr_char;
            index++;

            //assigning count!!
            if(count > 1){
                string count_str = to_string(count);

                for(int ch : count_str){
                    chars[index] = ch;
                    index++;
                }

            }
        }
        return index;
    }
};