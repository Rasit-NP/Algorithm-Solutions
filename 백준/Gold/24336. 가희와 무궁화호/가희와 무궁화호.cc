# include <iostream>
# include <unordered_map>
# include <string>
# include <algorithm>
using namespace std;

unordered_map<string, long double> dist = {
    { "Seoul", 0.0 },
    { "Yeongdeungpo", 9.1 },
    { "Anyang", 23.9 },
    { "Suwon", 41.5 },
    { "Osan", 56.5 },
    { "Seojeongri", 66.5 },
    { "Pyeongtaek", 75.0 },
    { "Seonghwan", 84.4 },
    { "Cheonan", 96.6 },
    { "Sojeongni", 107.4 },
    { "Jeonui", 114.9 },
    { "Jochiwon", 129.3 },
    { "Bugang", 139.8 },
    { "Sintanjin", 151.9 },
    { "Daejeon", 166.3 },
    { "Okcheon", 182.5 },
    { "Iwon", 190.8 },
    { "Jitan", 196.4 },
    { "Simcheon", 200.8 },
    { "Gakgye", 204.6 },
    { "Yeongdong", 211.6 },
    { "Hwanggan", 226.2 },
    { "Chupungnyeong", 234.7 },
    { "Gimcheon", 253.8 },
    { "Gumi", 276.7 },
    { "Sagok", 281.3 },
    { "Yangmok", 289.5 },
    { "Waegwan", 296.0 },
    { "Sindong", 305.9 },
    { "Daegu", 323.1 },
    { "Dongdaegu", 326.3 },
    { "Gyeongsan", 338.6 },
    { "Namseonghyeon", 353.1 },
    { "Cheongdo", 361.8 },
    { "Sangdong", 372.2 },
    { "Miryang", 381.6 },
    { "Samnangjin", 394.1 },
    { "Wondong", 403.2 },
    { "Mulgeum", 412.4 },
    { "Hwamyeong", 421.8 },
    { "Gupo", 425.2 },
    { "Sasang", 430.3 },
    { "Busan", 441.7 }
};

int trans(string time){
    return stoi(time.substr(0, 2))*60 + stoi(time.substr(3, 2));
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    unordered_map<string, int> start_time;
    unordered_map<string, int> end_time;
    string name, time;
    for (int i=0; i<n; i++){
        cin >> name;
        cin >> time;
        if (time.substr(0,1) != "-"){
            end_time[name] = trans(time);
        }
        cin >> time;
        if (time.substr(0,1) != "-"){
            start_time[name] = trans(time);
        }
    }
    string name1, name2;
    long double ans;
    for (int i=0; i<q; i++){
        ans = 0;
        cin >> name1 >> name2;
        ans = dist[name2] - dist[name1];
        if (ans < 0)    ans = -ans;
        int diff = (end_time[name2]-start_time[name1]);
        if (end_time[name2] < start_time[name1])
            diff += 24*60;
        ans /= diff;
        cout << fixed;
        cout.precision(8);
        cout << ans*60 << '\n';
    }
}