function show(people) {
    let result = 0
    for (let i = 0; i < people.length-1; i++) {
        if (people[i] < people[i+1]) result++;
    }
    return result;
}
function show2(people) {
    let result = 1;
    let max = people[0];
    for (let i = 1; i < people.length; i++) {
        if (max < people[i]) {
            result++;
            max = people[i];
        };
    }
    return result;
}

console.log(show2([130, 135, 148, 140, 145, 150, 150, 153]));