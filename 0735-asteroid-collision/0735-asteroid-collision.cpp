class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for (auto ast : asteroids) {

            bool destroy = false;   // initially current asteroid survive kar raha hai

            // CASE 1:
            // Positive asteroid hai -> directly stack me push
            if (ast > 0) {
                st.push(ast);
            }

            else {
                // Current asteroid negative hai

                // CASE 2:
                // Stack empty hai
                // Ya stack ka top bhi negative hai
                // Dono same direction me ja rahe hain -> collision nahi
                if (st.empty() || st.top() < 0) {
                    st.push(ast);
                }

                else {

                    // CASE 3:
                    // Stack ka top positive hai
                    // Current negative hai
                    // => + and - collision possible
                    while (!st.empty() && st.top() > 0) {

                        // CASE 3A:
                        // Same size -> dono destroy
                        if (abs(ast) == st.top()) {

                            st.pop();
                            destroy = true;  // current asteroid bhi destroy
                            break;
                        }

                        // CASE 3B:
                        // Current negative asteroid bada hai
                        // Example: 10 and -15
                        // 10 destroy hoga
                        else if (abs(ast) > st.top()) {

                            st.pop();

                            // IMPORTANT:
                            // Current asteroid abhi survive kar raha hai,
                            // lekin next positive asteroid se bhi collision
                            // ho sakta hai.
                            // Isliye yahan push nahi karenge.
                        }

                        // CASE 3C:
                        // Stack ka positive asteroid bada hai
                        // Example: 15 and -10
                        // -10 destroy hoga
                        else {

                            destroy = true;
                            break;
                        }
                    }

                    // Agar current asteroid kisi collision me destroy nahi hua
                    // to stack me push karo
                    if (!destroy) {
                        st.push(ast);
                    }
                }
            }
        }

        // Stack ko vector me convert karo
        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // Stack se elements reverse order me milte hain
        reverse(ans.begin(), ans.end());

        return ans;
    }
};