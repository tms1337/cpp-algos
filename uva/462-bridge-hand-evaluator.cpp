#include <iomanip>
#include <iostream>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <typeinfo>
#include <utility>

#include <algorithm>

#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

#define ll long long
#define ld long double

#define ii pair<int, int>

#define vi vector<int>
#define vd vector<double>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define vii vector<pair<int, int>>
#define vll vector<long long>

#define seb set<bool>
#define sei set<int>
#define seii set<pair<int, int>>
#define sell set<long long>

#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>
#define vvii vector<vector<pair<int, int>>>

#define mii map<int, int>
#define mid map<int, double>
#define mci map<char, int>
#define mic map<int, char>
#define msi map<string, int>
#define msvs map<string, vector<string>>
#define mcvc map<char, vector<char>>

#define stll stack<long long>

bool DEBUG = 0;
#define debug if (DEBUG)

#define forn(karna, n) for (int karna = 0; karna < n; karna++)
#define ignore cin.ignore(1000, '\n')

void print_hand(const mcvc &hand) {
  for (auto it = hand.begin(); it != hand.end(); it++) {
    cout << it->first << " --->" << endl;
    for (auto card = it->second.begin(); card != it->second.end(); card++) {
      cout << "\t" << *card << endl;
    }
    cout << endl;
  }
}

bool is_any(const vc &cards, const char &desired_card, const int &sz) {
  if (cards.size() != sz) {
    return false;
  } else {
    for (auto &card : cards) {
      if (card == desired_card) {
        return true;
      }
    }

    return false;
  }
}

int cnt_not_card(vc &cards, const char &card) {
  return count_if(cards.begin(), cards.end(), [card](const char &current_card) {
    return current_card != card;
  });
}

int cnt_card(vc &cards, const char &card) {
  return count_if(cards.begin(), cards.end(), [card](const char &current_card) {
    return current_card == card;
  });
}

int calculate_points(mcvc &hand_suite, mcvc &hand_card,
                     bool use_last_rules = true) {
  int points = 0;

  // rule 1
  int aces = 4 * hand_card['A'].size();
  debug cout << "Adding " << aces << " points for " << hand_card['A'].size()
             << " As" << endl;
  points += aces;

  int kings = 3 * hand_card['K'].size();
  debug cout << "Adding " << kings << " points for " << hand_card['K'].size()
             << " Ks" << endl;
  points += kings;

  int queens = 2 * hand_card['Q'].size();
  debug cout << "Adding " << queens << " points for " << hand_card['Q'].size()
             << " Qs" << endl;
  points += queens;

  int jacks = 1 * hand_card['J'].size();
  debug cout << "Adding " << jacks << " points for " << hand_card['J'].size()
             << " Js" << endl;
  points += jacks;

  // rule 2
  for (auto it = hand_suite.begin(); it != hand_suite.end(); it++) {
    if (cnt_card(it->second, 'K') == 1 && cnt_not_card(it->second, 'K') == 0) {
      debug cout << "Subtracting 1 point for K as only card in " << it->first
                 << endl;
      points -= 1;
    }
  }

  // rule 3
  for (auto it = hand_suite.begin(); it != hand_suite.end(); it++) {
    if (cnt_card(it->second, 'Q') == 1 && cnt_not_card(it->second, 'Q') <= 1) {
      debug cout << "Subtracting 1 point for Q as [0, 1] card in " << it->first
                 << endl;
      points -= 1;
    }
  }

  // rule 4
  for (auto it = hand_suite.begin(); it != hand_suite.end(); it++) {
    if (cnt_card(it->second, 'J') == 1 && cnt_not_card(it->second, 'J') <= 2) {
      debug cout << "Subtracting 1 point for J as [0, 1, 2] card in "
                 << it->first << endl;
      points -= 1;
    }
  }

  if (use_last_rules) {
    // rule 5
    for (auto it = hand_suite.begin(); it != hand_suite.end(); it++) {
      if (it->second.size() == 2) {
        debug cout << "Adding 1 point for " << it->first
                   << " containing 2 cards" << endl;
        points += 1;
      }
    }

    // rule 6
    for (auto it = hand_suite.begin(); it != hand_suite.end(); it++) {
      if (it->second.size() == 1) {
        debug cout << "Adding 2 points for " << it->first
                   << " containing 1 card" << endl;
        points += 2;
      }
    }

    // rule 7
    for (auto it = hand_suite.begin(); it != hand_suite.end(); it++) {
      if (it->second.size() == 0) {
        debug cout << "Adding 2 points for " << it->first
                   << " containing 0 cards" << endl;
        points += 2;
      }
    }
  }

  debug cout << string(50, '-') << endl;

  return points;
}

bool is_suite_stopped(vc &cards) {
  for (auto &card : cards) {
    if (card == 'A') {
      return true;
    } else if (card == 'K' && cnt_not_card(cards, 'K') >= 1) {
      return true;
    } else if (card == 'Q' && cnt_not_card(cards, 'Q') >= 2) {
      return true;
    }
  }

  return false;
}

bool are_all_suits_stopped(mcvc &hand_suite) {
  for (auto it = hand_suite.begin(); it != hand_suite.end(); it++) {
    if (!is_suite_stopped(it->second)) {
      return false;
    }
  }

  return true;
}

void evaluate_hand(const int &points, const int &no_trump_points,
                   mcvc &hand_suite) {
  if (points < 14) {
    printf("PASS\n");
  } else if (no_trump_points >= 16 && are_all_suits_stopped(hand_suite)) {
    cout << "BID NO-TRUMP" << endl;
  } else {
    using pair_type = remove_reference<decltype(hand_suite)>::type::value_type;

    mci priorities = {{'S', 4}, {'H', 3}, {'D', 2}, {'C', 1}};

    auto max_suite =
        max_element(
            begin(hand_suite), end(hand_suite),
            [priorities](const pair_type &p1, const pair_type &p2) -> bool {
              if (p1.second.size() == p2.second.size()) {
                return priorities.at(p1.first) < priorities.at(p2.first);
              } else {
                return p1.second.size() < p2.second.size();
              }
            })
            ->first;

    debug cout << "Suite sizes: " << endl;
    for (auto &suite : hand_suite) {
      debug cout << "\t" << suite.first << " has " << suite.second.size()
                 << " cards" << endl;
    }

    cout << "BID " << max_suite << endl;
  }
}

int main(int argc, char *argv[]) {
  if (argc >= 2) {
    DEBUG = 0;
  }

  bool should_break = false;

  while (true) {
    mcvc hand_suite = {{'S', {}}, {'H', {}}, {'C', {}}, {'D', {}}};

    mcvc hand_card = {
        {'A', {}}, {'2', {}}, {'3', {}}, {'4', {}}, {'5', {}},
        {'6', {}}, {'7', {}}, {'8', {}}, {'9', {}}, {'T', {}},
        {'J', {}}, {'Q', {}}, {'K', {}},
    };

    forn(i, 13) {
      char suite, card;

      if (scanf("%c%c ", &card, &suite) != 2) {
        should_break = true;
        break;
      }

      hand_suite[suite].push_back(card);
      hand_card[card].push_back(suite);
    }

    if (should_break) {
      break;
    }

    debug print_hand(hand_suite);
    debug cout << string(100, '=') << endl;
    debug print_hand(hand_card);

    int points = calculate_points(hand_suite, hand_card);
    int no_trump_points = calculate_points(hand_suite, hand_card, false);
    debug cout << "points: " << points
               << ", no_trump_points: " << no_trump_points << endl;
    evaluate_hand(points, no_trump_points, hand_suite);
  }

  return 0;
}