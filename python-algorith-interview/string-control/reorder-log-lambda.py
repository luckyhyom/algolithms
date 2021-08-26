from typing import List

# 로그를 재정렬하라. 기준은 다음과 같다.
# 1. 로그의 가장 앞 부분은 식별자다.
# 2. 문자로 구성된 로그가 숫자 로그보다 앞에 온다.
# 3. 식별자는 순서에 영향을 끼치지 않지만, 문자가 동일할 경우 식별자 순으로 한다.
# 4. 숫자 로그는 입력 순서대로 한다.
logs: List[str] = [
    'dig1 8 1 5 1', 
    'let1 art can', 
    'dig2 3 6', 
    'let2 own kit dig', 
    'let3 art zero'
]

def reorderLogFiles(self, logs: List[str]) -> List[str]:
    letters, digits = [], []
    for log in logs:
        if log.split()[1].isdigit():
            digits.append(log)
        else:
            letters.append(log)

    # 2개의 키를 람다 표현식으로 정렬
    letters.sort(key=lambda x: (x.split()[1:], x.split()[0]))
    return letters + digits

print(reorderLogFiles('',logs))

# 문자열[0]은 식별자로 쓰며, 식별자 다음의 값 문자열[1]을 기준으로 정렬한다.
# 값이 같은 경우에 차선으로 식별자를 기준으로 정렬한다.