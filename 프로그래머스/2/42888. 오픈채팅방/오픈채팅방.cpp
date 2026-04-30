# include <string>
# include <vector>
# include <unordered_map>
using namespace std;

vector<string> message = {{"님이 나갔습니다."}, {"님이 들어왔습니다."}};

vector<string> parse(string& record){
    vector<string> res;
    string local = "";
    
    for (char let : record){
        if (let == ' '){
            res.push_back(local);
            local.clear();
        }
        else {
            local.push_back(let);
        }
    }
    res.push_back(local);
    
    return res;
}

vector<string> solution(vector<string> records) {
    unordered_map<string, string> idToName;
    vector<pair<int, string>> history;
    
    for (string& record : records){
        vector<string> data = parse(record);
        
        string order = data[0];
        string id = data[1];
        if (order == "Enter"){
            string name = data[2];
            idToName[id] = name;
            history.push_back({1, id});
        }
        else if (order == "Leave"){
            history.push_back({0, id});
        }
        else if (order == "Change"){
            string name = data[2];
            idToName[id] = name;
        }
    }
    
    vector<string> ans;
    
    for (pair<int, string>& each : history){
        string name = idToName[each.second];
        
        for (char let : message[each.first]){
            name.push_back(let);
        }
        
        ans.push_back(name);
    }
    
    return ans;
}