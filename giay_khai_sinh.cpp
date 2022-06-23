#include<bits/stdc++.h>
using namespace std;
int X;
typedef struct BoCon{
    string bo, con;
    int lech;
}boCon;
bool cmp(pair<string,int> &a, pair<string,int> &b){
    if(a.second != b.second) return a.second > b.second;
    return !a.first.compare(b.first);
}
map<string, string> mapParents;
map<string, int> mapAge;
map<string, int > doLech;
boCon a[100];
int find(string name){
    int l = doLech[name];
    int s = mapAge[mapParents[name]];
    if(s != -1){
        return s - l;
    }
    else {
        mapAge[mapParents[name]] = find(mapParents[name]);
        return mapAge[mapParents[name]] - l;
    }
}
void giaPha(int T){
    cout<<"DATASET "<<T<<endl;
    for(int i = 0 ; i < X; i++){
        if(mapAge.find(a[i].bo) != mapAge.end() && mapAge[a[i].bo] != -1){
            mapAge[a[i].con] = mapAge[a[i].bo] - a[i].lech;
        }
        else if(mapAge.find(a[i].con) != mapAge.end() && mapAge[a[i].con] != -1){
            mapAge[a[i].bo] = mapAge[a[i].con] + a[i].lech;
        }
        else{
            mapAge[a[i].bo] = -1;
            mapAge[a[i].con] = -1;
            mapParents[a[i].con] = a[i].bo;
            doLech[a[i].con] = a[i].lech;
        }
    }
    map<string, int> :: iterator it;
    vector<pair<string , int> > b;
    for(it = mapAge.begin(); it != mapAge.end(); ++it){
        b.push_back((*it));
    }

    for(int i = 0 ; i < b.size(); i++){
        if(b[i].second == -1 ){
            int s = find(b[i].first);
            mapAge[b[i].first] = s;
            b[i].second = s;
        }
    }    
    sort(b.begin(), b.end(), cmp);
    for(int i = 1 ; i < b.size(); i++){
        cout<<b[i].first<<" "<<b[i].second<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    int T = 1;
    while (t--)
    { 
        cin>>X;
        mapParents.clear();
        mapAge.clear();
        doLech.clear();
        mapAge["Ted"] = 100;
        for(int i = 0 ; i < X; i++){
            cin>>a[i].bo>>a[i].con>>a[i].lech;    
        }
        giaPha(T);
        T++;
    }
    

    return 0;
}