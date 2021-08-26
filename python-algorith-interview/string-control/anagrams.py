import collections
from typing import List

# 문자열 배열을 받아 애너그램 단위로 그룹핑하라.
strArray = [ 'eat', 'ate', 'tea', 'red', 'dre', 'erd' ]
# => [ [ eat, ate, tea ], [ rea, dre, erd ] ]

def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
    anagrams = collections.defaultdict(list)
    
    for word in strs:
        # 정렬하여 딕셔너리에 추가
        anagrams[''.join(sorted(word))].append(word)
    return list(anagrams.values())

print(groupAnagrams('',strArray))