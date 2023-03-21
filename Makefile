CXX=g++ -g

all: isSubsequence middleNode detectCycle maxProfit longestPalindrome naryTreePreOrder sortRepeatingNumbers mergeTwoLists romanToInt reverseList numberPalindrome isomorphic

isSubsequence:
	$(CXX) isSubsequence.cpp -o isSubsequence -lgtest

middleNode:
	$(CXX) middleNode.cpp -o middleNode -lgtest

detectCycle:
	$(CXX) detectCycle.cpp -o detectCycle -lgtest

maxProfit:
	$(CXX) maxProfit.cpp -o maxProfit -lgtest

longestPalindrome:
	$(CXX) longestPalindrome.cpp -o longestPalindrome -lgtest

naryTreePreOrder:
	$(CXX) naryTreePreOrder.cpp -o naryTreePreOrder -lgtest

isomorphic:
	$(CXX) isomorphic.cpp -o isomorphic -lgtest

sortRepeatingNumbers:
	$(CXX) sortRepeatingNumbers.cpp -o sortRepeatingNumbers

mergeTwoLists:
	$(CXX) mergeTwoLists.cpp -o mergeTwoLists

romanToInt:
	$(CXX) romanToInt.cpp -o romanToInt

reverseList:
	$(CXX) reverseList.cpp -o reverseList

numberPalindrome:
	$(CXX) numberPalindrome.cpp -o numberPalindrome

linkedListIntersection:
	$(CXX) linkedListIntersection.cpp -o linkedListIntersection -lgtest

shortestPathAlternatingColors:
	$(CXX) shortestPathAlternatingColors.cpp -o shortestPathAlternatingColors -lgtest

elementwiseAddition:
	$(CXX) elementwiseAddition.cpp -o elementwiseAddition -lgtest

longestSubstringWithoutRepeat:
	$(CXX) longestSubstringWithoutRepeat.cpp -o longestSubstringWithoutRepeat -lgtest

clean:
	rm -f isSubsequence middleNode detectCycle reorderList maxProfit longestPalindrome naryTreePreOrder mergeTwoLists romanToInt reverseList sortRepeatingNumbers \
		 numberPalindrome linkedListIntersection isomorphic shortestPathAlternatingColors naryTree elementwiseAddition longestSubstringWithoutRepeat
