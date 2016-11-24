#include <vector>
#include <iostream>
#include <algorithm>

/** @struct Player
 *
 *  Primitive data structure to keep information of player name and score
 */
struct Player {
    std::string name;    //!< player name
    int score;    //!< player score
}; 

/** @fn Compare
 *
 *  Function perfroming comparison operation, that returns true
 *  if p1 has higher score or, same score with alphebetically smaller name
 *
 *  @param p1 first player
 *  @param p2 second player
 *  @return boolean indiating whether p1 should be placed first or not
 *  @see Player
 */
bool Compare(const Player& p1, const Player& p2)
{
    if ((p1.score > p2.score) || ((p1.score == p2.score) && (p1.name < p2.name)))
        return true;
    else
        return false;
};

/** @fn comparator
 *
 *  Function sorting players, first to score then to name
 *  For vector of [{"amy", 100}, {"david", 100}, {"heraldo", 50}, {"aakansha", 75}, {"aleksa", 150}]
 *  Output should be [{"aleksa", 150}, {"amy", 100}, {"david", 100}, {"aakansha", 75}, {"heraldo", 50}]
 *  Time complexity is nlogn
 *
 *  @param players input vector of players
 *  @return outputvector of sorted players
 *  @see Player
 *  @see Compare
 */
std::vector<Player> comparator(std::vector<Player> players) {
    std::vector<Player> compared_players = players;
    std::sort(compared_players.begin(), compared_players.end(), Compare);
    return compared_players;
}

int main() {
    
    int n;
    std::cin >> n;
    std::vector< Player > players;
    std::string name;
    int score;
    for(int i = 0; i < n; i++){
        std::cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    std::vector<Player > answer = comparator(players);
    for(unsigned int i = 0; i < answer.size(); i++) {
        std::cout << answer[i].name << " " << answer[i].score << std::endl;
    }
    return 0;
}
