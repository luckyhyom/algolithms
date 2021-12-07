// 7개의 자연수가 주어질 때, 이들 중 홀수인 자연수들을 모두 골라 그 합을 구하고, 고른 홀수들 중 최소값을 찾는 프로그램을 작성하세요.

const input = [12, 77, 38, 41, 53, 92, 85];
const result = 41;

function get(numbers) {
    let odds = numbers.filter((number) => number%2 === 1);
    const min = Math.min(...odds);
    const sum = odds.reduce((pre, cur, i) => {
        return pre + cur;
    }, 0);
    return [ min, sum ];
}