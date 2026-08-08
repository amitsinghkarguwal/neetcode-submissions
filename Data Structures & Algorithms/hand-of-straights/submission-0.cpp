#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        //Hand size must be a multiple of groupSize
        if (hand.size() % groupSize != 0) {
            return false;
        }

        // 2. std::map automatically keeps the keys (cards) strictly sorted
        map<int, int> card_counts;

        for (int card : hand) {
            card_counts[card]++;
        }

        // 3. Iterate map
        for (auto const& [card, count] : card_counts) {
            // If we have instances of this card left, we MUST start a straight here
            if (card_counts[card] > 0) {
                // We need to form this many groups starting with 'card'
                int num_groups_to_make = card_counts[card];
                
                // Try to build the consecutive sequence
                for (int i = 0; i < groupSize; i++) {
                    int needed_card = card + i;
                    
                    // If we don't have enough of the consecutive card, we fail
                    if (card_counts[needed_card] < num_groups_to_make) {
                        return false;
                    }
                    
                    // Consume the cards used in this straight
                    card_counts[needed_card] -= num_groups_to_make;
                }
            }
        }

        // If we made it through the whole map without failing, we win!
        return true;
    }
};