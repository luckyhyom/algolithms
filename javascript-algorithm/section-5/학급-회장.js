function mySolution(votes) {
    let result = {};
    let max = 0;
    let answer;
    votes.forEach(vote => {
        if (result[vote] === undefined) {
            result[vote] = 1;
        } else {
            result[vote]++;
        }
        max = Math.max(max, result[vote]);
        if(max === result[vote]) {
            answer = vote;
        }
    });

    return answer;
}





const input = ['B', 'A', 'C', 'B', 'A', 'C', 'C', 'A', 'C', 'C', 'B', 'D', 'E', 'D', 'E'];
console.log(mySolution(input));

function solution(s){  
    let answer;
    let sH = new Map();
    for(let x of s){
        if(sH.has(x)) sH.set(x, sH.get(x)+1);
        else sH.set(x, 1);
    }
    let max=Number.MIN_SAFE_INTEGER;
    for(let [key, val] of sH){
        if(val>max){
            max=val;
            answer=key;
        }
    }
    return answer;
}

let str="BACBACCACCBDEDE";
console.log(solution(str));