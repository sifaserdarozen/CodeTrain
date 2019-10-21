#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

/** @brief function checks if string is composed of unique chars
 * 
 *  With using an utility container
 *  time: O(N), memory: O(1)
 *  
 *  @param string to process
 *  @retun boolean to indicate if straing is composed of unique chars
 */
bool isUnique(const std::string& str)
{
	std::vector<bool> isUsedBefore(std::pow(2, sizeof(char)*8), false);
	
    for (const auto& s: str) {
		if (true == isUsedBefore[s]) {
			return false;
		} else {
			isUsedBefore[s] = true;
	    }
	}
	
	return true;
}

/** @brief function checks if string is composed of unique chars
 * 
 *  With using sorting and without extra container
 *  time: O(Nlog(N)), memory: O(1)
 *  
 *  @param string to process
 *  @retun boolean to indicate if straing is composed of unique chars
 */
bool isUniqueWithoutContainer(std::string str)
{
	const auto size = str.size();
	if ( size < 2 ) {
	    return true;	
	}
	
    std::sort(str.begin(), str.end());
	
	auto backIt = str.begin();
	auto currIt = backIt;
	currIt++;
	
	while (currIt != str.end()) {
		if (*currIt == *backIt) {
			return false;
	    }
	    currIt++;
	    backIt++;
	}
	
	return true;
}

