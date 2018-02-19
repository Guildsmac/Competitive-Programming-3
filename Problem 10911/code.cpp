#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<double> vd;

double getDistance(ii d1, ii d2);
void printPair(ii p);
double getSmaller(vd v);

int main(){
    int n;
    double ans=0;
    vii house;
    vb used;
    cin >> n;
    for(int i=0; i<n*2; i++){
        ii coord;
        cin >> coord.first >> coord.second;
        house.push_back(coord);
        used.push_back(false);
    }
    for(vii::iterator i = house.begin(); i != house.end(); i++){
        ii actCoord = *i;
        vd coords;
        int actOuterPos = distance(house.begin(), i);
        if(used.at(actOuterPos))
            continue;

        for(vii::iterator i2 = house.begin(); i2 != house.end(); i2++){
            if(i!=i2){
                ii tempCoord = *i2;
                coords.push_back(getDistance(actCoord, tempCoord));
            }
        }
        double smallerDistance = getSmaller(coords);
        for(vii::iterator i2 = house.begin(); i2 != house.end(); i2++){
            if(i!=i2){
                ii tempCoord = *i2;
                int actInnerPos = distance(house.begin(), i2);
                if(getDistance(actCoord, tempCoord)==smallerDistance && !used.at(actInnerPos)){
                    ans+=smallerDistance;
                    cout << "Distancia: " << smallerDistance << endl;
                    used.at(actOuterPos) = true;
                    used.at(actInnerPos) = true;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

void printPair(ii p){
    cout << "(" << p.first << ", " << p.second << ")";
}

double getDistance(ii d1, ii d2){
    return sqrt(pow((double)d1.first - (double)d2.first, 2) + pow((double)d1.second - (double)d2.second, 2));
}

double getSmaller(vd v){
    double smaller = INT_MAX;
    for(vd::iterator i = v.begin(); i!=v.end(); i++){
        if(*i < smaller)
            smaller = *i;

    }
    return smaller;
}
