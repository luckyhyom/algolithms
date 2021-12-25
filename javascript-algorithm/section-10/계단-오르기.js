function solution(n) {
    let answer = [];
    answer[1] = 1;
    answer[2] = 2;

    for (let i = 3; i <= n; i++) {
        answer[i] = answer[i-1] + answer[i-2];
    }

    return answer[answer.length-1];
}
function _solution(n) {
    let answer = 0;
    let dy = Array.from({length: n+1}, () => 0);
    dy[1] = 1;
    dy[2] = 2;
    for (let i = 3; i <= n; i++) {
        dy[i] = dy[i-1] + dy[i-2];
    };
    answer = dy[n];
    return answer;
}

console.log(_solution(7));