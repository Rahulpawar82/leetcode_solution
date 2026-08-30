class Solution {
public:
    string defangIPaddr(string address) {
        int index;
        string ans;

        for(index=0;index<address.size();index++)
        {
            if(address[index]=='.')
            {
                ans = ans + "[.]";
            }
            else 
            {
                ans = ans + address[index];
            }
        }
        return ans;
    }
};