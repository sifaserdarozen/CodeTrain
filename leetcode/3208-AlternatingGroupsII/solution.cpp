// Compute Complexity = O(N)
// Space Complexity = O(N)

int normalize(int idx, int N) {
    return (idx + N) % N; 
}

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // find alternating segments starts
        // a segment start is a point where previous item has the same color with him
        vector<int> segmentStarts;
        const int N = colors.size();
        for (int i = 0; i < N; ++i) {
            if (colors[normalize(i-1, N)] != colors[i]) {
                // means i is not a sequence start point
                continue;
            }
            segmentStarts.push_back(i);
        }

        // if there is no segment start, it means that we have a big sement of size N
        // treat it specially
        if (segmentStarts.empty()) {
            return N;
        }

        auto alternatingSegments = 0;
        for (const auto& idx : segmentStarts) {
            int segmentLength = 1;
            for (auto i = idx + 1; i < (idx + N); ++i) {
                if (colors[normalize(i, N)] == colors[normalize(i-1, N)]) {
                    break;
                }
                segmentLength++;
            }

            if (segmentLength >= k) {
                alternatingSegments += max((segmentLength - k + 1),0);
            }

            std::cout << idx << " " << segmentLength << " " << alternatingSegments << std::endl;
        }
        return alternatingSegments;
    }
};