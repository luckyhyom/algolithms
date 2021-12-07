// 9명의 난쟁이중 가짜가 둘이 섞여있다. 난쟁이들의 키의 합은 100이었다. 진짜 난쟁이만 남겨라.

function getReal(numbers) {
    let people = numbers.filter(n => n < 100);
    const target = 100;
    const sum = people.reduce((pre, cur) => pre+cur);
    const lierSum = sum - target;
    for (i=0; i < people.length-1; i++) {
        for (j=1; j < people.length; j++) {
            if (people[i] + people[j] === lierSum) {
                people.splice(j,1);
                people.splice(i,1); // i와 j를 제거하는 다른 방법은?
                return people;
            }
        }
    }
}

console.log(getReal([20, 7, 23, 19, 10, 15, 25, 8, 13]));