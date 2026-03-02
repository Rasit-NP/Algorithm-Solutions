# include <iostream>
# include <string>
# include <unordered_map>
using namespace std;

int main(void){
    int n;    cin >> n;
    unordered_map<string, string> my_map{{"Algorithm", "204"}, {"DataAnalysis", "207"}, {"ArtificialIntelligence", "302"},
                                     {"CyberSecurity", "B101"}, {"Network", "303"}, {"Startup", "501"}, {"TestStrategy", "105"}};
    while(n--){
        string word;    cin >> word;
        cout << my_map[word] << endl;
    }
}