class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()){
            return "";
        }
        unordered_map<char,int>need;//freq of chars req
        for(char c : t){
            need[c]++;
        }
        unordered_map<char,int>window;//freq of availabale string
        int left=0;
        int min_len=INT_MAX;
        int start=0;
        int have=0;
        int needCount=need.size();
        for(int right=0;right<s.size();right++){
            window[s[right]]++;
            if(window[s[right]]==need[s[right]] && need.find(s[right])!=need.end()){
                have++;
            }
            while(have == needCount){
                int windowlength=right-left+1;
                 if(windowlength<min_len){
                    min_len=windowlength;
                    start=left;
                }
                window[s[left]]--;
                if (need.count(s[left]) && window[s[left]] < need[s[left]]) {
                have--;
                }
                left++;
            }
        }
         if(min_len == INT_MAX){
                    return "";
                }
        return s.substr(start,min_len);
    }
};
