from typing import List


class ReorederLogFiles:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letters, digits = [], []
        for log in logs:
            print(letters)
            if log.split()[1].isdigit():
                digits.append(log)
            else:
                letters.append(log)

        # 2개의 키를 람다 표현식으로 정렬
        letters.sort(key=lambda x: (x.split()[1:], x.split()[0]))
        return letters + digits

a: List[str] = ['dig1 8 1 5 1', 'let1 art can', 'dig2 3 6', 'let2 own kit dig', 'let3 art zero', '12312 123']
print(ReorederLogFiles().reorderLogFiles(a))

# 문자열[0]은 식별자로 쓰며, 식별자 다음의 값 문자열[1]을 기준으로 정렬한다.
# 값이 같은 경우에 차선으로 식별자를 기준으로 정렬한다.