#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int timeToMin(int t) {
    int h = t / 100;
    int m = t % 100;
    return h * 60 + m;
}

struct Reservation {
    int id;
    int start;
    int end;
    int seatIdx;
};

bool cmp(const Reservation& a, const Reservation& b) {
    if (a.start != b.start) {
        return a.start < b.start;
    }
    return (a.end - a.start) < (b.end - b.start);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T, P;
    cin >> N >> T >> P;

    vector<Reservation> reservs(T);
    for (int i = 0; i < T; ++i) {
        int s, e;
        cin >> s >> e;
        reservs[i].id = i;
        reservs[i].start = timeToMin(s);
        reservs[i].end = timeToMin(e);
        reservs[i].seatIdx = -1;
    }

    sort(reservs.begin(), reservs.end(), cmp);

    for (int i = 0; i < T; ++i) {
        int currentStart = reservs[i].start;
        
        vector<int> occupiedSeats;
        for (int j = 0; j < i; ++j) {
            if (reservs[j].end > currentStart) {
                occupiedSeats.push_back(reservs[j].seatIdx);
            }
        }

        int bestSeat = -1;

        if (occupiedSeats.empty()) {
            bestSeat = 1;
        } else {
            int maxDist = -1;
            
            for (int seat = 1; seat <= N; ++seat) {
                bool isOccupied = false;
                for (int occ : occupiedSeats) {
                    if (occ == seat) {
                        isOccupied = true;
                        break;
                    }
                }
                if (isOccupied) continue;

                int minDist = 2000000000;
                for (int occ : occupiedSeats) {
                    int dist = abs(seat - occ);
                    if (dist < minDist) {
                        minDist = dist;
                    }
                }

                if (minDist > maxDist) {
                    maxDist = minDist;
                    bestSeat = seat;
                }
            }
        }
        reservs[i].seatIdx = bestSeat;
    }
    
    int startOp = timeToMin(900);
    int endOp = timeToMin(2100);
    vector<bool> pOccupied(2000, false);

    for (int i = 0; i < T; ++i) {
        if (reservs[i].seatIdx == P) {
            for (int t = reservs[i].start; t < reservs[i].end; ++t) {
                pOccupied[t] = true;
            }
        }
    }

    int mingyuTime = 0;
    for (int t = startOp; t < endOp; ++t) {
        if (!pOccupied[t]) {
            mingyuTime++;
        }
    }

    cout << mingyuTime << endl;

    return 0;
}