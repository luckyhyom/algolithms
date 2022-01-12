function mySolution(days, sales) {
    let answer=0, sum=0;
    for (let i = 0; i < days; i++) {
        sum += sales[i];
    }
    answer = sum;

    let right = days;
    let left = 0;
    while (right < sales.length) {
        sum += (sales[right++] - sales[left++]);
        answer = Math.max(sum, answer);
    }

    return answer;
}

let input = [12,15,11,20,25,10,20,19,13,15];
const result = mySolution(3, input);
const answer = 56;
console.log(result === answer);
