// Essa solução está quebrada. Caso alguém queira tentar encontrar o bug,
// sinta-se à vontade.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

const int POINTS_PER_WIN = 3;
const int POINTS_PER_DRAW = 1;
const int POINTS_PER_LOSS = 0;

struct TeamStats {
    std::string team_name;
    int points = 0;
    int games_played = 0;
    int goals_scored = 0;
    int goals_conceded = 0;

    int goal_balance(){
        return goals_scored - goals_conceded;
    }

    double point_percentage(){
        return (double) points / (games_played * POINTS_PER_WIN) * 100;
    }
};

std::vector<std::string> readTeamNames(int t){
    std::vector<std::string> team_names;
    for (int i = 0; i < t; i++){
        std::string s;
        std::cin >> s;
        team_names.push_back(s);
    }
    return team_names;
}

bool strLessThanCaseInsensitive(const std::string &a, const std::string &b){
    for (auto a_it = a.begin(), b_it = b.begin();
         a_it != a.end() and b_it != b.end();
         a_it++, b_it++){
        const char upper_a = std::toupper(*a_it);
        const char upper_b = std::toupper(*b_it);
        if (upper_a != upper_b){
            return upper_a < upper_b;
        }
    }
    return a.size() < b.size();
}

bool scoreDescending(const TeamStats &a, const TeamStats &b){
    if (a.points == b.points){
        return strLessThanCaseInsensitive(a.team_name, b.team_name);
    }
    return a.points > b.points;
}

std::vector<TeamStats> parseScores(int g, std::vector<std::string> team_names){
    std::vector<TeamStats> stats;
    std::map<std::string, decltype(stats.size())> name_to_stats_pos;

    decltype(stats.size()) pos = 0;
    for (std::string s : team_names){
        stats.push_back((TeamStats){team_name: s});
        name_to_stats_pos[s] = pos;
        pos++;
    }

    for (int i = 0; i < g; i++){
        std::string team1, team2;
        int goals1, goals2;
        std::cin >> team1 >> goals1;
        std::cin.ignore(3);
        std::cin >> goals2 >> team2;

        auto &stats1 = stats[name_to_stats_pos[team1]];
        auto &stats2 = stats[name_to_stats_pos[team2]];

        if (goals1 > goals2){
            stats1.points += POINTS_PER_WIN;
            stats2.points += POINTS_PER_LOSS;
        } else if (goals2 > goals1){
            stats1.points += POINTS_PER_LOSS;
            stats2.points += POINTS_PER_WIN;
        } else {
            stats1.points += POINTS_PER_DRAW;
            stats2.points += POINTS_PER_DRAW;
        }

        stats1.games_played++;
        stats2.games_played++;

        stats1.goals_scored += goals1;
        stats2.goals_scored += goals2;

        stats1.goals_conceded += goals2;
        stats2.goals_conceded += goals1;
    }

    return stats;
}

void printSortedStats(std::vector<TeamStats> team_stats){
    int prev_points = -1;
    // I don't need to initialize these with invalid values because they'll be
    // set at the first iteration, when the prev_points check inevitably fails.
    int prev_goals_scored; 
    int prev_goal_balance;
    decltype(team_stats.size()) pos = 1;
    for (auto stats : team_stats){
        if (prev_points == stats.points &&
            prev_goals_scored == stats.goals_scored &&
            prev_goal_balance == stats.goal_balance()){
            // Tied with previous team, no position should be printed
            std::cout << "    ";
        } else {
            prev_points = stats.points;
            prev_goals_scored = stats.goals_scored;
            prev_goal_balance = stats.goal_balance();
            std::cout << std::setw(2) << std::right << pos << ". ";
        }

        std::cout << std::setw(15) << std::right << stats.team_name << " "
            << std::setw(3) << std::right << stats.points << " "
            << std::setw(3) << std::right << stats.games_played << " "
            << std::setw(3) << std::right << stats.goals_scored << " "
            << std::setw(3) << std::right << stats.goals_conceded << " "
            << std::setw(3) << std::right << stats.goal_balance() << " ";

        std::cout << std::setw(6) << std::right;

        auto percentage = stats.point_percentage();
        if (!std::isnan(percentage)){
            std::cout << std::fixed << std::setprecision(2) << percentage;
        } else {
            std::cout << "N/A";
        }
        std::cout << '\n';

        pos++;
    }
}

int main(){
    bool first_entry = true;
    while (true){
        int t, g;
        std::cin >> t >> g;
        if (t == 0 && g == 0){
            break;
        }

        if (!first_entry){
            std::cout << '\n';
        }

        auto team_names = readTeamNames(t);
        auto team_stats = parseScores(g, team_names);

        std::stable_sort(team_stats.begin(), team_stats.end(), scoreDescending);

        printSortedStats(team_stats);

        first_entry = false;
    }
    return 0;
}
