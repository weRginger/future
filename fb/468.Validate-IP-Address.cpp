// Time O(n)
// Space O(1)
class Solution {
public:
    string validIPAddress(string IP) {
        if(count(IP.begin(),IP.end(),'.')==3) {
            // in case of 0.0.0., getline will stop on the last .
            // so we have to check manually
            if(IP[IP.size()-1]=='.') return "Neither"; 
            string token;
            stringstream s(IP); //convert the given string into stream for using getline function;
            while(getline(s,token,'.')) {
                if(token.length()==0 || token.length()>3) return "Neither";
                if(token[0]=='0' && token.length()!=1) return "Neither";
                for(char ch : token) if(!isdigit(ch)) return "Neither";
                if(stoi(token)>255) return "Neither";
            }
            return "IPv4";
        }
        else if(count(IP.begin(),IP.end(),':')==7) {
            if(IP[IP.size()-1]==':') return "Neither"; // same as above
            string token;
            stringstream s(IP);
            while(getline(s,token,':')) {
                if(token.length()==0 || token.length()>4) return "Neither";
                for(char ch : token) if(!isxdigit(ch)) return "Neither";
            }
            return "IPv6";
        }
        return "Neither";
    }
};
