# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
using namespace std;

struct User{
    int level;
    string nickname;

    User(int l, string n){
        level = l;
        nickname = n;
    }

    bool operator<(User user){
        if (this->nickname < user.nickname)
            return true;
        else
            return false; 
    }
};

struct Room{
    inline static int full_count = 0;
    int now_count;
    int base_level;
    vector<User> members;
    string state;

    Room(User user){
        state = "Waiting!";
        now_count = 0;
        base_level = user.level;
        entrance(user);
    }

    void entrance(User user){
        members.push_back(user);
        now_count++;

        if (now_count == full_count){
            state = "Started!";
        }
    }

    void print(){
        sort(members.begin(), members.end());
        cout << state << '\n';
        for (User member : members){
            cout << member.level << ' ' << member.nickname << '\n';
        }
    }

    bool new_member(){
        if (now_count < full_count){
            return true;
        }
        else
            return false;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int p, m;   cin >> p >> m;
    Room::full_count = m;
    vector<Room> rooms;
    while (p--){
        int l;
        string n;
        bool joined = false;
        cin >> l >> n;

        User user(l, n);

        for (Room &room : rooms){
            if (l <= room.base_level+10 && l >= room.base_level-10 && room.new_member()){
                room.entrance(user);
                joined = true;
                break;
            }
        }
        if (!joined){
            Room room(user);
            rooms.push_back(room);
        }
    }

    for (Room room : rooms){
        room.print();
    }
}