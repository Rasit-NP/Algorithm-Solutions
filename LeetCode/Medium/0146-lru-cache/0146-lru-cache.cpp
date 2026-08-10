# include <queue>
# include <unordered_map>
using namespace std;
typedef pair<int, int> pii;

class LRUCache {
private:
    int order = 0;
    int size = 0;
    int capacity;
    queue<pii> orders;
    unordered_map<int, pii> table;
public:
    LRUCache(int capacity): capacity(capacity){}
    
    int get(int key) {
        if (table.find(key) == table.end())
            return -1;
        orders.push({key, order});
        table[key].second = order++;

        return table[key].first;
    }
    
    void put(int key, int value) {
        if (table.find(key) == table.end()){
            if (size == capacity){
                while (true){
                    const auto [k, o] = orders.front();  orders.pop();
                    if (table[k].second == o){
                        table.erase(k);
                        --size;
                        break;
                    }
                }
            }
            ++size;
        }
        orders.push({key, order});
        table[key] = {value, order++};
    }
};