class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {

    }

    int ping(int t) {
        // q.push(t);

        // while (!q.empty() && q.front() < t - 3000) {
        //     q.pop();
        // }

        // return q.size();


        //1.
        q.push(t);

        //2. pop invalid req. older, older than t -3000
        while(!q.empty() && q.front() < (t - 3000)){
            q.pop();
        }

        //3. now q has only no of recent calls : R= [t - 3000, t]
        return q.size();
    }
};