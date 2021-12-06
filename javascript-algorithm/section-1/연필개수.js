// 연필 1 다스는 12자루입니다. 학생 1인당 연필을 1자루씩 나누어 준다고 할 때 N명의 학생수 를 입력하면 필요한 연필의 다스 수를 계산하는 프로그램을 작성하세요.
function getPens(peopleCount) {
    let standard = 12;
    let result = Math.ceil(peopleCount/standard);
    return result;
}

console.log(getPens(25));