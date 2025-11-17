# include <iostream>
# include <string>
# include <vector>
# include <queue>
using namespace std;

struct Score {
    int id;
    int solved = 0;
    int total = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> logs;
    Score* front = nullptr;
    Score* back = nullptr;
};

int swap(Score* my_node){
    Score* before = my_node->front->front;
    Score* my_back = my_node->back;
    Score* my_head = my_node->front;
    before->back = my_node;
    my_node->back = my_head;
    my_node->front = before;
    my_head->front = my_node;
    my_head->back = my_back;
    my_back->front = my_head;
    return 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    int n, m, i, log_cnt=0;
    cin >> n >> m;
    vector<Score*> rank(n+1);
    vector<int> pass(n+1);
    for (i=1; i<=n; i++){
        rank[i] = new Score();
        rank[i]->id = i;
    }
    Score head;
    Score tail;
    head.back = &tail;
    tail.front = &head;
    for (i=0; i<m; i++){
        string times;
        int id, p, s;
        cin >> times >> id >> p >> s;
        int hh = stoi(times.substr(0, 2));
        int mm = stoi(times.substr(3, 2));
        int time = hh*60 + mm;
        int bad = time + (s-1) * 20;
        if (time>180){
            rank[id]->logs.push({p, bad});
            log_cnt += 1;
            continue;
        }
        Score* my_node = rank[id];
        Score* node = &head;
        if (my_node->solved == 0){
            while (node->back != &tail)
                node = node->back;
            node->back = my_node;
            tail.front = my_node;
            my_node->front = node;
            my_node->back = &tail;
        }
        my_node->solved++;
        my_node->total += bad;
        while (my_node->front != &head && (my_node->solved > my_node->front->solved || (my_node->solved == my_node->front->solved && my_node->total < my_node->front->total))){
            swap(my_node);
        }
    }
    while (log_cnt>0){
        Score* my_node = tail.front;
        while (!my_node->logs.size()){
            my_node = my_node->front;
        }
        int pid = my_node->logs.top().first;
        int newbad = my_node->logs.top().second;
        my_node->logs.pop();
        my_node->solved++;
        my_node->total += newbad;
        while (my_node->front != &head && (my_node->solved > my_node->front->solved || (my_node->solved == my_node->front->solved && my_node->total < my_node->front->total))){
            swap(my_node);
            pass[my_node->id]++;
        }
        log_cnt--;
    }

    int maximum = 0, idx;
    Score* check = tail.front;
    while (check != &head){
        if (pass[check->id] >= maximum){
            maximum = pass[check->id];
            idx = check->id;
        }
        check = check->front;
    }
    for (i=1; i<=n; i++){
        delete rank[i];
    }
    cout << idx << '\n';
}
