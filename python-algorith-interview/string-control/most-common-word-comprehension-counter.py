import collections
import re
from typing import List

# 금지된 단어를 제외한 가장 흔하게 등장하는 단어를 출력하라. 대소문자 구분을 하지 않으며, 구두점 또한 무시한다.

paragraph = 'Bob hit a ball, the hit BALL flew far after it was hit'
banned = ['hit']
# => 'ball'

def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
    words = [word for word in re.sub(r'[^\w]', ' ', paragraph)
        .lower().split()
            if word not in banned]

    counts = collections.Counter(words)
    return counts.most_common(1)[0][0]

print(mostCommonWord('', paragraph, banned))

# counts = collections.defaultdict(int)
#   for word in words:
#       counts[word] += 1
# return max(counts, key=counts.get)

# 컴프리헨션: [ i * 2 for i in arr ]
# defaultdict(int): 존재하지 않는 key 조회시 key를 자동으로 생성하며 default value는 0