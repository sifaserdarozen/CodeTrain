// Compute complexity = O(N)
// Space complexity = O(1)

class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        // cant do much with empty container
        if (enemyEnergies.empty()) {
            return 0;
        }


        const auto minIt = min_element(enemyEnergies.begin(), enemyEnergies.end());

        if (currentEnergy < *minIt) {
            return 0;
        }

        currentEnergy -= *minIt;
        long long int totalEnergy = currentEnergy;
        long long points = 1;

        // get all energies except the smallest item
        for (auto it = enemyEnergies.begin(); it != enemyEnergies.end(); ++it) {
            if (it != minIt) {
                totalEnergy += *it;
            } 
        }

        // see how much more points we can get with this total energy
        points += totalEnergy / *minIt;

        return points;
    }
};