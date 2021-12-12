let input = [
    [3,4,1,2],
    [4,3,2,1],
    [3,1,4,2]
]

function partner(ranks) {
    let test = ranks.length;
    let people = ranks[0].length;
    let answer = 0;
    let result = [];
    for (let i = 1; i <=  people; i++) {
        for (let j = 1; j <=  people; j++) {
            let count = 0;
            for (let k = 0; k < test; k++) {
                let pi,pj = 0;
                for (let s = 0; s < people; s++) {
                    if (ranks[k][s] === i) pi = s;
                    if (ranks[k][s] === j) pj = s;
                }
                if (pi < pj) count++;
            }
            if (count === test) {
                result.push([i,j]);
                answer++;
            }
        }
        
    }
    return answer;
}

console.log(partner(input));