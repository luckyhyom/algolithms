function getLongest(strs) {
    let arr = [];
    let obj = {};
    strs.forEach(str => {
        arr.push(str.length);
        obj[str.length] = str;
    })
    let min = Math.max(...arr);
    return obj[min];
}
function getLongest2(strs) {
    let arr = strs.sort((a,b) => b.length - a.length);
    return arr[0];
}

function getLongest3(strs) {
    let answer = '';
    let max = Number.MIN_SAFE_INTEGER;
    for (const s of strs) {
        if (s.length > max) {
            max = s.length;
            answer = s;
        }
    }

    return answer;
}