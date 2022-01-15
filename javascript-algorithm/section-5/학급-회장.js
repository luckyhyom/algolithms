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