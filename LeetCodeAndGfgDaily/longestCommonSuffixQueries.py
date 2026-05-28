from typing import List
class Solution:
    class TrieNode:
        __slots__ = ['idx', 'children']
        def __init__(self):
            self.idx = -1
            self.children = {}
        
    def getNode(self, i):
        tmp = self.TrieNode()
        tmp.idx = i

        return tmp
    
    def insertTrie(self, wordsContainer: List[str], root, i):
        word = wordsContainer[i]
        n = len(word)

        for j in range(n-1, -1, -1):
            ch = word[j]

            if ch not in root.children:
                root.children[ch] = self.getNode(i)

            root = root.children[ch]

            if len(wordsContainer[root.idx]) > len(word):
                root.idx = i

    def searchTrie(self, wordsQuery, root, i):
        word = wordsQuery[i]
        ans_idx = root.idx
        n = len(wordsQuery[i])

        for j in range(n-1,-1,-1):
            ch = word[j]

            if ch not in root.children:
                break
            root = root.children[ch]
            ans_idx = root.idx
        
        return ans_idx


    def stringIndices(self, wordsContainer: List[str], wordsQuery: List[str]) -> List[int]:
        m = len(wordsContainer)
        n = len(wordsQuery)

        ans = [-1]*n
        root = self.getNode(0)

        for i in range(m):
            idx = root.idx
            if len(wordsContainer[idx]) > len(wordsContainer[i]):
                root.idx = i
            
            self.insertTrie(wordsContainer, root, i)
        
        for i in range(n):
            ans[i] = self.searchTrie(wordsQuery, root, i)

        del root
        return ans