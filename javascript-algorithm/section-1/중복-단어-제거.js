function noOverlap(strs) {
    let answer = [];
    strs.forEach(str => {
        if(!answer.includes(str)) {
            answer.push(str)
        }
    })
    return answer;
}

function noOverlap2(strs) {
    return strs.filter((v, i) => {
        return strs.indexOf(v) === i;
    });
}

console.log(noOverlap2(['asd','asd','asd','aaaa','apple','lemon','aaaa']));