#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Hero{
private:
    int matchesplayed;
    int wins;
    int bans;
    string id;
    string name;
    string spells[2];
    string items[3];
    string position;
    double ratePlayed;
    double rateWins;
    double rateBans;
    map<string, int> totalItems;
    map<string, int> totalSpells;
    map<string, int> totalPositions;
    
    void addToMap(map<string, int> &map, string data){
        if(map.find(data) != map.end()){
            map[data] = map[data] + 1;
        }
        else{
            map[data] = 1;
        }
    }
public:
    Hero(string name, string id){
        this->name = name;
        this->id = id;
        matchesplayed = 0;
        wins = 0;
        bans = 0;
    }
    Hero(){}
    string getName(){return name;}
    string getId(){return id;}
    string getPosition(){return position;}
    double getRatePlayed(){
        ratePlayed = ((double)matchesplayed / 184070.0) * 100.0;
        return ratePlayed;
    }
    double getRateWins(){
        rateWins = ((double)wins / (double)matchesplayed) * 100.0;
        return rateWins;
    }
    double getRateBans(){
        rateBans = ((double)bans / (double)matchesplayed) * 100.0;
        return rateBans;
    }
    void setTotalSpells(string spell_1, string spell_2){
        addToMap(totalSpells, spell_1);
        addToMap(totalSpells, spell_2);
        if(spells[0].empty()){
            spells[0] = spell_1;
            spells[1] = spell_2;
        }
    }
    void setTotalItems(string item_1, string item_2, string item_3, string item_4, string item_5, string item_6){
        if(!item_1.empty()){
            addToMap(totalItems, item_1);
            if(items[0].empty()){
                items[0] = item_1;
            }
            else if(items[1].empty()){
                items[1] = item_1;
            }
            else if(items[2].empty()){
                items[2] = item_1;
            }
        }
        if(!item_2.empty()){
            addToMap(totalItems, item_2);
            if(items[0].empty()){
                items[0] = item_2;
            }
            else if(items[1].empty()){
                items[1] = item_2;
            }
            else if(items[2].empty()){
                items[2] = item_2;
            }
        }
        if(!item_3.empty()){
            addToMap(totalItems, item_3);
            if(items[0].empty()){
                items[0] = item_3;
            }
            else if(items[1].empty()){
                items[1] = item_3;
            }
            else if(items[2].empty()){
                items[2] = item_3;
            }
        }
        if(!item_4.empty()){
            addToMap(totalItems, item_4);
            if(items[0].empty()){
                items[0] = item_4;
            }
            else if(items[1].empty()){
                items[1] = item_4;
            }
            else if(items[2].empty()){
                items[2] = item_4;
            }
        }
        if(!item_5.empty()){
            addToMap(totalItems, item_5);
            if(items[0].empty()){
                items[0] = item_5;
            }
            else if(items[1].empty()){
                items[1] = item_5;
            }
            else if(items[2].empty()){
                items[2] = item_5;
            }
        }
        if(!item_6.empty()){
            addToMap(totalItems, item_6);
            if(items[0].empty()){
                items[0] = item_6;
            }
            else if(items[1].empty()){
                items[1] = item_6;
            }
            else if(items[2].empty()){
                items[2] = item_6;
            }
        }
    }
    void setTotalPosition(string pos){
        addToMap(totalPositions, pos);
        if(position.empty()){
            position = pos;
        }
        else{
            if(totalPositions[position] < totalPositions[pos]){
                position = pos;
            }
        }
    }
