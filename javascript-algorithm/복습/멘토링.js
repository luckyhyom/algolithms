input = [
    [3,4,1,2],
    [4,3,2,1],
    [3,1,4,2],
]

function mento(ranks) {
    // 배열 길이 = 시험수
    // 시험 길이 = 사람 수
    // 시험 인덱스 = 등수
    // 시험 안의 번호 = 사람 번호
    let headCount = ranks[0].length;
    let answer = 0;
    for (let i = 1; i <= headCount; i++) {
        for (let j = 1; j <= headCount; j++) {
            let count = 0;
            for (let k = 0; k < ranks.length; k++) {
                let ip = 0;
                let jp = 0;
                for (let s = 0; s < headCount; s++) {
                    if (ranks[k][s] === i) ip = s
                    if (ranks[k][s] === j) jp = s
                }
                if (ip < jp) count++;
            }
            if (count === ranks.length) {
                answer++;
            }
        }
    }

    return answer;
}

console.log(mento(input));