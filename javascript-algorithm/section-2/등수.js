const input = [87, 89, 92, 100, 76];

function rank(people) {
    let sorted = [...people];
    sorted.sort((a,b) => {
        console.log(a,b,"??");
        return b-a
    });
    return people.map(p => {
        return sorted.indexOf(p)+1;
    })
}
function rank2(people) {
    let result = [];
    for (let i = 0; i < people.length; i++) {
        result.push(1);
        for (let j = 0; j < people.length; j++) {
            if (people[j] > people[i]) {
                result[i]++;
            }
        }
    }
    return result;
}

console.log(rank2(input));