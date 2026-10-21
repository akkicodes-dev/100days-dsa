class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiantQ, direQ;
        int postion = 0;

        for (; postion < senate.size(); postion++) {
            char senator = senate[postion];
            if (senator == 'R')
                radiantQ.push(postion);
            if (senator == 'D')
                direQ.push(postion);
        }

        while (!radiantQ.empty() && !direQ.empty()) {
            int rFront = radiantQ.front();
            radiantQ.pop();

            int dFront = direQ.front();
            direQ.pop();

            //yaha  hum  simulation kr rahe hai
            //simulation voting
            if (rFront < dFront) {
                //means R will ban D
                radiantQ.push(postion++);
            } else {
                //means d will ban  r
                direQ.push(postion++);
            }
        }

        if (!radiantQ.empty()) return "Radiant"; 
        return "Dire"; 
    }
};