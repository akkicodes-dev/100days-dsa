string orderCopy;

class Solution {
public:
    static bool cmp(const char &ch1, const char &ch2){
        // main sort karna chatha hu as per the order string 
        // if ch1 is present before ch2 in order string,
        // then place ch1 before ch2 in string s
        // and vice versa 
        return(orderCopy.find(ch1) < orderCopy.find(ch2));
    }

    string customSortString(string order, string s) {
        orderCopy = order;
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};
