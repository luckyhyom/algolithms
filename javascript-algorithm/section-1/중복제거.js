function noOverlap(str) {
    let result = '';
    for (const s of str) {
        if (result.includes(s)) {
            continue;
        } else {
            result += s;
        }
    }
    return result;
}

function noOverlap2(str) {
    let result = '';
    for (let i = 0; i < str.length; i++) {
        if(str.indexOf(str[i]) === i) {
            result += str[i];
        }
    }
    return result;
}


console.log(noOverlap2('aaabbbbbccecccdddddd'));