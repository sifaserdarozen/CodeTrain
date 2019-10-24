#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

#include <iostream>

/** @brief function checks if string is permutation of another
 * 
 *  With using an utility container
 *  time: O(N), memory: O(1)
 *  
 *  @param first string to process
 *  @param second string to proces
 *  @retun boolean to indicate if straing is permutation of other
 */
bool checkPermutation(const std::string& strA, const std::string& strB)
{
	if (strA.size() != strB.size()) {
		return false;
	}
		
	const size_t numberOfChars = std::pow(2, sizeof(char)*8);
	std::vector<int> charCount(numberOfChars, 0);
	
    for (const auto& s: strA) {
		charCount[s]++; 
	}
	
	for (const auto& s: strB) {
		charCount[s]--;
    }
	
    for (const auto& n: charCount) {
	    if (0 != n) {
			return false;
		}	
	}
	
	return true;
}

/** @brief function checks if string is composed of unique chars
 * 
 *  With using sorting and without extra container
 *  time: O(Nlog(N)), memory: O(1)
 *  
 *  @param first string to process
 *  @param second string to proces
 *  @retun boolean to indicate if straing is permutation of other
 */
bool checkPermutationWithoutContainer(std::string strA, std::string strB)
{
	if (strA.size() != strB.size()) {
		return false;
	}
	
    std::sort(strA.begin(), strA.end());
    std::sort(strB.begin(), strB.end());
	
	auto aIt = strA.begin();
	auto bIt = strB.begin();
	
	while (strA.end() != aIt) {
		if (*aIt++ != *bIt++) {
			return false;
	    }	
	}
			
	return true;    
}

