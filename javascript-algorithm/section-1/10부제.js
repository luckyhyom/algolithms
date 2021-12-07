// 주어진 날짜의 1의자리 숫자와 자동차의 일의 자리 숫자를 보고 10부제를 위반하는 차량의 대수를 출력합니다.
let today = 3
const carNumbers = [ 25, 23, 11, 47, 53, 17, 33 ];

function rule(day, numbers) {
    const result = numbers.filter(number => {
        return number%10 !== day;
    })
    return result.length;
}