//    void printTotalSpells(){
//        for(auto it = totalSpells.begin(); it != totalSpells.end(); it++){
//            cout << it->first << " " << it->second << endl;
//        }
//    }
//    void printSpells(){
//        cout << name << ": " << spells[0] << " " << spells[1] << endl;
//    }
//    void printItems(){
//        cout << items[0] << " " << items[1] << " " << items[2] << endl;
//    }
//    void printTotalItems(){
//        for(auto it = totalItems.begin(); it != totalItems.end(); it++){
//            cout << it->first << " " << it->second << endl;
//        }
//    }
    void addMatch(){
        matchesplayed += 1;
    }
    void addWin(int w){
        wins += w;
    }
    void addBan(int b){
        bans += b;
    }
    void findMostUsedSpells(){
        for (auto it = totalSpells.begin(); it != totalSpells.end(); it++) {
            if(totalSpells[spells[0]] < it->second && it->first != spells[1]){
                spells[0] = it->first;
            }
            if(totalSpells[spells[1]] < it->second && it->first != spells[0]){
                spells[1] = it->first;
            }
        }
    }
    void findMostUsedItems(){
        for (auto it = totalItems.begin(); it != totalItems.end(); it++) {
            if(totalItems[items[0]] < it->second && it->first != items[1] && it->first != items[2]){
                items[0] = it->first;
            }
            if(totalItems[items[1]] < it->second && it->first != items[0] && it->first != items[2]){
                items[1] = it->first;
            }
            if(totalItems[items[2]] < it->second && it->first != items[0] && it->first != items[1]){
                items[2] = it->first;
            }
        }
    }
};
class Participant{
    string hero_id;
    string spell_1;
    string spell_2;
    string position;
public:
    Participant(){}
    Participant(string id, string sp1, string sp2, string pos){
        hero_id = id;
        spell_1 = sp1;
        spell_2 = sp2;
        position = pos;
    }
    string getHero_id(){return hero_id;}
    string getSpell_1(){return spell_1;}
    string getSpell_2(){return spell_2;}
    string getPosition(){return position;}
};
class Stat{
    int win;
    string item_1;
    string item_2;
    string item_3;
    string item_4;
    string item_5;
    string item_6;
public:
    Stat(){}
    Stat(int win, string i1, string i2, string i3, string i4, string i5, string i6){
        this->win = win;
        item_1 = i1;
        item_2 = i2;
        item_3 = i3;
        item_4 = i4;
        item_5 = i5;
        item_6 = i6;
    }
    int getWin(){return win;}
    string getItem_1(){return item_1;}
    string getItem_2(){return item_2;}
    string getItem_3(){return item_3;}
    string getItem_4(){return item_4;}
    string getItem_5(){return item_5;}
    string getItem_6(){return item_6;}
};
void extractChamps(map <string, Hero> &heroMap, ifstream &file){
    string name;
    string id;
    getline(file, name);
    while(file.good()){
        getline(file, name, ',');
        getline(file, id);
        Hero* tempHero = new Hero(name, id);
        if(!name.empty() && !id.empty()){
            heroMap[id] = *tempHero;
        }
        //delete tempHero;
    }
}
void extractSpells(map <string, string> &spells, ifstream &file){
    string name;
    string id;
    while(file.good()){
        getline(file, id, ',');
        getline(file, name);
        if(!name.empty() && !id.empty()){
            spells[id] = name;
        }
    }
}
void extractItems(map <string, string> &spells, ifstream &file){
    string name;
    string id;
    while(file.good()){
        getline(file, id, ',');
        getline(file, name);
        if(!name.empty() && !id.empty()){
            spells[id] = name;
        }
    }
}
void extractParticipants(vector<Participant> &participants, ifstream &file){
    string hero_id;
    string spell_1;
    string spell_2;
    string role;
    string position;
    string temp;
    
    getline(file, temp);
    while(file.good()){
        getline(file, temp, ',');
        getline(file, temp, ',');
        getline(file, temp, ',');
        getline(file, temp, '"');
        getline(file, hero_id, '"');
        getline(file, temp, '"');
        getline(file, spell_1, '"');
        getline(file, temp, '"');
        getline(file, spell_2, '"');
        getline(file, temp, '"');
        getline(file, role, '"');
        getline(file, temp, '"');
        getline(file, position, '"');
        getline(file, temp);
        
        if(role == "DUO_SUPPORT"){
            position = role;
        }
        
        Participant* tempParticipant = new Participant(hero_id, spell_1, spell_2, position);
        if(!hero_id.empty() && !spell_1.empty() && !spell_2.empty() && !role.empty() && !position.empty()){
            participants.push_back(*tempParticipant);
        }
        //delete tempParticipant;
    }
}
void extractStats(vector<Stat> &stats, ifstream &file){
    string win;
    string item_1;
    string item_2;
    string item_3;
    string item_4;
    string item_5;
    string item_6;
    string temp;
    
    getline(file, temp);
    while (file.good()) {
        getline(file, temp, ',');
        getline(file, temp, '"');
        getline(file, win, '"');
        getline(file, temp, '"');
        getline(file, item_1, '"');
        getline(file, temp, '"');
        getline(file, item_2, '"');
        getline(file, temp, '"');
        getline(file, item_3, '"');
        getline(file, temp, '"');
        getline(file, item_4, '"');
        getline(file, temp, '"');
        getline(file, item_5, '"');
        getline(file, temp, '"');
        getline(file, item_6, '"');
        getline(file, temp);
        
        Stat* tempStat = new Stat(stoi(win), item_1, item_2, item_3, item_4, item_5, item_6);
        if(!win.empty() && !item_1.empty() && !item_2.empty() && !item_3.empty() && !item_6.empty()){
            stats.push_back(*tempStat);
        }
//        delete tempStat;
    }
}
void extractBans(vector<string> &bans, ifstream &file){
    string hero_id;
    string temp;
    
    getline(file, temp);
    while (file.good()) {
        getline(file, temp, ',');
        getline(file, temp, ',');
        getline(file, temp, '"');
        getline(file, hero_id, '"');
        getline(file, temp);
        bans.push_back(hero_id);
    }
}
int main() {
    map <string, Hero> heroMap;
    map <string, string> spells;
    map <string, string> items;
    vector<string> bans;
    vector<Participant> participants;
    vector<Stat> stats;
    
    ifstream fileChamps("champs.csv");
    ifstream fileSpells("spells.csv");
    ifstream fileItems("items.csv");
    ifstream fileParticipants("participants.csv");
    ifstream fileStats1("stats1.csv");
    ifstream fileStats2("stats1.csv");
    ifstream fileBans("teambans.csv");
    
    if (!fileChamps.is_open()) {
        cout << "Unable to open file champs";
        exit(1);
    }
    if (!fileSpells.is_open()) {
        cout << "Unable to open file spells";
        exit(1);
    }
    if (!fileItems.is_open()) {
        cout << "Unable to open file items";
        exit(1);
    }
    if (!fileParticipants.is_open()) {
        cout << "Unable to open file participants";
        exit(1);
    }
    if (!fileStats1.is_open()) {
        cout << "Unable to open file stats1";
        exit(1);
    }
    if (!fileStats2.is_open()) {
        cout << "Unable to open file stats2";
        exit(1);
    }
    if (!fileBans.is_open()) {
        cout << "Unable to open file bans";
        exit(1);
    }
    extractChamps(heroMap, fileChamps);
    extractSpells(spells, fileSpells);
    extractItems(items, fileItems);
    extractParticipants(participants, fileParticipants);
    extractStats(stats, fileStats1);
    extractStats(stats, fileStats2);
    extractBans(bans, fileBans);
    
    for(int i = 0; i < participants.size(); i++){
        string heroID = participants[i].getHero_id();
        string spell_1 = participants[i].getSpell_1();
        string spell_2 = participants[i].getSpell_2();
        string i1 = stats[i].getItem_1();
        string i2 = stats[i].getItem_2();
        string i3 = stats[i].getItem_3();
        string i4 = stats[i].getItem_4();
        string i5 = stats[i].getItem_5();
        string i6 = stats[i].getItem_6();
        string position = participants[i].getPosition();
        heroMap[heroID].addMatch();
        heroMap[heroID].setTotalSpells(spells[spell_1], spells[spell_2]);
        heroMap[heroID].setTotalPosition(position);
        heroMap[heroID].setTotalItems(items[i1], items[i2], items[i3], items[i4], items[i5], items[i6]);
    }
    for(auto it = heroMap.begin(); it != heroMap.end(); it++){
        heroMap[it->first].findMostUsedSpells();
        heroMap[it->first].findMostUsedItems();
    }
//                              TEST
//    for(auto it = heroMap.begin(); it != heroMap.end(); it++){
//        cout << it->first << " " << it->second.getId() << " " << it->second.getName() << endl;
//    }
//    for(auto it = spells.begin(); it != spells.end(); it++){
//        cout << it->first << " " << it->second << endl;
//    }
//    for(auto it = items.begin(); it != items.end(); it++){
//        cout << it->first << " " << it->second << endl;
//    }
//    for(int i = 0; i < participants.size(); i++){
//        cout << participants[i].getHero_id() << " " << participants[i].getSpell_1() <<
//        participants[i].getSpell_2() << " " << participants[i].getPosition() << endl;
//    }
//    for(int i = 0; i < bans.size(); i++){
//        cout << bans[i] << endl;
//    }
    return 0;
}
